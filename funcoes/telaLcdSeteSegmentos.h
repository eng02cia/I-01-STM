//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//              Funções de escrita no display de sete segmentos led       		//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraDadoLcdSeteSegmentos(void)
{
	if ((exibeVersionControl == 0) && (sistemaInicializado == 1) 
		&& (fazTelaInicialSeteSegmento == 1))
	{
		asciiTelaDisplaySeteSegmentos = 0;
		if ((menuAcessaMenusProgramacao != menuAcessaMenusProgramacaoEmEspera)
		|| (menuCalibraIndicador != menuCalibraIndicadorEmEspera)
		|| (menuModoTecnicoIndicador != menuModoTecnicoIndicadorEmEspera)
		|| (menuProgramacaoRelogioAtual != menuProgramaRelogioEmEspera)
		|| (menuProgramaDefinicaoFucionamento != menuDefinicaoFuncionamentoEmEspera)
		|| (menuConfiguraSerial_1 != menuConfiguraSerial_1EmEspera))
//coloca a pagina do dispaly dwin que mostra o menu de progarmação
		{

		}
		else if (mostraTelaTemporariaLcd == 0)
		{
			if (statusControleSubCarga == 1)
			{
				telaSubCargaSeteSegmentos();
				asciiTelaDisplaySeteSegmentos = 1;
			}
			if (statusControleSobreCarga == 1)
			{
				telaSobreCargaSeteSegmentos();
				asciiTelaDisplaySeteSegmentos = 1;
			}

			if (asciiTelaDisplaySeteSegmentos == 0)
			{
				/* TESTE - DEFINIR REGRA */
				if(exibeRelogioMem == _EXIBE_RELOGIO_HABILITADO)
				{
					telaMostraHoraSeteSegmentos();
				}
				else
				{
					if(controleTara == _TARADESATIVADA)
					{
						transfereArrayToArray(7,&pesoBrutoIndicadorAscii[0],&dadoLcdSetSegmentos[0]);
					}
					if(controleTara == _TARAATIVADA)
					{
						transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&dadoLcdSetSegmentos[0]);
					}
				}

			}
		}
		digitosDspTemp = &digitosLcdSeteSegmentos[5];
		displayPesoTemp = &dadoLcdSetSegmentos[6];
		loopConverteTelaLcd = 0;
		while (loopConverteTelaLcd < 6)
		{
			loopConverteTelaLcd ++;
			if (*displayPesoTemp == '.')
			{
				digitosDspTemp++;
				*digitosDspTemp += ValorPontoDecimalDspSeteSegmentos;
				displayPesoTemp--;
				digitosDspTemp--;
				loopConverteTelaLcd--;
			}
			else
			{
				if(*displayPesoTemp == ' ')
				{
					*digitosDspTemp = ValorTabelaEspaco;
				}
				if(*displayPesoTemp == '-')
				{
					*digitosDspTemp = ValorTabelaTraco;
				}
				if((*displayPesoTemp >= '0') && (*displayPesoTemp <= '9'))
				{
					*digitosDspTemp = *displayPesoTemp;
					*digitosDspTemp	-= 0x30; //converte de ascii para decimal
					if(ControleConvertePontoDecimal == 1)
					{
						ControleConvertePontoDecimal = 0;
						*digitosDspTemp += ValorPontoDecimalDspSeteSegmentos;
					}
				}
				if((*displayPesoTemp >= 'A') && (*displayPesoTemp <= 'Z'))
				{
					*digitosDspTemp = *displayPesoTemp;
					*digitosDspTemp	-= 55; //converte letra maiuscula da posicao da tabela de 7 segmentos
					if(ControleConvertePontoDecimal == 1)
					{
						*digitosDspTemp = *digitosDspTemp + ValorPontoDecimalDspSeteSegmentos;
						ControleConvertePontoDecimal = 0;
					}
				}
				if((*displayPesoTemp >= 'a') && (*displayPesoTemp <= 'z'))
				{
					*digitosDspTemp = *displayPesoTemp;
					*digitosDspTemp	=*digitosDspTemp - 87; //converte letra minuscula da posicao da tabela de 7 segmentos
					if(ControleConvertePontoDecimal == 1)
					{
						*digitosDspTemp = *digitosDspTemp + ValorPontoDecimalDspSeteSegmentos;
						ControleConvertePontoDecimal = 0;
					}
				}
				displayPesoTemp--;
				digitosDspTemp--;
			}
		}

		if((menuCalibraIndicador == menuCapacidadeMaxima)
			|| (menuCalibraIndicador == menuPesoCalibracao))
		{
			if(flagPiscaProgIndicador == 1 && flagTempoPiscaProgIndicador == 1)
			{

			}
			else
			{
				if(mostraTelaTemporariaLcd == 0)
				{
					digitosLcdSeteSegmentos[6 - posicaoPontoDecimalIndicadorMem] += 128;
				}
			}
		}
	}
}

///////////////////////////////////////////////////////////////////////////////////
/* TELA VERSAO 7SEG						                                         */
///////////////////////////////////////////////////////////////////////////////////
void telaVersaoSeteSegmentos(void)
{
	// versao, conforme telaInicialVersao -> 3.0.0
	digitosLcdSeteSegmentos[0] = Letra_V;
	digitosLcdSeteSegmentos[1] = Letra_E;
	digitosLcdSeteSegmentos[2] = Letra_R;
	digitosLcdSeteSegmentos[3] = 3;
	digitosLcdSeteSegmentos[4] = 0 + ValorPontoDecimalDspSeteSegmentos;
	digitosLcdSeteSegmentos[5] = 0 + ValorPontoDecimalDspSeteSegmentos;
}

///////////////////////////////////////////////////////////////////////////////////
/*TELA SUB CARGA SETE SEGMENTOS		                                             */
///////////////////////////////////////////////////////////////////////////////////
void telaSubCargaSeteSegmentos(void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'S';
		dadoLcdSetSegmentos[2] = 'U';
		dadoLcdSetSegmentos[3] = 'B';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'C';
		dadoLcdSetSegmentos[6] = 'A';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'U';
		dadoLcdSetSegmentos[2] = 'N';
		dadoLcdSetSegmentos[3] = 'D';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'L';
		dadoLcdSetSegmentos[6] = 'O';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'B';
		dadoLcdSetSegmentos[2] = 'A';
		dadoLcdSetSegmentos[3] = 'J';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'P';
		dadoLcdSetSegmentos[6] = 'E';
	}
}
///////////////////////////////////////////////////////////////////////////////////
/*TELA SOBRE CARGA SETE SEGMENTOS	                                             */
///////////////////////////////////////////////////////////////////////////////////
void telaSobreCargaSeteSegmentos(void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'S';
		dadoLcdSetSegmentos[2] = 'O';
		dadoLcdSetSegmentos[3] = 'B';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'C';
		dadoLcdSetSegmentos[6] = 'A';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'O';
		dadoLcdSetSegmentos[2] = 'V';
		dadoLcdSetSegmentos[3] = 'R';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'L';
		dadoLcdSetSegmentos[6] = 'O';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'S';
		dadoLcdSetSegmentos[2] = 'O';
		dadoLcdSetSegmentos[3] = 'B';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'P';
		dadoLcdSetSegmentos[6] = 'E';
	}
}
///////////////////////////////////////////////////////////////////////////////////
/*TELA AGUARDE CONGELAMENTO				                                         */
///////////////////////////////////////////////////////////////////////////////////
void telaAguardeSeteSegmentos(void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'A';
		dadoLcdSetSegmentos[2] = 'G';
		dadoLcdSetSegmentos[3] = 'U';
		dadoLcdSetSegmentos[4] = 'A';
		dadoLcdSetSegmentos[5] = 'R';
		dadoLcdSetSegmentos[6] = 'D';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'W';
		dadoLcdSetSegmentos[2] = 'A';
		dadoLcdSetSegmentos[3] = 'I';
		dadoLcdSetSegmentos[4] = 'T';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'E';
		dadoLcdSetSegmentos[2] = 'S';
		dadoLcdSetSegmentos[3] = 'P';
		dadoLcdSetSegmentos[4] = 'E';
		dadoLcdSetSegmentos[5] = 'R';
		dadoLcdSetSegmentos[6] = 'A';
	}
}
///////////////////////////////////////////////////////////////////////////////////
/*TELA PESO CALIBRACAO					                                         */
///////////////////////////////////////////////////////////////////////////////////
void telaPesoCalibracaoSeteSegmentos (void) 
{
	if((linguagemSelecionadaMem == _PORTUGUES)
		|| (linguagemSelecionadaMem == _ESPANHOL))
	{
		dadoLcdSetSegmentos[1] = 'P';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'S';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'C';
		dadoLcdSetSegmentos[6] = 'A';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'A';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = 'W';
		dadoLcdSetSegmentos[5] = 'E';
		dadoLcdSetSegmentos[6] = 'I';
	}

	/* Necessario que seja temporaria no display de sete segmentos */
	mostraTelaTemporariaLcd = 1;
	tempoMostraTelaTemporariaLcd = 0;
}
///////////////////////////////////////////////////////////////////////////////////
/*TELA CAPACIDADE MAXIMA 				                                         */
///////////////////////////////////////////////////////////////////////////////////
void telaCapacidadeMaximaSeteSegmentos (void) 
{
	if((linguagemSelecionadaMem == _PORTUGUES)
		|| (linguagemSelecionadaMem == _ESPANHOL))
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'A';
		dadoLcdSetSegmentos[3] = 'P';
		dadoLcdSetSegmentos[4] = 'M';
		dadoLcdSetSegmentos[5] = 'A';
		dadoLcdSetSegmentos[6] = 'X';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'M';
		dadoLcdSetSegmentos[2] = 'A';
		dadoLcdSetSegmentos[3] = 'X';
		dadoLcdSetSegmentos[4] = 'W';
		dadoLcdSetSegmentos[5] = 'E';
		dadoLcdSetSegmentos[6] = 'I';
	}

	/* Necessario que seja temporaria no display de sete segmentos */
	mostraTelaTemporariaLcd = 1;
	tempoMostraTelaTemporariaLcd = 0;
}
///////////////////////////////////////////////////////////////////////////////////
/*TELA SEM PESO							                                         */
///////////////////////////////////////////////////////////////////////////////////
void telaSemPesoSeteSegmentos (void) 
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'S';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'M';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'P';
		dadoLcdSetSegmentos[6] = 'E';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'N';
		dadoLcdSetSegmentos[2] = 'O';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = 'W';
		dadoLcdSetSegmentos[5] = 'E';
		dadoLcdSetSegmentos[6] = 'I';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'S';
		dadoLcdSetSegmentos[2] = 'I';
		dadoLcdSetSegmentos[3] = 'N';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'P';
		dadoLcdSetSegmentos[6] = 'E';
	}
}

void telaComPesoSeteSegmentos (void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'O';
		dadoLcdSetSegmentos[3] = 'M';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'P';
		dadoLcdSetSegmentos[6] = 'E';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'W';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'I';
		dadoLcdSetSegmentos[4] = 'G';
		dadoLcdSetSegmentos[5] = 'H';
		dadoLcdSetSegmentos[6] = 'T';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'O';
		dadoLcdSetSegmentos[3] = 'N';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'P';
		dadoLcdSetSegmentos[6] = 'E';
	}
}

void telaConfigSerialSeteSegmentos (void)
{
	/* Mesma string para os 3 idiomas */
	dadoLcdSetSegmentos[1] = 'C';
	dadoLcdSetSegmentos[2] = 'F';
	dadoLcdSetSegmentos[3] = 'G';
	dadoLcdSetSegmentos[4] = ' ';
	dadoLcdSetSegmentos[5] = 'S';
	dadoLcdSetSegmentos[6] = 'E';
}

void telaAcessaMenuModoTecnicoSeteSegmentos (void)
{
	/* Mesma string para os 3 idiomas */
	dadoLcdSetSegmentos[1] = 'P';
	dadoLcdSetSegmentos[2] = 'R';
	dadoLcdSetSegmentos[3] = 'O';
	dadoLcdSetSegmentos[4] = 'G';
	dadoLcdSetSegmentos[5] = ' ';
	dadoLcdSetSegmentos[6] = 'T';
}

void telaAcessaMenuCalibracaoSeteSegmentos (void) 
{
	/* Mesma string para os 3 idiomas */
	dadoLcdSetSegmentos[1] = 'C';
	dadoLcdSetSegmentos[2] = 'A';
	dadoLcdSetSegmentos[3] = 'L';
	dadoLcdSetSegmentos[4] = 'I';
	dadoLcdSetSegmentos[5] = 'B';
	dadoLcdSetSegmentos[6] = 'R';
}

void telaConfLimiteZeroSeteSegmentos (void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'L';
		dadoLcdSetSegmentos[2] = 'Z';
		dadoLcdSetSegmentos[3] = 'e';
		dadoLcdSetSegmentos[4] = 'r';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = tempConfigIndicador + '0';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'Z';
		dadoLcdSetSegmentos[2] = 'e';
		dadoLcdSetSegmentos[3] = 'r';
		dadoLcdSetSegmentos[4] = 'L';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = tempConfigIndicador + '0';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'L';
		dadoLcdSetSegmentos[2] = 'C';
		dadoLcdSetSegmentos[3] = 'e';
		dadoLcdSetSegmentos[4] = 'r';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = tempConfigIndicador + '0';
	}
}

void telaValorFiltroDigitalSeteSegmentos (void)
{
	dadoLcdSetSegmentos[1] = 'F';
	dadoLcdSetSegmentos[2] = 'I';
	dadoLcdSetSegmentos[3] = 'L';
	dadoLcdSetSegmentos[4] = ' ';
	dadoLcdSetSegmentos[5] = ' ';
	dadoLcdSetSegmentos[6] = ' ';

	if (menuModoTecnicoIndicador == defineFiltroDigital)
	{
		inteiroTo2BytesAscii(tempConfigIndicador, &dadoLcdSetSegmentos[5]);
	}

	if (menuCalibraIndicador == menuFiltroDigital)
	{
		inteiroTo2BytesAscii(tempProgIndicador, &dadoLcdSetSegmentos[5]);
	}
}

void telaMostraStatusZeroLigarSeteSegmentos (void)
{
	/* Mesma string para os 2 idiomas */
	if ((linguagemSelecionadaMem == _PORTUGUES) || (linguagemSelecionadaMem == _INGLES))
	{
		dadoLcdSetSegmentos[1] = 'Z';
		dadoLcdSetSegmentos[2] = 'P';
		dadoLcdSetSegmentos[3] = 'o';
	}
	
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'P';
		dadoLcdSetSegmentos[3] = 'o';
	}

	if (tempConfigIndicador == 1)
	{
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'N';
	}
	if (tempConfigIndicador == 0)
	{
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'F';
	}
}

void telaMostraFuncionamentoBackLightSeteSegmentos (void)
{
	/* Mesma string para os 2 idiomas */
	if((linguagemSelecionadaMem == _PORTUGUES) || (linguagemSelecionadaMem == _INGLES))
	{
		dadoLcdSetSegmentos[1] = 'B';
		dadoLcdSetSegmentos[2] = 'L';
		dadoLcdSetSegmentos[3] = ' ';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'L';
		dadoLcdSetSegmentos[2] = 'F';
		dadoLcdSetSegmentos[3] = ' ';		
	}	

	if (tempConfigIndicador == _BACKLIGHT_DESLIGADO)
	{	
		dadoLcdSetSegmentos[4] = 'O';
		dadoLcdSetSegmentos[5] = 'F';	
		dadoLcdSetSegmentos[6] = 'F';	
	}
	if (tempConfigIndicador == _BACKLIGHT_LIGADO)
	{
		dadoLcdSetSegmentos[4] = ' ';	
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'N';	
	}
	if (tempConfigIndicador == _BACKLIGHT_TEMPORIZADO)
	{
		dadoLcdSetSegmentos[4] = 'T';
		dadoLcdSetSegmentos[5] = 'M';	
		dadoLcdSetSegmentos[6] = 'P';	
	}
}

void telaTempoBackLightSeteSegmentos (void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'T';
		dadoLcdSetSegmentos[2] = 'B';
		dadoLcdSetSegmentos[3] = 'L';
		dadoLcdSetSegmentos[4] = ' ';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'B';
		dadoLcdSetSegmentos[2] = 'L';
		dadoLcdSetSegmentos[3] = 'T';
		dadoLcdSetSegmentos[4] = ' ';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'T';
		dadoLcdSetSegmentos[2] = 'L';
		dadoLcdSetSegmentos[3] = 'F';
		dadoLcdSetSegmentos[4] = ' ';		
	}	

	inteiroTo2BytesAscii(tempConfigIndicador,&dadoLcdSetSegmentos[5]);
}

void telaMostraSelecionaIdiomaSeteSegmentos (void)
{
	/* Mesma string para os 2 idiomas */
	if ((linguagemSelecionadaMem == _PORTUGUES) || (linguagemSelecionadaMem == _ESPANHOL))
	{
		dadoLcdSetSegmentos[1] = 'I';
		dadoLcdSetSegmentos[2] = 'd';
		dadoLcdSetSegmentos[3] = ' ';
	}
	if (linguagemSelecionadaMem == _INGLES) 
	{
		dadoLcdSetSegmentos[1] = 'L';
		dadoLcdSetSegmentos[2] = 'n';
		dadoLcdSetSegmentos[3] = ' ';
	}

	if(tempConfigModoFuncionamento == _PORTUGUES)
	{
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'P';
		dadoLcdSetSegmentos[6] = 'T';
	}
	if(tempConfigModoFuncionamento == _INGLES)
	{
		dadoLcdSetSegmentos[4] = 'E';
		dadoLcdSetSegmentos[5] = 'N';
		dadoLcdSetSegmentos[6] = 'G';
	}
	if(tempConfigModoFuncionamento == _ESPANHOL)
	{
		dadoLcdSetSegmentos[4] = 'E';
		dadoLcdSetSegmentos[5] = 'S';
		dadoLcdSetSegmentos[6] = 'P';		
	}	
}

void telaMostraNaoSeAplicaSeteSegmentos (void)
{
	dadoLcdSetSegmentos[1] = ' ';
	dadoLcdSetSegmentos[2] = ' ';
	dadoLcdSetSegmentos[3] = ' ';
	dadoLcdSetSegmentos[4] = ' ';
	dadoLcdSetSegmentos[5] = 'N';
	dadoLcdSetSegmentos[6] = 'A';	
}

void telaSenhaSeteSegmentos (void)
{
	if((linguagemSelecionadaMem == _PORTUGUES) || (linguagemSelecionadaMem == _ESPANHOL))
	{
		dadoLcdSetSegmentos[1] = 'S';
		dadoLcdSetSegmentos[2] = 'N';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'P';
		dadoLcdSetSegmentos[2] = 'W';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
		dadoLcdSetSegmentos[5] = ' ';
	}
}

void telaPosicaoPontoSeteSegmentos (void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = ' ';
		dadoLcdSetSegmentos[2] = 'P';
		dadoLcdSetSegmentos[3] = 'o';
		dadoLcdSetSegmentos[4] = 'n';
		dadoLcdSetSegmentos[5] = 't';
		dadoLcdSetSegmentos[6] = 'o';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = ' ';
		dadoLcdSetSegmentos[2] = ' ';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = 'd';
		dadoLcdSetSegmentos[5] = 'o';
		dadoLcdSetSegmentos[6] = 't';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = ' ';		
		dadoLcdSetSegmentos[2] = 'P';
		dadoLcdSetSegmentos[3] = 'u';
		dadoLcdSetSegmentos[4] = 'n';
		dadoLcdSetSegmentos[5] = 't';
		dadoLcdSetSegmentos[6] = 'o';
	}	

	/* Insere o ponto na posicao atual */
	digitosLcdSeteSegmentos[6 - tempProgIndicador] += ValorPontoDecimalDspSeteSegmentos;
}

void telaDefineDegrauPesoSeteSegmentos (void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'd';
		dadoLcdSetSegmentos[2] = 'e';
		dadoLcdSetSegmentos[3] = 'g';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'S';
		dadoLcdSetSegmentos[2] = 't';
		dadoLcdSetSegmentos[3] = 'p';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'P';		
		dadoLcdSetSegmentos[2] = 'a';
		dadoLcdSetSegmentos[3] = 's';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
	}
}

void telaAguardeCalibracaoSeteSegmentos (void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'A';
		dadoLcdSetSegmentos[2] = 'g';
		dadoLcdSetSegmentos[3] = 'u';
		dadoLcdSetSegmentos[4] = 'a';
		dadoLcdSetSegmentos[5] = 'r';
		dadoLcdSetSegmentos[6] = 'd';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'W';
		dadoLcdSetSegmentos[2] = 'a';
		dadoLcdSetSegmentos[3] = 'i';
		dadoLcdSetSegmentos[4] = 't';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'E';		
		dadoLcdSetSegmentos[2] = 's';
		dadoLcdSetSegmentos[3] = 'p';
		dadoLcdSetSegmentos[4] = 'e';
		dadoLcdSetSegmentos[5] = 'r';
		dadoLcdSetSegmentos[6] = 'a';
	}
}

void telaMostraProgVelSerial_1SeteSegmentos (void)
{
	dadoLcdSetSegmentos[1] = 'B';
	dadoLcdSetSegmentos[2] = 'R';

	switch (velocidadeTxSerial_1)
	{
		case velocidade1200Kbps:
			dadoLcdSetSegmentos[3] = '1';
			dadoLcdSetSegmentos[4] = '2';
			dadoLcdSetSegmentos[5] = '0';
			dadoLcdSetSegmentos[6] = '0';

			/* ponto */
			digitosLcdSeteSegmentos[3] += ValorPontoDecimalDspSeteSegmentos;
			break;
		case velocidade2400Kbps:
			dadoLcdSetSegmentos[3] = '2';
			dadoLcdSetSegmentos[4] = '4';
			dadoLcdSetSegmentos[5] = '0';
			dadoLcdSetSegmentos[6] = '0';

			/* ponto */
			digitosLcdSeteSegmentos[3] += ValorPontoDecimalDspSeteSegmentos;
			break;                            
		case velocidade4800Kbps:
			dadoLcdSetSegmentos[3] = '4';
			dadoLcdSetSegmentos[4] = '8';
			dadoLcdSetSegmentos[5] = '0';
			dadoLcdSetSegmentos[6] = '0';

			/* ponto */
			digitosLcdSeteSegmentos[3] += ValorPontoDecimalDspSeteSegmentos;
			break;
		case velocidade9600Kbps:
			dadoLcdSetSegmentos[3] = '9';
			dadoLcdSetSegmentos[4] = '6';
			dadoLcdSetSegmentos[5] = '0';
			dadoLcdSetSegmentos[6] = '0';

			/* ponto */
			digitosLcdSeteSegmentos[3] += ValorPontoDecimalDspSeteSegmentos;
			break;
		case velocidade19200Kbps:
			dadoLcdSetSegmentos[3] = '1';
			dadoLcdSetSegmentos[4] = '9';
			dadoLcdSetSegmentos[5] = '2';
			dadoLcdSetSegmentos[6] = '0';

			/* ponto */
			digitosLcdSeteSegmentos[4] += ValorPontoDecimalDspSeteSegmentos;
			break;
		case velocidade38400Kbps:
			dadoLcdSetSegmentos[3] = '3';
			dadoLcdSetSegmentos[4] = '8';
			dadoLcdSetSegmentos[5] = '4';
			dadoLcdSetSegmentos[6] = '0';

			/* ponto */
			digitosLcdSeteSegmentos[4] += ValorPontoDecimalDspSeteSegmentos;
			break;
		case velocidade57600Kbps:
			dadoLcdSetSegmentos[3] = '5';
			dadoLcdSetSegmentos[4] = '7';
			dadoLcdSetSegmentos[5] = '6';
			dadoLcdSetSegmentos[6] = '0';

			/* ponto */
			digitosLcdSeteSegmentos[4] += ValorPontoDecimalDspSeteSegmentos;
			break;
		case velocidade115200Kbps:
			dadoLcdSetSegmentos[3] = '1';
			dadoLcdSetSegmentos[4] = '1';
			dadoLcdSetSegmentos[5] = '5';
			dadoLcdSetSegmentos[6] = '2';

			/* ponto */
			digitosLcdSeteSegmentos[5] += ValorPontoDecimalDspSeteSegmentos;
			break;
		default:
			break;
	}
}

void telaMostraAtivDesativSerial_1SeteSegmentos (void)
{
	dadoLcdSetSegmentos[1] = 'S';		
	dadoLcdSetSegmentos[2] = '1';
	dadoLcdSetSegmentos[3] = ' ';

	if (tempConfigSerial == _SERIAL_1ATIVADA)
	{
		if (linguagemSelecionadaMem == _PORTUGUES) 
		{
			dadoLcdSetSegmentos[4] = 'A';		
			dadoLcdSetSegmentos[5] = 'T';
			dadoLcdSetSegmentos[6] = 'V';
		}
		if (linguagemSelecionadaMem == _INGLES) 
		{
			dadoLcdSetSegmentos[4] = 'E';		
			dadoLcdSetSegmentos[5] = 'N';
			dadoLcdSetSegmentos[6] = 'B';
		}
		if (linguagemSelecionadaMem == _ESPANHOL) 
		{
			dadoLcdSetSegmentos[4] = 'A';		
			dadoLcdSetSegmentos[5] = 'C';
			dadoLcdSetSegmentos[6] = 'T';
		}
	}
	else
	{
		/* Mesma string para os 2 idiomas */
		if ((linguagemSelecionadaMem == _PORTUGUES) || (linguagemSelecionadaMem == _ESPANHOL))
		{
			dadoLcdSetSegmentos[4] = 'D';		
			dadoLcdSetSegmentos[5] = 'E';
			dadoLcdSetSegmentos[6] = 'S';
		}
		if (linguagemSelecionadaMem == _INGLES) 
		{
			dadoLcdSetSegmentos[4] = 'D';		
			dadoLcdSetSegmentos[5] = 'I';
			dadoLcdSetSegmentos[6] = 'S';
		}
	}
}

void telaMostraTipoPortaSerial_1SeteSegmentos (void)
{
	/* Mesma string para os 3 idiomas: Porta/Port/Puerta */
	dadoLcdSetSegmentos[1] = 'P'; 
	dadoLcdSetSegmentos[2] = '1';
	dadoLcdSetSegmentos[3] = ' ';

	if (tempConfigSerial == _RS232)
	{
		dadoLcdSetSegmentos[4] = '2';		
		dadoLcdSetSegmentos[5] = '3';
		dadoLcdSetSegmentos[6] = '2';
	}
    if (tempConfigSerial == _RS485)
	{
		dadoLcdSetSegmentos[4] = '4';		
		dadoLcdSetSegmentos[5] = '8';
		dadoLcdSetSegmentos[6] = '5';
	}  
}

void telaMostraTipoSaidaSerial_1SeteSegmentos (void)
{
	/* Mesma string para os 3 idiomas: Formato/Format */
	dadoLcdSetSegmentos[1] = 'F';		
	dadoLcdSetSegmentos[2] = '1';
	dadoLcdSetSegmentos[3] = ' ';	

	if (tempConfigSerial == _TRANSMISSAOCONTINUA_1) 
	{
		dadoLcdSetSegmentos[4] = 'T';		
		dadoLcdSetSegmentos[5] = 'C';
		dadoLcdSetSegmentos[6] = '1';
	}
	if (tempConfigSerial == _TRANSMISSAOCONTINUA_2)
	{
		dadoLcdSetSegmentos[4] = 'T';		
		dadoLcdSetSegmentos[5] = 'C';
		dadoLcdSetSegmentos[6] = '2';
	}
    if (tempConfigSerial == _MODBUS_RTU)
	{
		dadoLcdSetSegmentos[4] = 'R';		
		dadoLcdSetSegmentos[5] = 'T';
		dadoLcdSetSegmentos[6] = 'U';
	}
}

void telaMostraTipoSaidaSerial_2SeteSegmentos (void)
{
	/* Mesma string para os 3 idiomas: Formato/Format */
	dadoLcdSetSegmentos[1] = 'F';		
	dadoLcdSetSegmentos[2] = '2';
	dadoLcdSetSegmentos[3] = ' ';	

	if (tempConfigSerial == _TRANSMISSAOCONTINUA_1) 
	{
		dadoLcdSetSegmentos[4] = 'T';		
		dadoLcdSetSegmentos[5] = 'C';
		dadoLcdSetSegmentos[6] = '1';
	}
	if (tempConfigSerial == _TRANSMISSAOCONTINUA_2)
	{
		dadoLcdSetSegmentos[4] = 'T';		
		dadoLcdSetSegmentos[5] = 'C';
		dadoLcdSetSegmentos[6] = '2';
	}
}

void telaMostraenderecoIndicadorSeteSegmentos (void)
{
	if (linguagemSelecionadaMem == _PORTUGUES) 
	{
		dadoLcdSetSegmentos[1] = 'E';		
		dadoLcdSetSegmentos[2] = 'N';
		dadoLcdSetSegmentos[3] = 'D';
	}
	if (linguagemSelecionadaMem == _INGLES) 
	{
		dadoLcdSetSegmentos[1] = 'A';		
		dadoLcdSetSegmentos[2] = 'D';
		dadoLcdSetSegmentos[3] = 'R';
	}
	if (linguagemSelecionadaMem == _ESPANHOL) 
	{
		dadoLcdSetSegmentos[1] = 'D';		
		dadoLcdSetSegmentos[2] = 'I';
		dadoLcdSetSegmentos[3] = 'R';
	}	

	dadoLcdSetSegmentos[4] = ' ';

	inteiroTo2BytesAscii(tempConfigSerial,&dadoLcdSetSegmentos[5]);
}

void telaMostraQtFramePorSegundoSeteSegmentos (void)
{
	/* Mesma sting para os 2 idiomas */
	if ((linguagemSelecionadaMem == _PORTUGUES) || (linguagemSelecionadaMem == _INGLES))
	{
		dadoLcdSetSegmentos[1] = 'F';		
		dadoLcdSetSegmentos[2] = 'P';
		dadoLcdSetSegmentos[3] = 'S';		
	}
	if (linguagemSelecionadaMem == _ESPANHOL) 
	{
		dadoLcdSetSegmentos[1] = 'C';		
		dadoLcdSetSegmentos[2] = 'P';
		dadoLcdSetSegmentos[3] = 'S';		
	}

	dadoLcdSetSegmentos[4] = ' ';

	inteiroTo2BytesAscii(tempConfigSerial,&dadoLcdSetSegmentos[5]);
}

void telaAcessaConfiguraRelogioSeteSegmentos (void)
{
	if (linguagemSelecionadaMem == _PORTUGUES) 
	{
		dadoLcdSetSegmentos[1] = 'D';		
		dadoLcdSetSegmentos[2] = 'A';
		dadoLcdSetSegmentos[3] = 'T';
		dadoLcdSetSegmentos[4] = '-';
		dadoLcdSetSegmentos[5] = 'H';
		dadoLcdSetSegmentos[6] = 'R';
	}
	if (linguagemSelecionadaMem == _INGLES) 
	{
		dadoLcdSetSegmentos[1] = 'D';		
		dadoLcdSetSegmentos[2] = 'A';
		dadoLcdSetSegmentos[3] = 'T';
		dadoLcdSetSegmentos[4] = '-';
		dadoLcdSetSegmentos[5] = 'T';
		dadoLcdSetSegmentos[6] = 'M';
	}
	if (linguagemSelecionadaMem == _ESPANHOL) 
	{
		dadoLcdSetSegmentos[1] = 'F';		
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'C';
		dadoLcdSetSegmentos[4] = '-';
		dadoLcdSetSegmentos[5] = 'H';
		dadoLcdSetSegmentos[6] = 'R';
	}		
}

void telaMostraProgExibeRelogioSeteSegmentos (void)
{
	if (linguagemSelecionadaMem == _PORTUGUES) 
	{
		dadoLcdSetSegmentos[1] = 'R';		
		dadoLcdSetSegmentos[2] = 'L';
		dadoLcdSetSegmentos[3] = 'G';
	}
	if (linguagemSelecionadaMem == _INGLES) 
	{
		dadoLcdSetSegmentos[1] = 'C';		
		dadoLcdSetSegmentos[2] = 'L';
		dadoLcdSetSegmentos[3] = 'K';
	}
	if (linguagemSelecionadaMem == _ESPANHOL) 
	{
		dadoLcdSetSegmentos[1] = 'R';		
		dadoLcdSetSegmentos[2] = 'L';
		dadoLcdSetSegmentos[3] = 'J';
	}	

	dadoLcdSetSegmentos[4] = ' ';

	if (tempProgDataHora == 1)
    {
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'N';
    } 
	else 
	{
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'F';
    }
}

void telaMostraProgHoraDataSeteSegmentos (void)
{
	switch (menuProgramacaoRelogioAtual)
	{
	case menuProgramaHoraH:
	case menuProgramaHoraL:
		dadoLcdSetSegmentos[1] = 'H';		
		dadoLcdSetSegmentos[2] = 'H';
		dadoLcdSetSegmentos[3] = ' '; 
		dadoLcdSetSegmentos[4] = ' ';

		dadoLcdSetSegmentos[5] = arrayProgHora[0];
		dadoLcdSetSegmentos[6] = arrayProgHora[1];
		break;
	case menuProgramaMinutoH:
	case menuProgramaMinutoL:
		dadoLcdSetSegmentos[1] = 'm';		
		dadoLcdSetSegmentos[2] = 'm';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = ' ';

		dadoLcdSetSegmentos[5] = arrayProgMinuto[0];
		dadoLcdSetSegmentos[6] = arrayProgMinuto[1];
		break;
	case menuProgramaDiaH:
	case menuProgramaDiaL:
		dadoLcdSetSegmentos[1] = 'd';		
		dadoLcdSetSegmentos[2] = 'd';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = ' ';

		dadoLcdSetSegmentos[5] = arrayProgDia[0];
		dadoLcdSetSegmentos[6] = arrayProgDia[1];		
		break;
	case menuProgramaMesH:
	case menuProgramaMesL:
		dadoLcdSetSegmentos[1] = 'M';		
		dadoLcdSetSegmentos[2] = 'M';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = ' ';

		dadoLcdSetSegmentos[5] = arrayProgMes[0];
		dadoLcdSetSegmentos[6] = arrayProgMes[1];				
		break;
	case menuProgramaAnoH:
	case menuProgramaAnoL:
		dadoLcdSetSegmentos[1] = 'A';		
		dadoLcdSetSegmentos[2] = 'A';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = ' ';

		dadoLcdSetSegmentos[5] = arrayProgAno[0];
		dadoLcdSetSegmentos[6] = arrayProgAno[1];		
		break;
	default:
		/* do nothing */
		break;
	}
}

void telaMostraHoraSeteSegmentos (void)
{
	dadoLcdSetSegmentos[1] = ' ';

	inteiroTo2BytesAscii(horaRelogio,&dadoLcdSetSegmentos[2]);

	if (piscaCaracter == 1)
	{
		dadoLcdSetSegmentos[4] = 'h';
	}
	else
	{
		dadoLcdSetSegmentos[4] = ' ';
	}

	inteiroTo2BytesAscii(minutoRelogio,&dadoLcdSetSegmentos[5]);
}

void telaZeroOkCalibracaoSeteSegmentos (void)
{
	/* Mesma string para os 2 idiomas */
	if ((linguagemSelecionadaMem == _PORTUGUES) || (linguagemSelecionadaMem == _INGLES))
	{
		dadoLcdSetSegmentos[1] = 'Z';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'R';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'K';
	}
	if (linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'R';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'K';
	}
}

void telaCertoCalibracaoSeteSegmentos (void)
{
	if (linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'R';
		dadoLcdSetSegmentos[4] = 'T';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if (linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'R';
		dadoLcdSetSegmentos[2] = 'I';
		dadoLcdSetSegmentos[3] = 'G';
		dadoLcdSetSegmentos[4] = 'H';
		dadoLcdSetSegmentos[5] = 'T';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if (linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'B';
		dadoLcdSetSegmentos[2] = 'I';
		dadoLcdSetSegmentos[3] = 'E';
		dadoLcdSetSegmentos[4] = 'N';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
	}
}