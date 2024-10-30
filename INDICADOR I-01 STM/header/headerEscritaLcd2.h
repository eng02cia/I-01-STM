//////////////////////////////////////////////////////////////////////////////////		
//                        Função de escrita no lcd 16x2                   		//
//////////////////////////////////////////////////////////////////////////////////	
//variaveis utilizadas na função
static unsigned char delayLcd = 0;
static unsigned char caracterLcd[32];
static unsigned char backupTelaLcd[32];
static unsigned char quantidadeByteLcd;
static unsigned char indexEscreveDadoLcd;
static unsigned char mostraTelaTemporariaLcd;
static unsigned char tempoMostraTelaTemporariaLcd;
unsigned char rlcdTemp;
short flagPreparaEscritaCgRam;
short flagInicializacaoPreparadaLcd;

union
	{
	struct 
		{
		unsigned Bit0:1;
		unsigned Bit1:1;
		unsigned Bit2:1;
		unsigned Bit3:1;
		unsigned Bit4:1;
		unsigned Bit5:1;
		unsigned Bit6:1;
		unsigned Bit7:1;
		}Flag;
		unsigned char Byte;
	}byteDataLcd;
//Enumeração de controle da escrita no lcd   
static enum controlaEscritaLcd
{
    inicializaLcd,
    escreveCaracterEspecialCgRam,
    enviaComandoEscritaLinha_1Lcd,
    enviaComandoEscritaLinha_2Lcd,
    enviaCaracterLinha_1Lcd,
    enviaCaracterLinha_2Lcd,         
}statusAtualEscritaLcd = inicializaLcd ;


//contantes utilizadas na função
#define delayExterno30Mls               150;
#define delayExterno5Mls                25;
#define delayExterno500Micro            2;
#define delayInterno1MicroSegundo       20;
#define delayInterno3MicroSegundo       90;
    
#define	EnderecoCgram                   0b01000000;
#define EnderecoLinha1                  0x80;
#define EnderecoLinha2                  0xC0;

//definiçao de pinos utilziados na função
#if _18F46K40
#define	pinoEnable              LATEbits.LATE1
#define	pinoSelectRegister  	LATEbits.LATE2
#define	pinoData7               LATAbits.LATA3
#define	pinoData6               LATAbits.LATA4
#define	pinoData5               LATAbits.LATA5
#define	pinoData4               LATEbits.LATE0
#endif
#if _18F47K40
#define	pinoEnable              LATEbits.LATE1
#define	pinoSelectRegister  	LATEbits.LATE2
#define	pinoData7               LATAbits.LATA3
#define	pinoData6               LATAbits.LATA4
#define	pinoData5               LATAbits.LATA5
#define	pinoData4               LATEbits.LATE0
#endif
#if _18F66K40
#define	pinoEnable              LATBbits.LATB4
#define	pinoSelectRegister  	LATBbits.LATB3
#define	pinoData7               LATCbits.LATC5
#define	pinoData6               LATAbits.LATA7
#define	pinoData5               LATAbits.LATA6
#define	pinoData4               LATBbits.LATB5
#endif


#define caracterRetorna	    	00
#define caracterSalva    		01
#define	caracterIncremento 		02

#define caracterAtivo   		01
#define	caracterSetaParaBaixo   02
#define caractersetaParaCima	03
#define	caractersetaDupla	   	04
#define	caracterDecremento		05


const char tabelaCgRam[] = {
//    0x1F,0x11,0x11,0x11,0x11,0x11,0x1F,0x00,
    0x08,0x10,0x1F,0x11,0x09,0x01,0x1F,0x00,    
    0x11,0x11,0x0A,0x0A,0x04,0x1F,0x1F,0x00,  
	0x00,0x00,0x04,0x0E,0x1F,0x00,0x00,0x00,    
	0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00,0x00,
	0x1F,0x1F,0x1F,0x1F,0x00,0x00,0x00,0x00,
	0x1F,0x1F,0x00,0x00,0x00,0x1F,0x1F,0x00,
	0x00,0x00,0x00,0x00,0x1F,0x1F,0x1F,0x00,
	0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x00};
//	0x1F,0x1B,0x1B,0x11,0x1B,0x1B,0x1F,0x00,
//	0x04,0x04,0x04,0x04,0x04,0x0E,0x04,0x00,
//	0x04,0x0E,0x04,0x04,0x04,0x04,0x04,0x00,
//	0x04,0x0E,0x04,0x04,0x04,0x0E,0x04,0x00,
//	0x00,0x00,0x1F,0x0E,0x04,0x00,0x00,0x00};
//    0x08,0x10,0x1F,0x11,0x09,0x01,0x1F,0x00,
//	0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F,0x1F};
    
//declaração de prototipos das funções utilizadas para escrever no lcd
void enviaComandoLcd (void);
void enviaCaracterLcd (void);
void transmiteByteLcd(void);
void transmiteNibleLcd (void);
void delayInternoMicroSegundos (unsigned char DelayInterno);
void delayExternoLcd (void);
void controlaEscritaLcd (void);
int escreveDadoLcd(const char *charOrigem,unsigned char*charDestino);
void apagaLcd(void);
void apagaLinha_1Lcd(void);
void apagaLinha_2Lcd(void);