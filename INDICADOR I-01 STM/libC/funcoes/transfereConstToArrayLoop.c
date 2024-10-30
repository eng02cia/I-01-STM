//////////////////////////////////////////////////////////////////////////////////
//Fun��o utilizada para transferir const array para outra array na RAM        	//
//////////////////////////////////////////////////////////////////////////////////
void transfereConstToArrayLoop(unsigned int quantidadetransferencia, const char *indexArrayOrigem, unsigned char *indexArrayDestino)
{
    while (quantidadetransferencia != 0)
    {
        *indexArrayDestino++ =  *indexArrayOrigem++; 
        quantidadetransferencia--;
    }       
}
