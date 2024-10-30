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

    teclaExternaPrint = 1;
   
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que decodifica o teclado 												//
//////////////////////////////////////////////////////////////////////////////////
void metodoDecodificaTeclado(void)
{
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 1                                                 				//
//////////////////////////////////////////////////////////////////////////////////                

	HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoColuna3_GPIO_Port, pinoColuna3_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin, GPIO_PIN_SET);



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
        tempTecla = teclaZeroRetorna;
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
//Trata Linha 2                                                 				//
//////////////////////////////////////////////////////////////////////////////////          
    HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin,GPIO_PIN_SET);


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
       tempTecla = teclaLigaDesliga;    
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }

    tempValorTecla = HAL_GPIO_ReadPin(pinoLinha2_GPIO_Port,pinoLinha2_Pin);
    if (flagTeclaPressionadaTemp == 0 &&tempValorTecla == 1)
    {
        tempTecla = teclaImprimeSetaAcima;
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
        teclaPresionda = 0;
        trataTeclaValidaIndicador = 0;
        tempoAcessoMenuProgramacao = 0;
        flagTempoAcessoMenuProgramacao = 0;  
        flagInibeTeclaSolta = 0;
    }
// multiplexa leds indicadotivos de zero e tara
    HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RELE4_GPIO_Port, RELE4_Pin,GPIO_PIN_RESET);
    HAL_GPIO_WritePin(RELE3_GPIO_Port, RELE3_Pin,GPIO_PIN_RESET);

   if (menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
    && menuCalibraIndicador == menuCalibraIndicadorEmEspera
    && menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
    && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera)
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
//Metodo de controle da tecla liga desliga extena                             	//
//////////////////////////////////////////////////////////////////////////////////
void verificaLigaDesligaExterno(void)
{
	tempTeclaStart = HAL_GPIO_ReadPin(FC1_GPIO_Port,FC1_Pin);
	if (tempTeclaStart == 0 )
    {
        if (teclaExternaLigaDesligaSolta == 0)
        {
            if (++tempoValidaLigaDesligaExterno > 19)
            {
                teclaExternaLigaDesligaSolta = 1;
                tempoValidaLigaDesligaExterno = 0;
                trataTeclaValidaIndicador = 1;
                teclaPressionadaAtual = teclaLigaDesliga;
            }  
        }
    }
    else
    {
        if (teclaExternaLigaDesligaSolta == 1)
        {   
            teclaExternaLigaDesligaSolta = 0;    
            teclaPresionda = 0;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Metodo de controle da tecla zero externo                                    	//
//////////////////////////////////////////////////////////////////////////////////
void verificaComandoZeroExterno(void)
{

	tempTeclaZero = HAL_GPIO_ReadPin(FC12_GPIO_Port,FC12_Pin);
    if (tempTeclaZero == 0)
    {
        if (teclaExternaZero == 0)
        {
            if (++tempoValidaZeroExterno > 19)
            {
                teclaExternaZero = 1;
                tempoValidaZeroExterno = 0;
                if (controleTara == 0){fazZeroIndicadorPeso = 1;}                  
            }
        }
    }
    else
    {
        if (teclaExternaZero == 1)
        {  
             teclaExternaZero = 0;
            tempoValidaZeroExterno = 0;                       
        }        
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Metodo de controle da tecla tara externo                                     	//
//////////////////////////////////////////////////////////////////////////////////
void verificaComandoTaraExterno(void)
{

	tempTeclaTara = HAL_GPIO_ReadPin(FC3_GPIO_Port,FC3_Pin);
    if (tempTeclaTara == 0)
    {
        if (teclaExternaTara == 0)
        {
            if (++tempoValidaTaraExterno > 19)
            {
                teclaExternaTara = 1;
                tempoValidaTaraExterno = 0;
                if (controleTara == _TARADESATIVADA)
                {
                    if (indicadorEmZero != 1) 
                    {
                        controleTara = _TARAATIVADA;
                        fazTaraIndicadorPeso = 1;
                    }                       
                }   
                else
                {
                    controleTara = _TARADESATIVADA;
                    valorTaraIndicador = valorZeroIndicador;
                }               
            }
        }
    }
    else
    {
        if (teclaExternaTara == 1)
        {  
             teclaExternaTara = 0;
            tempoValidaTaraExterno = 0;                       
        }        
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Metodo de controle da tecla print externo                                     	//
//////////////////////////////////////////////////////////////////////////////////
void verificaComandoPrintExterno(void)
{
    
	tempTeclaPrint = HAL_GPIO_ReadPin(FC4_GPIO_Port,FC4_Pin);
   
    if (tempTeclaPrint == 0)
    {
        if (teclaExternaPrint == 0 && sistemaInicializado == 1)
        {
            if (++tempoValidaPrintExterno > 19)
            {
                teclaExternaPrint = 1;
                tempoValidaPrintExterno = 0;
                if (valorPesoBrutoFloatIndicador >= 0) 
                {

                    funcaoControleAcumulaPesagem();
                    imprimeDataPesoIndicador();
                    if (modoFuncionamentoTelaPrincipalMem == _Pesagem_Relogio)
                    {
                        tempoMostraDadosPesagem = 1;
                    }

                }                
            }
        }
    }
    else
    {
        if (teclaExternaPrint == 1)
        {  
            teclaExternaPrint = 0;
            tempoValidaPrintExterno = 0;                       
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
// controle do zero do indicador         
    if (controleTara == _TARADESATIVADA && statusLigaDesliga == _LIGADO)
    {
        if (indicadorEmZero == 1){HAL_GPIO_WritePin(RELE3_GPIO_Port, RELE3_Pin,GPIO_PIN_SET);}
        else{HAL_GPIO_WritePin(RELE3_GPIO_Port, RELE3_Pin,GPIO_PIN_RESET);}
    }else{HAL_GPIO_WritePin(RELE3_GPIO_Port, RELE3_Pin,GPIO_PIN_RESET);}
//controle da tara
    if (controleTara == _TARAATIVADA && statusLigaDesliga == _LIGADO){HAL_GPIO_WritePin(RELE4_GPIO_Port, RELE4_Pin,GPIO_PIN_SET);}
    else{HAL_GPIO_WritePin(RELE4_GPIO_Port, RELE4_Pin,GPIO_PIN_RESET);}
}


