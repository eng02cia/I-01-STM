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
// telas de programa�ao
                                                 
const char charTelaConfiguraVelocidadeSerial[]={"VELOCID/SERIAL 1""                "};
const char charTelaAtivaDesativaSerial_1[]=    {"ATIVA/DESATIVA  ""SERIAL 1        "};
const char charTelaEscolhePortaSerial_1[]=     {"PORTA SERIAL 1  ""                "};
const char charTelaFormaSaidaDadosSerial_1[]=  {"DADOS SERIAL 1  ""                "};
const char charTelaFormaSaidaDadosSerial_2[]=  {"DADOS SERIAL 2  ""                "};
const char charTelaEnderecoIndicadorSerial_1[]={"END INDICADOR   ""SERIAL 1        "};
const char charTelaQtFramePorSegundo[]=        {"QT FRAME POR SEG""SERIAL 1        "};


const char charVelocidade1200Kbps[]=    {"1200"};
const char charVelocidade2400Kbps[]=    {"2400"};
const char charVelocidade4800Kbps[]=    {"4800"};
const char charVelocidade9600Kbps[]=    {"9600"};
const char charVelocidade19200Kbps[]=   {"19200"};
const char charVelocidade38400Kbps[]=   {"38400"};
const char charVelocidade57600Kbps[]=   {"57600"};
const char charVelocidade115200Kbps[]=   {"115200"};


const char charAtivado[]= {"ATIV"};
const char charDesativado[]={"DESAT"};
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

