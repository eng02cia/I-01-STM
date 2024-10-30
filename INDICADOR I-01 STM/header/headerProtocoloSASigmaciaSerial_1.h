/*//////////////////////////////////////////////////////////////////////////////////
//      Header que controlam a transmis�o de dados pela serial 1         		//		
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de fun��o utilizados												//
//////////////////////////////////////////////////////////////////////////////////		
void serial_1RxInterruptProtocoloSa(void);
void rxSerial_1ProtocoloSa(void);
void trataFrameProtocoloSa(void);
int checaFrameAsciiValido(unsigned char qtBytes, unsigned char *index);
void enviaConfirmaCalibracaoZero(void);
void enviaConfirmaCalibracaoPeso(void);
void enviaErroCalibracaoPeso(void);
void funcTempoMaxRxSerial_1(void);
void velocidadeSerial_1_115200Kbps(void);
void velocidadeSerial_1_57600Kbps(void);
void velocidadeSerial_1_38400Kbps(void);
void velocidadeSerial_1_19200Kbps(void);
void velocidadeSerial_1_9600Kbps(void);
void velocidadeSerial_1_4800Kbps(void);
void velocidadeSerial_1_2400Kbps(void);
void velocidadeSerial_1_1200Kbps(void);
void trataErroSerial_1(void);

static unsigned char frameRxProtocoloSaValido;
static unsigned char rrxSerial_1;
static unsigned char tamanhoFrameRxSerial_1;
static unsigned char indexRxSerial_1;
static unsigned char frameRxSerial_1[30];
static unsigned char tempoMaxRxSerial_1;
static unsigned char arrayTempProtocolo[5];
static unsigned char tempProtocolo;
static unsigned char qtBytesArray;
static unsigned char tempComparaValidade;
static unsigned char arrayTempRxSerial_1[7];
static unsigned char arrayTemp1RxSerial_1[7];
static unsigned char arrayTemp2RxSerial_1[7];
static unsigned char arrayEndIndicadorAscii[2];
short flagTempoMaxRxSerial_1;

enum
{
    inicioFimFrameSerial_1,
    finalFrameSerial_1,
}verificaFimFrame;


// comandos do protocolo AudioTEck
const char charVersaoIndicadorSigmaciaSa[] = {"H:1.50F:1.7\r\n"};
const char charLigaIndicador[] ={"IN:ON"};
const char charDesligaIndicador[] ={"IN:OFF"};
const char charStaFuncionamentoIndicador[] ={"IN:ST"};
const char charLigaTara[] ={"TR:ON"};
const char charDesligaTara[] ={"TR:OFF"};
const char charStatusTara[] ={"TR:ST"};
const char charLigaZero[] ={"ZE:ON"};
const char charLimiteZero[] ={"LZ:CF"};
const char charStatusLimiteZero[] ={"LZ:ST"};

const char charFiltroDigital[] ={"FD:CF"};
const char charStatusFiltroDigital[] ={"FD:ST"};


const char charSolicitaPesoBruto[] ={"PB:ST"};
const char charSolicitaPesoTara[] ={"PT:ST"};
const char charSolicitaPesoLiquido[] ={"PL:ST"};
const char charSolicitaVersao[] ={"VE:ST"};
const char charControleTxAutomatico[] ={"TA:CF"};
const char charStatusFuncionamento[] ={"FU:ST"};
//comandos de calibra��o
const char charCapacidadeMaxima[] ={"CM:CF"};
const char charStatusCapacidadeMaxima[] ={"CM:ST"};
const char charPesoCalibracao[] ={"PC:CF"};
const char charStatusPesoCalibracao[] ={"PC:ST"};
const char charPontoDecimal[] ={"PD:CF"};
const char charStatusPontoDecimal[] ={"PD:ST"};
const char charDegrauPeso[] ={"DP:CF"};
const char charStatusDegrauPeso[] ={"DP:ST"};
const char charCalibraZero[] ={"CZ:CF"};
const char charCalibraPeso[] ={"CP:CF"};

//mensagens de retorno

const char charRespostaTaraErro[] ={"TR:ERRO\r\n"};
const char charRespostaZeroOk[] ={"ZE:OK\r\n"};
const char charRespostaZeroErro1[] ={"ZE:ERRO1\r\n"};
const char charRespostaZeroErro2[] ={"ZE:ERRO2\r\n"};
const char charRespostaLimiteZeroOk[] ={"LZ:OK\r\n"};
const char charRespostaLimiteZeroErro[] ={"LZ:ERRO\r\n"};

const char charRespostaFiltroDigitalOk[] ={"FD:OK\r\n"};
const char charRespostaFiltroDigitalErro[] ={"FD:ERRO\r\n"};

const char charRespostaTxAutomatico[] = {"TA:OK\r\n"};
const char charRespostaCapMaxima[] = {"CM:OK\r\n"};
const char charRespostaErroCapMaxima[] = {"CM:ERRO\r\n"};
const char charRespostaPesoCalibracaoOk[] = {"PC:OK\r\n"};
const char charRespostaPesoCalibracaoErro1[] = {"PC:ERRO1\r\n"};
const char charRespostaPesoCalibracaoErro2[] = {"PC:ERRO2\r\n"};
const char charRespostaPontoDecimalOk[] = {"PD:OK\r\n"};
const char charRespostaPontoDecimalErro[] = {"PD:ERRO\r\n"};
const char charRespostaDegrauPesoOk[] = {"DP:OK\r\n"};
const char charRespostaDegrauPesoErro[] = {"DP:ERRO\r\n"};
const char charRespostaAguarde[] = {"AGUARDE\r\n"};
const char charRespostaCalibracaoZeroOk[] ={"CZ:OK\r\n"};
const char charRespostaCalibracaoPesoOk[] ={"CP:OK\r\n"};
const char charErroCalibracaoPesoOk[] ={"CP:ERRO\r\n"};
const char charErroComandoInvalido[] ={"COMANDO INVALIDO\r\n"};
const char charErroFrameInvalido[] ={"FRAME INVALIDO\r\n"};
*/
