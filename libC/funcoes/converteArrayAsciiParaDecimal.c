//////////////////////////////////////////////////////////////////////////////////		
//Transforma valores de um array de ascii para decimal                     	  	//
//////////////////////////////////////////////////////////////////////////////////	
void converteArrayAsciiParaDecimal (unsigned char QuantidadeBytes,unsigned char*IndexConverteValores)
{
    while(QuantidadeBytes !=0)
    {
//converte somente valores diferente  de ponto entre 0 e 9
        if (*IndexConverteValores >= '0' && *IndexConverteValores <= '9')
        {
            *IndexConverteValores = *IndexConverteValores - '0';
        }
        else
            if (*IndexConverteValores != ' ')
            {
                *IndexConverteValores = 0;
            }
//converte espa�o em zero
        if (*IndexConverteValores == ' ')
        {
            *IndexConverteValores = 0;
        }       
        
    *IndexConverteValores++;
    QuantidadeBytes --;
    }
}