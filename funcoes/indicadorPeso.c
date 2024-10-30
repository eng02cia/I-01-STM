//////////////////////////////////////////////////////////////////////////////////
//                                                                            	//
//                        Sistema de corte 4 reles em C                   		//
//                                                                            	//
//                        Desenvolvido por   		                           	//
//                                                                            	//
//  			    		Clodoaldo Flugel			                       	//
//                                                                            	//
//               Inicio em 30/07/15 as 23:00 hs                               	//
//////////////////////////////////////////////////////////////////////////////////
//inclus�o das defini��es para o funcionamento do software						//
//////////////////////////////////////////////////////////////////////////////////
//static unsigned char arrayFloat[10]={"100.9987"};
//float resultTesteFloat;

#pragma warning disable 1510
#pragma warning disable 373
#pragma warning disable 520
#pragma warning disable 356
#define pilhaEepromAtiva
#define indicadorI01_1_5_2
//#define indicadorI01_1_5_3
#ifndef __definicoesDeCompilacao


//#define backLightAmarelo
#endif 
#include <xc.h>
#include <stdlib.h>
#include <stdio.h>
#include "headerIniciaSistema.h"
#include "fusiveisPic18f46k40.h"
#ifdef  _18F66K40
#include <pic18f66k40.h>
#include "headerDecodificaTecladoIndicador_I_01_1_5_3.h"
#endif
#if _18F46K40
#include "fusiveisPic18f46k40.h"
#include <pic18f46k40.h>
#include "headerDecodificaTecladoIndicador_I_01.h"
#endif

#include "headerEeprom.h"
#include "headerPilhaSaveEeprom.h"
#include "headerControleTask.h"
#include "headerControlaTelas.h"
#include "headerControleDasTeclas.h"

#include "headerEscritaLcd.h"
#ifdef indicadorI01_1_5_2
#include "headerTxSerial_1_1_5_2.h"
#endif
#ifdef indicadorI01_1_5_3
#include "headerTxSerial_1_1_5_3.h"
#endif
#include "headerTxSerial_2.h"
#include "headerCalibracaoIndicador.h"
#include "headerHx711.h"
#include "headerControleCelulaCarga.h"
#include "headerChecaAutorizaZeroIndicador.h"
#include "headerFazZeroIndicador.h"
#include "headerFazMediaAdCalibraIndicador.h"
//#include "headerControleCargaVivaIndicador.h"
#include "headerMenuAcessaMenusProgramacao.h"
#include "headerMenuConfiguraSerial.h"
#include "headerMenuModoTecnicoIndicador.h"
#include "headerModBusRtu.h"
#include "headerTrataModBusRtu.h"
#include "headerProtocoloSASigmaciaSerial_1.h"
#include "headerControleBackLight.h"

////////////////////////////////////////////////////////////

#include "eepromRead.h"
#include "eepromSave.h"
#include "pilhaSaveEeprom.h"
#include "initSistemaPIC18F46K40.h"
#ifdef indicadorI01_1_5_3
#include "decodificaTecladoIndicador_I_01_1_5_3.h"
#endif

#include "escritaLcd.h"
#include "controleTask.h"
#include "controlaTelas.h"
#include "controleDasTeclas.h"
#include "calibracaoIndicador.h"
#include "hx711.h"
#include "controleCelulaCarga.h"
#include "checaAutorizaZeroIndicador.h"
#include "fazZeroIndicador.h"
#include "fazMediaAdCalibraIndicador.h"
//#include "controleCargaVivaIndicador.h"
#include "controleBackLight.h"
#ifdef indicadorI01_1_5_2
#include "funcoesTxSerial_1_1_5_2.h"
#include "decodificaTecladoIndicador_I_01.h"
#endif
#ifdef indicadorI01_1_5_3
#include "funcoesTxSerial_1_1_5_3.h"
#endif
#include "txSerial_2.h"
#include "acessaMenusProgramacao.h"
#include "menuConfiguraSerial.h"
#include "menuModoTecnicoIndicador.h"
#include "modBusRtu.h"
#include "trataModBusRtu.h"
#include "protocoloSASigmaciaSerial_1.h"
//////////////////////////////////////////////////////////////////////////////////
// Fun��o principal																//
//////////////////////////////////////////////////////////////////////////////////
void main (void)
// fun��es de inicializa��o	do sistema											//
{
//    resultTesteFloat = atof(arrayFloat);
	iniciaSistema();
//    NOP();
//    mostraPesoIndicador();
//    NOP();
// loop principal																//
    while (1)  
	{
        ClrWdt();
        ControleMultTask();
    }
}
//////////////////////////////////////////////////////////////////////////////////
// Vetor da interrup��o alta													//
//////////////////////////////////////////////////////////////////////////////////
//#pragma code Vetor_Interrupcao_Alta = 0x08
//void Vetor_Interrupcao_Alta(void)
//{
//asm GOTO Interupcao_alta_real _endasm
//}

//////////////////////////////////////////////////////////////////////////////////
// Fun��o da interrup��o alta													//
//////////////////////////////////////////////////////////////////////////////////
//#pragma code /* retorno � sec��o code por defeito */
//#pragma interrupt Interupcao_alta_real
//void Interupcao_alta_real (void)
//void interrupt tc_int(void)             // High priority interrupt
void __interrupt(high_priority) tcInt(void)
{
//interrup��o do timer zero utilizada no controle da execu��o das tasks			//	
    multTaskInterrupt();
    hx711TaskInterrupt();
    if (statusSaidaDadosSerial_1Eep == _TRANSMISSAOCONTINUA_1
    || statusSaidaDadosSerial_1Eep == _TRANSMISSAOCONTINUA_2)
    {
#ifdef indicadorI01_1_5_2        
        if (PIE3bits.RC1IE == 1 & PIR3bits.RC1IF == 1)
        {        
            PIR3bits.RC1IF = 0;
            rrxModBusRtu = RCREG1;
            RCREG1 = 0; 
        } 
#endif
#ifdef indicadorI01_1_5_3        
        if (PIE4bits.RC5IE == 1 & PIR4bits.RC5IF == 1)
        {        
            PIR4bits.RC5IF = 0;
            rrxModBusRtu = RCREG5;
            RCREG5 = 0; 
        } 
#endif              
    }
    if (statusSaidaDadosSerial_1Eep == _MODBUS_RTU){interruptModBusRtu();}
    if (statusSaidaDadosSerial_1Eep == _PROTOCOLO_SA){serial_1RxInterruptProtocoloSa();}  
//interrup��o da grava��o de dados na Eepron									//	
//    saveEepronInterrupt();
}
