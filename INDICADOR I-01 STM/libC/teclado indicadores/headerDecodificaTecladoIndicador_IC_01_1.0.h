/////////////////////////////////////////////////////////////////////////////////		
//prototipos de fun��o utilizados												//
//////////////////////////////////////////////////////////////////////////////////	
void inicializaDecodificaTeclado(void);
void metodoDecodificaTeclado(void);
void validaTeclaPresionada (void);
void metodoValidaTeclaPresionada(void);
void ledZeroTaraMultiplexado(void);
void ledZeroTaraDireto(void);
void verificaEntradaSensor(void);
void verificaLigaDesligaExterno(void);
//static unsigned char ControleDspTeclas;
static unsigned char loopValidaTecla ;
static unsigned char teclaAuxiliar = 0;
static unsigned char loopValidaTeclaSolta;
static unsigned char teclaExternaSolta;
static unsigned char tempoValidaLigaDesligaExterno;

static unsigned char controleSensorSeguranca;
static unsigned char tempoValidaSensorSeguranca;
static unsigned char teclaPressionada;
static unsigned char trataTeclaValidaIndicador;
static unsigned char statusLigaDesliga;

unsigned char tempTecla;
unsigned char tempValorTecla;
unsigned char tempTeclaStart;
unsigned char temp1TeclaStart;
unsigned char tempTeclaSensorSeguranca;
int flagIniciaTempoTeclaPresionada ;

int flagTeclaPressionadaTemp;
int flagInibeTeclaSolta;

enum teclaAtualValida
{
    teclaLigaDesliga,
    teclaZeroRetorna,
    teclaTaraSetaEsquerda,
    teclaImprimeSetaAcima,
    teclaSalva,    
    teclaMemoria1,
    teclaMemoria2,
    teclaStartStop,
    teclaSolta, 
    teclaNaoUsada,
}teclaPressionadaAtual = teclaSolta;

#define teclaLigaDesliga        0
#define teclaZeroRetorna        1
#define teclaTaraSetaEsquerda   2
#define teclaImprimeSetaAcima   3
#define teclaSalva              4
#define teclaMemoria1           5
#define teclaMemoria2           6
#define teclaRegistra           7
#define teclaNaoUsada           8

// pinos utilizados na funcao de decodifica��o das teclas
//#define	pinoColuna1              LATDbits.LATD1
//#define	pinoColuna2              LATDbits.LATD0
//#define	pinoColuna3              LATAbits.LATA7
//#define	pinoLinha1               PORTBbits.RB4
//#define	pinoLinha2               PORTAbits.RA6
//#define	pinoLinha3               PORTCbits.RC2

//#define	pinoTeclaExterna         PORTDbits.RD6
//#define	pinoEntradaSensor        PORTDbits.RD7

//#define	pinoMuxLed               LATDbits.LATD4
#define _DESLIGADO 0
#define _LIGADO 1

#define _sensorAberto 1
#define _sensorFechado 0
