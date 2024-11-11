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
// colunas output
    TRISEbits.TRISE6 = 0;
    TRISEbits.TRISE6 = 0;
    TRISDbits.TRISD5 = 0;
//linhas imput   
    TRISHbits.TRISH0 = 1;
    TRISDbits.TRISD4 = 1;
    TRISDbits.TRISD0 = 1;
    
    TRISFbits.TRISF7 = 1;//tecla comando liga/desliga
    TRISFbits.TRISF6 = 1;//tecla comando zero
    TRISFbits.TRISF5 = 1;//tecla comando tara
    TRISFbits.TRISF4 = 1;//tecla comando print
    
//    TRISDbits.TRISD4 = 0;// pino mux led
 
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;    
    TRISBbits.TRISB5 = 0; 
//    ledIndicadorLigado = 1;     
//    teclaExternaPrint = 1;
   
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que decodifica o teclado 												//
//////////////////////////////////////////////////////////////////////////////////
void metodoDecodificaTeclado(void)
{
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 1                                                 				//
//////////////////////////////////////////////////////////////////////////////////                 
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
        tempTecla = teclaZeroRetorna;
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
        tempTecla = teclaNaoUsada;
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
    pinoLedZero = 0;
    pinoLedTara = 0;
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
//Metodo de controle da tecla liga desliga extena                             	//
//////////////////////////////////////////////////////////////////////////////////
void verificaLigaDesligaExterno(void)
{
    if (pinoComandoLigaDesliga == 0)
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
            teclaPressionada = 0;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Metodo de controle da tecla zero externo                                    	//
//////////////////////////////////////////////////////////////////////////////////
void verificaComandoZeroExterno(void)
{
    if (pinoComandoZero == 0)
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
    if (pinoComandoTara == 0)
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
    
//    if (pinoComandoPrint == 1){LATAbits.LATA0 = 1;}
//    else{LATAbits.LATA0 = 0;}
    if (pinoComandoPrint == 1){LATAbits.LATA2 = 1;}
    else{LATAbits.LATA2 = 0;}
    
   
    if (pinoComandoPrint == 0)
    {
        if (teclaExternaPrint == 0 && sistemaInicializado == 1)
        {
            if (++tempoValidaPrintExterno > 19)
            {
                teclaExternaPrint = 1;
                tempoValidaPrintExterno = 0;
                if (valorPesoBrutoFloatIndicador >= 0) 
                {
#ifdef indicadorI02                    
                    funcaoControleAcumulaPesagem();
                    imprimeDataPesoIndicador();
                    if (modoFuncionamentoTelaPrincipalEep == _Pesagem_Relogio)
                    {
                        tempoMostraDadosPesagem = 1;
                    }
#endif                   
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
        if (indicadorEmZero == 1){pinoLedZero = 1;}
        else{pinoLedZero = 0;}            
    }else{pinoLedZero = 0;}  
//controle da tara
    if (controleTara == _TARAATIVADA && statusLigaDesliga == _LIGADO){pinoLedTara = 1;}
    else{pinoLedTara = 0;}
}
