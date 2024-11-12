//////////////////////////////////////////////////////////////////////////////////		
//      Header que controlam a transmis�o de dados pela serial 1         		//		
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
static unsigned char arrayTempConverteInt[8];
static unsigned char arrayTemp10ModBus[10];
//static long int longIntTemp;
//static float tempFloatModBusRtu;
static float tempPesoFloatModBus;
static long int tempLongIntPesoModBus;
static unsigned char *indexLongInt;
//static unsigned long int tempTransformaPesoModBus;
short flagVerificaSalvaFrameModBusRtu;
//short iniciaSalvaDadosModbusRtu;





//estrutura de dados do peso transmitido 
struct 
{ 
    union{
        char array4[4]; 
        long int int32;   
    }pesoBruto;
    union{
        struct{
            unsigned pontoDecimal:3;
            unsigned pesoNegativo:1;
            unsigned sobreCarga:1;
            unsigned subCarga:1;            
        }stBit;
        unsigned char Byte;
    }statusL;    
    char statusH;       
}peso32BitsModbus;
union{
     char array4[4]; 
     long int int32;   
}dadoTemp32BitsModbus;
