
///////////////////////////////////////////////////////////////////////////////
//funções de controle das medições da celula de carga                         	//
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
/*
*passos para transformação do peso
* 1- verificar se o peso não esta saturado, se saturando tratar de forma diferente.
 *2- calcular o diferencial da celula de carga e usar a referencia de calibração
 * para calcular o peso.
 *
 * dados importantes:
 * valor do Ad
 * valor de calibração
 * carga maxima
 * valor de zero

*/
void inicializaLedsIndicador(void)
{

}
void mostraPesoIndicador(void)
{
//////////////////////////////////////////////////////////////////////////////////
 // captura o peso sem filtro digital, peso sem filtro utilizado na             //
 // pesagem das peças de couro                                                  //
//////////////////////////////////////////////////////////////////////////////////
//verifica qual divisão utilizar no calculo do peso
#ifdef _indicadorCurturme
    if (dataAdMediaPronta < valorPeso_1FloatMem.float32)
    {
        if (valorDivisao_1IndicadorMem.float32 == 0)
        {
            valorDivisaoIndicador = valorDivisao_2IndicadorMem.float32;
            offSetPesoAtual = offSetFaixaPeso_2Mem;
        }
        else
        {
            valorDivisaoIndicador = valorDivisao_1IndicadorMem.float32;
            offSetPesoAtual = offSetFaixaPeso_1Mem;
        }
    }
    else
    {
        if (valorDivisao_2IndicadorMem.float32 == 0)
        {
            valorDivisaoIndicador = valorDivisao_1IndicadorMem.float32;
            offSetPesoAtual = offSetFaixaPeso_1Mem;
        }
        else
        {
            valorDivisaoIndicador = valorDivisao_2IndicadorMem.float32;
            offSetPesoAtual = offSetFaixaPeso_2Mem;
        }
    }
    dataAdMediaPronta = dataAdHx711;
    valorCorrigidoAd = valorZeroIndicador;
    valorCorrigidoAd = dataAdMediaPronta - valorCorrigidoAd;
    valorPesoTempIndicador = valorCorrigidoAd/valorDivisaoIndicador;
    fazArredondamentoPeso();
    valorPesoBrutoCarregamento = valorPesoTempIndicador;
    if (valorPesoTempIndicador > 30)
    {
        valorPesoBrutoCarregamento = valorPesoBrutoCarregamento + offSetTempPesoAtual;
    }
    trataPesoAdIndicador();
    transfereArrayToArray(7,&arrayPesoTemp[0],&pesoCarregamentoAscii[0]);
#endif
//media do valor ad para ajudar na estabilidade
//filtro digital

controleFiltroDigital = valorFiltroDigitalMem;
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
void trataPesoBrutoIndicador(void)
{
    valorCorrigidoAd = valorZeroIndicador;
    valorCorrigidoAd = dataAdMediaPronta - valorCorrigidoAd;
    valorPesoTempIndicador = valorCorrigidoAd/valorDivisaoIndicador;
#ifdef _indicadorCurturme
    if (valorPesoTempIndicador > 30)
    {
        offSetTempPesoAtual = 0;
        if (offSetPesoAtual > 15){offSetTempPesoAtual = offSetPesoAtual - 15;}
        if (offSetPesoAtual < 15)
        {
            offSetTempPesoAtual = 15 - offSetPesoAtual;
            offSetTempPesoAtual *= -1;
        }
    }
    if (valorPesoTempIndicador > 30)
    {
        valorPesoTempIndicador = valorPesoTempIndicador + offSetTempPesoAtual;
    }
#endif
    fazArredondamentoPeso();
    valorPesoBrutoFloatIndicador = valorPesoTempIndicador;
    trantandoPesoBruto = 1;
    trataPesoAdIndicador();
    valorPesoBrutoIntIndicador = atol(arrayConverteToInteiro);
    transfereArrayToArray(7,&arrayPesoTemp[0],&pesoBrutoIndicadorAscii[0]);

    floatTemp = valorPesoCargaMaxima;
    statusControleSobreCarga  = 0;
    statusControleSubCarga = 0;
    if (valorPesoTempIndicador  >= floatTemp){statusControleSobreCarga = 1;}
    floatTemp *=-1;
    if (valorPesoTempIndicador  <= floatTemp){statusControleSubCarga = 1;}
    trantandoPesoBruto = 0;
    // statusMostraPesoNegativo = statusPesoNegativoTemp;
}
//////////////////////////////////////////////////////////////////////////////////
//faz o tratamento do peso tara                                               //
//////////////////////////////////////////////////////////////////////////////////
void trataPesoTaraIndicador(void)
{
    valorPesoTempIndicador = valorTaraIndicador - valorZeroIndicador;
    valorPesoTempIndicador = valorPesoTempIndicador/valorDivisaoIndicador;
    valorPesoTaraFloatIndicador = valorPesoTempIndicador;
    fazArredondamentoPeso();
    trataPesoAdIndicador();
    valorPesoTaraIntIndicador = atol(arrayConverteToInteiro);
    transfereArrayToArray(7,&arrayPesoTemp[0],&pesoTaraIndicadorAscii[0]);
}
//////////////////////////////////////////////////////////////////////////////////
//faz o tratamento do peso liquido                                                //
//////////////////////////////////////////////////////////////////////////////////
void trataPesoLiquidoIndicador(void)
{
    if (controleTara == _TARAATIVADA)
    {
        valorPesoTempIndicador = valorPesoBrutoFloatIndicador - valorPesoTaraFloatIndicador;
        valorPesoLiquidoFloatIndicador = valorPesoTempIndicador;
    }
    else
    {
        valorPesoTempIndicador = 0;
        valorTaraIndicador = valorZeroIndicador;
    }
    fazArredondamentoPeso();
    trataPesoAdIndicador();
    valorPesoLiquidoIntIndicador = atol(arrayConverteToInteiro);  
    transfereArrayToArray(7,&arrayPesoTemp[0],&pesoLiquidoIndicadorAscii[0]);
}
//////////////////////////////////////////////////////////////////////////////////
//faz o tratamento do peso recebido pela celula de carga                        //
//////////////////////////////////////////////////////////////////////////////////
void trataPesoAdIndicador(void)
{
//transforma zero negativo em zero
//    tempLongInt = valorPesoTempIndicador;
//    if (tempLongInt == 0){valorPesoTempIndicador = 0;}
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
//faz correção da array de peso
    index1Indicador = &arrayPesoTemp[6];
    while(*index1Indicador == 0)
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
    statusPesoNegativo = 0;
    index1Indicador = &arrayPesoTemp[6];
    loopTempIndicador = 7;
    while(loopTempIndicador !=0)
    {
        if (*index1Indicador == '-')
        {
           statusPesoNegativo = 1;
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
        statusPesoNegativo = 0;
    }
    if (posicaoPontoDecimalIndicadorMem != 0){inserePontoDecimal(posicaoPontoDecimalIndicadorMem,7,&arrayPesoTemp[0]);}
    zeroAsciiEsquerdaToVazioAscii(7,&arrayPesoTemp[0]);
//insere traço quando peso negativo
   if (statusPesoNegativo == 1)
   {
        index1Indicador = &arrayPesoTemp[6];
        loopTempIndicador = 7;
        while(loopTempIndicador !=0)
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
void fazArredondamentoPeso(void)
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
