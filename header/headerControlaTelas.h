//////////////////////////////////////////////////////////////////////////////////		
//                  Header do controle das telas        		          		//	
//////////////////////////////////////////////////////////////////////////////////
//prototipos de fun��o utilizadas
void metodoControleDasTelas(void);
void funcaoTempoTelaInicial (void);

//variaveis utilizadas
static unsigned char tempoExibeTelaInicial;
//static unsigned char PesoAtualProcessoCorte[9];//mostra o peso progamado do corte que esta em execu��o
unsigned char tempControlaTelas;

//flags utilizados para controle das telas
static unsigned char exibeVersionControl;
static unsigned char transmitindoErro;
unsigned char trocaTelaPeso;
//frases utilizadas 

        
const char telaInicialIndicador[] =     {" INDICADOR I-01 "};
const char telaInicialVersao[] =        {"Vx.y.z          "};
const char telaStatusPrincipal[] =      {"                ""                "};
const char telaSobreCarga[] =           {"  SOBRE CARGA   "};
const char telaSubCarga[] =             {"  SUB CARGA     "};
const char telaSemCelulaCarga[] =       {"  CONECT/CABO   "};
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
