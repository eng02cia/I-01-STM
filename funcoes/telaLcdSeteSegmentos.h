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
		if (menuAcessaMenusProgramacao != menuAcessaMenusProgramacaoEmEspera
		|| menuCalibraIndicador != menuCalibraIndicadorEmEspera
		|| menuModoTecnicoIndicador != menuModoTecnicoIndicadorEmEspera
		|| menuProgramacaoRelogioAtual != menuProgramaRelogioEmEspera
		|| menuProgramaDefinicaoFucionamento != menuDefinicaoFuncionamentoEmEspera)
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
void telaPesoCalibracaoSeteSeg (void) 
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
}
///////////////////////////////////////////////////////////////////////////////////
/*TELA SEM PESO							                                         */
///////////////////////////////////////////////////////////////////////////////////
void telaSemPesoSeteSeg (void) 
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
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = tempConfigIndicador + '0';
		dadoLcdSetSegmentos[6] = 'p';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'Z';
		dadoLcdSetSegmentos[2] = 'e';
		dadoLcdSetSegmentos[3] = 'L';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = tempConfigIndicador + '0';
		dadoLcdSetSegmentos[6] = 'p';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'L';
		dadoLcdSetSegmentos[2] = 'C';
		dadoLcdSetSegmentos[3] = 'e';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = tempConfigIndicador + '0';
		dadoLcdSetSegmentos[6] = 'p';
	}
}

void telaValorFiltroDigitalSeteSegmentos (void)
{
	if ((linguagemSelecionadaMem == _PORTUGUES) || (linguagemSelecionadaMem == _ESPANHOL))
	{
		dadoLcdSetSegmentos[1] = 'F';
		dadoLcdSetSegmentos[2] = 'D';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = ' ';
	}
	if (linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'D';
		dadoLcdSetSegmentos[2] = 'F';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = ' ';
	}

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
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'Z';
		dadoLcdSetSegmentos[2] = 'P';
		dadoLcdSetSegmentos[3] = ' ';
	}
	
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'Z';
		dadoLcdSetSegmentos[2] = 'P';
		dadoLcdSetSegmentos[3] = ' ';

	}

	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'P';
		dadoLcdSetSegmentos[3] = ' ';
	}

	if (tempConfigIndicador == 1)
	{
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'N';
	}
	if (tempConfigIndicador == 0)
	{
		dadoLcdSetSegmentos[4] = 'O';
		dadoLcdSetSegmentos[5] = 'F';
		dadoLcdSetSegmentos[6] = 'F';
	}
}

void telaMostraFuncionamentoBackLightSeteSegmentos (void)
{
	if(linguagemSelecionadaMem == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'B';
		dadoLcdSetSegmentos[2] = 'L';
		dadoLcdSetSegmentos[3] = ' ';
	}
	if(linguagemSelecionadaMem == _INGLES)
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

	if (tempConfigIndicador == 0)
	{	
		dadoLcdSetSegmentos[4] = 'O';
		dadoLcdSetSegmentos[5] = 'F';	
		dadoLcdSetSegmentos[6] = 'F';	
	}
	if (tempConfigIndicador == 1)
	{
		dadoLcdSetSegmentos[4] = ' ';	
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'N';	
	}
	if (tempConfigIndicador == 2)
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
	if(tempConfigModoFuncionamento == _PORTUGUES)
	{
		dadoLcdSetSegmentos[1] = 'I';
		dadoLcdSetSegmentos[2] = 'd';
		dadoLcdSetSegmentos[3] = 'i';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'P';
		dadoLcdSetSegmentos[6] = 'T';
	}
	if(tempConfigModoFuncionamento == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'L';
		dadoLcdSetSegmentos[2] = 'n';
		dadoLcdSetSegmentos[3] = ' ';
		dadoLcdSetSegmentos[4] = 'E';
		dadoLcdSetSegmentos[5] = 'N';
		dadoLcdSetSegmentos[6] = 'G';
	}
	if(tempConfigModoFuncionamento == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'I';
		dadoLcdSetSegmentos[2] = 'd';
		dadoLcdSetSegmentos[3] = ' ';
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
		dadoLcdSetSegmentos[1] = 'P';
		dadoLcdSetSegmentos[2] = 'o';
		dadoLcdSetSegmentos[3] = 'n';
		dadoLcdSetSegmentos[4] = 't';
		dadoLcdSetSegmentos[5] = 'o';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if(linguagemSelecionadaMem == _INGLES)
	{
		dadoLcdSetSegmentos[1] = 'd';
		dadoLcdSetSegmentos[2] = 'o';
		dadoLcdSetSegmentos[3] = 't';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if(linguagemSelecionadaMem == _ESPANHOL)
	{
		dadoLcdSetSegmentos[1] = 'P';
		dadoLcdSetSegmentos[2] = 'u';
		dadoLcdSetSegmentos[3] = 'n';
		dadoLcdSetSegmentos[4] = 't';
		dadoLcdSetSegmentos[5] = 'o';
		dadoLcdSetSegmentos[6] = ' ';		
	}	

	/* Insere o ponto na posicao atual */
	digitosLcdSeteSegmentos[6 - tempProgIndicador] += ValorPontoDecimalDspSeteSegmentos;
}