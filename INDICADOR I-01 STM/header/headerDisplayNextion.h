//////////////////////////////////////////////////////////////////////////////////
/**/																			//
/**/					   /*PROTOTIPOS DISPLAY*/								//
/**/																			//
//////////////////////////////////////////////////////////////////////////////////


void mostraPesoKg(void);
void ocultaPesoKg(void);
void transfereCaracterLcdLinha1(void);
void transfereCaracterLcdLinha2(void);
void transfereBkpCaracterLcdMenuLinha1(void);
void transfereBkpCaracterLcdMenuLinha2(void);
void transfereCaracterLcdErroLimiteZero(void);
void limpaLinha2(void);
void setaKgTelaPeso(void);
void mostraPesoTaraKg(void);
//////////////////////////////////////////////////////////////////////////////////
/*																				//
**						VARIAVEIS UTILIZADAS DISPLAY							//
*/																				//
//////////////////////////////////////////////////////////////////////////////////

const char charErroNextion0PesoCargaMaxima[]=     {"PESO CALIBRACAO MAIOR"};
const char charErroNextion1PesoCargaMaxima[]=     {"CARGA MAXIMA"};
const char charErroNextion0PesoCalibracao[]=      {" ERRO DIVISAO   "};
const char charErroNextion1PesoCalibracao[]= 	  {"  MUITO BAIXA   "};

const char linhaPeso[]=      {"t2.txt=\""};
const char linha1Peso[]=      {"t3.txt=\""};
const char linha2Peso[]=      {"t4.txt=\""};


const char linha0LigaDisplay[]=      {"t0.txt=\"INDICADOR I-01"};
const char linha1LigaDisplay[]=      {"t1.txt=\""};
const char linha2LigaDisplay[]=      {"t2.txt=\"STM 1.0"};

const char linha0Menu[]=      {"t5.txt=\""};
const char linha1Menu[]=      {"t6.txt=\""};

const char linhaKg[]= 	{"t30.txt=\""};

//unsigned char frameCalibracao0Nextion[50];
//unsigned char frameCalibracao1Nextion[50];
unsigned char frame1Menu[50];
unsigned char frame2Menu[50];
unsigned char frameSenhaProg[50];
unsigned char frame1Serial[50];
unsigned char frame2Serial[50];
unsigned char frameTx0Nextion[100];
unsigned char frameTx1Nextion[100];
unsigned char frameTx2Nextion[50];
unsigned char frameTx3Nextion[50];
unsigned char frameKgPeso[50];
static unsigned char trocarPaginaNextion;
int trocarPaginaNextionNovo;
static unsigned char trocarPaginaPeso;
static unsigned char comunicandoDisplayNextion;
static unsigned char trocaPaginaMenuPeso;
static unsigned int tempTrocaPaginaPeso;

