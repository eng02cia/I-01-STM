#include "subtracaoValorArray.h"
//////////////////////////////////////////////////////////////////////////////////
//metodo que faz a subtra��o de duas grandezas (arrays de peso)				 	//
//Termo 0 da matriz o mais significativo										//
//Minuendo:(maior valor)            											//
//Subtraendo: (menor valor)         											//
//Resultado: Minuendo   														//
//////////////////////////////////////////////////////////////////////////////////
void subtracaoValorArray(unsigned char qtSubutracao,unsigned char *indexMinuendo,unsigned char *indexSubtraendo)
{
    unsigned char qtLoopEmprestivo = 0;
    unsigned char emprestimo = 0;
    unsigned char *indexTemp;
    indexMinuendo = indexMinuendo + qtSubutracao - 1;
    indexSubtraendo = indexSubtraendo + qtSubutracao - 1;
    while(qtSubutracao != 0)
    {        
        qtSubutracao--;
        *indexMinuendo = *indexMinuendo - *indexSubtraendo;	
        if (*indexMinuendo > 240)
        {
            *indexMinuendo = *indexMinuendo + 10; 
            qtLoopEmprestivo = qtSubutracao;
            indexMinuendo--;
            indexTemp = indexMinuendo;
            while(qtLoopEmprestivo!= 0)
            {
                qtLoopEmprestivo--;
                if (*indexMinuendo == 0)
                {
                    *indexMinuendo = 9;    
                    indexMinuendo--;   
                }
                else
                {
                    *indexMinuendo = *indexMinuendo - 1;
                    qtLoopEmprestivo = 0;
                    indexMinuendo++;   
                }
            }
            indexMinuendo = indexTemp + 1;
        }
        indexMinuendo--;
        indexSubtraendo--;    
	}
}
