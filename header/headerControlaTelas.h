//////////////////////////////////////////////////////////////////////////////////		
//                  Header do controle das telas        		          		//	
//////////////////////////////////////////////////////////////////////////////////
//prototipos de funcao utilizadas
void metodoControleDasTelas(void);
void funcaoTempoTelaInicial (void);

//variaveis utilizadas
static unsigned char tempoExibeTelaInicial;
//static unsigned char PesoAtualProcessoCorte[9];//mostra o peso progamado do corte que esta em execucao
unsigned char tempControlaTelas;

//flags utilizados para controle das telas
static unsigned char exibeVersionControl;
static unsigned char transmitindoErro;
unsigned char trocaTelaPeso;

//frases utilizadas 
const char telaStatusPrincipal[] =        {"                ""                "};
const char telaInicialVersao[] =          {" V3.0.0         "};
const char telaInicialIndicador[] =       {" INDICADOR I-01 "};

//  TELA PROG EM PORTUGUES
const char telaSobreCargaPT[] =           {"  SOBRE CARGA   "};
const char telaSubCargaPT[] =             {"  SUB CARGA     "};
const char telaSemCelulaCargaPT[] =       {"  CONECT/CABO   "};
// TELA PROG EM ESPANHOL
const char telaSobreCargaESP[]=           {"   SOBRE PESO   "};
const char telaSubCargaESP[]=             {"    BAJO PESO   "};
const char telaSemCelulaCargaESP[]=       {"CONECTE EL CABLE"};
// TELA PROG EM INGLES
const char telaSobreCargaING[]=           {"    OVERLOAD    "};
const char telaSubCargaING[]=             {"   UNDER LOAD   "};
const char telaSemCelulaCargaING[]=       {"  CONNECT/CABLE "};
//const char paradoLcd[]= {"PARADO"};
//const char descarregueLcd[]= {"DESCARREGUE"};
//const char descarregandoLcd[]= {"DESCARREGANDO"};
//const char semProgramacaoLcd[] = {"S/PROGRAMACAO"};
//const char pausaLcd[] = {"PAUSA"};
//const char pesoValorZero[] = {"     0"};
#ifdef indicadorI01_1_5_2
#define pinoBackLight  PORTCbits.RC5 
#endif
#ifdef indicadorI01_1_5_3
#define pinoBackLight  PORTCbits.RC2 
#endif

#define _PORTUGUES 	0
#define _INGLES		1
#define _ESPANHOL	2