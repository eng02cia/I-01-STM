/*//////////////////////////////////////////////////////////////////////////////////
//      funcoes que controlam a transmis�o de dados pela serial 1         		//	
//////////////////////////////////////////////////////////////////////////////////
#include "transfereConstToArray.h"
#include "comparaValoresArray.h"
#include "comparaConstComArray.h"
#include "carregaArrayComZeroDecimal.h"
#include "inteiroTo2BytesAscii.h"
#include "inteiroTo3BytesAscii.h"

//////////////////////////////////////////////////////////////////////////////////
//interrup��o da serial 1                                                       //
//////////////////////////////////////////////////////////////////////////////////
void serial_1RxInterruptProtocoloSa(void)
{
/*    if (PIE3bits.RC1IE == 1 & PIR3bits.RC1IF == 1)
    {        
        PIR3bits.RC1IF = 0;
        rrxSerial_1 = RCREG1;
        RCREG1 = 0; 
        if (menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
        && menuCalibraIndicador == menuCalibraIndicadorEmEspera        
        && exibeVersionControl  == 0
        && statusLigaDesliga == _LIGADO)    
        {
            rxSerial_1ProtocoloSa();
        }
        else
        {
            verificaFimFrame = inicioFimFrameSerial_1; 
            tempoMaxRxSerial_1 = 0;
            flagTempoMaxRxSerial_1 = 0;        
            tamanhoFrameRxSerial_1 = 0;
            indexRxSerial_1 = 0;
            carregaArrayComZeroDecimal(15,&frameRxSerial_1[0]);   
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//fun��o da recep��o de dados quando protocolo AudioTeck               			//
//////////////////////////////////////////////////////////////////////////////////	
void rxSerial_1ProtocoloSa(void)
{
//    flagTempoMaxRxSerial_1 = 1;    
    tempoMaxRxSerial_1 = 0;
    frameRxSerial_1[indexRxSerial_1++] = rrxSerial_1;
    tamanhoFrameRxSerial_1++;        
    switch (verificaFimFrame)
    {
        case inicioFimFrameSerial_1:
            if (rrxSerial_1 == '\r'){verificaFimFrame = finalFrameSerial_1;}                    
            break;
        case finalFrameSerial_1:
            if (rrxSerial_1 == '\n')
            {
//verifica a validade do endere�o                
                tempProtocolo = (((frameRxSerial_1[0]-'0')*10) + (frameRxSerial_1[1]-'0'));
                if (enderecoIndicadorEep == tempProtocolo){trataFrameProtocoloSa();}  
            }
            verificaFimFrame = inicioFimFrameSerial_1; 
            tempoMaxRxSerial_1 = 0;
            flagTempoMaxRxSerial_1 = 0;        
            tamanhoFrameRxSerial_1 = 0;
            indexRxSerial_1 = 0;
            carregaArrayComZeroDecimal(15,&frameRxSerial_1[0]);                        
            break;
    }
// descarta frame quando o tamanho � maior que o previsto    
    if (tamanhoFrameRxSerial_1 >= 30)
    {	
//        flagTempoMaxRxSerial_1 = 0;        
        tamanhoFrameRxSerial_1 = 0;
        indexRxSerial_1 = 0;
        carregaArrayComZeroDecimal(15,&frameRxSerial_1[0]);
    } 
}
//////////////////////////////////////////////////////////////////////////////////		
//fun��o de tratamento dos dados recebidos quando protocolo AudioTeck   		//
//////////////////////////////////////////////////////////////////////////////////	
void trataFrameProtocoloSa(void)
{   
//////////////////////////////////////////////////////////////////////////////////    
//verifica se liga o indicador de peso                                          //
//////////////////////////////////////////////////////////////////////////////////    
    frameRxProtocoloSaValido = 0;
    tempProtocolo = comparaConstComArray(&charLigaIndicador[0],&frameRxSerial_1[2]);
    if (tempProtocolo == 0)
    {
        frameRxProtocoloSaValido = 1;
        HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_SET);
        statusLigaDesliga = _LIGADO;
        exibeVersionControl = 1;
        escreveDadoLcd(&telaInicialIndicador[0],&caracterLcd[0]); 
        controleTara = _TARADESATIVADA;
// o indicador sera zerado na inicializa��o caso o peso esteja dentro do limite de zero
        fazZeroIndicadorPeso = 1;        
        transfereArrayToArray(9,&frameRxSerial_1[0],&frameTempTxSerial_1[0]);          
        quantidadeTempBytesTxSerial_1 = 9;
        flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
    }
//////////////////////////////////////////////////////////////////////////////////    
//verifica se desliga o indicador de peso                                        //
//////////////////////////////////////////////////////////////////////////////////  
    tempProtocolo = comparaConstComArray(&charDesligaIndicador[0],&frameRxSerial_1[2]);
    if (tempProtocolo == 0)
    {
        frameRxProtocoloSaValido = 1;
        carregaArrayComEspacoAscii(32,&caracterLcd[0]);
        HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_RESET);
        statusLigaDesliga = _DESLIGADO;
        controleTara = _TARADESATIVADA;   
        transfereArrayToArray(10,&frameRxSerial_1[0],&frameTempTxSerial_1[0]);          
        quantidadeTempBytesTxSerial_1 = 10;
        flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;  
    }     
//////////////////////////////////////////////////////////////////////////////////    
//verifica se solicita status funcionamento do indicador                        //
//////////////////////////////////////////////////////////////////////////////////  
    tempProtocolo = comparaConstComArray(&charStaFuncionamentoIndicador[0],&frameRxSerial_1[2]); 
    if (tempProtocolo == 0)
    {
        if (statusLigaDesliga == _LIGADO)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charLigaIndicador[0],&frameTempTxSerial_1[2]);
            frameTempTxSerial_1[7] = '\r';//line feed(LF))
            frameTempTxSerial_1[8] = '\n';//Carriage return(CR)    
            quantidadeTempBytesTxSerial_1 = 9;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;    
        }        
        if (statusLigaDesliga == _DESLIGADO)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charDesligaIndicador[0],&frameTempTxSerial_1[2]);
            frameTempTxSerial_1[8] = '\r';//line feed(LF))
            frameTempTxSerial_1[9] = '\n';//Carriage return(CR)                   
            quantidadeTempBytesTxSerial_1 = 10;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;   
        }            
    }   
//////////////////////////////////////////////////////////////////////////////////    
//verifica se ativa a funcao tara                                               //
//////////////////////////////////////////////////////////////////////////////////  
    if (statusLigaDesliga == _LIGADO)
    {   
        tempProtocolo = comparaConstComArray(&charLigaTara[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            if (indicadorEmZero != 1) 
            {
                controleTara = _TARAATIVADA;
                fazTaraIndicadorPeso = 1;
                transfereArrayToArray(9,&frameRxSerial_1[0],&frameTempTxSerial_1[0]);          
                quantidadeTempBytesTxSerial_1 = 9;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;              
            } 
            else
            {
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaTaraErro[0],&frameTempTxSerial_1[2]);              
                quantidadeTempBytesTxSerial_1 = 11;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;         
            }            
        }       
//////////////////////////////////////////////////////////////////////////////////    
//verifica se desativa a funcao tara                                            //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charDesligaTara[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            controleTara = _TARADESATIVADA;
            valorTaraIndicador = valorZeroIndicador;
            transfereArrayToArray(10,&frameRxSerial_1[0],&frameTempTxSerial_1[0]);          
            quantidadeTempBytesTxSerial_1 = 10;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                 
        }  
//////////////////////////////////////////////////////////////////////////////////    
//verifica se solicita a o status da funcao tara                                //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charStatusTara[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {  
            if (controleTara == _TARAATIVADA)
            {
                frameRxProtocoloSaValido = 1;
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charLigaTara[0],&frameTempTxSerial_1[2]);
                frameTempTxSerial_1[7] = '\r';//line feed(LF))
                frameTempTxSerial_1[8] = '\n';//Carriage return(CR)             
                quantidadeTempBytesTxSerial_1 = 9;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;    
            }        
            if (controleTara == _TARADESATIVADA)
            {
                frameRxProtocoloSaValido = 1;
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charDesligaTara[0],&frameTempTxSerial_1[2]);
                frameTempTxSerial_1[8] = '\r';//line feed(LF))
                frameTempTxSerial_1[9] = '\n';//Carriage return(CR)                   
                quantidadeTempBytesTxSerial_1 = 10;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;    
            }                
        }      
//////////////////////////////////////////////////////////////////////////////////    
//verifica se executa a funcao zero da balanca                                  //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charLigaZero[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            tempProtocolo = checaAutorizaZeroIndicador();
            if (controleTara == 0 && tempProtocolo == 0)
            {
                frameRxProtocoloSaValido = 1;
                fazZeroIndicadorPeso = 1;
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaZeroOk[0],&frameTempTxSerial_1[2]);          
                quantidadeTempBytesTxSerial_1 = 9;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                     
            }
//envia erro no comando de zero quando esta fora do limite de zero
            if (tempProtocolo == 1) 
            {
                frameRxProtocoloSaValido = 1;
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaZeroErro1[0],&frameTempTxSerial_1[2]);          
                quantidadeTempBytesTxSerial_1 = 12;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                  
            }    
//envia erro no comando de zero quando a tara esta ativa        
            if (controleTara == 1)
            { 
                frameRxProtocoloSaValido = 1;
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaZeroErro2[0],&frameTempTxSerial_1[2]);          
                quantidadeTempBytesTxSerial_1 = 12;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                
            }        
        }      
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe o valor com limite de zero                                 //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charLimiteZero[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
//calcula o limete de zero recebido
            frameRxProtocoloSaValido = 1;
            tempProtocolo = ((frameRxSerial_1[7]-'0')*100) + ((frameRxSerial_1[8]-'0')*10)+ (frameRxSerial_1[9]-'0'); 
            if (tempProtocolo < _LIMITE_ZERO_MAXIMO)
            {
                valorLimiteDeZeroEep = tempProtocolo;
                iniciaSalvaDadosEeprom = 1;
                pilhaEeprom.salvaLimiteDeZero = 1;                  
                
                salvaValorLimiteDeZeroEep();
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaLimiteZeroOk[0],&frameTempTxSerial_1[2]); 
                quantidadeTempBytesTxSerial_1 = 9;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
            }
            else
            {
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaLimiteZeroErro[0],&frameTempTxSerial_1[2]);              
                quantidadeTempBytesTxSerial_1 = 11;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;  
            }
        } 
 /////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a solicita��o do status para o limte de zero               //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charStatusLimiteZero[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charLimiteZero[0],&frameTempTxSerial_1[2]);
            inteiroTo3BytesAscii(valorLimiteDeZeroEep,&frameTempTxSerial_1[5]);
            frameTempTxSerial_1[8] = '\r';//line feed(LF))
            frameTempTxSerial_1[9] = '\n';//Carriage return(CR)
            quantidadeTempBytesTxSerial_1 = 10;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                  
        }              
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe o valor com valor do filtro digital                        //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charFiltroDigital[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
//calcula o limete de zero recebido
            frameRxProtocoloSaValido = 1;
            tempProtocolo = ((frameRxSerial_1[7]-'0')*100) + ((frameRxSerial_1[8]-'0')*10)+ (frameRxSerial_1[9]-'0'); 
            if (tempProtocolo < _VMAX_FILTRO_DIGITAL)
            {
                valorFiltroDigitalEep = tempProtocolo;
                iniciaSalvaDadosEeprom = 1;
                pilhaEeprom.salvaValorFiltroDigital = 1;                    

                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaFiltroDigitalOk[0],&frameTempTxSerial_1[2]); 
                quantidadeTempBytesTxSerial_1 = 9;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
            }
            else
            {
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaFiltroDigitalErro[0],&frameTempTxSerial_1[2]);              
                quantidadeTempBytesTxSerial_1 = 11;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;  
            }
        } 
 /////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a solicita��o do status para filtro digital                //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charStatusFiltroDigital[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charFiltroDigital[0],&frameTempTxSerial_1[2]);
            inteiroTo3BytesAscii(valorFiltroDigitalEep,&frameTempTxSerial_1[5]);
            frameTempTxSerial_1[8] = '\r';//line feed(LF))
            frameTempTxSerial_1[9] = '\n';//Carriage return(CR)
            quantidadeTempBytesTxSerial_1 = 10;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                  
        }                
//////////////////////////////////////////////////////////////////////////////////    
//verifica se � a solicitacao do peso bruto                                     //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charSolicitaPesoBruto[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charSolicitaPesoBruto[0],&frameTempTxSerial_1[2]);  
            transfereArrayToArray(7,&pesoBrutoIndicadorAscii[0],&frameTempTxSerial_1[5]);
            frameTempTxSerial_1[12] = '\r';//line feed(LF))
            frameTempTxSerial_1[13] = '\n';//Carriage return(CR)
            quantidadeTempBytesTxSerial_1 = 14;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
        }  
//////////////////////////////////////////////////////////////////////////////////    
//verifica se � a solicitacao do peso tara                                      //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charSolicitaPesoTara[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charSolicitaPesoTara[0],&frameTempTxSerial_1[2]); 
            transfereArrayToArray(7,&pesoTaraIndicadorAscii[0],&frameTempTxSerial_1[5]);
            frameTempTxSerial_1[12] = '\r';//line feed(LF))
            frameTempTxSerial_1[13] = '\n';//Carriage return(CR)
            quantidadeTempBytesTxSerial_1 = 14;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;   
        } 
//////////////////////////////////////////////////////////////////////////////////    
//verifica se � a solicitacao do peso liquido                                   //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charSolicitaPesoLiquido[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charSolicitaPesoLiquido[0],&frameTempTxSerial_1[2]);     
            transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&frameTempTxSerial_1[5]);
            frameTempTxSerial_1[12] = '\r';//line feed(LF))
            frameTempTxSerial_1[13] = '\n';//Carriage return(CR)
            quantidadeTempBytesTxSerial_1 = 14;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;          
        } 
//////////////////////////////////////////////////////////////////////////////////    
//verifica se solicita a o status do funcionamento                              //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charStatusFuncionamento[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            frameTempTxSerial_1[2] = 'S';
            frameTempTxSerial_1[3] = 'F';
            frameTempTxSerial_1[4] = ':';
//carrega o status do zero        
            if (indicadorEmZero){frameTempTxSerial_1[5] = '1';}
            else{frameTempTxSerial_1[5] = '0';}
//carrega o status da tara        
            if (controleTara == _TARAATIVADA){frameTempTxSerial_1[6] = '1';}
            else{frameTempTxSerial_1[6] = '0';}
//carrega o status da sub carga
            if (statusControleSubCarga == 1){frameTempTxSerial_1[7] = '1';}
            else{frameTempTxSerial_1[7] = '0';}
//carrega o status da sobre carga
            if (statusControleSobreCarga == 1){frameTempTxSerial_1[8] = '1';}
            else{frameTempTxSerial_1[8] = '0';}        
            frameTempTxSerial_1[9] = '\r';//line feed(LF))
            frameTempTxSerial_1[10] = '\n';//Carriage return(CR)                   
            quantidadeTempBytesTxSerial_1 = 11;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                      
        }        
//////////////////////////////////////////////////////////////////////////////////    
//verifica se � a solicita��o de numero de serie                                //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charSolicitaVersao[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charVersaoIndicadorSigmaciaSa[0],&frameTempTxSerial_1[2]);
            quantidadeTempBytesTxSerial_1 = 16;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;           
        }     
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe dados da configura��o para transmiss�o autom�tica de dados //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charControleTxAutomatico[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            if (frameRxSerial_1[7] == '1'){statusTransmiteAutomaticoEep[0] = 1;}
            if (frameRxSerial_1[7] == '0'){statusTransmiteAutomaticoEep[0] = 0;}
            statusTransmiteAutomaticoEep[1] = (((frameRxSerial_1[8] -'0')*10) + (frameRxSerial_1[9] -'0'));
            iniciaSalvaDadosEeprom = 1;
            pilhaEeprom.salvaTransmissaoAutomaticaSerial_1 = 1;  
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charRespostaTxAutomatico[0],&frameTempTxSerial_1[2]);
            quantidadeTempBytesTxSerial_1 = 9;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;              
        }       
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a configura��o para capacidade maxima                      //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charCapacidadeMaxima[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            tempProtocolo = checaFrameAsciiValido(7,&frameRxSerial_1[7]);
            if (tempProtocolo == 0)
            {
                transfereArrayToArray(7,&frameRxSerial_1[7],&capacidadeMaximaIndicadorEep[0]);
                capacidadeMaximaIndicadorEep[7] = 0;
                valorPesoCargaMaxima = atol(capacidadeMaximaIndicadorEep);
                iniciaSalvaDadosEeprom = 1;
                pilhaEeprom.salvaPesoCapacidadeMaxima = 1;                  
        
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaCapMaxima[0],&frameTempTxSerial_1[2]);
                quantidadeTempBytesTxSerial_1 = 9;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
            }
            else
            {
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaErroCapMaxima[0],&frameTempTxSerial_1[2]);
                quantidadeTempBytesTxSerial_1 = 11;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
            }         
        }  
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a solicita��o do status da programa��o para a capacidade   //
// maxima de peso                                                               //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charStatusCapacidadeMaxima[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charCapacidadeMaxima[0],&frameTempTxSerial_1[2]);
            transfereArrayToArray(7,&capacidadeMaximaIndicadorEep[0],&frameTempTxSerial_1[5]);
            frameTempTxSerial_1[12] = '\r';//line feed(LF))
            frameTempTxSerial_1[13] = '\n';//Carriage return(CR)                   
            quantidadeTempBytesTxSerial_1 = 14;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
        }
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a configura��o para o peso de calibra��o                   //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charPesoCalibracao[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            tempProtocolo = checaFrameAsciiValido(7,&frameRxSerial_1[7]);
            if (tempProtocolo == 0)
            {        
                transfereArrayToArray(7,&frameRxSerial_1[7],&arrayTempRxSerial_1[0]);
                transfereArrayToArray(7,&capacidadeMaximaIndicadorEep[0],&arrayTemp1RxSerial_1[0]);
                transfereArrayToArray(7,&arrayTempRxSerial_1[0],&arrayTemp2RxSerial_1[0]);
                
                converteArrayAsciiParaDecimal(6,&arrayTemp1RxSerial_1[0]);
                converteArrayAsciiParaDecimal(6,&arrayTemp2RxSerial_1[0]);              
                tempProgIndicador = comparaValoresArray(6,&arrayTemp1RxSerial_1[0],&arrayTemp2RxSerial_1[0]);
                if ( tempProgIndicador == 1)
                {
                    transfereArrayToArray(6,&arrayTempRxSerial_1[0],&pesoCalibracaoIndicadorEep[0]);
                    pesoCalibracaoIndicadorEep[7] = 0;
                    iniciaSalvaDadosEeprom = 1;
                    pilhaEeprom.salvaPesoCalibracao = 1;                          
            
                    inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                    transfereConstToArray(&charRespostaPesoCalibracaoOk[0],&frameTempTxSerial_1[2]);
                    quantidadeTempBytesTxSerial_1 = 9;
                    flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                     
                }
                else
                {
                    inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                    transfereConstToArray(&charRespostaPesoCalibracaoErro2[0],&frameTempTxSerial_1[2]);
                    quantidadeTempBytesTxSerial_1 = 12;
                    flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;               
                } 
            }
            else
            {
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaPesoCalibracaoErro1[0],&frameTempTxSerial_1[2]);
                quantidadeTempBytesTxSerial_1 = 12;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;       
            }
        } 
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a solicita��o do status da programa��o para o peso de      //
//calibra��o                                                                    //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charStatusPesoCalibracao[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        { 
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charPesoCalibracao[0],&frameTempTxSerial_1[2]);
            transfereArrayToArray(7,&pesoCalibracaoIndicadorEep[0],&frameTempTxSerial_1[5]);
            frameTempTxSerial_1[12] = '\r';//line feed(LF))
            frameTempTxSerial_1[13] = '\n';//Carriage return(CR)                   
            quantidadeTempBytesTxSerial_1 = 14;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
        }        
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a configura��o para o ponto decimal                        //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charPontoDecimal[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            tempProtocolo = frameRxSerial_1[7]-'0';
            if (tempProtocolo < 5)
            {
                posicaoPontoDecimalIndicadorEep = tempProtocolo;
                iniciaSalvaDadosEeprom = 1;
                pilhaEeprom.salvaPosicaoPontoDecimal = 1;                        
 
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaPontoDecimalOk[0],&frameTempTxSerial_1[2]);
                quantidadeTempBytesTxSerial_1 = 9;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;    
            }
            else
            {
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaPontoDecimalErro[0],&frameTempTxSerial_1[2]);
                quantidadeTempBytesTxSerial_1 = 11;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                           
            }
        }
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a solicita��o do status da programa��o para o ponto decimal //
///////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charStatusPontoDecimal[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {   
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charPontoDecimal[0],&frameTempTxSerial_1[2]);
            frameTempTxSerial_1[5] = posicaoPontoDecimalIndicadorEep + '0';
            frameTempTxSerial_1[6] = '\r';//line feed(LF))
            frameTempTxSerial_1[7] = '\n';//Carriage return(CR)                   
            quantidadeTempBytesTxSerial_1 = 8;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
        }           
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a configura��o para o degrau do peso                       //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charDegrauPeso[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            tempProtocolo = frameRxSerial_1[7]-'0';
            if (tempProtocolo == 1 || tempProtocolo == 2 || tempProtocolo == 5 || tempProtocolo == 10)
            {
                degrauIndicadorEep = tempProtocolo;
                iniciaSalvaDadosEeprom = 1;
                pilhaEeprom.salvaDegrauPeso = 1;                        

                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaDegrauPesoOk[0],&frameTempTxSerial_1[2]);
                quantidadeTempBytesTxSerial_1 = 9;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                
            }
            else
            {
                inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
                transfereConstToArray(&charRespostaDegrauPesoErro[0],&frameTempTxSerial_1[2]);
                quantidadeTempBytesTxSerial_1 = 11;
                flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                       
            }   
        }
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe a solicita��o do status da programa��o para o degral do peso//
///////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charStatusDegrauPeso[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {  
            frameRxProtocoloSaValido = 1;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charDegrauPeso[0],&frameTempTxSerial_1[2]);
            frameTempTxSerial_1[5] = degrauIndicadorEep + '0';
            frameTempTxSerial_1[6] = '\r';//line feed(LF))
            frameTempTxSerial_1[7] = '\n';//Carriage return(CR)                   
            quantidadeTempBytesTxSerial_1 = 8;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1; 
        }               
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe o comando para calibra��o do zero                          //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charCalibraZero[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            menuCalibraIndicador = menuSemPeso;
            flagFazMediaAd = 1;
             loopMediaCalibracao = 0;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charRespostaAguarde[0],&frameTempTxSerial_1[2]);
            quantidadeTempBytesTxSerial_1 = 11;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;             
        }   
//////////////////////////////////////////////////////////////////////////////////    
//verifica se recebe o comando para calibra��o com peso                         //
//////////////////////////////////////////////////////////////////////////////////  
        tempProtocolo = comparaConstComArray(&charCalibraPeso[0],&frameRxSerial_1[2]); 
        if (tempProtocolo == 0)
        {
            frameRxProtocoloSaValido = 1;
            tempAd = 0;
            flagFazMediaAd = 1;
            loopMediaCalibracao = 0;
            menuCalibraIndicador = menuComPeso;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            transfereConstToArray(&charRespostaAguarde[0],&frameTempTxSerial_1[2]);
            quantidadeTempBytesTxSerial_1 = 11;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;            
        }
//////////////////////////////////////////////////////////////////////////////////    
//caso nao recebe nenhum frame valido envia menssagem de erro                  //
////////////////////////////////////////////////////////////////////////////////// 
        if (frameRxProtocoloSaValido == 0)
        {
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            quantidadeTempBytesTxSerial_1 = transfereConstToArray(&charErroComandoInvalido[0],&frameTempTxSerial_1[2]);
            quantidadeTempBytesTxSerial_1 = quantidadeTempBytesTxSerial_1 + 1;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;             
        }
    }
    else
    {
        inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
        transfereConstToArray(&charDesligaIndicador[0],&frameTempTxSerial_1[2]);
        frameTempTxSerial_1[8] = '\r';//line feed(LF))
        frameTempTxSerial_1[9] = '\n';//Carriage return(CR)                   
        quantidadeTempBytesTxSerial_1 = 10;
        flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;                   
    }
}
//////////////////////////////////////////////////////////////////////////////////    
//mensagem enviada com confirma��o da calibra��o do zero                        //
//////////////////////////////////////////////////////////////////////////////////  
void enviaConfirmaCalibracaoZero(void)
{
    menuCalibraIndicador = menuCalibraIndicadorEmEspera;
    inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
    transfereConstToArray(&charRespostaCalibracaoZeroOk[0],&frameTempTxSerial_1[2]);
    quantidadeTempBytesTxSerial_1 = 9;
    flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;            
}
//////////////////////////////////////////////////////////////////////////////////    
//mensagem enviada com confirma��o da calibra��o do zero                        //
//////////////////////////////////////////////////////////////////////////////////  
void enviaConfirmaCalibracaoPeso(void)
{
    menuCalibraIndicador = menuCalibraIndicadorEmEspera;
    inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
    transfereConstToArray(&charRespostaCalibracaoPesoOk[0],&frameTempTxSerial_1[2]);
    quantidadeTempBytesTxSerial_1 = 9;
    flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;            
}
//////////////////////////////////////////////////////////////////////////////////    
//mensagem enviada com informa��o de erro na calibra��o                         //
//////////////////////////////////////////////////////////////////////////////////  
void enviaErroCalibracaoPeso(void)
{
    inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
    transfereConstToArray(&charErroCalibracaoPesoOk[0],&frameTempTxSerial_1[2]);
    quantidadeTempBytesTxSerial_1 = 11;
    flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;           
}
//////////////////////////////////////////////////////////////////////////////////    
//verifica se os dados de determinado frame � valido                            //
// usado apra chegar se o frame de capacidade maxima e peso de calibra��o est�o  //
//corretos  valores validos entre 0 ascii e 9 ascii                             //
//////////////////////////////////////////////////////////////////////////////////  
int checaFrameAsciiValido(unsigned char qtBytes, unsigned char *index)
{
    tempComparaValidade = 0;
    while(qtBytes != 0)
    {
        if (*index < '0' || *index > '9'){tempComparaValidade = 1;}      
        *index++; 
        if (tempComparaValidade == 0){qtBytes--;}
        else{qtBytes = 0;}
    }
	return tempComparaValidade;
}
//////////////////////////////////////////////////////////////////////////////////    
//tempo maximo permitido para recep��o de um frame valido                       //
//////////////////////////////////////////////////////////////////////////////////
void funcTempoMaxRxSerial_1(void)
{
    if (flagTempoMaxRxSerial_1 == 1)
    {    
        if (++tempoMaxRxSerial_1 == 100)
        {
            flagTempoMaxRxSerial_1  = 0;
            tempoMaxRxSerial_1 = 0;
            inteiroTo2BytesAscii(enderecoIndicadorEep,&frameTempTxSerial_1[0]);
            quantidadeTempBytesTxSerial_1 = transfereConstToArray(&charErroFrameInvalido[0],&frameTempTxSerial_1[2]);
            quantidadeTempBytesTxSerial_1 = quantidadeTempBytesTxSerial_1 + 1;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 1;     
            flagTempoMaxRxSerial_1 = 0;        
            tamanhoFrameRxSerial_1 = 0;
            indexRxSerial_1 = 0;
            carregaArrayComZeroDecimal(15,&frameRxSerial_1[0]);            
        }
    }
}

*/
 
