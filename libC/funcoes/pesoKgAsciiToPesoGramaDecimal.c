#include "pesoKgAsciiToPesoGramaDecimal.h"
#include "transfereArrayToArray.h"
#include "converteArrayAsciiParaDecimal.h"
#include "carregaArrayComEspacoAscii.h"
#define tamanhoArrayTemp  13
//////////////////////////////////////////////////////////////////////////////////		
//Transforma um peso ascii de para um peso dicimal em grama              	  	//
//qtBytesOrigem  quantidades de bytes da array de origem                        //
//indexOrigem  ponteiro da array de origem                                      //
//qtBytesDestino  quantidades de bytes da array de destino                      //
//indexDestino  ponteiro da array de desrtino                                   //
//////////////////////////////////////////////////////////////////////////////////	
void pesoKgAsciiToPesoGramaDecimal(unsigned char posicaoPontoDecimal,unsigned char qtBytesOrigem,unsigned char *indexOrigem,unsigned char qtBytesDestino,unsigned char *indexDestino)
{
    unsigned char arrayTemp[13];
    unsigned char indexRetiraPonto;
    unsigned char loop;
    unsigned char temp;
    carregaArrayComEspacoAscii(13,&arrayTemp[0]);
    if (qtBytesOrigem == 13){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[0]);}
    if (qtBytesOrigem == 12){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[1]);}
    if (qtBytesOrigem == 11){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[2]);}
    if (qtBytesOrigem == 10){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[3]);}
    if (qtBytesOrigem == 9){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[4]);}
    if (qtBytesOrigem == 8){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[5]);}
    if (qtBytesOrigem == 7){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[6]);}
    if (qtBytesOrigem == 6){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[7]);}
    if (qtBytesOrigem == 5){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[8]);}
    if (qtBytesOrigem == 4){transfereArrayToArray(qtBytesOrigem,indexOrigem,&arrayTemp[9]);}
    // retira o ponto decimal e substitui por zero
    indexRetiraPonto = 0;
 	if (arrayTemp[11] == '.'){indexRetiraPonto = 10;}
	if (arrayTemp[10] == '.'){indexRetiraPonto = 9;}
	if (arrayTemp[9] == '.')	{indexRetiraPonto = 8;}
    loop = indexRetiraPonto;
    while(loop != 0)
    {
        temp = arrayTemp[indexRetiraPonto++];
        arrayTemp[indexRetiraPonto] = temp;
        indexRetiraPonto = indexRetiraPonto - 2;
        loop--;       
    }       
//Se o peso for negativo tranforma em peso zero
    indexRetiraPonto = tamanhoArrayTemp;
    while(indexRetiraPonto != 255)
    {
        temp = arrayTemp[indexRetiraPonto];
        if (temp == '-'){carregaArrayComEspacoAscii(tamanhoArrayTemp,&arrayTemp[0]);}
        indexRetiraPonto --;  
    }   
	if (posicaoPontoDecimal == 0){loop = 3;}		
	if (posicaoPontoDecimal == 1){loop = 2;}		
	if (posicaoPontoDecimal == 2){loop = 1;}				
	if (posicaoPontoDecimal > 2){loop = 0;}				
//transforma kilograma em grama
    indexRetiraPonto = 0;
	while (loop !=0)
	{
        loop--;  
        arrayTemp[0] = arrayTemp[1]; 
        arrayTemp[1] = arrayTemp[2]; 
        arrayTemp[2] = arrayTemp[3]; 
        arrayTemp[3] = arrayTemp[4]; 
        arrayTemp[4] = arrayTemp[5]; 
        arrayTemp[5] = arrayTemp[6]; 
        arrayTemp[6] = arrayTemp[7]; 
        arrayTemp[7] = arrayTemp[8]; 
        arrayTemp[8] = arrayTemp[9]; 
        arrayTemp[9] = arrayTemp[10]; 
        arrayTemp[10] = arrayTemp[11]; 
        arrayTemp[11] = arrayTemp[12]; 
        arrayTemp[12] = 0;        
	}
//transforma os valores convertidos de ascii para decimal
    converteArrayAsciiParaDecimal(tamanhoArrayTemp,&arrayTemp[0]);
    
    if (qtBytesDestino == 13){transfereArrayToArray(qtBytesDestino,&arrayTemp[0],indexDestino);}
    if (qtBytesDestino == 12){transfereArrayToArray(qtBytesDestino,&arrayTemp[1],indexDestino);}
    if (qtBytesDestino == 11){transfereArrayToArray(qtBytesDestino,&arrayTemp[2],indexDestino);}
    if (qtBytesDestino == 10){transfereArrayToArray(qtBytesDestino,&arrayTemp[3],indexDestino);}
    if (qtBytesDestino == 9){transfereArrayToArray(qtBytesDestino,&arrayTemp[4],indexDestino);}
    if (qtBytesDestino == 8){transfereArrayToArray(qtBytesDestino,&arrayTemp[5],indexDestino);}
    if (qtBytesDestino == 7){transfereArrayToArray(qtBytesDestino,&arrayTemp[6],indexDestino);}
    if (qtBytesDestino == 6){transfereArrayToArray(qtBytesDestino,&arrayTemp[7],indexDestino);}
    if (qtBytesDestino == 5){transfereArrayToArray(qtBytesDestino,&arrayTemp[8],indexDestino);}
    if (qtBytesDestino == 4){transfereArrayToArray(qtBytesDestino,&arrayTemp[9],indexDestino);}
}