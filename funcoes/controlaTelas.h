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
	if (exibeVersionControl == 0 && mostraTelaTemporariaLcd == 0)
	{
		//Menu de programação
		if (menuAcessaMenusProgramacao != menuAcessaMenusProgramacaoEmEspera
				|| menuCalibraIndicador != menuCalibraIndicadorEmEspera
				|| menuConfiguraSerial_1 != menuConfiguraSerial_1EmEspera
				|| menuModoTecnicoIndicador != menuModoTecnicoIndicadorEmEspera)
		{
			if (trocarPaginaDwin == 1)
						{
							trocarPaginaDwin=0;
							goToPageDWIN(3);
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
				//caso sem recepção de de peso coloca tela e erro
				escreveDadoLcd(&telaStatusPrincipal[0],&caracterLcd[0]);
				if (trocarPaginaDwin == 0)
				{
					trocarPaginaDwin=1;
					if (posicaoPontoDecimalIndicadorMem == 0 )
					{
						goToPageDWIN(1);
						limpaLinha2Dwin();
					}
					if (posicaoPontoDecimalIndicadorMem != 0 )
					{
						goToPageDWIN(2);
						limpaLinha2Dwin();
					}
				}
				//carrega o status da memoria que esta em uso nomomento
				// teste serial
				//                if (flagTxSerial_2 == 0){caracterLcd[0] = '0';}
				//                else{caracterLcd[0] = '1';}
				//                if (transmitindoSerial_2 == 0){caracterLcd[2] = '0';}
				//                else{caracterLcd[2] = '1';}
				//                inteiroTo2BytesAscii(indexTxSerial_2,&caracterLcd[4]);

				//                if (flagTxSerial_1.txSerial_1 == 0){caracterLcd[7] = '0';}
				//                else{caracterLcd[7] = '1';}
				//                if (flagTxSerial_1.transmitindoSerial_1 == 0){caracterLcd[9] = '0';}
				//                else{caracterLcd[9] = '1';}
				//                inteiroTo2BytesAscii(indexTxSerial_1,&caracterLcd[11]);
				//////////////////////////////////////////////////////////////////////////////////
				//tela 1 de status de funcionamento                                         	//
				//////////////////////////////////////////////////////////////////////////////////
				if (statusControleSobreCarga == 1 | statusControleSubCarga == 1)
				{
					if (statusControleSobreCarga == 1){transfereConstToArray(&telaSobreCarga[0],&caracterLcd[16]);}
					if (statusControleSubCarga == 1){transfereConstToArray(&telaSubCarga[0],&caracterLcd[16]);}
					transfereCaracterLcdLinha2Dwin();

					ocultaPesoDwin();
				}
				else
				{
					transfereConstToArray(&modeloIndicador[0],&caracterLcd[0]);
					transfereCaracterLcdLinha1Dwin();
					if (controleTara == _TARAATIVADA)
					{
						transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&caracterLcd[22]);
					}
					else
					{
						//                        caracterLcd[16] = testeEndModbus +'0';
						transfereArrayToArray(7,&pesoBrutoIndicadorAscii[0],&caracterLcd[22]);
					}
					mostraPesoDwin();
					caracterLcd[30] = 'K';
					caracterLcd[31] = 'g';
				}
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
			trocarPaginaPeso=1;
			iniciaVariaveisTxSerial_1();
		}
	}
}




