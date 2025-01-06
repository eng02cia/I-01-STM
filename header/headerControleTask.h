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
//static unsigned char loopMediaTaskReadAd;
//static float dataMediaHx711Task;
//static unsigned char tempoTaskControlePeso;
short controleDasTasks;
short flagTaskHx711;

//////////////////////////////////////////////////////////////////////																		
//Inicializcao do timer utilizado para controle das tasks  			//
//////////////////////////////////////////////////////////////////////
//5000 CICLOS IGUAL A 250 MICRO SEGUNDOS

void init_timer_multtask (void);
void controleMultTask(void);
void multTaskInterrupt(void);
void hx711TaskInterrupt(void);
void funcaoControleLeituraPeso(void);
