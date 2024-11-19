#include "transfereArrayToArray.h"
#include "converteArrayAsciiParaDecimal.h"
#include "inteiroTo2BytesAscii.h"
#include "carregaArrayComZeroAscii.h"
#include "zeroAsciiEsquerdaToVazioAscii.h"
#include "comparaValoresArray.h"
//#define _senhaInicial
//////////////////////////////////////////////////////////////////////////////////		
//Funcoes de calibracao do indicador de peso                                    //
//////////////////////////////////////////////////////////////////////////////////
void controleCalibraIndicador(void)
{
	switch (menuCalibraIndicador)
	{
	//////////////////////////////////////////////////////////////////////////////////
	//Verifica se esta sendo digitado uma senha valida para acesso                  //
	//////////////////////////////////////////////////////////////////////////////////
	case menuVerificaSenhaCalibracao:

		verificaSenhaAcessoCalibracao();

		if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&telaMostraSenhaLcdPT[0],&caracterLcd[0]);}
		if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&telaMostraSenhaLcdING[0],&caracterLcd[0]);}
		if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&telaMostraSenhaLcdESP[0],&caracterLcd[0]);}
		caracterLcd[16]= senhaTemp[0];
		caracterLcd[17]= senhaTemp[1];
		caracterLcd[18]= senhaTemp[2];
		caracterLcd[19]= senhaTemp[3];
		//retorna ao menu anterior
		if (teclaPressionadaAtual == teclaZeroRetorna)
		{
			teclaPressionadaAtual = teclaSolta;
			menuCalibraIndicador = menuCalibraIndicadorEmEspera;
			telaAcessaMenuFazCalibracao();
		}
		//tecla Seta acima
		if (teclaPressionadaAtual == teclaSalva)
		{
			teclaPressionadaAtual = teclaSolta;
			senhaValidada = 0;
			transfereConstToArray(&senhaTecnica[0],&arrayTempIndicador[2]);
			transfereArrayToArray(4,&senhaTemp[0],&arrayTemp1Indicador[2]);
			tempProgIndicador = comparaValoresArray(4,&arrayTempIndicador[2],&arrayTemp1Indicador[2]);
			if (tempProgIndicador == 0)
			{
				controleTara = _TARADESATIVADA;
				tempProgIndicador = valorFiltroDigitalMem;
				telaValorFiltroDigitalIndicador();
				senhaValidada = 1;
			}
			if (senhaValidada == 0)
			{
				transfereConstToArray(&senhaProgDivisao[0],&arrayTempIndicador[2]);
				transfereArrayToArray(4,&senhaTemp[0],&arrayTemp1Indicador[2]);
				tempProgIndicador = comparaValoresArray(4,&arrayTempIndicador[2],&arrayTemp1Indicador[2]);

				if (tempProgIndicador == 0)
				{
					menuCalibraIndicador = menuAjustaValorDivisao;
					//                        buf = ftoa(valorDivisaoIndicador,status);
					loopConverteDivisaoInterna = 0;
					carregaArrayComEspacoAscii(10,&valorAtualDivisaoInterna[0]);
					while (loopConverteDivisaoInterna < 9)
					{
						valorAtualDivisaoInterna[loopConverteDivisaoInterna] = *buf;
						buf++;
						loopConverteDivisaoInterna++;
					}
					rotacionaArrayTelaValorDivisao();
					carregaArrayComEspacoAscii(10,&arrayTempProgDivisao[0]);
					arrayTempProgDivisao[9] = '0';
					loopProgDivisaoIntena = 0;
					telaMostraValorProDivisaoInterna();
					menuCalibraIndicador = menuAjustaValorDivisao;
					senhaValidada = 1;
				}
				if (senhaValidada == 0)
				{
					telaErroSenhaTecnica();
					apagaSenha();
					flagPiscaDigitoSenha = 1;
					digitoAtualProgramacao = programandoDigitoTres;
				}
			}
		}
		break;
		/////////////////////////////////////////////////////////////////////////////////
		//Define o ajuste para divisao interna                                          //
		//////////////////////////////////////////////////////////////////////////////////
	case menuAjustaValorDivisao:
		//tecla incremento
		switch (teclaPressionadaAtual)
		{
		//retorna ao menu anterior
		case teclaZeroRetorna:
			teclaPressionadaAtual = teclaSolta;
			menuCalibraIndicador = menuCalibraIndicadorEmEspera;
			telaAcessaMenuFazCalibracao();
			break;
			//tecla Seta acima
		case teclaImprimeSetaAcima:
			if (arrayTempProgDivisao[9] !=  '.'){arrayTempProgDivisao[9]++;}
			if (arrayTempProgDivisao[9] == '.'){arrayTempProgDivisao[9] = '0';}
			else if (arrayTempProgDivisao[9] > '9'){arrayTempProgDivisao[9] = '.';}
			else if (arrayTempProgDivisao[9] < '.'){arrayTempProgDivisao[9] = '0';}
			telaMostraValorProDivisaoInterna();
			break;
			//tecla seta esquerda
		case teclaTaraSetaEsquerda:
			if (loopProgDivisaoIntena < 8)
			{
				loopProgDivisaoIntena++;
				arrayTempProgDivisao[0] = arrayTempProgDivisao[1];
				arrayTempProgDivisao[1] = arrayTempProgDivisao[2];
				arrayTempProgDivisao[2] = arrayTempProgDivisao[3];
				arrayTempProgDivisao[3] = arrayTempProgDivisao[4];
				arrayTempProgDivisao[4] = arrayTempProgDivisao[5];
				arrayTempProgDivisao[5] = arrayTempProgDivisao[6];
				arrayTempProgDivisao[6] = arrayTempProgDivisao[7];
				arrayTempProgDivisao[7] = arrayTempProgDivisao[8];
				arrayTempProgDivisao[8] = arrayTempProgDivisao[9];
				arrayTempProgDivisao[9] = '0';
			}
			else
			{
				loopProgDivisaoIntena = 0;
				carregaArrayComEspacoAscii(10,&arrayTempProgDivisao[0]);
				arrayTempProgDivisao[9] = '0';
			}
			telaMostraValorProDivisaoInterna();
			break;
			//tecla Ok
		case teclaSalva:
			teclaPressionadaAtual = teclaSolta;
			transfereArrayToArray(10,&arrayTempProgDivisao[0],&arrayInteiroTemp[0]);
			rotacionaArrayInsere0Converte();
			tempFloatCalculaDivisao = atof(arrayInteiroTemp);
			if (tempFloatCalculaDivisao > 10)
			{
				valorDivisaoIndicador = tempFloatCalculaDivisao;
				valorDivisaoIndicadorMem.float32 = valorDivisaoIndicador;
				salvaValorDivisaoIndicadorMem();
				menuCalibraIndicador = menuCalibraIndicadorEmEspera;
			}
			else
			{
				transfereArrayToArray(32,&caracterLcd[0],&backupTelaLcd[0]);
				if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charErroPesoCalibracaoPT[0],&caracterLcd[0]);}
				if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charErroPesoCalibracaoING[0],&caracterLcd[0]);}
				if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charErroPesoCalibracaoESP[0],&caracterLcd[0]);}
				transfereCaracterLcdMenu1Dwin();
				transfereCaracterLcdMenu2Dwin();
				mostraTelaTemporariaLcd = 1;
				tempoMostraTelaTemporariaLcd = 0;
			}
			break;
		}
		break;
	//////////////////////////////////////////////////////////////////////////////////
	//define o valor do filtro digital                                              //
	//////////////////////////////////////////////////////////////////////////////////
	case menuFiltroDigital:
		//tecla incremento
		switch (teclaPressionadaAtual)
		{
		//retorna a tela anterior
		case  teclaZeroRetorna:
			menuCalibraIndicador = menuCalibraIndicadorEmEspera;
			teclaPressionadaAtual = teclaSolta;
			flagInibeTeclaSolta = 1;
			flagPiscaProgIndicador = 0;
			flagFazMediaAd = 0;
			flagFimCalibracao = 0;
			operacaoComTeclado = 0;
			telaAcessaMenuFazCalibracao();
			break;
			//tecla Seta acima
		case teclaTaraSetaEsquerda:
			teclaPressionadaAtual = teclaSolta;
			tempProgIndicador = 0;
			telaValorFiltroDigitalIndicador();
			break;
		case teclaImprimeSetaAcima:
			teclaPressionadaAtual = teclaSolta;
			tempProgIndicador++;
			if (tempProgIndicador >= _VMAX_FILTRO_DIGITALI01){tempProgIndicador = 0;}                      
			telaValorFiltroDigitalIndicador();
			break;
//tecla Ok
			case teclaSalva:
				teclaPressionadaAtual = teclaSolta;
				valorFiltroDigitalMem = tempProgIndicador;
				salvaValorFiltroDigitalMem();
				tempProgIndicador = posicaoPontoDecimalIndicadorMem;
				telaPosicaoPontoDecimalIndicador();
				break;
			}
			break;
	//////////////////////////////////////////////////////////////////////////////////
	//define a posicao do ponto decimal                                             //
	//////////////////////////////////////////////////////////////////////////////////
	case menuDefinePontoDecimal:
		//tecla incremento
		switch (teclaPressionadaAtual )
		{
		//retorna a tela anterior
		case  teclaZeroRetorna:
			teclaPressionadaAtual = teclaSolta;
			tempProgIndicador = valorFiltroDigitalMem;
			telaValorFiltroDigitalIndicador();
			break;
		case teclaTaraSetaEsquerda:
			teclaPressionadaAtual = teclaSolta;
			tempProgIndicador = 0;
			telaPosicaoPontoDecimalIndicador();
			break;
			//tecla Seta acima
		case teclaImprimeSetaAcima:
			teclaPressionadaAtual = teclaSolta;
			if (++tempProgIndicador > 3){tempProgIndicador = 0;};
			telaPosicaoPontoDecimalIndicador();
			break;
			//tecla Ok
		case teclaSalva:
			teclaPressionadaAtual = teclaSolta;
			posicaoPontoDecimalIndicadorMem = tempProgIndicador;

			salvaPosicaoPontoDecimalIndicadorMem();

			tempProgIndicador = degrauIndicadorMem;
			telaDefineDegrauPesoIndicador();
			break;
		}
			break;
	//////////////////////////////////////////////////////////////////////////////////
	//define o degrau do peso 1, 2, 5, 10, 20                                       //
	//////////////////////////////////////////////////////////////////////////////////
	case menuDefineDegrauPeso:
		//tecla incremento
		switch (teclaPressionadaAtual )
		{
		case teclaTaraSetaEsquerda:
			teclaPressionadaAtual = teclaSolta;
			tempProgIndicador = 1;
			telaControlaIncrementodegrauIndicador();
			break;
			//retorna ao menu anterior
		case teclaZeroRetorna:
			teclaPressionadaAtual = teclaSolta;
			tempProgIndicador = posicaoPontoDecimalIndicadorMem;
			telaPosicaoPontoDecimalIndicador();
			break;
			//tecla Seta acima
		case teclaImprimeSetaAcima:
			teclaPressionadaAtual = teclaSolta;
			if (tempProgIndicador == 1){tempProgIndicador = 2;}
			else if (tempProgIndicador == 2){tempProgIndicador = 5;}
			else if (tempProgIndicador == 5){tempProgIndicador = 10;}
#ifdef indicadorCargaViva   
else if (tempProgIndicador == 10){tempProgIndicador = 1;}
else{tempProgIndicador = 1;}
#endif
#ifndef indicadorCargaViva   
			else if (tempProgIndicador == 10){tempProgIndicador = 20;}
			else if (tempProgIndicador == 20){tempProgIndicador = 1;}
			else{tempProgIndicador = 1;}
#endif                          
			telaControlaIncrementodegrauIndicador();
			break;
			//tecla Ok
		case teclaSalva:
			teclaPressionadaAtual = teclaSolta;
			degrauIndicadorMem = tempProgIndicador;
			salvaPosicaoDegrauIndicadorMem();
			telaPesoCargaMaximaIndicador();
			break;
		}
		break;
	/////////////////////////////////////////////////////////////////////////////////
	//Define a capacidade maxima de peso para o indicador                           //
	//////////////////////////////////////////////////////////////////////////////////
	case menuCapacidadeMaxima:
		//tecla incremento
		switch (teclaPressionadaAtual )
		{
		//retorna ao menu anterior
		case teclaZeroRetorna:
			teclaPressionadaAtual = teclaSolta;
			tempProgIndicador = degrauIndicadorMem;
			telaDefineDegrauPesoIndicador();
			break;
			//tecla Seta acima
		case teclaImprimeSetaAcima:
			manipulacaoDoDigitoDoIndicador();
			break;
			//tecla seta esquerda
		case teclaTaraSetaEsquerda:
			manipulacaoDoDigitoDoIndicador();

			break;
			//tecla Ok
		case teclaSalva:
			teclaPressionadaAtual = teclaSolta;
			carregaArrayComZeroAscii(8,&capacidadeMaximaIndicadorMem[0]);
			transfereArrayToArray(6,&arrayTempIndicador[0],&capacidadeMaximaIndicadorMem[2]);
			carregaArrayComZeroAscii(10,&arrayInteiroTemp[0]);
			transfereArrayToArray(8,&capacidadeMaximaIndicadorMem[0],&arrayInteiroTemp[2]);
			rotacionaArrayInsere0Converte();
			valorPesoCargaMaxima = atol(arrayInteiroTemp);

			salvaPesoCapacidadeMaxIndicadorMem();

			telaPesoCalibracaoIndicador();
			break;
		}
		break;
	//////////////////////////////////////////////////////////////////////////////////
	//Define o peso de calibracao                                                   //
	//////////////////////////////////////////////////////////////////////////////////
	case menuPesoCalibracao:
		//tecla incremento
		switch (teclaPressionadaAtual )
		{
		//retorna ao menu anterior
		case teclaZeroRetorna:
			telaPesoCargaMaximaIndicador();
			break;
			//tecla Seta acima
		case teclaImprimeSetaAcima:
			manipulacaoDoDigitoDoIndicador();
			break;
			//tecla seta esquerda
		case teclaTaraSetaEsquerda:
			manipulacaoDoDigitoDoIndicador();
			break;
			//tecla Ok
		case teclaSalva:
			teclaPressionadaAtual = teclaSolta;
			transfereArrayToArray(6,&capacidadeMaximaIndicadorMem[2],&arrayTemp1Indicador[0]);
			transfereArrayToArray(6,&arrayTempIndicador[0],&arrayTemp2Indicador[0]);

			converteArrayAsciiParaDecimal(6,&arrayTemp1Indicador[0]);
			converteArrayAsciiParaDecimal(6,&arrayTemp2Indicador[0]);

			tempProgIndicador = comparaValoresArray(6,&arrayTemp1Indicador[0],&arrayTemp2Indicador[0]);
			if (tempProgIndicador != 2) // pode ser maior ou igual
			{
				carregaArrayComZeroAscii(8,&pesoCalibracaoIndicadorMem[0]);
				carregaArrayComZeroAscii(10,&arrayInteiroTemp[0]);
				transfereArrayToArray(6,&arrayTempIndicador[0],&pesoCalibracaoIndicadorMem[2]);
				transfereArrayToArray(8,&pesoCalibracaoIndicadorMem[0],&arrayInteiroTemp[2]);
				rotacionaArrayInsere0Converte();

				salvaPesoCalibracaoIndicadorMem();

				telaPesoZeroIndicador();
			}
			else
			{
				telaErroCapacidadeMaxima();
				flagPiscaProgIndicador = 1;
				digitoAtualIndicador = digitoZero;
			}
			break;
		}
		break;
	//////////////////////////////////////////////////////////////////////////////////
	//faz a leitura da celula sem peso (zero)                                       //
	//////////////////////////////////////////////////////////////////////////////////
	case menuSemPeso:
		//tecla incremento
		if (flagFazMediaAd == 0)//nao permite a entrada durante a leitura do peso
		{
			switch (teclaPressionadaAtual)
			{
			//retorna ao menu anterior
			case teclaZeroRetorna:
				teclaPressionadaAtual = teclaSolta;
				telaPesoCalibracaoIndicador();
				break;
				//tecla seta esquerda
			case teclaTaraSetaEsquerda:
				teclaPressionadaAtual = teclaSolta;
				tempAd = 0;
				flagFazMediaAd = 1;
				loopMediaCalibracao = 0;
				operacaoComTeclado = 1;
				if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charAguardePT[0],&caracterLcd[16]);}
				if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charAguardeING[0],&caracterLcd[16]);}
				if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charAguardeESP[0],&caracterLcd[16]);}
				break;
				//tecla Ok
			case teclaSalva:
				teclaPressionadaAtual = teclaSolta;
				menuCalibraIndicador = menuComPeso;
				if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charComPesoIndicadorPT[0],&caracterLcd[0]);}
				if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charComPesoIndicadorING[0],&caracterLcd[0]);}
				if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charComPesoIndicadorESP[0],&caracterLcd[0]);}
				caracterLcd[29] = caracterRetorna;
				caracterLcd[30] = '<';
				caracterLcd[31] = caracterSalva;

				break;
			}
			break;
		}
		//////////////////////////////////////////////////////////////////////////////////
		//faz a leitura da celula do valor equivalente ao peso de calibracao            //
		//////////////////////////////////////////////////////////////////////////////////
	case menuComPeso:
		//tecla incremento
		if (flagFazMediaAd == 0)//nao permite a entrada durante a leitura do peso
		{
			switch (teclaPressionadaAtual)
			{
			//retorna ao menu anterior
			case teclaZeroRetorna:
				teclaPressionadaAtual = teclaSolta;
				telaPesoZeroIndicador();
				break;
				//tecla Seta acima
			case teclaTaraSetaEsquerda:
				teclaPressionadaAtual = teclaSolta;
				tempAd = 0;
				flagFazMediaAd = 1;
				loopMediaCalibracao = 0;
				operacaoComTeclado = 1;
				if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charAguardePT[0],&caracterLcd[16]);}
				if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charAguardeING[0],&caracterLcd[16]);}
				if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charAguardeESP[0],&caracterLcd[16]);}
				break;
				//tecla Ok
			case teclaSalva:
				teclaPressionadaAtual = teclaSolta;
				flagFimCalibracao = 0;
				flagFazMediaAd = 0;
				menuCalibraIndicador = menuCalibraIndicadorEmEspera;
				break;
			}
		}
		break;
	}
}

//////////////////////////////////////////////////////////////////////////////////
/*tela de checagem da senha de acesso a calibracao                              */
//////////////////////////////////////////////////////////////////////////////////
void telaSenhaDeAcessoCalibracao(void)
{
	menuCalibraIndicador = menuVerificaSenhaCalibracao;


	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&telaVerificaSenhaLcdPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&telaVerificaSenhaLcdING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&telaVerificaSenhaLcdESP[0],&caracterLcd[0]);}
	menuAcessaMenusProgramacao = menuAcessaMenusProgramacaoEmEspera;

	caracterLcd[29] = '<';
	caracterLcd[30] = caracterIncremento;
	caracterLcd[31] = caracterSalva;

	flagPiscaDigitoSenha = 1;
	digitoAtualProgramacao = programandoDigitoTres;
	apagaSenha();
}
//////////////////////////////////////////////////////////////////////////////////
/*tela que mostra a programacao do filtro digital                               */
//////////////////////////////////////////////////////////////////////////////////
void telaValorFiltroDigitalIndicador(void)
{
	menuCalibraIndicador = menuFiltroDigital;
	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charValorFiltroDigitalPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charValorFiltroDigitalING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charValorFiltroDigitalESP[0],&caracterLcd[0]);}
	if (tempProgIndicador < 10){caracterLcd[16] = tempProgIndicador + '0';}
	else if (tempProgIndicador < 100){inteiroTo2BytesAscii(tempProgIndicador,&caracterLcd[16]);}
	else{inteiroTo3BytesAscii(tempProgIndicador,&caracterLcd[16]);}

	caracterLcd[30] = caracterIncremento;
	caracterLcd[31] = caracterSalva;

}
//////////////////////////////////////////////////////////////////////////////////
/*tela de programacao da posicao doponto decimal                                */
//////////////////////////////////////////////////////////////////////////////////
void telaPosicaoPontoDecimalIndicador(void)
{
	menuCalibraIndicador = menuDefinePontoDecimal;
	
	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charPosicaoPontoDecimalPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charPosicaoPontoDecimalING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charPosicaoPontoDecimalESP[0],&caracterLcd[0]);}

	if (tempProgIndicador == _SEM_PONTO){transfereConstToArray(&charSemPonto[0],&caracterLcd[16]);}
	if (tempProgIndicador == _CEMGRAMAS){transfereConstToArray(&charCemGramasPonto[0],&caracterLcd[16]);}
	if (tempProgIndicador == _DEZGRAMAS){transfereConstToArray(&charDezGramasPonto[0],&caracterLcd[16]);}
	if (tempProgIndicador == _UMGRAMA){transfereConstToArray(&charUmaGramasPonto[0],&caracterLcd[16]);}
	if (tempProgIndicador == _DECIGRAMA){transfereConstToArray(&charUmDecigramaPonto[0],&caracterLcd[16]);}

	caracterLcd[29] = caracterRetorna;
	caracterLcd[30] = caracterIncremento;
	caracterLcd[31] = caracterSalva;

}
//////////////////////////////////////////////////////////////////////////////////		
//carrega a tela programacao do degrau do indicador 1,2,5,10 e 20            	//
//////////////////////////////////////////////////////////////////////////////////
void telaDefineDegrauPesoIndicador(void)
{ 
	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charDegrauPesoIndicadorPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charDegrauPesoIndicadorING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charDegrauPesoIndicadorESP[0],&caracterLcd[0]);}

	menuCalibraIndicador = menuDefineDegrauPeso;
	telaControlaIncrementodegrauIndicador();

	caracterLcd[29] = caracterRetorna;
	caracterLcd[30] = caracterIncremento;
	caracterLcd[31] = caracterSalva;

}
//////////////////////////////////////////////////////////////////////////////////
//tela que mostra a programacao da carga maxima do indicador                    //
//////////////////////////////////////////////////////////////////////////////////
void telaPesoCargaMaximaIndicador(void)
{
	flagPiscaProgIndicador = 1;
	digitoAtualIndicador = digitoZero;
	menuCalibraIndicador = menuCapacidadeMaxima;

	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charCapacidadeMaxIndicadorPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charCapacidadeMaxIndicadorING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charCapacidadeMaxIndicadorESP[0],&caracterLcd[0]);}

	transfereArrayToArray(6,&capacidadeMaximaIndicadorMem[2],&arrayTempIndicador[0]);

	caracterLcd[28] = caracterRetorna;
	caracterLcd[29] = caracterIncremento;
	caracterLcd[30] = '<';
	caracterLcd[31] = caracterSalva;

}
//////////////////////////////////////////////////////////////////////////////////
//tela que mostra a programacao do peso de calibracao do indicador              //
//////////////////////////////////////////////////////////////////////////////////
void telaPesoCalibracaoIndicador(void)
{
	flagPiscaProgIndicador = 1;
	digitoAtualIndicador = digitoZero;
	menuCalibraIndicador = menuPesoCalibracao;

	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charPesoCalibracaoIndicadorPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charPesoCalibracaoIndicadorING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charPesoCalibracaoIndicadorESP[0],&caracterLcd[0]);}
	
	transfereArrayToArray(6,&pesoCalibracaoIndicadorMem[2],&arrayTempIndicador[0]);

	caracterLcd[28] = caracterRetorna;
	caracterLcd[29] = caracterIncremento;
	caracterLcd[30] = '<';
	caracterLcd[31] = caracterSalva;
}
//////////////////////////////////////////////////////////////////////////////////
//tela que faz a leitura da indicaodr sem peso (zero)                           //
//////////////////////////////////////////////////////////////////////////////////
void telaPesoZeroIndicador(void)
{
	menuCalibraIndicador = menuSemPeso;

	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charSemPesoIndicadorPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charSemPesoIndicadorING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charSemPesoIndicadorESP[0],&caracterLcd[0]);}

	caracterLcd[29] = caracterRetorna;
	caracterLcd[30] = '<';
	caracterLcd[31] = caracterSalva;
}
//////////////////////////////////////////////////////////////////////////////////
//tela que controla a programacao do valor do degrau do indicador              //
//////////////////////////////////////////////////////////////////////////////////
void telaControlaIncrementodegrauIndicador(void)
{
	if (tempProgIndicador == 10 || tempProgIndicador == 20){inteiroTo2BytesAscii(tempProgIndicador,&caracterLcd[16]);}
	else
	{
		caracterLcd[17] = ' ';
		caracterLcd[16] = tempProgIndicador + '0';
	}
}
//////////////////////////////////////////////////////////////////////////////////
//metodo que controla a intermitencia de piscagem do digito prog indicador      //
//////////////////////////////////////////////////////////////////////////////////
void metodoPiscaProgIndicador(void)
{
	if (++tempoPiscaProgIndicador > 3)
	{
		tempoPiscaProgIndicador  = 0;
		if (flagTempoPiscaProgIndicador == 1){flagTempoPiscaProgIndicador = 0;}
		else{flagTempoPiscaProgIndicador = 1;}
	}
	if (mostraTelaTemporariaLcd == 0)
	{
		if (menuCalibraIndicador == menuCapacidadeMaxima){piscaDigitoProgIndicador();}
		if (menuCalibraIndicador == menuPesoCalibracao){piscaDigitoProgIndicador();}
	}
}
//////////////////////////////////////////////////////////////////////////////////		
//metodo que controla qual digito vai piscar durante a programacao do indicador //
//////////////////////////////////////////////////////////////////////////////////

void piscaDigitoProgIndicador(void)
{
	if (posicaoPontoDecimalIndicadorMem == 0)
	{
		caracterLcd[16]= arrayTempIndicador[0];
		caracterLcd[17]= arrayTempIndicador[1];
		caracterLcd[18]= arrayTempIndicador[2];
		caracterLcd[19]= arrayTempIndicador[3];
		caracterLcd[20]= arrayTempIndicador[4];
		caracterLcd[21]= arrayTempIndicador[5];
	}
	if (posicaoPontoDecimalIndicadorMem == 1)
	{
		caracterLcd[16]= arrayTempIndicador[0];
		caracterLcd[17]= arrayTempIndicador[1];
		caracterLcd[18]= arrayTempIndicador[2];
		caracterLcd[19]= arrayTempIndicador[3];
		caracterLcd[20]= arrayTempIndicador[4];
		caracterLcd[21] = '.';
		caracterLcd[22]= arrayTempIndicador[5];
	}
	if (posicaoPontoDecimalIndicadorMem == 2)
	{
		caracterLcd[16]= arrayTempIndicador[0];
		caracterLcd[17]= arrayTempIndicador[1];
		caracterLcd[18]= arrayTempIndicador[2];
		caracterLcd[19]= arrayTempIndicador[3];
		caracterLcd[20] = '.';
		caracterLcd[21]= arrayTempIndicador[4];
		caracterLcd[22]= arrayTempIndicador[5];
	}
	if (posicaoPontoDecimalIndicadorMem == 3)
	{
		caracterLcd[16]= arrayTempIndicador[0];
		caracterLcd[17]= arrayTempIndicador[1];
		caracterLcd[18]= arrayTempIndicador[2];
		caracterLcd[19] = '.';
		caracterLcd[20]= arrayTempIndicador[3];
		caracterLcd[21]= arrayTempIndicador[4];
		caracterLcd[22]= arrayTempIndicador[5];
	}
	if (posicaoPontoDecimalIndicadorMem == 4)
	{
		caracterLcd[16]= arrayTempIndicador[0];
		caracterLcd[17]= arrayTempIndicador[1];
		caracterLcd[18] = '.';
		caracterLcd[19]= arrayTempIndicador[2];
		caracterLcd[20]= arrayTempIndicador[3];
		caracterLcd[21]= arrayTempIndicador[4];
		caracterLcd[22]= arrayTempIndicador[5];
	}
	if (flagPiscaProgIndicador == 1 & flagTempoPiscaProgIndicador == 1)
	{
		if (posicaoPontoDecimalIndicadorMem == 0)
		{
			if (digitoAtualIndicador == digitoZero){caracterLcd[21] = ' ';}
			if (digitoAtualIndicador == digitoUm){caracterLcd[20] = ' ';}
			if (digitoAtualIndicador == digitoDois){caracterLcd[19] = ' ';}
			if (digitoAtualIndicador == digitoTres){caracterLcd[18] = ' ';}
			if (digitoAtualIndicador == digitoQuatro){caracterLcd[17] = ' ';}
			if (digitoAtualIndicador == digitoCinco){caracterLcd[16] = ' ';}
		}
		if (posicaoPontoDecimalIndicadorMem == 1)
		{
			if (digitoAtualIndicador == digitoZero){caracterLcd[22] = ' ';}
			if (digitoAtualIndicador == digitoUm){caracterLcd[20] = ' ';}
			if (digitoAtualIndicador == digitoDois){caracterLcd[19] = ' ';}
			if (digitoAtualIndicador == digitoTres){caracterLcd[18] = ' ';}
			if (digitoAtualIndicador == digitoQuatro){caracterLcd[17] = ' ';}
			if (digitoAtualIndicador == digitoCinco){caracterLcd[16] = ' ';}
		}
		if (posicaoPontoDecimalIndicadorMem == 2)
		{
			if (digitoAtualIndicador == digitoZero){caracterLcd[22] = ' ';}
			if (digitoAtualIndicador == digitoUm){caracterLcd[21] = ' ';}
			if (digitoAtualIndicador == digitoDois){caracterLcd[19] = ' ';}
			if (digitoAtualIndicador == digitoTres){caracterLcd[18] = ' ';}
			if (digitoAtualIndicador == digitoQuatro){caracterLcd[17] = ' ';}
			if (digitoAtualIndicador == digitoCinco){caracterLcd[16] = ' ';}
		}
		if (posicaoPontoDecimalIndicadorMem == 3)
		{
			if (digitoAtualIndicador == digitoZero){caracterLcd[22] = ' ';}
			if (digitoAtualIndicador == digitoUm){caracterLcd[21] = ' ';}
			if (digitoAtualIndicador == digitoDois){caracterLcd[20] = ' ';}
			if (digitoAtualIndicador == digitoTres){caracterLcd[18] = ' ';}
			if (digitoAtualIndicador == digitoQuatro){caracterLcd[17] = ' ';}
			if (digitoAtualIndicador == digitoCinco){caracterLcd[16] = ' ';}
		}
		if (posicaoPontoDecimalIndicadorMem == 4)
		{
			if (digitoAtualIndicador == digitoZero){caracterLcd[22] = ' ';}
			if (digitoAtualIndicador == digitoUm){caracterLcd[21] = ' ';}
			if (digitoAtualIndicador == digitoDois){caracterLcd[20] = ' ';}
			if (digitoAtualIndicador == digitoTres){caracterLcd[19] = ' ';}
			if (digitoAtualIndicador == digitoQuatro){caracterLcd[17] = ' ';}
			if (digitoAtualIndicador == digitoCinco){caracterLcd[16] = ' ';}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////
//                                                                              //
//Faz a programacao dos digitos do peso na programacao do indicador             //
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////       
void manipulacaoDoDigitoDoIndicador(void)       
{
	if (teclaPressionadaAtual == teclaImprimeSetaAcima)
	{
		flagPiscaProgIndicador = 0;
	}
	if (teclaPressionadaAtual == teclaTaraSetaEsquerda)
	{
		flagPiscaProgIndicador = 1;
	}
	switch (digitoAtualIndicador)
	{
	//////////////////////////////////////////////////////////////////////////////////
	//programacao do digito zero (digito menos siginificativo)                      //
	//////////////////////////////////////////////////////////////////////////////////
	case digitoZero:
		switch (teclaPressionadaAtual)
		{
		// tecla incrementa o valor do digito
		case teclaImprimeSetaAcima:
			if (++arrayTempIndicador[5] > '9'|| arrayTempIndicador[5] < '0'){arrayTempIndicador[5] = '0';}
			break;
			//Direciona programacao para digito a esquerda
		case teclaTaraSetaEsquerda:
			digitoAtualIndicador = digitoUm;
			break;
		}
		break;
		//////////////////////////////////////////////////////////////////////////////////
		//programacao do digito um                                                      //
		//////////////////////////////////////////////////////////////////////////////////
		case digitoUm:
			switch (teclaPressionadaAtual )
			{
			// tecla incrementa o valor do digito
			case teclaImprimeSetaAcima:
				if (++arrayTempIndicador[4] > '9'|| arrayTempIndicador[4] < '0'){arrayTempIndicador[4] = '0';}
				break;
				//Direciona programacao para digito a esquerda
			case teclaTaraSetaEsquerda:
				digitoAtualIndicador = digitoDois;
				break;
			}
			break;
			//////////////////////////////////////////////////////////////////////////////////
			//programacao do digito dois                                                    //
			//////////////////////////////////////////////////////////////////////////////////
			case digitoDois:
				switch (teclaPressionadaAtual )
				{
				// tecla incrementa o valor do digito
				case teclaImprimeSetaAcima:
					if (++arrayTempIndicador[3] > '9'|| arrayTempIndicador[3] < '0'){arrayTempIndicador[3] = '0';}
					break;
					//Direciona programacao para digito a esquerda
				case teclaTaraSetaEsquerda:
					digitoAtualIndicador = digitoTres;
					break;
				}
				break;
				//////////////////////////////////////////////////////////////////////////////////
				//programacao do digito tres                                                    //
				//////////////////////////////////////////////////////////////////////////////////
				case digitoTres:
					switch (teclaPressionadaAtual)
					{
					// tecla incrementa o valor do digito
					case teclaImprimeSetaAcima:
						if (++arrayTempIndicador[2] > '9'|| arrayTempIndicador[2] < '0'){arrayTempIndicador[2] = '0';}
						break;
						//Direciona programacao para digito a esquerda
					case teclaTaraSetaEsquerda:
						digitoAtualIndicador = digitoQuatro;
						break;
					}
					break;
					//////////////////////////////////////////////////////////////////////////////////
					//programacao do digito quatro                                                  //
					//////////////////////////////////////////////////////////////////////////////////
					case digitoQuatro:
						switch (teclaPressionadaAtual )
						{
						// tecla incrementa o valor do digito
						case teclaImprimeSetaAcima:
							if (++arrayTempIndicador[1] > '9'|| arrayTempIndicador[1] < '0'){arrayTempIndicador[1] = '0';}
							break;
							//Direciona programacao para digito a esquerda
						case teclaTaraSetaEsquerda:
							digitoAtualIndicador = digitoCinco;
							break;
						}
						break;
						//////////////////////////////////////////////////////////////////////////////////
						//programacao do digito cinco                                                   //
						//////////////////////////////////////////////////////////////////////////////////
						case digitoCinco:
							switch (teclaPressionadaAtual )
							{
							// tecla incrementa o valor do digito
							case teclaImprimeSetaAcima:
								if (++arrayTempIndicador[0] > '9'|| arrayTempIndicador[0] < '0'){arrayTempIndicador[0] = '0';}
								break;
								//Direciona programacao para digito a esquerda
							case teclaTaraSetaEsquerda:
								digitoAtualIndicador = digitoZero;
								break;
							}
							break;
	}
}
/*tela de erro do peso de calibracao                                            */
void telaErroPesoCalibracao (void)
{    
	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charComPesoIndicadorPT[0],&backupTelaLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charComPesoIndicadorING[0],&backupTelaLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charComPesoIndicadorESP[0],&backupTelaLcd[0]);}

	backupTelaLcd[28] = caracterRetorna;
	backupTelaLcd[29] = caracterIncremento;
	backupTelaLcd[30] = '<';
	backupTelaLcd[31] = caracterSalva;

	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charErroPesoCalibracaoPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charErroPesoCalibracaoING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charErroPesoCalibracaoESP[0],&caracterLcd[0]);}
	
	transfereCaracterLcdMenu1Dwin();
	transfereCaracterLcdMenu2Dwin();
	mostraTelaTemporariaLcd = 1;
	tempoMostraTelaTemporariaLcd = 1;

#ifdef displaySeteSegmentosLcd
	transfereArrayToArray(6,&dadoLcdSetSegmentos[0],&backupDigitosLcdSeteSegmentos[0]);
	dadoLcdSetSegmentos[1] = 'E';
	dadoLcdSetSegmentos[2] = 'R';
	dadoLcdSetSegmentos[3] = 'R';
	dadoLcdSetSegmentos[4] = 'O';
	dadoLcdSetSegmentos[5] = 'R';
	dadoLcdSetSegmentos[6] = '6';
#endif
}

/*tela de erro na capacidade maxima programada                                */
void telaErroCapacidadeMaxima (void)
{    
	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charPesoCalibracaoIndicadorPT[0],&backupTelaLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charPesoCalibracaoIndicadorING[0],&backupTelaLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charPesoCalibracaoIndicadorESP[0],&backupTelaLcd[0]);}

	backupTelaLcd[28] = caracterRetorna;
	backupTelaLcd[29] = caracterIncremento;
	backupTelaLcd[30] = '<';
	backupTelaLcd[31] = caracterSalva;

	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charErroPesoCargaMaximaPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charErroPesoCargaMaximaING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charErroPesoCargaMaximaESP[0],&caracterLcd[0]);}

	transfereCaracterLcdMenu1Dwin();
	transfereCaracterLcdMenu2Dwin();
	mostraTelaTemporariaLcd = 1;
	tempoMostraTelaTemporariaLcd = 1;
}
//////////////////////////////////////////////////////////////////////////////////		
//Metodo que define a senha usada para acesso a calibracao                      //
//                                                                              // 
//////////////////////////////////////////////////////////////////////////////////
void verificaSenhaAcessoCalibracao(void)
{
	switch (digitoAtualProgramacao)
	{
	//////////////////////////////////////////////////////////////////////////////////
	//programacao do digito zero (digito menos siginificativo)                      //
	//////////////////////////////////////////////////////////////////////////////////
	case programandoDigitoZero:
		switch (teclaPressionadaAtual)
		{
		// tecla incrementa o valor do digito
		case teclaImprimeSetaAcima:
			teclaPressionadaAtual = teclaSolta;
			flagPiscaDigitoSenha = 0;
			senhaTemp[3]++;
			if (senhaTemp[3] > '9'){senhaTemp[3] = '0';}
			break;
			//Direciona programacao para digito a esquerda
		case teclaTaraSetaEsquerda:
			teclaPressionadaAtual = teclaSolta;
			flagPiscaDigitoSenha = 1;
			digitoAtualProgramacao = programandoDigitoTres;
			break;
		default:
			break;
		}
		break;
	//////////////////////////////////////////////////////////////////////////////////
	//programacao do digito um                                                      //
	//////////////////////////////////////////////////////////////////////////////////
	case programandoDigitoUm:
		switch (teclaPressionadaAtual)
		{
		// tecla incrementa o valor do digito
		case teclaImprimeSetaAcima:
			teclaPressionadaAtual = teclaSolta;
			flagPiscaDigitoSenha = 0;
			senhaTemp[2]++;
			if (senhaTemp[2] > '9'){senhaTemp[2] = '0';}
			break;
			//Direciona programacao para digito a esquerda
		case teclaTaraSetaEsquerda:
			teclaPressionadaAtual = teclaSolta;
			flagPiscaDigitoSenha = 1;
			digitoAtualProgramacao = programandoDigitoZero;
			break;
		default:
			break;
		}
		break;
	//////////////////////////////////////////////////////////////////////////////////
	//programacao do digito dois                                                    //
	//////////////////////////////////////////////////////////////////////////////////
	case programandoDigitoDois:
		switch (teclaPressionadaAtual )
		{
		// tecla incrementa o valor do digito
		case teclaImprimeSetaAcima:
			teclaPressionadaAtual = teclaSolta;
			flagPiscaDigitoSenha = 0;
			senhaTemp[1]++;
			if (senhaTemp[1] > '9'){senhaTemp[1] = '0';}
			break;
		case teclaTaraSetaEsquerda:
			teclaPressionadaAtual = teclaSolta;
			flagPiscaDigitoSenha = 1;
			digitoAtualProgramacao = programandoDigitoUm;
			break;
		default:
			break;
		}
		break;
	//////////////////////////////////////////////////////////////////////////////////
	//programacao do digito tres                                                    //
	//////////////////////////////////////////////////////////////////////////////////
	case programandoDigitoTres:
		switch (teclaPressionadaAtual)
		{
		// tecla incrementa o valor do digito
		case teclaImprimeSetaAcima:
			teclaPressionadaAtual = teclaSolta;
			flagPiscaDigitoSenha = 0;
			senhaTemp[0]++;
			if (senhaTemp[0] > '9'){senhaTemp[0] = '0';}
			break;
			//Direciona programacao para digito a esquerda
		case teclaTaraSetaEsquerda:
			teclaPressionadaAtual = teclaSolta;
			flagPiscaDigitoSenha = 1;
			digitoAtualProgramacao = programandoDigitoDois;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}
//////////////////////////////////////////////////////////////////////////////////
//tela que mostra a programacao da divisao interna                              //
//////////////////////////////////////////////////////////////////////////////////
void telaMostraValorProDivisaoInterna(void)
{
	transfereConstToArray(&telaMenuProgValorDivisao[0],&caracterLcd[0]);
	transfereArrayToArray(10,&valorAtualDivisaoInterna[0],&caracterLcd[3]);
	transfereArrayToArray(10,&arrayTempProgDivisao[0],&caracterLcd[19]);

	caracterLcd[29] = caracterIncremento;
	caracterLcd[30] = '<';
	caracterLcd[31] = caracterSalva;

}
//////////////////////////////////////////////////////////////////////////////////		
//Tela que carrega a mensagem de erro peso fora do intervalo permitido          // 
//////////////////////////////////////////////////////////////////////////////////
void telaErroSenhaTecnica(void)
{
	transfereArrayToArray(32,&caracterLcd[0],&backupTelaLcd[0]);

	if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&telaSenhaInvalidaLcdPT[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&telaSenhaInvalidaLcdING[0],&caracterLcd[0]);}
	if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&telaSenhaInvalidaLcdESP[0],&caracterLcd[0]);}
	
	transfereCaracterLcdMenu1Dwin();
	transfereCaracterLcdMenu2Dwin();

	flagPiscaDigitoSenha = 1;
	mostraTelaTemporariaLcd = 1;
	tempoMostraTelaTemporariaLcd = 1;
} 
//////////////////////////////////////////////////////////////////////////////////		
//metodo que controla qual digito vai piscar quando definindo a senha         	//
//////////////////////////////////////////////////////////////////////////////////
void controlaPiscaDigitoProgSenha(void)
{ 

#ifdef _senhaInicial
	if (menuCalibraIndicador == menuVerificaSenhaCalibracao|| menuAcessaMenusProgramacao == verificaSenhaMenuAcessoProgramacao)
#endif       
#ifndef _senhaInicial
	if (menuCalibraIndicador == menuVerificaSenhaCalibracao)
#endif
	{
		if (++tempoPiscaSenha > 3)
		{
			tempoPiscaSenha = 0;
			if (flagTempoPiscaDigitoSenha == 1){flagTempoPiscaDigitoSenha = 0;}
			else{flagTempoPiscaDigitoSenha = 1;}


			caracterLcd[16]= senhaTemp[0];
			caracterLcd[17]= senhaTemp[1];
			caracterLcd[18]= senhaTemp[2];
			caracterLcd[19]= senhaTemp[3];
			if (flagPiscaDigitoSenha == 1 & flagTempoPiscaDigitoSenha == 1)
			{
				if (digitoAtualProgramacao == programandoDigitoZero){caracterLcd[19] = '_';}
				if (digitoAtualProgramacao == programandoDigitoUm){caracterLcd[18] = '_';}
				if (digitoAtualProgramacao == programandoDigitoDois){caracterLcd[17] = '_';}
				if (digitoAtualProgramacao == programandoDigitoTres){caracterLcd[16] = '_';}
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////		
//apaga a senha digitada                                                     	//
//////////////////////////////////////////////////////////////////////////////////
void apagaSenha(void)
{
	senhaTemp[0] ='0';
	senhaTemp[1] ='0';
	senhaTemp[2] ='0';
	senhaTemp[3] ='0';
}
//////////////////////////////////////////////////////////////////////////////////		
//rotaciona o valor da array com valor da divisao para mostrar na tela         	//
////////////////////////////////////////////////////////////////////////////////// 
void rotacionaArrayTelaValorDivisao(void)
{ 
	while (valorAtualDivisaoInterna[9] == ' ' || valorAtualDivisaoInterna[9] == '0')
	{
		valorAtualDivisaoInterna[9] = valorAtualDivisaoInterna[8];
		valorAtualDivisaoInterna[8] = valorAtualDivisaoInterna[7];
		valorAtualDivisaoInterna[7] = valorAtualDivisaoInterna[6];
		valorAtualDivisaoInterna[6] = valorAtualDivisaoInterna[5];
		valorAtualDivisaoInterna[5] = valorAtualDivisaoInterna[4];
		valorAtualDivisaoInterna[4] = valorAtualDivisaoInterna[3];
		valorAtualDivisaoInterna[3] = valorAtualDivisaoInterna[2];
		valorAtualDivisaoInterna[2] = valorAtualDivisaoInterna[1];
		valorAtualDivisaoInterna[1] = valorAtualDivisaoInterna[0];
		valorAtualDivisaoInterna[0] = ' ';
	}
	if (valorAtualDivisaoInterna[9] == '.')
	{
		valorAtualDivisaoInterna[0] = valorAtualDivisaoInterna[1];
		valorAtualDivisaoInterna[1] = valorAtualDivisaoInterna[2];
		valorAtualDivisaoInterna[2] = valorAtualDivisaoInterna[3];
		valorAtualDivisaoInterna[3] = valorAtualDivisaoInterna[4];
		valorAtualDivisaoInterna[4] = valorAtualDivisaoInterna[5];
		valorAtualDivisaoInterna[5] = valorAtualDivisaoInterna[6];
		valorAtualDivisaoInterna[6] = valorAtualDivisaoInterna[7];
		valorAtualDivisaoInterna[7] = valorAtualDivisaoInterna[8];
		valorAtualDivisaoInterna[8] = valorAtualDivisaoInterna[9];
		valorAtualDivisaoInterna[9] = '0';
	}
}








