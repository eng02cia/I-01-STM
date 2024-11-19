#include "transfereConstToArray.h"
/*faz a media de peso durante a 5 segundos para armazenar coleta dos dados do
 * leitor AD 
 */
extern UART_HandleTypeDef huart3;
void fazMediaAdCalibraIndicador(void)
{
    if (flagFazMediaAd == 1)
    {
        if (flagFimCalibracao != 1)
        {
            if (tempMediaCalibraIndicador != 0){tempMediaCalibraIndicador =  tempMediaCalibraIndicador + dataAdHx711;}
            else{tempMediaCalibraIndicador = dataAdHx711;}


        }
        ++loopMediaCalibracao;
        if (loopMediaCalibracao == 50)
        {
            tempAd = tempMediaCalibraIndicador/loopMediaCalibracao;
            tempMediaCalibraIndicador = 0;
            loopMediaCalibracao = 0;
            flagFazMediaAd = 0;
            if (menuCalibraIndicador == menuSemPeso)
            {
                valorZeroIndicadorMem.int32 = tempAd;
                valorZeroIndicador = valorZeroIndicadorMem.int32;
                salvaValorAdZeroIndicadorMem();
                valorTaraIndicador = tempAd; 
                if (operacaoComTeclado == 1) // VER DO QUE SE TRATA ISSO AQUI
                {
                    telaZeroOkCalibracao();
                }
//                else{enviaConfirmaCalibracaoZero();}
            } 
            if (menuCalibraIndicador == menuComPeso)
            {
                if (flagFimCalibracao == 1)
                {
                    menuCalibraIndicador = menuCalibraIndicadorEmEspera;
                    flagFimCalibracao = 0;
					HAL_UART_Transmit(&huart3, "page PESO", 9, 25);
					HAL_UART_Transmit(&huart3, cmd_end, 3, 25);
                }
                else
                {
//verifica se as medidas da celula de carga foram positivas ou negativas
                    loopMediaCalibracao = 35;
                    tempAd = tempAd - valorZeroIndicadorMem.int32;
                    if (tempAd < 0){tempAd *=-1;}//transforma peso em positivo caso valor negativo
                    valorAdPesoCalibracao = tempAd;
//converter o peso de calibracao para 32 bits 
                    carregaArrayComZeroAscii(10,&arrayInteiroTemp[0]);      
                    transfereArrayToArray(8,&pesoCalibracaoIndicadorMem[0],&arrayInteiroTemp[2]);
                    rotacionaArrayInsere0Converte();
                    temp1Ad = atol(arrayInteiroTemp);   
                    valorDivisaoIndicador = tempAd/temp1Ad;


                    if (valorDivisaoIndicador >= 10)
                    {
                        valorDivisaoIndicadorMem.float32 = valorDivisaoIndicador;
                        salvaValorDivisaoIndicadorMem();

                        if (operacaoComTeclado == 1)
                        {
							if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&charCertoPT[0],&caracterLcd[16]);}
                            if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&charCertoING[0],&caracterLcd[16]);}
                            if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&charCertoESP[0],&caracterLcd[16]);}

                            flagFimCalibracao = 1;
                            flagFazMediaAd = 1;
                        }
         //               else{enviaConfirmaCalibracaoPeso();}
                    }
                    else
                    {
                        flagFimCalibracao = 0;
                        flagFazMediaAd = 0; 
                        if (operacaoComTeclado == 1){telaErroPesoCalibracao();}
//                        else{enviaErroCalibracaoPeso();}
                    }               
                }
            }          
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////
/*Calcula a divisao interna                                                     */
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////
/*Rotaciona a array e insere zero para limite de conversao de array             */
//////////////////////////////////////////////////////////////////////////////////
void rotacionaArrayInsere0Converte(void)
{
    static unsigned char indexRetiraPonto;
    static unsigned char temp;
    static unsigned char loop;
   // retira o ponto decimal e substitui por zero
    indexRetiraPonto = 0;
 	if (arrayInteiroTemp[8] == '.'){indexRetiraPonto = 7;}
	if (arrayInteiroTemp[7] == '.'){indexRetiraPonto = 6;}
	if (arrayInteiroTemp[6] == '.')	{indexRetiraPonto = 5;}
  	if (arrayInteiroTemp[5] == '.')	{indexRetiraPonto = 4;}
    loop = indexRetiraPonto;
    while (loop != 0)
    {
        temp = arrayInteiroTemp[indexRetiraPonto++];
        arrayInteiroTemp[indexRetiraPonto] = temp;
        indexRetiraPonto = indexRetiraPonto - 2;
        loop--;       
    }              
    arrayInteiroTemp[0] = arrayInteiroTemp[1]; 
    arrayInteiroTemp[1] = arrayInteiroTemp[2]; 
    arrayInteiroTemp[2] = arrayInteiroTemp[3]; 
    arrayInteiroTemp[3] = arrayInteiroTemp[4]; 
    arrayInteiroTemp[4] = arrayInteiroTemp[5]; 
    arrayInteiroTemp[5] = arrayInteiroTemp[6]; 
    arrayInteiroTemp[6] = arrayInteiroTemp[7];
    arrayInteiroTemp[7] = arrayInteiroTemp[8];
    arrayInteiroTemp[8] = arrayInteiroTemp[9];    
    arrayInteiroTemp[9] = 0;    
}

//////////////////////////////////////////////////////////////////////////////////
/*tela zero ok na calibracao										             */
//////////////////////////////////////////////////////////////////////////////////
void telaZeroOkCalibracao(void)
{
	if (linguagemSelecionadaMem == 0){transfereConstToArray(&charZeroOkPT[0],&caracterLcd[16]);}
	if (linguagemSelecionadaMem == 1){transfereConstToArray(&charZeroOkING[0],&caracterLcd[16]);}
	if (linguagemSelecionadaMem == 2){transfereConstToArray(&charZeroOkESP[0],&caracterLcd[16]);}
#ifdef displaySeteSegmentosLcd
	if (linguagemSelecionadaMem == portugues)
	{
		dadoLcdSetSegmentos[1] = 'Z';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'R';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'K';
	}
	if (linguagemSelecionadaMem == ingles)
	{
		dadoLcdSetSegmentos[1] = 'Z';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'R';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'K';
	}
	if (linguagemSelecionadaMem == espanhol)
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'R';
		dadoLcdSetSegmentos[4] = ' ';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = 'K';
	}
#endif
}
//////////////////////////////////////////////////////////////////////////////////
/*tela calibracao correta											             */
//////////////////////////////////////////////////////////////////////////////////
void telaCertoCalibracao(void)
{
	if (linguagemSelecionadaMem == _PORTUGUES){transfereConstToArray(&charCertoPT[0],&caracterLcd[16]);}
	if (linguagemSelecionadaMem == _INGLES){transfereConstToArray(&charCertoING[0],&caracterLcd[16]);}
	if (linguagemSelecionadaMem == _ESPANHOL){transfereConstToArray(&charCertoESP[0],&caracterLcd[16]);}
#ifdef displaySeteSegmentosLcd
	if (linguagemSelecionadaMem == portugues)
	{
		dadoLcdSetSegmentos[1] = 'C';
		dadoLcdSetSegmentos[2] = 'E';
		dadoLcdSetSegmentos[3] = 'R';
		dadoLcdSetSegmentos[4] = 'T';
		dadoLcdSetSegmentos[5] = 'O';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if (linguagemSelecionadaMem == ingles)
	{
		dadoLcdSetSegmentos[1] = 'R';
		dadoLcdSetSegmentos[2] = 'I';
		dadoLcdSetSegmentos[3] = 'G';
		dadoLcdSetSegmentos[4] = 'H';
		dadoLcdSetSegmentos[5] = 'T';
		dadoLcdSetSegmentos[6] = ' ';
	}
	if (linguagemSelecionadaMem == espanhol)
	{
		dadoLcdSetSegmentos[1] = 'B';
		dadoLcdSetSegmentos[2] = 'I';
		dadoLcdSetSegmentos[3] = 'E';
		dadoLcdSetSegmentos[4] = 'N';
		dadoLcdSetSegmentos[5] = ' ';
		dadoLcdSetSegmentos[6] = ' ';
	}
#endif
}
