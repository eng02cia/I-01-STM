//////////////////////////////////////////////////////////////////////////////////		
//      Header que controlam a transmis�o de dados pela serial 1         		//		
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de funcao utilizados												//
//////////////////////////////////////////////////////////////////////////////////		
void iniciaVariaveisTxSerial_1(void);
void controleTxSerial_1(void);
void controleTxFrameSerial_1(void);
void iniciaTxSerial_1(void);
void tempoControleTransmiteFrameAutomatico(void);
//////////////////////////////////////////////////////////////////////////////////		
//declaracao de variaveis utilziadas nesta funcao								//
//////////////////////////////////////////////////////////////////////////////////		
static unsigned char frameTempTxSerial_1[30];
static unsigned char quantidadeTempBytesTxSerial_1;
static unsigned char indexTempTxSerial_1;
static unsigned char transmiteStatusPeso;
static unsigned char transmiteStatusDaPesagem;

static unsigned char frameTxSerial_1[31];
static unsigned char quantidadeBytesTxSerial_1;
static unsigned char indexTxSerial_1;
static unsigned int tempoTxSeria_1;
static unsigned int tempo1TxSerial_1;
struct 
{
    unsigned transmitindoSerial_1:1;
    unsigned txSerial_1:1;
    unsigned tempoMaxRxPesoComando:1;
    unsigned tempoSolicitaPesoComando:1;
    unsigned tempoComandoModBusRtu:1;
    unsigned tempoMaxRxModBusRtu:1;
    unsigned enviaConfirmacaoDeRecebimento:1;
}flagTxSerial_1;

unsigned char tempTxSerial_1;
//#define	pinoControleRs485     LATDbits.LATD5

#define _SERIAL_1ATIVADA 1
#define _RS232 1
#define _RS485 0
#define  _ATIVA 1
