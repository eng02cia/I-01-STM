void ocultaPesoDwin(void)
{
	if (posicaoPontoDecimalIndicadorMem == 0)													 //
	{
		frameDwin0x1000[0] = 0;
		frameDwin0x1000[1] ='-';
		frameDwin0x1000[2] = 0;
		frameDwin0x1000[3] ='-';
		frameDwin0x1000[4] = 0;
		frameDwin0x1000[5] ='-';
		frameDwin0x1000[6] = 0;
		frameDwin0x1000[7] ='-';
		frameDwin0x1000[8] = 0;
		frameDwin0x1000[9] ='-';
		frameDwin0x1000[10] = 0;
		frameDwin0x1000[11] ='-';
		frameDwin0x1000[12] = 0;
		frameDwin0x1000[13] ='-';
		frameDwin0x1000[14] =0;
		frameDwin0x1000[15] ='-';
		writeVariableDWIN(19,0x2000,&frameDwin0x1000[0]);
		carregaArrayComEspacoAscii(32, &frameDwin0x2000[0]);
	}
	if (posicaoPontoDecimalIndicadorMem == 1 || posicaoPontoDecimalIndicadorMem == 2 || posicaoPontoDecimalIndicadorMem == 3 || posicaoPontoDecimalIndicadorMem == 4)
	{
		frameDwin0x2000[0] = 0;
		frameDwin0x2000[1] ='-';
		frameDwin0x2000[2] = 0;
		frameDwin0x2000[3] ='-';
		frameDwin0x2000[4] = 0;
		frameDwin0x2000[5] ='-';
		frameDwin0x2000[6] = 0;
		frameDwin0x2000[7] ='-';
		frameDwin0x2000[8] = 0;
		frameDwin0x2000[9] ='-';
		frameDwin0x2000[10] = 0;
		frameDwin0x2000[11] ='-';
		frameDwin0x2000[12] = 0;
		frameDwin0x2000[13] ='-';
		frameDwin0x2000[14] =0;
		frameDwin0x2000[15] ='-';
		writeVariableDWIN(19,0x3000,&frameDwin0x2000[0]);
		carregaArrayComEspacoAscii(32, &frameDwin0x3000[0]);
	}
}

void mostraPesoDwin(void)
{
	if (posicaoPontoDecimalIndicadorMem == 1 || posicaoPontoDecimalIndicadorMem == 2 || posicaoPontoDecimalIndicadorMem == 3 || posicaoPontoDecimalIndicadorMem == 4)
		{
			if (defineFont == 1)
			{
				defineFont = 0;
				voltaFonte = 1;
				carregaArrayComEspacoAscii(32, &frameDwin0x1000[0]);
				writeVariableDWIN(11,0x1000,&frameDwin0x1000[0]);
	//			goToPageDWIN(02);
			}

			if (pesoBrutoIndicadorAscii[2] != ' ')
			{
				frameDwin0x2000[0] = 0;
				frameDwin0x2000[1] = pesoBrutoIndicadorAscii[2];
				frameDwin0x2000[2] = 0;
				frameDwin0x2000[3] = pesoBrutoIndicadorAscii[3];
				frameDwin0x2000[4] = 0;
				frameDwin0x2000[5] = pesoBrutoIndicadorAscii[4];
				frameDwin0x2000[6] = 0;
				frameDwin0x2000[7] = pesoBrutoIndicadorAscii[5];
				frameDwin0x2000[8] = 0;
				frameDwin0x2000[9] = pesoBrutoIndicadorAscii[6];
				writeVariableDWIN(13,0x3000,&frameDwin0x2000[0]);
			}
			else
			{
				frameDwin0x2000[2] = 0;
				frameDwin0x2000[3] = pesoBrutoIndicadorAscii[3];
				frameDwin0x2000[4] = 0;
				frameDwin0x2000[5] = pesoBrutoIndicadorAscii[4];
				frameDwin0x2000[6] = 0;
				frameDwin0x2000[7] = pesoBrutoIndicadorAscii[5];
				frameDwin0x2000[8] = 0;
				frameDwin0x2000[9] = pesoBrutoIndicadorAscii[6];
				writeVariableDWIN(11,0x3000,&frameDwin0x2000[2]);
			}
		}
	else
		if (posicaoPontoDecimalIndicadorMem == 0)													 //
		{
			if (voltaFonte == 1)
			{
				defineFont = 1;
				voltaFonte = 0;
				carregaArrayComEspacoAscii(32, &frameDwin0x2000[0]);
				writeVariableDWIN(11,0x2000,&frameDwin0x2000[0]);
//				goToPageDWIN(00);
			}

			if (pesoBrutoIndicadorAscii[2] != ' ')
			{
				frameDwin0x1000[0] = 0;
				frameDwin0x1000[1] = pesoBrutoIndicadorAscii[2];
				frameDwin0x1000[2] = 0;
				frameDwin0x1000[3] = pesoBrutoIndicadorAscii[3];
				frameDwin0x1000[4] = 0;
				frameDwin0x1000[5] = pesoBrutoIndicadorAscii[4];
				frameDwin0x1000[6] = 0;
				frameDwin0x1000[7] = pesoBrutoIndicadorAscii[5];
				frameDwin0x1000[8] = 0;
				frameDwin0x1000[9] = pesoBrutoIndicadorAscii[6];
				writeVariableDWIN(13,0x2000,&frameDwin0x1000[0]);
			}
			else
			{
				frameDwin0x1000[2] = 0;
				frameDwin0x1000[3] = pesoBrutoIndicadorAscii[3];
				frameDwin0x1000[4] = 0;
				frameDwin0x1000[5] = pesoBrutoIndicadorAscii[4];
				frameDwin0x1000[6] = 0;
				frameDwin0x1000[7] = pesoBrutoIndicadorAscii[5];
				frameDwin0x1000[8] = 0;
				frameDwin0x1000[9] = pesoBrutoIndicadorAscii[6];
				writeVariableDWIN(11,0x2000,&frameDwin0x2000[2]);
			}

		}
}

void limpaLinha2Dwin(void)
{
	carregaArrayComEspacoAscii(32, &frameDwin0x1300[0]);
	writeVariableDWIN(16,0x1300,&frameDwin0x1300[0]);
}

void transfereCaracterLcdLinha1Dwin(void)
{
	if (caracterLcd[15] == 'C' || caracterLcd[16] == 'C' || caracterLcd[17] == 'C')
	{
		transfereArrayToArray(13,&caracterLcd[0],&frameDwin0x1200[0]);
		writeVariableDWIN(16,0x1200,&frameDwin0x1200[0]);

	}
	else
	{
		transfereArrayToArray(16,&caracterLcd[0],&frameDwin0x1200[0]);
		writeVariableDWIN(19,0x1200,&frameDwin0x1200[0]);
	}
}

void transfereCaracterLcdLinha2Dwin(void)
{
	if (caracterLcd[29] == '<' || caracterLcd[30] == 'C' || caracterLcd[31] == 'C')
	{
		transfereArrayToArray(13,&caracterLcd[16],&frameDwin0x1300[0]);
		writeVariableDWIN(16,0x1300,&frameDwin0x1300[0]);
	}
	else
	{
		transfereArrayToArray(16,&caracterLcd[16],&frameDwin0x1300[0]);
		writeVariableDWIN(19,0x1300,&frameDwin0x1300[0]);
	}

}

void transfereCaracterLcdMenu1Dwin(void)
{
	if (caracterLcd[15] == 'C' || caracterLcd[16] == 'C' || caracterLcd[17] == 'C')
	{
		transfereArrayToArray(13,&caracterLcd[0],&frameDwin0x1400[0]);
		writeVariableDWIN(16,0x1400,&frameDwin0x1400[0]);
	}
	else
	{
		transfereArrayToArray(16,&caracterLcd[0],&frameDwin0x1400[0]);
		writeVariableDWIN(19,0x1400,&frameDwin0x1400[0]);
	}
}

void transfereCaracterLcdMenu2Dwin(void)
{
	if (caracterLcd[29] == '<' || caracterLcd[30] == 'C' || caracterLcd[31] == 'C')
	{
		transfereArrayToArray(13,&caracterLcd[16],&frameDwin0x1500[0]);
		writeVariableDWIN(16,0x1500,&frameDwin0x1500[0]);
	}
	else
	{
		transfereArrayToArray(16,&caracterLcd[16],&frameDwin0x1500[0]);
		writeVariableDWIN(19,0x1500,&frameDwin0x1500[0]);
	}
}

void zeraTelaInicio(void)
{
	carregaArrayComEspacoAscii(32, frameDwin0x1000);
	carregaArrayComEspacoAscii(32, frameDwin0x1200);
	carregaArrayComEspacoAscii(32, frameDwin0x1300);

	writeVariableDWIN(35,0x1000,&frameDwin0x1000[0]);
	writeVariableDWIN(35,0x1200,&frameDwin0x1200[0]);
	writeVariableDWIN(35,0x1300,&frameDwin0x1300[0]);

}

/*void trocaTelaDwin(void)
{
	if (statusCargaBateriaModo2==semFonte)																		//
	{
		if (posicaoPontoDecimalIndicadorMem == 0)													 //
		{
			goToPageDWIN(00);
		}
		if (posicaoPontoDecimalIndicadorMem == 1 || posicaoPontoDecimalIndicadorMem == 2 || posicaoPontoDecimalIndicadorMem == 3 || posicaoPontoDecimalIndicadorMem == 4)
		{
			goToPageDWIN(01);
		}

	}
	if (statusCargaBateriaModo2==cargaCompleta)																		//
	{
		if (posicaoPontoDecimalIndicadorMem == 0)													 //
		{
			goToPageDWIN(04);
		}
		if (posicaoPontoDecimalIndicadorMem == 1 || posicaoPontoDecimalIndicadorMem == 2 || posicaoPontoDecimalIndicadorMem == 3 || posicaoPontoDecimalIndicadorMem == 4)
				{
					goToPageDWIN(06);
				}
	}

	if (statusCargaBateriaModo2==carregando)																			//
	{
		if (posicaoPontoDecimalIndicadorMem == 0)													 //
		{
			goToPageDWIN(03);
		}
		if (posicaoPontoDecimalIndicadorMem == 1 || posicaoPontoDecimalIndicadorMem == 2 || posicaoPontoDecimalIndicadorMem == 3 || posicaoPontoDecimalIndicadorMem == 4)
		{
			goToPageDWIN(05);
		}
	}

}
*/
