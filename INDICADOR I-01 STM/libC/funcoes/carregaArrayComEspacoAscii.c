//////////////////////////////////////////////////////////////////////////////////		
//Carrega registradores com espaço ascii                               	  	//
//////////////////////////////////////////////////////////////////////////////////	
void carregaArrayComEspacoAscii(unsigned char QuantidadeBytes,unsigned char*IndexApagaValores)
{
    while(QuantidadeBytes !=0)
    {
        *IndexApagaValores = ' ';
        *IndexApagaValores++;
        QuantidadeBytes--;
    }
}