//////////////////////////////////////////////////////////////////////////////////		
//              funcoes d eescrita na Memrom        	                  		//
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar o status de funcionamento da       	//
//da comunica��o da serial 1                                                    //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusFuncionamentoTxSerial_1Mem(void)
{    
	Data_Write_I2c[0] = statusComunicacaoSerial_1Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 0, tamanhoPagina, &Data_Write_I2c[0], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar a velocidade de comunicacao       	//
//da serial 1                                                                   //
//////////////////////////////////////////////////////////////////////////////////	
void salvaVelocidadeTxSerial_1Mem(void)
{    
	Data_Write_I2c[1] = velocidadeTxSerial_1Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 1, tamanhoPagina, &Data_Write_I2c[1], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar o status da saida da serial 1       	//
//se ser� rs 232 ou rs485                                                       //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusSaidaPortaSerial_1Mem(void)
{    
	Data_Write_I2c[2] = statusPortaSerial_1Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 2, tamanhoPagina, &Data_Write_I2c[2], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar a forma de saida de dados pela serial //
//1                                                                             //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusSaidaDadosSerial_1Mem(void)
{    
	Data_Write_I2c[3] = statusSaidaDadosSerial_1Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 3, tamanhoPagina, &Data_Write_I2c[3], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar a forma de saida de dados pela serial //
//2                                                                             //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusSaidaDadosSerial_2Mem(void)
{    
	Data_Write_I2c[4] = statusSaidaDadosSerial_2Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 4, tamanhoPagina, &Data_Write_I2c[4], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar o endere�o Indicador              	//
//////////////////////////////////////////////////////////////////////////////////	
void salvaEnderecoIndicadorMem(void)
{    
	Data_Write_I2c[5] = enderecoIndicadorMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 5, tamanhoPagina, &Data_Write_I2c[5], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que salva a quantidade de frames que ser�o transmitidas por segundo  	//
//quando no modo transmis�o continua                                            //
//////////////////////////////////////////////////////////////////////////////////	
void salvaQtFramePorSegundoMem(void)
{    
	Data_Write_I2c[6] = qtFramePorSegundoMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 6, tamanhoPagina, &Data_Write_I2c[6], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar o status de de ligado/deligado    	//
// enviar o comando para zerar o indicador apos peso menor que resto permitido  //                                                                    //
//////////////////////////////////////////////////////////////////////////////////		
void preparaSalvaStatusPowerOnMem(void)
{
	Data_Write_I2c[7] = statusPowerOnMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 7, tamanhoPagina, &Data_Write_I2c[7], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para se a transmis�o automatica de dados esta   	//
//ativa ou desativada                                                           //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusTransmisaoAutomaticoMem(void)
{    
    transfereArrayToArray(2,&statusTransmiteAutomaticoMem[0],&Data_Write_I2c[16]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 16, tamanhoPagina, &Data_Write_I2c[16], 2, 20);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar o modo de funcionamento do back light //
//////////////////////////////////////////////////////////////////////////////////	
void salvaModoFuncionamentoBackLightMem(void)
{    
	Data_Write_I2c[8] = modoFuncionamentoBackLightMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 8, tamanhoPagina, &Data_Write_I2c[8], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar o tempo para desligamento do          //
//back light                                                                    //
//////////////////////////////////////////////////////////////////////////////////	
void salvaTempoDesligaBackLightMem(void)
{    
	Data_Write_I2c[9] = modoFuncionamentoBackLightMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 9, tamanhoPagina, &Data_Write_I2c[9], umBit, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que prepara os dados para salvar o status da execu��o do zero ao ligar //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusZeroPowerMem(void)
{    
	Data_Write_I2c[10] = statusZeroAoLigarMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 10, tamanhoPagina, &Data_Write_I2c[10], umBit, 10);
}
/*salva valor do limite de zero permitido*/
void salvaValorLimiteDeZeroMem(void)
{
	Data_Write_I2c[11] = valorLimiteDeZeroMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 11, tamanhoPagina, &Data_Write_I2c[11], umBit, 10);
}
/* salva o valor do filtro digital                                              */
void salvaValorFiltroDigitalMem(void)
{
	Data_Write_I2c[12] = valorFiltroDigitalMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 12, tamanhoPagina, &Data_Write_I2c[12], umBit, 10);
}
/* salva o valor da posi��o do ponto decimal                                  */
void salvaPosicaoPontoDecimalIndicadorMem(void)
{
	Data_Write_I2c[13] = posicaoPontoDecimalIndicadorMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 13, tamanhoPagina, &Data_Write_I2c[13], umBit, 10);
}
/* salva o valor do degral do indicador de peso                               */
void salvaPosicaoDegrauIndicadorMem(void)
{
	Data_Write_I2c[14] = degrauIndicadorMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 14, tamanhoPagina, &Data_Write_I2c[14], umBit, 10);
}
/* salva o peso definido como capacidade maxima para o indicador              */
void salvaPesoCapacidadeMaxIndicadorMem(void)
{
    transfereArrayToArray(8,&capacidadeMaximaIndicadorMem[0],&Data_Write_I2c[24]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 24, tamanhoPagina, &Data_Write_I2c[24], 8, 50);
}
/* salva o peso definido como peso de calibra��o                              */
void salvaPesoCalibracaoIndicadorMem(void)
{
    transfereArrayToArray(8,&pesoCalibracaoIndicadorMem[0],&Data_Write_I2c[32]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 32, tamanhoPagina, &Data_Write_I2c[32], 8, 50);
}
/* salva o valor ad definido com zero do indicador                             */
void salvaValorAdZeroIndicadorMem(void)
{
    transfereArrayToArray(4,&valorZeroIndicadorMem.array4[0],&Data_Write_I2c[40]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 40, tamanhoPagina, &Data_Write_I2c[40], 4, 50);
}
/* salva o valor da divisao do peso                                              */
void salvaValorDivisaoIndicadorMem(void)
{
    transfereArrayToArray(4,&valorDivisaoIndicadorMem.array4[0],&Data_Write_I2c[44]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 44, tamanhoPagina, &Data_Write_I2c[44], 4, 50);
}
//////////////////////////////////////////////////////////////////////////////////		
//fun��o loop salvamento de dados na Memrom     								//
//////////////////////////////////////////////////////////////////////////////////	
