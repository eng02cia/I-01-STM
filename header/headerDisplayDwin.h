void ocultaPesoDwin(void);
void mostraPesoTesteDisplay(void);
void mostraPesoDwin(void);
void limpaLinha2Dwin(void);
void transfereCaracterLcdLinha1Dwin(void);
void transfereCaracterLcdLinha2Dwin(void);
void transfereCaracterLcdMenu1Dwin(void);
void transfereCaracterLcdMenu2Dwin(void);
void zeraPesoParaErro(void);
void zeraErroParaPeso (void);
void limpaLinha1Dwin(void);
void transfereCaracterDwinLinhasCorrente(void);
void transfereCaracterDwinLinha1Aplicacao(void);
void transfereCaracterDwinLinha2Aplicacao(void);
void transfereCaracterDwinLinha2NumBrinco(void);
void transfereCaracterDwinTelaInicial(void);
void carregaTela1(void);
void carregaTela2(void);
void carregaTela11(void);
void backLightDwinMaximo(void);
void backLightDwinMinimo(void);
//void trocaTelaConformeNegativo(void);
uint8_t frameDwin0x1000Erro[50];
uint8_t frameDwin0x2000ErroCponto[50];
//static unsigned char loopConverteCorrente;
unsigned char tempArrayCorrente[10];
uint8_t frameTxDwin[50];
//uint8_t frameDwin0x1100[50]; //KG
//uint8_t frameDwin0x1200[50]; //LINHA 1
//uint8_t frameDwin0x1300[50]; //LINHA 2
//uint8_t frameDwin0x1400[50]; //MENU 1
//uint8_t frameDwin0x1500[50]; //MENU 2
//uint8_t frameDwin0x1600[6]; //MENU 2

//uint8_t frameDwin0x2000[50]; //PESO TELA 1
//uint8_t frameDwin0x2100[50]; //PESO TELA 2
//uint8_t frameDwin0x2200[50]; //PESO TELA 3
//uint8_t frameDwin0x2300[50]; //PESO TELA 4

//uint8_t frameDwin0x3000[50]; //PESO TELA 1 COM PONTO
//uint8_t frameDwin0x3100[50]; //PESO TELA 2 COM PONTO
//uint8_t frameDwin0x3200[50]; //PESO TELA 3 COM PONTO
//uint8_t frameDwin0x3300[50]; //PESO TELA 4 COM PONTO

//uint8_t frameDwin0x4000[50]; //PESO TELA 1 COM PONTO NEGATIVO
//uint8_t frameDwin0x4100[50]; //PESO TELA 2 COM PONTO NEGATIVO
//uint8_t frameDwin0x4200[50]; //PESO TELA 3 COM PONTO NEGATIVO
//uint8_t frameDwin0x4300[50]; //PESO TELA 4 COM PONTO NEGATIVO

//uint8_t frameDwin0x5000[50]; //NIVEL BATERIA
//uint8_t frameDwin0x5100[50]; //NIVEL BATERIA
//uint8_t frameDwin0x1800[50];
uint8_t telaPesoDwin[7];
uint8_t tempTelaDwin;
uint8_t indexRetiraPontoDwin;
uint8_t loopRetiraPontoDwin;
static unsigned char limpaLinha1;

const char charTela0Dwin[]={0x5A,0xA5,0x07,0x82,0x00,0x84,0x5A,0x01,0,0};
const char charTela1Dwin[]={0x5A,0xA5,0x07,0x82,0x00,0x84,0x5A,0x01,0,1};
const char charTela2Dwin[]={0x5A,0xA5,0x07,0x82,0x00,0x84,0x5A,0x01,0,2};
const char charTela11Dwin[]={0x5A,0xA5,0x07,0x82,0x00,0x84,0x5A,0x01,0,11};

const char pesoTraco[]= {"-------"};
const char tx5BytesDwin[]= {0x5A,0xA5,0x05,0x82};
const char tx6BytesDwin[]= {0x5A,0xA5,0x06,0x82};
const char tx16BytesDwin[]= {0x5A,0xA5,0x13,0x82};


//static unsigned char tempFrameDwin[32];
static unsigned char tempPosicaoPontoDwin;
static unsigned char trocarPaginaDwin;
static unsigned char fazTelaInicialPesoDwin;
static unsigned char contadorInicialTelaPesoDwin;
//static unsigned char controleTelaInicialPesoDwin;
enum
{
	 ocultaPeso,
	 holdPeso,
	 pesoReal,
}controleTelaDwin;

