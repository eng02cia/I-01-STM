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
    TRISAbits.TRISA7 = 0;
    TRISDbits.TRISD0 = 1;
    TRISAbits.TRISA6 = 1;
    TRISCbits.TRISC2 = 1;
    TRISBbits.TRISB4 = 1;
    TRISDbits.TRISD6 = 1;//tecla externa(start stop)
    TRISDbits.TRISD7 = 1;//entrada pausa processo   
    TRISDbits.TRISD4 = 0;// pino mux led
    TRISDbits.TRISD0 = 0;// mux led tara zer0 
    TRISDbits.TRISD1 = 0;// mux led tara zer0     
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que decodifica o teclado 												//
//////////////////////////////////////////////////////////////////////////////////
void metodoDecodificaTeclado(void)
{
    if (exibeVersionControl == 0)
    {
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 1                                                 				//
//////////////////////////////////////////////////////////////////////////////////                
        pinoMuxLed = 1;
        pinoColuna2 = 0;
        pinoColuna3 = 0;
        pinoColuna1 = 1;
        NOP();
        flagTeclaPressionadaTemp = 0;        
        if (flagTeclaPressionadaTemp == 0 & pinoLinha1 == 1)
        {
            tempTecla = teclaNaoUsada;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
        if (flagTeclaPressionadaTemp == 0 & pinoLinha2 == 1)
        {
            tempTecla = teclaTaraSetaEsquerda;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }        
        if (flagTeclaPressionadaTemp == 0 & pinoLinha3 == 1)
        {
            tempTecla = teclaMemoria1;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }        
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 2                                                 				//
//////////////////////////////////////////////////////////////////////////////////          
        pinoColuna1 = 0;
        pinoColuna2 = 1;
        NOP();        
        if (flagTeclaPressionadaTemp == 0 & pinoLinha1 == 1)
        {
            tempTecla = teclaLigaDesliga;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
        if (flagTeclaPressionadaTemp == 0 & pinoLinha2 == 1)
        {
            tempTecla = teclaImprimeSetaAcima;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }        
        if (flagTeclaPressionadaTemp == 0 & pinoLinha3 == 1)
        {
            tempTecla = teclaMemoria2;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 3                                                 				//
//////////////////////////////////////////////////////////////////////////////////          
        pinoColuna2 = 0;
        pinoColuna3 = 1;
        NOP();        
        if (flagTeclaPressionadaTemp == 0 & pinoLinha1 == 1)
        {
            tempTecla = teclaZeroRetorna;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
        if (flagTeclaPressionadaTemp == 0 & pinoLinha2 == 1)
        {
            tempTecla = teclaSalva;
            flagTeclaPressionadaTemp = 1;
            metodoValidaTeclaPresionada(); 
        }
        if (flagTeclaPressionadaTemp == 0 & pinoLinha3 == 1)
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
        pinoColuna1 = 0;
        pinoColuna2 = 0;   
        pinoColuna3 = 0;       
#ifdef sistemaDeCorte
    if (menuProgramacaoPesoAtual == menuProgramacaoPesoEmEspera
        && menuCorteManualAtual == menuAcionaCorteEmEspera    
        && menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
        && menuModoTecnicoCorte == menuModoTecnicoCorteEmEspera
        && menuCalibraIndicador == menuCalibraIndicadorEmEspera
        && menuApagaMemoria == menuApagaMemoriaEmEspera
        && menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
        && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera)
        {
            ledZeroTaraMultiplexado();
        }      
#endif  
#ifdef sistemaDeEnsaque
    if (menuProgramacaoPesoAtual == menuProgramacaoPesoEmEspera
        && menuCorteManualAtual == menuAcionaCorteEmEspera    
        && menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
        && menuModoTecnicoCorte == menuModoTecnicoCorteEmEspera
        && menuCalibraIndicador == menuCalibraIndicadorEmEspera
        && menuApagaMemoria == menuApagaMemoriaEmEspera
        && menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
        && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera)
    {
        ledZeroTaraMultiplexado();
    }
#endif           
#ifdef sistemaIndicadorBrinquedosUniao
        if (menuCalibraIndicador == menuCalibraIndicadorEmEspera
        && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera
        && menuDefineParametrosItens == menuDefineParametrosItensEmEspera
        && menuProgramacaoRelogioAtual == menuProgramaRelogioEmEspera) 
        {
            ledZeroTaraMultiplexado();
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
    pinoColuna1 = 0;
    pinoColuna2 = 0;
    pinoColuna3 = 0;    
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
    if (pinoTeclaExterna == 0)
    {
        if (teclaExternaSolta == 0)
        {
            if (++tempoValidaLigaDesligaExterno > 19)
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
        if (teclaExternaSolta == 1)
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
    if (statusSensorSegurancaEep == 1)
    {
        if (pinoEntradaSensor == 0)
        {
            if (controleSensorSeguranca == _sensorAberto)
            {
                if (++tempoValidaSensorSeguranca > 19)
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
void ledZeroTaraMultiplexado(void)
{
// controle do zero do indicador         
    if (controleTara == _TARADESATIVADA && statusLigaDesliga == _LIGADO)
    {
        if (indicadorEmZero == 1)
        {
            pinoColuna2 = 1;
            pinoMuxLed = 0;
        }
    }
//controle da tara
    if (controleTara == _TARAATIVADA && statusLigaDesliga == _LIGADO)
    {
        pinoColuna1 = 1;
        pinoMuxLed = 0;
    }   
}

