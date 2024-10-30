#pragma warning disable 373

#include "decodificaProtocolosBalancas.h"
#include "trataBytesValidosPeso.h"
#include "transfereArrayToArray.h"
//////////////////////////////////////////////////////////////////////////////////		
//declaração de variaveis utilziadas nesta função								//
//////////////////////////////////////////////////////////////////////////////////		
static unsigned char frameTemp[55];
static unsigned char testetamanhoFrame;
static unsigned char index;
static unsigned char indexMatrix;
static unsigned char rtemp;
static unsigned char rloopControlaConversaoFinal;
static unsigned char indicaPesoNegativo;
static unsigned char displayPesoCuritiba[7];
static unsigned char frameValidoTemp[7];
static unsigned char protocoloIdentificado;
static unsigned char frameValido;
enum
{
    riceLake,
    epmSerialZero,
    epmSerialUm,
    aftsBt2000C,
    aftsBt2000R_S,
    saturnoSbr140,
    digitronDgn5,
    digitronDgn6,
    alfaPrTrc,
    alfaPrt02,
    aephMatrix,
    liderBalmak,
    toledoP03,
    toledoP01,
    toledoInd,
    weightecWt1000,
    weightecWt21,
    weightecWt3000I,
    knWagen,
    sigmaciaI01,
    imapX3,
    confiantecClasico,
    confiantecNovo,
    kratosIk14,
    semIndicador,
}modeloIndicador = semIndicador;

//////////////////////////////////////////////////////////////////////////////////		
//Função de tratamento dos protocolos de peso recebidos das balanças			//
//////////////////////////////////////////////////////////////////////////////////		
int funcTrataProtocolosBalancasCuritiba(unsigned char tamanhoFrameCuritiba, unsigned char *indexMatrix1Curitiba)
{
    testetamanhoFrame = tamanhoFrameCuritiba;

	for (index = 0 ; index < 55 ; index ++)
    {		
        frameTemp[index] = *indexMatrix1Curitiba;
        indexMatrix1Curitiba ++;
        frameTemp [index] = frameTemp [index] & 0b01111111;// usado para transforma bytes recebidos de 7 para 8 bytes
	}
	protocoloIdentificado = 0;
    modeloIndicador = semIndicador;
    		
//Separa os bytes validos para Toledo P03
//ultima correção 10/08/2018
//passa a tratar o frame toledo sem o stx(0x02) e também passa a tratR
//um frame toledo com 16 bytes, isso seria possivel sem stx e sem CKS
	if((tamanhoFrameCuritiba == 16 || tamanhoFrameCuritiba == 17 || tamanhoFrameCuritiba== 18) &&(frameTemp[0] != ' '))	
	{
        if(frameTemp[0] == 0x02){rtemp = frameTemp[2];}
        else{rtemp = frameTemp[1];}        
		rtemp = rtemp & 0b00000111;// usado para filtrar a posição do ponto decimal	
		//Sem ponto decimal
		if(rtemp == 1 == 0 ||rtemp == 1 ||rtemp == 2 )
		{
            if(frameTemp[0] == 0x02)
            {
                frameValidoTemp[0] = '0';
                frameValidoTemp[1] = frameTemp[4];
                frameValidoTemp[2] = frameTemp[5];
                frameValidoTemp[3] = frameTemp[6];
                frameValidoTemp[4] = frameTemp[7];
                frameValidoTemp[5] = frameTemp[8];
                frameValidoTemp[6] = frameTemp[9];
            }
            else
            {
                frameValidoTemp[0] = '0';
                frameValidoTemp[1] = frameTemp[3];
                frameValidoTemp[2] = frameTemp[4];
                frameValidoTemp[3] = frameTemp[5];
                frameValidoTemp[4] = frameTemp[6];
                frameValidoTemp[5] = frameTemp[7];
                frameValidoTemp[6] = frameTemp[8];
            }
		}
		// ponto decimal indicando 100 gramas		
		if(rtemp == 3)
		{
            if(frameTemp[0] == 0x02)
            {            
                frameValidoTemp[0] = frameTemp[4];
                frameValidoTemp[1] = frameTemp[5];
                frameValidoTemp[2] = frameTemp[6];
                frameValidoTemp[3] = frameTemp[7];
                frameValidoTemp[4] = frameTemp[8];
                frameValidoTemp[5] = '.';
                frameValidoTemp[6] = frameTemp[9];	
            }
            else
            {
                frameValidoTemp[0] = frameTemp[3];
                frameValidoTemp[1] = frameTemp[4];
                frameValidoTemp[2] = frameTemp[5];
                frameValidoTemp[3] = frameTemp[6];
                frameValidoTemp[4] = frameTemp[7];
                frameValidoTemp[5] = '.';
                frameValidoTemp[6] = frameTemp[8];	                
            }
		}			
		// ponto decimal indicando 10 gramas		
		if(rtemp == 4)
		{
            if(frameTemp[0] == 0x02)
            {              
                frameValidoTemp[0] = frameTemp[4];
                frameValidoTemp[1] = frameTemp[5];
                frameValidoTemp[2] = frameTemp[6];
                frameValidoTemp[3] = frameTemp[7];
                frameValidoTemp[4] = '.';
                frameValidoTemp[5] = frameTemp[8];
                frameValidoTemp[6] = frameTemp[9];
            }
            else
            {
                frameValidoTemp[0] = frameTemp[3];
                frameValidoTemp[1] = frameTemp[4];
                frameValidoTemp[2] = frameTemp[5];
                frameValidoTemp[3] = frameTemp[6];
                frameValidoTemp[4] = '.';
                frameValidoTemp[5] = frameTemp[7];
                frameValidoTemp[6] = frameTemp[8];                
                
            }
		}			
		// ponto decimal indicando 1 grama		
		if(rtemp == 5)
		{
            if(frameTemp[0] == 0x02)
            {            
                frameValidoTemp[0] = frameTemp[4];
                frameValidoTemp[1] = frameTemp[5];
                frameValidoTemp[2] = frameTemp[6];
                frameValidoTemp[3] = '.';
                frameValidoTemp[4] = frameTemp[7];
                frameValidoTemp[5] = frameTemp[8];
                frameValidoTemp[6] = frameTemp[9];	
            }
            else
            {
                frameValidoTemp[0] = frameTemp[3];
                frameValidoTemp[1] = frameTemp[4];
                frameValidoTemp[2] = frameTemp[5];
                frameValidoTemp[3] = '.';
                frameValidoTemp[4] = frameTemp[6];
                frameValidoTemp[5] = frameTemp[7];
                frameValidoTemp[6] = frameTemp[8];	                
            }
		}
        if(frameTemp[0] == 0x02){rtemp = frameTemp[3];}
        else{rtemp = frameTemp[1];}        		
		rtemp = rtemp & 0b00000100;// usado para filtrar a indicação de peso negativo	
        if(rtemp!= 0)
        {
            frameValidoTemp[0]= '-';
        }         
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePesoBlCuritiba(&frameValidoTemp[0]);
        if(frameValido == 0)
        {
            protocoloIdentificado =1;
            modeloIndicador = toledoP03;
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPesoCuritiba[0]);
        }
	}
	return protocoloIdentificado;
}	
/////////////////////////////////////////////////////////////////////////////////
//metodo que captura o peso da balança recebido pela serial             		//
/////////////////////////////////////////////////////////////////////////////////
void getPesoIndicadorBalCuritibaAscii(unsigned char*indexDestino)
{
    unsigned char *indexOrigem;
    unsigned char qtBytes;
    qtBytes = 7;
    indexOrigem = &displayPesoCuritiba[0];
    while (qtBytes!= 0)
    {
        *indexDestino++ = *indexOrigem++; 
        qtBytes--;
    }           
}
//////////////////////////////////////////////////////////////////////////////////		
//Verifica a validade do frame de peso processado 	                		  	//
//////////////////////////////////////////////////////////////////////////////////		
void verificaValidadeFramePesoBlCuritiba(unsigned char *index)	
{
    unsigned char loop = 0;


    loop = 0;
    frameValido = 0;
	while (loop < 6)        
	{
        if((*index == ',' ||*index == '.' ||(*index >= '0' && *index <= '9')|| *index == '-'|| *index == ' '|| *index == '+'|| *index == 0X6F))  
        {
            
        }
        else
        {
            frameValido = 1;
        }
		loop++;
        *index++;
	}	

}

