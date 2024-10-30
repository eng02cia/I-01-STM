//////////////////////////////////////////////////////////////////////////////////
/*metodo utilizado para zerar a balan�a                                          */
//////////////////////////////////////////////////////////////////////////////////
void metodoFazZeroIndicadorPeso(void)
{
    if(fazZeroIndicadorPeso == 1 || fazTaraIndicadorPeso == 1)
    {
        tempTeclaControlZero = 0;
        if(fazZeroIndicadorPeso == 1){tempTeclaControlZero = checaAutorizaZeroIndicador();}
        if(tempTeclaControlZero == 0)
        {
            if(tempMediaCalibraIndicador != 0){tempMediaCalibraIndicador =  tempMediaCalibraIndicador + dataAdHx711;}
            else{tempMediaCalibraIndicador =  dataAdHx711;}
            ++loopMediaCalibracao;
            if(loopMediaCalibracao > 4)
            {
                tempMediaCalibraIndicador = tempMediaCalibraIndicador/loopMediaCalibracao;
                flagFazMediaAd = 0;
                loopMediaCalibracao = 0;
                if(fazZeroIndicadorPeso == 1)
                {
                    flagLimiteZeroInicial = 0;
                    valorZeroIndicadorMem.int32 = tempMediaCalibraIndicador;
                    tempMediaCalibraIndicador = 0;
                    valorZeroIndicador = valorZeroIndicadorMem.int32;
                    fazZeroIndicadorPeso = 0;
                    controleTipoZero = _CEMPORCENTO;
                    if(controleTara == _TARADESATIVADA){valorTaraIndicador = valorZeroIndicador;}
                     valorPesoAnteriorCargaViva = 0;
                     salvaValorAdZeroIndicadorMem();
                                   
                }
                if(fazTaraIndicadorPeso == 1)
                {
                    valorTaraIndicador = tempMediaCalibraIndicador;
                    tempMediaCalibraIndicador = 0;
                    fazTaraIndicadorPeso = 0;
                }
            }
        }
//cancela o zero da balan�a caso for capturado algum peso fora da faixa de zero        
        else
        {
            loopMediaCalibracao = 0;
            flagFazMediaAd = 0;
            tempMediaCalibraIndicador = 0;
            fazZeroIndicadorPeso = 0;
            fazTaraIndicadorPeso = 0;
            telaErroLimiteZero();
            controleTipoZero = _CEMPORCENTO;
        }
    }
}
