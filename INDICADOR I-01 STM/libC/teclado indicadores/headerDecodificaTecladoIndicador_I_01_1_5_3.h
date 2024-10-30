/////////////////////////////////////////////////////////////////////////////////		
//prototipos de função utilizados												//
//////////////////////////////////////////////////////////////////////////////////	
void inicializaDecodificaTeclado(void);
void metodoDecodificaTeclado(void);
void validaTeclaPresionada (void);
void metodoValidaTeclaPresionada(void);
void ledZeroTaraDireto(void);

void verificaLigaDesligaExterno(void);
void VerificaComandoZeroExterno(void);
void verificaComandoTaraExterno(void);
void verificaComandoPrintExterno(void);
//static unsigned char ControleDspTeclas;
static unsigned char loopValidaTecla ;
static unsigned char teclaAuxiliar = 0;
static unsigned char loopValidaTeclaSolta;
static unsigned char teclaExternaLigaDesligaSolta;
static unsigned char teclaExternaZero;
static unsigned char teclaExternaTara;
static unsigned char teclaExternaPrint;

static unsigned char tempoValidaLigaDesligaExterno;
static unsigned char tempoValidaZeroExterno;
static unsigned char tempoValidaTaraExterno;
static unsigned char tempoValidaPrintExterno;
static unsigned char statusLigaDesliga;
static unsigned char teclaPresionda;
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
#endif
#if _18F47K40
#define	pinoColuna1              LATDbits.LATD1
#define	pinoColuna2              LATDbits.LATD0
#define	pinoColuna3              LATAbits.LATA7
#define	pinoLinha1               PORTBbits.RB4
#define	pinoLinha2               PORTAbits.RA6
#define	pinoLinha3               PORTCbits.RC2
#endif
#if _18F66K40
#define	pinoColuna1              LATEbits.LATE6
#define	pinoColuna2              LATEbits.LATE7
#define	pinoColuna3              LATDbits.LATD5
#define	pinoLinha1               PORTHbits.RH0
#define	pinoLinha2               PORTDbits.RD4
#define	pinoLinha3               PORTDbits.RD0
#endif

#if _18F46K40
#define	ledIndicadorLigado       LATAbits.LATA1
#define	pinoLedZero              LATAbits.LATA0
#define	pinoLedTara              LATBbits.LATB5
#endif
#if _18F47K40
#define	ledIndicadorLigado       LATAbits.LATA1
#define	pinoLedZero              LATAbits.LATA0
#define	pinoLedTara              LATBbits.LATB5
#endif

#if _18F66K40
//#define	ledIndicadorLigado       LATAbits.LATA1
#define	pinoLedZero              LATHbits.LATH3
#define	pinoLedTara              LATHbits.LATH2
#endif
#if _18F46K40
#define	pinoComandoLigaDesliga   PORTDbits.RD6
#define pinoComandoZero          PORTDbits.RD7
#define pinoComandoTara          PORTBbits.RB6   
#define pinoComandoPrint         PORTBbits.RB7  
#endif
#if _18F47K40
#define	pinoComandoLigaDesliga   PORTDbits.RD6
#define pinoComandoZero          PORTDbits.RD7
#define pinoComandoTara          PORTBbits.RB6   
#define pinoComandoPrint         PORTBbits.RB7  
#endif
#if _18F66K40
#define	pinoComandoLigaDesliga   PORTFbits.RF7
#define pinoComandoZero          PORTFbits.RF6
#define pinoComandoTara          PORTFbits.RF5   
#define pinoComandoPrint         PORTFbits.RF4 
#endif

#if _18F46K40
#define	pinoMuxLed               LATDbits.LATD4
#endif
#if _18F47K40
#define	pinoMuxLed               LATDbits.LATD4
#endif
#define _DESLIGADO 0
#define _LIGADO 1