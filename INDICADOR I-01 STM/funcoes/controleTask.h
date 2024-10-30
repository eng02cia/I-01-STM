//////////////////////////////////////////////////////////////////////
//timer 0 com preeescalar de 2 interrup��o a cada 200 micro segundos//
//////////////////////////////////////////////////////////////////////
extern UART_HandleTypeDef huart3;

//////////////////////////////////////////////////////////////////////////////////
//Fun��o de interrup��o dos tempo de controle das tasks                         //
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
//Fun��o de interrup��o dos tempo de leitura do conversor ad                    //
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//Fun��o de controle das tasks							      		//
//////////////////////////////////////////////////////////////////////
void ControleMultTask(void)
{
//////////////////////////////////////////////////////////////////////        
//fun��es executadas on time                              			//
//////////////////////////////////////////////////////////////////////
    if(flagTaskHx711 == 1)
    {
        flagTaskHx711 = 0;
    }

	trataControleDasTeclas();
//////////////////////////////////////////////////////////////////////
//Verifica houve um estouro do tempo para incio do tempo das tasks  //
//////////////////////////////////////////////////////////////////////    
	if(controleDasTasks == 1)
	{
        controleDasTasks = 0;
        //trataFrameRxModBusRtu();

//////////////////////////////////////////////////////////////////////        
//fun��es executadas a cada 200 micro segundos          			//
//////////////////////////////////////////////////////////////////////
        delayExternoLcd();      
///////////////////////////////////////////////////////////////////////        
//fun��es executadas a cada 1 mile segundo               			 //
///////////////////////////////////////////////////////////////////////
		if(++micro_segundos == 5) //
		{
            micro_segundos = 0;	
            controlaEscritaLcd();
            tempoValidaTeclaQuandoSolta();
            metodoDecodificaTeclado();
            controleTxFrameSerial_1();
            controleTxFrameSerial_2();

            if(statusLigaDesliga == _LIGADO){controlaBackLightOscilaPeso();}
            else{HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin, GPIO_PIN_RESET);}
		}
///////////////////////////////////////////////////////////////////////        
//fun��es executadas a cada 10 mile segundo                			 //
///////////////////////////////////////////////////////////////////////       
		if  (++mile_segundos == 50)
		{
            mile_segundos=0;	
            funcaoVerificaSalvaModBusRtu();
            funcaoLeituraDadosMemoriaModBusRtu();
            funcaoControleLeituraPeso();
		}
///////////////////////////////////////////////////////////////////////        
//fun��es executadas a cada 100 mile segundo               			 //
///////////////////////////////////////////////////////////////////////           
		if	(++deze_segundos == 500)
		{
            deze_segundos = 0;
            controlaPiscaDigitoProgSenha();
            metodoPiscaProgIndicador();
            funcaoTempoAcessoMenuProgramacao();
            funcaoTempoTelaInicial();
            controlaTempoExibeTelaTemporaria();
            fazMediaAdCalibraIndicador();  
            metodoFazZeroIndicadorPeso();
            metodoControleDasTelas();  
            TimerReadi2c();
		}
///////////////////////////////////////////////////////////////////////        
//fun��es executadas a cada 1000 mile segundo (1 segundo)  			 //
/////////////////////////////////////////////////////////////////////// 
		if	(++cente_segundos == 5000)
		{
            cente_segundos = 0;
            if(sistemaInicializado == 0)
            {
            	sistemaInicializado = 1;
                if(statusPowerOnMem == _LIGADO)
                {
                	metodoLigaSistema();
                }
            }

            funcaoTempoBackLight();

		}
	}
}

////////////////////////////////////////////////////////////////////////////////        
//fun��es que controla a leitura e tratamento do ad de leitura do peso        //
////////////////////////////////////////////////////////////////////////////////
void funcaoControleLeituraPeso(void)
{    

	if(flagModBusRtu.transmitindoModBusRtu == 0)
	{
		switch(controleLeituraPesoI01)
		{
		case 0:
			readHx711();
			controleLeituraPesoI01++;
			break;
		case 1:
			mostraPesoIndicador();
			controleLeituraPesoI01++;
			break;
		case 2:
			trataPesoBrutoIndicador();
			controleLeituraPesoI01++;
			break;
		case 3:
			trataPesoTaraIndicador();
			controleLeituraPesoI01++;
			break;
		case 4:
			trataPesoLiquidoIndicador();
			controleLeituraPesoI01 = 0;
			break;
		default:
			controleLeituraPesoI01 = 0;
			break;
		}
	}
}



void TelaInicio (void)
{
	if(fazTelaInicio == 1)
	{
		fazTelaInicio = 0;
		HAL_UART_Transmit(&huart3, "page START", 10, 25);
		HAL_UART_Transmit(&huart3, cmd_end, 3, 25);
		HAL_UART_Transmit(&huart3, "sleep=0", 7, 25);
		HAL_UART_Transmit(&huart3, cmd_end, 3, 25);
	}
}

