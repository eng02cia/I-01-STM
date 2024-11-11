/*
 * includes.h
 *
 *  Created on: 26 de ago de 2022
 *      Author: Micro
 */

#ifndef INC_INCLUDES_H_
#define INC_INCLUDES_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "transfereConstToArray.h"
uint8_t cmd_end[3] ={0xFF, 0xFF, 0xFF};
uint8_t Rx_ModbusSerial_1[10];
#include "headerPilhaSaveEeprom.h"
#include "headerControleTask.h"
#include "headerControlaTelas.h"
#include "headerControleDasTeclas.h"
#include "headerEscritaLcd.h"
#include "headerTxSerial_1_1_5_2.h"
#include "headerTxSerial_2.h"
#include "headerCalibracaoIndicador.h"
#include "headerHx711.h"
#include "headerControleCelulaCarga.h"
#include "headerControleBackLight.h"
#include "headerChecaAutorizaZeroIndicador.h"
#include "headerFazZeroIndicador.h"
#include "headerFazMediaAdCalibraIndicador.h"
#include "headerMenuAcessaMenusProgramacao.h"
#include "headerMenuConfiguraSerial.h"
#include "headerMenuModoTecnicoIndicador.h"
#include "headerModBusRtu.h"
#include "headerTrataModBusRtu.h"
#include "headerProtocoloSASigmaciaSerial_1.h"
#include "headerDecodificaTecladoIndicador_I01.h"
#include "headerDisplayNextion.h"
#include "headerfuncaoI2c.h"
#include "headerDisplayDwin.h"
#include "headerTecladoPs2.h"
#include "headerMenuDefinicaoFuncionamento.h"
#include "headerEeprom.h"
#include "headeri2c.h"
#include "headerProgRelogio.h"


#include "i2c.h"
#include "menuProgRelogio.h"
#include "DWIN.h"
#include "tecladoPs2.h"
#include "controleTask.h"
#include "escritaLcd.h"
#include "funcaoI2c.h"
#include "funcaoDisplayNextion.h"
#include "controlaTelas.h"
#include "controleDasTeclas.h"
#include "calibracaoIndicador.h"
#include "controleCelulaCarga.h"
#include "controleBackLight.h"
#include "hx711.h"
#include "checaAutorizaZeroIndicador.h"
#include "fazZeroIndicador.h"
#include "fazMediaAdCalibraIndicador.h"
#include "funcoesTxSerial_1_1_5_2.h"
#include "txSerial_2.h"
#include "acessaMenusProgramacao.h"
#include "menuConfiguraSerial.h"
#include "menuModoTecnicoIndicador.h"
#include "modBusRtu.h"
#include "trataModBusRtu.h"
//#include "protocoloSASigmaciaSerial_1.h"
#include "decodificaTecladoIndicador_I01.h"
#include "eepromRead.h"
#include "eepromSave.h"
#include "funcaoDwin.h"
#include "menuDefinicaoFuncionamento.h"

#endif /* INC_INCLUDES_H_ */
