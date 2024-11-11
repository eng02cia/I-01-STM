//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//              funcoes de leitura das teclas Ad do Sistema de corte       		//
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
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 1                                                 				//
//////////////////////////////////////////////////////////////////////////////////                
//    pinoMuxLed = 1;
	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_SET);

    flagTeclaPressionadaTemp = 0;

    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha1_GPIO_Port,pinoLinha1_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
        tempTecla = teclaNaoUsada;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }
    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha2_GPIO_Port,pinoLinha2_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
        tempTecla = teclaTaraSetaEsquerda;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }        
    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha3_GPIO_Port,pinoLinha3_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
       tempTecla = teclaNaoUsada;
//        tempTecla = teclaMemoria1;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }        
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 2                                                 				//
//////////////////////////////////////////////////////////////////////////////////          
    HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin,GPIO_PIN_SET);

    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha1_GPIO_Port,pinoLinha1_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
        tempTecla = teclaZeroRetorna;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }

    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha2_GPIO_Port,pinoLinha2_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
        tempTecla = teclaNaoUsada;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }        

    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha3_GPIO_Port,pinoLinha3_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
        tempTecla = teclaSalva;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 3                                                 				//
//////////////////////////////////////////////////////////////////////////////////          
    HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pinoColuna3_GPIO_Port, pinoColuna3_Pin,GPIO_PIN_SET);

    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha1_GPIO_Port,pinoLinha1_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
       tempTecla = teclaNaoUsada;    
//        tempTecla = teclaZeroRetorna;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }

    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha2_GPIO_Port,pinoLinha2_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
        tempTecla = teclaImprimeSetaAcima;
        //tempTecla = teclaSalva;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }

    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha3_GPIO_Port,pinoLinha3_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
        tempTecla = teclaNaoUsada;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }                
    if (flagTeclaPressionadaTemp == 0 )
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

   if (menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
    && menuCalibraIndicador == menuCalibraIndicadorEmEspera
//    && menuConfiguraSerial == menuConfiguraSerialEmEspera
    && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera
    && menuProgramacaoRelogioAtual == menuProgramaRelogioEmEspera
    && menuConfiguraSemFio == menuConfiguraSemFioEmEspera
    && menuProgramaDefinicaoFucionamento == menuDefinicaoFuncionamentoEmEspera
    && menuConfiguraAplicacao == menuConfiguraAplicacaoEmEspera)
   {
       ledZeroTaraDireto();
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
	if (loopValidaTecla == 0)
	{
        loopValidaTecla ++;
		teclaAuxiliar = tempTecla;
	}
	else
	{
		if (teclaAuxiliar == tempTecla)
		{
			if (++loopValidaTecla == 50)//equivalente a 50 mile segundos
			{
				teclaPressionadaAtual = teclaAuxiliar;
				loopValidaTecla = 0;
				trataTeclaValidaIndicador = 1;
				loopValidaTeclaSolta = 0;
                tempoValidaTeclaSolta = 0;                 
                if (flagInibeTeclaSolta == 1){flagTempoValidaTeclaSolta = 0; }
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
    if (tempTeclaStart == 0)
    {
        if (teclaExternaSolta == 0)
        {
            if (++tempoValidaLigaDesligaExterno > 9)
            {
                teclaExternaSolta = 1;
                tempoValidaLigaDesligaExterno = 0;
                trataTeclaValidaIndicador = 1;
                teclaPressionadaAtual = teclaRegistra;
              
            }  
        }
    }
    else
    {
        if (teclaExternaSolta == 1)
        {   
            teclaExternaSolta = 0;    
            teclaPressionada = 0;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Liga leds direto                                                          	//
//quando no modo indicador liga leds do corte para indicar status da tara e zero//
//nesta configura��o so cortes nao s�o utilizados                               //
//////////////////////////////////////////////////////////////////////////////////
void ledZeroTaraDireto(void)
{
	if (exibeVersionControl == 0)
	{
		if (controleTara == _TARADESATIVADA)
		{
			if (indicadorEmZero == 1){HAL_GPIO_WritePin(LED_ZERO_GPIO_Port,LED_ZERO_Pin,GPIO_PIN_SET);}
			else{HAL_GPIO_WritePin(LED_ZERO_GPIO_Port,LED_ZERO_Pin,GPIO_PIN_RESET);}
		}else{HAL_GPIO_WritePin(LED_ZERO_GPIO_Port,LED_ZERO_Pin,GPIO_PIN_RESET);}
		//controle da tara
		if (controleTara == _TARAATIVADA){HAL_GPIO_WritePin(LED_TARA_GPIO_Port,LED_TARA_Pin,GPIO_PIN_SET);}
		else{HAL_GPIO_WritePin(LED_TARA_GPIO_Port,LED_TARA_Pin,GPIO_PIN_RESET);}
	}
}
