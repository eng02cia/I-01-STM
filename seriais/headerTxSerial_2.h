//////////////////////////////////////////////////////////////////////////////////		
//      Header das funcoes que controlam a transmis�o de dados pela serial 2 	//
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de fun��o utilizados												//
//////////////////////////////////////////////////////////////////////////////////		
void inicializaSerial_2(void);
void controleTxSerial_2(void);
void controleTxFrameSerial_2(void);
void trataErroSerial_2(void);

void velocidadeSerial_3_115200Kbps(void);


//variaveis utilizadas na serial 2

static unsigned char frameTxSerial_2[30];
static unsigned char indexTxSerial_2;
static unsigned char qtBytesTxSerial_2;
static unsigned char tempoTxSerial_2;
static unsigned char transmitindoSerial_2;
static unsigned char *indexCorrigePeso;
short flagTxSerial_2;
