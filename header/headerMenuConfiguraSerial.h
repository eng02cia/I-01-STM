//////////////////////////////////////////////////////////////////////////////////		
//hederes do menu de acesso a programa��o do sistema                            //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de fun��o
void funcaoMenusConfiguraSerial_1(void);
void controlaTxSerial_1(void);
void telaMostraAtivaDesativaSerial_1(void);
void telaMostraProgVelocidadeSerial_1(void);
void telaMostraTipoPortaSerial_1(void);
void telaMostraTipoSaidaDadosSerial_1(void);
void telaMostraTipoSaidaDadosSerial_2(void);
void telaMostraEnderecoIndicador(void);
void telaMostraQtFramePorSegundo(void);
void telaMostraProgVelocidadeSerial_1(void);
//contantes utilizadas na fun��o                

// telas portugues                                                 
const char charTelaConfiguraVelocidadeSerialPT[]={"VELOCID/SERIAL 1""                "};
const char charTelaAtivaDesativaSerial_1PT[]=    {"ATIVA/DESATIVA  ""SERIAL 1        "};
const char charTelaEscolhePortaSerial_1PT[]=     {"PORTA SERIAL 1  ""                "};
const char charTelaFormaSaidaDadosSerial_1PT[]=  {"DADOS SERIAL 1  ""                "};
const char charTelaFormaSaidaDadosSerial_2PT[]=  {"DADOS SERIAL 2  ""                "};
const char charTelaEnderecoIndicadorSerial_1PT[]={"END INDICADOR   ""SERIAL 1        "};
const char charTelaQtFramePorSegundoPT[]=        {"QT FRAME POR SEG""SERIAL 1        "};
const char charAtivadoPT[]= {"ATIV"};
const char charDesativadoPT[]={"DESAT"};

// telas ingles                                                 
const char charTelaConfiguraVelocidadeSerialING[]={"SERIAL 1 BAUD   ""                "};
const char charTelaAtivaDesativaSerial_1ING[]=    {"ENABLE/DISABLE  ""SERIAL 1        "};
const char charTelaEscolhePortaSerial_1ING[]=     {"SERIAL 1 PORT   ""                "};
const char charTelaFormaSaidaDadosSerial_1ING[]=  {"SERIAL 1 DATA   ""                "};
const char charTelaFormaSaidaDadosSerial_2ING[]=  {"SERIAL 2 DATA   ""                "};
const char charTelaEnderecoIndicadorSerial_1ING[]={"INDICATOR ADDRES""SERIAL 1        "};
const char charTelaQtFramePorSegundoING[]=        {"FRAMES PER SEC  ""SERIAL 1        "};
const char charAtivadoING[]= {"ENAB"};
const char charDesativadoING[]={"DISAB"};

// telas espanhol                                                 
const char charTelaConfiguraVelocidadeSerialESP[]={"SERIE 1 BAUDIO  ""                "};
const char charTelaAtivaDesativaSerial_1ESP[]=    {"ACTIVA/DESACTIVA""SERIAL 1        "};
const char charTelaEscolhePortaSerial_1ESP[]=     {"PUERTO SERIE 1  ""                "};
const char charTelaFormaSaidaDadosSerial_1ESP[]=  {"DATOS SERIE 1   ""                "};
const char charTelaFormaSaidaDadosSerial_2ESP[]=  {"DATOS SERIE 2   ""                "};
const char charTelaEnderecoIndicadorSerial_1ESP[]={"DIRECCION INDIC.""SERIAL 1        "};
const char charTelaQtFramePorSegundoESP[]=        {"CUADROS POR SEG.""SERIAL 1        "};
const char charAtivadoESP[]= {"ACTIV"};
const char charDesativadoESP[]={"DESACT"};

const char charVelocidade1200Kbps[]=    {"1200"};
const char charVelocidade2400Kbps[]=    {"2400"};
const char charVelocidade4800Kbps[]=    {"4800"};
const char charVelocidade9600Kbps[]=    {"9600"};
const char charVelocidade19200Kbps[]=   {"19200"};
const char charVelocidade38400Kbps[]=   {"38400"};
const char charVelocidade57600Kbps[]=   {"57600"};
const char charVelocidade115200Kbps[]=   {"115200"};


const char charRs232[]={"RS232"};
const char charRs485[]={"RS485"};

const char charTcContinua_1[]={"TC CONTINUA_1"};
const char charTcContinua_2[]={"TC CONTINUA_2"};
const char charModBusRtu[]= {"MODBUS-RTU"};
const char charSigmaciaSa[]= {"SIGMACIA-SA"};

const char linha0Serial[]=      {"t6.txt=\""};
const char linha1Serial[]=      {"t7.txt=\""};

unsigned char frameSerialNextion[100];
unsigned char frameVelocidadeSerial[100];
unsigned char frameSaidaDadosNextion[100];
unsigned char frameEndindicadorNextion[100];

//unsigned char frameSaidaDadosNextion[100];


static unsigned char tempConfigSerial;


const char charTelaNextionConfiguraVelocidadeSerial[]={"VELOCID/SERIAL 1"};
const char charTelaNextionAtivaDesativaSerial_1[]=    {"ATIVA/DESATIVA  ""SERIAL 1"};
const char charTelaNextionEscolhePortaSerial_1[]=     {"PORTA SERIAL 1  "};
const char charTelaNextionFormaSaidaDadosSerial_1[]=  {"DADOS SERIAL 1"};
const char charTelaNextionFormaSaidaDadosSerial_2[]=  {"DADOS SERIAL 2  "};
const char charTelaNextionEnderecoIndicadorSerial_1[]={"END INDICADOR   "};
const char charTelaEndereco2IndicadorSerial_1[]=	  {"SERIAL 1        "};
const char charTelaNextionQtFramePorSegundo[]=        {"QT FRAME POR SEG"};
const char charTelaNextionQtFramePorSegundo2[]=       {"SERIAL 1        "};



//indica qual o menu atual que esta sendo programado
enum
{
    menuConfiguraSerial_1EmEspera,
    defineVelocidadeSerial_1,
    ativaDesativaSerial_1, 
    definePortaSerial_1,
    defineSaidaDadosSerial_1,
    defineSaidaDadosSerial_2,    
    defineEnderecoIndicadorSerial_1,
    defineQtFramePorSegundoSerial_1,  
}menuConfiguraSerial_1 = menuConfiguraSerial_1EmEspera;

enum velocidadeTxSerial_1
{
    velocidadeTxSerial_1EmEspera,  
    velocidade1200Kbps,
    velocidade2400Kbps,
    velocidade4800Kbps,
    velocidade9600Kbps,
    velocidade19200Kbps,
    velocidade38400Kbps,
    velocidade57600Kbps,
	velocidade115200Kbps,
}velocidadeTxSerial_1  = velocidadeTxSerial_1EmEspera;
       
#define _TRANSMISSAOCONTINUA_1 0
#define _TRANSMISSAOCONTINUA_2 1
#define _MODBUS_RTU 2

//flags utilizados na programa��o

