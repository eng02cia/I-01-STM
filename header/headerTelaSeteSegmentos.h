//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//               Header de escrita de dados no display lcd de sete segmentos     //
//////////////////////////////////////////////////////////////////////////////////			
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de fun��o utilizados												//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraDadoLcdSeteSegmentos(void);
void telaSemCelulaCargaSeteSegmentos(void);
void telaSubCargaSeteSegmentos(void);
void telaSobreCargaSeteSegmentos(void);
void telaAguardeSeteSegmentos(void);
void telaVersaoSeteSegmentos(void);

unsigned char *digitosDspTemp;
unsigned char *displayPesoTemp;
static unsigned char loopConverteTelaLcd;
static unsigned char asciiTelaDisplaySeteSegmentos;

#define balanca_01 	0
#define balanca_02 	1
