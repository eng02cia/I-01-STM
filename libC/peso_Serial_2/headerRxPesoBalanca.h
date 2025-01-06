//////////////////////////////////////////////////////////////////////////////////		
//                       Header Rx Serial display remoto                  		//		
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de funcao utilizados												//
//////////////////////////////////////////////////////////////////////////////////		
void initRxPesoSerial_1(void);
void rxSerial_1Rs232Interrupt(void);
void mudaVelocidadeSerial_1(void);
void tempoControleRxSerial_1(void);
void recebeFramePesoSerial_1(void);
void funcaoIdentificaEntradaSerial_1(void);
void controleTempoJanelaFrameSerial_1(void);
void funcaoIdentificaSemSerial_1(void);

//////////////////////////////////////////////////////////////////////////////////		
//declara��o de variaveis utilziadas nesta funcao								//
//////////////////////////////////////////////////////////////////////////////////		
static unsigned char tempoReferenciaFinalFrameSerial_1;
unsigned char statusProtocoloIdenticadoSerial_1;
unsigned char dado_Serial_1Temp;
static unsigned char indexSerial_1;
static unsigned char tempoControleFinalFrameSerial_1;
static unsigned char dado_Serial_1[2];
static unsigned char frameRxSerial_1[60];
static unsigned char frameRxSerial_1Backup[60];
static unsigned char tamanhoFrameRxSerial_1Backup;
static unsigned char pesoAsciiSerial_1[7] = {' ',' ',' ',' ',' ',' ','0'};
static unsigned char statusBufferSerial_1;
static unsigned char rloopMudaTempoJanelaFrameSerial_1;
static unsigned char tamanhoFrameRxSerial_1;
static unsigned char rloopIdentificaEntradaSerial_1;
static unsigned char tipoProtocoloEep;
static unsigned char tempoSemDadoSerial_1;
static unsigned char statusErroRxPesoSerial_1;
static unsigned char tempoMaxPicaLedRxSerial_1;
short flagTempoControleFinalFrameSerial_1;
short flagTempoSemDadoSerial_1;

//short flagRxSerial1Tasks;
short flagPiscaLedRxSerial_1;
#define _DESATIVADO 0
#define _ATIVADO 1
#define _BUFFER_CHEIO 1
#define _BUFFER_VAZIO 0
#define _COM_BALANCA 1
#define _SEM_BALANCA 0
//flags utilizados na funcao de recp��o do peso serial

enum 
{
    velocidadeSerial_1_1200Kbps,    
    velocidadeSerial_1_2400Kbps,
    velocidadeSerial_1_4800Kbps,
    velocidadeSerial_1_9600Kbps,
    velocidadeSerial_1_19200Kbps, 
}velocidadeSerial_1Atual = velocidadeSerial_1_9600Kbps;

#define tempoIntervaloEntreFrameSerial_1 50

