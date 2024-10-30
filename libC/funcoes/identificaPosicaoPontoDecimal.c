unsigned char posicaoPontoIdentificadaDecimal;
//////////////////////////////////////////////////////////////////////////////////
//Metodo utilizado para identifica��o do ponto decimal                  		//
//////////////////////////////////////////////////////////////////////////////////
int identificaPosicaoPontoDecimal(unsigned char *indexPosicaoPonto)
{
	posicaoPontoIdentificadaDecimal = 0;
    *indexPosicaoPonto--;
	if (*indexPosicaoPonto == '.'){posicaoPontoIdentificadaDecimal = 1;}
	*indexPosicaoPonto--;
	if (*indexPosicaoPonto == '.'){posicaoPontoIdentificadaDecimal = 2;}
	*indexPosicaoPonto--;
	if (*indexPosicaoPonto == '.'){posicaoPontoIdentificadaDecimal = 3;};
	*indexPosicaoPonto--;
	if (*indexPosicaoPonto == '.'){posicaoPontoIdentificadaDecimal = 4;};    
    return posicaoPontoIdentificadaDecimal;
}