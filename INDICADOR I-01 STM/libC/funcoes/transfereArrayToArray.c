//////////////////////////////////////////////////////////////////////////////////
//metodo utilizado na tranferencia de array para array                   		//
//////////////////////////////////////////////////////////////////////////////////
void transfereArrayToArray(unsigned int qtBytes,unsigned char *indexOrigem,unsigned char *indexDestino)
{
    while (qtBytes!= 0)
    {
        *indexDestino++ = *indexOrigem++; 
        qtBytes--;
    }       
}
