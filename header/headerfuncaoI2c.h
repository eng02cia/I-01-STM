#include "stdint.h"

extern I2C_HandleTypeDef hi2c1;
//////////////////////////////////////////////////////////////////////////////////
//Defines Utilizados             												//
//////////////////////////////////////////////////////////////////////////////////
#define EEPROM_I2C &hi2c1
#define EEPROM_ADDR 0xA0 // EEPROM ADDRESS (8bits)

char data_to_read[10];
uint8_t Data[16];
uint8_t Data_read[16];



uint16_t tamanhoPagina = 64;
uint16_t umByte = 1;
uint8_t Data_Write_I2c[162];
uint8_t tempCarregaValorArray[32];

static unsigned char flagFazLeituraI2c;
static unsigned char tempoLeituraI2c;
//////////////////////////////////////////////////////////////////////////////////
//prototipos de funcao utilizados												//
//////////////////////////////////////////////////////////////////////////////////
//void gravari2c(void);
//void leri2c(void);

void le_i2c(void);
