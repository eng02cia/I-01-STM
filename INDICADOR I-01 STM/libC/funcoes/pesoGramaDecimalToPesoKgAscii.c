#include "pesoGramaDecimalToPesoKgAscii.h"
#include "transfereArrayToArray.h"
#include "converteArrayDecimalParaAscii.h"
#include "zeroAsciiEsquerdaToVazioAscii.h"
#include "inserePontoDecimal.h"
#include "carregaArrayComZeroDecimal.h"
#define tamanhaArray 13
#define _SIM 1
#define _NAO 0
//////////////////////////////////////////////////////////////////////////////////		
//função que ocncatena opeso de acordo com a posição do ponto decimal      	  	//
//////////////////////////////////////////////////////////////////////////////////	
void pesoGramaDecimalToPesoKgAscii(unsigned char inserePonto,unsigned char posicaoPontoDecimal,unsigned char qtBytesOrigem,unsigned char *indexOrigem,unsigned char qtBytesDestino,unsigned char *indexDestino)
{
    unsigned char arrayTemp[13];
    unsigned char tempPreparaPeso;
    carregaArrayComZeroDecimal(13,&arrayTemp[0]);
    if(qtBytesOrigem == 13)transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[0]);
    if(qtBytesOrigem == 12)transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[1]);
    if(qtBytesOrigem == 11)transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[2]);
    if(qtBytesOrigem == 10)transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[3]);
    if(qtBytesOrigem == 9)transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[4]);
    if(qtBytesOrigem == 8)transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[5]);
    if(qtBytesOrigem == 7)transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[6]);
    if(qtBytesOrigem == 6)transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[7]);
    
	if(posicaoPontoDecimal == 0){tempPreparaPeso = 3;}		
	if(posicaoPontoDecimal == 1){tempPreparaPeso = 2;}		
	if(posicaoPontoDecimal == 2){tempPreparaPeso = 1;}				
	if(posicaoPontoDecimal > 2){tempPreparaPeso = 0;}				
	while (tempPreparaPeso !=0)
	{
		tempPreparaPeso--;
   		arrayTemp[12] = arrayTemp[11];
   		arrayTemp[11] = arrayTemp[10];
   		arrayTemp[10] = arrayTemp[9];
   		arrayTemp[9] = arrayTemp[8];
   		arrayTemp[8] = arrayTemp[7];
		arrayTemp[7] = arrayTemp[6];
		arrayTemp[6] = arrayTemp[5];
		arrayTemp[5] = arrayTemp[4];
		arrayTemp[4] = arrayTemp[3];
		arrayTemp[3] = arrayTemp[2];
		arrayTemp[2] = arrayTemp[1];
		arrayTemp[1] = arrayTemp[0];
        arrayTemp[0] = 0;
	}
    converteArrayDecimalParaAscii(tamanhaArray,&arrayTemp[0]);
    if(inserePonto == _SIM){inserePontoDecimal(posicaoPontoDecimal,tamanhaArray,&arrayTemp[0]);}
    zeroAsciiEsquerdaToVazioAscii(tamanhaArray,&arrayTemp[0]);     
    if(qtBytesDestino == 13){transfereArrayToArray(qtBytesDestino,&arrayTemp[0],indexDestino);}
    if(qtBytesDestino == 12){transfereArrayToArray(qtBytesDestino,&arrayTemp[1],indexDestino);}
    if(qtBytesDestino == 11){transfereArrayToArray(qtBytesDestino,&arrayTemp[2],indexDestino);}
    if(qtBytesDestino == 10){transfereArrayToArray(qtBytesDestino,&arrayTemp[3],indexDestino);}
    if(qtBytesDestino == 9){transfereArrayToArray(qtBytesDestino,&arrayTemp[4],indexDestino);}
    if(qtBytesDestino == 8){transfereArrayToArray(qtBytesDestino,&arrayTemp[5],indexDestino);}
    if(qtBytesDestino == 7){transfereArrayToArray(qtBytesDestino,&arrayTemp[6],indexDestino);}
    if(qtBytesDestino == 6){transfereArrayToArray(qtBytesDestino,&arrayTemp[7],indexDestino);}    
}