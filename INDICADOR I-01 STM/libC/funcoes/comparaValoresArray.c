 unsigned char tempComparaValorArray;
//////////////////////////////////////////////////////////////////////////////////
//metodo que compara valores (arrays de peso)                                   //
//Termo 0 da matriz o mais significativo                                        //
//Termo 1: variavelB (Valor Maior)                                              //
//Termo 2: variavelA (Valor Menor)                                               //
//variavelB = 0 Igual                                                               //
//variavelB = 1 Menor                                                               //
//variavelB = 2 Maior                                                               //
//////////////////////////////////////////////////////////////////////////////////
unsigned char comparaValoresArray(unsigned char qtBytes,unsigned char *variavelA, unsigned char *variavelB) 
{
    tempComparaValorArray = 0;
    while(qtBytes != 0)
    {
        if (*variavelB > *variavelA){tempComparaValorArray = 2;}
        if (*variavelB < *variavelA){tempComparaValorArray = 1;}
        *variavelB++;
        *variavelA++; 
        if(tempComparaValorArray == 0){qtBytes--;}
        else{qtBytes = 0;}
    }
	return tempComparaValorArray;
}	