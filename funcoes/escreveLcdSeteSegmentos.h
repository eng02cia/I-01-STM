/////////////////////////////////////////////////////////////////////////////////		
//Metodo que controla o intervalo de tempo de escrita do display lcd          //
/////////////////////////////////////////////////////////////////////////////////
void tempoEscreveLcdSeteSegmentos(void)
{
	if(fazTelaInicialSeteSegmento == 0){controlTempoControleLcdEscritaSeteSegmentos = 100;}
	else{controlTempoControleLcdEscritaSeteSegmentos = 50;}

   if((++tempoControleLcdEscritaSeteSegmentos >= controlTempoControleLcdEscritaSeteSegmentos)
		&& (statusLigaDesliga == _LIGADO))
   {
	   tempoControleLcdEscritaSeteSegmentos = 0;
//FAZ INICIALIZAÇÃO DO DISPLAY
	   if(sistemaInicializado == 0)
	   {
			telaVersaoSeteSegmentos();
	   }
	   if(sistemaInicializado == 1)
	   {
			/* Aguarda um tempo na tela de versao, apos isso faz tela inicial */
		   if(fazTelaInicialSeteSegmento == 0)
		   {
			   contadorInicializaTelaSeteSegmento += 2;
			   switch(contadorInicializaTelaSeteSegmento)
			   {
					case 50:
						digitosLcdSeteSegmentos[0] = 1;
						digitosLcdSeteSegmentos[1] = 1 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[2] = 1 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[3] = 1 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[4] = 1 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[5] = 1 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[6] = 1 + ValorPontoDecimalDspSeteSegmentos;
						break;
					case 60:
						digitosLcdSeteSegmentos[0] = 2;
						digitosLcdSeteSegmentos[1] = 2 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[2] = 2 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[3] = 2 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[4] = 2 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[5] = 2 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[6] = 2 + ValorPontoDecimalDspSeteSegmentos;
						break;
					case 70:
						digitosLcdSeteSegmentos[0] = 3;
						digitosLcdSeteSegmentos[1] = 3 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[2] = 3 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[3] = 3 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[4] = 3 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[5] = 3 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[6] = 3 + ValorPontoDecimalDspSeteSegmentos;
						break;
					case 80:
						digitosLcdSeteSegmentos[0] = 4;
						digitosLcdSeteSegmentos[1] = 4 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[2] = 4 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[3] = 4 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[4] = 4 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[5] = 4 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[6] = 4 + ValorPontoDecimalDspSeteSegmentos;
						break;
					case 90:
						digitosLcdSeteSegmentos[0] = 5;
						digitosLcdSeteSegmentos[1] = 5 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[2] = 5 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[3] = 5 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[4] = 5 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[5] = 5 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[6] = 5 + ValorPontoDecimalDspSeteSegmentos;
						break;
					case 100:
						digitosLcdSeteSegmentos[0] = 6;
						digitosLcdSeteSegmentos[1] = 6 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[2] = 6 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[3] = 6 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[4] = 6 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[5] = 6 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[6] = 6 + ValorPontoDecimalDspSeteSegmentos;
						break;
					case 110:
						digitosLcdSeteSegmentos[0] = 7;
						digitosLcdSeteSegmentos[1] = 7 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[2] = 7 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[3] = 7 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[4] = 7 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[5] = 7 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[6] = 7 + ValorPontoDecimalDspSeteSegmentos;
						break;
					case 120:
						digitosLcdSeteSegmentos[0] = 8;
						digitosLcdSeteSegmentos[1] = 8 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[2] = 8 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[3] = 8 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[4] = 8 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[5] = 8 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[6] = 8 + ValorPontoDecimalDspSeteSegmentos;
						break;
					case 130:
						digitosLcdSeteSegmentos[0] = 9;
						digitosLcdSeteSegmentos[1] = 9 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[2] = 9 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[3] = 9 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[4] = 9 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[5] = 9 + ValorPontoDecimalDspSeteSegmentos;
						digitosLcdSeteSegmentos[6] = 9 + ValorPontoDecimalDspSeteSegmentos;
						break;
					case 140:
						fazTelaInicialSeteSegmento = 1;
						contadorInicializaTelaSeteSegmento = 0;
						break;
			   }
		   }
	   }
	   //ESCREVE DADOS NO DISPLAY
        controleDsp = 0;
        while(controleDsp < 7)
		{
        	dadoDigitoLcdTemp = digitosLcdSeteSegmentos[controleDsp];
        	if(dadoDigitoLcdTemp >= ValorPontoDecimalDspSeteSegmentos)
        	{
        		dadoDigitoLcdTemp -= ValorPontoDecimalDspSeteSegmentos;
        		dadoDigitosEscreveLcd[controleDsp] = tabSegDsp[dadoDigitoLcdTemp];
        		dadoDigitosEscreveLcd[controleDsp] += ValorPontoDecimalDspSeteSegmentos;
        	}
        	else
        	{
        		dadoDigitosEscreveLcd[controleDsp] = tabSegDsp[dadoDigitoLcdTemp];
        	}
        	controleDsp++;
		}
        apagaLcdSeteSegmentos();
        escreveDigitosLcdSetSegmentos();
   }
}
/////////////////////////////////////////////////////////////////////////////////		
//Metodo que apaga a ultima linha escrita na matriz                            //
////////////////////////////////////////////////////////////////////////////////
void apagaLcdSeteSegmentos(void)
{
//inicia pinos de escrita do 74HC164
	HAL_GPIO_WritePin(resetDsp_GPIO_Port, resetDsp_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(resetDsp_GPIO_Port, resetDsp_Pin,GPIO_PIN_SET);
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que escreve os digitos no display				                        //
//PINO DB7 = DATA																//
//PINO DB6 = CLOCK
//PONO DB5 = RESET
//////////////////////////////////////////////////////////////////////////////////
void escreveDigitosLcdSetSegmentos(void)
{ 
//	HAL_GPIO_WritePin(COM_DSP_GPIO_Port, COM_DSP_Pin,GPIO_PIN_RESET);
//	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_RESET);
	indexExcreveDigitos = 0;
//escreve novo dado  na linha
//    indexEscreveMatriz = ValorUltimaColunaMatriz;
    for(loopEscreveSegmentosLcd = 6 ; loopEscreveSegmentosLcd != 0 ; loopEscreveSegmentosLcd--)
    {
    	controlSegmentosDsp.Byte = dadoDigitosEscreveLcd[indexExcreveDigitos];
    	indexExcreveDigitos++;
    	//escreve segmento A
    	if(controlSegmentosDsp.Display.PontoDecimal == 1){HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_SET);}
    	else{HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_RESET);}
    	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_SET);//db6 clock
    	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_RESET);
    	//escreve segmento B
    	if(controlSegmentosDsp.Display.SegG == 1){HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_SET);}
    	else{HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_RESET);}
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_SET);//db6 clock
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_RESET);
    	//escreve segmento C
    	if(controlSegmentosDsp.Display.SegF == 1){HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_SET);}
    	else{HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_RESET);}
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_SET);//db6 clock
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_RESET);
    	//escreve segmento D
    	if(controlSegmentosDsp.Display.SegE == 1){HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_SET);}
    	else{HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_RESET);}
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_SET);//db6 clock
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_RESET);
    	//escreve segmento E
    	if(controlSegmentosDsp.Display.SegD == 1){HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_SET);}
    	else{HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_RESET);}
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_SET);//db6 clock
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_RESET);
    	//escreve segmento F
    	if(controlSegmentosDsp.Display.SegC == 1){HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_SET);}
    	else{HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_RESET);}
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_SET);//db6 clock
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_RESET);
    	//escreve segmento G
    	if(controlSegmentosDsp.Display.SegB == 1){HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_SET);}
    	else{HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_RESET);}
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_SET);//db6 clock
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_RESET);
    	//escreve segmento Ponto
    	if(controlSegmentosDsp.Display.SegA == 1){HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_SET);}
    	else{HAL_GPIO_WritePin(dataLcd_GPIO_Port, dataLcd_Pin,GPIO_PIN_RESET);}
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_SET);//db6 clock
       	HAL_GPIO_WritePin(clockLcd_GPIO_Port, clockLcd_Pin,GPIO_PIN_RESET);
    }
 }

    

