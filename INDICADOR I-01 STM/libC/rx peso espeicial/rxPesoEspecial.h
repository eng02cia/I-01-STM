//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//  Faz recep��o dos dados quando indicador digitron modo t2					//	
//////////////////////////////////////////////////////////////////////////////////		
#include "somaValorArray.h"
#include "pesoGramaDecimalToPesoKgAscii.h"
#include "inserePontoDecimal.h"
#include "pesoKgAsciiToPesoGramaDecimal.h"
#include "zeroAsciiEsquerdaToVazioAscii.h"
#include "verificaValorArrayIgualZeroDecimal.h"
#include "subtracaoValorArray.h"
#include "comparaValoresArray.h"
//////////////////////////////////////////////////////////////////////////////////
//inicializa Rx serial digitron                                                 //
//////////////////////////////////////////////////////////////////////////////////
void initRxPesoDigitronT2(void)
{
    statusRxPesoDigitronSerial_1 = _ATIVADO;
}

//////////////////////////////////////////////////////////////////////////////////
//interrup��o da serial 1                                                       //
//////////////////////////////////////////////////////////////////////////////////
void serial_1InterruptDigitronT2(void)
{
 #ifdef _16F1716
    if(PIE1bits.RCIE == 1 & PIR1bits.RCIF == 1)
    {	
        PIR1bits.RCIF = 0;
        dado_Serial_1 = RCREG1;
        RCREG = 0; 
        recebeFramePesoSerial_1();
    }	
#endif        
#ifdef _18F24K40
    if(PIE3bits.RCIE == 1 & PIR3bits.RCIF == 1)
    {	
        PIR3bits.RCIF = 0;
        dado_Serial_1 = RCREG;
        RCREG1 = 0;  
        recebeFramePesoSerial_1();
    }	
#endif
#ifdef _18F26K40
    if(PIE3bits.RC1IE == 1 & PIR3bits.RC1IF == 1)
    {	
        PIR3bits.RC1IF = 0;
        dado_Serial_1 = RCREG1;
        RCREG1 = 0;  
       recebeFramePesoSerial_1();        
    }	
#endif    
#ifdef _18F26K22
    if(PIE1bits.RCIE == 1 & PIR1bits.RCIF == 1)
    {	
        PIR1bits.RCIF = 0;
        dado_Serial_1 = RCREG1;
        RCREG = 0; 

    }	
#endif 
#ifdef _16F886
    if(PIE1bits.RCIE == 1 & PIR1bits.RCIF == 1)
    {	
        PIR1bits.RCIF = 0;
        dado_Serial_1 = RCREG;
        RCREG = 0; 
        recebeFramePesoSerial_1();
    }	
#endif        
}
//////////////////////////////////////////////////////////////////////////////////	
//fun��o que recebe um frame de dados de peso                           		//
//////////////////////////////////////////////////////////////////////////////////		
void recebeFramePesoSerial_1DigitronT2(void)
{
    if(statusRxPesoDigitronSerial_1 == _ATIVADO)
    {
        flagTempoControleFinalFrameSerial_1 = 1;
        tempoControleFinalFrameSerial_1 = 0;  
        frameRxSerial_1[indexSerial_1++] = dado_Serial_1[0];
        tamanhoFrameRxSerial_1 ++;
        if (tamanhoFrameRxSerial_1 >= 40)
        {	
            tamanhoFrameRxSerial_1 = 0;
            indexSerial_1 = 0;	            
//            controleTempoJanelaFrameSerial_1();
//            mudaVelocidadeSerial_1();
        }
	}
}
//////////////////////////////////////////////////////////////////////////////////
//Tempo de controle da recep��o de um frame pela serial							//
//Aguarda um  periodo de tempo sem a recep��o de bytes para considerar final do	//
//frame dai passa a analizar o frame											//
//executar a cada 1 mls                                                         //
//////////////////////////////////////////////////////////////////////////////////
void tempoControleRxSerial_1DigitronT2(void)
{
    if(statusRxPesoDigitronSerial_1 == _ATIVADO)
    {
        if(flagTempoControleFinalFrameSerial_1 == 1)
        {
            tempoControleFinalFrameSerial_1++;
            if(tempoControleFinalFrameSerial_1 >= 15)
            {
                tamanhoFramePeso = tamanhoFrameRxSerial_1;
                tamanhoFrameRxSerial_1 = 0;
                indexSerial_1 = 0;	                            
                flagApagaDisplaySeteSegmentos = 1;
                tempoApagaDisplaySeteSegmentos = 0;
                flagTempoControleFinalFrameSerial_1 = 0;		
                tempoControleFinalFrameSerial_1 = 0;
                flagTempoSemDadoSerial_1 = 1;
                tempoSemDadoSerial_1 = 0;
                statusBufferSerial_1 = _BUFFER_CHEIO;
                statusErroRxPesoSerial_1 = _COM_BALANCA;
                if(frameRxSerial_1[0] == 0x2 || frameRxSerial_1[0] == 0x82)
                {
                    trataFrameRxToledoP03();
                }
                else
                {
                    trataFrameRxDigitronT2();
                }
                
            }
		}
	}	
}
//////////////////////////////////////////////////////////////////////////////////
//trata frame t2 digitron                           							//
//////////////////////////////////////////////////////////////////////////////////
/*
 * Identifica��o de tipo de pacote feame peso digitron T2
 * Sem tara est�vel             68 decimal
 * Com tara est�vem             69 decimal
 * sem tara oscilante           64 decimal
 * com tara oscilante           65  decimal
 * sem tara negativo            76 decimal
 * com tara negativo            77 decimal
 * sem tara oscilante negativo  72 decimal
 * com tata oscilante negativo  73 decimal
 * balan�a em zero              70 decimal
 */
void trataFrameRxDigitronT2(void)
{ 
    carregaArrayComEspacoAscii(7,&pesoAsciiSerial_1[0]);
    carregaArrayComEspacoAscii(7,&pesoLiquidoPesoEspecial[0]);
    carregaArrayComEspacoAscii(7,&pesoTaraPesoEspecial[0]);

    tipoDadoRxDigitronT2 = frameRxSerial_1[0];    
//diferencia��o da vers�o do frame do digitron de acordo com o tamanho do frame de peso
    if(tamanhoFramePeso == 18)
    {
        if(frameRxSerial_1[7] != '.')
        {
            transfereArrayToArray(7,&frameRxSerial_1[1],&pesoAsciiSerial_1[0]);    
            transfereArrayToArray(7,&frameRxSerial_1[1],&pesoLiquidoPesoEspecial[0]);
            transfereArrayToArray(7,&frameRxSerial_1[10],&pesoTaraPesoEspecial[0]); 
        }
        else
        {
            transfereArrayToArray(6,&frameRxSerial_1[1],&pesoAsciiSerial_1[1]);    
            transfereArrayToArray(6,&frameRxSerial_1[1],&pesoLiquidoPesoEspecial[1]);
            transfereArrayToArray(6,&frameRxSerial_1[10],&pesoTaraPesoEspecial[1]);           
        }
    }
    else
    {
        if(frameRxSerial_1[6] != '.')
        {
            transfereArrayToArray(6,&frameRxSerial_1[1],&pesoAsciiSerial_1[1]);    
            transfereArrayToArray(6,&frameRxSerial_1[1],&pesoLiquidoPesoEspecial[1]);
            transfereArrayToArray(6,&frameRxSerial_1[9],&pesoTaraPesoEspecial[1]); 
        }
        else
        {
            transfereArrayToArray(5,&frameRxSerial_1[1],&pesoAsciiSerial_1[2]);    
            transfereArrayToArray(5,&frameRxSerial_1[1],&pesoLiquidoPesoEspecial[2]);
            transfereArrayToArray(5,&frameRxSerial_1[9],&pesoTaraPesoEspecial[2]);           
        }
    }           
    posicaoPontoPesoEspecial = identificaPosicaoPontoDecimal(&pesoAsciiSerial_1[6]); 
    zeroAsciiEsquerdaToVazioAscii(7,&pesoAsciiSerial_1[0]);
    zeroAsciiEsquerdaToVazioAscii(7,&pesoLiquidoPesoEspecial[0]);
    zeroAsciiEsquerdaToVazioAscii(7,&pesoTaraPesoEspecial[0]);            
    if(tipoDadoRxDigitronT2 == 'L' || tipoDadoRxDigitronT2 == 'M' || tipoDadoRxDigitronT2 == 'H' ||tipoDadoRxDigitronT2 == 'I')
    {
       pesoNegativoPesoEspecial = '-'; 
       pesoAsciiSerial_1[0] = '-';
    }
    else{pesoNegativoPesoEspecial = '+';}
    if(pesoNegativoPesoEspecial == '+')
    {        
        metodoComumTrataPesoEspecial();
    }
}
//////////////////////////////////////////////////////////////////////////////////
//trata frame toledo P03                               							//
//////////////////////////////////////////////////////////////////////////////////
void trataFrameRxToledoP03(void)
{
//transforma bytes de 7 bits para 8 bits  
    carregaArrayComEspacoAscii(7,&pesoAsciiSerial_1[0]);
    carregaArrayComEspacoAscii(7,&pesoBrutoPesoEspecial[0]);
    carregaArrayComEspacoAscii(7,&pesoLiquidoPesoEspecial[0]);
    carregaArrayComEspacoAscii(7,&pesoTaraPesoEspecial[0]);    
  	for (indexPesoEspecial = 0 ; indexPesoEspecial < 20 ; indexPesoEspecial ++)
    {		
        frameRxSerial_1[indexPesoEspecial] = frameRxSerial_1 [indexPesoEspecial] & 0b01111111;// usado para transforma bytes recebidos de 7 para 8 bytes
	}  
    rtempPesoEspecial = frameRxSerial_1[1] & 0b00000111;// usado para filtrar a posi��o do ponto decimal		
    if(rtempPesoEspecial == 0 ||rtempPesoEspecial == 1 ||rtempPesoEspecial== 2){posicaoPontoPesoEspecial = 0;}
    if(rtempPesoEspecial == 3){posicaoPontoPesoEspecial = 1;}
    if(rtempPesoEspecial == 4){posicaoPontoPesoEspecial = 2;}
    if(rtempPesoEspecial == 5){posicaoPontoPesoEspecial = 3;}
    
    
    transfereArrayToArray(6,&frameRxSerial_1[4],&pesoAsciiSerial_1[1]);
//   transfereArrayToArray(6,&frameRxSerial_1[4],&pesoBrutoPesoEspecial[1]);
    transfereArrayToArray(6,&frameRxSerial_1[4],&pesoLiquidoPesoEspecial[1]);
    transfereArrayToArray(6,&frameRxSerial_1[10],&pesoTaraPesoEspecial[1]); 
//    posicaoPontoPesoEspecial = identificaPosicaoPontoDecimal(&pesoAsciiSerial_1[6]); 

    zeroAsciiEsquerdaToVazioAscii(7,&pesoAsciiSerial_1[0]);
    zeroAsciiEsquerdaToVazioAscii(7,&pesoBrutoPesoEspecial[0]);
//    zeroAsciiEsquerdaToVazioAscii(7,&pesoLiquidoPesoEspecial[0]);
    zeroAsciiEsquerdaToVazioAscii(7,&pesoTaraPesoEspecial[0]);   
    inserePontoDecimal(posicaoPontoPesoEspecial,7,&pesoAsciiSerial_1[0]);  
    rtempPesoEspecial = frameRxSerial_1[2];
	rtempPesoEspecial = rtempPesoEspecial & 0b00000010;// usado para filtrar a indica��o de peso negativo
    if(rtempPesoEspecial != 0)
    {
        pesoNegativoPesoEspecial = '-'; 
        pesoAsciiSerial_1[0] = '-';
        metodoColocaPontoPesoEspecial();
    }
    else{pesoNegativoPesoEspecial = '+';}
    if(pesoNegativoPesoEspecial == '+')
    {         
        metodoComumTrataPesoEspecial();
    }
}
//////////////////////////////////////////////////////////////////////////////////
//metodo comum trata peso especial                           					//
//////////////////////////////////////////////////////////////////////////////////
void metodoComumTrataPesoEspecial(void)
{

	pesoKgAsciiToPesoGramaDecimal(posicaoPontoPesoEspecial,7,&pesoLiquidoPesoEspecial[0],9,&pesoLiquidoDecimal[0]);
	pesoKgAsciiToPesoGramaDecimal(posicaoPontoPesoEspecial,7,&pesoBrutoPesoEspecial[0],9,&pesoBrutoDecimal[0]);
    pesoKgAsciiToPesoGramaDecimal(posicaoPontoPesoEspecial,7,&pesoTaraPesoEspecial[0],9,&pesoTaraDecimal[0]);         
    erroPesoTara = verificaValorArrayIgualZeroDecimal(9,&pesoTaraDecimal[0]);
    if(erroPesoTara != 1)
    {
    	//transfereArrayToArray(9,&pesoLiquidoDecimal[0],&pesoBrutoDecimal[0]);
    	transfereArrayToArray(6,&valorTaraManual[0],&tempConvertePesoEspecial[1]);
    	transformaParaKilograma();
    	transfereArrayToArray(7,&tempConvertePesoEspecial[0],&valorTaraManualPesoEspecial[0]);

    	transfereArrayToArray(6,&valorPesoMorto[0],&tempConvertePesoEspecial[1]);
    	transformaParaKilograma();
    	transfereArrayToArray(7,&tempConvertePesoEspecial[0],&valorPesoMortoPesoEspecial[0]);

    	pesoKgAsciiToPesoGramaDecimal(posicaoPontoPesoEspecial,7,&valorTaraManualPesoEspecial[0],9,&pesoTaraDecimal[0]);
    	pesoKgAsciiToPesoGramaDecimal(posicaoPontoPesoEspecial,7,&valorPesoMorto[0],9,&pesoMortoDecimal[0]);

    	transfereArrayToArray(9,&pesoMortoDecimal[0],&tempCalculaPeso[0]);
    	somaValorArray(9,&tempCalculaPeso[0],&pesoTaraDecimal[0]);

    	tempRxPesoEspecial = comparaValoresArray(9,&tempCalculaPeso[0],&pesoBrutoDecimal[0]);
    	erroTarraMaiorQueLiquido = 0;
    	if(tempRxPesoEspecial == 1)
    	{
    		erroTarraMaiorQueLiquido = 1;
    	}
    }

	verificaTara = verificaValorArrayIgualZeroDecimal(9,&pesoTaraDecimal[0]);
	if(verificaTara != 0)
	{
		transfereArrayToArray(7,&pesoTaraDecimal[0],&tempCalculaPeso[0]);
		somaValorArray(9, &tempCalculaPeso[0],&pesoLiquidoDecimal[0]);
		transfereArrayToArray(7,&tempCalculaPeso[0],&pesoBrutoDecimal[0]);
		pesoGramaDecimalToPesoKgAscii(1,posicaoPontoPesoEspecial,9,&pesoBrutoDecimal[0],7,&pesoBrutoPesoEspecial[0]);
		pesoGramaDecimalToPesoKgAscii(1,posicaoPontoPesoEspecial,9,&pesoTaraDecimal[0],7,&pesoTaraPesoEspecial[0]);
		pesoGramaDecimalToPesoKgAscii(1,posicaoPontoPesoEspecial,9,&pesoLiquidoDecimal[0],7,&pesoLiquidoPesoEspecial[0]);
	}
	else
	{
		transfereArrayToArray(7,&pesoLiquidoDecimal[0],&pesoBrutoDecimal[0]);
		//subtracaoValorArray(9,&pesoLiquidoDecimal[0],&tempCalculaPeso[0]);
		pesoGramaDecimalToPesoKgAscii(1,posicaoPontoPesoEspecial,9,&pesoBrutoDecimal[0],7,&pesoBrutoPesoEspecial[0]);
		pesoGramaDecimalToPesoKgAscii(1,posicaoPontoPesoEspecial,9,&pesoTaraDecimal[0],7,&pesoTaraPesoEspecial[0]);
		pesoGramaDecimalToPesoKgAscii(1,posicaoPontoPesoEspecial,9,&pesoLiquidoDecimal[0],7,&pesoLiquidoPesoEspecial[0]);
	}



}
void metodoColocaPontoPesoEspecial(void)
{
    pesoKgAsciiToPesoGramaDecimal(posicaoPontoPesoEspecial,7,&pesoTaraPesoEspecial[0],9,&pesoTaraDecimal[0]);
	pesoGramaDecimalToPesoKgAscii(1,posicaoPontoPesoEspecial,9,&pesoTaraDecimal[0],7,&pesoTaraPesoEspecial[0]);
}
//////////////////////////////////////////////////////////////////////////////////
/*transforma o peso programado em kiligrama                                     */
//////////////////////////////////////////////////////////////////////////////////
void transformaParaKilograma(void)
{
	loopConvertePonto = posicaoPontoPesoEspecial;
	while (loopConvertePonto !=0)
	{
        loopConvertePonto--;  
        tempConvertePesoEspecial[0] = tempConvertePesoEspecial[1]; 
        tempConvertePesoEspecial[1] = tempConvertePesoEspecial[2]; 
        tempConvertePesoEspecial[2] = tempConvertePesoEspecial[3]; 
        tempConvertePesoEspecial[3] = tempConvertePesoEspecial[4]; 
        tempConvertePesoEspecial[4] = tempConvertePesoEspecial[5]; 
        tempConvertePesoEspecial[5] = tempConvertePesoEspecial[6]; 
        tempConvertePesoEspecial[6] = '0'; 
	}
}
//////////////////////////////////////////////////////////////////////////////////
/*Rotaciona a array durante a progtama��o                                       */
//////////////////////////////////////////////////////////////////////////////////
void rotacionaArrayProgCarregamento(void)
{

}

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
