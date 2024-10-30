//////////////////////////////////////////////////////////////////////////////////		
//                                                                           	//
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de fun��es
void pilhaSalvaDadosEeprom(void);

//variaveis
static unsigned char  iniciaSalvaDadosEeprom;
//static unsigned char  controleEepronOcupada;

struct
{
//menu calibra indicador
    unsigned salvaPosicaoPontoDecimal:1;
    unsigned salvaValorFiltroDigital:1;
    unsigned salvaDegrauPeso:1;
    unsigned salvaPesoCapacidadeMaxima:1;
    unsigned salvaPesoCalibracao:1;
    unsigned salvaValorDivisaoInterna:1; 
    unsigned salvaValorAdZero:1;    
//menu modo tecnico indicador
    unsigned salvaLimiteDeZero:1;
    unsigned salvaModoFuncionamentoBackLight:1;
    unsigned salvaTempoBackLightLigado:1;
    unsigned salvaModoZeroAoLigar:1;
//menu configura serial 1
    unsigned salvaConfiguraVelocidadeSerial_1:1;
    unsigned salvaAtivaDesativaSerial_1:1;
    unsigned salvaDefinePortaSerial_1:1;
    unsigned salvaSaidaDeDadosSerial_1:1;
    unsigned salvaTransmissaoAutomaticaSerial_1:1;
    unsigned salvaEnderecoIndicadorSerial_1:1;
    unsigned salvaQuantidadeFrameSegSerial_1:1;
    unsigned salvaSaidaDeDadosSerial_2:1;
//operacao indicador    
    unsigned salvaStatusPowerOn:1;
    unsigned pausaSalvaDadosEeprom:1;
}pilhaEeprom;
// constantes

#define pilhaEepromAtiva
