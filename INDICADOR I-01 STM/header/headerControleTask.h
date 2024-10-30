/////////////////////////////////////////////////////////////////////////////////
//                                                                            	//
//                        Controle de tasks				                   		//
//                                                                            	//
//                        Desenvolvido por   		                           	//
//                                                                            	//
//  			    		Clodoaldo Flugel			                       	//
//                                                                            	//
//               Inicio em 02/02/15 as 17:40 hs                               	//
//           Parado em    /  /   as   :   hs                                  	//
//           Reiniciado em   /  /   as   :   hs					    	   		//	
//                                                                            	//
//									 									       	//			
//////////////////////////////////////////////////////////////////////////////////
//Variaveis
//#include "definicoes.h"
static unsigned char micro_segundos;
static unsigned char mile_segundos;
static unsigned int deze_segundos;
static unsigned int cente_segundos;
static unsigned char loopMediaTaskReadAd;
static float dataMediaHx711Task;
static unsigned char controleLeituraPesoI01;
//static unsigned char tempoTaskControlePeso;
short controleDasTasks;
short flagTaskHx711;

//////////////////////////////////////////////////////////////////////																		
//Inicializ��o do timer utilizado para controle das tasks  			//
//////////////////////////////////////////////////////////////////////
//5000 CICLOS IGUAL A 250 MICRO SEGUNDOS

#define TMR1H_250us	0xF0;
#define TMR1L_250us 0x5F;

#define TMR3H_12_5mls 0x9E;
#define TMR3L_12_5mls 0x57;

void init_timer_multtask (void);
void controleMultTask(void);
void multTaskInterrupt(void);
void hx711TaskInterrupt(void);
void funcaoControleLeituraPeso(void);
