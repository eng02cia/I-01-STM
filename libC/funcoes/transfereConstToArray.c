//////////////////////////////////////////////////////////////////////////////////
//Fun��o utilizada para transferir const array para outra array na RAM        	//
//////////////////////////////////////////////////////////////////////////////////
unsigned char transfereConstToArray(const char *charOrigem,unsigned char*charDestino)
{
	 unsigned char qtBytes;
    qtBytes = 0;
    while (*charOrigem != 0) 
    {
        *charDestino = *charOrigem;
        charOrigem++;
        charDestino++; 
        qtBytes++; 
    }
    return qtBytes;
}
