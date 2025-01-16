#include "transfereArrayToArrayInvertido.h"
//////////////////////////////////////////////////////////////////////////////////		
//funcao que carrega os valores da memoria intena modbus para ser transmitida   //	
//////////////////////////////////////////////////////////////////////////////////
void funcaoValoresTxModBusRtu(unsigned char qtBytesTx,unsigned char*origem,unsigned char *destino)
{
    while (qtBytesTx != 0)
    {
        *destino = *origem;
        destino++;
        origem++; 
        qtBytesTx--;
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//      funcoes de interligacao da modbus com a memoria do indicador      		//	
//////////////////////////////////////////////////////////////////////////////////
void funcaoLeituraDadosMemoriaModBusRtu(void)
{
//prepara peso no display arrayMemoriaModbusRtu[0]
    if (controleTara ==  _TARADESATIVADA)
    {
        tempPesoFloatModBus = valorPesoBrutoFloatIndicador;
        tempLongIntPesoModBus = valorPesoBrutoIntIndicador;
        transformaPesoParaPadraoModbus();
        transfereArrayToArrayInvertido(6,&peso32BitsModbus.statusH,&arrayMemoriaModbusRtu[0]);
    }
    if (controleTara == _TARAATIVADA)
    {   
        tempPesoFloatModBus = valorPesoLiquidoFloatIndicador;
        tempLongIntPesoModBus = valorPesoLiquidoIntIndicador;
        transformaPesoParaPadraoModbus();
        transfereArrayToArrayInvertido(6,&peso32BitsModbus.statusH,&arrayMemoriaModbusRtu[0]);
    }       
//prepara peso bruto arrayMemoriaModbusRtu[6]  
    tempPesoFloatModBus = valorPesoBrutoFloatIndicador;
    tempLongIntPesoModBus = valorPesoBrutoIntIndicador;
    transformaPesoParaPadraoModbus();    
    transfereArrayToArrayInvertido(6,&peso32BitsModbus.statusH,&arrayMemoriaModbusRtu[6]);
//prepara peso tara arrayMemoriaModbusRtu[12]  
    tempPesoFloatModBus = valorPesoTaraFloatIndicador;
    tempLongIntPesoModBus = valorPesoTaraIntIndicador;
    transformaPesoParaPadraoModbus();        
    transfereArrayToArrayInvertido(6,&peso32BitsModbus.statusH,&arrayMemoriaModbusRtu[12]);    
//prepara peso liqudo arrayMemoriaModbusRtu[18]  
    tempPesoFloatModBus = valorPesoLiquidoFloatIndicador;
    tempLongIntPesoModBus = valorPesoLiquidoIntIndicador;
    transformaPesoParaPadraoModbus();        
    transfereArrayToArrayInvertido(6,&peso32BitsModbus.statusH,&arrayMemoriaModbusRtu[18]);          
//status power on arrayMemoriaModbusRtu[24]  
        arrayMemoriaModbusRtu[24] = 0;
        arrayMemoriaModbusRtu[25] = statusPowerOnMem;
//status tara arrayMemoriaModbusRtu[26]  
        arrayMemoriaModbusRtu[26] = 0;
        if (controleTara == _TARAATIVADA){arrayMemoriaModbusRtu[27] = 1;} 
        else{arrayMemoriaModbusRtu[27] = 0;} 
 //status comando zero arrayMemoriaModbusRtu[28]  
        arrayMemoriaModbusRtu[28] = 0;
        arrayMemoriaModbusRtu[29] = 0;
//status faixa de zero arrayMemoriaModbusRtu[30]  
        arrayMemoriaModbusRtu[30] = 0;
        arrayMemoriaModbusRtu[31] = valorLimiteDeZeroMem;    
//status filtro digital arrayMemoriaModbusRtu[33]  
        arrayMemoriaModbusRtu[32] = 0;
        arrayMemoriaModbusRtu[33] = valorFiltroDigitalMem;
//status do modo de funcionamento do zero ao ligar
        arrayMemoriaModbusRtu[34] = 0;
        arrayMemoriaModbusRtu[35] = statusZeroAoLigarMem;
        transfereArrayToArray(35,&arrayMemoriaModbusRtu[0],&arrayMemoriaModbusRtuEspenho[0]); 
 }
//////////////////////////////////////////////////////////////////////////////////		
//      funcoes de interligacao da modbus verifica se salva frame recebido		//	
//////////////////////////////////////////////////////////////////////////////////
void funcaoVerificaSalvaModBusRtu(void)
{
    if (flagVerificaSalvaFrameModBusRtu == 1)
    {
        flagVerificaSalvaFrameModBusRtu = 0;
//verifica se liga/desliga o indicador de peso
        if (arrayMemoriaModbusRtu[24] != arrayMemoriaModbusRtuEspenho[24]
        ||arrayMemoriaModbusRtu[25] != arrayMemoriaModbusRtuEspenho[25])
        {             
            arrayMemoriaModbusRtu[24] = arrayMemoriaModbusRtuEspenho[24]; 
            arrayMemoriaModbusRtu[25] = arrayMemoriaModbusRtuEspenho[25]; 
            if (arrayMemoriaModbusRtu[25] == 1){metodoLigaSistema();}
            if (arrayMemoriaModbusRtu[25] == 0){metodoDesligaSistema();}            
        }   
//verifica se tara/destara o indicador de peso
        if (arrayMemoriaModbusRtu[26] != arrayMemoriaModbusRtuEspenho[26]
        ||arrayMemoriaModbusRtu[27] != arrayMemoriaModbusRtuEspenho[27])
        {
            arrayMemoriaModbusRtu[27] = arrayMemoriaModbusRtuEspenho[27];
//verifica se tara
            if (arrayMemoriaModbusRtu[27] == 1)
            {
                if (indicadorEmZero != 1) 
                {
                    controleTara = _TARAATIVADA;
                    fazTaraIndicadorPeso = 1;
                }                                    
            }
//verifica se destara            
            if (arrayMemoriaModbusRtu[27] == 0)
            {
                controleTara = _TARADESATIVADA;
            }
        }
//verifica se aplica zero ao indicador de peso
        if ( arrayMemoriaModbusRtuEspenho[28] == 0 && arrayMemoriaModbusRtuEspenho[29] == 1)
        {
            fazZeroIndicadorPeso = 1;
            metodoFazZeroIndicadorPeso();
        }        
//verifica se salva faixa do limite de zero
        if (arrayMemoriaModbusRtu[30] != arrayMemoriaModbusRtuEspenho[30]
        ||arrayMemoriaModbusRtu[31] != arrayMemoriaModbusRtuEspenho[31])
        {    
            if (arrayMemoriaModbusRtuEspenho[31] <= _limiteProgLimiteDeZero)
            {                
                valorLimiteDeZeroMem = arrayMemoriaModbusRtuEspenho[31];
                salvaValorLimiteDeZeroMem();
            }
        }   
//verifica se salva o valor para o filtro digital
        if (arrayMemoriaModbusRtu[32] != arrayMemoriaModbusRtuEspenho[32]
        ||arrayMemoriaModbusRtu[33] != arrayMemoriaModbusRtuEspenho[33])
        {   
            if (arrayMemoriaModbusRtuEspenho[33] <= _limiteProgValorFiltroDigital)
            {
                valorFiltroDigitalMem = arrayMemoriaModbusRtuEspenho[33];
                salvaValorFiltroDigitalMem();
            }
        }
//verifica se salva o modo de funcionamento do zero ao ligar
        if (arrayMemoriaModbusRtu[34] != arrayMemoriaModbusRtuEspenho[34]
        ||arrayMemoriaModbusRtu[35] != arrayMemoriaModbusRtuEspenho[35]) 
        {
            if (arrayMemoriaModbusRtuEspenho[35] <= _limiteStatusProgramacaoZeroAoLigar)
            {
                statusZeroAoLigarMem = arrayMemoriaModbusRtuEspenho[35];
                salvaStatusZeroPowerMem();
            }
        }        
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//funcao utilizada para transoforma o peso recebido no formato modbus Rtu   	//
//////////////////////////////////////////////////////////////////////////////////
void transformaPesoParaPadraoModbus(void)
{
    if (tempPesoFloatModBus < 0)
    {
        peso32BitsModbus.statusL.stBit.pesoNegativo = 1;
    }
    else
    {
        peso32BitsModbus.statusL.stBit.pesoNegativo = 0;
    }
    peso32BitsModbus.pesoBruto.int32 =  tempLongIntPesoModBus;
    peso32BitsModbus.statusL.stBit.pontoDecimal = posicaoPontoDecimalIndicadorMem;
    peso32BitsModbus.statusL.stBit.sobreCarga = statusControleSobreCarga;
    peso32BitsModbus.statusL.stBit.subCarga = statusControleSubCarga;
}
//////////////////////////////////////////////////////////////////////////////////
/*Rotaciona a array e insere zero para limite de conversao de array para inteiro*/
/* modbus                                                                       */
//////////////////////////////////////////////////////////////////////////////////
void rotacionaArrayInsere0ConverteParaInteiroModBus(void)
{
    arrayTemp10ModBus[0] = arrayTemp10ModBus[1]; 
    arrayTemp10ModBus[1] = arrayTemp10ModBus[2]; 
    arrayTemp10ModBus[2] = arrayTemp10ModBus[3]; 
    arrayTemp10ModBus[3] = arrayTemp10ModBus[4]; 
    arrayTemp10ModBus[4] = arrayTemp10ModBus[5]; 
    arrayTemp10ModBus[5] = arrayTemp10ModBus[6]; 
    arrayTemp10ModBus[6] = arrayTemp10ModBus[7]; 
    arrayTemp10ModBus[7] = arrayTemp10ModBus[8]; 
    arrayTemp10ModBus[8] = arrayTemp10ModBus[9];     
    arrayTemp10ModBus[9] = 0;    
}
