//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que verifica se os valores de uma array s�o iguais a zero ascii  	//
//////////////////////////////////////////////////////////////////////////////////	
unsigned char tempComparaValores;
int verificaValorArrayIgualValorNegativo(unsigned char quantidadeBytes,unsigned char*indexComparaValores)
{
    tempComparaValores = 0;
    while(quantidadeBytes !=0)
    {
        if (*indexComparaValores == '-')
        {
           tempComparaValores = 1;
        }
        *indexComparaValores++;
        quantidadeBytes--;
    }
    return tempComparaValores;
}