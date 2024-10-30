unsigned char loopPosicaoPonto;
unsigned char tempConverte;
//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que transforma zero a esquerda em vazio    						  	//
/////////////////////////////////////////////////////////////////////////////////
void inserePontoDecimal(unsigned char posicaoPonto,unsigned char tamanhoArray,unsigned char *indexArrayDestino)
{
    if (posicaoPonto != 0)
    {
        if (posicaoPonto == 4){loopPosicaoPonto = tamanhoArray - 4;}
        if (posicaoPonto == 3){loopPosicaoPonto = tamanhoArray - 3;}
        if (posicaoPonto == 2){loopPosicaoPonto = tamanhoArray - 2;}            
        if (posicaoPonto == 1){loopPosicaoPonto = tamanhoArray - 1;}             
        while(loopPosicaoPonto!=0)
        {
            *indexArrayDestino++;
            tempConverte = *indexArrayDestino;
            *indexArrayDestino--;
            *indexArrayDestino = tempConverte; 
            loopPosicaoPonto--;
            *indexArrayDestino++;
        }
        *indexArrayDestino--;
        *indexArrayDestino = '.';
        *indexArrayDestino--;
	}	    
}