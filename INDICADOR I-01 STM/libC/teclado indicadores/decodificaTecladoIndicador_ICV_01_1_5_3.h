//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//              Funções de leitura das teclas Ad do Sistema de corte       		//
//                                                                            	//
//////////////////////////////////////////////////////////////////////////////////		



//////////////////////////////////////////////////////////////////////////////////
//Função que inicializa a utiliação dos canais digitais                         //
//////////////////////////////////////////////////////////////////////////////////
void inicializaDecodificaTeclado(void)
{
#ifndef _18F66K40    
// colunas output
    TRISDbits.TRISD0 = 0;
    TRISDbits.TRISD1 = 0;
    TRISAbits.TRISA7 = 0;
//linhas imput   
    TRISBbits.TRISB4 = 1;
    TRISAbits.TRISA6 = 1;
    TRISCbits.TRISC2 = 1;
    
    TRISDbits.TRISD6 = 1;//tecla externa(start stop)
    TRISDbits.TRISD4 = 0;// pino mux led
//pinos de rele
    TRISAbits.TRISA0 = 0;
    TRISAbits.TRISA1 = 0;
    TRISAbits.TRISA2 = 0;    
    TRISBbits.TRISB5 = 0; 
    
    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA2 = 0;
    PORTBbits.RB5 = 0;
#endif
#ifdef _18F66K40    
// colunas output
    TRISDbits.TRISD2 = 0;
    TRISDbits.TRISD3 = 0;
    TRISBbits.TRISB5 = 0;
//linhas imput   
    TRISAbits.TRISA1 = 1;
    TRISBbits.TRISB4 = 1;
    TRISBbits.TRISB3 = 1;
    
//    TRISDbits.TRISD6 = 1;//tecla externa(start stop)
//    TRISDbits.TRISD4 = 0;// pino mux led
//LED ZERO E TARA
    TRISDbits.TRISD6 = 0;
    TRISDbits.TRISD5 = 0;
//    TRISAbits.TRISA2 = 0;    
//    TRISBbits.TRISB5 = 0; 
    
    PORTAbits.RA0 = 0;
    PORTAbits.RA1 = 0;
    PORTAbits.RA2 = 0;
    PORTBbits.RB5 = 0;
#endif    
    
    
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
    pinoColuna2 = 0;
    pinoColuna3 = 0;
    pinoColuna1 = 1;
    NOP();
    flagTeclaPressionadaTemp = 0;        
    if(flagTeclaPressionadaTemp == 0 & pinoLinha1 == 1)
    {
        tempTecla = teclaZeroRetorna;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }
    if(flagTeclaPressionadaTemp == 0 & pinoLinha2 == 1)
    {
        tempTecla = teclaNaoUsada;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }        
    if(flagTeclaPressionadaTemp == 0 & pinoLinha3 == 1)
    {
        tempTecla = teclaSalva;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }        
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 2                                                 				//
//////////////////////////////////////////////////////////////////////////////////          
    pinoColuna1 = 0;
    pinoColuna2 = 1;
    NOP();        
    if(flagTeclaPressionadaTemp == 0 & pinoLinha1 == 1)
    {
        tempTecla = teclaNaoUsada;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }
    if(flagTeclaPressionadaTemp == 0 & pinoLinha2 == 1)
    {
        tempTecla = teclaImprimeSetaAcima;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }        
    if(flagTeclaPressionadaTemp == 0 & pinoLinha3 == 1)
    {
        tempTecla = teclaRegistra;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }
//////////////////////////////////////////////////////////////////////////////////
//Trata Linha 3                                                 				//
//////////////////////////////////////////////////////////////////////////////////          
    pinoColuna2 = 0;
    pinoColuna3 = 1; 
    NOP(); 
    if(flagTeclaPressionadaTemp == 0 & pinoLinha1 == 1)
    {
        tempTecla = teclaTaraSetaEsquerda;    
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }
    if(flagTeclaPressionadaTemp == 0 & pinoLinha2 == 1)
    {
        tempTecla = teclaNaoUsada;
        flagTeclaPressionadaTemp = 1;
        metodoValidaTeclaPresionada(); 
    }
    if(flagTeclaPressionadaTemp == 0 & pinoLinha3 == 1)
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
    pinoColuna1 = 0;
    pinoColuna2 = 0; 
    pinoColuna3 = 0;
    pinoLedZero = 0;
    pinoLedTara = 0;
   if(menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
    && menuCalibraIndicador == menuCalibraIndicadorEmEspera
    && menuConfiguraSerial == menuConfiguraSerialEmEspera
    && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera
    && menuProgramacaoRelogioAtual == menuProgramaRelogioEmEspera
    && menuConfiguraWifi == menuConfiguraWifiEmEspera
    && menuProgramaDifinicaoFucionamento == menuDefinicaoFuncionamentoEmEspera
    && menuConfiguraAplicacao == menuConfiguraAplicacaoEmEspera)
   {
       ledZeroTaraDireto();
   }       
}
//////////////////////////////////////////////////////////////////////////////////		
//Função que faz a leitura das teclas multplexadas com os pinos de controle do 	//
//diplay																		//
//////////////////////////////////////////////////////////////////////////////////		
void metodoValidaTeclaPresionada(void)
{
    pinoColuna1 = 0;
    pinoColuna2 = 0;
    pinoColuna3 = 0;    
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
/*void verificaLigaDesligaExterno(void)
{
    if(pinoTeclaExterna == 0)
    {
        if(teclaExternaSolta == 0)
        {
            if(++tempoValidaLigaDesligaExterno > 9)
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
        if(teclaExternaSolta == 1)
        {   
            teclaExternaSolta = 0;    
            teclaPressionada = 0;
        }
    }
}
 */
//////////////////////////////////////////////////////////////////////////////////		
//Liga leds direto                                                          	//
//quando no modo indicador liga leds do corte para indicar status da tara e zero//
//nesta configuração so cortes nao são utilizados                               //
//////////////////////////////////////////////////////////////////////////////////
void ledZeroTaraDireto(void)
{
    if(exibeVersionControl == 0)
    {
// controle do zero do indicador         
        if(controleTara == _TARADESATIVADA)
        {
            if(indicadorEmZero == 1){pinoLedZero = 1;}
            else{pinoLedZero = 0;}            
        }else{pinoLedZero = 0;}  
//controle da tara
        if(controleTara == _TARAATIVADA){pinoLedTara = 1;}
        else{pinoLedTara = 0;}
    }
}
