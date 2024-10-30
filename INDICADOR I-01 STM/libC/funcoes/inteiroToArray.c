//////////////////////////////////////////////////////////////////////////////////		
//Função converte valores inteiros para para 6 bytes ascii					  	//
//////////////////////////////////////////////////////////////////////////////////		
int inteiroToArray(unsigned int rtempArray,unsigned char *indexDestino)
{
    unsigned char qtDigitos;
    unsigned char zeroEsquerdatratado = 0;
    unsigned char rtemp1Array = 0;
    unsigned char rtemp2Array = 0;
    unsigned char rtemp3Array = 0;
    unsigned char rtemp4Array = 0;
    unsigned char rtemp5Array = 0;
    unsigned char rtemp6Array = 0;

    while(rtempArray >= 10)
	{
        rtempArray  = rtempArray  - 10;
        rtemp1Array ++;
        if(rtemp1Array >=10)
        {
            rtemp1Array = 0;
            rtemp2Array++;
        }
        if(rtemp2Array >=10)
        {
            rtemp2Array = 0;
            rtemp3Array++;
        }
        if(rtemp3Array >=10)
        {
            rtemp3Array = 0;
            rtemp4Array++;
        }
        if(rtemp4Array >=10)
        {
            rtemp4Array = 0;
            rtemp5Array++;
        }
    }
////////////////////////////////////////////////////////////////////////////////    
    if(zeroEsquerdatratado == 0)
    {
        if(rtemp5Array!=0)
        {
            *indexDestino++ = rtemp5Array +'0';
            qtDigitos = 6;
            zeroEsquerdatratado = 1;
        }  
    }
    else
    {
        *indexDestino++ = rtemp5Array +'0';        
    }
////////////////////////////////////////////////////////////////////////////////    
    if(zeroEsquerdatratado == 0)
    {
        if(rtemp4Array!=0)
        {
            *indexDestino++ = rtemp4Array +'0';
            qtDigitos = 5;
            zeroEsquerdatratado = 1;
        }  
    }
    else
    {
        *indexDestino++ = rtemp4Array +'0';        
    }
////////////////////////////////////////////////////////////////////////////////    
    if(zeroEsquerdatratado == 0)
    {
        if(rtemp3Array!=0)
        {
            *indexDestino++ = rtemp3Array +'0';
            qtDigitos = 4;
            zeroEsquerdatratado = 1;
        }  
    }
    else
    {
        *indexDestino++ = rtemp3Array +'0';        
    }    
////////////////////////////////////////////////////////////////////////////////    
    if(zeroEsquerdatratado == 0)
    {
        if(rtemp2Array!=0)
        {
            *indexDestino++ = rtemp2Array +'0';
            qtDigitos = 3;
            zeroEsquerdatratado = 1;
        }  
    }
    else
    {
        *indexDestino++ = rtemp2Array +'0';        
    }        
////////////////////////////////////////////////////////////////////////////////    
    if(zeroEsquerdatratado == 0)
    {
        if(rtemp1Array!=0)
        {
            *indexDestino++ = rtemp1Array +'0';
            qtDigitos = 2;
            zeroEsquerdatratado = 1;
        }  
    }
    else
    {
        *indexDestino++ = rtemp1Array +'0';        
    }            
////////////////////////////////////////////////////////////////////////////////    
    if(zeroEsquerdatratado == 0)
    {
        if(rtempArray!=0)
        {
            *indexDestino++ = rtempArray +'0';
            qtDigitos = 2;
            zeroEsquerdatratado = 1;
        }  
    }
    else
    {
        *indexDestino++ = rtempArray +'0';        
    }                    
    return qtDigitos;
}