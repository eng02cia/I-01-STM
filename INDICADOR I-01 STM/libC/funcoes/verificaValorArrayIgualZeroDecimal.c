//////////////////////////////////////////////////////////////////////////////////		
//Função que verifica se os valores de uma array são iguais a zero decimal    	//
//////////////////////////////////////////////////////////////////////////////////	
unsigned char verificaValorArrayIgualZeroDecimal(unsigned char quantidadeBytes,unsigned char*indexComparaValores)
{
unsigned char tempComparaValores = 0;
    while(quantidadeBytes !=0)
    {
        if(*indexComparaValores != 0)
        {
           tempComparaValores = 1;
        }
        *indexComparaValores++;
        quantidadeBytes--;
    }
    return tempComparaValores;
}