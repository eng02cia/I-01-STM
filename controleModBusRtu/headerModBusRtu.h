//////////////////////////////////////////////////////////////////////////////////		
//      Header que controlam a transmisao de dados pela serial 1         		//		
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de funcao utilizados												//
//////////////////////////////////////////////////////////////////////////////////		
void iniciaVariaveisTxSerial_1ModBusRtu(void);
void serial_1RxInterruptModBusRtu(void);
void controleTxFrameSerial_1ModBusRtu(void);
void solicitaPesoBalancaSerial_1ModBusRtu(void);
void rxSerial_1InterruptComando(void);
void recebePesoComando(void);
void metodoTempoMaxRxPesoPesoComando(void);
void metodoIniciaRxComando_1(void);
void metodoIniciaModoModbus(void);
void gerenciaComandosModbus(void);
void interruptModBusRtu(void);
void rxSerialModBusRtu(void);
void trataFrameRxModBusRtu(void);
void trataModBusRtu(void);
void convertePesoModBusToPesoAscii(void);

void iniciaTxModbus(void);

void velocidadeSerial_1_115200Kbps(void);
void velocidadeSerial_1_57600Kbps(void);
void velocidadeSerial_1_38400Kbps(void);
void velocidadeSerial_1_19200Kbps(void);
void velocidadeSerial_1_9600Kbps(void);
void velocidadeSerial_1_4800Kbps(void);
void velocidadeSerial_1_2400Kbps(void);
void velocidadeSerial_1_1200Kbps(void);
void trataErroSerial_1(void);



//////////////////////////////////////////////////////////////////////////////////		
//declaracao de variaveis utilziadas nesta funcao								//
//////////////////////////////////////////////////////////////////////////////////		
static unsigned char silentModBusRtu;
static unsigned char frameTxModBusRtu[90];


static unsigned char qtBytesTxModBusRtu;
static unsigned char indexTxModBusRtu;
//static unsigned char testeEndModbus;
static unsigned char arrayPesoBrutoModbus[6];
static unsigned char arrayPesoTaraModbus[6];
static unsigned char arrayTempModBusRtu[2];
static unsigned char frameRxModBusRtu[60];
static unsigned char rrxModBusRtu;
static unsigned char indexRxModBusRtu;
static unsigned char tempoMaxRxModBusRtu;
static unsigned char tamanhoFrameRxModBusRtu;
static unsigned char tempRxModBusRtu;
static unsigned char tempModBusRtu;
static unsigned char temp1ModBusRtu;
static unsigned char temp2ModBusRtu;
static unsigned char numeroRegistradorModBusH;
static unsigned char numeroRegistradorModBusL;


static unsigned char *indexModBus;
struct 
{
    unsigned transmitindoModBusRtu:1;
    unsigned txModBusRtu:1;
    unsigned tempoMaxRxModBusRtu:1;
}flagModBusRtu;

#define _qtMaxLeituraRegistradorValido16Bits 18
#define _qtMaxLeituraRegistradorValido8Bits 36

#define _qtMaxEscritaRegistradorValido16Bits 18
#define _qtMaxEscritaRegistradorValido8Bits 36
