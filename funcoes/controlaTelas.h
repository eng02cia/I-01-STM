#include "transfereArrayToArray.h"
#include "transfereConstToArray.h"
#include "inteiroTo2BytesAscii.h"
#include "inteiroTo3BytesAscii.h"
#include "pesoGramaDecimalToPesoKgAscii.h"
#include "carregaArrayComEspacoAscii.h"
#include "verificaValorArrayIgualEspacoAscii.h"
extern UART_HandleTypeDef huart3;
//////////////////////////////////////////////////////////////////////////////////
//Metodos responsaveis pelo controle das telas exibidas no display            	//
//////////////////////////////////////////////////////////////////////////////////
void metodoControleDasTelas(void)
{
	if ((exibeVersionControl == 0) && (mostraTelaTemporariaLcd == 0) && (sistemaInicializado == 1))
	{
		//Menu de programacao
		if (menuAcessaMenusProgramacao != menuAcessaMenusProgramacaoEmEspera
			|| menuCalibraIndicador != menuCalibraIndicadorEmEspera
			|| menuConfiguraSerial_1 != menuConfiguraSerial_1EmEspera
			|| menuModoTecnicoIndicador != menuModoTecnicoIndicadorEmEspera
			|| menuProgramacaoRelogioAtual != menuProgramaRelogioEmEspera
			|| menuProgramaDefinicaoFucionamento != menuDefinicaoFuncionamentoEmEspera)
		{
			if (trocarPaginaDwin == 1)
			{
				trocarPaginaDwin=0;
				carregaTela2();
			}
			transfereCaracterLcdMenu1Dwin();
			transfereCaracterLcdMenu2Dwin();
		}
		//Tela de status principal
		else
		{
			if (statusLigaDesliga == _LIGADO)
			{
				//cria a tela de status principal 1
				//caso sem recepcao de peso coloca tela e erro
				escreveDadoLcd(&telaStatusPrincipal[0],&caracterLcd[0]);
				
				if (trocarPaginaDwin == 0)
				{
					trocarPaginaDwin = 1;
					carregaTela1();				
				}

				if ((statusControleSobreCarga == 1) || (statusControleSubCarga == 1))
				{
					if (statusControleSobreCarga == 1){
						if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&telaSobreCargaPT[0],&caracterLcd[16]);}
						if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&telaSobreCargaING[0],&caracterLcd[16]);}
						if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&telaSobreCargaESP[0],&caracterLcd[16]);}
					}
					if (statusControleSubCarga == 1) {
						if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&telaSubCargaPT[0],&caracterLcd[16]);}
						if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&telaSubCargaING[0],&caracterLcd[16]);}
						if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&telaSubCargaESP[0],&caracterLcd[16]);}
					}

					controleTelaDwin = ocultaPeso;

					transfereCaracterLcdLinha1Dwin();
					transfereCaracterLcdLinha2Dwin();
				}
				else
				{
					if (exibeRelogioMem == _EXIBE_RELOGIO_DESABILITADO) {
						mostraNomeTelaIndicadorDwin();
					}				
					if (exibeRelogioMem == _EXIBE_RELOGIO_HABILITADO) { 
						telaMostraHoraData();
						transfereCaracterLcdLinha1Dwin();
					}
					limpaLinha2Dwin();

					if (controleTara == _TARAATIVADA)
					{
						transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&caracterLcd[22]);
					}
					else
					{
						transfereArrayToArray(7,&pesoBrutoIndicadorAscii[0],&caracterLcd[22]);
					}
					caracterLcd[30] = 'K';
					caracterLcd[31] = 'g';
				}
				
				mostraPesoDwin();
			}
		}
	}
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que controla o tempo de ixibicao da tela inicial                     	//
//////////////////////////////////////////////////////////////////////////////////		
void funcaoTempoTelaInicial (void)
{
	if (exibeVersionControl == 1)
	{
		if (++tempoExibeTelaInicial == 39)
		{
			tempoExibeTelaInicial = 0;
			exibeVersionControl = 0;
			sistemaInicializado = 1;
			iniciaVariaveisTxSerial_1();
		}
	}
}

//////////////////////////////////////////////////////////////////////////////////
//Mostra hora e data do indicaodr de peso                                     	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraHoraData(void)
{
	inteiroTo2BytesAscii(horaRelogio,&caracterLcd[2]);
	
	if (piscaCaracter == 1) {
		caracterLcd[4] = ':';
	} else {
		caracterLcd[4] = ' ';
	}
	
	inteiroTo2BytesAscii(minutoRelogio,&caracterLcd[5]);
	caracterLcd[7] = ' ';
	inteiroTo2BytesAscii(diaMesRelogio,&caracterLcd[8]);
	caracterLcd[10] = '/';
	inteiroTo2BytesAscii(mesRelogio,&caracterLcd[11]);
	caracterLcd[13] = '/';
	inteiroTo2BytesAscii(anoRelogio,&caracterLcd[14]);
}

//////////////////////////////////////////////////////////////////////////////////
//Funcao que controla a velocidade de pisca de caracteres                    	//
//recurso usado na programacao de campos de porgramacao                         //
//////////////////////////////////////////////////////////////////////////////////
void funcaoPiscaCaracter(void)
{
	if (++tempoPiscaCaracter == 5) {
		tempoPiscaCaracter = 0;

		if (piscaCaracter == 1) {
			piscaCaracter = 0;
		} else {
			piscaCaracter = 1;
		}
	}
}