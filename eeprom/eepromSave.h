//////////////////////////////////////////////////////////////////////////////////		
//              funcoes d eescrita na Memrom        	                  		//
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar o status de funcionamento da       	//
//da comunicacao da serial 1                                                    //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusFuncionamentoTxSerial_1Mem(void)
{    
	Data_Write_I2c[endStatusComunicacaoSerial1Mem] = statusComunicacaoSerial_1Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 0, tamanhoPagina, 
		&Data_Write_I2c[endStatusComunicacaoSerial1Mem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar a velocidade de comunicacao       	//
//da serial 1                                                                   //
//////////////////////////////////////////////////////////////////////////////////	
void salvaVelocidadeTxSerial_1Mem(void)
{    
	Data_Write_I2c[endVelocidadeTxSerial1Mem] = velocidadeTxSerial_1Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 1, tamanhoPagina, 
		&Data_Write_I2c[endVelocidadeTxSerial1Mem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar o status da saida da serial 1       	//
//se ser� rs 232 ou rs485                                                       //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusSaidaPortaSerial_1Mem(void)
{    
	Data_Write_I2c[endStatusPortaSerial1Mem] = statusPortaSerial_1Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 2, tamanhoPagina, 
		&Data_Write_I2c[endStatusPortaSerial1Mem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar a forma de saida de dados pela serial //
//1                                                                             //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusSaidaDadosSerial_1Mem(void)
{    
	Data_Write_I2c[endStatusSaidaDadosSerial1Mem] = statusSaidaDadosSerial_1Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 3, tamanhoPagina, 
		&Data_Write_I2c[endStatusSaidaDadosSerial1Mem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar a forma de saida de dados pela serial //
//2                                                                             //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusSaidaDadosSerial_2Mem(void)
{    
	Data_Write_I2c[endStatusSaidaDadosSerial2Mem] = statusSaidaDadosSerial_2Mem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 4, tamanhoPagina,
		&Data_Write_I2c[endStatusSaidaDadosSerial2Mem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar o endere�o Indicador              	//
//////////////////////////////////////////////////////////////////////////////////	
void salvaEnderecoIndicadorMem(void)
{    
	Data_Write_I2c[endEnderecoIndicadorMem] = enderecoIndicadorMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 5, tamanhoPagina, 
		&Data_Write_I2c[endEnderecoIndicadorMem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que salva a quantidade de frames que ser�o transmitidas por segundo  	//
//quando no modo transmis�o continua                                            //
//////////////////////////////////////////////////////////////////////////////////	
void salvaQtFramePorSegundoMem(void)
{    
	Data_Write_I2c[endQtFramePorSegundoMem] = qtFramePorSegundoMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 6, tamanhoPagina, 
		&Data_Write_I2c[endQtFramePorSegundoMem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar o status de de ligado/deligado    	//
// enviar o comando para zerar o indicador apos peso menor que resto permitido  //                                                                    //
//////////////////////////////////////////////////////////////////////////////////		
void preparaSalvaStatusPowerOnMem(void)
{
	Data_Write_I2c[endStatusPowerOnMem] = statusPowerOnMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 7, tamanhoPagina, 
		&Data_Write_I2c[endStatusPowerOnMem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar o modo de funcionamento do back light //
//////////////////////////////////////////////////////////////////////////////////	
void salvaModoFuncionamentoBackLightMem(void)
{    
	Data_Write_I2c[endModoFuncionamentoBacklightMem] = modoFuncionamentoBackLightMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 8, tamanhoPagina, 
		&Data_Write_I2c[endModoFuncionamentoBacklightMem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar o tempo para desligamento do          //
//back light                                                                    //
//////////////////////////////////////////////////////////////////////////////////	
void salvaTempoDesligaBackLightMem(void)
{    
	Data_Write_I2c[endTempoDesligaBacklightMem] = modoFuncionamentoBackLightMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 9, tamanhoPagina, 
		&Data_Write_I2c[endTempoDesligaBacklightMem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para salvar o status da execucao do zero ao ligar //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusZeroPowerMem(void)
{    
	Data_Write_I2c[endStatusZeroAoLigarMem] = statusZeroAoLigarMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 10, tamanhoPagina, 
		&Data_Write_I2c[endStatusZeroAoLigarMem], umByte, 10);
}
/*salva valor do limite de zero permitido*/
void salvaValorLimiteDeZeroMem(void)
{
	Data_Write_I2c[endValorLimiteDeZeroMem] = valorLimiteDeZeroMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 11, tamanhoPagina, 
		&Data_Write_I2c[endValorLimiteDeZeroMem], umByte, 10);
}
/* salva o valor do filtro digital                                              */
void salvaValorFiltroDigitalMem(void)
{
	Data_Write_I2c[endValorFiltroDigitalMem] = valorFiltroDigitalMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 12, tamanhoPagina, 
		&Data_Write_I2c[endValorFiltroDigitalMem], umByte, 10);
}
/* salva o valor da posicao do ponto decimal                                  */
void salvaPosicaoPontoDecimalIndicadorMem(void)
{
	Data_Write_I2c[endPosicaoPontoDecimalIndicadorMem] = posicaoPontoDecimalIndicadorMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 13, tamanhoPagina, 
		&Data_Write_I2c[endPosicaoPontoDecimalIndicadorMem], umByte, 10);
}
/* salva o valor do degral do indicador de peso                               */
void salvaPosicaoDegrauIndicadorMem(void)
{
	Data_Write_I2c[endDegrauIndicadorMem] = degrauIndicadorMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 14, tamanhoPagina, 
		&Data_Write_I2c[endDegrauIndicadorMem], umByte, 10);
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que prepara os dados para se a transmis�o automatica de dados esta   	//
//ativa ou desativada                                                           //
//////////////////////////////////////////////////////////////////////////////////	
void salvaStatusTransmisaoAutomaticoMem(void)
{    
    transfereArrayToArray(2,&statusTransmiteAutomaticoMem[0],
		&Data_Write_I2c[endStatusTransmiteAutomaticoMem]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 15, tamanhoPagina, 
		&Data_Write_I2c[endStatusTransmiteAutomaticoMem], 2, 20);
}
/* salva o peso definido como capacidade maxima para o indicador              */
void salvaPesoCapacidadeMaxIndicadorMem(void)
{
    transfereArrayToArray(8,&capacidadeMaximaIndicadorMem[0],
		&Data_Write_I2c[endCapacidadeMaximaIndicadorMem]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 17, tamanhoPagina, 
		&Data_Write_I2c[endCapacidadeMaximaIndicadorMem], 8, 50);
}
/* salva o peso definido como peso de calibracao                              */
void salvaPesoCalibracaoIndicadorMem(void)
{
    transfereArrayToArray(8,&pesoCalibracaoIndicadorMem[0],
		&Data_Write_I2c[endPesoCalibracaoIndicadorMem]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 25, tamanhoPagina, 
		&Data_Write_I2c[endPesoCalibracaoIndicadorMem], 8, 50);
}
/* salva o valor ad definido com zero do indicador                             */
void salvaValorAdZeroIndicadorMem(void)
{
    transfereArrayToArray(4,&valorZeroIndicadorMem.array4[0],
		&Data_Write_I2c[endValorZeroIndicadorMem]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 33, tamanhoPagina, 
		&Data_Write_I2c[endValorZeroIndicadorMem], 4, 50);
}
/* salva o valor da divisao do peso                                              */
void salvaValorDivisaoIndicadorMem(void)
{
    transfereArrayToArray(4,&valorDivisaoIndicadorMem.array4[0],
		&Data_Write_I2c[endValorDivisaoIndicadorMem]);
    HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 37, tamanhoPagina, 
		&Data_Write_I2c[endValorDivisaoIndicadorMem], 4, 50);
}
/* salva o nome do indicador na tela inicial 									*/
void salvaNomeTelaIndicadorMem(void)//16BITS
{
	transfereArrayToArray(16,&nomeTelaIndicadorMem[0],
		&Data_Write_I2c[endNomeTelaIniciallMem]);
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 41, tamanhoPagina, 
		&Data_Write_I2c[endNomeTelaIniciallMem], 16, 50);
}
/* salva a linguagem selecionada */
void salvaLinguagemSelecionadaMem(void)
{
	Data_Write_I2c[endlinguagemSelecionadaMem] = linguagemSelecionadaMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, endlinguagemSelecionadaMem, tamanhoPagina, 
		&Data_Write_I2c[endlinguagemSelecionadaMem], umByte, 10);
}
/* salva o funcionamento de exibicao do relogio */
void salvaExibeRelogio(void)
{
	Data_Write_I2c[endExibeRelogioMem] = exibeRelogioMem;
	HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, endExibeRelogioMem, tamanhoPagina, 
		&Data_Write_I2c[endExibeRelogioMem], umByte, 10);
}