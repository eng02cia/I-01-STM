//////////////////////////////////////////////////////////////////////////////////		
//Função que verifica se os valores de uma array são iguais a zero ascii  	//
//////////////////////////////////////////////////////////////////////////////////	
unsigned char tempComparaValores;
unsigned char verificaValorArrayIgualZeroAscii(unsigned char quantidadeBytes,unsigned char*indexComparaValores)
{
    tempComparaValores = 0;
    while(quantidadeBytes !=0)
    {
        if(*indexComparaValores != '0')
        {
           tempComparaValores = 1;
        }
        *indexComparaValores++;
        quantidadeBytes--;
    }
    return tempComparaValores;
}