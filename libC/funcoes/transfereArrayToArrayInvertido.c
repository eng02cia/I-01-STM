//////////////////////////////////////////////////////////////////////////////////
//metodo utilizado na tranferencia de array para array                   		//
//////////////////////////////////////////////////////////////////////////////////
void transfereArrayToArrayInvertido(unsigned int qtBytes,unsigned int *indexOrigem,unsigned int *indexDestino)
{
    while (qtBytes!= 0)
    {
        *indexDestino++ = *indexOrigem--;
        qtBytes--;
    }       
}
