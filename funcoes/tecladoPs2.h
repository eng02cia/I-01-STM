extern  GPIO_InitTypeDef GPIO_InitStruct = {0};
//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
// Fun��es de comunicacao com teclado PS2                                   	//
//////////////////////////////////////////////////////////////////////////////////
//  DESCRIcao DO PROTOCOLO:													  	//
//  Pinos Utilizados
// Portb 00 clock
// Portb 01 data
//////////////////////////////////////////////////////////////////////////////////		
//funcao que inicializa o barramento de comunicacao com teclado ps2 			//
//////////////////////////////////////////////////////////////////////////////////		
void inicializaComunicacaoPs2(void)
{
    if(tecladoPs2Inicializado == 0)
    {
    	HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
    	__HAL_RCC_GPIOC_CLK_DISABLE();
        tecladoPs2Inicializado = 1;
       	HAL_GPIO_DeInit(pinoDataPs2_GPIO_Port, &GPIO_InitStruct);
       	GPIO_InitStruct.Pin = pinoDataPs2_Pin;
  	  	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  	    GPIO_InitStruct.Pull = GPIO_NOPULL;
        HAL_GPIO_Init(pinoDataPs2_GPIO_Port, &GPIO_InitStruct);


        HAL_GPIO_DeInit(pinoClockPs2_GPIO_Port, &GPIO_InitStruct);
       	GPIO_InitStruct.Pin = pinoClockPs2_Pin;
  	  	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  	    GPIO_InitStruct.Pull = GPIO_NOPULL;
  	    HAL_GPIO_Init(pinoClockPs2_GPIO_Port, &GPIO_InitStruct);

  	  __HAL_RCC_GPIOC_CLK_ENABLE();
  	  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que faz a recepcao de dados do teclado ps2                         	//
//          																	//
//////////////////////////////////////////////////////////////////////////////////		
void recebeDadoTecladoPs2Interrupt(void)	
{
    switch(statusRxPs2Atual)
    {
//////////////////////////////////////////////////////////////////////////////////        
        case rxPs2Start:
        	tempPinoData = HAL_GPIO_ReadPin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin);
            if(tempPinoData == 0)
            {
                statusRxPs2Atual = rxPs2Byte;
                rloopRxDataTeclado = 0;
                dataRxTecladoPs2 = 0;  
                paridadeRxPs2.Byte = 0;
            }
        break;
//////////////////////////////////////////////////////////////////////////////////        
        case rxPs2Byte:
        	tempPinoData = HAL_GPIO_ReadPin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin);
            if(tempPinoData == 0)
            {
                dataRxTecladoPs2 = dataRxTecladoPs2 + 0;
            }            
            else
            {
                dataRxTecladoPs2 = dataRxTecladoPs2 + 0x80;
                paridadeRxPs2.Byte++;
            }
           
            if(++rloopRxDataTeclado == 8 )
            {
                statusRxPs2Atual = rxPs2Paridade;               
            }
            else
            {
                dataRxTecladoPs2 = dataRxTecladoPs2 >> 1;
            }
        break;
//////////////////////////////////////////////////////////////////////////////////        
        case rxPs2Paridade:

            if(paridadeRxPs2.St.bitParidade == 1)
            {
            	tempPinoData = HAL_GPIO_ReadPin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin);
                if(tempPinoData == 0)
                {
                    statusRxPs2Atual = rxPs2Stop;
                }
                else
                {
                    statusRxPs2Atual = rxPs2Start;
                }                
            }
            if(paridadeRxPs2.St.bitParidade == 0)
            {
            	tempPinoData = HAL_GPIO_ReadPin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin);
                if(tempPinoData == 1)
                {
                    statusRxPs2Atual = rxPs2Stop;
                }
                else
                {
                    statusRxPs2Atual = rxPs2Start;
                }                
            }
        break;
//////////////////////////////////////////////////////////////////////////////////        
        case rxPs2Stop: 
            statusRxPs2Atual = rxPs2Start;                        
            dataTeclaPresPs2[indexDataTeclaPresPs2] = dataRxTecladoPs2; 
            indexDataTeclaPresPs2++;
            if(indexDataTeclaPresPs2 > 19)
            {
                indexDataTeclaPresPs2 = 0;
            }
            tempPinoData = HAL_GPIO_ReadPin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin);
            if(tempPinoData == 1)
            {
                if(configuraTecladoPs2 == 0)
                {
                    if(dataRxTecladoPs2 != 0xFE && dataRxTecladoPs2 != 0xFA)
                    {
                        dataTeclaPs2 = dataRxTecladoPs2;
                        flagTrataTeclaPs2 = 1; 
                        funcaoVerificaTeclaValidaPs2();
                    }
                }
//verifica se � confirmacao do recebimento do pedido de configuracao do teclado
                if(dataRxTecladoPs2 == 0xFA)
                {
//verifica se � configuracao do teclado                
                    if(configuraTecladoPs2 == 1)
                    {
                        dataTxPs2 = statusTecladoPs2.Byte;
                        configuraTecladoPs2 = 0;
                        dataTxPs2Backup = dataTxPs2;
                        startTxTecladoPs2Interrupt();       
                    }
                }
//verifica se esta sendo solicitado o reenvio do ultimo dado            
                if(dataRxTecladoPs2 == 0xFE)
                {
                    dataTxPs2 = dataTxPs2Backup;
                    startTxTecladoPs2Interrupt();                 
                } 
            }
        break;                   
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que inicia a transmis�o de dados para o teclado                       	//
//          																	//
//////////////////////////////////////////////////////////////////////////////////	
void startTxTecladoPs2Interrupt(void)	
{
//prepara start pino clock ps2    

	HAL_NVIC_DisableIRQ(EXTI15_10_IRQn);
	__HAL_RCC_GPIOC_CLK_DISABLE();
    HAL_GPIO_DeInit(pinoClockPs2_GPIO_Port, &GPIO_InitStruct);
   	GPIO_InitStruct.Pin = pinoClockPs2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(pinoClockPs2_GPIO_Port, &GPIO_InitStruct);


    HAL_GPIO_WritePin(pinoClockPs2_GPIO_Port, pinoClockPs2_Pin, GPIO_PIN_RESET);

    delayMicroSegundosPs2(1600);
//prepara start pino data ps2


	HAL_GPIO_DeInit(pinoDataPs2_GPIO_Port, &GPIO_InitStruct);
	GPIO_InitStruct.Pin = pinoDataPs2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(pinoDataPs2_GPIO_Port, &GPIO_InitStruct);


	HAL_GPIO_WritePin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin, GPIO_PIN_RESET);
    delayMicroSegundosPs2(100);
//libera pino de clock para o teclado ps2

    HAL_GPIO_WritePin(pinoClockPs2_GPIO_Port, pinoClockPs2_Pin, GPIO_PIN_SET);

    HAL_GPIO_DeInit(pinoClockPs2_GPIO_Port, &GPIO_InitStruct);
   	GPIO_InitStruct.Pin = pinoClockPs2_Pin;
	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	HAL_GPIO_Init(pinoClockPs2_GPIO_Port, &GPIO_InitStruct);

	__HAL_RCC_GPIOC_CLK_ENABLE();
	HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);
    statusInterruptPs2Atual = interruptTxPs2;
    statusTxPs2Atual = txPs2Start; 
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que transmite dados para o teclado interrupcao                       	//
//          																	//
//////////////////////////////////////////////////////////////////////////////////	
void transmiteDadoTecladoPs2Interrupt (void)	
{
     switch(statusTxPs2Atual)
    {
//////////////////////////////////////////////////////////////////////////////////        
        case txPs2Start:
            statusTxPs2Atual = txPs2Byte;
            rloopTxPs2 = 0;
            paridadeTxPs2.Byte = 0;
        break;
//////////////////////////////////////////////////////////////////////////////////        
        case txPs2Byte: 
            tempTxPs2 = dataTxPs2;
            tempTxPs2 = tempTxPs2 & 0b00000001;            
            if(tempTxPs2 == 0)
            {
            	HAL_GPIO_WritePin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin, GPIO_PIN_RESET);
            }
            else
            {
                paridadeTxPs2.Byte++;
                HAL_GPIO_WritePin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin, GPIO_PIN_SET);
            }            
            dataTxPs2 = dataTxPs2 >> 1;
            if(++rloopTxPs2 == 8)
            {
                statusTxPs2Atual = txPs2Paridade;
            }            
        break;    
//////////////////////////////////////////////////////////////////////////////////        
        case txPs2Paridade: 
            if(paridadeTxPs2.St.bitParidade == 0)
            {
            	HAL_GPIO_WritePin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin, GPIO_PIN_SET);
            }
            else
            {
            	HAL_GPIO_WritePin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin, GPIO_PIN_RESET);
            }  
            statusTxPs2Atual = txPs2BitAcknowledge;
        break;        
//////////////////////////////////////////////////////////////////////////////////        
        case txPs2BitAcknowledge: 

        	__HAL_RCC_GPIOC_CLK_DISABLE();
        	HAL_GPIO_DeInit(pinoDataPs2_GPIO_Port, &GPIO_InitStruct);
        	GPIO_InitStruct.Pin = pinoDataPs2_Pin;
        	GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
        	GPIO_InitStruct.Pull = GPIO_NOPULL;
        	HAL_GPIO_Init(pinoDataPs2_GPIO_Port, &GPIO_InitStruct);

        	__HAL_RCC_GPIOC_CLK_ENABLE();
            statusTxPs2Atual = txPs2ChecaAcknowledge;
        break; 
//////////////////////////////////////////////////////////////////////////////////
        case txPs2ChecaAcknowledge:
        	tempPinoData = HAL_GPIO_ReadPin(pinoDataPs2_GPIO_Port, pinoDataPs2_Pin);
            if(tempPinoData == 0)
            {
                statusInterruptPs2Atual = interruptRxPs2;
            }
        break;                 
    }           
}
//////////////////////////////////////////////////////////////////////////////////
//faz delay de em micro segundos                                                //
//////////////////////////////////////////////////////////////////////////////////
void delayMicroSegundosPs2(unsigned int delayInterno)
{
    while (delayInterno !=0)
    {
        delayInterno--;
    }
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que controla o tempo maximo premitido para configuracao do teclado     //
//////////////////////////////////////////////////////////////////////////////////
void metodoTempoControleConfigPs2(void)
{
    if(configuraTecladoPs2 == 1)
    {
        if(++tempoMaxConfigTecladoPs2 > 500)
        {
            tempoMaxConfigTecladoPs2 = 0;
            configuraTecladoPs2 = 0;            
        }
    }    
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que ativa a funcao scrolllock do teclado Ps2                           //
//////////////////////////////////////////////////////////////////////////////////
void metodoAtivascrollLockTecladoPs2(void)
{
    dataTxPs2 = 0xED;    
    dataTxPs2Backup = 0xED;
    configuraTecladoPs2 = 1;
    statusTecladoPs2.St.scrollLock = 1;
    configuraTecladoPs2 = 1;
    startTxTecladoPs2Interrupt();
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que ativa a funcao NumLock do teclado Ps2                              //
//////////////////////////////////////////////////////////////////////////////////
void metodoAtivaNumLockTecladoPs2(void)
{
    dataTxPs2 = 0xED;    
    dataTxPs2Backup = 0xED;
    configuraTecladoPs2 = 1;
    statusTecladoPs2.St.numLock = 1;
    configuraTecladoPs2 = 1;
    startTxTecladoPs2Interrupt();
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que ativa a funcao capsLock do teclado Ps2                             //
//////////////////////////////////////////////////////////////////////////////////
void metodoAtivaCapsLockTecladoPs2(void)
{
    dataTxPs2 = 0xED;    
    dataTxPs2Backup = 0xED;
    configuraTecladoPs2 = 1;
    statusTecladoPs2.St.capsLock = 1;
    configuraTecladoPs2 = 1;
    startTxTecladoPs2Interrupt();
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que ativa a funcao scrolllock do teclado Ps2                           //
//////////////////////////////////////////////////////////////////////////////////
void metodoDesativascrollLockTecladoPs2(void)
{
    dataTxPs2 = 0xED;    
    dataTxPs2Backup = 0xED;
    configuraTecladoPs2 = 1;
    statusTecladoPs2.St.scrollLock = 0;
    configuraTecladoPs2 = 1;
    startTxTecladoPs2Interrupt();    
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que Desativa a funcao NumLock do teclado Ps2                              //
//////////////////////////////////////////////////////////////////////////////////
void metodoDesativaNumLockTecladoPs2(void)
{
    dataTxPs2 = 0xED;    
    dataTxPs2Backup = 0xED;
    configuraTecladoPs2 = 1;
    statusTecladoPs2.St.numLock = 0;
    configuraTecladoPs2 = 1;
    startTxTecladoPs2Interrupt();    
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que Desativa a funcao capsLock do teclado Ps2                          //
//////////////////////////////////////////////////////////////////////////////////
void metodoDesativaCapsLockTecladoPs2(void)
{
    dataTxPs2 = 0xED;    
    dataTxPs2Backup = 0xED;
    configuraTecladoPs2 = 1;
    statusTecladoPs2.St.capsLock = 0;
    configuraTecladoPs2 = 1;
    startTxTecladoPs2Interrupt();    
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que controla o tempo maximo para recepcao de uma tecla valida          //
//////////////////////////////////////////////////////////////////////////////////
void tempoValidaTeclaPs2(void)
{
    if (flagRecebendoDadoTecladoPs2 == 1)
    {
        if(++tempoRecebendoDadoTecladoPs2 > 500)
        {
            flagRecebendoDadoTecladoPs2 = 0;
            tempoRecebendoDadoTecladoPs2 = 0;
//            verificaTeclaSoltaPs2 = 0;
            teclaPressionadaPs2 = tipoTecla;        
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que separa qual foi a tecla pressionada pelo teclado ps2               //
//////////////////////////////////////////////////////////////////////////////////
void funcaoVerificaTeclaValidaPs2(void)
{
    if(flagTrataTeclaPs2 == 1)
    {
        flagRecebendoDadoTecladoPs2 = 1;
        flagTrataTeclaPs2 = 0;
        tempoRecebendoDadoTecladoPs2 = 0;
        switch(teclaPressionadaPs2)
        {
            case tipoTecla:                   
// verifica se o teclado acabou de ser conectado
                if(dataTeclaPs2 == 0xAA)
                {
                   configTecladoPs2 = 1;
//                    configFuncaoNumLock = 1;        
                }
// verifica se � tecla shift
                if(dataTeclaPs2 == 0x12 || dataTeclaPs2 == 0x59)
                {                
                    teclaPressionadaPs2 = teclaShift;
//                    dataTempTeclaPs2 = dataTeclaPs2;
                }        
// verfica se � tecla especial 
                if(dataTeclaPs2 == 0xE0)
                {                
                    teclaPressionadaPs2 = teclaExtend;
                }             
                else
                {
                    if(dataTeclaPs2 != 0xF0 && dataTeclaPs2 != 0xE0 && dataTeclaPs2 != 0x12 && dataTeclaPs2 != 0x59 && dataTeclaPs2 != 0xAA && dataTeclaPs2 != 0xFA)
                    {
//verifca se a funcao caps lock esta ativa
                       if(statusTecladoPs2.St.capsLock == 1)
                        {
                            if(dataTeclaPs2 < _TAMANHO_MAXIMO_TABELA)
                            {
                                teclaPs2Press = tabelaConvertePcKeyboardToAsciiMaiusculo[dataTeclaPs2];
                                if(teclaPs2Press != 0)
                                {
                                    teclaValidaPs2 = 1;
                                    teclasEditaProgramaAtualPs2 == teclaSoltaPs2;
                                }
                                else
                                {
                                    teclasEditaProgramaAtualPs2 == teclaSoltaPs2;
                                    checaTeclaEdicaoTecladoPs2();                                   
                                }           
                            }                                                                      
                        }
                        if(statusTecladoPs2.St.capsLock == 0)
                        {
                            if(dataTeclaPs2 < _TAMANHO_MAXIMO_TABELA)
                            {  
                                teclaPs2Press = tabelaConvertePcKeyboardToAsciiMinusculo[dataTeclaPs2];
                                if(teclaPs2Press != 0)
                                {
                                    teclaValidaPs2 = 1;
                                    teclasEditaProgramaAtualPs2 == teclaSoltaPs2;
                                }
                                else
                                {
                                    teclasEditaProgramaAtualPs2 == teclaSoltaPs2;
                                    checaTeclaEdicaoTecladoPs2();                                    
                                }
                            }
                        }
                        dataTempTeclaPs2 = dataTeclaPs2;
                        teclaPressionadaPs2 = aguardaFinalRepeticaoTecla;
                    }
                }
                break;
//trata tecla quando pressionada a tecla shift
            case teclaShift:
                if(dataTeclaPs2 != 0x12 && dataTeclaPs2 != 0x59 && dataTeclaPs2 != 0xF0)
                {
                    teclaPs2Press = tabelaConvertePcKeyboardToAsciiMaiusculo[dataTeclaPs2];
                    if(teclaPs2Press != 0){teclaValidaPs2 = 1;}
                    dataTempTeclaPs2 = dataTeclaPs2;
                    teclaPressionadaPs2 = aguardaFinalRepeticaoTecla;
                }
                break; 
// trata tecla quando pressiona teclas da parte estendida
            case teclaExtend:
                teclaPressionadaPs2 = aguardaFinalRepeticaoTecla;
                dataTempTeclaPs2 = dataTeclaPs2;
                if(dataTeclaPs2 == 0x75)
                {
                    teclasEditaProgramaAtualPs2 = teclaSetaParaCima;
                    teclaValidaPs2 = 1;
                }
                if(dataTeclaPs2 == 0x72)
                {
                    teclasEditaProgramaAtualPs2 = teclaSetaParaBaixo;
                    teclaValidaPs2 = 1;
                }            
                if(dataTeclaPs2 == 0x6B)
                {
                    teclasEditaProgramaAtualPs2 = teclaSetaParaEsquerda;
                    teclaValidaPs2 = 1;
                }
                if(dataTeclaPs2 == 0x74)
                {
                    teclasEditaProgramaAtualPs2 = teclaSetaParaDireita;
                    teclaValidaPs2 = 1;
                }
                if(dataTeclaPs2 == 0x71)
                { 
                    teclasEditaProgramaAtualPs2 = teclaDel;
                    teclaValidaPs2 = 1;
                } 
                if(dataTeclaPs2 == 0x5A)
                {
                    teclasEditaProgramaAtualPs2 = teclaEnter;
                    teclaValidaPs2 = 1;
                }
                if(dataTeclaPs2 == 0x7D)
                {
                    teclasEditaProgramaAtualPs2 = teclaPageUp;
                    teclaValidaPs2 = 1;
                }   
                if(dataTeclaPs2 == 0x7A)
                {
                    teclasEditaProgramaAtualPs2 = teclaPageDown;
                    teclaValidaPs2 = 1;
                }    
                if(dataTeclaPs2 == 0x37)
                {
                    teclasEditaProgramaAtualPs2 = teclaPower;
                    teclaValidaPs2 = 1;
                } 
                break;
//aguarda final repeticao da tecla
            case aguardaFinalRepeticaoTecla:
                if(dataTeclaPs2 == 0xF0){teclaPressionadaPs2 = aguardaFinalFrame;}
                break;
                
//aguarda final do frame com valor da tecla
            case  aguardaFinalFrame:
                if(dataTempTeclaPs2 == dataTeclaPs2)
                {
                    verificaTeclaSoltaPs2 = 0;
                    teclaPressionadaPs2 = tipoTecla;             
                    flagRecebendoDadoTecladoPs2 = 0;
                    tempoRecebendoDadoTecladoPs2 = 0;
                }
                break;   
        }            
    }
}

//////////////////////////////////////////////////////////////////////////////////
//metodo checa tecla de edicaodo teclado ps2                                    //
//////////////////////////////////////////////////////////////////////////////////
void checaTeclaEdicaoTecladoPs2(void)
{
    if(dataTeclaPs2 == 0x66)// telca back space
    {
        teclasEditaProgramaAtualPs2 = teclaBackSpace;
        teclaValidaPs2 = 1;
    }
    if(dataTeclaPs2 == 0x5A)// tecla enter
    {
        teclasEditaProgramaAtualPs2 = teclaEnter; 
        teclaValidaPs2 = 1;
    }
    if(dataTeclaPs2 == 0x76)// tecla Esc
    {
        teclasEditaProgramaAtualPs2 = teclaEsc; 
        teclaValidaPs2 = 1;
    } 
    if(dataTeclaPs2 == 0x05)// tecla F1
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao1; 
        teclaValidaPs2 = 1;
    }
    if(dataTeclaPs2 == 0x06)// tecla F2
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao2; 
        teclaValidaPs2 = 1;
    }            
    if(dataTeclaPs2 == 0x04)// tecla F3
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao3; 
        teclaValidaPs2 = 1;
    } 
    if(dataTeclaPs2 == 0x0C)// tecla F4
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao4; 
        teclaValidaPs2 = 1;
    }
    if(dataTeclaPs2 == 0x03)// tecla F5
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao5; 
        teclaValidaPs2 = 1;
    }  
    if(dataTeclaPs2 == 0x0B)// tecla F6
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao6; 
        teclaValidaPs2 = 1;
    }  
    if(dataTeclaPs2 == 0x83)// tecla F7
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao7; 
        teclaValidaPs2 = 1;
    }                    
    if(dataTeclaPs2 == 0x0A)// tecla F8
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao8; 
        teclaValidaPs2 = 1;
    }                    
    if(dataTeclaPs2 == 0x01)// tecla F9
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao9; 
        teclaValidaPs2 = 1;
   }                                           
    if(dataTeclaPs2 == 0x09)// tecla F10
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao10; 
        teclaValidaPs2 = 1;
    }     
    if(dataTeclaPs2 == 0x78)// tecla F11
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao11; 
        teclaValidaPs2 = 1;
    }                
    if(dataTeclaPs2 == 0x07)// tecla F12
    {
        teclasEditaProgramaAtualPs2 = teclaFuncao12; 
        teclaValidaPs2 = 1;
    }                                
    if(dataTeclaPs2 == 0x58)// ativa desativa caps lock
    {
        configTecladoPs2 = 1;
        configFuncaoCapsLock = 1;            
    }
    if(dataTeclaPs2 == 0x77)//ativa desativa num Lock
    {
        configTecladoPs2 = 1;
        configFuncaoNumLock = 1;     
   }   
}  
//////////////////////////////////////////////////////////////////////////////////
//metodo que faz o sistema aguardar um tempo antes de iniciar a configuracao    //
// do teclado ps2                                                               //
//////////////////////////////////////////////////////////////////////////////////
void metodoIniciaConfigTecladoPs2(void)
{
    if(configTecladoPs2 == 1)
    {
        if(++tempoInicioConfigTecladoPs2 > 100)
        {
            configTecladoPs2 = 0;
            tempoInicioConfigTecladoPs2 = 0;
            if(configFuncaoCapsLock == 1)
            {
                configFuncaoCapsLock = 0;
                if(statusTecladoPs2.St.capsLock  == 1)
                {
                    metodoDesativaCapsLockTecladoPs2();
                }
                else
                {
                    metodoAtivaCapsLockTecladoPs2();
                }                                
            }
            if(configFuncaoNumLock == 1)
            {
                configFuncaoNumLock = 0;
                if(statusTecladoPs2.St.numLock  == 1)
                {
                    metodoDesativaNumLockTecladoPs2();
                }
                else
                {
                    metodoAtivaNumLockTecladoPs2();
                }                                 
            }            
        }
    }
    
}
