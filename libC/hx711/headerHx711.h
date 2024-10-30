//////////////////////////////////////////////////////////////////////////////////		
//                  header hx711                        		          		//	
//////////////////////////////////////////////////////////////////////////////////
//prototipos de função utilizadas
void inicializaHx711(void);
void readHx711(void);
void delayReadHx711(void);
void testeLeituraAd(void);
static unsigned char countReadHx711;
static unsigned char delayHx711;
static unsigned char hx711Temp;
static unsigned char arrayDataHx711[3];
static unsigned char hx711TipoPeso;
static unsigned char hx711StatusSatura; 
static unsigned char hx711StatusCelulaCarga;
static float dataAdHx711;
//static unsigned char loopTesteAd;

//strutura de dados utilizadas na leitura dos bits de dados do barramento
//de comunicação do hx711
union
	{
	struct
		{
		 unsigned bit0:1;
		 unsigned bit1:1;
		 unsigned bit2:1;
		 unsigned bit3:1;
		 unsigned bit4:1;
		 unsigned bit5:1;
		 unsigned bit6:1;
		 unsigned bit7:1;
		}St;
	unsigned char Byte;
	}rxDataBarramentoHx711;
#ifdef placaAutomacao  
#define pinoClockHx711  LATAbits.LATA1
#define pinoDataHx711   PORTAbits.RA0  
#endif 
    
#ifdef _18F46K40     
#define pinoClockHx711  LATDbits.LATD2 //output 
#define pinoDataHx711   PORTDbits.RD3  //imput
#endif        
#ifdef _18F47K40      
#define pinoClockHx711  LATDbits.LATD2  
#define pinoDataHx711   PORTDbits.RD3  
#endif
#ifdef  _18F66K40    
#ifdef indicadorI01_1_5_3     
#define pinoClockHx711  LATEbits.LATE5  
#define pinoDataHx711   PORTEbits.RE4  
#endif 
#endif
#ifdef indicador_ICV04
#define pinoDataHx711   PORTDbits.RD0  
#define pinoClockHx711  LATDbits.LATD1    
#endif    
    
#define _CELULA_CARGA_SATURADA 1
#define _CELULA_CARGA_NAO_SATURADA 0
#define _PESO_POSITIVO_CELULA_CARGA 0
#define _PESO_NEGATIVO_CELULA_CARGA 1
#define _comCelulaDeCarga 0
#define _semCelulaDeCarga 1