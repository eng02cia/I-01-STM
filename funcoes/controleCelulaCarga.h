
///////////////////////////////////////////////////////////////////////////////
//funcoes de controle das medicoes da celula de carga                         	//
//////////////////////////////////////////////////////////////////////////////////
#include "transfereArrayToArray.h"
#include "carregaArrayComZeroAscii.h"
#include "verificaValorArrayIgualZeroAscii.h"
#include "verificaValorArrayIgualValorNegativo.h"
#include "inserePontoDecimal.h"
#include "zeroAsciiEsquerdaToVazioAscii.h"
#include "converteArrayAsciiParaDecimal.h"
#include "carregaArrayComZeroDecimal.h"
#include "converteArrayDecimalParaAscii.h"
#include "somaValorArray.h"
#include "comparaValoresArray.h"

//////////////////////////////////////////////////////////////////////////////////
//faz o tratamento da estabilidade do peso                                      //
//////////////////////////////////////////////////////////////////////////////////
void controlIndicacaoPesoEstavelLinhaI(void)
{
    /* controla a visualizacao do led de estabilidade do peso
    peso considerado estavel quando sem oscilacao por mais de 1,2 segundos. o inmetro permite um tempo de ate 2
    segundos sem oscilacao. */

    tempComparaCeluCarga = comparaValoresArray(7,&pesoConvertido[0],&referenciaPesoEstavelAscii[0]);
    if (tempComparaCeluCarga == 0 && flagIndicaPesoEstavel == 0)
    {
        if (++tempoIndicaPesoEstavel >= 12)
        {
            flagIndicaPesoEstavel = 1;
            tempoIndicaPesoEstavel = 0;
            HAL_GPIO_WritePin(led_pesoEstavel_GPIO_Port,led_pesoEstavel_Pin,GPIO_PIN_SET);
        }
    }
    else
    {
        if (tempComparaCeluCarga != 0)
        {
            transfereArrayToArray(7,&pesoConvertido[0],&referenciaPesoEstavelAscii[0]);
            flagIndicaPesoEstavel = 0;
            tempoIndicaPesoEstavel = 0;
            HAL_GPIO_WritePin(led_pesoEstavel_GPIO_Port,led_pesoEstavel_Pin,GPIO_PIN_RESET);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////
//tempo                                      //
//////////////////////////////////////////////////////////////////////////////////


/*
*passos para transformacao do peso
* 1- verificar se o peso nao esta saturado, se saturando tratar de forma diferente.
 *2- calcular o diferencial da celula de carga e usar a referencia de calibracao
 * para calcular o peso.
 *
 * dados importantes:
 * valor do Ad
 * valor de calibracao
 * carga maxima
 * valor de zero
*/
void mostraPesoIndicadorI01(void)
{
    dataAdMediaPronta = dataAdHx711;
    valorCorrigidoAd = valorZeroIndicador;
    valorCorrigidoAd = dataAdMediaPronta - valorCorrigidoAd;
    valorPesoTempIndicador = valorCorrigidoAd/valorDivisaoIndicador;
    fazArredondamentoPesoI01();

    trataPesoAdIndicadorI01();
    transfereArrayToArray(7,&arrayPesoTemp[0],&pesoCarregamentoAscii[0]);

//media do valor ad para ajudar na estabilidade
//filtro digital

    controleFiltroDigital = valorFiltroDigitalMem * 3;
    if (loopMediaAdPeso < controleFiltroDigital)
    {
        dataAdPeso = dataAdPeso + dataAdHx711;
        loopMediaAdPeso++;
    }
    else
    {
        loopMediaAdPeso++;
        dataAdPeso = dataAdPeso + dataAdHx711;
        dataAdPeso = dataAdPeso/loopMediaAdPeso;
        dataAdMediaPronta = dataAdPeso;
        dataAdPeso = 0;
        loopMediaAdPeso = 0;
    }
}
//////////////////////////////////////////////////////////////////////////////////
//faz o tratamento do peso bruto                                                //
//////////////////////////////////////////////////////////////////////////////////
void trataPesoBrutoIndicadorI01(void)
{
    valorCorrigidoAd = valorZeroIndicador;
    valorCorrigidoAd = dataAdMediaPronta - valorCorrigidoAd;
    valorPesoTempIndicador = valorCorrigidoAd/valorDivisaoIndicador;
    fazArredondamentoPesoI01();
    valorPesoBrutoFloatIndicador = valorPesoTempIndicador;
    trantandoPesoBruto = 1;
    
    trataPesoAdIndicadorI01();
    valorPesoBrutoIntIndicador = atol(arrayConverteToInteiro);
    transfereArrayToArray(7,&arrayPesoTemp[0],&pesoBrutoIndicadorAscii[0]);

    floatTemp = valorPesoCargaMaxima;
    floatTemp = valorPesoCargaMaxima + 9;
    statusControleSobreCarga  = 0;
    statusControleSubCarga = 0;

    floatTemp = valorPesoCargaMaxima + (degrauIndicadorMem * 9);
    if (valorPesoTempIndicador  >= floatTemp){statusControleSobreCarga = 1;}
//   floatTemp *=-1;
    float1Temp = (degrauIndicadorMem * 9);
    float1Temp *=-1;
    if (valorPesoTempIndicador  <= float1Temp){statusControleSubCarga = 1;}
    trantandoPesoBruto = 0;
    if (controleTara == _TARADESATIVADA)
    {
    	statusControleMostraPesoNegativo = statusPesoNegativoTemp;
    }
}
//////////////////////////////////////////////////////////////////////////////////
//faz o tratamento do peso tara                                               	//
//////////////////////////////////////////////////////////////////////////////////
void trataPesoTaraIndicadorI01(void)
{
    valorPesoTempIndicador = valorTaraIndicador - valorZeroIndicador;
    valorPesoTempIndicador = valorPesoTempIndicador/valorDivisaoIndicador;
    valorPesoTaraFloatIndicador = valorPesoTempIndicador;
    fazArredondamentoPesoI01();    
    trataPesoAdIndicadorI01();       
    valorPesoTaraIntIndicador = atol(arrayConverteToInteiro);
    transfereArrayToArray(7,&arrayPesoTemp[0],&pesoTaraIndicadorAscii[0]);
}
//////////////////////////////////////////////////////////////////////////////////
//faz o tratamento do peso liquido                                                //
//////////////////////////////////////////////////////////////////////////////////
void trataPesoLiquidoIndicadorI01(void)
{
    if (controleTara == _TARAATIVADA)
    {
        valorPesoTempIndicador = valorPesoBrutoFloatIndicador - valorPesoTaraFloatIndicador;
        valorPesoLiquidoFloatIndicador = valorPesoTempIndicador;
        valorPesoTempIndicador = (int)(valorPesoBrutoIntIndicador - valorPesoTaraIntIndicador);
    }
    else
    {
        valorPesoTempIndicador = 0;
        valorTaraIndicador = valorZeroIndicador;
    }
    fazArredondamentoPesoI01();
    
    valorPesoTESTE1 = valorPesoTempIndicador;

    trataPesoAdIndicadorI01();
    valorPesoLiquidoIntIndicador = atol(arrayConverteToInteiro);  
    transfereArrayToArray(7,&arrayPesoTemp[0],&pesoLiquidoIndicadorAscii[0]);
    if (controleTara == _TARAATIVADA)
    {
    	statusControleMostraPesoNegativo = statusPesoNegativoTemp;
    }
}
//////////////////////////////////////////////////////////////////////////////////
//faz o tratamento do peso recebido pela celula de carga                        //
//////////////////////////////////////////////////////////////////////////////////
void trataPesoAdIndicadorI01(void)
{
//transforma zero negativo em zero
    f = valorPesoTempIndicador;
    buf = ftoa();
    loopConvertePesoCelulaCarga = 0;
//transoforma valor float em array de peso
    while (loopConvertePesoCelulaCarga < 9)
    {
        arrayPesoConvertidoCelulaCarga[loopConvertePesoCelulaCarga] = *buf;
        buf++;
        loopConvertePesoCelulaCarga++;
    }
//carrega peso convertido
    carregaArrayComZeroDecimal(7,&arrayPesoTemp[0]);

    index2Indicador = &arrayPesoTemp[0];
    index1Indicador = &arrayPesoConvertidoCelulaCarga[0];
    loopConvertePesoCelulaCarga = 0;

    while (loopConvertePesoCelulaCarga != 7)
    {
        *index2Indicador = *index1Indicador;
        index1Indicador++;
        index2Indicador++;
        loopConvertePesoCelulaCarga++;
        if (*index1Indicador == '.'){loopConvertePesoCelulaCarga = 7;}
    }   

//faz correcao da array de peso
    index1Indicador = &arrayPesoTemp[6];
    while (*index1Indicador == 0)
    {
        arrayPesoTemp[6] = arrayPesoTemp[5];
        arrayPesoTemp[5] = arrayPesoTemp[4];
        arrayPesoTemp[4] = arrayPesoTemp[3];
        arrayPesoTemp[3] = arrayPesoTemp[2];
        arrayPesoTemp[2] = arrayPesoTemp[1];
        arrayPesoTemp[1] = arrayPesoTemp[0];
        arrayPesoTemp[0] = '0';
    }

// trata peso quando negativo
    statusPesoNegativoTemp = 0;
    index1Indicador = &arrayPesoTemp[6];
    loopTempIndicador = 7;
    while (loopTempIndicador != 0)
    {
        if (*index1Indicador == '-')
        {
           statusPesoNegativoTemp = 1;
           *index1Indicador = '0';
           loopTempIndicador = 1;
        }
        *index1Indicador--;
        loopTempIndicador--;
    }
//faz tratamento do degrau do peso
    converteArrayAsciiParaDecimal(7,&arrayPesoTemp[0]);
    carregaArrayComZeroDecimal(7,&arrayPesoTemp1[0]);
    if (degrauIndicadorMem == 2)
    {
        if (arrayPesoTemp[6] == 1){arrayPesoTemp[6] = 2;}
        if (arrayPesoTemp[6] == 3){arrayPesoTemp[6] = 4;}
        if (arrayPesoTemp[6] == 5){arrayPesoTemp[6] = 6;}
        if (arrayPesoTemp[6] == 7){arrayPesoTemp[6] = 8;}
        if (arrayPesoTemp[6] == 9)
        {
            arrayPesoTemp[6] = 0;
            arrayPesoTemp1[5] = 1;
            somaValorArray(6,&arrayPesoTemp[0],&arrayPesoTemp1[0]);
        }
    }
    if (degrauIndicadorMem == 5)
    {
        if (arrayPesoTemp[6] >= 0 && arrayPesoTemp[6] <= 2){arrayPesoTemp[6] = 0;}
        if (arrayPesoTemp[6] >= 3 && arrayPesoTemp[6] <= 7){arrayPesoTemp[6] = 5;}
        if (arrayPesoTemp[6] >= 8 && arrayPesoTemp[6] <= 9)
        {
            arrayPesoTemp[6] = 0;
            arrayPesoTemp1[5] = 1;
            somaValorArray(6,&arrayPesoTemp[0],&arrayPesoTemp1[0]);
        }
    }
    if (degrauIndicadorMem == 10)
    {
        if (arrayPesoTemp[6] >= 5)
        {
            arrayPesoTemp[6] = 0;
            arrayPesoTemp1[5] = 1;
            somaValorArray(6,&arrayPesoTemp[0],&arrayPesoTemp1[0]);
        }
        else
        {
            arrayPesoTemp[6] = 0;
        }
    }
    if (degrauIndicadorMem == 20)
    {
        arrayPesoTemp[6]= 0;
        if (arrayPesoTemp[5] == 1){arrayPesoTemp[5] = 2;}
        if (arrayPesoTemp[5] == 3){arrayPesoTemp[5] = 4;}
        if (arrayPesoTemp[5] == 5){arrayPesoTemp[5] = 6;}
        if (arrayPesoTemp[5] == 7){arrayPesoTemp[5] = 8;}
        if (arrayPesoTemp[5] == 9)
        {
            arrayPesoTemp[5] = 0;
            arrayPesoTemp1[4] = 1;
            somaValorArray(6,&arrayPesoTemp[0],&arrayPesoTemp1[0]);
        }
    }
    converteArrayDecimalParaAscii(7,&arrayPesoTemp[0]);
    carregaArrayComZeroDecimal(8,&arrayConverteToInteiro[0]);
    transfereArrayToArray(7,&arrayPesoTemp[0],&arrayConverteToInteiro[0]);

// finaliza tratamento do peso
//verifica se peso igual a zero
    if (trantandoPesoBruto == 1){ indicadorEmZero = 0;}
    tempControleCelulaCarga = verificaValorArrayIgualZeroAscii(7,&arrayPesoTemp[0]);
    if (tempControleCelulaCarga == 0)
    {
        carregaArrayComZeroAscii(7,&arrayPesoTemp[0]);
        if (trantandoPesoBruto == 1){indicadorEmZero = 1;}
        statusPesoNegativoTemp = 0;
    }
    if (posicaoPontoDecimalIndicadorMem != 0){inserePontoDecimal(posicaoPontoDecimalIndicadorMem,7,&arrayPesoTemp[0]);}
    zeroAsciiEsquerdaToVazioAscii(7,&arrayPesoTemp[0]);
//insere traco quando peso negativo
   if (statusPesoNegativoTemp == 1)
   {
        index1Indicador = &arrayPesoTemp[6];
        loopTempIndicador = 7;
        while (loopTempIndicador != 0)
        {
            if (*index1Indicador == ' ')
            {
                *index1Indicador = '-';
                loopTempIndicador = 1;
            }
            *index1Indicador--;
            loopTempIndicador--;
        }
   }
}
//////////////////////////////////////////////////////////////////////////////////
//faz  com arredondamento quando peso negativo e qaundo peso positivo           //
//////////////////////////////////////////////////////////////////////////////////
void fazArredondamentoPesoI01(void)
{
    if (valorPesoTempIndicador < 0)
    {
        floatTemp1 = valorPesoTempIndicador;
        floatTemp1 *= -1;
        tempLongInt = floatTemp1;
        floatTemp1 = floatTemp1 - tempLongInt;
       if (floatTemp1 >= 0.55){valorPesoTempIndicador = valorPesoTempIndicador - 1;}
    }
    else
    {
        floatTemp1 = valorPesoTempIndicador;
        tempLongInt = floatTemp1;
        floatTemp1 = floatTemp1 - tempLongInt;
        if (floatTemp1 >= 0.55){valorPesoTempIndicador = valorPesoTempIndicador + 1;}
    }
}
