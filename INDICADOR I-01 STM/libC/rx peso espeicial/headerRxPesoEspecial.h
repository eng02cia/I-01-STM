//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//  Faz a recepe��o e tratamento de peso quando no indicador digitron   		//	
//  Peso liquido e peso bruto                                                   //
//////////////////////////////////////////////////////////////////////////////////		
//Declara��o de prototipos utilizados na fun��o									//
//////////////////////////////////////////////////////////////////////////////////		
void serial_1InterruptDigitronT2(void);
void recebeFramePesoSerial_1DigitronT2(void);
void tempoControleRxSerial_1DigitronT2(void);
void trataFrameRxDigitronT2(void);
void initRxPesoDigitronT2(void);
void trataFrameRxToledoP03(void);
void metodoComumTrataPesoEspecial(void);
void transformaParaKilograma(void);
void metodoColocaPontoPesoEspecial(void);
//////////////////////////////////////////////////////////////////////////////////
// Declara��o de vari�veis utilizadas no gerenciamento das balan�as				//
//////////////////////////////////////////////////////////////////////////////////
static unsigned char rtempPesoEspecial;
static unsigned char indexPesoEspecial;
static unsigned char tipoDadoRxDigitronT2;
static unsigned char pesoNegativoPesoEspecial;
static unsigned char posicaoPontoPesoEspecial;
static unsigned char pesoLiquidoPesoEspecial[7];
static unsigned char pesoTaraPesoEspecial[7];
static unsigned char pesoBrutoPesoEspecial[7];
static unsigned char pesoBrutoDecimal[9];
static unsigned char pesoTaraDecimal[9];
static unsigned char pesoLiquidoDecimal[9];
static unsigned char pesoMortoDecimal[9];
static unsigned char tempCalculaPeso[9];
static unsigned char dado_Serial_1[2];
static unsigned char verificaTara;

static unsigned char pesoAsciiSerial_1[7] = {' ',' ',' ',' ',' ',' ','0'};
static unsigned char frameRxSerial_1[60];
static unsigned char frameRxSerial_1Backup[60];
static unsigned char statusRxPesoDigitronSerial_1;
static unsigned char tamanhoFramePeso;
static unsigned char tempRxPesoEspecial;
static unsigned char erroPesoTara;
static unsigned char erroTarraMaiorQueLiquido;
static unsigned char loopConvertePonto;
static unsigned char valorTaraManualPesoEspecial[7];
static unsigned char valorPesoMortoPesoEspecial[7];
static unsigned char tempConvertePesoEspecial[7];
static unsigned char statusBufferSerial_1;
static unsigned char rloopMudaTempoJanelaFrameSerial_1;
static unsigned char tamanhoFrameRxSerial_1;
static unsigned char rloopIdentificaEntradaSerial_1;
static unsigned char tipoProtocoloEep;
static unsigned char tempoSemDadoSerial_1;
static unsigned char statusErroRxPesoSerial_1;
static unsigned char tempoMaxPicaLedRxSerial_1;
static unsigned char indexSerial_1;
static unsigned char tempoControleFinalFrameSerial_1;
static unsigned char valorPesoMorto[10];
static unsigned char valorTaraManual[10];
static unsigned char tempoReferenciaFinalFrameSerial_1;

#define _DESATIVADO 0
#define _ATIVADO 1
#define _BUFFER_CHEIO 1
#define _BUFFER_VAZIO 0
#define _COM_BALANCA 1
#define _SEM_BALANCA 0

short flagTempoControleFinalFrameSerial_1;
short flagTempoSemDadoSerial_1;
