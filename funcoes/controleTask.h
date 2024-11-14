//////////////////////////////////////////////////////////////////////
//timer 0 com preeescalar de 2 interrupcao a cada 200 micro segundos//
//////////////////////////////////////////////////////////////////////
extern UART_HandleTypeDef huart3;

//////////////////////////////////////////////////////////////////////////////////
//Funcao de interrupcao dos tempo de controle das tasks                         //
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
//Funcao de interrupcao dos tempo de leitura do conversor ad                    //
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//Funcao de controle das tasks							      		//
//////////////////////////////////////////////////////////////////////
void ControleMultTask(void)
{
//////////////////////////////////////////////////////////////////////        
//funcoes executadas on time                              			//
//////////////////////////////////////////////////////////////////////
	trataControleDasTeclas();

    if (flagTaskHx711 == 1)
    {
        flagTaskHx711 = 0;
    }
//////////////////////////////////////////////////////////////////////
//Verifica houve um estouro do tempo para incio do tempo das tasks  //
//////////////////////////////////////////////////////////////////////    
	if (controleDasTasks == 1)
	{
        controleDasTasks = 0;
        trataFrameRxModBusRtu();

//////////////////////////////////////////////////////////////////////        
//funcoes executadas a cada 200 micro segundos          			//
//////////////////////////////////////////////////////////////////////
        delayExternoLcd();      
///////////////////////////////////////////////////////////////////////        
//funcoes executadas a cada 1 mile segundo               			 //
///////////////////////////////////////////////////////////////////////
		if (++micro_segundos >= 5) //
		{
            micro_segundos = 0;	
            controlaEscritaLcd();
            tempoValidaTeclaQuandoSolta();
            metodoDecodificaTeclado();
            controleTxFrameSerial_1();
            controleTxFrameSerial_2();

			tempoValidaTeclaPs2();
			metodoIniciaConfigTecladoPs2();
			metodoTempoControleConfigPs2();

            if (statusLigaDesliga == _LIGADO){controlaBackLightOscilaPeso();}
            else{HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin, GPIO_PIN_RESET);}
		}
///////////////////////////////////////////////////////////////////////        
//funcoes executadas a cada 10 mile segundo                			 //
///////////////////////////////////////////////////////////////////////       
		if  (++mile_segundos >= 50)
		{
            mile_segundos=0;	
            funcaoVerificaSalvaModBusRtu();
            funcaoLeituraDadosMemoriaModBusRtu();
            funcaoControleLeituraPeso();
		}
///////////////////////////////////////////////////////////////////////        
//funcoes executadas a cada 100 mile segundo               			 //
///////////////////////////////////////////////////////////////////////           
		if	(++deze_segundos >= 500)
		{
            deze_segundos = 0;
			telaMostraProgHoraData();
			funcaoPiscaCaracter();
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
//funcoes executadas a cada 1000 mile segundo (1 segundo)  			 //
/////////////////////////////////////////////////////////////////////// 
		if	(++cente_segundos >= 5000)
		{
            cente_segundos = 0;
			metodoTempoLeituraRelogio();
            funcaoTempoBackLight();

            if (sistemaInicializado == 0)
            {
            	sistemaInicializado = 1;
                if (statusPowerOnMem == _LIGADO)
                {
                	metodoLigaSistema();
                }
            }
		}
	}
}

////////////////////////////////////////////////////////////////////////////////        
//funcoes que controla a leitura e tratamento do ad de leitura do peso        //
////////////////////////////////////////////////////////////////////////////////
void funcaoControleLeituraPeso(void)
{    
	if (flagModBusRtu.transmitindoModBusRtu == 0)
	{
		switch (controleLeituraPesoI01) {
			case kStatusControlePeso_LendoHx711:
				readHx711();
				controleLeituraPesoI01++;
				break;
			case kStatusControlePeso_MostraPeso:
				mostraPesoIndicador();
				controleLeituraPesoI01++;
				break;
			case kStatusControlePeso_TrataPesoBruto:
				trataPesoBrutoIndicador();
				controleLeituraPesoI01++;
				break;
			case kStatusControlePeso_TrataPesoTara:
				trataPesoTaraIndicador();
				controleLeituraPesoI01++;
				break;
			case kStatusControlePeso_TrataPesoLiquido:
				trataPesoLiquidoIndicador();
				controleLeituraPesoI01 = 0;
				break;
			default:
				controleLeituraPesoI01 = 0;
				break;
		}
	}
}


