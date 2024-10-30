//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//                        Funções Inicialização			                   		//
//                                                                            	//	
//                        Desenvolvido por   		                           	//
//                                                                           	//
//  			    GLOBAL ENERGY TELECOMUNICATION		                       	//
//                                                                            	//
//               Inicio em 26/06/07 as 17:40 hs                               	//
//           Parado em    /  /   as   :   hs                                  	//
//           Reiniciado em   /  /   as   :   hs					    	   		//	
//                                                                            	//
//									 									       	//			
//////////////////////////////////////////////////////////////////////////////////		
//////////////////////////////////////////////////////////////////////////////////		
//Inicialização das portas de entrada e saida									//
//////////////////////////////////////////////////////////////////////////////////		
void iniciaSistema(void)
{
	LATA = 0b00000000;
	TRISA = 0b00000000;
	ANSELA = 0b00000000;
	PORTA = 0b00000000;
    
	LATB = 0b00000000;
	TRISB = 0b00000000;
	ANSELB = 0b00000000;
 	PORTB = 0b00000000;
    
	LATC = 0b00000000;
	TRISC = 0b00000000;
#ifdef  _18F46K40    
	ANSELC = 0b00000000;
#endif
#ifdef  _18F47K40    
	ANSELC = 0b00000000;
#endif    
	PORTC = 0b00000000;
    
	LATD = 0b00000000;
	TRISD = 0b00000000;
	ANSELD = 0b00000000;    
	PORTD = 0b00000000;  
#ifdef  _18F66K40    
	PORTE = 0b00000000;
	LATE = 0b00000000;
	TRISE = 0b00000000;
	ANSELE = 0b00000000; 

 	PORTF = 0b00000000;
	LATF = 0b00000000;
	TRISF = 0b00000000;
	ANSELF = 0b00000000;   

 	PORTG = 0b00000000;
	LATG = 0b00000000;
	TRISG = 0b00000000;
	ANSELG = 0b00000000;           
#endif   
    
//    WPUCbits.WPUC7 = 1;
//prioridade das interrupções													//
	INTCONbits.IPEN = 1;
	IPR1 = 0b11111111;
	IPR2 = 0b11111111;
	IPR3 = 0b11111111;
	IPR4 = 0b11111111;
	IPR5 = 0b11111111;
	IPR6 = 0b11111111;
	IPR7 = 0b11111111;

//inicialização do oscilador interno 64 mhz										//
    OSCFRQ =  0b00001000;
	OSCCON1 = 0b00000000;
//	OSCTUNEbits.PLLEN = 1;
//    INLVLCbits.INLVLC7 = 1;
									
//Carrega os dados da EEprom                                            		//
	inicializaDadosEeprom();
//inicialização a interrupção geral		
	INTCONbits.GIE = 1;
	INTCONbits.PEIE = 1;    
//inicializa o timer para controle das tasks									//
	init_timer_multtask();
//inicializa a função de leitura do teclado                 					//
	inicializaDecodificaTeclado();

//inicializa a porta serial 1													//
    iniciaVariaveisTxSerial_1();
//inicializa a porta serial 2
    inicializaSerial_2();
//inicia tecla externa
#ifdef indicadorI01_1_5_2     
    iniciaTeclaExterna();
#endif    
    inicializaHx711(); 
// LIGA BACKLIHT
#ifdef indicadorI01_1_5_2    
    TRISCbits.TRISC5 = 0;
#endif
#ifdef indicadorI01_1_5_3    
    TRISCbits.TRISC2 = 0;
#endif    
//iniciliza os leds indicativos de zero e tara
    inicializaLedsIndicador();

}
	