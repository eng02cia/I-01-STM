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
		//Menu de programação
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
					// mostraModeloIndicadorDwin();
					mostraNomeTelaIndicadorDwin();
					limpaLinha2Dwin();					

					if (controleTara == _TARAATIVADA)
					{
						transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&caracterLcd[22]);
					}
					else
					{
						//                        caracterLcd[16] = testeEndModbus +'0';
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
//Função que controla o tempo de ixibição da tela inicial                     	//
//////////////////////////////////////////////////////////////////////////////////		
void funcaoTempoTelaInicial (void)
{
	if (exibeVersionControl == 1)
	{
		if (++tempoExibeTelaInicial == 39)
		{
			tempoExibeTelaInicial = 0;
			exibeVersionControl = 0;
			trocarPaginaPeso = 1;
			iniciaVariaveisTxSerial_1();
		}
	}
}

