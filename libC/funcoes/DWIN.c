//==============================================================================
//---------------------------------Includes-------------------------------------
//==============================================================================
#include "DWIN.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
//==============================================================================
//---------------------------------Defines--------------------------------------
//==============================================================================

#define headerDWIN_H 0x5A
#define headerDWIN_L 0xA5
//==============================================================================
//--------------------------------Variables-------------------------------------
//==============================================================================
struct readDataDWIN_P readDataDWIN;
struct curveDataDWIN_p curveDataDWIN;
//==============================================================================
//--------------------------------PROTOTYPE-------------------------------------
//==============================================================================
uint8_t getByte(unsigned char*b);
//==============================================================================
//--------------------------Device initialization-------------------------------
//==============================================================================
void dwinUartDmaInit()
{
  readDataDWIN.delayOverflowMaxTime = 3000;
  for (uint16_t i = 0; i <DWIN_UART_BUFFER_SIZE;i++){readDataDWIN.uartBuffer[i] = 0xffff;}
  HAL_UART_Receive_DMA(&DWIN_UART, (uint8_t *)&readDataDWIN.uartBuffer, DWIN_UART_BUFFER_SIZE);
}
//==============================================================================
//--------------------------------FUNCTIONS-------------------------------------
//==============================================================================

//==============================================================================
//---------------------------preset variable DWIN-------------------------------
//==============================================================================

//==============================================================================
//--------------------------Retrieving_a_data_byte------------------------------
//==============================================================================
uint8_t getByte(unsigned char*b)
{
  if (readDataDWIN.uartBuffer[readDataDWIN.uartCnt]!=0xffff)
  {
    *b=(readDataDWIN.uartBuffer[readDataDWIN.uartCnt] & 0xff);
    readDataDWIN.uartBuffer[readDataDWIN.uartCnt]=0xffff;
    readDataDWIN.uartCnt++;
    if (readDataDWIN.uartCnt == DWIN_UART_BUFFER_SIZE) readDataDWIN.uartCnt=0;
    return 1;
  } 
  else 
  {
	  return 0;
  }
}
//==============================================================================
//-------------------------------Recive_Data------------------------------------
//==============================================================================
void receivingDataPacket()
{ 
  uint16_t m = 0;
    if (!readDataDWIN.PacketReady)
      { 
        getByte(&readDataDWIN.GettingByte); 
        m = 0; 
          if (readDataDWIN.GettingByte == 0x5A)
          {
            readDataDWIN.rxData[m] = readDataDWIN.GettingByte; // start byte 1
            m++;
            readDataDWIN.timeoutDelay = 0;
            while ((getByte(&readDataDWIN.GettingByte)==0)&&(readDataDWIN.timeoutOverflow  != 1))
            {
            	readDataDWIN.timeoutDelay++;
            	if (readDataDWIN.timeoutDelay > readDataDWIN.delayOverflowMaxTime)readDataDWIN.timeoutOverflow = 1;
            }
            readDataDWIN.rxData[m] = readDataDWIN.GettingByte; // start byte 2 
            m++;
            readDataDWIN.timeoutDelay = 0;
            while ((getByte(&readDataDWIN.GettingByte)==0)&&(readDataDWIN.timeoutOverflow  != 1))
            {
            	readDataDWIN.timeoutDelay++;
            	if (readDataDWIN.timeoutDelay > readDataDWIN.delayOverflowMaxTime)readDataDWIN.timeoutOverflow = 1;
            }
            readDataDWIN.rxData[m] = readDataDWIN.GettingByte; // Data packet length
            readDataDWIN.lengthRxPacket = readDataDWIN.rxData[m];
            m++;
            readDataDWIN.timeoutDelay = 0;
            for(uint16_t i = 0;i < readDataDWIN.lengthRxPacket; i++) // Fill the buffer with data
            {
              while ((getByte(&readDataDWIN.GettingByte)==0)&&(readDataDWIN.timeoutOverflow  != 1))
              {
            	  readDataDWIN.timeoutDelay++;
            	  if (readDataDWIN.timeoutDelay > readDataDWIN.delayOverflowMaxTime)readDataDWIN.timeoutOverflow = 1;
              }
              readDataDWIN.timeoutDelay = 0;
              readDataDWIN.rxData[m] = readDataDWIN.GettingByte; // Retrieving data
              m++;
            }
          readDataDWIN.PacketReady = true; 
          } 
        readDataDWIN.GettingByte = 0; 
      } 
}
//==============================================================================
//------------------------------Parsing_Data------------------------------------
//==============================================================================
void parsingDWIN()
{
  receivingDataPacket();
  if (readDataDWIN.PacketReady)
  {
    readDataDWIN.parsingDataDWIN.header = (uint16_t)readDataDWIN.rxData[0]<<8 | (uint16_t)readDataDWIN.rxData[1];
    readDataDWIN.parsingDataDWIN.length = readDataDWIN.rxData[2];
    readDataDWIN.parsingDataDWIN.command = (commandDWIN)readDataDWIN.rxData[3];
    for (uint8_t i = 0; i < (readDataDWIN.lengthRxPacket - 1);i++)
    {
      readDataDWIN.parsingDataDWIN.data[i] = readDataDWIN.rxData[i+4];
    }
    readDataDWIN.PacketReady = false;
  }
  
}
//==============================================================================
//-----------------------------Wait Ok Message----------------------------------
//==============================================================================

void waitOkMessageDWIN()
{
	uint32_t startTime = HAL_GetTick();
	uint32_t stopTime = HAL_GetTick();

	while (((startTime + 10) > stopTime) && (readDataDWIN.parsingDataDWIN.data[0] != 0x4F))
	{
		stopTime = HAL_GetTick();
		parsingDWIN();
	}
	if (readDataDWIN.parsingDataDWIN.data[0] == 0x4F) readDataDWIN.parsingDataDWIN.data[0] = 0x00;
}
//==============================================================================
//----------------------------DWIN GO TO PAGE-----------------------------------
//==============================================================================
void goToPageDWIN(uint16_t page)
{
  uint8_t str[10] = {headerDWIN_H,headerDWIN_L,0x07,0x82,0x00,0x84,0x5A,0x01,(page & 0xFF00)>>8,page & 0xFF};

  HAL_UART_Transmit(&DWIN_UART, str, sizeof(str),0xFF);    
}
//==============================================================================
//------------------------------Read Variable-----------------------------------
//==============================================================================

void readVariableDWIN(uint16_t adress, uint8_t lenHalfWord)
{
  uint8_t str[10] = {headerDWIN_H,headerDWIN_L,0x04,0x83,(adress & 0xFF00)>>8,adress & 0xFF,lenHalfWord};

  HAL_UART_Transmit(&DWIN_UART, str, 7,0xFF);    
}
//==============================================================================
//-------------------------------Write LED--------------------------------------
//==============================================================================

void writeLedDWIN(uint8_t ledWork, uint8_t ledSleep)
{
  uint8_t str[10] = {0x00};
  str[0] = headerDWIN_H;
  str[1] = headerDWIN_L;
  str[2] = 0x05;
  str[3] = 0x82;
  str[4] = 0x00;
  str[5] = 0x82;
  str[6] = ledWork;
  str[7] = ledSleep;

  HAL_UART_Transmit(&DWIN_UART, str, 8,0xFF);    
}
//==============================================================================
//----------------------------Write Variable------------------------------------
//==============================================================================

void writeVariableDWIN(uint8_t len, uint16_t adress, uint8_t* data)
{
  uint8_t str[250] = {0x00};
  str[0] = headerDWIN_H;
  str[1] = headerDWIN_L;
  str[2] = len;
  str[3] = writeVariable;
  str[4] = (adress & 0xFF00)>>8;
  str[5] = adress & 0xFF;
  for (uint8_t i = 0; i < (len - 3);i++)
{
  str[i+6] = data[i];
}

  HAL_UART_Transmit(&DWIN_UART, str, (len + 3),0xFF);    
}

//==============================================================================
//------------------------Write Variable Half Word------------------------------
//==============================================================================

void writeHalfWordDWIN(uint16_t adress, uint16_t data)
{
  uint8_t str[9] = {0x00};
  str[0] = headerDWIN_H;
  str[1] = headerDWIN_L;
  str[2] = 0x05;
  str[3] = writeVariable;
  str[4] = (adress & 0xFF00)>>8;
  str[5] = adress & 0xFF;
  str[6] = (data & 0xFF00)>>8;
  str[7] = data & 0xFF;

  HAL_UART_Transmit(&DWIN_UART, str, 8,0xFF);    
}
//==============================================================================
//--------------------------Write Variable Word---------------------------------
//==============================================================================

void writeWordDWIN(uint16_t adress, uint32_t data)
{
  uint8_t str[11] = {0x00};
  str[0] = headerDWIN_H;
  str[1] = headerDWIN_L;
  str[2] = 0x07;
  str[3] = writeVariable;
  str[4] = (adress & 0xFF00)>>8;
  str[5] = adress & 0xFF;
  str[6] = (data & 0xFF000000)>>24;
  str[7] = (data & 0x00FF0000)>>16;
  str[8] = (data & 0x0000FF00)>>8;
  str[9] =  data & 0x000000FF;
  
  HAL_UART_Transmit(&DWIN_UART, str, 10,0xFF);    
}
//==============================================================================
//-------------------------Write Variable 2 Word--------------------------------
//==============================================================================

void writeDoubleWordDWIN(uint16_t adress, uint64_t data)
{
  uint8_t str[15] = {0x00};
  str[0] = headerDWIN_H;
  str[1] = headerDWIN_L;
  str[2] = 0x11;
  str[3] = writeVariable;
  str[4] = (adress & 0xFF00)>>8;
  str[5] = adress & 0xFF;
  str[6] = (data & 0xFF00000000000000)>>56;
  str[7] = (data & 0x00FF000000000000)>>48;
  str[8] = (data & 0x0000FF0000000000)>>40;
  str[9] =  data & 0x000000FF00000000>>32;
  str[10] = (data & 0x00000000FF000000)>>24;
  str[11] = (data & 0x0000000000FF0000)>>16;
  str[12] = (data & 0x000000000000FF00)>>8;
  str[13] =  data & 0x00000000000000FF;
  

  HAL_UART_Transmit(&DWIN_UART, str, 14,0xFF);    
}

//==============================================================================
//--------------------------Write One Curve DWIN--------------------------------
//==============================================================================

void writeOneCurveDWIN(uint8_t ChanelCurve, uint8_t lenData, uint16_t* data)
{

	uint8_t strC[255] = {0x00};
	memset(strC,0x00,255);
	  strC[0] = headerDWIN_H;
	  strC[1] = headerDWIN_L;
	  strC[2] = 9 + (lenData * 2);
	  strC[3] = writeVariable;
	  strC[4] = 0x03;
	  strC[5] = 0x10;
	  strC[6] = headerDWIN_H;
	  strC[7] = headerDWIN_L;
	  strC[8] = 0x01;
	  strC[9] = 0x00;
	  strC[10] = ChanelCurve;
	  strC[11] = lenData;
	  for (uint8_t i = 0; i < lenData; i++)
	  {
		  strC[12 + (i * 2)] = (*data & 0xFF00)>>8;
		  strC[12 + ((i * 2) + 1)] = (*data & 0x00FF);
	  }
	  HAL_UART_Transmit(&DWIN_UART, strC, (12 + (lenData * 2)),0xFF);
}

//==============================================================================
//----------------------------Write Curve DWIN----------------------------------
//==============================================================================

uint8_t writeCurveDWIN(struct curveDataDWIN_p curveDataDWIN)
{

	uint8_t returnStatus = 0;
	uint8_t lenData = 0;
	uint8_t cntCurve = 0;
	uint8_t cnt = 0;

for (uint8_t i = 0; i < 8; i++)
{
	if ((curveDataDWIN.CurveEnable[i] == true)&&(curveDataDWIN.CurveLenData[i] != 0))
	{
		lenData += curveDataDWIN.CurveLenData[i];
		cntCurve++;
	}
}

	if (lenData < (123 - 2 * cntCurve))
	{
		uint8_t strC[255] = {0x00};
		memset(strC,0x00,255);
		strC[0] = headerDWIN_H;
		strC[1] = headerDWIN_L;
		strC[2] = 9 + ((lenData + cntCurve) * 2);
		strC[3] = writeVariable;
		strC[4] = 0x03;
		strC[5] = 0x10;
		strC[6] = headerDWIN_H;
		strC[7] = headerDWIN_L;
		strC[8] = cntCurve;
		strC[9] = 0x00;
		cnt = 10;

		for (uint8_t i = 0; i < 8; i++) // choice channel
		{
			if ((curveDataDWIN.CurveEnable[i] == true)&&(curveDataDWIN.CurveLenData[i] != 0))
			{
				strC[cnt] = i;
				cnt++;
				strC[cnt] = curveDataDWIN.CurveLenData[i];
				cnt++;
				for (uint8_t j = 0; j < curveDataDWIN.CurveLenData[i]; j++)
				{
					strC[cnt] = (curveDataDWIN.CurveData[i][j] & 0xFF00)>>8;
					cnt++;
					strC[cnt] =  (curveDataDWIN.CurveData[i][j] & 0x00FF);
					cnt++;

				}

			}
		}
		HAL_UART_Transmit(&DWIN_UART, strC, (12 + ((lenData + cntCurve) * 2)),0xFFFF);
		returnStatus = 0;
	}
	else
	{
		returnStatus = 1;
	}
	return returnStatus;
}


//==============================================================================
//---------------------------------END FILE-------------------------------------
//==============================================================================
