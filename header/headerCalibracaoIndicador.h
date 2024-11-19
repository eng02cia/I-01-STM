//////////////////////////////////////////////////////////////////////////////////		
//funcoes de programacao do peso do corte                                       //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de funcoes
void controleCalibraIndicador(void);
void telaPosicaoPontoDecimalIndicador (void);
void telaDefineDegrauPesoIndicador(void);
void piscaDigitoProgIndicador(void);
void piscaDigitoProgIndicadorNextion(void);
void manipulacaoDoDigitoDoIndicador(void);
void metodoPiscaProgIndicador(void);
void telaControlaIncrementodegrauIndicador(void);
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

//telas PORTUGUES
const char telaVerificaSenhaLcdPT[]  =      {"DIGITE SENHA    ""                "};
const char telaMostraSenhaLcdPT[]  =        {"DIGITE SENHA    ""                "};
const char charValorFiltroDigitalPT[]=      {"FILTRO DIGITAL  ""                "};
const char charPosicaoPontoDecimalPT[]=     {"POSICAO PONTO   ""                "};
const char charDegrauPesoIndicadorPT[]=     {"DEGRAU PESO     ""                "};
const char charCapacidadeMaxIndicadorPT[]=  {"CAPACIDADE MAX  ""                "};
const char charPesoCalibracaoIndicadorPT[]= {"PESO CALIBRACAO ""                "};
const char charSemPesoIndicadorPT[]=        {"SEM PESO        ""                "};
const char charComPesoIndicadorPT[]=        {"COM PESO        ""                "};
const char telaSenhaInvalidaLcdPT[]=        {"SENHA INVALIDA  ""                "};
const char charErroPesoCargaMaximaPT[]=     {"P/CALIBRACAO MA ""IOR CARGA MAXIMA"};
const char charErroPesoCalibracaoPT[]=      {"ERRO: DIVISAO   ""  MUITO BAIXA   "};

//telas INGLES
const char telaVerificaSenhaLcdING[]  =      {"TYPE PASSWORD   ""                "};
const char telaMostraSenhaLcdING[]  =        {"TYPE PASSWORD   ""                "};
const char charValorFiltroDigitalING[]=      {"DIGITAL FILTER  ""                "};
const char charPosicaoPontoDecimalING[]=     {"DOT POSITION    ""                "};
const char charDegrauPesoIndicadorING[]=     {"WEIGHT STEP     ""                "};
const char charCapacidadeMaxIndicadorING[]=  {"MAX CAPACITY    ""                "};
const char charPesoCalibracaoIndicadorING[]= {"CALIB. WEIGHT   ""                "};
const char charSemPesoIndicadorING[]=        {"NO WEIGHT       ""                "};
const char charComPesoIndicadorING[]=        {"WITH WEIGHT     ""                "};
const char telaSenhaInvalidaLcdING[]=        {"INVALID PASSWORD""                "};
const char charErroPesoCargaMaximaING[]=     {"CALIB. WEIGHT   ""GREATER THAN MAX"};
const char charErroPesoCalibracaoING[]=      {"ERROR: DIVISION ""  TOO LOW       "};

//telas ESPANHOL
const char telaVerificaSenhaLcdESP[]  =      {"CONTRASENA      ""                "};
const char telaMostraSenhaLcdESP[]  =        {"CONTRASENA      ""                "};
const char charValorFiltroDigitalESP[]=      {"FILTRO DIGITAL  ""                "};
const char charPosicaoPontoDecimalESP[]=     {"POSICION PUNTO  ""                "};
const char charDegrauPesoIndicadorESP[]=     {"PASO DE PESO    ""                "};
const char charCapacidadeMaxIndicadorESP[]=  {"CAPACIDAD MAXIMA""                "};
const char charPesoCalibracaoIndicadorESP[]= {"PESO CALIBRACION""                "};
const char charSemPesoIndicadorESP[]=        {"SIN PESO        ""                "};
const char charComPesoIndicadorESP[]=        {"CON PESO        ""                "};
const char telaSenhaInvalidaLcdESP[]=        {"CONTRASENA NO VA""LIDA            "};
const char charErroPesoCargaMaximaESP[]=     {"PESO DE CALIBRAC""ION MUY ALTO    "};
const char charErroPesoCalibracaoESP[]=      {"ERROR: DIVISION ""DEMASIADO BAJA  "};


const char charSemPonto[]=          {"00000."};
const char charCemGramasPonto[]=    {"0000.0"};
const char charDezGramasPonto[]=    {"000.00"};
const char charUmaGramasPonto[]=    {"00.000"};
const char charUmDecigramaPonto[]=  {"0.0000"};

// telas portugues
const char charAguardePT[]=   {" AGUARDE  "};
const char charZeroOkPT[]=    {" ZERO OK  "};
const char charCertoPT[]=     {" CERTO    "};

// telas ingles
const char charAguardeING[]=   {" WAIT     "};
const char charZeroOkING[]=    {" ZERO OK  "};
const char charCertoING[]=     {" DONE     "};

// telas espanhol
const char charAguardeESP[]=   {" ESPERAR  "};
const char charZeroOkESP[]=    {" CERO OK  "};
const char charCertoESP[]=     {" HECHO    "};

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
//gerencia a manipulacao dos digitos de um algarimos durante a programacao
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

#define _VMAX_FILTRO_DIGITALI01 11
//#define limiteProgFiltroDigital 121
//flags utilizados na programacao

