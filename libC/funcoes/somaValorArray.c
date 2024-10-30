
//////////////////////////////////////////////////////////////////////////////////
//metodo que faz a soma de duas grandezas (arrays de peso)					 	//
//Termo 0 da matriz o mais significativo										//
//Parcela 1:(maior valor)            											//
//Parcela 2: (menor valor)          											//
//Total: Parcela 1													     		//
//////////////////////////////////////////////////////////////////////////////////
void somaValorArray(unsigned char qtSoma,unsigned char *indexParcela_1,unsigned char *indexParcela_2)
{	
    unsigned char restoSoma;
    restoSoma = 0;
    indexParcela_1 = indexParcela_1 + qtSoma - 1;
    indexParcela_2 = indexParcela_2 + qtSoma - 1;    
    while(qtSoma != 0)
    {        
        qtSoma--;
        *indexParcela_1 = *indexParcela_1 + *indexParcela_2;	
        if (*indexParcela_1 > 9)
        {
            *indexParcela_1 = *indexParcela_1 - 10;  
            restoSoma = 1;
        }
        indexParcela_1--;
        indexParcela_2--;
        if (restoSoma == 1)
        {
            *indexParcela_1 = *indexParcela_1 + 1; 
            restoSoma = 0;
        }        
    }
}