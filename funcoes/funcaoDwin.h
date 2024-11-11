extern UART_HandleTypeDef huart3;
extern UART_HandleTypeDef huart1;
#include "transfereConstToArray.h"
#include "transfereArrayToArray.h"
#include "carregaArrayComEspacoAscii.h"
#include "inteiroTo2BytesAscii.h"
#include "transfereConstToArrayLoop.h"

void carregaTela0(void)
{
	transfereConstToArrayLoop(10,&charTela0Dwin[0],&frameTxDwin[0]);
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],10,100);
}

void carregaTela1(void)
{
	transfereConstToArrayLoop(10,&charTela1Dwin[0],&frameTxDwin[0]);
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],10,100);
}
void carregaTela2(void)
{
	transfereConstToArrayLoop(10,&charTela2Dwin[0],&frameTxDwin[0]);
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],10,100);
}
void carregaTela11 (void)
{
	transfereConstToArrayLoop(10,&charTela11Dwin[0],&frameTxDwin[0]);
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],10,100);
}
//////////////////////////////////////////////////////////////////////////
// FUNÇÃO QUE MOSTRA O PESO DA BALANÇA NO DWIN   						//
//////////////////////////////////////////////////////////////////////////
void mostraPesoDwin(void)
{
	if(fazTelaInicialPesoDwin == 0)
	{
		contadorInicialTelaPesoDwin += 2;
		switch(contadorInicialTelaPesoDwin)
		{
		case 1:
			telaPesoDwin[1] = '0';
			telaPesoDwin[2] = '0';
			telaPesoDwin[3] = '0';
			telaPesoDwin[4] = '0';
			telaPesoDwin[5] = '0';
			telaPesoDwin[6] = '0';
			break;
		case 10:
			telaPesoDwin[1] = '1';
			telaPesoDwin[2] = '1';
			telaPesoDwin[3] = '1';
			telaPesoDwin[4] = '1';
			telaPesoDwin[5] = '1';
			telaPesoDwin[6] = '1';
			break;
		case 20:
			telaPesoDwin[1] = '2';
			telaPesoDwin[2] = '2';
			telaPesoDwin[3] = '2';
			telaPesoDwin[4] = '2';
			telaPesoDwin[5] = '2';
			telaPesoDwin[6] = '2';
			break;
		case 30:
			telaPesoDwin[1] = '3';
			telaPesoDwin[2] = '3';
			telaPesoDwin[3] = '3';
			telaPesoDwin[4] = '3';
			telaPesoDwin[5] = '3';
			telaPesoDwin[6] = '3';
			break;
		case 40:
			telaPesoDwin[1] = '4';
			telaPesoDwin[2] = '4';
			telaPesoDwin[3] = '4';
			telaPesoDwin[4] = '4';
			telaPesoDwin[5] = '4';
			telaPesoDwin[6] = '4';
			break;
		case 50:
			telaPesoDwin[1] = '5';
			telaPesoDwin[2] = '5';
			telaPesoDwin[3] = '5';
			telaPesoDwin[4] = '5';
			telaPesoDwin[5] = '5';
			telaPesoDwin[6] = '5';
			break;
		case 60:
			telaPesoDwin[1] = '6';
			telaPesoDwin[2] = '6';
			telaPesoDwin[3] = '6';
			telaPesoDwin[4] = '6';
			telaPesoDwin[5] = '6';
			telaPesoDwin[6] = '6';
			break;
		case 70:
			telaPesoDwin[1] = '7';
			telaPesoDwin[2] = '7';
			telaPesoDwin[3] = '7';
			telaPesoDwin[4] = '7';
			telaPesoDwin[5] = '7';
			telaPesoDwin[6] = '7';
			break;
		case 80:
			telaPesoDwin[1] = '8';
			telaPesoDwin[2] = '8';
			telaPesoDwin[3] = '8';
			telaPesoDwin[4] = '8';
			telaPesoDwin[5] = '8';
			telaPesoDwin[6] = '8';
			break;
		case 90:
			telaPesoDwin[1] = '9';
			telaPesoDwin[2] = '9';
			telaPesoDwin[3] = '9';
			telaPesoDwin[4] = '9';
			telaPesoDwin[5] = '9';
			telaPesoDwin[6] = '9';
			break;
		case 100:
			fazTelaInicialPesoDwin = 1;
			contadorInicialTelaPesoDwin = 0;
			controleTelaDwin = pesoReal;
			break;
		}
	}

	if(fazTelaInicialPesoDwin == 1)
	{
		tempPosicaoPontoDwin = 0;

		switch(controleTelaDwin)
		{
			case ocultaPeso:
				transfereConstToArray(&pesoTraco[0],&telaPesoDwin[0]);
				controleTelaDwin = pesoReal;
				tempPosicaoPontoDwin = 0;
				break;
			case holdPeso: // VERIFICAR
				//transfereArrayToArray(7,&pesoConvertidoKiloCargaVivaHolding[0],&telaPesoDwin[0]);
				controleTelaDwin = pesoReal;
				break;
			case pesoReal:
				transfereArrayToArray(7,&pesoBrutoIndicadorAscii[0],&telaPesoDwin[0]); // TESTE - Necessario utilizar peso tratado
				break;
		}
		if(tempPosicaoPontoDwin != 0)
		{
			retiraPontoDecimalDwin();
		}
	}

	//////////////////////////////////////////////////////////////////////////
	// transmite dado para o digito 1										//
	//////////////////////////////////////////////////////////////////////////
	transfereArrayToArray(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x10;
	frameTxDwin[5] = 0x00;
	frameTxDwin[6] = 0;
	frameTxDwin[7] = telaPesoDwin[6];
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,50);
	//////////////////////////////////////////////////////////////////////////
	// transmite dado para o digito 2										//
	//////////////////////////////////////////////////////////////////////////
	transfereArrayToArray(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x10;
	frameTxDwin[5] = 0x01;
	frameTxDwin[6] = 0;
	frameTxDwin[7] = telaPesoDwin[5];
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,50);
	//////////////////////////////////////////////////////////////////////////
	// transmite dado para o digito 3										//
	//////////////////////////////////////////////////////////////////////////
	transfereArrayToArray(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x10;
	frameTxDwin[5] = 0x02;
	frameTxDwin[6] = 0;
	frameTxDwin[7] = telaPesoDwin[4];
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,50);
	//////////////////////////////////////////////////////////////////////////
	// transmite dado para o digito 4										//
	//////////////////////////////////////////////////////////////////////////
	transfereArrayToArray(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x10;
	frameTxDwin[5] = 0x03;
	frameTxDwin[6] = 0;
	frameTxDwin[7] = telaPesoDwin[3];
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,50);
	//////////////////////////////////////////////////////////////////////////
	// transmite dado para o digito 5										//
	//////////////////////////////////////////////////////////////////////////
	transfereArrayToArray(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x10;
	frameTxDwin[5] = 0x04;
	frameTxDwin[6] = 0;
	frameTxDwin[7] = telaPesoDwin[2];
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,50);
	//////////////////////////////////////////////////////////////////////////
	// transmite dado para o digito 6										//
	//////////////////////////////////////////////////////////////////////////
	transfereArrayToArray(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x10;
	frameTxDwin[5] = 0x05;
	frameTxDwin[6] = 0;
	frameTxDwin[7] = telaPesoDwin[1];
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,50);

	//////////////////////////////////////////////////////////////////////////
	// controla posição ponto 100 gramas									//
	//////////////////////////////////////////////////////////////////////////
	transfereArrayToArray(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x20;
	frameTxDwin[5] = 0x00;
	frameTxDwin[6] = 0;
	if(tempPosicaoPontoDwin == 1){frameTxDwin[7] = '.';}
	else{frameTxDwin[7] = ' ';}
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,50);
	//////////////////////////////////////////////////////////////////////////
	// controla posição ponto 10 gramas									//
	//////////////////////////////////////////////////////////////////////////
	transfereArrayToArray(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x20;
	frameTxDwin[5] = 0x01;
	frameTxDwin[6] = 0;
	if(tempPosicaoPontoDwin == 2){frameTxDwin[7] = '.';}
	else{frameTxDwin[7] = ' ';}
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,50);
	//////////////////////////////////////////////////////////////////////////
	// controla posição ponto 1 grama					        			//
	//////////////////////////////////////////////////////////////////////////
	transfereArrayToArray(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x20;
	frameTxDwin[5] = 0x02;
	frameTxDwin[6] = 0;
	if(tempPosicaoPontoDwin == 3){frameTxDwin[7] = '.';}
	else{frameTxDwin[7] = ' ';}
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,50);
}
//////////////////////////////////////////////////////////////////////////
// função que retira o ponto decimal				        			//
//////////////////////////////////////////////////////////////////////////
void retiraPontoDecimalDwin(void)
{
	loopRetiraPontoDwin = 6;
	indexRetiraPontoDwin = 5 - tempPosicaoPontoDwin;
	while(loopRetiraPontoDwin != 0)
	{
		tempTelaDwin = telaPesoDwin[indexRetiraPontoDwin];
		indexRetiraPontoDwin++;
		telaPesoDwin[indexRetiraPontoDwin] = tempTelaDwin;
		indexRetiraPontoDwin = indexRetiraPontoDwin -2;
		loopRetiraPontoDwin--;
	}
	telaPesoDwin[0]= ' ';
}

void removeCaracteresEspeciaisDwin (uint8_t posicaoInicial, uint8_t qtdCaracteres) {
	uint8_t i = 0;

	for (i = posicaoInicial; i < qtdCaracteres; i++) {
		if ((frameTxDwin[i] == caracterRetorna) || (frameTxDwin[i] == caracterSalva)
				|| (frameTxDwin[i] == caracterIncremento) || (frameTxDwin[i] == caracterAtivo)
				|| (frameTxDwin[i] == caracterSetaParaBaixo) || (frameTxDwin[i] == caractersetaParaCima)
				|| (frameTxDwin[i] == caractersetaDupla) || (frameTxDwin[i] == caracterDecremento)) {
			frameTxDwin[i] = ' ';
		}
	}
}

void transfereCaracterLcdLinha1Dwin(void)
{
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x12;
	frameTxDwin[5] = 0x00;
	transfereArrayToArray(16,&caracterLcd[0],&frameTxDwin[6]);

	removeCaracteresEspeciaisDwin(6,16);

	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}

void transfereCaracterLcdLinha2Dwin(void)
{
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x13;
	frameTxDwin[5] = 0x00;
	transfereArrayToArray(16,&caracterLcd[16],&frameTxDwin[6]);

	removeCaracteresEspeciaisDwin(6,16);

	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}
void transfereCaracterLcdMenu1Dwin(void)
{
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x14;
	frameTxDwin[5] = 0x00;
	transfereArrayToArray(16,&caracterLcd[0],&frameTxDwin[6]);

	removeCaracteresEspeciaisDwin(6,16);

	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}

void transfereCaracterLcdMenu2Dwin(void)
{

	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x15;
	frameTxDwin[5] = 0x00;
	transfereArrayToArray(16,&caracterLcd[16],&frameTxDwin[6]);
	
	removeCaracteresEspeciaisDwin(6,16);

	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}
void limpaLinha1Dwin(void)
{
	carregaArrayComEspacoAscii(50,&frameTxDwin[0]);
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x12;
	frameTxDwin[5] = 0x00;
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}
void limpaLinha2Dwin(void)
{
	carregaArrayComEspacoAscii(50,&frameTxDwin[0]);
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x13;
	frameTxDwin[5] = 0x00;
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}
void transfereCaracterDwinLinha1Aplicacao(void)
{
	carregaArrayComEspacoAscii(50,&frameTxDwin[0]);
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x12;
	frameTxDwin[5] = 0x00;
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}
void transfereCaracterDwinLinha2Aplicacao(void)
{
	carregaArrayComEspacoAscii(50,&frameTxDwin[0]);
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x13;
	frameTxDwin[5] = 0x00;
	transfereArrayToArray(7,&caracterLcd[9],&frameTxDwin[14]);
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}
void transfereCaracterDwinTelaInicial(void)
{
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x18;
	frameTxDwin[5] = 0x00;
	transfereConstToArray(&telaInicialVersao[0],&frameTxDwin[6]);
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}

void mostraModeloIndicadorDwin (void) {
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x12;
	frameTxDwin[5] = 0x00;
	transfereConstToArrayLoop(16,&telaInicialIndicador[0],&frameTxDwin[6]);	
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}

void mostraNomeTelaIndicadorDwin (void) {
	transfereConstToArrayLoop(4,&tx16BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x12;
	frameTxDwin[5] = 0x00;
	transfereConstToArrayLoop(16,&nomeTelaIndicadorMem[0],&frameTxDwin[6]);	
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],22,50);
}

void backLightDwinMaximo(void)
{
	transfereConstToArrayLoop(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x00;
	frameTxDwin[5] = 0x82;
	frameTxDwin[6] = 0x64;
	frameTxDwin[7] = 0x64;// bacht light 100%
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,10);
}
void backLightDwinMinimo(void)
{
	transfereConstToArrayLoop(4,&tx5BytesDwin[0],&frameTxDwin[0]);
	frameTxDwin[4] = 0x00;
	frameTxDwin[5] = 0x82;
	frameTxDwin[6] = 0x0A;
	frameTxDwin[7] = 0x0A;// bacht light 30%
	HAL_UART_Transmit(&huart3,&frameTxDwin[0],8,10);
}
/*
void transfereCaracterDwinLinhasCorrente(void)
{
	carregaArrayComEspacoAscii(32, &tempFrameDwin[0]);

	f = busvoltage;
	buf = ftoa();
	while(loopConverteCorrente< 5)
	    {
			tempArrayCorrente[loopConverteCorrente] = *buf;
	        buf++;
	        loopConverteCorrente++;
	    }
	loopConverteCorrente = 0;
	transfereArrayToArray(5,&tempArrayCorrente[0],&frameDwin0x5100[0]);
	writeVariableDWIN(19,0x1200,&frameDwin0x5100[0]);
	carregaArrayComEspacoAscii(32, &tempArrayCorrente[0]);

	f = current_mA;
	buf = ftoa();
	while(loopConverteCorrente< 5)
	    {
			tempArrayCorrente[loopConverteCorrente] = *buf;
	        buf++;
	        loopConverteCorrente++;	    }
	loopConverteCorrente = 0;
	transfereArrayToArray(5,&tempArrayCorrente[0],&frameDwin0x5100[0]);
	writeVariableDWIN(19,0x1300,&frameDwin0x5100[0]);
	carregaArrayComEspacoAscii(32, &tempArrayCorrente[0]);

}*/
