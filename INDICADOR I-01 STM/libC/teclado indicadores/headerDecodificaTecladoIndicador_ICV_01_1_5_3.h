/////////////////////////////////////////////////////////////////////////////////		
//prototipos de função utilizados												//
//////////////////////////////////////////////////////////////////////////////////	
void inicializaDecodificaTeclado(void);
void metodoDecodificaTeclado(void);
void validaTeclaPresionada (void);
void metodoValidaTeclaPresionada(void);
void ledZeroTaraDireto(void);
//static unsigned char ControleDspTeclas;
static unsigned char loopValidaTecla ;
static unsigned char teclaAuxiliar = 0;
static unsigned char loopValidaTeclaSolta;
static unsigned char teclaExternaSolta;
static unsigned char tempoValidaLigaDesligaExterno;
//static unsigned char statusLigaDesliga;
static unsigned char teclaPressionada;
static unsigned char trataTeclaValidaIndicador;
unsigned char tempTecla;


short flagIniciaTempoTeclaPresionada ;

short flagTeclaPressionadaTemp;
short flagInibeTeclaSolta;

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

// pinos utilizados na funcao de decodificação das teclas
#if _18F46K40
#define	pinoColuna1              LATDbits.LATD1
#define	pinoColuna2              LATDbits.LATD0
#define	pinoColuna3              LATAbits.LATA7
#define	pinoLinha1               PORTBbits.RB4
#define	pinoLinha2               PORTAbits.RA6
#define	pinoLinha3               PORTCbits.RC2

#define	pinoLedZero              LATAbits.LATA0
#define	pinoLedTara             LATBbits.LATB5


#define	pinoTeclaExterna         PORTDbits.RD6
#define	pinoMuxLed               LATDbits.LATD4
#endif

#if _18F66K40
#define	pinoColuna1              LATDbits.LATD2
#define	pinoColuna2              LATDbits.LATD3
#define	pinoColuna3              LATBbits.LATB5
#define	pinoLinha1               PORTAbits.RA1
#define	pinoLinha2               PORTBbits.RB4
#define	pinoLinha3               PORTBbits.RB3

#define	pinoLedZero              LATDbits.LATD6
#define	pinoLedTara              LATDbits.LATD5


#define	pinoTeclaExterna         PORTFbits.RF0
#endif


#define _DESLIGADO 0
#define _LIGADO 1