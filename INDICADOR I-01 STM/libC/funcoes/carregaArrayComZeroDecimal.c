//////////////////////////////////////////////////////////////////////////////////		
//Carrega registradores com zero decimal                                  	//
//////////////////////////////////////////////////////////////////////////////////	
void carregaArrayComZeroDecimal(unsigned int quantidadeBytes,unsigned char*indexApagaValores)
{
    while(quantidadeBytes !=0)
    {
        *indexApagaValores = 0;
        *indexApagaValores++;
        quantidadeBytes--;
    }
}