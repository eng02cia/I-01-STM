#include "comparaValoresArray.h"
#include "transfereArrayToArray.h"
//////////////////////////////////////////////////////////////////////////////////
/*metodo utilizado para controlar o back light quando o peso oscila             */
//////////////////////////////////////////////////////////////////////////////////
void controlaBackLightOscilaPeso(void)
{
    if( modoFuncionamentoBackLightMem == _BACKLIGHT_TEMPORIZADO)
    {
        if(controleTara ==_TARADESATIVADA)
        {
            tempPesoBackLight = comparaValoresArray(7,&pesoBrutoIndicadorAscii[0],&arrayPesoBackLight[0]);
            if(tempPesoBackLight != 0)
            {
                transfereArrayToArray(7,&pesoBrutoIndicadorAscii[0],&arrayPesoBackLight[0]);
                HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_SET);
                tempoBacklightLigado = 0;
                flagTempoExibeBackLight = 1;
            }
        }
        else
        {
            tempPesoBackLight = comparaValoresArray(7,&pesoLiquidoIndicadorAscii[0],&arrayPesoBackLight[0]);
            if(tempPesoBackLight != 0)
            {
                transfereArrayToArray(7,&pesoLiquidoIndicadorAscii[0],&arrayPesoBackLight[0]);
                HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_SET);
                tempoBacklightLigado = 0;
               flagTempoExibeBackLight = 1;
            }
        }
    } 
}
