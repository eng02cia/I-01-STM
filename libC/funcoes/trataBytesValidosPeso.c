//////////////////////////////////////////////////////////////////////////////////		
//Fun��o que trata os bytes validos de peso      	                		  	//
//////////////////////////////////////////////////////////////////////////////////		
void trataBytesValidosPeso(unsigned char *indexOrigem)	
{
	unsigned char *index;
	unsigned char indicaPesoNegativo = 0;
    unsigned char loop = 0;

    index = indexOrigem;
//se h� virgula substitui ponto decimal 

	while (loop < 7)
	{
		loop ++;
		if (*index == ',')
		{	
			*index = '.';
		}			
		index++;
	}
//transforma zero a esquerda em vazio e identifica a exist�ncia do sinal negativo e concatena o sinal um byte antes do byte valido mais siginificativo
// loop no maximo = 6 para n�o apagar o ultimo zero
//caracteres que devera��o ser substuidos por espa�o 
// 0 ascii
// - tra�o ascii
// espa�o ascii
// + ascii
// 6F caracter de peso estabilizados EPM
    loop = 0;
	index = indexOrigem;
	while ((loop < 6)&& (*index == '0' || *index == '-'|| *index == ' '|| *index == '+'|| *index == 0X6F))
	{
		loop++;
		if (*index == '-')
		{
			indicaPesoNegativo = 1;
		}	
        *index = ' ';
		index++;
        
	}	
//verifica se o ultimo caracter valido e ponto decimal, se sim coloca zero a esquerda
	if (*index == '.')
	{
		index--;	
		*index = '0';
	}
//verifica se o peso � negativo, se for coloca sinal de negativo concatenado de forma correta		
	if	(indicaPesoNegativo == 1)
	{
		index--;
		*index = '-';
	}			
}
