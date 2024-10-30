//////////////////////////////////////////////////////////////////////////////////
//faz a checagem para autorizar o zero do indicador                             //
//////////////////////////////////////////////////////////////////////////////////
int checaAutorizaZeroIndicador(void)
{
    unsigned char  tempErroZero;
    tempErroZero = 0;
    floatTemp = valorPesoCargaMaxima;
    floatTemp = floatTemp/100; 
// Limite de zero decimal limite de zero minimo de 0.1%  
    if (controleTipoZero == _MILPORCENTO)
    { 
        floatTemp = floatTemp * valorLimiteDeZeroMem;
        floatTemp = floatTemp/10;      
    }
// Limite de zero n�o decimal limite de zero minimo de 1%        
    if (controleTipoZero == _CEMPORCENTO)
    {   
        if (flagLimiteZeroInicial == 1){floatTemp = floatTemp * valorLimiteZeroInicial;}
        else{floatTemp = floatTemp * valorLimiteDeZeroMem;}
    } 
    float1Temp = floatTemp;
    float1Temp *= -1;
    if (valorPesoBrutoFloatIndicador <= floatTemp && valorPesoBrutoFloatIndicador >= float1Temp){tempErroZero = 0;}
    else{tempErroZero = 1;}
    return tempErroZero;
}
