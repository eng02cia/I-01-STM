//////////////////////////////////////////////////////////////////////////////////		
//                          Header                                             	//
//////////////////////////////////////////////////////////////////////////////////	

//////////////////////////////////////////////////////////////////////////////////
//prototipo de funcoes                                                          //
//////////////////////////////////////////////////////////////////////////////////
#include "stdint.h"

//////////////////////////////////////////////////////////////////////////////////
//Defines Utilizados             												//
//////////////////////////////////////////////////////////////////////////////////
#define EEPROM_I2C &hi2c1
#define EEPROM_ADDR 0xA0 // EEPROM ADDRESS (8bits)

#define DS1307_ADDRESS 0xD0 //RELOGIO ADRESS

void grava_i2c(void);
void le_i2c(void);
void grava_Relogio_i2c(uint8_t seg, uint8_t min, uint8_t horas, uint8_t diaDaSemana, uint8_t diaDoMes, uint8_t mes, uint8_t ano);
void le_Relogio_i2c(void);


uint16_t enderecoInicialPagina = 0;
//uint16_t tamanhoPagina = 8;
uint16_t quantidadeBytes = 7;

//////////////////////////////////////////////////////////////////////////////////
//prototipos de funcao utilizados Relogio										//
//////////////////////////////////////////////////////////////////////////////////

const char defaultRelogio[]={1,1,1,1,1,1,22	};

uint8_t set_time[7];
uint16_t enderecoInicialPaginaRelogio = 0;
uint16_t tamanhoPaginaRelogio = 8;
uint16_t quantidadeBytesRelogio = 7;

//uint8_t arrayAno[10];
//uint8_t arrayMes[10];
//uint8_t arrayDia[10];
//uint8_t arrayMinuto[10];
//uint8_t arrayHora[10];

// Convert normal decimal numbers to binary coded decimal
uint8_t decToBcd(int val)
{
  return (uint8_t)( (val/10*16) + (val%10) );
}
// Convert binary coded decimal to normal decimal numbers
int bcdToDec(uint8_t val)
{
  return (int)( (val/16*10) + (val%16) );
}

typedef struct {
	uint8_t segundos;
	uint8_t minutos;
	uint8_t horas;
	uint8_t diaDaSemana;
	uint8_t diaDoMes;
	uint8_t mes;
	uint8_t ano;
} TIME;

TIME time;

void inicializaComunicacaoI2c (void);
void readRelogioI2c (void);
void writeRelogioI2c (void);
void metodoTempoLeituraRelogio(void);
unsigned char transformaBcdParaDecimal(unsigned char valor);
unsigned char transformaDecimalParaBcd(unsigned char valor);
//////////////////////////////////////////////////////////////////////////////////
//declaracao de variaveis                                                       //
//////////////////////////////////////////////////////////////////////////////////
//static unsigned char frameDataRelogio[7];
static unsigned char segundoRelogio;
static unsigned char minutoRelogio;
static unsigned char horaRelogio;
static unsigned char diaSemanaRelogio;
static unsigned char diaMesRelogio;
static unsigned char mesRelogio;
static unsigned char anoRelogio;
static unsigned char tempoLeituraRelogio;

static unsigned char anoBase; 
static unsigned char statusLeituraRelogio;

//static unsigned char loopErroI2cMsspAck;
//static unsigned char loopErroI2cMssp;
//static unsigned char loopProcessoI2c;
//static unsigned char fimProcessoI2c;

//static unsigned char endHMemoriaI2c;
//static unsigned char endLMemoriaI2c;
//static unsigned char dataMemoriaI2c[32];
//static unsigned char loopQtBytesI2c;
//short fazLeituraRelogio;
//short fazEscritaRelogio;
short flagRelogioInicializado;
// enumeracao de controle do barramento I2C 


//////////////////////////////////////////////////////////////////////////////////
//contantes utilizadas                                                          //
//////////////////////////////////////////////////////////////////////////////////
#define comRelogio 0
#define semRelogio 1
//#define BAUDI2C 100	// Desired Baud Rate in kbps
//#define FOSCI2C 64000 // Oscillator Clock in kHz

//#define			VescritaRl					0b11010000
//#define			VleituraRl					0b11010001
#define			VLeituraEepromI2c			0b10100001
#define			VEscritaEepromI2c			0b10100000

//#define			endPonteiroRl				00
#define         valorAnoBase				20
//#define pinoDataInputPs2 PORTBbits.RB1
//#define pinoClockInputPs2 PORTBbits.RB0
//#define FAZ_START 0
//#define FAZ_REESTART 0

    
    
    
    
    
