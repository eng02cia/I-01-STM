/*
 * flash.h
 *
 *  Created on: 25 de abr de 2022
 *      Author: Micro
 */

#ifndef INC_FLASH_H_
#define INC_FLASH_H_
#include "transfereConstToArray.h"
#include "transfereArrayToArray.h"
#include "transfereConstToArrayLoop.h"
unsigned char bytesDataFlash[60];

const char configFabrica[] = 
{		
	_SERIAL_1ATIVADA, 
	velocidade9600Kbps,
	_RS485,
	_MODBUS_RTU,
	_TRANSMISSAOCONTINUA_1,
	1,
	4,
	_LIGADO,
	_BACKLIGHT_TEMPORIZADO,
	3,
	_DESLIGADO,
	2,
	2,
	0,
	1,
	2,4,
	' ',' ',' ','2','0','0','0','0',
	' ',' ',' ',' ',' ',' ',' ',' ',
	' ',' ',' ',' ',
	' ',' ',' ',' ',	
};

//////////////////////////////////////////////////////////////////////////////////
//FUNCAO QUE GRAVA NA FLASH                                                   	//
//////////////////////////////////////////////////////////////////////////////////
void gravaFlash (void)
{

	bytesDataFlash[0] = statusComunicacaoSerial_1Mem; //1
    bytesDataFlash[1] = velocidadeTxSerial_1Mem; //4
	bytesDataFlash[2] = statusPortaSerial_1Mem; //0
	bytesDataFlash[3] = statusSaidaDadosSerial_1Mem; //2
	bytesDataFlash[4] = statusSaidaDadosSerial_2Mem; //0
	bytesDataFlash[5] = enderecoIndicadorMem; //1
    bytesDataFlash[6] = qtFramePorSegundoMem; //4
	bytesDataFlash[7] = statusPowerOnMem; //1
    bytesDataFlash[8] = modoFuncionamentoBackLightMem; //2
	bytesDataFlash[9] = tempoDesligaBackLightMem; //3
	bytesDataFlash[10] = statusZeroAoLigarMem; //0
	bytesDataFlash[11] = valorLimiteDeZeroMem; //2
	bytesDataFlash[12] = valorFiltroDigitalMem; //2
	bytesDataFlash[13] = posicaoPontoDecimalIndicadorMem; //0
	bytesDataFlash[14] = degrauIndicadorMem; //1


    transfereArrayToArray(2,&statusTransmiteAutomaticoMem[0],&bytesDataFlash[16]); //2,4

	transfereArrayToArray(8,&capacidadeMaximaIndicadorMem[0],&bytesDataFlash[24]);

	transfereArrayToArray(8,&pesoCalibracaoIndicadorMem[0],&bytesDataFlash[34]);

	transfereArrayToArray(4,&valorZeroIndicadorMem.array4[0],&bytesDataFlash[40]);

	transfereArrayToArray(4,&valorDivisaoIndicadorMem.array4[0],&bytesDataFlash[44]);


	Flash_Write_Data(0x0807F000 , (uint32_t *)bytesDataFlash, 12);

}
//////////////////////////////////////////////////////////////////////////////////
//FUNCAO QUE FAZ LEITURA NA FLASH                                               //   	//
//////////////////////////////////////////////////////////////////////////////////
void leituraFlash (void)
{
	statusComunicacaoSerial_1Mem =	bytesDataFlash[0];
	velocidadeTxSerial_1Mem = bytesDataFlash[1];
	statusPortaSerial_1Mem = bytesDataFlash[2];
	statusSaidaDadosSerial_1Mem = bytesDataFlash[3];
	enderecoIndicadorMem = bytesDataFlash[4];
	qtFramePorSegundoMem= bytesDataFlash[9];
	statusPowerOnMem = bytesDataFlash[6];
	modoFuncionamentoBackLightMem = bytesDataFlash[11];
	tempoDesligaBackLightMem = bytesDataFlash[12];
	statusZeroAoLigarMem = bytesDataFlash[5];
	valorLimiteDeZeroMem = bytesDataFlash[44];
	valorFiltroDigitalMem = bytesDataFlash[30];
	posicaoPontoDecimalIndicadorMem = bytesDataFlash[16];
	degrauIndicadorMem = bytesDataFlash[17];

/* le o valor definido para status Transmite Automatico                         */
	transfereArrayToArray(2,&bytesDataFlash[8],&statusTransmiteAutomaticoMem[0]);


/* le o peso definido como capacidade maxima para o indicador                   */
	transfereArrayToArray(8,&bytesDataFlash[18],&capacidadeMaximaIndicadorMem[0]);
	carregaArrayComZeroAscii(10,&arrayInteiroTemp[0]);
	transfereArrayToArray(8,&capacidadeMaximaIndicadorMem[0],&arrayInteiroTemp[2]);
	rotacionaArrayInsere0Converte();
	valorPesoCargaMaxima = atol(arrayInteiroTemp);

/* le o peso definido como valor zero indicador             					*/
	transfereArrayToArray(4,&bytesDataFlash[26],&valorZeroIndicadorMem.array4[0]);
    valorZeroIndicador = valorZeroIndicadorMem.int32;
    valorTaraIndicador = valorZeroIndicador;

/* le o peso definido como peso calibracao indicador           			        */
	transfereArrayToArray(8,&bytesDataFlash[32],&pesoCalibracaoIndicadorMem[0]);

/* le o peso definido como valor divisao indicador              				*/
	transfereArrayToArray(4,&bytesDataFlash[40],&valorDivisaoIndicadorMem.array4[0]);
	valorDivisaoIndicador = valorDivisaoIndicadorMem.float32;

}
//////////////////////////////////////////////////////////////////////////////////
//FUNCAO QUE FAZ LEITURA DA FLASH CASO ZERE O PROCESSADOR A 0xFFFFFFF           //
//////////////////////////////////////////////////////////////////////////////////
void leituraConfiguracao (void)
{

	Flash_Read_Data(0x0807F000 , &bytesDataFlash, 12); // 1 = 8BIT 10 = 44BIT
	if(bytesDataFlash[0] == 255)
	{
		transfereConstToArrayLoop(48,&configFabrica[0],&bytesDataFlash[0]);
		Flash_Write_Data(0x0807F000 , (uint32_t *)bytesDataFlash, 12);
	}
	leituraFlash();
}

//////////////////////////////////////////////////////////////////////////////////
//TIMER DA INICIALIZAÇÃO DA FLASH                                               //
//////////////////////////////////////////////////////////////////////////////////
void TimerReadFlash (void)
{
	if(flagFazLeituraFlash == 1)
			{
					if(++tempoLeituraFlash > 5)
					{
						flagFazLeituraFlash = 0;
						tempoLeituraFlash = 0;
						leituraConfiguracao();
					}
			}
}
#endif /* INC_FLASH_H_ */
