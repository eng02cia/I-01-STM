//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que verifica se os valores de uma array s�o iguais a espa�o ascii    	//
//////////////////////////////////////////////////////////////////////////////////	
int verificaValorArrayIgualEspacoAscii(unsigned char quantidadeBytes,unsigned char*indexComparaValores)
{
unsigned char tempComparaValores = 0;
    while(quantidadeBytes !=0)
    {
        if (*indexComparaValores != ' ')
        {
           tempComparaValores = 1;
        }
        *indexComparaValores++;
        quantidadeBytes--;
    }
    return tempComparaValores;
}