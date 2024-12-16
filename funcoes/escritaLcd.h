#include "carregaArrayComEspacoAscii.h"
extern UART_HandleTypeDef huart3;
//////////////////////////////////////////////////////////////////////////////////
//Funcao que controla o tempo de ixibicao da tela temporaria                  	//
//////////////////////////////////////////////////////////////////////////////////
void controlaTempoExibeTelaTemporaria (void)
{
    if (mostraTelaTemporariaLcd == 1)
    {
        if (++tempoMostraTelaTemporariaLcd > 20)
        {
            mostraTelaTemporariaLcd = 0;
            tempoMostraTelaTemporariaLcd = 0;
            transfereArrayToArray(32,&backupTelaLcd[0],&caracterLcd[0]);
            transfereArrayToArray(6,&backupDigitosLcdSeteSegmentos[0],&dadoLcdSetSegmentos[1]);
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////
//Funcao para apagar todos os caracteres do lcd                                	//
//////////////////////////////////////////////////////////////////////////////////
unsigned char indexApagaLcd;
void apagaLcd(void)
{
   indexApagaLcd = 0;
//   charDestino = &caracterLcd[0];
   while (++indexApagaLcd < 32) 
  {
//  *charDestino = ' ';
  }  
}
//////////////////////////////////////////////////////////////////////////////////
//Funcao para apagar a linha 1 do lcd                                          	//
//////////////////////////////////////////////////////////////////////////////////
void apagaLinha_1Lcd(void)
{
   indexApagaLcd = 0;
//   charDestino = &caracterLcd[0];
   while (++indexApagaLcd < 16) 
  {
//        *charDestino = ' ';
  }  
}
//////////////////////////////////////////////////////////////////////////////////
//Funcao para apagar a linha 2 do lcd                                          	//
//////////////////////////////////////////////////////////////////////////////////
void apagaLinha_2Lcd(void)
{
   indexApagaLcd = 0;
//   charDestino = &caracterLcd[0];
   while (++indexApagaLcd < 16) 
  {
//  *charDestino = ' ';
  }  
}
//////////////////////////////////////////////////////////////////////////////////
//Funcao utilizada para transferir uma array de string para ser escrita na   	//
//no lcd                                                                        //
//////////////////////////////////////////////////////////////////////////////////
int escreveDadoLcd(const char *charOrigem,unsigned char*charDestino)
{
	while (*charOrigem != 0)
    {
        *charDestino = *charOrigem;
        charOrigem++;
        charDestino++;   
    }
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que controla a escrita de dados no lcd                                 //
//////////////////////////////////////////////////////////////////////////////////
void controlaEscritaLcd (void)
{
    if (delayLcd == 0)
    {
       switch (statusAtualEscritaLcd) {        
// Inicializa o lcd 
            case inicializaLcd:
                if (flagInicializacaoPreparadaLcd == 0)
                {
//Prepara dados para inicializar o lcd
                    flagInicializacaoPreparadaLcd = 1; 

                    delayLcd = delayExterno30Mls;
                    quantidadeByteLcd = 8;
                    indexEscreveDadoLcd = 0;
                    caracterLcd[indexEscreveDadoLcd++] = 0x30;// envia comando para inicializar display 
                    caracterLcd[indexEscreveDadoLcd++] = 0x30;// envia comando para inicializar display 
                    caracterLcd[indexEscreveDadoLcd++] = 0x30;// envia comando para inicializar display 
                    caracterLcd[indexEscreveDadoLcd++] = 0x28;// configura LCD, 4 bits, matriz de 7x5, 1 linha
                    caracterLcd[indexEscreveDadoLcd++] = 0x28;// configura LCD, 4 bits, matriz de 7x5, 1 linha
                    caracterLcd[indexEscreveDadoLcd++] = 0x0C;// display sem cursor
                    caracterLcd[indexEscreveDadoLcd++] = 0x06;// desloca cursor para a direita
                    caracterLcd[indexEscreveDadoLcd++] = 0x01;// desloca cursor para a direita
                    indexEscreveDadoLcd = 0;
                }
                else
                {
//Faz efetivamente a inicialziacao do lcd
                    if (quantidadeByteLcd == 5)
                    {
                        quantidadeByteLcd--;
                        HAL_GPIO_WritePin(pinoSelectRegister_GPIO_Port, pinoSelectRegister_Pin, GPIO_PIN_RESET);
                        delayInternoMicroSegundos(90);
                        byteDataLcd.Byte = caracterLcd[indexEscreveDadoLcd++];
                        transmiteNibleLcd();
                        HAL_GPIO_WritePin(pinoEnable_GPIO_Port, pinoEnable_Pin, GPIO_PIN_SET);
                        delayInternoMicroSegundos(20);
                        HAL_GPIO_WritePin(pinoEnable_GPIO_Port, pinoEnable_Pin, GPIO_PIN_RESET);
                    }
                    else
                    {                       
                        if (quantidadeByteLcd == 0)
                        {
                            statusAtualEscritaLcd = escreveCaracterEspecialCgRam;
                        }
                        else
                        {
                            quantidadeByteLcd--;
                            byteDataLcd.Byte = caracterLcd[indexEscreveDadoLcd++];  
                            enviaComandoLcd();
                        }
                    }                    
                }
            break;
//EscreveCaracterEspecial na Cg ram
            case escreveCaracterEspecialCgRam:
               if (flagPreparaEscritaCgRam == 0)
                {
                   flagPreparaEscritaCgRam = 1;
                   byteDataLcd.Byte = EnderecoCgram;
                   enviaComandoLcd();
                   quantidadeByteLcd = 0;
                   indexEscreveDadoLcd = 0;
                }
                else
                {
                    byteDataLcd.Byte = tabelaCgRam[indexEscreveDadoLcd++];
                    enviaCaracterLcd();
                    if (++quantidadeByteLcd > 63)
                    {
                        statusAtualEscritaLcd = enviaComandoEscritaLinha_1Lcd; 
                        carregaArrayComEspacoAscii(32,&caracterLcd[0]);
                    }               
               }            
            break;
//muda endereco para escrita na linha 1 do lcd
            case enviaComandoEscritaLinha_1Lcd:
                statusAtualEscritaLcd = enviaCaracterLinha_1Lcd;
                byteDataLcd.Byte = EnderecoLinha1;
                indexEscreveDadoLcd = 0;
                quantidadeByteLcd = 16;
                enviaComandoLcd();
            break;
//muda endereco para escrita na linha 2 do lcd        
            case enviaComandoEscritaLinha_2Lcd:
                statusAtualEscritaLcd = enviaCaracterLinha_2Lcd;
                byteDataLcd.Byte = EnderecoLinha2;
                indexEscreveDadoLcd = 16;
                quantidadeByteLcd = 16;
                enviaComandoLcd();           
            break;
//controla a escrita de dados na linha 1 do lcd     
            case enviaCaracterLinha_1Lcd:
                byteDataLcd.Byte = caracterLcd[indexEscreveDadoLcd++];
                enviaCaracterLcd();
                if (--quantidadeByteLcd == 0)
                {
                    statusAtualEscritaLcd = enviaComandoEscritaLinha_2Lcd;      
                }           
            break; 
 //controla a escrita de dados na linha 2 do lcd  
            case enviaCaracterLinha_2Lcd:
                byteDataLcd.Byte = caracterLcd[indexEscreveDadoLcd++];
                enviaCaracterLcd();
                if (--quantidadeByteLcd == 0)
                {
                    statusAtualEscritaLcd = enviaComandoEscritaLinha_1Lcd;      
                }           
            break;
       }
    }
}
//////////////////////////////////////////////////////////////////////////////////
//Envia comando para o Lcd                                                      //
//////////////////////////////////////////////////////////////////////////////////
void enviaComandoLcd (void)
{
	HAL_GPIO_WritePin(pinoSelectRegister_GPIO_Port, pinoSelectRegister_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoEnable_GPIO_Port, pinoEnable_Pin,GPIO_PIN_RESET);
    transmiteByteLcd();
    delayLcd = delayExterno5Mls;
}
//////////////////////////////////////////////////////////////////////////////////
//Envia Caracter para o Lcd                                                     //
//////////////////////////////////////////////////////////////////////////////////
void enviaCaracterLcd (void)
{
	HAL_GPIO_WritePin(pinoSelectRegister_GPIO_Port, pinoSelectRegister_Pin,GPIO_PIN_SET);
	HAL_GPIO_WritePin(pinoEnable_GPIO_Port, pinoEnable_Pin,GPIO_PIN_RESET);
    transmiteByteLcd();
    delayLcd = delayExterno500Micro;
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que controla o envio de um byte ao lcd                                 //
//////////////////////////////////////////////////////////////////////////////////
void transmiteByteLcd(void)
{
    transmiteNibleLcd();
    HAL_GPIO_WritePin(pinoEnable_GPIO_Port, pinoEnable_Pin,GPIO_PIN_SET);
    delayInternoMicroSegundos(20);
    HAL_GPIO_WritePin(pinoEnable_GPIO_Port, pinoEnable_Pin,GPIO_PIN_RESET);
    byteDataLcd.Byte = byteDataLcd.Byte <<4;
 
    transmiteNibleLcd();
    HAL_GPIO_WritePin(pinoEnable_GPIO_Port, pinoEnable_Pin,GPIO_PIN_SET);
    delayInternoMicroSegundos(20);
    HAL_GPIO_WritePin(pinoEnable_GPIO_Port, pinoEnable_Pin,GPIO_PIN_RESET);
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que manda nible para o lcd, sao dois nible por byte                    //
//////////////////////////////////////////////////////////////////////////////////
void transmiteNibleLcd (void)
{
	HAL_GPIO_WritePin(pinoData7_GPIO_Port, pinoData7_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoData6_GPIO_Port, pinoData6_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoData5_GPIO_Port, pinoData5_Pin,GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoData4_GPIO_Port, pinoData4_Pin,GPIO_PIN_RESET);
   
    if (byteDataLcd.Flag.Bit7 == 1)
    {
    	HAL_GPIO_WritePin(pinoData7_GPIO_Port, pinoData7_Pin,GPIO_PIN_SET);
    }
    if (byteDataLcd.Flag.Bit6 == 1)
    {
    	HAL_GPIO_WritePin(pinoData6_GPIO_Port, pinoData6_Pin,GPIO_PIN_SET);
    }
    if (byteDataLcd.Flag.Bit5 == 1)
    {
    	HAL_GPIO_WritePin(pinoData5_GPIO_Port, pinoData5_Pin,GPIO_PIN_SET);    
    }
    if (byteDataLcd.Flag.Bit4 == 1)
    {
    	HAL_GPIO_WritePin(pinoData4_GPIO_Port, pinoData4_Pin,GPIO_PIN_SET);
    }
}
//////////////////////////////////////////////////////////////////////////////////
//metodo que contrala tempos maiores utilizando o timer das tasks               //
//////////////////////////////////////////////////////////////////////////////////
void delayExternoLcd (void)
{
    if (delayLcd != 0)
    {
       delayLcd--;
    }
}
//////////////////////////////////////////////////////////////////////////////////
//faz delay de em micro segundos necesssario para o lcd validar o dado          //
//////////////////////////////////////////////////////////////////////////////////
void delayInternoMicroSegundos (unsigned char delayInterno)
{
    while (delayInterno !=0)
    {
        delayInterno--;
    }
}

