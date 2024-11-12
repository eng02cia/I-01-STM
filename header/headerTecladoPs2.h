//////////////////////////////////////////////////////////////////////////////////		
//                          Header                                             	//
//////////////////////////////////////////////////////////////////////////////////	

//////////////////////////////////////////////////////////////////////////////////
//prototipo de fun��es                                                          //
//////////////////////////////////////////////////////////////////////////////////
//void inicializaComunicacaoPs2(void);
void recebeDadoTecladoPs2Interrupt(void);
void startTxTecladoPs2Interrupt(void);
void transmiteDadoTecladoPs2Interrupt(void);

void funcaoVerificaTeclaValidaPs2(void);
void tempoValidaTeclaPs2(void);
void checaTeclaEdicaoTecladoPs2(void);
void metodoAtivascrollLockTecladoPs2(void);
void metodoAtivaNumLockTecladoPs2(void);
void metodoAtivaCapsLockTecladoPs2(void);
void metodoDesativaScrollLockTecladoPs2(void);
void metodoDesativaNumLockTecladoPs2(void);
void metodoDesativaCapsLockTecladoPs2(void);
void metodoDesativaScrollLockTecladoPs2(void);
void delayMicroSegundosPs2(unsigned int DelayInterno);
void metodoIniciaConfigTecladoPs2(void);
void metodoTempoControleConfigPs2(void);
//////////////////////////////////////////////////////////////////////////////////
//declaracao de variaveis                                                       //
//////////////////////////////////////////////////////////////////////////////////
static unsigned char dataTeclaPresPs2[20];
static unsigned char dataRxTecladoPs2;
static unsigned char dataTeclaPs2;
static unsigned char dataTempTeclaPs2;
static unsigned char rloopRxDataTeclado;
static unsigned char indexDataTeclaPresPs2;
static unsigned int tempoRecebendoDadoTecladoPs2;
static unsigned int tempoMaxConfigTecladoPs2;
static unsigned char teclaPs2Press;
static unsigned char dataTempPressPs2;
static unsigned char configuraTecladoPs2;
static unsigned char verificaTeclaSoltaPs2;
//static unsigned char primeiraParteFrameTeclaExtend;
static unsigned char configTecladoPs2;
static unsigned char configFuncaoCapsLock;
static unsigned char tempoInicioConfigTecladoPs2;
static unsigned char configFuncaoNumLock;
static unsigned char teclaValidaPs2;
static unsigned char tempPinoData;
//static unsigned char tipoTeclaPressionada;
short flagControleInterruptTxPs2;
short flagRecebendoDadoTecladoPs2;
short flagTrataTeclaPs2;
short tecladoPs2Inicializado;
//////////////////////////////////////////////////////////////////////////////////
static unsigned char rloopTxPs2;
static unsigned char tempTxPs2;
static unsigned char dataTxPs2;
static unsigned char dataTxPs2Backup;
// enumeracao de controle da interrupcao do teclado ps2
enum statusInterruptPs2
{
    interruptTxPs2,
    interruptRxPs2,
}statusInterruptPs2Atual = interruptRxPs2;
//enumeracao de controle da recepcao de dados do teclado ps2
enum statusRxPs2
{
    rxPs2Start,
    rxPs2Byte,
    rxPs2Paridade,
    rxPs2Stop,
} statusRxPs2Atual = rxPs2Start;		
//uniao de estrutura utilizada para receber cada bit de um byte do teclado ps2
union
	{
	struct
		{
            unsigned bitParidade:1;
		}St;
        unsigned char Byte;
	}paridadeRxPs2;
    
//enumeracao de controle do inicio da transmis�o de dados para o teclado ps2
enum statusTxPs2
{
    txPs2Start,
    txPs2Byte,
    txPs2Paridade,
    txPs2BitAcknowledge,
    txPs2ChecaAcknowledge,
} statusTxPs2Atual = txPs2Start;
//enumeracao de tratamento da tecla pressionada
enum teclaPressionadaPs2
{
    tipoTecla,
    teclaShift,
    teclaExtend,
    aguardaFinalRepeticaoTecla,
    aguardaFinalFrame,
} teclaPressionadaPs2 = tipoTecla;
//enumeracao de controle de teclas consideradas especiais
//teclas utilizadas para na navegacao  e edicao de programacao
enum teclasEditaPrograma
{
    teclaSoltaPs2,
    teclaSetaParaCima,
    teclaSetaParaBaixo,     
    teclaSetaParaEsquerda,     
    teclaSetaParaDireita,     
    teclaBackSpace,  
    teclaDel,
    teclaEnter,
    teclaEsc,
    teclaFuncao1,
    teclaFuncao2,
    teclaFuncao3,
    teclaFuncao4,
    teclaFuncao5, 
    teclaFuncao6, 
    teclaFuncao7, 
    teclaFuncao8, 
    teclaFuncao9, 
    teclaFuncao10, 
    teclaFuncao11, 
    teclaFuncao12,   
    teclaPageUp,
    teclaPageDown,
    teclaPower,
}teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
// uni�o de controle paridade       
union
{
	struct
	{
        unsigned bitParidade:1;
	}St;
    unsigned char Byte;
}paridadeTxPs2;
//uniao de estrutura utilizada para controlar o status do teclado
union
{
	struct
	{       
        unsigned scrollLock:1;
        unsigned numLock:1;
        unsigned capsLock:1;
        unsigned unused:5;
	}St;
    unsigned char Byte;
}statusTecladoPs2;    
//////////////////////////////////////////////////////////////////////////////////
//Pinos utilizados                                                              //
//////////////////////////////////////////////////////////////////////////////////
//#define pinoDataInputPs2 PORTBbits.RB0

#define tipoTecladoPs2 1
#define _TAMANHO_MAXIMO_TABELA 0X84
const char tabelaConvertePcKeyboardToAsciiMinusculo[]={
    0,  //  VAGO    00?
    0,  //  F9      01
    0,  //  VAGO    02?
    0,  //  F5      03
    0,  //  F3      04
    0,  //  F1      05
    0,  //  F2      06
    0,  //  F12     07
    0,  //  VAGO    08?
    0,  //  F10     09
    0,  //  F8      0A
    0,  //  F6      0B
    0,  //  F4      0C
    0,  //  TAB     0D
    '\'',  //  contra barra       0E
    0,  //  VAGO    OF?
    0,  //  VAGO    10?
    0,  //  ALT     11
    0,  //  SHIFT A 12
    0,  //  VAGO    13?
    0,  //  CONTROL 14
    'q',    //  Q   15
    '1',    //  1   16
    0,  //  VAGO    17?
    0,  //  VAGO    18?
    0,  //  VAGO    19?
    'z',    //  Z   1A
    's',    //  S   1B
    'a',    //  A   1C
    'w',    //  W   1D
    '2',    //  2   1E
    0,  //  VAGO    1F?
    0,  //  VAGO    20?
    'c',    //  C   21
    'x',    //  X   22
    'd',    //  D   23
    'e',    //  E   24
    '4',    //  4   25
    '3',    //  3   26
    0,  //  VAGO    27?
    0,  //  VAGO    28?
    ' ', // SPACE    29
    'v',    //  V   2A
    'f',    //  F   2B
    't',    //  T   2C
    'r',    //  R   2D
    '5',    //  5   2E
    0,  //  VAGO    2F?
    0,  //  VAGO    30?
    'n',    //  N   31
    'b',    //  B   32
    'h',    //  H   33
    'g',    //  G   34
    'y',    //  Y   35
    '6',    //  6   37
    0,  //  VAGO    37?
    0,  //  VAGO    38?
    0,  //  VAGO    39?    
    'm',    //  M   3A
    'j',    //  J   3B
    'u',    //  U   3C
    '7',    //  7   3D
    '8',    //  8   3E
    0,  //  VAGO    3F?
    0,  //  VAGO    40?
    ',',// VIRGULA  41
    'k',    //  K   42
    'i',    //  I   43
    'o',    //  O   44
    '0',    //  0   45
    '9',    //  9   46
    0,  //  VAGO    47?
    0,  //  VAGO    48?
    '.',    //  .   49
    ';',    //  ;   4A
    'l',    //  L   4B
    0,    //  �     4C
    'p',    //  P   4D
    '-',    //  -   4E
    0,  //  VAGO    4F?
    0,  //  VAGO    50?    
    '\'',  //  contra barra    51? 
    0, // ascento ^ 52
    0,  //  VAGO    53?  
    0,//  ascento � 54
    '=',// IGUAL    55
    0,  //  VAGO    56?
    0,  //  VAGO    57?  
    0,  //  CAPS LOCK 58
    0,  //  SHIFT B   59
    0,  //  ENTER    5A 
    '[',//  FECHA COUCHETE 5B 
    0,  //  VAGO    5C?
    ']',// CONTRA BARRA 5D    
    0,  //  VAGO    5E?
    0,  //  VAGO    5F?  
    0,  //  VAGO    60? 
    0,  //  VAGO    61? 
    0,  //  VAGO    62?     
    0,  //  VAGO    63?  
    0,  //  VAGO    64?  
    0,  //  VAGO    65?
    0,  //  BACK SPACE 66 
    0,  //  VAGO    67?
    0,  //  VAGO    68?  
    '1',// NUM LOCK 69 
    0,  //  VAGO    6A? 
    '4',// NUM LOCK 6B     
    '7',// NUM LOCK 6C  
    0,  //  VAGO    6D?  
    0,  //  VAGO    6E?
    0,  //  VAGO    6F?
    '0',// NUM LOCK 70  
    '.',// NUM LOCK 71 
    '2',// NUM LOCK 72 
    '5',// NUM LOCK 73     
    '6',// NUM LOCK 74  
    '8',// NUM LOCK 75  
    0,  // ESC      76  
    0,  // ATIVA NUM LOCK  77  
    0,  //  F11     78
    '+',// NUM LOCK 79    
    '3',// NUM LOCK 7A
    '-',// NUM LOCK 7B  
    '*',// NUM LOCK 7C 
    '9',// NUM LOCK 7D 
    0,  //  VAGO    7E?     
    0,  //  VAGO    7F?  
    0,  //  VAGO    80?  
    0,  //  VAGO    81? 
    0,  //  VAGO    82? 
    0,  //  F7      83  
};
const char tabelaConvertePcKeyboardToAsciiMaiusculo[]={
    0,  //  VAGO    00?
    0,  //  F9      01
    0,  //  VAGO    02?
    0,  //  F5      03
    0,  //  F3      04
    0,  //  F1      05
    0,  //  F2      06
    0,  //  F12     07
    0,  //  VAGO    08?
    0,  //  F10     09
    0,  //  F8      0A
    0,  //  F6      0B
    0,  //  F4      0C
    0,  //  TAB     0D
    '\'',  //  contra barra       0E
    0,  //  VAGO    OF?
    0,  //  VAGO    10?
    0,  //  ALT     11
    0,  //  SHIFT A 12
    0,  //  VAGO    13?
    0,  //  CONTROL 14
    'Q',    //  Q   15
    '1',    //  1   16
    0,  //  VAGO    17?
    0,  //  VAGO    18?
    0,  //  VAGO    19?
    'Z',    //  Z   1A
    'S',    //  S   1B
    'A',    //  A   1C
    'W',    //  W   1D
    '2',    //  2   1E
    0,  //  VAGO    1F?
    0,  //  VAGO    20?
    'C',    //  C   21
    'X',    //  X   22
    'D',    //  D   23
    'E',    //  E   24
    '4',    //  4   25
    '3',    //  3   26
    0,  //  VAGO    27?
    0,  //  VAGO    28?
    ' ', // SPACE    29
    'V',    //  V   2A
    'F',    //  F   2B
    'T',    //  T   2C
    'R',    //  R   2D
    '5',    //  5   2E
    0,  //  VAGO    2F?
    0,  //  VAGO    30?
    'N',    //  N   31
    'B',    //  B   32
    'H',    //  H   33
    'G',    //  G   34
    'Y',    //  Y   35
    '6',    //  6   37
    0,  //  VAGO    37?
    0,  //  VAGO    38?
    0,  //  VAGO    39?    
    'M',    //  M   3A
    'J',    //  J   3B
    'U',    //  U   3C
    '7',    //  7   3D
    '8',    //  8   3E
    0,  //  VAGO    3F?
    0,  //  VAGO    40?
    ',',// VIRGULA  41
    'K',    //  K   42
    'I',    //  I   43
    'O',    //  O   44
    '0',    //  0   45
    '9',    //  9   46
    0,  //  VAGO    47?
    0,  //  VAGO    48?
    '.',    //  .   49
    ';',    //  ;   4A
    'L',    //  L   4B
     0,    //  �   4C
    'P',    //  P   4D
    '-',    //  -   4E
    0,  //  VAGO    4F?
    0,  //  VAGO    50?    
    '/',//  barra   51 
    0, //  ascento ^52
    0,  //  VAGO    53?  
    0,//  ascento agudo 54
    '=',// IGUAL    55
    0,  //  VAGO    56?
    0,  //  VAGO    57?  
    0,  //  CAPS LOCK 58
    0,  //  SHIFT B   59
    0,  //  ENTER    5A 
    '[',//  FECHA COUCHETE 5B 
    0,  //  VAGO    5C?
    ']',// CONTRA BARRA 5D    
    0,  //  VAGO    5E?
    0,  //  VAGO    5F?  
    0,  //  VAGO    60? 
    0,  //  VAGO    61? 
    0,  //  VAGO    62?     
    0,  //  VAGO    63?  
    0,  //  VAGO    64?  
    0,  //  VAGO    65?
    0,  //  BACK SPACE 66 
    0,  //  VAGO    67?
    0,  //  VAGO    68?  
    '1',// NUM LOCK 69 
    0,  //  VAGO    6A? 
    '4',// NUM LOCK 6B     
    '7',// NUM LOCK 6C  
    0,  //  VAGO    6D?  
    0,  //  VAGO    6E?
    0,  //  VAGO    6F?
    '0',// NUM LOCK 70  
    '.',// NUM LOCK 71 
    '2',// NUM LOCK 72 
    '5',// NUM LOCK 73     
    '6',// NUM LOCK 74  
    '8',// NUM LOCK 75  
    0,  // ESC      76  
    0,  // ATIVA NUM LOCK  77  
    0,  //  F11     78
    '+',// NUM LOCK 79    
    '3',// NUM LOCK 7A
    '-',// NUM LOCK 7B  
    '*',// NUM LOCK 7C 
    '9',// NUM LOCK 7D 
    0,  //  VAGO    7E?     
    0,  //  VAGO    7F?  
    0,  //  VAGO    80?  
    0,  //  VAGO    81? 
    0,  //  VAGO    82? 
    0,  //  F7      83  
};
