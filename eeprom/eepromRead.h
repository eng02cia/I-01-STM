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
	statusComunicacaoSerial_1Mem =	Data_Write_I2c[0];
	velocidadeTxSerial_1Mem = Data_Write_I2c[1];
	statusPortaSerial_1Mem = Data_Write_I2c[2];
	statusSaidaDadosSerial_1Mem = Data_Write_I2c[3];
	statusSaidaDadosSerial_2Mem = Data_Write_I2c[4];
	enderecoIndicadorMem = Data_Write_I2c[5];
	qtFramePorSegundoMem= Data_Write_I2c[6];
	statusPowerOnMem = Data_Write_I2c[7];
	modoFuncionamentoBackLightMem = Data_Write_I2c[8];
	tempoDesligaBackLightMem = Data_Write_I2c[9];
	statusZeroAoLigarMem = Data_Write_I2c[10];
	valorLimiteDeZeroMem = Data_Write_I2c[11];
	valorFiltroDigitalMem = Data_Write_I2c[12];
	posicaoPontoDecimalIndicadorMem = Data_Write_I2c[13];
	degrauIndicadorMem = Data_Write_I2c[14];

/* le o valor definido para status Transmite Automatico                         */
	transfereArrayToArray(2,&Data_Write_I2c[15],&statusTransmiteAutomaticoMem[0]);

/* le o peso definido como capacidade maxima para o indicador                   */
	transfereArrayToArray(8,&Data_Write_I2c[17],&capacidadeMaximaIndicadorMem[0]);
	carregaArrayComZeroAscii(10,&arrayInteiroTemp[0]);
	transfereArrayToArray(8,&capacidadeMaximaIndicadorMem[0],&arrayInteiroTemp[2]);
	rotacionaArrayInsere0Converte();
	valorPesoCargaMaxima = atol(arrayInteiroTemp);

/* le o peso definido como peso calibracao indicador           			        */
	transfereArrayToArray(8,&Data_Write_I2c[25],&pesoCalibracaoIndicadorMem[0]);

/* le o peso definido como valor zero indicador             					*/
	transfereArrayToArray(4,&Data_Write_I2c[33],&valorZeroIndicadorMem.array4[0]);
    valorZeroIndicador = valorZeroIndicadorMem.int32;
    valorTaraIndicador = valorZeroIndicador;

/* le o peso definido como valor divisao indicador              				*/
	transfereArrayToArray(4,&Data_Write_I2c[37],&valorDivisaoIndicadorMem.array4[0]);
	valorDivisaoIndicador = valorDivisaoIndicadorMem.float32;

/* le o nome definido para a tela inicial			              				*/
	transfereArrayToArray(16,&Data_Write_I2c[41],&nomeTelaIndicadorMem[0]);
}

void leituraI2c_Default(void)
{
	HAL_I2C_Mem_Read(EEPROM_I2C, EEPROM_ADDR, 0, tamanhoPagina, &Data_Write_I2c[0], 64, 200);
	if (Data_Write_I2c[63] != 1)
	{
		transfereConstToArrayLoop(64,&defaultEeprom[0],&Data_Write_I2c[0]);
		HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 0, tamanhoPagina, &Data_Write_I2c[0], 32, 700);
		HAL_Delay(10);
		HAL_I2C_Mem_Write(EEPROM_I2C, EEPROM_ADDR, 32, tamanhoPagina, &Data_Write_I2c[32], 32, 700);
		HAL_Delay(10);
		le_i2c();
	}
	else
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
