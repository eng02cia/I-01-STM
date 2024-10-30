void ocultaPesoDwin(void);
void mostraPesoDwin(void);
void limpaLinha2Dwin(void);
void transfereCaracterLcdLinha1Dwin(void);
void transfereCaracterLcdLinha2Dwin(void);
void transfereCaracterLcdMenu1Dwin(void);
void transfereCaracterLcdMenu2Dwin(void);
void zeraTelaInicio(void);
//void trocaTelaDwin(void);

uint8_t frameDwin0x1000[50];
uint8_t frameDwin0x1100[50];
uint8_t frameDwin0x1200[50];
uint8_t frameDwin0x1300[50];
uint8_t frameDwin0x1400[50];
uint8_t frameDwin0x1500[50];
uint8_t frameDwin0x2000[50];

static unsigned char pegaValorAd[10];
uint8_t frameDwin0x3000[50];
static unsigned char trocarPaginaDwin;
static unsigned char defineFont;
static unsigned char voltaFonte;
