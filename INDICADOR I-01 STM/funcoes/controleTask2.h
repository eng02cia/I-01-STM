//////////////////////////////////////////////////////////////////////
//timer 0 com preeescalar de 2 interrup��o a cada 200 micro segundos//
//////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////
//Fun��o de controle das tasks							      		//
//////////////////////////////////////////////////////////////////////
void ControleMultTask(void)
{
//////////////////////////////////////////////////////////////////////        
//fun��es executadas on time                              			//
//////////////////////////////////////////////////////////////////////
    trataControleDasTeclas();
    if(flagTaskHx711 == 1)
    {
        flagTaskHx711 = 0;           
    }    
//////////////////////////////////////////////////////////////////////
//Verifica houve um estouro do tempo para incio do tempo das tasks  //
//////////////////////////////////////////////////////////////////////    
	if(controleDasTasks == 1)
	{
		controleDasTasks = 0;
        trataFrameRxModBusRtu();
        controleTxFrameSerial_1ModBusRtu();
        controleTxSerial_1();
        controleTxSerial_2();
        trataErroSerial_1();
        trataErroSerial_2();

//////////////////////////////////////////////////////////////////////        
//fun��es executadas a cada 200 micro segundos          			//
//////////////////////////////////////////////////////////////////////
        delayExternoLcd();      
///////////////////////////////////////////////////////////////////////        
//fun��es executadas a cada 1 mile segundo               			 //
///////////////////////////////////////////////////////////////////////
		if (++micro_segundos == 5)
		{
            micro_segundos = 0;	
            controlaEscritaLcd();
            tempoValidaTeclaQuandoSolta();
            metodoDecodificaTeclado();
            controleTxFrameSerial_1();
            controleTxFrameSerial_2();
            funcTempoMaxRxSerial_1();
            if(statusLigaDesliga == _LIGADO){controlaBackLightOscilaPeso();}
            else{pinoBackLight = 0;}
		}
///////////////////////////////////////////////////////////////////////        
//fun��es executadas a cada 10 mile segundo                			 //
///////////////////////////////////////////////////////////////////////       
		if  (++mile_segundos == 50)
		{
            mile_segundos=0;	
            salvaDataEepron();
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
            //controlaPiscaDigitoProgSenha();
            //metodoPiscaProgIndicador();
            //funcaoTempoAcessoMenuProgramacao();
           // funcaoTempoTelaInicial();
           // controlaTempoExibeTelaTemporaria();
            //fazMediaAdCalibraIndicador();
            //metodoFazZeroIndicadorPeso();
            //metodoControleDasTelas();
            tempoControleTransmiteFrameAutomatico();
//            pilhaSalvaDadosEeprom();
		}
///////////////////////////////////////////////////////////////////////        
//fun��es executadas a cada 1000 mile segundo (1 segundo)  			 //
/////////////////////////////////////////////////////////////////////// 
		if	(++cente_segundos == 5000)
		{
            cente_segundos = 0;
            funcaoTempoBackLight();
/*            if(sistemaInicializado == 0)
            	{
                sistemaInicializado = 1;
                if(statusPowerOnEep == _LIGADO){ metodoLigaSistema();}
            	}
		}
			*/
		}
	}
}



////////////////////////////////////////////////////////////////////////////////        
//fun��es que controla a leitura e tratamento do ad de leitura do peso        //
////////////////////////////////////////////////////////////////////////////////
void funcaoControleLeituraPeso(void)
{    
 /*   if(flagModBusRtu.transmitindoModBusRtu == 0)
    {
        switch(controleLeituraPeso)
        {
            case 0:
                readHx711(); 
                controleLeituraPeso++;
                break;
            case 1:
                mostraPesoIndicador();   
                controleLeituraPeso++;
                break;
            case 2:
                trataPesoBrutoIndicador();
                controleLeituraPeso++;
                break;
            case 3:
                trataPesoTaraIndicador();
                controleLeituraPeso++;
                break;    
            case 4:
                trataPesoLiquidoIndicador();
                controleLeituraPeso = 0;
                break;                    
        }
    }*/
}

