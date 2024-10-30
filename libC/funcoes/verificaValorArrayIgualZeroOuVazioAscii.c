//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que verifica se os valores de uma array s�o iguais a zero ascii  	//
//////////////////////////////////////////////////////////////////////////////////	

int verificaValorArrayIgualZeroOuVazioAscii(unsigned char quantidadeBytes,unsigned char*indexComparaValores)
{
	unsigned char tempComparaValores;
    tempComparaValores = 0;
    while(quantidadeBytes !=0)
    {
        if (*indexComparaValores != '0'&& *indexComparaValores != ' ')
        {
           tempComparaValores = 1;
        }
        *indexComparaValores++;
        quantidadeBytes--;
    }
    return tempComparaValores;
}
