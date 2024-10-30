//////////////////////////////////////////////////////////////////////////////////		
//      Funções que controlam a transmisão de dados pela serial 1         		//
//////////////////////////////////////////////////////////////////////////////////
#include "transfereConstToArray.h"
#include "transfereArrayToArray.h"
#include "carregaArrayComZeroDecimal.h"
#include "somaValorArray.h"
#include "calculoCks.h"
#include "converteArrayDecimalParaAscii.h"
#include "zeroAsciiEsquerdaToVazioAscii.h"
#include "transfereArrayToArrayInvertido.h"
#include "calculoCks.h"
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart5;

//////////////////////////////////////////////////////////////////////////////////		
//função que controla a transmisão de dados pela serial 1   					//
//////////////////////////////////////////////////////////////////////////////////		
void controleTxFrameSerial_1ModBusRtu(void)
{

}
//////////////////////////////////////////////////////////////////////////////////		
//                                                                              //
//metodos relacionados a transmissão e recpção quando mo modo modbus rtu      	//
//                                                                              //
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//metodo que inicia a comunicaçãomodBus Rtu                                    	//
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////		
//descrição do padrao modbus adotado pelo indicador de peso                   	//
//escrita leitura em varios registradores
// byte 1 endereço (1 a 99)
// byte 2 função modbus escrita em um unico registradore (0x03)
// byte 3 numero do registrador  H                  (0x00)
// byte 4 numero do registrador  L                  (0x10)
// byte 5 quantidade de bytes a serem lidos H       (0x00)
// byte 6 quantidade de bytes a serem lidos L       (0x00)//um, dois e tres  
// byte 7 valor cks L
// byte 8 valor cks H
//////////////////////////////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////////////
//interrupção da serial 1                                                       //
//////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////		
//função da recepção quando no modo modbus rtu                        			//
//////////////////////////////////////////////////////////////////////////////////	
void rxSerialModBusRtu(void)
{
    flagModBusRtu.tempoMaxRxModBusRtu = 1;    
    tempoMaxRxModBusRtu = 0;
    frameRxModBusRtu[indexRxModBusRtu++] = rrxModBusRtu;
    tamanhoFrameRxModBusRtu++;
    if (tamanhoFrameRxModBusRtu >= 60)
    {	
        flagModBusRtu.tempoMaxRxModBusRtu = 0;        
        tamanhoFrameRxModBusRtu = 0;
        indexRxModBusRtu = 0;
        carregaArrayComZeroDecimal(60,&frameRxModBusRtu[0]);
    } 
}
//////////////////////////////////////////////////////////////////////////////////		
//função de tratamento dos dados recebidos quando no modo modbus Rtu   			//
//considerar time out                                                           //
//////////////////////////////////////////////////////////////////////////////////	
void trataFrameRxModBusRtu(void)
{
    if (flagModBusRtu.tempoMaxRxModBusRtu == 1) {
        flagModBusRtu.tempoMaxRxModBusRtu = 0;
        tempoMaxRxModBusRtu = 0;
        tempRxModBusRtu = tamanhoFrameRxModBusRtu - 2;
        tamanhoFrameRxModBusRtu--;
        calculaValorChecksum(tempRxModBusRtu,&frameRxModBusRtu[0],&arrayTempModBusRtu[0]);   
        if (arrayTempModBusRtu[1] == frameRxModBusRtu[tamanhoFrameRxModBusRtu])
        {
            tamanhoFrameRxModBusRtu--;
            if (arrayTempModBusRtu[0] == frameRxModBusRtu[tamanhoFrameRxModBusRtu])
            {     
//                    testeEndModbus = frameRxModBusRtu[0];
                if (frameRxModBusRtu[0] == enderecoIndicadorMem)
                {
                    trataModBusRtu();
                    tamanhoFrameRxModBusRtu = 0;
                    indexRxModBusRtu = 0;
                    carregaArrayComZeroDecimal(60,&frameRxModBusRtu[0]); 
                }
                else
                {
                    tamanhoFrameRxModBusRtu = 0;
                    indexRxModBusRtu = 0;
//                        carregaArrayComZeroDecimal(60,&frameRxModBusRtu[0]);
                }
            }
            tamanhoFrameRxModBusRtu = 0;
            indexRxModBusRtu = 0;
//               carregaArrayComZeroDecimal(60,&frameRxModBusRtu[0]);
        }
        tamanhoFrameRxModBusRtu = 0;
        indexRxModBusRtu = 0;
//            carregaArrayComZeroDecimal(60,&frameRxModBusRtu[0]);

    }    
}
//////////////////////////////////////////////////////////////////////////////////		
//função utilizada para transoforma os dados para retornar                  	//
//////////////////////////////////////////////////////////////////////////////////	
void trataModBusRtu(void)
{
// verifica tipo do comando recebido 
    if (frameRxModBusRtu[1] == 0x03)//leitura de multiplos registradores
    {
//verifica numero do registrador inicial
        tempModBusRtu = ((frameRxModBusRtu[2]*255)+ frameRxModBusRtu[3]);
//////////////////////////////////////////////////////////////////////////////////	        
        if (tempModBusRtu >= 0x01 && tempModBusRtu <= _qtMaxLeituraRegistradorValido16Bits)
        {
//endereço inicial
//tempModBusRtu = valor do endereço inicial
            tempModBusRtu = tempModBusRtu - 1;
            tempModBusRtu = tempModBusRtu * 2;            
//quantidade de registradores
//temp1ModBusRtu = valor com a quantidade de registradores          
            temp1ModBusRtu = ((frameRxModBusRtu[4]*255)+ frameRxModBusRtu[5]); 
            temp1ModBusRtu = temp1ModBusRtu *2;
//verifica se não estrapolou a quatidade maxima de registradores a serem lidos
            temp2ModBusRtu = tempModBusRtu + temp1ModBusRtu;
            if (temp2ModBusRtu <= _qtMaxLeituraRegistradorValido8Bits)
            {
            //construção da resposta
//temp2ModBusRtu = valor com a quantidade de bytes para resposta
                frameTxModBusRtu[0] = enderecoIndicadorMem;
                frameTxModBusRtu[1] = 0x03;
                frameTxModBusRtu[2] = temp1ModBusRtu;  
                funcaoValoresTxModBusRtu(temp1ModBusRtu,&arrayMemoriaModbusRtu[tempModBusRtu],&frameTxModBusRtu[3]);
                temp2ModBusRtu = temp1ModBusRtu + 3;//valor 3 quantidade fixa de bytes para resposta
                calculaValorChecksum(temp2ModBusRtu,&frameTxModBusRtu[0],&frameTxModBusRtu[temp2ModBusRtu]);
                qtBytesTxModBusRtu = temp2ModBusRtu + 2;// valor 2 quantidade de bytes do cks	
                flagModBusRtu.transmitindoModBusRtu = 1;
                flagModBusRtu.txModBusRtu = 1;
                indexTxModBusRtu = 0; 
                HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
                iniciaTxModbus();
            }
            else
            {
                frameTxModBusRtu[0] = enderecoIndicadorMem;
                frameTxModBusRtu[1] = frameRxModBusRtu[1] + 0x80;
                frameTxModBusRtu[2] = 0x02;
                calculaValorChecksum(3,&frameTxModBusRtu[0],&frameTxModBusRtu[3]);   
                qtBytesTxModBusRtu = 5;		
                flagModBusRtu.transmitindoModBusRtu = 1;
                flagModBusRtu.txModBusRtu = 1;
                indexTxModBusRtu = 0; 
                HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
                iniciaTxModbus();
            }
        } 
        else//implementa erro registrador invalido
        {
            frameTxModBusRtu[0] = enderecoIndicadorMem;
            frameTxModBusRtu[1] = frameRxModBusRtu[1] + 0x80;
            frameTxModBusRtu[2] = 0x02;
            calculaValorChecksum(3,&frameTxModBusRtu[0],&frameTxModBusRtu[3]);   
            qtBytesTxModBusRtu = 5;		
            flagModBusRtu.transmitindoModBusRtu = 1;
            flagModBusRtu.txModBusRtu = 1;
            indexTxModBusRtu = 0; 
            HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
            iniciaTxModbus();
        }       
    }   
//////////////////////////////////////////////////////////////////////////////////	        
//escrita em um unico registrador                                               //
//////////////////////////////////////////////////////////////////////////////////	        
    if (frameRxModBusRtu[1] == 0x06)
    {
//verifica numero do registrador inicial
        tempModBusRtu = ((frameRxModBusRtu[2]*255)+ frameRxModBusRtu[3]);
//////////////////////////////////////////////////////////////////////////////////	        
// endereço inicial permitido para salvar dados
        if (tempModBusRtu >= 0x0D && tempModBusRtu <= _qtMaxEscritaRegistradorValido16Bits)
        {
//endereço inicial
//tempModBusRtu = valor do endereço inicial
            tempModBusRtu = tempModBusRtu - 1;     
            tempModBusRtu = tempModBusRtu * 2;            
            funcaoValoresTxModBusRtu(2,&frameRxModBusRtu[4],&arrayMemoriaModbusRtuEspenho[tempModBusRtu]);
            flagVerificaSalvaFrameModBusRtu = 1;
            transfereArrayToArray(8,&frameRxModBusRtu[0],&frameTxModBusRtu[0]);
            qtBytesTxModBusRtu = 8;
            flagModBusRtu.transmitindoModBusRtu = 1;
            flagModBusRtu.txModBusRtu = 1;
            indexTxModBusRtu = 0; 
            HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
            iniciaTxModbus();
        } 
        else//implementa erro registrador invalido
        {
            frameTxModBusRtu[0] = enderecoIndicadorMem;
            frameTxModBusRtu[1] = frameRxModBusRtu[1] + 0x80;
            frameTxModBusRtu[2] = 0x02;
            calculaValorChecksum(3,&frameTxModBusRtu[0],&frameTxModBusRtu[3]);   
            qtBytesTxModBusRtu = 5;		
            flagModBusRtu.transmitindoModBusRtu = 1;
            flagModBusRtu.txModBusRtu = 1;
            indexTxModBusRtu = 0; 
            HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
            iniciaTxModbus();
        }     
    }
//////////////////////////////////////////////////////////////////////////////////	        
//escrita em um varios registradores                                            //
//////////////////////////////////////////////////////////////////////////////////	          
    if (frameRxModBusRtu[1] == 0x10)
    {
//verifica numero do registrador inicial
        tempModBusRtu = ((frameRxModBusRtu[2]*255)+ frameRxModBusRtu[3]);
//////////////////////////////////////////////////////////////////////////////////	        
// endereço inicial permitido para salvar dados
        if (tempModBusRtu >= 0x0D && tempModBusRtu <= _qtMaxEscritaRegistradorValido16Bits)
        {
//endereço inicial
//tempModBusRtu = valor do endereço inicial
            tempModBusRtu = tempModBusRtu - 1;    
            tempModBusRtu = tempModBusRtu * 2;
//quantidade de registradores
//temp1ModBusRtu = valor com a quantidade de registradores          
            temp1ModBusRtu = ((frameRxModBusRtu[4]*255)+ frameRxModBusRtu[5]); 
            temp1ModBusRtu = temp1ModBusRtu * 2;
            temp2ModBusRtu = tempModBusRtu + temp1ModBusRtu;
//verifica validade da quantidade de registradores            
            if (temp1ModBusRtu == frameRxModBusRtu[6])
            {
                if (temp2ModBusRtu <= _qtMaxEscritaRegistradorValido8Bits)
                {                        
//construção da resposta
                    funcaoValoresTxModBusRtu(temp1ModBusRtu,&frameRxModBusRtu[7],&arrayMemoriaModbusRtuEspenho[tempModBusRtu]);            
                    flagVerificaSalvaFrameModBusRtu = 1;
//temp2ModBusRtu = valor com a quantidade de bytes para resposta
                    transfereArrayToArray(6,&frameRxModBusRtu[0],&frameTxModBusRtu[0]);            
                    temp2ModBusRtu = 6;
                    calculaValorChecksum(6,&frameTxModBusRtu[0],&frameTxModBusRtu[temp2ModBusRtu]);
                    qtBytesTxModBusRtu = temp2ModBusRtu + 2;// valor 2 quantidade de bytes do cks	
                    flagModBusRtu.transmitindoModBusRtu = 1;
                    flagModBusRtu.txModBusRtu = 1;
                    indexTxModBusRtu = 0;
                    HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
                    iniciaTxModbus();
                }
                else
                {
                    frameTxModBusRtu[0] = enderecoIndicadorMem;
                    frameTxModBusRtu[1] = frameRxModBusRtu[1] + 0x80;
                    frameTxModBusRtu[2] = 0x02;
                    calculaValorChecksum(3,&frameTxModBusRtu[0],&frameTxModBusRtu[3]);   
                    qtBytesTxModBusRtu = 5;		
                    flagModBusRtu.transmitindoModBusRtu = 1;
                    flagModBusRtu.txModBusRtu = 1;
                    indexTxModBusRtu = 0; 
                    HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
                    iniciaTxModbus();
                }
            }
            else
            {
                frameTxModBusRtu[0] = enderecoIndicadorMem;
                frameTxModBusRtu[1] = frameRxModBusRtu[1] + 0x80;
                frameTxModBusRtu[2] = 0x02;
                calculaValorChecksum(3,&frameTxModBusRtu[0],&frameTxModBusRtu[3]);   
                qtBytesTxModBusRtu = 5;		
                flagModBusRtu.transmitindoModBusRtu = 1;
                flagModBusRtu.txModBusRtu = 1;
                indexTxModBusRtu = 0; 
                HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
                iniciaTxModbus();
            }
        } 
        else//implementa erro registrador invalido
        {
            frameTxModBusRtu[0] = enderecoIndicadorMem;
            frameTxModBusRtu[1] = frameRxModBusRtu[1] + 0x80;
            frameTxModBusRtu[2] = 0x02;
            calculaValorChecksum(3,&frameTxModBusRtu[0],&frameTxModBusRtu[3]);   
            qtBytesTxModBusRtu = 5;		
            flagModBusRtu.transmitindoModBusRtu = 1;
            flagModBusRtu.txModBusRtu = 1;
            indexTxModBusRtu = 0; 
            HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
            iniciaTxModbus();
        }
    }     
//implementa erro função invalida
    if (flagModBusRtu.txModBusRtu == 0)
    {
        frameTxModBusRtu[0] = enderecoIndicadorMem;
        frameTxModBusRtu[1] = frameRxModBusRtu[1] + 0x80;
        frameTxModBusRtu[2] = 0x01;
        calculaValorChecksum(3,&frameTxModBusRtu[0],&frameTxModBusRtu[3]);   
        qtBytesTxModBusRtu = 5;		
        flagModBusRtu.transmitindoModBusRtu = 1;
        flagModBusRtu.txModBusRtu = 1;
        indexTxModBusRtu = 0; 
        HAL_GPIO_WritePin(CONTROL485_GPIO_Port, CONTROL485_Pin, GPIO_PIN_SET);
        iniciaTxModbus();
    }    
}

void iniciaTxModbus (void)
{

	if (statusPortaSerial_1Mem == _RS485){HAL_UART_Transmit_IT(&huart5,&frameTxModBusRtu[0],qtBytesTxModBusRtu);}
	if (statusPortaSerial_1Mem == _RS232){HAL_UART_Transmit_IT(&huart1,&frameTxModBusRtu[0],qtBytesTxModBusRtu);}
}

//configura serial para velocidade de 115200 kbps	
void velocidadeSerial_1_115200Kbps(void)
{
	HAL_UART_Abort_IT(&huart1);
	HAL_UART_Abort_IT(&huart5);
	HAL_UART_DeInit(&huart1);
	HAL_UART_DeInit(&huart5);
	huart1.Init.BaudRate = 115200;
	huart5.Init.BaudRate = 115200;
	HAL_UART_Init(&huart1);
	HAL_UART_Init(&huart5);
	HAL_UART_Receive_IT (&huart1,Rx_ModbusSerial_1,1);
	HAL_UART_Receive_IT (&huart5,Rx_ModbusSerial_1,1);
	silentModBusRtu = 5;//1000 microsegundos
	//silentModBusRtu = 2;//400 microsegundos
}
//configura serial para velocidade de 57600 kbps								//
void velocidadeSerial_1_57600Kbps(void)
{
	HAL_UART_Abort_IT(&huart1);
	HAL_UART_Abort_IT(&huart5);
	HAL_UART_DeInit(&huart1);
	HAL_UART_DeInit(&huart5);
	huart1.Init.BaudRate = 57600;
	huart5.Init.BaudRate = 57600;
	HAL_UART_Init(&huart1);
	HAL_UART_Init(&huart5);
	HAL_UART_Receive_IT (&huart1,Rx_ModbusSerial_1,1);
	HAL_UART_Receive_IT (&huart5,Rx_ModbusSerial_1,1);
	silentModBusRtu = 5;//1000 microsegundos
	//silentModBusRtu = 3;// 600 microsegundos
}
//configura serial para velocidade de 38400 kbps								//
void velocidadeSerial_1_38400Kbps(void)
{
	HAL_UART_Abort_IT(&huart1);
	HAL_UART_Abort_IT(&huart5);
	HAL_UART_DeInit(&huart1);
	HAL_UART_DeInit(&huart5);
	huart1.Init.BaudRate = 38400;
	huart5.Init.BaudRate = 38400;
	HAL_UART_Init(&huart1);
	HAL_UART_Init(&huart5);
	HAL_UART_Receive_IT (&huart1,Rx_ModbusSerial_1,1);
	HAL_UART_Receive_IT (&huart5,Rx_ModbusSerial_1,1);
	silentModBusRtu = 5;//1000 microsegundos
}
//configura serial para velocidade de 19200 kbps								//
void velocidadeSerial_1_19200Kbps(void)
{
	HAL_UART_Abort_IT(&huart1);
	HAL_UART_Abort_IT(&huart5);
	HAL_UART_DeInit(&huart1);
	HAL_UART_DeInit(&huart5);
	huart1.Init.BaudRate = 19200;
	huart5.Init.BaudRate = 19200;
	HAL_UART_Init(&huart1);
	HAL_UART_Init(&huart5);
	HAL_UART_Receive_IT (&huart1,Rx_ModbusSerial_1,1);
	HAL_UART_Receive_IT (&huart5,Rx_ModbusSerial_1,1);
	silentModBusRtu = 10;//2000 microsegundos
}
//configura serial para velocidade de 9600 kbps								//
void velocidadeSerial_1_9600Kbps(void)
{
	HAL_UART_Abort_IT(&huart1);
	HAL_UART_Abort_IT(&huart5);
	HAL_UART_DeInit(&huart1);
	HAL_UART_DeInit(&huart5);
	huart1.Init.BaudRate = 9600;
	huart5.Init.BaudRate = 9600;
	HAL_UART_Init(&huart1);
	HAL_UART_Init(&huart5);
	HAL_UART_Receive_IT (&huart1,Rx_ModbusSerial_1,1);
	HAL_UART_Receive_IT (&huart5,Rx_ModbusSerial_1,1);
	silentModBusRtu = 20;//4000 microsegundos
}
//configura serial para velocidade de 4800 kbps								//
void velocidadeSerial_1_4800Kbps(void)
{
	HAL_UART_Abort_IT(&huart1);
	HAL_UART_Abort_IT(&huart5);
	HAL_UART_DeInit(&huart1);
	HAL_UART_DeInit(&huart5);
	huart1.Init.BaudRate = 4800;
	huart5.Init.BaudRate = 4800;
	HAL_UART_Init(&huart1);
	HAL_UART_Init(&huart5);
	HAL_UART_Receive_IT (&huart1,Rx_ModbusSerial_1,1);
	HAL_UART_Receive_IT (&huart5,Rx_ModbusSerial_1,1);
	silentModBusRtu = 40;//8000 microsegundos
}
//configura serial para velocidade de 4800 kbps								//
void velocidadeSerial_1_2400Kbps(void)
{
	HAL_UART_Abort_IT(&huart1);
	HAL_UART_Abort_IT(&huart5);
	HAL_UART_DeInit(&huart1);
	HAL_UART_DeInit(&huart5);
	huart1.Init.BaudRate = 2400;
	huart5.Init.BaudRate = 2400;
	HAL_UART_Init(&huart1);
	HAL_UART_Init(&huart5);
	HAL_UART_Receive_IT (&huart1,Rx_ModbusSerial_1,1);
	HAL_UART_Receive_IT (&huart5,Rx_ModbusSerial_1,1);
	silentModBusRtu = 80;//16000 microsegundos
}
//configura serial para velocidade de 1200 kbps								//
void velocidadeSerial_1_1200Kbps(void)
{
	HAL_UART_Abort_IT(&huart1);
	HAL_UART_Abort_IT(&huart5);
	HAL_UART_DeInit(&huart1);
	HAL_UART_DeInit(&huart5);
	huart1.Init.BaudRate = 1200;
	huart5.Init.BaudRate = 1200;
	HAL_UART_Init(&huart1);
	HAL_UART_Init(&huart5);
	HAL_UART_Receive_IT (&huart1,Rx_ModbusSerial_1,1);
	HAL_UART_Receive_IT (&huart5,Rx_ModbusSerial_1,1);
	silentModBusRtu = 160;//32000 microsegundos
}	
// Faz o tratamento de erro da serial 1
void trataErroSerial_1(void)
{

}
