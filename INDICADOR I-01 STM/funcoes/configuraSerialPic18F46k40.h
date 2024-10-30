//////////////////////////////////////////////////////////////////////////////////		
//                       Funções Rx Serial display remoto                  		//		
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//função que inicializa a serial 1												//
//////////////////////////////////////////////////////////////////////////////////		
void InicializaSerial_1(void)
{
	TXSTAbits.BRGH = 1;
	RCSTAbits.SPEN = 1;
	RCSTAbits.CREN = 1;  
    BAUDCTLbits.BRG16 = 1;
    TX1PPS = 0b10110; // dereciona o modulo tx serial para o portc 6
    RC6PPS = 0b01001; //0b10100; 
	PIE3bits.RCIE = 1;    
	velocidade9600KbpsSerial_1();  
	IndexSerial_1 = &MensSerial_1 [0];
//habilita como saida o pino de controle da entrada serial						//
	TRISCbits.TRISC3 = 0;	
	TRISCbits.TRISC5 = 0;	
    PinoSinalizaRxSerial_1 = 0;
	PinoIdentificaEntradaSerial = 0;
    TempoReferenciaTamanhoFrame = tempoIntervaloEntreFrame;
}
