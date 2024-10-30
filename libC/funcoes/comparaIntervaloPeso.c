#include "transfereArrayToArray.h"
#include "subtracaoValorArray.h"
#include "comparaValoresArray.h"
#include "somaValorArray.h"
//////////////////////////////////////////////////////////////////////////////////
//metodo utilizado para verificar se a balan�a esta estabilizada			 	//
//Tolerancia Superior: Especifica o quanto o peso da balan�a pode estar acima do// 
//peso alvo		 																//
//Tolerancia Inferior:Especifica o quanto o peso da balan�a pode estar abaixo do// 
//peso alvo		 																//															//
//Peso alvo: peso programado ou referencia de peso								// 
// o peso anterior mais tolerancia superior nem menor que o peso anterior da	//
// da balan�a - a tolerancia inferior											//
//Peso Balan�a Temp: Valor do peso atual da balan�a							//
//////////////////////////////////////////////////////////////////////////////////							
//Resultado: Resultado da fun��o												//
//Resultado = 0(peso da balan�a dentro da faixa de peso programado e tolerancia)//
//Resultado = 1(peso da balan�a abaixo do peso programado - tolerancia			//
//Resultado = 2(peso da balan�a acima do peso programdo + tolerancia			//

//variaveis utilizadas na fun��o												//
//////////////////////////////////////////////////////////////////////////////////							
 unsigned char resultadoFinal;
 unsigned char resultado_A;
 unsigned char resultado_B;
 unsigned char pesoDecimalTemp[9];
int comparaIntervaloPeso(unsigned char *pesoDecimalBalanca,unsigned char *pesoAlvo,unsigned char *toleranciaL,unsigned char *toleranciaH)
{
	resultado_A = 0;
	resultado_B = 0;
    resultadoFinal = 0;
// verifica se o peso da balan�a < peso alvo - tolerancia inferior
    transfereArrayToArray(9,pesoAlvo,&pesoDecimalTemp[0]);
    subtracaoValorArray(9,&pesoDecimalTemp[0],toleranciaL);    
	resultado_A = comparaValoresArray(9,&pesoDecimalTemp[0],pesoDecimalBalanca);
    
    transfereArrayToArray(9,pesoAlvo,&pesoDecimalTemp[0]);
    somaValorArray(9,&pesoDecimalTemp[0],toleranciaH);    
	resultado_B = comparaValoresArray(9,&pesoDecimalTemp[0],pesoDecimalBalanca);
    
 //peso da balan�a < peso alvo - tolerancia inferior  
	if (resultado_A == 1 && resultado_B == 1)
	{
		resultadoFinal = 0;
	}
 //peso da balan�a dentro
	if ((resultado_A == 2 || resultado_A == 0) && (resultado_B == 1 || resultado_B == 0))
	{
		resultadoFinal = 1;
	}
//peso da balan�a > peso alvo + tolerancia superior  
	if (resultado_A == 2 && resultado_B == 2)
	{
		resultadoFinal = 2;
	}		
	return resultadoFinal;
}
	
	