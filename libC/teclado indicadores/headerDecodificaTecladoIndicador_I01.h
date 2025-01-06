/////////////////////////////////////////////////////////////////////////////////		
//prototipos de funcao utilizados												//
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
static unsigned char teclaPressionada;
static unsigned char trataTeclaValidaIndicador;
unsigned char tempTecla;
unsigned char tempValorTecla;
unsigned char tempTeclaStart;
unsigned char temp1TeclasStart;
unsigned char tempTeclaPrint;
unsigned char tempTeclaTara;
unsigned char tempTeclaZero;
static unsigned char flagIniciaTempoTeclaPresionada ;

static unsigned char flagTeclaPressionadaTemp;
static unsigned char flagInibeTeclaSolta;


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

//#define	ledIndicadorLigado       LATAbits.LATA1

#define _DESLIGADO 0
#define _LIGADO 1
