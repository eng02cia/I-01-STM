//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//              funcoes de Escrita e gravacao an eeprom	                  		//
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

#define endStatusComunicacaoSerial1Mem			0
#define endVelocidadeTxSerial1Mem				1
#define	endStatusPortaSerial1Mem				2
#define endStatusSaidaDadosSerial1Mem			3
#define	endStatusSaidaDadosSerial2Mem			4
#define endEnderecoIndicadorMem					5
#define endQtFramePorSegundoMem					6
#define endStatusPowerOnMem						7
#define endModoFuncionamentoBacklightMem		8
#define endTempoDesligaBacklightMem				9
#define endStatusZeroAoLigarMem					10
#define endValorLimiteDeZeroMem					11
#define endValorFiltroDigitalMem				12
#define endPosicaoPontoDecimalIndicadorMem		13
#define endDegrauIndicadorMem					14
#define endStatusTransmiteAutomaticoMem			15 // 2 bytes
#define endCapacidadeMaximaIndicadorMem			17 // 8 bytes
#define endPesoCalibracaoIndicadorMem			25 // 8 bytes
#define endValorZeroIndicadorMem				33 // 4 bytes
#define endValorDivisaoIndicadorMem				37 // 4 bytes
#define endNomeTelaIniciallMem					41 // 16 bytes
#define endlinguagemSelecionadaMem				57 // 1 byte
#define endExibeRelogioMem						58 // 1 byte

const char defaultEeprom[] = 
{
/* 00 */	_SERIAL_1ATIVADA,
/* 01 */	velocidade9600Kbps,
/* 02 */	_RS485,
/* 03 */	_MODBUS_RTU,
/* 04 */	_TRANSMISSAOCONTINUA_1,
/* 05 */	1,
/* 06 */	4,
/* 07 */	_LIGADO,
/* 08 */	_BACKLIGHT_TEMPORIZADO,
/* 09 */	3,
/* 10 */	_DESLIGADO,
/* 11 */	2,
/* 12 */	2,
/* 13 */	0,
/* 14 */	1,
/* 15 */	2,4,															 
/* 17 */	'0','0','0','2','0','0','0','0', 								
/* 25 */	'0','0','0','0','0','0','0','0', 								
/* 33 */	' ',' ',' ',' ', 												
/* 37 */	' ',' ',' ',' ',													
/* 41 */	'I','N','D','I','C','A','D','O','R',' ','I','-','0','1',' ',' ',
/* 57 */	_PORTUGUES,
/* 58 */	_EXIBE_RELOGIO_DESABILITADO,
/* 59 */	' ',' ',' ',' ',1,																													
};

//////////////////////////////////////////////////////////////////////////////////		
//prototipos de funcao utilizados												//
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
void salvaExibeRelogioMem(void);
void salvaPosicaoPontoDecimalIndicadorMem(void);
void salvaStatusSaidaPortaSerial_1Mem(void);
void salvaValorDivisaoIndicadorMem(void);

//////////////////////////////////////////////////////////////////////////////////		
//declaracao de variaveis utilziadas nesta funcao								//
//////////////////////////////////////////////////////////////////////////////////		
static unsigned char statusComunicacaoSerial_1Mem;
static unsigned char velocidadeTxSerial_1Mem;
static unsigned char statusPortaSerial_1Mem;
static unsigned char statusSaidaDadosSerial_1Mem;
static unsigned char statusSaidaDadosSerial_2Mem;
static unsigned char enderecoIndicadorMem;
static unsigned char qtFramePorSegundoMem;
static unsigned char statusTransmiteAutomaticoMem[2];
//static unsigned char modoPesagemIndicadorMem = 0;
static unsigned char statusPowerOnMem;
static unsigned char statusZeroAoLigarMem;
static unsigned char statusLigaDesliga;
//static unsigned char valorDivisaoCargaVivaMem;
//variaveis referente as funcoes do indicador de peso
static unsigned char valorLimiteDeZeroMem;//porcentagem
//static unsigned char valorZeroMilPorcentoMem;// 0.1 porcento
static unsigned char valorFiltroDigitalMem;
static unsigned char posicaoPontoDecimalIndicadorMem;
static unsigned char degrauIndicadorMem;
static unsigned char capacidadeMaximaIndicadorMem[8];
static unsigned char pesoCalibracaoIndicadorMem[8];
static unsigned char modoFuncionamentoBackLightMem;
static unsigned char tempoDesligaBackLightMem;
static unsigned char nomeTelaIndicadorMem[16];
static unsigned char linguagemSelecionadaMem;
static unsigned char exibeRelogioMem;

union{
     char array4[4]; 
     float float32;   
}valorDivisaoIndicadorMem;
union{
     char array4[4]; 
     int32_t int32;   
}valorZeroIndicadorMem;

//dadosBateladasMem[16] armazena dados sobre as bateladas ate o momento
//de 0 a 8 peso acumulado das bateladas
//de 9 a 16 quantidade de bateladas executadas ate o momento
//static unsigned char dadosBateladasMem[16];
//static unsigned char tempArrayMem[16];
//static unsigned char arrayDadoEeprom[16];
//static unsigned char dataEeprom;
//static unsigned char endEeprom;
//static unsigned char loopApagaMemoria;
//static unsigned char quantidadeByteEeprom;
//static unsigned char indexMem;
//static unsigned char  iniciaSalvaDadosEeprom;
//static unsigned char  controleEepronOcupada;
//static unsigned char bytesDataEepron[10];
//static unsigned char posicaoEpromDadosBatelada;
//unsigned char RloopReadEeprom;
unsigned char tempMem;
//short flagSalvaByteEepron;
//short flagApagaMemoria;
//endereco memoria eeprom
union
{
	struct
	{
        uint8_t endL:8;
        uint8_t endH:8;
	}end8Bits;
    uint16_t end16Bits;
}endEeprom;
