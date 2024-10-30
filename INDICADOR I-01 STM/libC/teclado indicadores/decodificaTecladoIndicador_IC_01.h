//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//              Fun��es de leitura das teclas Ad do Sistema de corte       		//
//                                                                            	//
//////////////////////////////////////////////////////////////////////////////////		



//////////////////////////////////////////////////////////////////////////////////
//Fun��o que inicializa a utilia��o dos canais digitais                         //
//////////////////////////////////////////////////////////////////////////////////
void inicializaDecodificaTeclado(void)
{

}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que decodifica o teclado 												//
//////////////////////////////////////////////////////////////////////////////////
void metodoDecodificaTeclado(void)
{
    if(exibeVersionControl == 0)
    {
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 1                                                 				//
//////////////////////////////////////////////////////////////////////////////////                
    	HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(pinoColuna3_GPIO_Port, pinoColuna3_Pin, GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin, GPIO_PIN_SET);

        flagTeclaPressionadaTemp = 0;

        tempValorTecla = HAL_GPIO_ReadPin(pinoLinha1_GPIO_Port,pinoLinha1_Pin);
        if(flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
        {
            tempTecla = teclaNaoUsada;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
        tempValorTecla = HAL_GPIO_ReadPin(pinoLinha2_GPIO_Port,pinoLinha2_Pin);
        if(flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
        {
            tempTecla = teclaTaraSetaEsquerda;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }        
        tempValorTecla = HAL_GPIO_ReadPin(pinoLinha3_GPIO_Port,pinoLinha3_Pin);
        if(flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
        {
            tempTecla = teclaMemoria1;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }        
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 2                                                 				//
//////////////////////////////////////////////////////////////////////////////////          
        HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin,GPIO_PIN_SET);

        tempValorTecla = HAL_GPIO_ReadPin(pinoLinha1_GPIO_Port,pinoLinha1_Pin);
        if(flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
        {
            tempTecla = teclaLigaDesliga;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
        tempValorTecla = HAL_GPIO_ReadPin(pinoLinha2_GPIO_Port,pinoLinha2_Pin);
        if(flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
        {
            tempTecla = teclaImprimeSetaAcima;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }        
        tempValorTecla = HAL_GPIO_ReadPin(pinoLinha3_GPIO_Port,pinoLinha3_Pin);
        if(flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
        {
            tempTecla = teclaMemoria2;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 3                                                 				//
//////////////////////////////////////////////////////////////////////////////////          
        HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin,GPIO_PIN_RESET);
        HAL_GPIO_WritePin(pinoColuna3_GPIO_Port, pinoColuna3_Pin,GPIO_PIN_SET);

        tempValorTecla = HAL_GPIO_ReadPin(pinoLinha1_GPIO_Port,pinoLinha1_Pin);
        if(flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
        {
            tempTecla = teclaZeroRetorna;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
        tempValorTecla = HAL_GPIO_ReadPin(pinoLinha2_GPIO_Port,pinoLinha2_Pin);
        if(flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
        {
            tempTecla = teclaSalva;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
        tempValorTecla = HAL_GPIO_ReadPin(pinoLinha3_GPIO_Port,pinoLinha3_Pin);
        if(flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
        {
            tempTecla = teclaNaoUsada;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }                
        if(flagTeclaPressionadaTemp == 0 )
        {
            teclaPressionada = 0;
            trataTeclaValidaIndicador = 0;
            tempoAcessoMenuProgramacao = 0;
            flagTempoAcessoMenuProgramacao = 0;  
            flagInibeTeclaSolta = 0;
        }
// multiplexa leds indicadotivos de zero e tara
    	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin,GPIO_PIN_RESET);
    	HAL_GPIO_WritePin(pinoColuna3_GPIO_Port, pinoColuna3_Pin,GPIO_PIN_RESET);
#ifdef sistemaDeCorte
    if(menuProgramacaoPesoAtual == menuProgramacaoPesoEmEspera
        && menuCorteManualAtual == menuAcionaCorteEmEspera    
        && menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
        && menuModoTecnicoCorte == menuModoTecnicoCorteEmEspera
        && menuCalibraIndicador == menuCalibraIndicadorEmEspera
        && menuApagaMemoria == menuApagaMemoriaEmEspera
        && menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
        && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera)
        {
    	ledZeroTaraDireto();
        }      
#endif  
#ifdef sistemaDeEnsaque
    if(menuProgramacaoPesoAtual == menuProgramacaoPesoEmEspera
        && menuCorteManualAtual == menuAcionaCorteEmEspera    
        && menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
        && menuModoTecnicoCorte == menuModoTecnicoCorteEmEspera
        && menuCalibraIndicador == menuCalibraIndicadorEmEspera
        && menuApagaMemoria == menuApagaMemoriaEmEspera
        && menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
        && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera)
    {
    	ledZeroTaraDireto();
    }
#endif           
#ifdef sistemaIndicadorBrinquedosUniao
        if(menuCalibraIndicador == menuCalibraIndicadorEmEspera
        && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera
        && menuDefineParametrosItens == menuDefineParametrosItensEmEspera
        && menuProgramacaoRelogioAtual == menuProgramaRelogioEmEspera) 
        {
        	ledZeroTaraDireto();
        }
#endif              
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que faz a leitura das teclas multplexadas com os pinos de controle do 	//
//diplay																		//
//////////////////////////////////////////////////////////////////////////////////		
void metodoValidaTeclaPresionada(void)
{
	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoColuna3_GPIO_Port, pinoColuna3_Pin,GPIO_PIN_RESET);
	if(loopValidaTecla == 0)
	{
        loopValidaTecla ++;
		teclaAuxiliar = tempTecla;
	}
	else
	{
		if(teclaAuxiliar == tempTecla)
		{
			if(++loopValidaTecla == 50)//equivalente a 50 mile segundos
			{
				teclaPressionadaAtual = teclaAuxiliar;
				loopValidaTecla = 0;
				trataTeclaValidaIndicador = 1;
				loopValidaTeclaSolta = 0;
                tempoValidaTeclaSolta = 0;                 
                if(flagInibeTeclaSolta == 1){flagTempoValidaTeclaSolta = 0; }
                else{flagTempoValidaTeclaSolta = 1;}
			}
		}
		else
		{
			loopValidaTecla = 0;
			teclaAuxiliar = 0;
		}	
	}
}
//////////////////////////////////////////////////////////////////////////////////		
//Metodo de controle da tecla externa                                          	//
//////////////////////////////////////////////////////////////////////////////////
void verificaLigaDesligaExterno(void)
{
	tempTeclaStart = HAL_GPIO_ReadPin(pinoTeclaExterna_GPIO_Port,pinoTeclaExterna_Pin);
	temp1TeclaStart = HAL_GPIO_ReadPin(FC1_GPIO_Port,FC1_Pin);
    if(tempTeclaStart == 0 || temp1TeclaStart == 0)
    {
        if(teclaExternaSolta == 0)
        {
            if(++tempoValidaLigaDesligaExterno > 19)
            {
                teclaExternaSolta = 1;
                tempoValidaLigaDesligaExterno = 0;
                trataTeclaValidaIndicador = 1;
                teclaPressionadaAtual = teclaStartStop;
            }  
        }
    }
    else
    {
        if(teclaExternaSolta == 1)
        {   
            teclaExternaSolta = 0;    
            teclaPressionada = 0;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Metodo que valida a entrada pausa ou sensor de seguranca                     	//
//////////////////////////////////////////////////////////////////////////////////
void verificaEntradaSensor(void)
{

    if(statusSensorSegurancaMem == 1)
    {
    	tempTeclaSensorSeguranca = HAL_GPIO_ReadPin(FC12_GPIO_Port,FC12_Pin);
        if(tempTeclaSensorSeguranca == 0)
        {
            if(controleSensorSeguranca == _sensorAberto)
            {
                if(++tempoValidaSensorSeguranca > 19)
                {
                    tempoValidaSensorSeguranca = 0;
                    controleSensorSeguranca = _sensorFechado;
                }  
            }
        }
        else{ controleSensorSeguranca = _sensorAberto;}
    }
    else{controleSensorSeguranca = _sensorFechado;}
}

//////////////////////////////////////////////////////////////////////////////////		
//Liga leds mutiplexando                                                     	//
//////////////////////////////////////////////////////////////////////////////////
/*
void ledZeroTaraMultiplexado(void)
{
// controle do zero do indicador         
    if(controleTara == _TARADESATIVADA && statusLigaDesliga == _LIGADO)
    {
        if(indicadorEmZero == 1)
        {
        	HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin,GPIO_PIN_SET);
            HAL_GPIO_WritePin(LED5_GPIO_Port , pinoLedZero,GPIO_PIN_RESET);
        }
    }
//controle da tara
    if(controleTara == _TARAATIVADA && statusLigaDesliga == _LIGADO)
    {
    	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_SET);
    	HAL_GPIO_WritePin(LED6_GPIO_Port , pinoLedTara,GPIO_PIN_RESET);


    }   
}
*/
void ledZeroTaraDireto(void)
{
// controle do zero do indicador
    if(controleTara == _TARADESATIVADA && statusLigaDesliga == _LIGADO)
    {
        if(indicadorEmZero == 1){HAL_GPIO_WritePin(LED_ZERO_GPIO_Port,LED_ZERO_Pin,GPIO_PIN_SET);}
        else{HAL_GPIO_WritePin(LED_ZERO_GPIO_Port,LED_ZERO_Pin,GPIO_PIN_RESET);}
    }else{HAL_GPIO_WritePin(LED_ZERO_GPIO_Port,LED_ZERO_Pin,GPIO_PIN_RESET);}
//controle da tara
    if(controleTara == _TARAATIVADA && statusLigaDesliga == _LIGADO){HAL_GPIO_WritePin(LED_TARA_GPIO_Port,LED_TARA_Pin,GPIO_PIN_SET);}
    else{HAL_GPIO_WritePin(LED_TARA_GPIO_Port,LED_TARA_Pin,GPIO_PIN_RESET);}
}
