//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//              Fun��es de Escrita e grava��o an eeprom	                  		//
//                                                                            	//
//                        	Desenvolvido por   		                           	//
//                                                                           	//
//  			    		Clodoaldo Flugel			                       	//
//                                                                            	//
//               Inicio em 26/06/07 as 17:40 hs                               	//
//           Parado em    /  /   as   :   hs                                  	//
//           Reiniciado em   /  /   as   :   hs					    	   		//
//                                                                            	//
//									 									       	//			
//////////////////////////////////////////////////////////////////////////////////

const char defaultEeprom[] = {1,4,0,2,0,1,4,1,//7
							  2,3,0,2,2,0,1,' ',//15
							  2,4,' ',' ',' ',' ',' ',' ',//23
							  '0','0','0','1','0','0','0','0',//31
							  '0','0','0','0','1','0','0','0',//39
							  0xC8,0xE6,0x0F,0x4A,0x17,0x39,0x59,0x44,//47
							  ' ',' ',' ',' ',' ',0,' ',' ',//55
							  ' ',' ',' ',' ',' ',' ',' ',1,//63
							 };

//////////////////////////////////////////////////////////////////////////////////		
//prototipos de fun��o utilizados												//
//////////////////////////////////////////////////////////////////////////////////		
void inicializaDadosEeprom(void);
void funcaoQtBytesSalvaEeprom(void);
void salvaDataEeprom(void);
void leDadosEeeprom(void);
int leUmByteEeprom (void);
void saveEepronInterrupt(void);

void readConfigIndicadorEep(void);
void readPosicaoPontoDecimalIndicador(void);   
void readPosicaoDegrauIndicador(void);
void readPesoCapacidadeMaxIndicador(void);
void readPesoCalibracaoIndicador(void);
void readValorAdZeroIndicador(void);
void readValorDivisaoIndicador(void);
void readValorFiltroDigitalEep(void);
void readValorLimiteDeZeroIndicador(void);
void readStatusTransmissaoSerial_1(void);
void readValorFiltroDigitalEep(void);

void salvaStatusFuncionamentoTxSerial_1Mem(void);
void salvaVelocidadeTxSerial_1Eep(void);
void salvaStatusSaidaPortaSerial_1Eep(void);
void salvaTempoCongelaPesoCargaVivaEep(void);
void salvaPesoCapacidadeMaxIndicadorMem(void);
void salvaPosicaoDegrauIndicadorMem(void);
void salvaPesoCalibracaoIndicadorMem(void);
void salvaValorAdZeroIndicadorMem(void);
void salvaValorFiltroDigitalMem(void);
void salvaValorLimiteDeZeroMem(void);
void salvaEnderecoIndicadorMem(void);
void salvaStatusSaidaDadosSerial_1Mem(void);
void salvaStatusSaidaDadosSerial_2Mem(void);
void salvaStatusTransmisaoAutomaticoMem(void);
void salvaQtFramePorSegundoMem(void);
void salvaQtDivisoesCargaVivaMem(void);
void salvaModoFuncionamentoBackLightMem(void);
void salvaTempoDesligaBackLightMem(void);
void salvaStatusZeroPowerMem(void);
//////////////////////////////////////////////////////////////////////////////////		
//declara��o de variaveis utilziadas nesta fun��o								//
//////////////////////////////////////////////////////////////////////////////////		
static unsigned char statusComunicacaoSerial_1Mem;
static unsigned char velocidadeTxSerial_1Mem;
static unsigned char statusPortaSerial_1Mem;
static unsigned char statusSaidaDadosSerial_1Mem;
static unsigned char statusSaidaDadosSerial_2Mem;
static unsigned char enderecoIndicadorMem;
static unsigned char qtFramePorSegundoMem;
static unsigned char statusTransmiteAutomaticoMem[2];
static unsigned char modoPesagemIndicadorMem = 0;
static unsigned char statusPowerOnMem;
static unsigned char statusZeroAoLigarMem;
static unsigned char statusLigaDesliga;
//static unsigned char valorDivisaoCargaVivaMem;
//variaveis referente as fun�oes do indicador de peso
static unsigned char valorLimiteDeZeroMem;//porcentagem
static unsigned char valorZeroMilPorcentoMem;// 0.1 porcento
static unsigned char valorFiltroDigitalMem;
static unsigned char posicaoPontoDecimalIndicadorMem;
static unsigned char degrauIndicadorMem;
static unsigned char capacidadeMaximaIndicadorMem[8];
static unsigned char pesoCalibracaoIndicadorMem[8];
static unsigned char modoFuncionamentoBackLightMem;
static unsigned char tempoDesligaBackLightMem;

//controle da velocidade comunica��o
//enum 
//{
//    velocidade1200Kbps,
//    velocidade2400Kbps,
//    velocidade4800Kbps,
//    velocidade9600Kbps,
//    velocidade19200Kbps,   
//}velocidadeTxSerial_1Mem
union{
     char array4[4]; 
     float float32;   
}valorDivisaoIndicadorMem;
union{
     char array4[4]; 
     float int32;   
}valorZeroIndicadorMem;

//dadosBateladasMem[16] armazena dados sobre as bateladas ate o momento
//de 0 a 8 peso acumulado das bateladas
//de 9 a 16 quantidade de bateladas executadas ate o momento
//static unsigned char dadosBateladasMem[16];
//static unsigned char tempArrayMem[16];
static unsigned char arrayDadoEeprom[16];
static unsigned char dataEeprom;
//static unsigned char endEeprom;
//static unsigned char loopApagaMemoria;
static unsigned char quantidadeByteEeprom;
static unsigned char indexMem;
//static unsigned char  iniciaSalvaDadosEeprom;
//static unsigned char  controleEepronOcupada;
//static unsigned char bytesDataEepron[10];
static unsigned char posicaoEpromDadosBatelada;
//unsigned char RloopReadEeprom;
unsigned char tempMem;
//short flagSalvaByteEepron;
//short flagApagaMemoria;
//endere�o memoria eeprom
union
{
	struct
	{
        unsigned char endL:8;
        unsigned char endH:8;
	}end8Bits;
    unsigned int end16Bits;
}endEeprom;
