//////////////////////////////////////////////////////////////////////////////////		
//funcoes de programa��o do peso do corte                                       //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de funcoes
void controleCalibraIndicador(void);
void telaPosicaoPontoDecimalIndicador (void);
void telaDefineDegrauPesoIndicador(void);
void piscaDigitoProgIndicador(void);
void piscaDigitoProgIndicadorNextion(void);
void manipulacaoDoDigitoDoIndicador(void);
void metodoPiscaProgIndicador(void);
void telaControlaIncrementoDegralIndicador(void);
void telaValorFiltroDigitalIndicador(void);
void telaErroPesoCalibracao (void);
void telaErroCapacidadeMaxima(void);
void verificaSenhaAcessoCalibracao(void);
void telaErroSenhaTecnica(void);
void controlaPiscaDigitoProgSenha(void);
void apagaSenha(void);
void telaSenhaDeAcessoCalibracao(void);
void telaPesoCargaMaximaIndicador(void);
void telaPesoCalibracaoIndicador(void);
void telaPesoZeroIndicador(void);
void telaMostraValorProDivisaoInterna(void);
void calculaDivisaoInterna();
void rotacionaArrayTelaValorDivisao(void);
//telas 
const char telaVerificaSenhaLcd[]  =      {"DIGITE SENHA    ""                "};
const char telaMostraSenhaLcd[]  =        {"DIGITE SENHA    ""                "};
const char charValorFiltroDigital[]=      {"FILTRO DIGITAL  ""                "};
const char charPosicaoPontoDecimal[]=     {"POSICAO PONTO   ""                "};
const char charDegrauPesoIndicador[]=     {"DEGRAU PESO     ""                "};
const char charCapacidadeMaxIndicador[]=  {"CAPACIDADE MAX  ""                "};
const char charPesoCalibracaoIndicador[]= {"PESO CALIBRACAO ""                "};
const char charSemPesoIndicador[]=        {"SEM PESO        ""                "};
const char charComPesoIndicador[]=        {"COM PESO        ""                "};
const char telaSenhaInvalidaLcd[]=        {"SENHA INVALIDA  ""                "};

const char charErroPesoCargaMaxima[]=     {"P/CALIBRACAO MA ""IOR CARGA MAXIMA"};
const char charErroPesoCalibracao[]=      {" ERRO DIVISAO   ""  MUITO BAIXA   "};

const char charSemPonto[]=          {"00000."};
const char charCemGramasPonto[]=    {"0000.0"};
const char charDezGramasPonto[]=    {"000.00"};
const char charUmaGramasPonto[]=    {"00.000"};
const char charUmDecigramaPonto[]=  {"0.0000"};
const char charAguarde[]=   {"AGUARDE   "};
const char charZeroOk[]=    {"ZERO OK   "};
const char charCerto[]=     {"CERTO     "};
const char senhaTecnica[]= {"4358"};
const char senhaProgDivisao[]={"6752"};


const char telaMenuProgValorDivisao[] = {"VD:             ""                "};
static unsigned char tempProgIndicador;
static unsigned char arrayTempIndicador[6];
static unsigned char arrayTemp1Indicador[6];
static unsigned char arrayTemp2Indicador[6];
static unsigned char senhaTemp[4];
static unsigned char tempoPiscaProgIndicador;
static unsigned char senhaValidada;

static float tempMediaCalibraIndicador;
static float tempAd;
static long int temp1Ad;
static float valorAdPesoCalibracao;
//static unsigned char loopMediaZero;
static unsigned char *buffer;
static unsigned char loopMediaCalibracao;
static unsigned char fazZeroIndicadorPeso;
static unsigned char fazTaraIndicadorPeso;
static unsigned char tempoPiscaSenha;
static unsigned char tempTeclaControlZero;
static unsigned char operacaoComTeclado;


static unsigned char arrayTempProgDivisao[10];
static unsigned char valorAtualDivisaoInterna[10];
static unsigned char loopProgDivisaoIntena;
float tempFloatCalculaDivisao;
static unsigned char loopConverteDivisaoInterna;

union
{
     float float32;
     char array4[4]; 
     long int int32;
}conversaoTiposDivisao;

// variaveis utilizadas no calculo da divisao
//uldiv_t result;
static float tempResultado;
static float tempFloat;
static unsigned calculaRestoCalibracao;

short flagTempoPiscaProgIndicador;
short flagPiscaProgIndicador;
short flagPiscaDigitoSenha;
short flagTempoPiscaDigitoSenha;
union
{
     float float32;
     char array4[4]; 
     long int int32;
}conversaoTipos;
//variaveis utilizadas

//indica qual o menu atual que esta sendo Acessado
enum 
{  
    menuCalibraIndicadorEmEspera, 
    menuVerificaSenhaCalibracao,
    menuAjustaValorDivisao,
    menuFiltroDigital,
    menuDefinePontoDecimal,     
    menuDefineDegrauPeso,     
    menuCapacidadeMaxima,  
    menuPesoCalibracao, 
    menuSemPeso, 
    menuComPeso,      
}menuCalibraIndicador = menuCalibraIndicadorEmEspera;
//gerencia a manipula��o dos digitos de um algarimos durante a programa��o
enum
{
    digitoZero,
    digitoUm,
    digitoDois,
    digitoTres,   
    digitoQuatro,
    digitoCinco,    
}digitoAtualIndicador = digitoZero;

#define _SEM_PONTO    0
#define _CEMGRAMAS    1
#define _DEZGRAMAS    2
#define _UMGRAMA     3
#define _DECIGRAMA    4
#ifdef indicadorCargaViva
#define _VMAX_FILTRO_DIGITAL 4
#endif
#ifndef indicadorCargaViva
#define _VMAX_FILTRO_DIGITAL 30
#endif
//#define limiteProgFiltroDigital 121
//flags utilizados na programa��o

