//////////////////////////////////////////////////////////////////////////////////		
//                       Fun��es Rx peso serial 1                         		//		
//////////////////////////////////////////////////////////////////////////////////
extern UART_HandleTypeDef huart2;
//#include "definicoesConpilacao.h"
#include "velocidade1200KbpsSerial_1.h"
#include "velocidade2400KbpsSerial_1.h"
#include "velocidade4800KbpsSerial_1.h"
#include "velocidade9600KbpsSerial_1.h"
#include "velocidade19200KbpsSerial_1.h"
#include "transfereArrayToArray.h"

//#define _BALANCASCURITIBA 
//////////////////////////////////////////////////////////////////////////////////	
//inicializa o temp da janela entre frames da serial 1                     		//
//////////////////////////////////////////////////////////////////////////////////	
void initRxPesoSerial_1(void)
{
    tempoReferenciaFinalFrameSerial_1 = 50;
}
//////////////////////////////////////////////////////////////////////////////////	
//fun��o que recebe um frame de dados de peso                           		//
//////////////////////////////////////////////////////////////////////////////////		
void recebeFramePesoSerial_1(void)
{
    tempoMaxPicaLedRxSerial_1 = 0;
    flagTempoControleFinalFrameSerial_1 = 1;
    tempoControleFinalFrameSerial_1 = 0;  
    frameRxSerial_1[indexSerial_1++] = dado_Serial_1[0];
    dado_Serial_1[0] = 0;
    tamanhoFrameRxSerial_1 ++;
    if (tamanhoFrameRxSerial_1 >= 55)
    {	
        tamanhoFrameRxSerial_1 = 0;
        indexSerial_1 = 0;	            
        controleTempoJanelaFrameSerial_1();
        mudaVelocidadeSerial_1();
        carregaArrayComZeroDecimal(60,&frameRxSerial_1[0]);
	}
}
//////////////////////////////////////////////////////////////////////////////////
//Tempo de controle da recep��o de um frame pela serial							//
//Aguarda um  periodo de tempo sem a recep��o de bytes para considerar final do	//
//frame dai passa a analizar o frame											//
//executar a cada 1 mls                                                         //
//////////////////////////////////////////////////////////////////////////////////
void tempoControleRxSerial_1(void)
{

	if(flagTempoControleFinalFrameSerial_1 == 1)
	{
		tempoControleFinalFrameSerial_1++;
		if(tempoControleFinalFrameSerial_1 >= tempoReferenciaFinalFrameSerial_1)
		{
			flagTempoControleFinalFrameSerial_1 = 0;
			tempoControleFinalFrameSerial_1 = 0;
			flagTempoSemDadoSerial_1 = 1;
			tempoSemDadoSerial_1 = 0;
			//                flagApagaDisplaySeteSegmentos = 1;
			//                tempoApagaDisplaySeteSegmentos = 0;
#ifdef _BALANCASCURITIBA    
			statusProtocoloIdenticadoSerial_1 = funcTrataProtocolosBalancasCuritiba(tamanhoFrameRxSerial_1,tipoProtocoloEep,&frameRxSerial_1[0]);
#endif        
#ifndef _BALANCASCURITIBA    
			statusProtocoloIdenticadoSerial_1 = funcTrataProtocolosBalancas(tamanhoFrameRxSerial_1,tipoProtocoloEep,&frameRxSerial_1[0]);
#endif                

			indexSerial_1 = 0;
			if(statusProtocoloIdenticadoSerial_1 != 1)
			{
				tamanhoFrameRxSerial_1 =0;
				mudaVelocidadeSerial_1();
				controleTempoJanelaFrameSerial_1();
			    carregaArrayComZeroDecimal(60,&frameRxSerial_1[0]);
			}
			else
			{
				rloopMudaTempoJanelaFrameSerial_1 = 0;
				tamanhoFrameRxSerial_1Backup = tamanhoFrameRxSerial_1;
				transfereArrayToArray(tamanhoFrameRxSerial_1,&frameRxSerial_1[0],&frameRxSerial_1Backup[0]);

#ifdef _BALANCASCURITIBA    
				getPesoIndicadorBalCuritibaAscii(&pesoAsciiSerial_1[0]);
#endif 
#ifndef _BALANCASCURITIBA                        
				getPesoIndicadorAscii(&pesoAsciiSerial_1[0]);
#endif                    
				tamanhoFrameRxSerial_1 = 0;
				statusBufferSerial_1 = _BUFFER_CHEIO;
				statusErroRxPesoSerial_1 = _COM_BALANCA;
			    carregaArrayComZeroDecimal(60,&frameRxSerial_1[0]);
			}
		}
	}
}	

//////////////////////////////////////////////////////////////////////////////////		
//Muda a velocidade da serial quando n�o encontra um frame de peso valido 		//
//////////////////////////////////////////////////////////////////////////////////		
void mudaVelocidadeSerial_1(void)
{
    switch (velocidadeSerial_1Atual)
    {
        case velocidadeSerial_1_1200Kbps:
            velocidadeSerial_1Atual = velocidadeSerial_1_2400Kbps;
            velocidade2400KbpsSerial_1();
        break;            
        case velocidadeSerial_1_2400Kbps:
            velocidadeSerial_1Atual = velocidadeSerial_1_4800Kbps;
            velocidade4800KbpsSerial_1();
        break;
        case velocidadeSerial_1_4800Kbps:
            velocidadeSerial_1Atual = velocidadeSerial_1_9600Kbps;
            velocidade9600KbpsSerial_1();
        break; 
        case velocidadeSerial_1_9600Kbps:
            velocidadeSerial_1Atual = velocidadeSerial_1_19200Kbps;
            velocidade19200KbpsSerial_1();
        break;
        case velocidadeSerial_1_19200Kbps:            
            velocidadeSerial_1Atual = velocidadeSerial_1_1200Kbps;
            velocidade1200KbpsSerial_1();
        break;	
	}
    HAL_UART_Receive_IT(&huart2,dado_Serial_1,1);//ativa recepção serial
}
//////////////////////////////////////////////////////////////////////////////////
//Funcao que faz a alternancia entre RS232 e RS485 a cada 5 segundos		 	//
//Metodo utilizado para identificar em qual serial esta chegando os dados		//
//Quando um protocolo � identificado a alternacia para							//
//////////////////////////////////////////////////////////////////////////////////
void funcaoIdentificaEntradaSerial_1(void)						
{
	rloopIdentificaEntradaSerial_1++;
	if(rloopIdentificaEntradaSerial_1 == 5)//quantidade de velocidades possiveis
	{
    	rloopIdentificaEntradaSerial_1 = 0;
//		if(pinoIdentificaEntradaSerial_1 == 0){pinoIdentificaEntradaSerial_1 = 1;}
//		else{pinoIdentificaEntradaSerial_1 = 0;}
    }
}
//////////////////////////////////////////////////////////////////////////////////
//Muda o tempo da janela entre frames permitida                                 //
//////////////////////////////////////////////////////////////////////////////////
void controleTempoJanelaFrameSerial_1(void)
{
#ifdef __RxSerial_1Rs485eRs232    
    if(++rloopMudaTempoJanelaFrameSerial_1 == 10)//quantidade de loop igual a 2 vezes a quantidade de velocidades seriais
#else
    if(++rloopMudaTempoJanelaFrameSerial_1 == 5) 
#endif        
    {
        rloopMudaTempoJanelaFrameSerial_1 = 0;
        tempoReferenciaFinalFrameSerial_1 = tempoReferenciaFinalFrameSerial_1 -5;
        if(tempoReferenciaFinalFrameSerial_1 < 5)
        {
            tempoReferenciaFinalFrameSerial_1 = tempoIntervaloEntreFrameSerial_1;
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que monitora a falta de dados na serial 1  						 	//
//executar a cada 1 segundo                                                     //
//////////////////////////////////////////////////////////////////////////////////
void funcaoIdentificaSemSerial_1(void)
{		
	if(flagTempoSemDadoSerial_1 == 1)
	{
		if(++tempoSemDadoSerial_1 > 5)
		{
			flagTempoSemDadoSerial_1 = 0;
			tempoSemDadoSerial_1 = 0;
            statusProtocoloIdenticadoSerial_1 = 0;
            velocidadeSerial_1Atual = velocidadeSerial_1_9600Kbps;
            velocidade9600KbpsSerial_1();
            HAL_UART_Receive_IT(&huart2,dado_Serial_1,1);//ativa recepção serial
         	indexSerial_1 = 0;

            funcLimpaDisplayPeso();
            getPesoIndicadorAscii(&pesoAsciiSerial_1[0]);
            statusErroRxPesoSerial_1 = _SEM_BALANCA;
		}
	}
}
