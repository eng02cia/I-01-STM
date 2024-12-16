#include "transfereArrayToArray.h"
#include "transfereConstToArray.h"
#include "inteiroTo2BytesAscii.h"
//////////////////////////////////////////////////////////////////////////////////		
//Funcoes de programacao da data e hora do sistema                              //
//                                                                              //	
//////////////////////////////////////////////////////////////////////////////////
void funcaoProgramaHoraData(void)
{
    if (teclaPressionadaAtual == teclaZeroRetorna)
    {        
        menuProgramacaoRelogioAtual = menuProgramaRelogioEmEspera;
        teclaPressionadaAtual = teclaSolta;    
        flagInibeTeclaSolta = 1;  
        telaAcessaMenuConfiguraRelogio();
    }
    else
    {
//////////////////////////////////////////////////////////////////////////////////
//Programa a parte alta da hora                                                 //            
//////////////////////////////////////////////////////////////////////////////////
        switch(menuProgramacaoRelogioAtual)
        {
//verifica se exibe ou nao o relogio na tela principal
            case menuProgramaExibeRelogio:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima) 
                {
                    teclaPressionadaAtual = teclaSolta;                    
                    if (tempProgDataHora == 1){tempProgDataHora = 0;}
                    else{tempProgDataHora = 1;}    
                }
                if (teclaPressionadaAtual == teclaSalva)
                {
                    teclaPressionadaAtual = teclaSolta;  
                    exibeRelogioMem = tempProgDataHora;
                    salvaExibeRelogio();

                    inteiroTo2BytesAscii(horaRelogio,&arrayProgHora[0]);
                    inteiroTo2BytesAscii(minutoRelogio,&arrayProgMinuto[0]);
                    inteiroTo2BytesAscii(diaMesRelogio,&arrayProgDia[0]);
                    inteiroTo2BytesAscii(mesRelogio,&arrayProgMes[0]);
                    inteiroTo2BytesAscii(anoRelogio,&arrayProgAno[0]);
                    tempProgDataHora = arrayProgHora[0];
                    marcaEdicao = 1;
                    menuProgramacaoRelogioAtual = menuProgramaHoraH;
                }
                break;
//verifica se insere dado no campo hora H
            case menuProgramaHoraH:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;                    
                    if (tempProgDataHora > 2){tempProgDataHora = 0;}
                    arrayProgHora[0] = tempProgDataHora + '0';
                    marcaEdicao = 0;
                }                               
//valida o campo hora H                                     
                if (teclaPressionadaAtual == teclaSalva || teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    menuProgramacaoRelogioAtual = menuProgramaHoraL;
                    tempProgDataHora = arrayProgHora[1] - '0';   
                    marcaEdicao = 1;     
                }                   
                break;
//////////////////////////////////////////////////////////////////////////////////
//Programa a parte L da hora                                                    //            
//////////////////////////////////////////////////////////////////////////////////                        
            case menuProgramaHoraL:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;                    
                    if (tempProgDataHora > 9){tempProgDataHora = 0;}
                    arrayProgHora[1] = tempProgDataHora + '0';
                    marcaEdicao = 0;
                }                               
//valida o campo hora H                                     
                if (teclaPressionadaAtual == teclaSalva || teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    menuProgramacaoRelogioAtual = menuProgramaMinutoH;        
                    verificaHoraValida();        
                }                   
                break;
//////////////////////////////////////////////////////////////////////////////////
//Programa a parte alta do minuto  H                                             //            
//////////////////////////////////////////////////////////////////////////////////        
            case menuProgramaMinutoH:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;              
                    if (tempProgDataHora > 5){tempProgDataHora = 0;}
                    arrayProgMinuto[0] = tempProgDataHora +'0';
                    marcaEdicao = 0;
                }                          
//valida o minuto programada e vai para o campo dia                          
                if (teclaPressionadaAtual == teclaSalva || teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    menuProgramacaoRelogioAtual = menuProgramaMinutoL;  
                    tempProgDataHora = arrayProgMinuto[1] - '0'; 
                }                                   
                break;
 //////////////////////////////////////////////////////////////////////////////////
//Programa a parte baixa do minuto  L                                            //            
//////////////////////////////////////////////////////////////////////////////////        
            case menuProgramaMinutoL:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;              
                    if (tempProgDataHora > 9){tempProgDataHora = 0;}
                    arrayProgMinuto[1] = tempProgDataHora +'0';
                    marcaEdicao = 0;
                }                          
//valida o minuto programada e vai para o campo dia                          
                if (teclaPressionadaAtual == teclaSalva || teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
                    teclaPressionadaAtual = teclaSolta;  
                    verificaMinutoValido();
                }                                   
                break;
//////////////////////////////////////////////////////////////////////////////////
//Programa o dia parte alta H                                                   //            
//////////////////////////////////////////////////////////////////////////////////               
            case menuProgramaDiaH:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;
                    if (tempProgDataHora > 3){tempProgDataHora = 0;}
                    arrayProgDia[0] = tempProgDataHora +'0';
                    marcaEdicao = 0;
                }                       
//valida dia programada e vai para o campo mes                  
                if (teclaPressionadaAtual == teclaSalva || teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    menuProgramacaoRelogioAtual = menuProgramaDiaL;
                    tempProgDataHora = arrayProgDia[1] - '0'; 
                    marcaEdicao = 1;
//                    tempProgDataHora = mesRelogio;
                }                                   
                break;
//////////////////////////////////////////////////////////////////////////////////
//Programa o dia parte alta L                                                   //            
//////////////////////////////////////////////////////////////////////////////////               
            case menuProgramaDiaL:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;
                    if (tempProgDataHora > 9){tempProgDataHora = 0;}
                    arrayProgDia[1] = tempProgDataHora +'0';
                    marcaEdicao = 0;
                }                       
//valida dia programada e vai para o campo mes                  
                if (teclaPressionadaAtual == teclaSalva || teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    menuProgramacaoRelogioAtual = menuProgramaMesH;
                    tempProgDataHora = arrayProgMes[0] - '0'; 
                    marcaEdicao = 1;
//                    tempProgDataHora = mesRelogio;
                }                                   
                break;
//////////////////////////////////////////////////////////////////////////////////
//Programa o Mes parte alta H                                                   //            
//////////////////////////////////////////////////////////////////////////////////          
            case menuProgramaMesH:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;
                    if (tempProgDataHora > 1){tempProgDataHora = 0;}
                    arrayProgMes[0] = tempProgDataHora +'0';
                    marcaEdicao = 0;
                }         
//valida a mes programada e vai para o campo ano                  
                if (teclaPressionadaAtual == teclaSalva || teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    menuProgramacaoRelogioAtual = menuProgramaMesL;
                    tempProgDataHora = arrayProgMes[1] - '0';
                    marcaEdicao = 1;
                }                                   
                break;
//////////////////////////////////////////////////////////////////////////////////
//Programa o Mes parte baixa L                                                  //            
//////////////////////////////////////////////////////////////////////////////////          
            case menuProgramaMesL:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;
                    if (tempProgDataHora > 9){tempProgDataHora = 0;}
                    arrayProgMes[1] = tempProgDataHora +'0';
                    marcaEdicao = 0;
                }         
//valida a mes programada e vai para o campo ano                  
                if (teclaPressionadaAtual == teclaSalva || teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    menuProgramacaoRelogioAtual = menuProgramaAnoH;
                    tempProgDataHora = arrayProgAno[0] - '0';
                    marcaEdicao = 1;
                }                                   
                break;
//////////////////////////////////////////////////////////////////////////////////
//Programa o Ano parte alta H                                                   //            
//////////////////////////////////////////////////////////////////////////////////                             
            case menuProgramaAnoH:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;
                    if (tempProgDataHora > 9){tempProgDataHora = 0;}
                    arrayProgAno[0] = tempProgDataHora +'0';
                    marcaEdicao = 0;
                }         
//valida o ano programado                          
                if (teclaPressionadaAtual == teclaSalva || teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    menuProgramacaoRelogioAtual = menuProgramaAnoL;
                    tempProgDataHora = arrayProgAno[1] - '0';
                    marcaEdicao = 1;
                }                               
                break;
//////////////////////////////////////////////////////////////////////////////////
//Programa o Ano parte baixa L                                                  //            
//////////////////////////////////////////////////////////////////////////////////                             
            case menuProgramaAnoL:
                if (teclaPressionadaAtual == teclaImprimeSetaAcima)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    tempProgDataHora++;
                    if (tempProgDataHora > 9){tempProgDataHora = 0;}
                    arrayProgAno[1] = tempProgDataHora +'0';
                    marcaEdicao = 0;
                }         
//valida o ano programado                          
                if (teclaPressionadaAtual == teclaTaraSetaEsquerda) 
                {
                    teclaPressionadaAtual = teclaSolta; 
                    marcaEdicao = 1;
                    menuProgramacaoRelogioAtual = menuProgramaHoraH;
                }
                
                if (teclaPressionadaAtual == teclaSalva)
                {
                    teclaPressionadaAtual = teclaSolta; 
                    verificaDataValida();
                }                               
                break;
			default:
				break;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////
//metodo que verifica a validade da hora programada                             //            
//////////////////////////////////////////////////////////////////////////////////
void verificaHoraValida (void)
{
    horaTemp = (((arrayProgHora[0] - '0') *10) + (arrayProgHora[1] - '0'));
    if (horaTemp > 24)
    {
        menuProgramacaoRelogioAtual = menuProgramaHoraH;
        tempProgDataHora = arrayProgHora[0] - '0';   
        marcaEdicao = 1;
        mostraTelaTemporariaLcd = 1;
        transfereArrayToArray(32,&caracterLcd[0],&backupTelaLcd[0]);
        if (linguagemSelecionadaMem == _PORTUGUES){transfereConstToArray(&telaHoraInvalidaLcdPT[0],&caracterLcd[0]);}
        if (linguagemSelecionadaMem == _INGLES){transfereConstToArray(&telaHoraInvalidaLcdING[0],&caracterLcd[0]);}
        if (linguagemSelecionadaMem == _ESPANHOL){transfereConstToArray(&telaHoraInvalidaLcdESP[0],&caracterLcd[0]);}
    }
    else
    {
        menuProgramacaoRelogioAtual = menuProgramaMinutoH;
        tempProgDataHora = arrayProgMinuto[0] - '0';   
        marcaEdicao = 1;
    }        
}
//////////////////////////////////////////////////////////////////////////////////
//metodo que verifica a validade do minuto programado                           //            
//////////////////////////////////////////////////////////////////////////////////
void verificaMinutoValido(void)
{
    minutoTemp = (((arrayProgMinuto[0] - '0') *10) + (arrayProgMinuto[1] - '0'));
    if (minutoTemp > 60)
    {
        menuProgramacaoRelogioAtual = menuProgramaMinutoH;
        tempProgDataHora = arrayProgMinuto[0] - '0';   
        marcaEdicao = 1;
        mostraTelaTemporariaLcd = 1;
        transfereArrayToArray(32,&caracterLcd[0],&backupTelaLcd[0]);
        if (linguagemSelecionadaMem == _PORTUGUES){transfereConstToArray(&telaHoraInvalidaLcdPT[0],&caracterLcd[0]);}
        if (linguagemSelecionadaMem == _INGLES){transfereConstToArray(&telaHoraInvalidaLcdING[0],&caracterLcd[0]);}
        if (linguagemSelecionadaMem == _ESPANHOL){transfereConstToArray(&telaHoraInvalidaLcdESP[0],&caracterLcd[0]);}
    }
    else
    {
        menuProgramacaoRelogioAtual = menuProgramaDiaH;
        tempProgDataHora = arrayProgDia[0] - '0';   
        marcaEdicao = 1;
    }        
}
//////////////////////////////////////////////////////////////////////////////////
//metodo que verifica a validade da data programada                             //            
//////////////////////////////////////////////////////////////////////////////////
void verificaDataValida(void)
{
    diaTemp = (((arrayProgDia[0] - '0') *10) + (arrayProgDia[1] - '0'));
    mesTemp = (((arrayProgMes[0] - '0') *10) + (arrayProgMes[1] - '0'));
    anoTemp = (((arrayProgAno[0] - '0') *10) + (arrayProgAno[1] - '0'));
    validaData();
    if (verificaValidade == 1)
    {
        mostraTelaTemporariaLcd = 1;
        menuProgramacaoRelogioAtual = menuProgramaDiaH;
        tempProgDataHora = arrayProgDia[0] - '0';   
        marcaEdicao = 1;
        transfereArrayToArray(32,&caracterLcd[0],&backupTelaLcd[0]);
        if (linguagemSelecionadaMem == _PORTUGUES){transfereConstToArray(&telaDataInvalidaLcdPT[0],&caracterLcd[0]);}
        if (linguagemSelecionadaMem == _INGLES){transfereConstToArray(&telaDataInvalidaLcdING[0],&caracterLcd[0]);}
        if (linguagemSelecionadaMem == _ESPANHOL){transfereConstToArray(&telaDataInvalidaLcdESP[0],&caracterLcd[0]);}
    }
    else
    {
        menuProgramacaoRelogioAtual = menuProgramaRelogioEmEspera;
        telaAcessaMenuConfiguraRelogio();
        horaRelogio = horaTemp;
        minutoRelogio = minutoTemp;
        diaMesRelogio = diaTemp;
        mesRelogio = mesTemp;
        anoRelogio = anoTemp;
        tempoLeituraRelogio = 2;
        grava_Relogio_i2c(0,minutoTemp,horaTemp,0,diaTemp,mesTemp,anoTemp);
    }        
}
//////////////////////////////////////////////////////////////////////////////////
//metodo que verifica se data definida e valida                                 //            
//////////////////////////////////////////////////////////////////////////////////
void validaData(void)
{  
    classificaMes();
    verificaValidade = 0;
    if (mesTemp == 2 && anoBissexto == 0 && diaTemp > 28){verificaValidade = 1;}
    if (mesTemp == 2 && anoBissexto == 1 && diaTemp > 29){verificaValidade = 1;}    
    if (mes31Dias == 0 && diaTemp > 30){verificaValidade = 1;} 
    if (diaTemp > 31){verificaValidade = 1;}  
    if (mesTemp > 12){verificaValidade = 1;}      
}
//////////////////////////////////////////////////////////////////////////////////
//metodo que classifica o tipo do mes                                           //            
//////////////////////////////////////////////////////////////////////////////////
void classificaMes(void)
{
    unsigned char mesTempClassificaData;
    unsigned char anoTempClassificaData;

    mes31Dias = 0;
    anoBissexto = 0;
    mesTempClassificaData = mesTemp;
    anoTempClassificaData = anoTemp;
    if (mesTempClassificaData == 2)
    {
        anoTempClassificaData =  anoTempClassificaData >> 2;
        anoTempClassificaData =  anoTempClassificaData && 0b00000001;
        if (anoTempClassificaData == 0){anoBissexto = 0;}
        else{anoBissexto = 1;}
    }
    else
    {
        if ((mesTempClassificaData == 1) || (mesTempClassificaData == 3) || (mesTempClassificaData == 5)
             || (mesTempClassificaData == 7) || (mesTempClassificaData == 8) || (mesTempClassificaData == 10)
             || (mesTempClassificaData == 12))
        {
            mes31Dias = 1;
        }
        else
        {
                mes31Dias = 0;
        }
    }
}

void telaMostraProgExibeRelogio (void)
{
    if (linguagemSelecionadaMem == _PORTUGUES){transfereConstToArray(&telaProgExibeRelogioPT[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _INGLES){transfereConstToArray(&telaProgExibeRelogioING[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _ESPANHOL){transfereConstToArray(&telaProgExibeRelogioESP[0],&caracterLcd[0]);}

    if (tempProgDataHora == 1)
    {
        if (linguagemSelecionadaMem == _PORTUGUES){transfereConstToArray(&telaHabilitadoPT[0],&caracterLcd[16]);}
        if (linguagemSelecionadaMem == _INGLES){transfereConstToArray(&telaHabilitadoING[0],&caracterLcd[16]);}
        if (linguagemSelecionadaMem == _ESPANHOL){transfereConstToArray(&telaHabilitadoESP[0],&caracterLcd[16]);}
    } else {
        if (linguagemSelecionadaMem == _PORTUGUES){transfereConstToArray(&telaDesabilitadoPT[0],&caracterLcd[16]);}
        if (linguagemSelecionadaMem == _INGLES){transfereConstToArray(&telaDesabilitadoING[0],&caracterLcd[16]);}   
        if (linguagemSelecionadaMem == -_ESPANHOL){transfereConstToArray(&telaDesabilitadoESP[0],&caracterLcd[16]);}
    }

#ifdef displaySeteSegmentosLcd
    telaMostraProgExibeRelogioSeteSegmentos();
#endif
}

void telaMostraProgHoraMin (void)
{
    if (linguagemSelecionadaMem == _PORTUGUES){transfereConstToArray(&telaProgHoraDataLcdPT[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _INGLES){transfereConstToArray(&telaProgHoraDataLcdING[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _ESPANHOL){transfereConstToArray(&telaProgHoraDataLcdESP[0],&caracterLcd[0]);}

    caracterLcd[16]= arrayProgHora[0];
    caracterLcd[17]= arrayProgHora[1];
    caracterLcd[18] = ':';
    caracterLcd[19]= arrayProgMinuto[0];
    caracterLcd[20]= arrayProgMinuto[1];      

    carregaArrayComEspacoAscii(21,&caracterLcd[0]);

#ifdef displaySeteSegmentosLcd
    if ((menuProgramacaoRelogioAtual == menuProgramaHoraH) || (menuProgramacaoRelogioAtual == menuProgramaHoraL))
    {
        telaMostraProgHoraSeteSegmentos();
    }
    if ((menuProgramacaoRelogioAtual == menuProgramaMinutoH) || (menuProgramacaoRelogioAtual == menuProgramaMinutoL))
    {
        telaMostraProgMinutoSeteSegmentos();
    }
#endif
}

//////////////////////////////////////////////////////////////////////////////////
//metodo que controla a visualizacao da edicao                                  //            
//////////////////////////////////////////////////////////////////////////////////
void telaMostraProgHoraData(void)
{
    if (menuProgramacaoRelogioAtual != menuProgramaRelogioEmEspera)
    {
        if (menuProgramacaoRelogioAtual == menuProgramaExibeRelogio) 
        {
            telaMostraProgExibeRelogio();
        } 
        else if (mostraTelaTemporariaLcd == 0)
        { 
            if (linguagemSelecionadaMem == _PORTUGUES){transfereConstToArray(&telaProgHoraDataLcdPT[0],&caracterLcd[0]);}
        	if (linguagemSelecionadaMem == _INGLES){transfereConstToArray(&telaProgHoraDataLcdING[0],&caracterLcd[0]);}
        	if (linguagemSelecionadaMem == _ESPANHOL){transfereConstToArray(&telaProgHoraDataLcdESP[0],&caracterLcd[0]);}

            caracterLcd[16]= arrayProgHora[0];
            caracterLcd[17]= arrayProgHora[1];
            caracterLcd[18] = ':';
            caracterLcd[19]= arrayProgMinuto[0];
            caracterLcd[20]= arrayProgMinuto[1];      
            caracterLcd[21] = ' ';
            caracterLcd[22]= arrayProgDia[0];
            caracterLcd[23]= arrayProgDia[1];
            caracterLcd[24] = '/';
            caracterLcd[25]= arrayProgMes[0];
            caracterLcd[26]= arrayProgMes[1];          
            caracterLcd[27] = '/';
            caracterLcd[28]= arrayProgAno[0];
            caracterLcd[29]= arrayProgAno[1];  

#ifdef displaySeteSegmentosLcd
            telaMostraProgHoraDataSeteSegmentos();
#endif

//controla a visualizacao da programacao da hora        
            if (menuProgramacaoRelogioAtual == menuProgramaHoraH)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[16] = '_';
                    dadoLcdSetSegmentos[5] = ' ';
                }
            }
            if (menuProgramacaoRelogioAtual == menuProgramaHoraL)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[17] = '_';
                    dadoLcdSetSegmentos[6] = ' ';
                }
            }               
//controla a visualizacao da programacao da minuto        
            if (menuProgramacaoRelogioAtual == menuProgramaMinutoH)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[19] = '_';
                    dadoLcdSetSegmentos[5] = ' ';
                }
            }
            if (menuProgramacaoRelogioAtual == menuProgramaMinutoL)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[20] = '_';
                    dadoLcdSetSegmentos[6] = ' ';
                }
            }                    
//controla a visualizacao da programacao do dia        
            if (menuProgramacaoRelogioAtual == menuProgramaDiaH)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[22] = '_';
                    dadoLcdSetSegmentos[5] = ' ';
                }
            }     
            if (menuProgramacaoRelogioAtual == menuProgramaDiaL)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[23] = '_';
                    dadoLcdSetSegmentos[6] = ' ';
                }
            }                                      
//controla a visualizacao da programacao do mes        
            if (menuProgramacaoRelogioAtual == menuProgramaMesH)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[25] = '_';
                    dadoLcdSetSegmentos[5] = ' ';
                }
            }
            if (menuProgramacaoRelogioAtual == menuProgramaMesL)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[26] = '_';
                    dadoLcdSetSegmentos[6] = ' ';
                }
            }                             
//controla a visualizacao da programacao do ano        
            if (menuProgramacaoRelogioAtual == menuProgramaAnoH)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[28] = '_';
                    dadoLcdSetSegmentos[5] = ' ';
                }
            }
            if (menuProgramacaoRelogioAtual == menuProgramaAnoL)
            {
                if (piscaCaracter == 1 && marcaEdicao == 1)
                {
                    caracterLcd[29] = '_';
                    dadoLcdSetSegmentos[6] = ' ';
                }
            }
        }               
    }    
}
