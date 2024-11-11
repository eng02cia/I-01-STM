//////////////////////////////////////////////////////////////////////////////////		
//Fun��es de programa��o do peso do corte                                       //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de fun��o
void funcaoProgramaHoraData(void);
void verificaHoraValida (void);
void verificaMinutoValido (void);
void verificaDataValida (void);
void validaData(void);
void classificaMes(void);
void telaMostraProgHoraData(void);
void funcaoPiscaCaracter(void);
//variaveis utilizadas

//static unsigned char letraTemp;
//unsigned char ValorProgramado;
static unsigned char arrayHora[2];
static unsigned char arrayMinuto[2];
static unsigned char arrayDia[2];
static unsigned char arrayMes[2];
static unsigned char arrayAno[2];

static unsigned char arrayProgHora[2];
static unsigned char arrayProgMinuto[2];
static unsigned char arrayProgDia[2];
static unsigned char arrayProgMes[2];
static unsigned char arrayProgAno[2];


static unsigned char horaTemp;
static unsigned char minutoTemp;
//static unsigned char segundoTemp;
static unsigned char diaTemp;
static unsigned char mesTemp;
static unsigned char anoTemp;
static unsigned char verificaValidade;
//static unsigned char posicaoDigitoProgHora;
static unsigned char mes31Dias;
static unsigned char anoBissexto;
static unsigned char tempProgDataHora;
static unsigned char tempoPiscaCaracter;
static unsigned char piscaCaracter;
static unsigned char marcaEdicao;
//indica qual o menu atual que esta sendo programado
enum 
{
    menuProgramaHoraH, 
    menuProgramaHoraL,     
    menuProgramaMinutoH,  
    menuProgramaMinutoL,     
    menuProgramaDiaH,
    menuProgramaDiaL,
    menuProgramaMesH,    
    menuProgramaMesL,  
    menuProgramaAnoH,  
    menuProgramaAnoL,      
    menuProgramaRelogioEmEspera,
}   menuProgramacaoRelogioAtual = menuProgramaRelogioEmEspera;

// constantes utilizadas na fun��o
#define         mesFevereiro				02

//TELA PROG PORTUGUES
const char telaProgHoraDataLcdPT[]=   	{"PROG HORA/DATA  ""                "};
const char telaHoraInvalidaLcdPT[]=   	{"HORA INVALIDA   ""                "};
const char telaDataInvalidaLcdPT[]=   	{"DATA INVALIDA   ""                "};

//TELA PROG ESPANHOL
const char telaProgHoraDataLcdESP[]=   	{"PROG HORA/FECHA ""                "};
const char telaHoraInvalidaLcdESP[]=  	{"HORA INVALIDO   ""                "};
const char telaDataInvalidaLcdESP[]=   	{"FECHA INVALIDO  ""                "};

//TELA PROG INGLES
const char telaProgHoraDataLcdING[]=   	{"PROG TIME/DATE  ""                "};
const char telaHoraInvalidaLcdING[]=   	{"INVALID HOUR    ""                "};
const char telaDataInvalidaLcdING[]=   	{"INVALID DATE    ""                "};
