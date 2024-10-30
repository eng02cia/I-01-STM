 unsigned char tempComparaConstanteComArray;
 unsigned char fimComparaConst;
//////////////////////////////////////////////////////////////////////////////////
//metodo que compara valores de uma constante com uma array                                  //
//Termo 0 da matriz o mais significativo                                        //
//Termo 1: variavelB (Valor Maior)                                              //
//Termo 2: variavelA (Valor Menor)                                               //
//variavelB = 0 Igual                                                               //
//variavelB = 1 Menor                                                               //
//variavelB = 2 Maior                                                               //
//////////////////////////////////////////////////////////////////////////////////
int comparaConstComArray (const char *variavelA, unsigned char *variavelB) 
{
    fimComparaConst = 0;
    tempComparaConstanteComArray = 0;
    while(fimComparaConst == 0)
    {
        if (*variavelB > *variavelA){tempComparaConstanteComArray = 2;}
        if (*variavelB < *variavelA){tempComparaConstanteComArray = 1;}
        *variavelB++;
        *variavelA++; 
        if (*variavelA == 0) {fimComparaConst = 1;}// se final do teste
        if (tempComparaConstanteComArray != 0){fimComparaConst = 1;}// se encontrado resultado
    }
	return tempComparaConstanteComArray;
}	