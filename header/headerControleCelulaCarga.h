//////////////////////////////////////////////////////////////////////////////////		
//         funcoes de controle das medicoes da celula de carga           		//	
//////////////////////////////////////////////////////////////////////////////////
//prototipos de funcao utilizadas
void inicializaLedsIndicador(void);
void mostraPesoIndicador(void);
void trataPesoAdIndicador(void);
void fazArredondamentoPeso(void);
void trataPesoBrutoIndicador(void);
void trataPesoTaraIndicador(void);
void trataPesoLiquidoIndicador(void);
void controlIndicacaoPesoEstavelLinhaI(void);


void tempoEstabilidadeCargaViva(void);
//variaveis utilizadas no calculo do peso
//registra o peso atual da balanca 01

static unsigned char pesoBrutoIndicadorAscii[7];
static unsigned char pesoTaraIndicadorAscii[7];
static unsigned char pesoLiquidoIndicadorAscii[7];
static unsigned char pesoConvertido[7];
static unsigned char pesoCarregamentoAscii[7] =     {' ',' ',' ',' ',' ',' ','0'};
// static unsigned char arrayTempCalculaPeso[9];
static unsigned char referenciaPesoEstavelAscii[7];

static unsigned long int valorPesoBrutoIntIndicador;
static unsigned long int valorPesoTaraIntIndicador;
static unsigned long int valorPesoLiquidoIntIndicador;

static float valorPesoBrutoFloatIndicador;
static float valorPesoTaraFloatIndicador;
static float valorPesoLiquidoFloatIndicador;
//static float valorPesoConvertidoFloatIndicador;

//static unsigned long int valorPesoBrutoIndicador;
//static unsigned long int valorPesoTaraIndicador;
//static unsigned long int valorPesoLiquidoIndicador;

//static float valorPesoBrutoCarregamento;//nao mudar do tipo float
static float valorPesoTempIndicador;
static float valorPesoTESTE1;
//static float valorPesoTESTE2;

static float valorPesoAnteriorCargaViva;
float f;
static unsigned long int tempLongInt;
static float dataAdPeso;
static float dataAdMediaPronta;
static float valorCorrigidoAd;
static float valorZeroIndicador;
static float valorTaraIndicador;
//static unsigned long int valorCalibracaoIndicador;
static unsigned long int valorPesoCargaMaxima;
static float valorDivisaoIndicador;
//static float valorDivisaoIndicador;
//static unsigned char statusPesoIndicador;
static unsigned char arrayPesoTemp[7];
static unsigned char arrayPesoTemp1[7];
static unsigned char arrayConverteToInteiro[8];
static unsigned char tempControleCelulaCarga;
//static unsigned char arrayPesoFinal[7];
static unsigned char *index1Indicador;
static unsigned char *index2Indicador;
static unsigned char loopMediaAdPeso;
static unsigned char loopTempIndicador;
//static unsigned char statusPesoNegativo;
static unsigned char indicadorEmZero;
static unsigned char controleFiltroDigital;
static float floatTemp;
static float float1Temp;
//static float limiteHPesoCargaViva;
//static float limiteLPesoCargaViva;
//static unsigned char controleInicioCongelaPeso;
//static unsigned char tempoMostraPesoOscilanteCargaVivatempo;
//static unsigned char loopFimCorvetePeso;
//static unsigned char offSetPesoAtual;
//static float offSetTempPesoAtual;
//static float tempPesoIndicador;
//short statusPesoPositivoNegativoInidicador;
short statusControleSobreCarga;
short statusControleSubCarga;
short statusControleMostraPesoNegativo;
short statusPesoNegativoTemp;
short trantandoPesoBruto;
short flagFazMediaAd;
short flagFimCalibracao;
//short flagNovaLeituraCargaViva;
short flagTempoMostraPesoOscilanteCargaViva;
char *buf;
//static unsigned char status;
static float floatTemp;
static float floatTemp1;
//static unsigned char controleNovaLeituraCargaViva;
//static unsigned char valorfloatLimiteH[6];
//static unsigned char valorfloatLimiteL[6];
//static unsigned char valorfloatPesoTeste[9];
static unsigned char arrayPesoConvertidoCelulaCarga[9];
static unsigned char loopConvertePesoCelulaCarga;
//static unsigned char loopTestePeso;
static unsigned char controleTipoZero;
static unsigned char valorLimiteZeroInicial;//usado na inicializacao
static unsigned char tempComparaCeluCarga;
static unsigned char tempoIndicaPesoEstavel;

short flagLimiteZeroInicial;
short flagIndicaPesoEstavel;


#define _PESOPOSITIVO 1
#define _PESONEGATIVO 0
#define _TARAATIVADA  1
#define _TARADESATIVADA  0

#define _CEMPORCENTO 0 
#define _MILPORCENTO 1
//#define pinoMostraZero LATDbits.LD0
//#define pinoMostraTara LATDbits.LD1



