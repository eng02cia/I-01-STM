//#pragma warning disable 373
//#define _BALANCASCURITIBA 
#include "decodificaProtocolosBalancas.h"
#include "trataBytesValidosPeso.h"
#include "transfereArrayToArray.h"
//////////////////////////////////////////////////////////////////////////////////		
//declara��o de variaveis utilziadas nesta fun��o								//
//////////////////////////////////////////////////////////////////////////////////		
static unsigned char frameTemp[55];
static unsigned char testetamanhoFrame;
static unsigned char tamanhoFrame;
static unsigned char index;
static unsigned char indexMatrix;
static unsigned char rtemp;
static unsigned char rloopControlaConversaoFinal;
static unsigned char indicaPesoNegativo;
static unsigned char displayPeso[7];
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
//Fun��o de tratamento dos protocolos de peso recebidos das balan�as			//
//////////////////////////////////////////////////////////////////////////////////		
int funcTrataProtocolosBalancas (unsigned char tamanhoFrameInicial, unsigned char tipoProtocolo,unsigned char *indexMatrix1)
{
    tamanhoFrame = tamanhoFrameInicial;
    testetamanhoFrame = tamanhoFrameInicial;

	for (index = 0 ; index < 55 ; index ++)
    {		
        frameTemp[index] = *indexMatrix1;
        indexMatrix1 ++;
        frameTemp [index] = frameTemp [index] & 0b01111111;// usado para transforma bytes recebidos de 7 para 8 bytes
	}
	protocoloIdentificado = 0;
    modeloIndicador = semIndicador;
    switch (tipoProtocolo)
    {        
            case 0:
                decodificaProtocoloGeral();
                break;
            case 1:
//Separa bytes validos para o protocolo do indicador HOOK AT150
//MAR�O 2020		
                if (tamanhoFrame == 7 && frameTemp[6]== 0x0D)
                {
                    protocoloIdentificado = 1;
                    displayPeso[0] = '0';
                    displayPeso[1] = frameTemp[0];
                    displayPeso[2] = frameTemp[1];
                    displayPeso[3] = frameTemp[2];
                    displayPeso[4] = frameTemp[3];
                    displayPeso[5] = frameTemp[4];
                    displayPeso[6] = frameTemp[5];
                    trataBytesValidosPeso(&displayPeso[0]);
                }    	
                if (tamanhoFrame == 6 && frameTemp[5]== 0x0D)
                {
                    protocoloIdentificado = 1;
                    displayPeso[0] = '0';
                    displayPeso[1] = '0';
                    displayPeso[2] = frameTemp[0];
                    displayPeso[3] = frameTemp[1];
                    displayPeso[4] = frameTemp[2];
                    displayPeso[5] = frameTemp[3];
                    displayPeso[6] = frameTemp[4];
                    trataBytesValidosPeso(&displayPeso[0]);
                } 
                if (tamanhoFrame == 5 && frameTemp[4]== 0x0D)
                {
                    protocoloIdentificado = 1;
                    displayPeso[0] = '0';
                    displayPeso[1] = '0';
                    displayPeso[2] = '0';
                    displayPeso[3] = frameTemp[0];
                    displayPeso[4] = frameTemp[1];
                    displayPeso[5] = frameTemp[2];
                    displayPeso[6] = frameTemp[3];
                    trataBytesValidosPeso(&displayPeso[0]);
                } 
                if (tamanhoFrame == 4 && frameTemp[3]== 0x0D)
                {
                    protocoloIdentificado = 1;
                    displayPeso[0] = '0';
                    displayPeso[1] = '0';
                    displayPeso[2] = '0';
                    displayPeso[3] = '0';
                    displayPeso[4] = frameTemp[0];
                    displayPeso[5] = frameTemp[1];
                    displayPeso[6] = frameTemp[2];
                    trataBytesValidosPeso(&displayPeso[0]);
                }
                if (tamanhoFrame == 3 && frameTemp[2]== 0x0D)
                {
                    protocoloIdentificado = 1;
                    displayPeso[0] = '0';
                    displayPeso[1] = '0';
                    displayPeso[2] = '0';
                    displayPeso[3] = '0';
                    displayPeso[4] = '0';
                    displayPeso[5] = frameTemp[0];
                    displayPeso[6] = frameTemp[1];
                    trataBytesValidosPeso(&displayPeso[0]);
                }    	     
                if (tamanhoFrame == 2 && frameTemp[2]== 0x0D)
                {
                    protocoloIdentificado = 1;
                    displayPeso[0] = '0';
                    displayPeso[1] = '0';
                    displayPeso[2] = '0';
                    displayPeso[3] = '0';
                    displayPeso[4] = '0';
                    displayPeso[5] = '0';
                    displayPeso[6] = frameTemp[0];
                    trataBytesValidosPeso(&displayPeso[0]);
                }    	                     
                break;
    }
  	return protocoloIdentificado;
}
//////////////////////////////////////////////////////////////////////////////////		
//decodifica protocolos gerais                                      			//
//////////////////////////////////////////////////////////////////////////////////	    
void decodificaProtocoloGeral(void)    
{  
//Indicador Kratos sem ponto 07/2021
    if ((tamanhoFrame == 8 && frameTemp[0] == 0x02 && frameTemp[7] == 0x0D)|| (tamanhoFrame == 9 && frameTemp[0] == 0x02 && frameTemp[8] == 0x0D))
    {
        if (frameTemp[1] == 'l' || frameTemp[1]== 'n'|| frameTemp[1]== 'd')
        {
            frameValidoTemp[0] = '-';
        }
        else
        {
            frameValidoTemp[0] = '0';
        }
        if (tamanhoFrame == 9 && frameTemp[7] != '.')
        {                
            frameValidoTemp[1] = frameTemp[2];
            frameValidoTemp[2] = frameTemp[3];
            frameValidoTemp[3] = frameTemp[4];
            frameValidoTemp[4] = frameTemp[5];
            frameValidoTemp[5] = frameTemp[6];
            frameValidoTemp[6] = frameTemp[7];           
        }
        else
        {
            frameValidoTemp[1] = '0';
            frameValidoTemp[2] = frameTemp[2];
            frameValidoTemp[3] = frameTemp[3];
            frameValidoTemp[4] = frameTemp[4];
            frameValidoTemp[5] = frameTemp[5];
            frameValidoTemp[6] = frameTemp[6];
        }       
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {  
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
            protocoloIdentificado = 1;
            modeloIndicador = kratosIk14;
        }                 
    }    
//Indicador ICV Sigmacia
    if (tamanhoFrame == 12 && frameTemp[10] == 0x0D  && frameTemp[11]== 0x0A)
    {      
        frameValidoTemp[0] = '0';
        frameValidoTemp[1] = frameTemp[4];
        frameValidoTemp[2] = frameTemp[5];
        frameValidoTemp[3] = frameTemp[6];
        frameValidoTemp[4] = frameTemp[7];
        frameValidoTemp[5] = frameTemp[8];
        frameValidoTemp[6] = frameTemp[9];
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {  
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
            protocoloIdentificado =1;
        }                 
    }
//Separa os bytes validos para o o indicador Confiantec	novo
	if ((tamanhoFrame == 12) && (frameTemp[0] == 'i' && frameTemp[11] == '\r'))
	{
        frameValidoTemp[0] = ' ';     
        if (frameTemp[1] == '-'){frameValidoTemp[0] = '-';}    
        frameValidoTemp[1] = frameTemp[2];
        frameValidoTemp[2] = frameTemp[3];
        frameValidoTemp[3] = frameTemp[4];
        frameValidoTemp[4] = frameTemp[5];
        frameValidoTemp[5] = frameTemp[6];
        frameValidoTemp[6] = frameTemp[7];
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {        
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
            protocoloIdentificado =1;
            modeloIndicador = confiantecNovo;
        }        
	}		          
//Separa os bytes validos para o o indicador Confiantec	clasico
	if	((tamanhoFrame == 19) && (frameTemp[14] == 'k' && frameTemp[17] == '\n'))
	{

        if (frameTemp[4] == '-'){frameValidoTemp[0] = '-';}
        else{frameValidoTemp[0] = frameTemp[5];}        
        frameValidoTemp[1] = frameTemp[6];
        frameValidoTemp[2] = frameTemp[7];
        frameValidoTemp[3] = frameTemp[8];
        frameValidoTemp[4] = frameTemp[9];
        frameValidoTemp[5] = frameTemp[10];
        frameValidoTemp[6] = frameTemp[11];
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {         
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
            protocoloIdentificado =1;
            modeloIndicador = confiantecClasico;
        }        
	}		      
//Separa os bytes validos para o o indicador imapX3			
	if	((tamanhoFrame == 9) && (frameTemp[0] == 0x3D))
	{

        if (frameTemp[1] == '-'){frameValidoTemp[0] = frameTemp[1];}
        else{frameValidoTemp[0] = frameTemp[2];}        
        frameValidoTemp[1] = frameTemp[3];
        frameValidoTemp[2] = frameTemp[4];
        frameValidoTemp[3] = frameTemp[5];
        frameValidoTemp[4] = frameTemp[6];
        frameValidoTemp[5] = frameTemp[7];
        frameValidoTemp[6] = frameTemp[8];
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {        
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
            protocoloIdentificado =1;
            modeloIndicador = imapX3;
        }       
	}		
//Separa os bytes validos para o indicador toledo IND331 especial		
	if ((tamanhoFrame == 25)&& frameTemp[23] == 0X0D)
    {

//        modeloIndicador = sigmaciaI01; 
		frameValidoTemp[0] = frameTemp[8];
		frameValidoTemp[1] = frameTemp[9];
		frameValidoTemp[2] = frameTemp[10];
		frameValidoTemp[3] = frameTemp[11];
		frameValidoTemp[4] = frameTemp[12];
		frameValidoTemp[5] = frameTemp[13];
		frameValidoTemp[6] = frameTemp[14];
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
        	protocoloIdentificado = 1;
        }
	}           
//Separa os bytes validos do indicador Sigmacia I-01			
	if ((tamanhoFrame == 30)&&(frameTemp[0] == 2)&&(frameTemp[29] == 0X0A))
	{
		frameValidoTemp[0] = frameTemp[3];
		frameValidoTemp[1] = frameTemp[4];
		frameValidoTemp[2] = frameTemp[5];
		frameValidoTemp[3] = frameTemp[6];
		frameValidoTemp[4] = frameTemp[7];
		frameValidoTemp[5] = frameTemp[8];
		frameValidoTemp[6] = frameTemp[9];
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        
        if (frameValido == 0)
        {
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
            protocoloIdentificado =1;
            modeloIndicador = sigmaciaI01;             
        }
	}        
//Separa os bytes validos da serial do indicador RICE LAKE(BALAN�AS ACORES SERIAL 3)			
	if ((tamanhoFrame == 30)&&(frameTemp[28] == ' ')&&(frameTemp[29] == ' '))
	{
		protocoloIdentificado =1;
        modeloIndicador = sigmaciaI01; 
		displayPeso[0] = frameTemp[0];
		displayPeso[1] = frameTemp[1];
		displayPeso[2] = frameTemp[2];
		displayPeso[3] = frameTemp[3];
		displayPeso[4] = frameTemp[4];
		displayPeso[5] = frameTemp[5];
		displayPeso[6] = frameTemp[6];
		trataBytesValidosPeso(&displayPeso[0]);
	}
//Separa os bytes validos da serial do indicador RICE LAKE(BALAN�AS ACORES SERIAL 4)
//14 BYTES Ex: 02 32 32 32 32 32 52 54 48 76 71 32 13 10 peso igual a 460 kg
	if ((tamanhoFrame == 14)&&(frameTemp[0] == 2)&&(frameTemp[13] == 10))
	{
		protocoloIdentificado =1;
        modeloIndicador = riceLake; 
		displayPeso[0] = frameTemp[2];
		displayPeso[1] = frameTemp[3];
		displayPeso[2] = frameTemp[4];
		displayPeso[3] = frameTemp[5];
		displayPeso[4] = frameTemp[6];
		displayPeso[5] = frameTemp[7];
		displayPeso[6] = frameTemp[8];
        if (frameTemp[1] == '-'){displayPeso[0] = '-';}
		trataBytesValidosPeso(&displayPeso[0]);
//        verificaValidadeFramePeso(&displayPeso[0]);
//        if (protocoloIdentificado == 0){funcLimpaDisplayPeso();}
	}        
//Separa os bytes validos da serial 1 dos indicadores epm e bj850
//quantidade de bytes 29 se refere ao indicador wt27 transmitindo no formato
//epm
	if ((tamanhoFrame == 28 || tamanhoFrame == 29 ||tamanhoFrame == 30 )&&(frameTemp[0] == 0x20))
	{
		protocoloIdentificado =1;
        modeloIndicador = epmSerialZero;
		displayPeso[0] = frameTemp[4];
		displayPeso[1] = frameTemp[5];
		displayPeso[2] = frameTemp[6];
		displayPeso[3] = frameTemp[7];
		displayPeso[4] = frameTemp[8];
		displayPeso[5] = frameTemp[9];
		displayPeso[6] = frameTemp[10];
		trataBytesValidosPeso(&displayPeso[0]);
	}
//Separa os bytes validos da serial 2 dos indicadores epm velocidade de 4800 kbps, saida padr�o para display
//peso n�o estabilziado transmite 11 bytes, byte 0 e 10 expressam um valor depois da aplica��o da mascara no bit mais significativo
//peso estabilizado transmite 10 bytes, byte 0 e 9 expressam um valor depois da aplica��o da mascara no bit mais significativo				
	if ((tamanhoFrame == 11)&&(frameTemp[0] == 0x00 && frameTemp[10] == 0x01))
	{
		protocoloIdentificado =1;
        modeloIndicador = epmSerialUm;
		displayPeso[0] = frameTemp[1];
		displayPeso[1] = frameTemp[2];
		displayPeso[2] = frameTemp[3];
		displayPeso[3] = frameTemp[4];
		displayPeso[4] = frameTemp[5];
		displayPeso[5] = frameTemp[6];
		displayPeso[6] = frameTemp[7];
		trataBytesValidosPeso(&displayPeso[0]);
	}
//separa bytes quando recebe frame do indicador SP4000 serial 0(configuraado para display DG6000)
//sem ponto
	if ((tamanhoFrame == 9)&&(frameTemp[0] == 17))
	{
		protocoloIdentificado =1;
        modeloIndicador = epmSerialUm;
		displayPeso[0] = ' ';
		displayPeso[1] = ' ';
		displayPeso[2] = frameTemp[2];
		displayPeso[3] = frameTemp[3];
		displayPeso[4] = frameTemp[4];
		displayPeso[5] = frameTemp[5];
		displayPeso[6] = frameTemp[6];
		trataBytesValidosPeso(&displayPeso[0]);
	}    
//separa bytes quando recebe frame do indicador SP4000 serial 0(configuraado para display DG6000)
//com ponto
	if ((tamanhoFrame == 10)&&(frameTemp[0] == 17))
	{
		protocoloIdentificado =1;
        modeloIndicador = epmSerialUm;
		displayPeso[0] = ' ';
		displayPeso[1] = frameTemp[2];
		displayPeso[2] = frameTemp[3];
		displayPeso[3] = frameTemp[4];
		displayPeso[4] = frameTemp[5];
		displayPeso[5] = frameTemp[6];
		displayPeso[6] = frameTemp[7];
		trataBytesValidosPeso(&displayPeso[0]);
	}        
//peso estabilizado transmite 10 bytes, byte 0 e 9 expressam um valor depois da aplica��o da mascara no bit mais significativo				
	if ((tamanhoFrame == 10)&&(frameTemp[0] == 0x00 && frameTemp[9] == 0x01))
	{
		protocoloIdentificado =1;
        modeloIndicador = epmSerialUm;        
		displayPeso[0] = ' ';
		displayPeso[1] = frameTemp[1];
		displayPeso[2] = frameTemp[2];
		displayPeso[3] = frameTemp[3];
		displayPeso[4] = frameTemp[4];
		displayPeso[5] = frameTemp[5];
		displayPeso[6] = frameTemp[6];
		trataBytesValidosPeso(&displayPeso[0]);
	}														
//Separa os bytes validos para Afts Bt2000C				
	if (tamanhoFrame == 8 && frameTemp[0] == 0x3D)
	{
		protocoloIdentificado =1;
        modeloIndicador = aftsBt2000C;
		if (frameTemp[1] == ' '|| frameTemp[1] == '-')// ordem do peso correta
		{
    		displayPeso[0] = frameTemp[1];
			displayPeso[1] = frameTemp[2];
			displayPeso[2] = frameTemp[3];
			displayPeso[3] = frameTemp[4];
			displayPeso[4] = frameTemp[5];
			displayPeso[5] = frameTemp[6];
			displayPeso[6] = frameTemp[7];
			trataBytesValidosPeso(&displayPeso[0]);
		}
		if (frameTemp[7] ==' '|| frameTemp[7] == '-')//ordem do peso ivertido
		{
			displayPeso[0] = frameTemp[7];
			displayPeso[1] = frameTemp[6];
			displayPeso[2] = frameTemp[5];
			displayPeso[3] = frameTemp[4];
			displayPeso[4] = frameTemp[3];
			displayPeso[5] = frameTemp[2];
			displayPeso[6] = frameTemp[1];
			trataBytesValidosPeso(&displayPeso[0]);
		}					
	}			
//Separa os bytes validos para Afts Bt2000R/S				
	if (tamanhoFrame == 10 && frameTemp[8] == 0x0D&& frameTemp[9] == 0x0A)
	{
		protocoloIdentificado =1;
        modeloIndicador = aftsBt2000R_S;
		displayPeso[0] = frameTemp[1];
		displayPeso[1] = frameTemp[2];
		displayPeso[2] = frameTemp[3];
		displayPeso[3] = frameTemp[4];
		displayPeso[4] = frameTemp[5];
		displayPeso[5] = frameTemp[6];
		displayPeso[6] = frameTemp[7];
		if (frameTemp[0]== '-')
		{
			displayPeso[0] = '-';
		}
		trataBytesValidosPeso(&displayPeso[0]);
	}			
//Separa os bytes validos para o Indicador Sbr 140 (pacote normal e reduzido				
	if	((tamanhoFrame == 8 || tamanhoFrame == 12) && (frameTemp[0] == 0x0D))
	{
        protocoloIdentificado =1;
        modeloIndicador = saturnoSbr140;
        displayPeso[0] = '0';
        displayPeso[1] = frameTemp[1];
        displayPeso[2] = frameTemp[2];
        displayPeso[3] = frameTemp[3];
        displayPeso[4] = frameTemp[4];
        displayPeso[5] = frameTemp[5];
        displayPeso[6] = frameTemp[6];
        trataBytesValidosPeso(&displayPeso[0]);
	}				
//Separa os bytes validos para Digitron Dgn5 e Dgn6				
	if ((tamanhoFrame== 8 || tamanhoFrame== 9) && (frameTemp[0] != 0x02) && (frameTemp[7] == 0x0D || frameTemp[8] == 0x0D))		
	{
		protocoloIdentificado = 1;
		if (tamanhoFrame== 8)
		{
            modeloIndicador = digitronDgn5;
			if (frameTemp[6]== '.')
			{
                displayPeso[0] = '0';
                displayPeso[1] = '0';
                displayPeso[2] = frameTemp[1];
                displayPeso[3] = frameTemp[2];
                displayPeso[4] = frameTemp[3];
                displayPeso[5] = frameTemp[4];
                displayPeso[6] = frameTemp[5];
    		}
			else
			{
                displayPeso[0] = '0';
                displayPeso[1] = frameTemp[1];
                displayPeso[2] = frameTemp[2];
                displayPeso[3] = frameTemp[3];
                displayPeso[4] = frameTemp[4];
                displayPeso[5] = frameTemp[5];
                displayPeso[6] = frameTemp[6];
			}
		}
        if (tamanhoFrame == 9)
		{
            modeloIndicador = digitronDgn6;
            if (frameTemp[7]== '.')
			{            
                displayPeso[0] = '0';
                displayPeso[1] = frameTemp[1];
                displayPeso[2] = frameTemp[2];
                displayPeso[3] = frameTemp[3];
                displayPeso[4] = frameTemp[4];
                displayPeso[5] = frameTemp[5];
                displayPeso[6] = frameTemp[6];
            }
            else
            {
                displayPeso[0] = frameTemp[1];
                displayPeso[1] = frameTemp[2];
                displayPeso[2] = frameTemp[3];
                displayPeso[3] = frameTemp[4];
                displayPeso[4] = frameTemp[5];
                displayPeso[5] = frameTemp[6];
                displayPeso[6] = frameTemp[7];
            }
		}			
		frameTemp[0] = frameTemp[0] & 0b00001000;// usado para filtrar a indica��o de peso negativo	
		if (frameTemp[0]!= 0){displayPeso[0]= '-';}
        trataBytesValidosPeso(&displayPeso[0]);       
    }
//Separa os bytes validos para Alfa Trc com e sem ponto e com e sem ponto		
	if ((tamanhoFrame == 20 || tamanhoFrame==22) && (frameTemp[0] == 'P' || frameTemp[0] == '*'))
	{
        protocoloIdentificado =1;
        modeloIndicador = alfaPrTrc;
        if (frameTemp[9] == ' ' || frameTemp[9] == 0)
        {
            displayPeso[0] = '0';
			displayPeso[1] = frameTemp[3];
			displayPeso[2] = frameTemp[4];
			displayPeso[3] = frameTemp[5];
			displayPeso[4] = frameTemp[6];
			displayPeso[5] = frameTemp[7];
			displayPeso[6] = frameTemp[8];
		}
		else						
		{	
			displayPeso[0] = frameTemp[3];
			displayPeso[1] = frameTemp[4];
			displayPeso[2] = frameTemp[5];
			displayPeso[3] = frameTemp[6];
			displayPeso[4] = frameTemp[7];
			displayPeso[5] = frameTemp[8];
			displayPeso[6] = frameTemp[9];
		}
		trataBytesValidosPeso(&displayPeso[0]);
	}       
//Separa os bytes validos para Alfa Trc com 24 bytes
// formato encontrado em comunica��o 3101C transmis�ao formato AA		
	if (tamanhoFrame == 24 && (frameTemp[0] == 'P' || frameTemp[0] == '*'))
	{
		protocoloIdentificado = 1;
        modeloIndicador = alfaPrTrc;
		displayPeso[0] = frameTemp[5];
		displayPeso[1] = frameTemp[6];
		displayPeso[2] = frameTemp[7];
		displayPeso[3] = frameTemp[8];
		displayPeso[4] = frameTemp[9];
		displayPeso[5] = frameTemp[10];
		displayPeso[6] = frameTemp[11];
		trataBytesValidosPeso(&displayPeso[0]);
	}               
//Separa os bytes validos para Alfa PRT02		
	if (tamanhoFrame == 15 && frameTemp[0] == 0x02)
	{		
		rtemp = frameTemp[1];
		rtemp = rtemp & 0b00000111;// usado para filtrar a posi��o do ponto decimal	
		//Sem ponto decimal
		if	(rtemp == 0)
		{
			frameValidoTemp[0] = '0';
			frameValidoTemp[1] = '0';
			frameValidoTemp[2] = frameTemp[3];
			frameValidoTemp[3] = frameTemp[4];
			frameValidoTemp[4] = frameTemp[5];
			frameValidoTemp[5] = frameTemp[6];
			frameValidoTemp[6] = frameTemp[7];	
//            frameValidoTemp[6] = '0';
		}
		// ponto decimal indicando 100 gramas		
		if (rtemp == 1)
		{
			frameValidoTemp[0] = '0';
			frameValidoTemp[1] = frameTemp[3];
			frameValidoTemp[2] = frameTemp[4];
			frameValidoTemp[3] = frameTemp[5];
			frameValidoTemp[4] = frameTemp[6];
			frameValidoTemp[5] = '.';
			frameValidoTemp[6] = frameTemp[7];		
		}			
		// ponto decimal indicando 10 gramas		
		if (rtemp == 2)
		{
			frameValidoTemp[0] = '0';
			frameValidoTemp[1] = frameTemp[3];
			frameValidoTemp[2] = frameTemp[4];
			frameValidoTemp[3] = frameTemp[5];
			frameValidoTemp[4] = '.';
			frameValidoTemp[5] = frameTemp[6];
			frameValidoTemp[6] = frameTemp[7];		
		}			
		// ponto decimal indicando 1 grama		
		if (rtemp == 3)
		{
			frameValidoTemp[0] = '0';
			frameValidoTemp[1] = frameTemp[3];
			frameValidoTemp[2] = frameTemp[4];
			frameValidoTemp[3] = '.';
			frameValidoTemp[4] = frameTemp[5];
			frameValidoTemp[5] = frameTemp[6];
			frameValidoTemp[6] = frameTemp[7];		
		}
	// ponto decimal indicando 1 decimo degrama		
		if (rtemp ==4)
		{
			frameValidoTemp[0] = '0';
			frameValidoTemp[1] = frameTemp[3];
			frameValidoTemp[2] = '.';
			frameValidoTemp[3] = frameTemp[4];
			frameValidoTemp[4] = frameTemp[5];
			frameValidoTemp[5] = frameTemp[6];
			frameValidoTemp[6] = frameTemp[7];		
		}
		rtemp = frameTemp[1];			
		rtemp = rtemp & 0b00001000;// usado para filtrar a indica��o de peso negativo	
		if (rtemp!= 0)
		{
			frameValidoTemp[0]= '-';
		}
		trataBytesValidosPeso(&frameValidoTemp[0]);	
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {
            protocoloIdentificado =1;
            modeloIndicador = alfaPrt02;
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
        }		
	}
//Separa os bytes validos para AEPH matrix com e sem ponto		
	if ((tamanhoFrame == 36) && (frameTemp[0] == 'P' || frameTemp[0] == '*'))
	{
        frameValidoTemp[0] = ' ';
        frameValidoTemp[1] = frameTemp[3];
        frameValidoTemp[2] = frameTemp[4];
        frameValidoTemp[3] = frameTemp[5];
		frameValidoTemp[4] = frameTemp[6];
		frameValidoTemp[5] = frameTemp[7];
		frameValidoTemp[6] = frameTemp[8];
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {  
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
            protocoloIdentificado =1;
            modeloIndicador = aephMatrix;
        }                 
	}     
//Separa os bytes validos para AEPH matrix com e sem ponto		
	if ((tamanhoFrame == 39) && (frameTemp[0] == 'P' || frameTemp[0] == '*'))
	{
        frameValidoTemp[0] = frameTemp[3];
        frameValidoTemp[1] = frameTemp[4];
        frameValidoTemp[2] = frameTemp[5];
        frameValidoTemp[3] = frameTemp[6];
		frameValidoTemp[4] = frameTemp[7];
		frameValidoTemp[5] = frameTemp[8];
		frameValidoTemp[6] = frameTemp[9];
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {  
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
            protocoloIdentificado =1;
            modeloIndicador = aephMatrix;
        }                 
	}    
    
    //Separa os bytes validos para Lider/Balmak		
    // atualiza��o 11/2016 para indicador 2052D
	if ((tamanhoFrame == 10) && (frameTemp[0] == 0x01) && (frameTemp[9] == 0x02))
	{
		protocoloIdentificado =1;
        modeloIndicador = liderBalmak;
		displayPeso[0] = frameTemp[1];
		displayPeso[1] = frameTemp[2];
		displayPeso[2] = frameTemp[3];
		displayPeso[3] = frameTemp[4];
		displayPeso[4] = frameTemp[5];
		displayPeso[5] = frameTemp[6];
		displayPeso[6] = frameTemp[7];
		if (displayPeso[6] == '.')
		{
//			displayPeso[6] = '0';
            displayPeso[6] = displayPeso[5];
            displayPeso[5] = displayPeso[4];
            displayPeso[4] = displayPeso[3];
            displayPeso[3] = displayPeso[2];
            displayPeso[2] = displayPeso[1];
            displayPeso[1] = displayPeso[0];
            displayPeso[0] = ' ';                    
		}
		trataBytesValidosPeso(&displayPeso[0]);
	}    		
	if ((tamanhoFrame == 11) && (frameTemp[0] == 0x01) && (frameTemp[10] == 0x02))
	{
		protocoloIdentificado =1;
        modeloIndicador = liderBalmak;
		displayPeso[0] = frameTemp[1];
		displayPeso[1] = frameTemp[2];
		displayPeso[2] = frameTemp[3];
		displayPeso[3] = frameTemp[4];
		displayPeso[4] = frameTemp[5];
		displayPeso[5] = frameTemp[6];
		displayPeso[6] = frameTemp[7];
		if (displayPeso[6] == '.')
		{
            displayPeso[6] = displayPeso[5];
            displayPeso[5] = displayPeso[4];
            displayPeso[4] = displayPeso[3];
            displayPeso[3] = displayPeso[2];
            displayPeso[2] = displayPeso[1];
            displayPeso[1] = displayPeso[0];
            displayPeso[0] = ' ';                    
		}
		trataBytesValidosPeso(&displayPeso[0]);
	}
	if ((tamanhoFrame == 9) && (frameTemp[0] == 0x01) && (frameTemp[9] == 0x02))
	{				
		protocoloIdentificado =1;
        modeloIndicador = liderBalmak;
		if (tamanhoFrame == 9 && frameTemp [7] != ' ')
		{
			displayPeso[0] = frameTemp[1];
			displayPeso[1] = frameTemp[2];
			displayPeso[2] = frameTemp[3];
			displayPeso[3] = frameTemp[4];
			displayPeso[4] = frameTemp[5];
			displayPeso[5] = frameTemp[6];
			displayPeso[6] = frameTemp[7];
		}
		if (tamanhoFrame == 9 && frameTemp [7] == ' ')
		{
			displayPeso[0] = '0';
			displayPeso[1] = frameTemp[1];
			displayPeso[2] = frameTemp[2];
			displayPeso[3] = frameTemp[3];
			displayPeso[4] = frameTemp[4];
			displayPeso[5] = frameTemp[5];
			displayPeso[6] = frameTemp[6];	
		}								
		trataBytesValidosPeso(&displayPeso[0]);
	}			
//Separa os bytes validos para Toledo P03
//ultima corre��o 10/08/2018
//passa a tratar o frame toledo sem o stx(0x02) e tamb�m passa a tratR
//um frame toledo com 16 bytes, isso seria possivel sem stx e sem CKS
	if ((tamanhoFrame == 16 || tamanhoFrame == 17 || tamanhoFrame== 18) &&(frameTemp[0] != ' '))	
	{
        if (frameTemp[0] == 0x02){rtemp = frameTemp[1];}
        else{rtemp = frameTemp[0];}
		rtemp = rtemp & 0b00000111;// usado para filtrar a posi��o do ponto decimal	
		//Sem ponto decimal
		if (rtemp == 1 == 0 ||rtemp == 1 ||rtemp == 2 )
		{
            if (frameTemp[0] == 0x02)
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
		if (rtemp == 3)
		{
            if (frameTemp[0] == 0x02)
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
		if (rtemp == 4)
		{
            if (frameTemp[0] == 0x02)
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
		if (rtemp == 5)
		{
            if (frameTemp[0] == 0x02)
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
        if (frameTemp[0] == 0x02){rtemp = frameTemp[2];}
        else{rtemp = frameTemp[1];}        		
		rtemp = rtemp & 0b00000010;// usado para filtrar a indica��o de peso negativo	
        if (rtemp!= 0)
        {
            frameValidoTemp[0]= '-';
        }  
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {
            protocoloIdentificado =1;
            modeloIndicador = toledoP03;
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
        }
	}
//Separa os bytes validos para Toledo P01 sem data e sem hora				
	if ((tamanhoFrame == 13) && (frameTemp[0] == 0x02 && frameTemp[12] == 0xA))	
	{
		protocoloIdentificado =1;
        modeloIndicador = toledoP01;
//		rtemp = frameTemp[1];
//		rtemp = rtemp & 0b00000111;// usado para filtrar a posi��o do ponto decimal	
		displayPeso[0] = frameTemp[1];
		displayPeso[1] = frameTemp[2];
		displayPeso[2] = frameTemp[3];
		displayPeso[3] = frameTemp[4];
		displayPeso[4] = frameTemp[5];
		displayPeso[5] = frameTemp[6];
		displayPeso[6] = frameTemp[7];
		trataBytesValidosPeso(&displayPeso[0]);      
    }    
//Separa os bytes validos para Weightech  Wt1000 modelo antigo				
	if ((tamanhoFrame == 13 ||tamanhoFrame == 15) && (frameTemp[0] == 'W'))
	{
		protocoloIdentificado =1;
        modeloIndicador = weightecWt1000;
        if (frameTemp[8]  == ' ')
        {
            displayPeso[0] = ' ';
            displayPeso[1] = frameTemp[2];
            displayPeso[2] = frameTemp[3];
            displayPeso[3] = frameTemp[4];
            displayPeso[4] = frameTemp[5];
            displayPeso[5] = frameTemp[6];
            displayPeso[6] = frameTemp[7];                        
        }
        else
        {
            displayPeso[0] = frameTemp[2];
            displayPeso[1] = frameTemp[3];
            displayPeso[2] = frameTemp[4];
            displayPeso[3] = frameTemp[5];
            displayPeso[4] = frameTemp[6];
            displayPeso[5] = frameTemp[7];
            displayPeso[6] = frameTemp[8];
        }
		trataBytesValidosPeso(&displayPeso[0]);
	}	
//Separa os bytes validos para toledo ind linha ind	 560 16 bytes  
	if ((tamanhoFrame == 16 || tamanhoFrame == 34 || tamanhoFrame == 53) && (frameTemp[0] == ' ' && frameTemp[1] == ' '))	
	{
		protocoloIdentificado =1;
		frameValidoTemp[0] = frameTemp[3];
		frameValidoTemp[1] = frameTemp[4];
		frameValidoTemp[2] = frameTemp[5];
		frameValidoTemp[3] = frameTemp[6];
		frameValidoTemp[4] = frameTemp[7];
		frameValidoTemp[5] = frameTemp[8];
		frameValidoTemp[6] = frameTemp[9];
		trataBytesValidosPeso(&frameValidoTemp[0]);
        verificaValidadeFramePeso(&frameValidoTemp[0]);
        if (frameValido == 0)
        {
            protocoloIdentificado = 1;
            modeloIndicador = toledoInd;
            transfereArrayToArray(7,&frameValidoTemp[0],&displayPeso[0]);
        }                        
    }
//Separa os bytes validos para Weightech  Wt1000 modelo atual				
	if ((tamanhoFrame == 27 || tamanhoFrame == 47) && (frameTemp[25] == 0x0D || frameTemp[45] == 0x0D))
	{
        if (frameTemp[8]== ' ')
        {
            protocoloIdentificado = 1;
            modeloIndicador = weightecWt1000;
            displayPeso[0] = ' ';
            displayPeso[1] = frameTemp[2];
            displayPeso[2] = frameTemp[3];
            displayPeso[3] = frameTemp[4];
            displayPeso[4] = frameTemp[5];
            displayPeso[5] = frameTemp[6];
            displayPeso[6] = frameTemp[7];
            trataBytesValidosPeso(&displayPeso[0]);         
        }
        else
        {
            protocoloIdentificado =1;
            modeloIndicador = weightecWt1000;            
            displayPeso[0] = frameTemp[2];
            displayPeso[1] = frameTemp[3];
            displayPeso[2] = frameTemp[4];
            displayPeso[3] = frameTemp[5];
            displayPeso[4] = frameTemp[6];
            displayPeso[5] = frameTemp[7];
            displayPeso[6] = frameTemp[8];
            trataBytesValidosPeso(&displayPeso[0]);
		}	
    }
//Separa os bytes validos para Weightech  Wt21 				
    if ((tamanhoFrame == 18 ) && (frameTemp[0] == 'S' || frameTemp[0] == 'U'))
	{
		protocoloIdentificado =1;
        modeloIndicador = weightecWt21;
		displayPeso[0] = frameTemp[6];//indicativo de peso negativo vem nesse byte
		displayPeso[1] = frameTemp[8];
		displayPeso[2] = frameTemp[9];
		displayPeso[3] = frameTemp[10];
		displayPeso[4] = frameTemp[11];
		displayPeso[5] = frameTemp[12];
		displayPeso[6] = frameTemp[13];
		trataBytesValidosPeso(&displayPeso[0]);
	}			
//Separa os bytes validos para Weightech Wt3000I 6 bytes				
	if ((tamanhoFrame == 20) && (frameTemp[0] == 'S' || frameTemp[0] == 'U'))
	{
		protocoloIdentificado =1;
        modeloIndicador = weightecWt3000I;
		displayPeso[0] = frameTemp[6];//indicativo de peso negativo vem nesse byte
		displayPeso[1] = frameTemp[8];
		displayPeso[2] = frameTemp[9];
		displayPeso[3] = frameTemp[10];
		displayPeso[4] = frameTemp[11];
		displayPeso[5] = frameTemp[12];
		displayPeso[6] = frameTemp[13];
		trataBytesValidosPeso(&displayPeso[0]);
	}
//Separa os bytes validos para Weightech Wt3000I 7 bytes				
	if ((tamanhoFrame == 21) && (frameTemp[0] == 'S' || frameTemp[0] == 'U'))
	{
		protocoloIdentificado =1;
        modeloIndicador = weightecWt3000I;
		displayPeso[0] = frameTemp[6];//indicativo de peso negativo vem nesse byte
		displayPeso[1] = frameTemp[9];
		displayPeso[2] = frameTemp[10];
		displayPeso[3] = frameTemp[11];
		displayPeso[4] = frameTemp[12];
		displayPeso[5] = frameTemp[13];
		displayPeso[6] = frameTemp[14];
		trataBytesValidosPeso(&displayPeso[0]);
	}			
//Separa os bytes validos para Kn Wagen				
	if ((tamanhoFrame == 14) && (frameTemp[0] == 0x20)&& (frameTemp[13] == 0x0A))
	{		
		protocoloIdentificado =1;
        modeloIndicador = knWagen;
		displayPeso[0] = frameTemp[3];
		displayPeso[1] = frameTemp[4];
		displayPeso[2] = frameTemp[5];
		displayPeso[3] = frameTemp[6];
		displayPeso[4] = frameTemp[7];
		displayPeso[5] = frameTemp[8];
		displayPeso[6] = frameTemp[9];
		if	(frameTemp[0]== '-')
		{
			displayPeso[0] = '-';
		}
		trataBytesValidosPeso(&displayPeso[0]);
	}			
//Separa os bytes validos para Filisola Idm			
	if (tamanhoFrame == 10 && frameTemp[0]== 0x02)
	{
		protocoloIdentificado = 1;
		displayPeso[0] = '0';
		displayPeso[1] = frameTemp[3];
		displayPeso[2] = frameTemp[4];
		displayPeso[3] = frameTemp[5];
		displayPeso[4] = frameTemp[6];
		displayPeso[5] = frameTemp[7];
		displayPeso[6] = frameTemp[8];
		trataBytesValidosPeso(&displayPeso[0]);
	}
}			
/////////////////////////////////////////////////////////////////////////////////
//Trata o frame recebido pela serial 1 para identificar o qual o protocolo		//
/////////////////////////////////////////////////////////////////////////////////
void funcLimpaDisplayPeso(void)	
{
	displayPeso[0] = ' ';
	displayPeso[1] = ' ';
	displayPeso[2] = ' ';
	displayPeso[3] = ' ';
	displayPeso[4] = ' ';
	displayPeso[5] = ' ';
	displayPeso[6] = ' ';	
}	
/////////////////////////////////////////////////////////////////////////////////
//metodo que captura o peso da balan�a recebido pela serial             		//
/////////////////////////////////////////////////////////////////////////////////
void getPesoIndicadorAscii(unsigned char*indexDestino)
{
    unsigned char *indexOrigem;
    unsigned char qtBytes;
    qtBytes = 7;
    indexOrigem = &displayPeso[0];
    while (qtBytes!= 0)
    {
        *indexDestino++ = *indexOrigem++; 
        qtBytes--;
    }           
}
/////////////////////////////////////////////////////////////////////////////////
//metodo que retorna o modelo do indicador de peso que esta transmitindo 		//
/////////////////////////////////////////////////////////////////////////////////
int getModeloIndicador(void)
{
    return modeloIndicador;
}
//////////////////////////////////////////////////////////////////////////////////		
//Verifica a validade do frame de peso processado 	                		  	//
//////////////////////////////////////////////////////////////////////////////////		
void verificaValidadeFramePeso(unsigned char *index)	
{
    unsigned char loop = 0;


    loop = 0;
    frameValido = 0;
	while (loop < 6)        
	{
        if ((*index == ',' ||*index == '.' ||(*index >= '0' && *index <= '9')|| *index == '-'|| *index == ' '|| *index == '+'|| *index == 0X6F))  
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

