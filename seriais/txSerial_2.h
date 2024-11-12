//////////////////////////////////////////////////////////////////////////////////		
//   funcoes tx serial 2                                                        //	
//////////////////////////////////////////////////////////////////////////////////
// Faz o tratamento de erro da serial 2
extern UART_HandleTypeDef huart2;

extern UART_HandleTypeDef huart3;


void trataErroSerial_2(void)
{
	/*
    if (RCSTA2bits.OERR == 1)
    {
        RCSTA2bits.CREN = 0;	
        RCSTA2bits.CREN = 1;
    }*/
}	
//////////////////////////////////////////////////////////////////////////////////		
//Inicializa  serial 2                                       					//
//////////////////////////////////////////////////////////////////////////////////

void inicializaSerial_2(void)
{
	/*
}
    TXSTA2bits.BRGH = 1;
	RCSTA2bits.SPEN = 1;
	RCSTA2bits.CREN = 1;
    TXSTA2bits.TXEN = 1;
  	BAUDCON2bits.BRG16 = 1; 

#ifdef indicadorI01_1_5_2
    TRISBbits.TRISB3 = 1;
    TRISBbits.TRISB2 = 1;    
    TX2PPS = 0b01011; // dereciona o modulo tx serial para o portb3
    RB3PPS = 0b01011; 
    RX2PPS = 0b10010;  // dereciona o modulo rx serial para o portb 2   
#endif
#ifdef indicadorI01_1_5_3
    TRISGbits.TRISG1 = 1;
    TRISGbits.TRISG2 = 1; 

    RG1PPS = 0x0E; // RG1 TX2
    CK2PPS = 0x31;
    RX2PPS = 0x32;  // RG2 RX2    
    
#endif    
    SPBRGH2 = 6;// velicidade serial 2 9600 kbps
	SPBRG2 = 130;
	*/
}
//////////////////////////////////////////////////////////////////////////////////		
//funcao que controla a impress�o pela serial 2         						//
//////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////		
//funcao que controla a transmiss�o de dados para o display remoto  			//
//////////////////////////////////////////////////////////////////////////////////		
void controleTxFrameSerial_2(void)
{
    if (statusLigaDesliga == _LIGADO
    && menuCalibraIndicador == menuCalibraIndicadorEmEspera
    && exibeVersionControl  == 0)
    {
// controle da quantidade de frames transmitido por segundo
//base de temp 1 mls                
        if (transmitindoSerial_2 == 0)
        {
            if (++tempoTxSerial_2 >= 150)
            {
                tempoTxSerial_2 = 0;
                if (statusSaidaDadosSerial_2Mem == _TRANSMISSAOCONTINUA_1)
                {
                    frameTxSerial_2[0] = 0x02;
                    frameTxSerial_2[1] = 'B';
                    frameTxSerial_2[2] = ':' ; 
                    if (controleTara == _TARAATIVADA)
                    {
                        transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&frameTxSerial_2[3]);
                    }
                    else
                    {
                        transfereArrayToArray(7,&pesoBrutoIndicadorAscii[0],&frameTxSerial_2[3]);
                    }                    
//peso tara                                       
                    frameTxSerial_2[10] = 'T';
                    frameTxSerial_2[11] = ':';                           
                    transfereArrayToArray(7,&pesoTaraIndicadorAscii[0],&frameTxSerial_2[12]); 
//peso liquido
                    frameTxSerial_2[19] = 'L';
                    frameTxSerial_2[20] = ':';                           
                    transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&frameTxSerial_2[21]);                                       
                    frameTxSerial_2[28] = 0x0D;
                    frameTxSerial_2[29] = 0x0A; 
                    flagTxSerial_2 = 1;
                    qtBytesTxSerial_2 = 30;
                    indexTxSerial_2 = 0;
                    transmitindoSerial_2 = 1;
                    HAL_UART_Transmit_IT(&huart2,&frameTxSerial_2[0],qtBytesTxSerial_2);
                }    
                if (statusSaidaDadosSerial_2Mem == _TRANSMISSAOCONTINUA_2)
                {
                    frameTxSerial_2[0] = 0x0D;
                    if (controleTara == _TARAATIVADA)
                    {
                        transfereArrayToArray(6,&pesoLiquidoIndicadorAscii[1],&frameTxSerial_2[1]);
                    }   
                    else
                    {
                        transfereArrayToArray(6,&pesoBrutoIndicadorAscii[1],&frameTxSerial_2[1]);
                    }                    
                    indexCorrigePeso = &frameTxSerial_2[1];    
                    while(*indexCorrigePeso == ' ')
                    {    
                        *indexCorrigePeso = '0';
                        indexCorrigePeso++;
                    }                    
                    frameTxSerial_2[7] = 0x0A; 
                    flagTxSerial_2 = 1;
                    qtBytesTxSerial_2 = 8;
                    transmitindoSerial_2 = 1;
                    HAL_UART_Transmit_IT(&huart2,&frameTxSerial_2[0],qtBytesTxSerial_2);
                }                                    
            }
        }
    }
}



