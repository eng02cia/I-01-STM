//////////////////////////////////////////////////////////////////////////////////		
//Carrega registradores com zero decimal                                        //
//////////////////////////////////////////////////////////////////////////////////	
void carregaArrayComZeroAscii(unsigned char QuantidadeBytes,unsigned char*IndexApagaValores)
{
    while(QuantidadeBytes !=0)
    {
        *IndexApagaValores = '0';
        *IndexApagaValores++;
        QuantidadeBytes--;
    }
}