//////////////////////////////////////////////////////////////////////////////////
//metodo utilizado na tranferencia de array para array                   		//
//////////////////////////////////////////////////////////////////////////////////
void transfereArrayToArrayInvertido(unsigned char qtBytes,unsigned char *indexOrigem,unsigned char *indexDestino)
{
    while (qtBytes!= 0)
    {
        *indexDestino++ = *indexOrigem--;
        qtBytes--;
    }       
}
