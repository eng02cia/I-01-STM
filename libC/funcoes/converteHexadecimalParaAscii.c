//////////////////////////////////////////////////////////////////////////////////		
//Transforma valores hexadecimal para ascii                             	  	//
//////////////////////////////////////////////////////////////////////////////////	
void converteHexadecimalParaAscii(unsigned char valorHexadecimal,unsigned char*indexDestinoConversao)
{
    unsigned char rtempArray = 0;
    unsigned char rtemp1Array = 0;
    while(valorHexadecimal >= 16)
    {
        valorHexadecimal = valorHexadecimal - 0x10;
        rtemp1Array++;
    }
    rtempArray = valorHexadecimal;
    if (rtemp1Array <= 9)
    {
        *indexDestinoConversao = rtemp1Array + '0';        
    }
    else
    {
        rtemp1Array = rtemp1Array - 0x0A;
        *indexDestinoConversao = rtemp1Array + 'A'; 
    }
    indexDestinoConversao++;
    if (rtempArray <= 9)
    {
        *indexDestinoConversao = rtempArray + '0';        
    }
    else
    {
        rtempArray  = rtempArray - 0x0A;
        *indexDestinoConversao = rtempArray + 'A'; 
    }   
}