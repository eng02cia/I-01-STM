//////////////////////////////////////////////////////////////////////////////////		
//Transforma valores de um array de decimal para ascii                     	  	//
//////////////////////////////////////////////////////////////////////////////////	
void converteArrayDecimalParaAscii(unsigned char quantidadeBytes,unsigned char*indexConverteValores)
{
    while(quantidadeBytes !=0)
    {
        if (*indexConverteValores != '.')
        {
            *indexConverteValores = *indexConverteValores + '0';
        }
        indexConverteValores++;
        quantidadeBytes--;
    }
}