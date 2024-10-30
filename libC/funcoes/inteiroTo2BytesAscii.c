static unsigned char temp1Array;
static unsigned char temp2Array;   
/////////////////////////////////////////////////////////////////////////////////		
//Função converte valores inteiros para 2 bytes ascii           			  	//
//////////////////////////////////////////////////////////////////////////////////		
void inteiroTo2BytesAscii(unsigned char valorInteiro,unsigned char *indexArrayDestino)
{
    temp1Array = valorInteiro;
    temp2Array = 0;
    while(temp1Array >= 10)
	{
        temp1Array  = temp1Array - 10;
        temp2Array ++;
    }
    *indexArrayDestino = temp2Array +'0';
    *indexArrayDestino++;
    *indexArrayDestino = temp1Array +'0';     
}