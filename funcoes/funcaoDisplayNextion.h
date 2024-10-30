//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//                                												//
//      		   FUNCAO DE ESCRITA DO DISPLAY GRAFICO NEXTION                 //
//                                                                            	//
/**/extern UART_HandleTypeDef huart3;									 		//
//////////////////////////////////////////////////////////////////////////////////

void mostraPesoKg(void)
{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							carregaArrayComEspacoAscii(32,&frameTx0Nextion[0]); 								 //
							transfereConstToArray(&linhaPeso,&frameTx0Nextion[0]);							 	 //
							transfereArrayToArray(5,&pesoBrutoIndicadorAscii[2],&frameTx0Nextion[8]);		 	 //
							frameTx0Nextion[13] ='\"';															 //
							transfereConstToArray(&cmd_end,&frameTx0Nextion[14]);								 //
							HAL_UART_Transmit(&huart3, &frameTx0Nextion[0], 17,15);								 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void mostraPesoTaraKg(void)
{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							carregaArrayComEspacoAscii(32,&frameTx0Nextion[0]); 								 //
							transfereConstToArray(&linhaPeso,&frameTx0Nextion[0]);							 	 //
							transfereArrayToArray(5,&pesoLiquidoIndicadorAscii[2],&frameTx0Nextion[8]);		 	 //
							frameTx0Nextion[13] ='\"';															 //
							transfereConstToArray(&cmd_end,&frameTx0Nextion[14]);								 //
							HAL_UART_Transmit(&huart3, &frameTx0Nextion[0], 17,15);								 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void ocultaPesoKg(void)
{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							carregaArrayComEspacoAscii(32,&frameTx0Nextion[0]); 								 //
							transfereConstToArray(&linhaPeso,&frameTx0Nextion[0]);							 	 //
							frameTx0Nextion[8] ='-';															 //
							frameTx0Nextion[9] ='-';															 //
							frameTx0Nextion[10] ='-';															 //
							frameTx0Nextion[11] ='-';															 //
							frameTx0Nextion[12] ='-';															 //
							frameTx0Nextion[13] ='-';															 //
							frameTx0Nextion[14] ='-';															 //
							frameTx0Nextion[15] ='\"';															 //
							transfereConstToArray(&cmd_end,&frameTx0Nextion[16]);								 //
							HAL_UART_Transmit(&huart3, &frameTx0Nextion[0], 19,15);								 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void transfereCaracterLcdLinha1(void)
{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							carregaArrayComEspacoAscii(32,&frameTx2Nextion[0]); 								 //
							transfereConstToArray(&linha1Peso,&frameTx2Nextion[0]);							 	 //
							transfereArrayToArray(16,&caracterLcd[0],&frameTx2Nextion[8]);						 //
							frameTx2Nextion[24] ='\"';															 //
							transfereConstToArray(&cmd_end,&frameTx2Nextion[25]);								 //
							HAL_UART_Transmit(&huart3, &frameTx2Nextion[0], 28,15);								 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void transfereCaracterLcdLinha2(void)
{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							carregaArrayComEspacoAscii(32,&frameTx3Nextion[0]); 								 //
							transfereConstToArray(&linha2Peso,&frameTx3Nextion[0]);							 	 //
							transfereArrayToArray(16,&caracterLcd[16],&frameTx3Nextion[8]);						 //
							frameTx3Nextion[24] ='\"';															 //
							transfereConstToArray(&cmd_end,&frameTx3Nextion[25]);								 //
							HAL_UART_Transmit(&huart3, &frameTx3Nextion[0], 28,15);								 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void transfereCaracterLcdMenuLinha1(void)
{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							carregaArrayComEspacoAscii(32,&frame1Menu[0]); 										 //
							transfereConstToArray(&linha0Menu,&frame1Menu[0]);								 	 //
							transfereArrayToArray(16,&caracterLcd[0],&frame1Menu[8]);							 //
							frame1Menu[24] ='\"';																 //
							transfereConstToArray(&cmd_end,&frame1Menu[25]);									 //
							HAL_UART_Transmit(&huart3, &frame1Menu[0], 28,15);									 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void transfereCaracterLcdMenuLinha2(void)
{
	if (caracterLcd[29] == '<' || caracterLcd[30] == 'C' || caracterLcd[31] == 'C')
		{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
								carregaArrayComEspacoAscii(32,&frame2Menu[0]); 										 //
								transfereConstToArray(&linha1Menu,&frame2Menu[0]);								 	 //
								transfereArrayToArray(16,&caracterLcd[16],&frame2Menu[8]);						 	 //
								frame2Menu[20] ='\"';																 //
								transfereConstToArray(&cmd_end,&frame2Menu[21]);									 //
								HAL_UART_Transmit(&huart3, &frame2Menu[0], 24,15);									 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}
	else
		{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
								carregaArrayComEspacoAscii(32,&frame2Menu[0]); 										 //
								transfereConstToArray(&linha1Menu,&frame2Menu[0]);								 	 //
								transfereArrayToArray(16,&caracterLcd[16],&frame2Menu[8]);						 	 //
								frame2Menu[24] ='\"';																 //
								transfereConstToArray(&cmd_end,&frame2Menu[25]);									 //
								HAL_UART_Transmit(&huart3, &frame2Menu[0], 28,15);									 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		}

}

void transfereCaracterLcdErroLimiteZero(void)
{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							carregaArrayComEspacoAscii(32,&frameTx3Nextion[0]); 								 //
							transfereConstToArray(&linha2Peso,&frameTx3Nextion[0]);							 	 //
							transfereArrayToArray(16,&caracterLcd[0],&frameTx3Nextion[8]);						 //
							frameTx3Nextion[24] ='\"';															 //
							transfereConstToArray(&cmd_end,&frameTx3Nextion[25]);								 //
							HAL_UART_Transmit(&huart3, &frameTx3Nextion[0], 28,15);								 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void limpaLinha2(void)
{
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							carregaArrayComEspacoAscii(32,&frameTx3Nextion[0]); 								 //
							transfereConstToArray(&linha2Peso,&frameTx3Nextion[0]);							 	 //
							frameTx3Nextion[8] =' ';															 //
							frameTx3Nextion[9] =' ';															 //
							frameTx3Nextion[10] ='\"';															 //
							transfereConstToArray(&cmd_end,&frameTx3Nextion[11]);								 //
							HAL_UART_Transmit(&huart3, &frameTx3Nextion[0], 14,15);								 //
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

void setaKgTelaPeso(void)
{
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
								carregaArrayComEspacoAscii(32,&frameKgPeso[0]); 								 //
								transfereConstToArray(&linhaKg,&frameKgPeso[0]);							 	 //
								frameKgPeso[9] ='K';															 //
								frameKgPeso[10] ='g';															 //
								frameKgPeso[11] ='\"';															 //
								transfereConstToArray(&cmd_end,&frameKgPeso[12]);								 //
								HAL_UART_Transmit(&huart3, &frameKgPeso[0], 15,15);								 //
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}
