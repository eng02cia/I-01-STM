//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que transforma zero a esquerda em vazio    						  	//
//////////////////////////////////////////////////////////////////////////////////	
void zeroAsciiEsquerdaToVazioAscii(unsigned char quantidadeBytes,unsigned char*indexConverteValores)
{
unsigned char fimTransformacao;
   fimTransformacao = 0;
    while(fimTransformacao == 0)    
    {
        if (*indexConverteValores == '0'||*indexConverteValores == ' ')
        {
            *indexConverteValores = ' ';
        }
        else
        {
            fimTransformacao = 1;  
        }
        quantidadeBytes --;        
        if (fimTransformacao != 1)
        {
            *indexConverteValores++;
            if (*indexConverteValores == '.' || *indexConverteValores ==',')
            { 
                *indexConverteValores--;
                *indexConverteValores = '0';
                fimTransformacao = 1;
            }
        } 
        if (quantidadeBytes == 1)
        {
            fimTransformacao = 1;
        }        
    }
}