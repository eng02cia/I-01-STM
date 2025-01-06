//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//               Header de escrita de dados no display lcd de sete segmentos     //
//////////////////////////////////////////////////////////////////////////////////			
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de funcao utilizados												//
//////////////////////////////////////////////////////////////////////////////////
void tempoEscreveLcdSeteSegmentos(void);
void apagaLcdSeteSegmentos(void);
void escreveDigitosLcdSetSegmentos(void);
void delayEscritaSegmentosLcd(void);

unsigned char ControleConvertePontoDecimal;
static unsigned char controleDsp;
static unsigned char indexExcreveDigitos;
static unsigned char loopEscreveSegmentosLcd;
static unsigned char dadoDigitoLcdTemp;
static unsigned char tempoControleLcdEscritaSeteSegmentos;
static unsigned char controlTempoControleLcdEscritaSeteSegmentos;
static unsigned char digitosLcdSeteSegmentos[6];
static unsigned char backupDigitosLcdSeteSegmentos[7];
static unsigned char dadoLcdSetSegmentos[7];
static unsigned char dadoDigitosEscreveLcd[6];
static unsigned int contadorInicializaTelaSeteSegmento;
static unsigned char fazTelaInicialSeteSegmento;

union
{
	struct
	{
		unsigned SegA:			1;
		unsigned SegB:			1;
		unsigned SegC:			1;
		unsigned SegD:			1;
		unsigned SegE:			1;
		unsigned SegF:			1;
		unsigned SegG:			1;
		unsigned PontoDecimal:	1;
	} Display;
	unsigned char Byte;
} controlSegmentosDsp;
                   
#define	Letra_A	10
#define	Letra_B	11
#define	Letra_C	12
#define	Letra_D	13
#define	Letra_E	14
#define	Letra_F	15
#define	Letra_G	16
#define	Letra_H	17
#define	Letra_I	18
#define	Letra_J	19
#define	Letra_K	20
#define	Letra_L	21
#define	Letra_M	22
#define	Letra_N	23
#define	Letra_O	24
#define	Letra_P	25
#define	Letra_Q	26
#define	Letra_R	27
#define	Letra_S	28
#define	Letra_T	29
#define	Letra_U	30
#define	Letra_V	31
#define	Letra_W	32
#define	Letra_X	33
#define	Letra_Y	34
#define	Letra_Z	35

#define ValorTabelaEspaco 36
#define ValorZeroAbsolutoEpm 37
#define ValorTabelaTraco 38;
#define ValorGrausCelsius 39;
#define ValorPontoDecimalDspSeteSegmentos 128


const char tabSegDsp[]={0b00111111,  //0
	0b00000110,  //1
	0b01011011,  //2
	0b01001111,  //3
	0b01100110,  //4
	0b01101101,  //5
	0b01111101,  //6
	0b00000111,  //7
	0b01111111,  //8
	0b01101111,  //9
	0b01110111,  //A 
	0b01111100,  //B
	0b00111001,  //C
	0b01011110,  //D
	0b01111001,  //E
	0b01110001,  //F
	0b01111101,  //G
	0b01110100,  //H
	0b00110000,  //I
	0b00011111,  //J
	0b01010110,  //K
	0b00111000,  //L
	0b00110111,  //M
	0b01010100,  //N
	0b01011100,  //O
	0b01110011,  //P
	0b00111111,  //Q
	0b01010000,  //R
	0b01101101,  //S
	0b01111000,  //T
	0b00011100,  //U
	0b00111110,  //V
	0b01100010,  //W
	0b01100110,  //X
	0b01111110,  //Y
	0b01011011,  //Z
	0b00000000,  //APAGADO
	0b01011100,  // ZERO ABSOLUTO
	0b01000000, //TRACO
	0b01011000,};// graus celcius
