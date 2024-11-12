//////////////////////////////////////////////////////////////////////////////////		
//hederes do menu de configuracao do indicador                                  //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de funcao
void funcaoMenuModoTecnicoIndicador(void);
void telaMostraProgramacaoLimiteZero(void);
void telaValorFiltroDigitalModoTecnicoIndicador(void);
void telaMostraProgramacaoStatusZeroLigarIndicador(void);
void telaMostraProgramacaoModoFuncionamentoBackLight(void);
void telaTempoBackLightLigado(void);
//contantes utilizadas na funcao                
// telas de programa�ao
                                                 
// TELA PROG PORTUGUES
const char charTelaConfiguraLimiteZeroPT[]=      {"LIMITE ZERO     ""                "};
const char charTelaModoPesagemIndicadorPT[]=     {"ZERO POWER ON   ""                "};
const char charTelaModoFuncBackLightPT[]=        {"MODO BACK LIGHT ""                "};
const char charTelaTempoBackLightPT[]=           {"TEMPO BACK LIGHT""                "};
const char charTelaAtivadoPT[]=                  {"ATIVADO"};
const char charTelaDesativadoPT[]=               {"DESATIVADO"};
const char charTelaLigadoPT[]=                   {"LIGADO"};
const char charTelaLigadoPorTempoPT[]=           {"LIGADO/TEMPO"};
const char charTelaDesligadoPT[]=                {"DESLIGADO"};

// TELA PROG ESPANHOL
const char charTelaConfiguraLimiteZeroESP[]=        {"LIMITE CERO     ""                "};
const char charTelaModoPesagemIndicadorESP[]=       {"CERO POWER ON   ""                "};
const char charTelaModoFuncBackLightESP[]=          {"MODO LUZ D FONDO""                "};
const char charTelaTempoBackLightESP[]=             {"TIEMPO LUZ FONDO""                "};
const char charTelaAtivadoESP[]=                    {"ACTIVADO"};
const char charTelaDesativadoESP[]=                 {"DESACTIVADO"};
const char charTelaLigadoESP[]=                     {"ENCENDIDO"};
const char charTelaLigadoPorTempoESP[]=             {"TEMPORARIO"};
const char charTelaDesligadoESP[]=                  {"APAGADO"};

// TELA PROG INGLES
const char charTelaConfiguraLimiteZeroING[]=        {"ZERO LIMIT      ""                "};
const char charTelaModoPesagemIndicadorING[]=       {"ZERO POWER ON   ""                "};
const char charTelaModoFuncBackLightING[]=          {"BACKLIGHT MODE""                  "};
const char charTelaTempoBackLightING[]=             {"BACKLIGHT TIME""                  "};
const char charTelaAtivadoING[]=                    {"ENABLED"};
const char charTelaDesativadoING[]=                 {"DISABLED"};
const char charTelaLigadoING[]=                     {"ON"};
const char charTelaLigadoPorTempoING[]=             {"ON BY TIME"};
const char charTelaDesligadoING[]=                  {"OFF"};



static unsigned char tempConfigIndicador;


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//																							//
//FUNÇOES DISPLAY																			/
//																							//
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
const char charTelaConfiguraLimiteZeroPTNextion[]=      {"LIMITE ZERO     "};
const char charTelaConfiguraLimiteZeroPTNextion2[]=      {"        "};

const char charTelaConfigurTempoBackLightNextion[]=      {"        "};


const char linha0MenuTecnico[]=      {"t4.txt=\""};
const char linha1MenuTecnico[]=      {"t5.txt=\""};






//indica qual o menu atual que esta sendo programado
enum menuModoTecnicoIndicador
{
    menuModoTecnicoIndicadorEmEspera,
    defineLimiteDeZero,
    defineFiltroDigital, 
    defineZeroAoLigar,
    defineModoFuncionamentoBackLight,
    defineTempoDesligaBackLight, 
}menuModoTecnicoIndicador = menuModoTecnicoIndicadorEmEspera;

#define _CARGAVIVA 1
#define _LIMITE_ZERO_MAXIMO 6
#define _limiteProgLimiteDeZero 5
#define _limiteProgValorFiltroDigital 20
#define _limiteStatusProgramacaoZeroAoLigar 1
//flags utilizados na programacao

