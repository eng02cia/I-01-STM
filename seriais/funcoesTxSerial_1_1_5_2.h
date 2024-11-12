//////////////////////////////////////////////////////////////////////////////////		
//      funcoes que controlam a transmis�o de dados pela serial 1         		//	
//////////////////////////////////////////////////////////////////////////////////
#include "transfereArrayToArray.h"
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart5;
//////////////////////////////////////////////////////////////////////////////////		
//Inicializa as variaveis utilizadas na Transmis�o da serial 1					//
//////////////////////////////////////////////////////////////////////////////////		
void iniciaVariaveisTxSerial_1(void)
{
	velocidadeTxSerial_1 = velocidadeTxSerial_1Mem;
    if (velocidadeTxSerial_1 == velocidade1200Kbps){velocidadeSerial_1_1200Kbps();}
    if (velocidadeTxSerial_1 == velocidade2400Kbps){velocidadeSerial_1_2400Kbps();}
    if (velocidadeTxSerial_1 == velocidade4800Kbps){velocidadeSerial_1_4800Kbps();}
    if (velocidadeTxSerial_1 == velocidade9600Kbps){velocidadeSerial_1_9600Kbps();}
    if (velocidadeTxSerial_1 == velocidade19200Kbps){velocidadeSerial_1_19200Kbps();} 
    if (velocidadeTxSerial_1 == velocidade38400Kbps){velocidadeSerial_1_38400Kbps();} 
    if (velocidadeTxSerial_1 == velocidade57600Kbps){velocidadeSerial_1_57600Kbps();} 
    if (velocidadeTxSerial_1 == velocidade115200Kbps){velocidadeSerial_1_115200Kbps();}
}
//////////////////////////////////////////////////////////////////////////////////		
//funcao que faz a transmis�o de dados pela serial 1   		        			//
//////////////////////////////////////////////////////////////////////////////////		
void controleTxSerial_1(void)
{

	/*
    if (statusSaidaDadosSerial_1Mem != _MODBUS_RTU)
    {
        if (flagTxSerial_1.txSerial_1 == 1 & TXSTA1bits.TRMT == 1)
        {
            if (quantidadeBytesTxSerial_1 == 0)
            {
                flagTxSerial_1.txSerial_1 = 0;
                flagTxSerial_1.transmitindoSerial_1 = 0;
                indexTxSerial_1 = 0;
                if (statusPortaSerial_1Mem == _RS485){CONTROL485_Pin = 0;}
            }
            else
            {
                TXREG1= frameTxSerial_1[indexTxSerial_1];
                quantidadeBytesTxSerial_1--;
                indexTxSerial_1++;
                flagTxSerial_1.txSerial_1 = 1;
            }
		}
	}	*/
}
//////////////////////////////////////////////////////////////////////////////////		
//funcao que controla a transmis�o de dados pela serial 1   					//
//////////////////////////////////////////////////////////////////////////////////	
void controleTxFrameSerial_1(void)
{
//////////////////////////////////////////////////////////////////////////////////		
//tranmiss�o continua de dados protocolo 1                     					//
//////////////////////////////////////////////////////////////////////////////////	
    if (statusLigaDesliga == _LIGADO
    && menuCalibraIndicador == menuCalibraIndicadorEmEspera
    && statusSaidaDadosSerial_1Mem == _TRANSMISSAOCONTINUA_1
    && statusComunicacaoSerial_1Mem == _SERIAL_1ATIVADA)
    {
// controle da quantidade de frames transmitido por segundo
//base de temp 1 mls            
        tempo1TxSerial_1 = 950/qtFramePorSegundoMem;
        if (++tempoTxSeria_1 >= tempo1TxSerial_1)
        {
            tempoTxSeria_1 = 0;
            if (flagTxSerial_1.transmitindoSerial_1 == 0)
            {                
                frameTxSerial_1[0] = 0x02;
                frameTxSerial_1[1] = 'B';
                frameTxSerial_1[2] = ':' ;                           
                transfereArrayToArray(7,&pesoBrutoIndicadorAscii[0],&frameTxSerial_1[3]);
//peso tara                                       
                frameTxSerial_1[10] = 'T';
                frameTxSerial_1[11] = ':';                           
                transfereArrayToArray(7,&pesoTaraIndicadorAscii[0],&frameTxSerial_1[12]); 
//peso liquido
                frameTxSerial_1[19] = 'L';
                frameTxSerial_1[20] = ':';                           
                transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&frameTxSerial_1[21]);                                       
                frameTxSerial_1[28] = 0x0D;
                frameTxSerial_1[29] = 0x0A; 
                flagTxSerial_1.txSerial_1 = 1;
                quantidadeBytesTxSerial_1 = 30;
                indexTxSerial_1 = 0;
                flagTxSerial_1.transmitindoSerial_1 = 1;
                HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin,GPIO_PIN_SET);
                if (statusPortaSerial_1Mem == _RS485){HAL_UART_Transmit_IT(&huart5,&frameTxSerial_1[0],quantidadeBytesTxSerial_1);}
                if (statusPortaSerial_1Mem == _RS232){HAL_UART_Transmit_IT(&huart1,&frameTxSerial_1[0],quantidadeBytesTxSerial_1);}
            }
            else
            {
                tempoTxSeria_1--;
            }
        }
    }
//////////////////////////////////////////////////////////////////////////////////		
//tranmiss�o continua de dados protocolo 2                     					//
//////////////////////////////////////////////////////////////////////////////////       
    if (statusLigaDesliga == _LIGADO
    && menuCalibraIndicador == menuCalibraIndicadorEmEspera
    && statusSaidaDadosSerial_1Mem == _TRANSMISSAOCONTINUA_2
    && statusComunicacaoSerial_1Mem == _SERIAL_1ATIVADA)
    {
// controle da quantidade de frames transmitido por segundo
//base de temp 1 mls            
        tempo1TxSerial_1 = 950/qtFramePorSegundoMem;
        if (++tempoTxSeria_1 >= tempo1TxSerial_1)
        {
            tempoTxSeria_1 = 0;
            if (flagTxSerial_1.transmitindoSerial_1 == 0)
            {                
                frameTxSerial_1[0] = 0xD;               
                transfereArrayToArray(6,&pesoBrutoIndicadorAscii[1],&frameTxSerial_1[1]);
                indexCorrigePeso = &frameTxSerial_1[1];   
                while(*indexCorrigePeso == ' ')
                {    
                    *indexCorrigePeso = '0';
                    indexCorrigePeso++;
                }                             
                frameTxSerial_1[7] = 0x0A; 
                flagTxSerial_1.txSerial_1 = 1;
                quantidadeBytesTxSerial_1 = 8;
                indexTxSerial_1 = 0;
                flagTxSerial_1.transmitindoSerial_1 = 1;
                HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin,GPIO_PIN_SET);
                if (statusPortaSerial_1Mem == _RS485){HAL_UART_Transmit_IT(&huart5,&frameTxSerial_1[0],quantidadeBytesTxSerial_1);}
                if (statusPortaSerial_1Mem == _RS232){HAL_UART_Transmit_IT(&huart1,&frameTxSerial_1[0],quantidadeBytesTxSerial_1);}
            }
            else
            {
                tempoTxSeria_1--;
            }
        }
    }    
    
//////////////////////////////////////////////////////////////////////////////////		
//controle da transmiss�o serial quando no protocolo Sigma Ascii    			//
// && statusSaidaDadosSerial_1Mem == _PROTOCOLO_SA &&
// statusComunicacaoSerial_1Mem == _SERIAL_1ATIVADA)
// menuCalibraIndicador == menuCalibraIndicadorEmEspera       
  //////////////////////////////////////////////////////////////////////////////////	        
/*    if (statusLigaDesliga == _LIGADO
    && statusSaidaDadosSerial_1Mem == _PROTOCOLO_SA
    && statusComunicacaoSerial_1Mem == _SERIAL_1ATIVADA)
    {
    	
//////////////////////////////////////////////////////////////////////////////////		
//retorna uma confirmacao de recebimento valida do Client						//
//////////////////////////////////////////////////////////////////////////////////		
        if (flagTxSerial_1.enviaConfirmacaoDeRecebimento == 1 & flagTxSerial_1.transmitindoSerial_1 == 0)
        {
            flagTxSerial_1.transmitindoSerial_1 = 1;
            flagTxSerial_1.enviaConfirmacaoDeRecebimento = 0;
            quantidadeBytesTxSerial_1 = quantidadeTempBytesTxSerial_1;
            transfereArrayToArray(quantidadeTempBytesTxSerial_1,&frameTempTxSerial_1[0],&frameTxSerial_1[0]);
            quantidadeBytesTxSerial_1 = quantidadeTempBytesTxSerial_1;
            iniciaTxSerial_1();	
            if (statusPortaSerial_1Mem == _RS485){HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin,GPIO_PIN_SET);}
        }
        else
        {
            if (transmiteStatusPeso == 1 & flagTxSerial_1.transmitindoSerial_1 == 0)
            {
                transmiteStatusPeso = 0;
                inteiroTo2BytesAscii(enderecoIndicadorMem,&frameTxSerial_1[0]);
                frameTxSerial_1[2] = 'B';
                frameTxSerial_1[3] = ':' ;                           
                transfereArrayToArray(7,&pesoBrutoIndicadorAscii[0],&frameTxSerial_1[4]);         
//peso tara                                       
                frameTxSerial_1[11] = 'T';
                frameTxSerial_1[12] = ':';   
                transfereArrayToArray(7,&pesoTaraIndicadorAscii[0],&frameTxSerial_1[13]);                      
//peso liquido
                frameTxSerial_1[20] = 'L';
                frameTxSerial_1[21] = ':';                           
                transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&frameTxSerial_1[22]);
                frameTxSerial_1[29] = 0x0D;
                frameTxSerial_1[30] = 0x0A; 
                flagTxSerial_1.txSerial_1 = 1;
                quantidadeBytesTxSerial_1 = 31;
                indexTxSerial_1 = 0;
                flagTxSerial_1.transmitindoSerial_1 = 1; 
                if (statusPortaSerial_1Mem == _RS485){HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin,GPIO_PIN_SET);}
            }
            if (transmiteStatusDaPesagem == 1 & flagTxSerial_1.transmitindoSerial_1 == 0)
            {
                transmiteStatusDaPesagem = 0;
                inteiroTo2BytesAscii(enderecoIndicadorMem,&frameTxSerial_1[0]);
                frameTxSerial_1[2] = 'S';
                frameTxSerial_1[3] = 'F';
                frameTxSerial_1[4] = ':';
//carrega o status do zero        
                if (indicadorEmZero){frameTxSerial_1[5] = '1';}
                else{frameTxSerial_1[5] = '0';}
//carrega o status da tara        
                if (controleTara == _TARAATIVADA){frameTxSerial_1[6] = '1';}
                else{frameTxSerial_1[6] = '0';}
//carrega o status da sub carga
                if (statusControleSubCarga == 1){frameTxSerial_1[7] = '1';}
                else{frameTxSerial_1[7] = '0';}
//carrega o status da sobre carga
                if (statusControleSobreCarga == 1){frameTxSerial_1[8] = '1';}
                else{frameTxSerial_1[8] = '0';}        
                frameTxSerial_1[9] = '\r';//line feed(LF))
                frameTxSerial_1[10] = '\n';//Carriage return(CR)                   
                flagTxSerial_1.txSerial_1 = 1;
                quantidadeBytesTxSerial_1 = 11;
                indexTxSerial_1 = 0;
                flagTxSerial_1.transmitindoSerial_1 = 1;  
                if (statusPortaSerial_1Mem == _RS485){HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin,GPIO_PIN_SET);}
            }
        }
    }*/
}
//////////////////////////////////////////////////////////////////////////////////    
//prepara a para enviar a resposta                                              //
//////////////////////////////////////////////////////////////////////////////////  
void iniciaTxSerial_1(void)
{
    flagTxSerial_1.txSerial_1 = 1;
    flagTxSerial_1.transmitindoSerial_1 = 1;
    indexTxSerial_1 = 0;
}  
//////////////////////////////////////////////////////////////////////////////////    
//tempo de controle da transmisss�o dos frames automaticos                      //
//////////////////////////////////////////////////////////////////////////////////
void tempoControleTransmiteFrameAutomatico(void)
{
    if (flagTxSerial_1.transmitindoSerial_1 == 0)
    {
        if (statusPortaSerial_1Mem == _RS232)
        {  
            if (statusTransmiteAutomaticoMem[0] == _ATIVA && statusLigaDesliga == _LIGADO)
            {
                if (++tempoTxSeria_1 > statusTransmiteAutomaticoMem[1])
                {
                    tempoTxSeria_1 = 0; 
                    transmiteStatusPeso = 1;
                    transmiteStatusDaPesagem = 1;
                }             
            }
        }       
    }
}
 
