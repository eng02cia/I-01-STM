//////////////////////////////////////////////////////////////////////////////////		
//      Header que controlam a transmisao de dados pela serial 1         		//		
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de funcao utilizados												//
//////////////////////////////////////////////////////////////////////////////////		
void funcaoLeituraDadosMemoria(void);
void funcaoControleModBusRtu(void);
void transformaPesoParaPadraoModbus(void);
void rotacionaArrayInsere0ConverteParaInteiroModBus(void);
void funcaoValoresTxModBusRtu(unsigned char qtBytesTx,unsigned char *origem,unsigned char *destino);
void funcaoLeituraDadosMemoriaModBusRtu(void);
void funcaoVerificaSalvaModBusRtu(void);
void funcaoControleEepronModBusRtu(void);
void converteLongIntToArray(void);
void fazArredondamentoPesoModBusRtu(void);
//declaracao de variaveis utilizadas
static unsigned char arrayMemoriaModbusRtu[36];
static unsigned char arrayMemoriaModbusRtuEspenho[36];
//static unsigned char arrayTempConverteInt[8];
static unsigned char arrayTemp10ModBus[10];
//static long int longIntTemp;
//static float tempFloatModBusRtu;
static float tempPesoFloatModBus;
static long int tempLongIntPesoModBus;
//static unsigned char *indexLongInt;
//static unsigned long int tempTransformaPesoModBus;
short flagVerificaSalvaFrameModBusRtu;
//short iniciaSalvaDadosModbusRtu;





//estrutura de dados do peso transmitido 
struct 
{ 
    union{
        uint8_t array4[4]; 
        uint32_t int32;   
    }pesoBruto;
    union{
        struct{
            uint8_t pontoDecimal:3;
            uint8_t pesoNegativo:1;
            uint8_t sobreCarga:1;
            uint8_t subCarga:1;            
            uint8_t naoUsado:2;
        }stBit;
        uint8_t Byte;
    }statusL;    
    uint8_t statusH;       
}peso32BitsModbus;

union{
     uint8_t array4[4]; 
     uint32_t int32;   
}dadoTemp32BitsModbus;
