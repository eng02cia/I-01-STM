//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//        Funções de cofiguração do modulo rf hm trp  na serial 2         		//
//                                                                            	//
//////////////////////////////////////////////////////////////////////////////////		
//Contantes utilizadas nas funções								   				//		
//////////////////////////////////////////////////////////////////////////////////		

#define	PconfigHmTrpSerial_2	PORTCbits.RC5
#define	PenableHmTrpSerial_2	LATCbits.LATC4

#define	PCanalRf_01         	LATCbits.LATC2
#define	PCanalRf_02         	LATCbits.LATC1
#define	PCanalRf_03         	LATCbits.LATC0
#define	PCanalRf_04         	LATAbits.LATA6
#define	PCanalRf_05         	LATAbits.LATA7

//////////////////////////////////////////////////////////////////////////////////		
//declaração de variaveis utilIzadas nesta função								//
//////////////////////////////////////////////////////////////////////////////////		
static unsigned char FrameTxSerial_2 [12];
static unsigned char RendCanalRf [4];
static unsigned char QuantidadeBytesTxSerial_2 = 0;
static unsigned char IndexTxSerial_2 = 0;	
static unsigned char TempoTransmiteFramePesoHmTrp = 0;
static unsigned char TempoInicioConfiguracaoHmTrpSerial_2 = 0;
static unsigned char TempoFinalizaConfiguracaoHmTrpSerial_2 = 0;
short FlagTxSerial_2 = 0;
short FlagTransmitindoSerial_2 = 0;
//short FlagTeclaConfiguraSistema = 0;
short FlagIniciaConfiguracaoHmTrpSerial_2 = 0;
short FlagFinalizaConfiguracaoHmTrpSerial_2 = 0;
short FlagConfigurandoCanalRfSerial_2 = 0;

//////////////////////////////////////////////////////////////////////////////////		
//prototipos de função utilizados												//
//////////////////////////////////////////////////////////////////////////////////		
void IniciaConfiguracaoHmTrpSerial_2 (void);
void ConverteEnderecoRfHmTrpSerial_2 (void);
void ConfiguraCanalRfHmTrpSerial_2 (void);
void ControleTxSerial_2 (void);
void Velocidade9600KbpsSerial_2(void);
void InicializaHmTrpSerial_2 (void);
void ControlaTxFramePesoSerial_2 (void);
void MetodoTempoIniciaConfiguracaoHmTrpSerial_2 (void);
void MetodoTempoFinalizaConfiguracaoHmTrpSerial_2 (void);
