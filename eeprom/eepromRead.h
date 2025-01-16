#include "transfereArrayToArray.h"
#include "carregaArrayComZeroAscii.h"
//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//              funcoes de Escrita e gravacao an eeprom	                  		//		
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que le os dados da eeprom na inicialziacao		            			//
//////////////////////////////////////////////////////////////////////////////////		
void le_i2c(void)
{
	statusComunicacaoSerial_1Mem =	Data_Write_I2c[endStatusComunicacaoSerial1Mem];
	velocidadeTxSerial_1Mem = Data_Write_I2c[endVelocidadeTxSerial1Mem];
	statusPortaSerial_1Mem = Data_Write_I2c[endStatusPortaSerial1Mem];
	statusSaidaDadosSerial_1Mem = Data_Write_I2c[endStatusSaidaDadosSerial1Mem];
	statusSaidaDadosSerial_2Mem = Data_Write_I2c[endStatusSaidaDadosSerial2Mem];
	enderecoIndicadorMem = Data_Write_I2c[endEnderecoIndicadorMem];
	qtFramePorSegundoMem= Data_Write_I2c[endQtFramePorSegundoMem];
	statusPowerOnMem = Data_Write_I2c[endStatusPowerOnMem];
	modoFuncionamentoBackLightMem = Data_Write_I2c[endModoFuncionamentoBacklightMem];
	tempoDesligaBackLightMem = Data_Write_I2c[endTempoDesligaBacklightMem];
	statusZeroAoLigarMem = Data_Write_I2c[endStatusZeroAoLigarMem];
	valorLimiteDeZeroMem = Data_Write_I2c[endValorLimiteDeZeroMem];
	valorFiltroDigitalMem = Data_Write_I2c[endValorFiltroDigitalMem];
	posicaoPontoDecimalIndicadorMem = Data_Write_I2c[endPosicaoPontoDecimalIndicadorMem];
	degrauIndicadorMem = Data_Write_I2c[endDegrauIndicadorMem];

/* le o valor definido para status Transmite Automatico                         */
	transfereArrayToArray(2,&Data_Write_I2c[endStatusTransmiteAutomaticoMem],&statusTransmiteAutomaticoMem[0]);

/* le o peso definido como capacidade maxima para o indicador                   */
	transfereArrayToArray(8,&Data_Write_I2c[endCapacidadeMaximaIndicadorMem],&capacidadeMaximaIndicadorMem[0]);
	carregaArrayComZeroAscii(10,&arrayInteiroTemp[0]);
	transfereArrayToArray(8,&capacidadeMaximaIndicadorMem[0],&arrayInteiroTemp[2]);
	rotacionaArrayInsere0Converte();
	valorPesoCargaMaxima = atol(arrayInteiroTemp);

/* le o peso definido como peso calibracao indicador           			        */
	transfereArrayToArray(8,&Data_Write_I2c[endPesoCalibracaoIndicadorMem],&pesoCalibracaoIndicadorMem[0]);

/* le o peso definido como valor zero indicador             					*/
	transfereArrayToArray(4,&Data_Write_I2c[endValorZeroIndicadorMem],&valorZeroIndicadorMem.array4[0]);
    valorZeroIndicador = valorZeroIndicadorMem.int32;
    valorTaraIndicador = valorZeroIndicador;

/* le o peso definido como valor divisao indicador              				*/
	transfereArrayToArray(4,&Data_Write_I2c[endValorDivisaoIndicadorMem],&valorDivisaoIndicadorMem.array4[0]);
	valorDivisaoIndicador = valorDivisaoIndicadorMem.float32;

/* le o nome definido para a tela inicial			              				*/
	transfereArrayToArray(16,&Data_Write_I2c[endNomeTelaIniciallMem],&nomeTelaIndicadorMem[0]);

/* le a linguagem definida */
	linguagemSelecionadaMem = Data_Write_I2c[endlinguagemSelecionadaMem];

	exibeRelogioMem = Data_Write_I2c[endExibeRelogioMem];
}

void leituraI2c_Default(void)
{
	HAL_I2C_Mem_Read(EEPROM_I2C, EEPROM_ADDR, 0, tamanhoPagina, &Data_Write_I2c[0], 64, 700);
	if (Data_Write_I2c[63] != 1)
	{
		transfereConstToArrayLoop(64,&defaultEeprom[0],&Data_Write_I2c[0]);
		HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 0, tamanhoPagina, &Data_Write_I2c[0], 64, 700);
	}	
	le_i2c();
}

void TimerReadi2c (void)
{
	if (flagFazLeituraI2c == 1)
	{
		if (++tempoLeituraI2c > 5)
		{
			flagFazLeituraI2c = 0;
			tempoLeituraI2c = 0;
			leituraI2c_Default();
		}
	}
}
