//////////////////////////////////////////////////////////////////////////////////		
//              Fun�oes que controlam o salvamento da dados na eeprom     		//		
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//      Pilha salva dados eeprom                                        		//	
//////////////////////////////////////////////////////////////////////////////////
void pilhaSalvaDadosEeprom(void)
{
    if(iniciaSalvaDadosEeprom == 1)
    {
        pilhaEeprom.pausaSalvaDadosEeprom = 0;
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaPosicaoPontoDecimal == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaPosicaoPontoDecimal = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaPosicaoPontoDecimalIndicador();
//            controleEepronOcupada = 1;             
        }                 
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaValorFiltroDigital == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaValorFiltroDigital = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaValorFiltroDigitalEep();
//            controleEepronOcupada = 1;             
        } 
//////////////////////////////////////////////////////////////////////////////////             
       if(pilhaEeprom.salvaDegrauPeso == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaDegrauPeso = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaPosicaoDegralIndicador();
//            controleEepronOcupada = 1;             
        } 
//////////////////////////////////////////////////////////////////////////////////             
       if(pilhaEeprom.salvaPesoCapacidadeMaxima == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaPesoCapacidadeMaxima = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaPesoCapacidadeMaxIndicador();
//            controleEepronOcupada = 1;             
        }    
//////////////////////////////////////////////////////////////////////////////////             
      if(pilhaEeprom.salvaPesoCalibracao == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaPesoCalibracao = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaPesoCalibracaoIndicador();
//            controleEepronOcupada = 1;             
        }      
//////////////////////////////////////////////////////////////////////////////////             
      if(pilhaEeprom.salvaValorDivisaoInterna == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaValorDivisaoInterna = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaValorDivisaoIndicador();
//            controleEepronOcupada = 1;             
        }              
//////////////////////////////////////////////////////////////////////////////////             
      if(pilhaEeprom.salvaValorAdZero == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaValorAdZero = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaValorAdZeroIndicador();
//            controleEepronOcupada = 1;             
        }            
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaLimiteDeZero == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaLimiteDeZero = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaValorLimiteDeZeroEep();
//            controleEepronOcupada = 1; 
        }         
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaModoFuncionamentoBackLight == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaModoFuncionamentoBackLight = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaModoFuncionamentoBackLightEep();
//            controleEepronOcupada = 1; 
        } 
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaTempoBackLightLigado == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaTempoBackLightLigado = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaTempoDesligaBackLightEep();   
//          controleEepronOcupada = 1; 
        }          
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaConfiguraVelocidadeSerial_1 == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaConfiguraVelocidadeSerial_1 = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaVelocidadeTxSerial_1Eep();
            iniciaVariaveisTxSerial_1();         
//            controleEepronOcupada = 1; 
        }          
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaAtivaDesativaSerial_1 == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaAtivaDesativaSerial_1 = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaStatusFuncionamentoTxSerial_1Eep();             
//            controleEepronOcupada = 1; 
        }             
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaDefinePortaSerial_1 == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaDefinePortaSerial_1 = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaStatusSaidaPortaSerial_1Eep(); 
            iniciaVariaveisTxSerial_1();      
//            controleEepronOcupada = 1; 
        }       
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaSaidaDeDadosSerial_1 == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaSaidaDeDadosSerial_1 = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaStatusSaidaDadosSerial_1Eep();           
//            controleEepronOcupada = 1; 
        }               
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaEnderecoIndicadorSerial_1 == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaEnderecoIndicadorSerial_1 = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaEnderecoIndicadorEep();            
//            controleEepronOcupada = 1; 
        }  
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaQuantidadeFrameSegSerial_1  == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaQuantidadeFrameSegSerial_1 = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaQtFramePorSegundoEep();           
//            controleEepronOcupada = 1; 
        }    
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaTransmissaoAutomaticaSerial_1 == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaTransmissaoAutomaticaSerial_1 = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaStatusTransmisaoAutomaticoEep();           
//            controleEepronOcupada = 1; 
        }         
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaSaidaDeDadosSerial_2 == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaSaidaDeDadosSerial_2 = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaStatusSaidaDadosSerial_2Eep();           
//            controleEepronOcupada = 1; 
        }                   
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaStatusPowerOn  == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaStatusPowerOn  = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            preparaSalvaStatusPowerOn();
//            controleEepronOcupada = 1;  
        }  
//////////////////////////////////////////////////////////////////////////////////           
        if(pilhaEeprom.salvaModoZeroAoLigar == 1 & pilhaEeprom.pausaSalvaDadosEeprom  == 0)
        {
            pilhaEeprom.salvaModoZeroAoLigar  = 0;
            pilhaEeprom.pausaSalvaDadosEeprom  = 1;
            salvaStatusZeroPowerEep();
//            controleEepronOcupada = 1;  
        }             
//////////////////////////////////////////////////////////////////////////////////                   
        if(pilhaEeprom.pausaSalvaDadosEeprom ==0){iniciaSalvaDadosEeprom = 0;}
    }
}
