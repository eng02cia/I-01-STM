//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//              funcoes de tratamento das teclas do display                		//
//                                                                            	//
//                        	Desenvolvido por   		                           	//
//                                                                           	//
//  			    		Clodoaldo Flugel			                       	//
//                                                                            	//
//               Inicio em 26/06/07 as 17:40 hs                               	//
//           Parado em    /  /   as   :   hs                                  	//
//           Reiniciado em   /  /   as   :   hs					    	   		//
//                                                                            	//
//									 									       	//			
//////////////////////////////////////////////////////////////////////////////////
void funcaoTempoAcessoMenuProgramacao(void);
void tempoValidaTeclaQuandoSolta (void);
void trataControleDasTeclas (void);
void telaErroPesoProgramado(void);
void verificaLigaDesligaExterno (void);
void iniciaTeclaExterna (void);
void tempoInicioProcessoPrendeSaco(void);
void telaErroLimiteZero(void);
void metodoLigaSistema(void);
void funcaoTempoBackLight(void);
void metodoDesligaSistema(void);
//////////////////////////////////////////////////////////////////////////////////		
//Contantes utilizadas nas funcoes								   				//		
//////////////////////////////////////////////////////////////////////////////////		

//////////////////////////////////////////////////////////////////////////////////		
//declara��o de variaveis utilziadas nesta fun��o								//
//////////////////////////////////////////////////////////////////////////////////		
static unsigned char sistemaInicializado;
static unsigned char tempoAcessoMenuProgramacao;
static unsigned char tempoValidaTeclaSolta;
static unsigned char tempoSegundoBacklightLigado;
static unsigned char tempoBacklightLigado;
static unsigned char controleTara;
unsigned char trocaPraTelaInicial;
unsigned char ControlaAcessaMenu;
short flagTempoAcessoMenuProgramacao;
short flagProgMenuPrincipal;
short flagTempoValidaTeclaSolta;
short flagSaidaMenuProgramacao; 
//short flagInibeTeclaSolta;
short flagTempoExibeBackLight;

// TELA PROG PORTUGUES
const char telaErroLimiteZeroLcdPT[]=   {"ERRO LIMITE ZERO"};

// TELA PROG ESPANHOL
const char telaErroLimiteZeroLcdESP[]=  {"ERRO LIMITE CERO"};

// TELA PROG INGLES
const char telaErroLimiteZeroLcdING[]=  {"ZERO LIMIT ERROR"};

enum digitoProgramacao
{
    programandoDigitoZero,
    programandoDigitoUm,
    programandoDigitoDois,
    programandoDigitoTres,   
    programandoDigitoQuatro,
    programandoDigitoCinco,
    }digitoAtualProgramacao = programandoDigitoZero;
