    unsigned char temp1Array;
    unsigned char temp2Array;   
    unsigned char temp3Array;   
/////////////////////////////////////////////////////////////////////////////////		
//Fun��o converte valores inteiros para 2 bytes ascii           			  	//
//////////////////////////////////////////////////////////////////////////////////		
void inteiroTo3BytesAscii(unsigned int valorInteiro,unsigned char *indexArrayDestino)
{
    temp3Array = 0;
    temp2Array = 0;
    temp1Array = valorInteiro;
    while(temp1Array >= 10)
	{
        temp1Array  = temp1Array  - 10;
        temp2Array ++;
        if (temp2Array >=10)
        {
            temp2Array = 0;
            temp3Array++;
        }
    }
    *indexArrayDestino = temp3Array +'0';
    *indexArrayDestino++;
    *indexArrayDestino = temp2Array +'0'; 
    *indexArrayDestino++;
    *indexArrayDestino = temp1Array +'0';     
}
