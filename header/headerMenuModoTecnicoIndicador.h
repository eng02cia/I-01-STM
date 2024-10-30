//////////////////////////////////////////////////////////////////////////////////		
//hederes do menu de configura��o do indicador                                  //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de fun��o
void funcaoMenuModoTecnicoIndicador(void);
void telaMostraProgramacaoLimiteZero(void);
void telaValorFiltroDigitalModoTecnicoIndicador(void);
void telaMostraProgramacaoStatusZeroLigarIndicador(void);
void telaMostraProgramacaoModoFuncionamentoBackLight(void);
void telaTempoBackLightLigado(void);
//contantes utilizadas na fun��o                
// telas de programa�ao
                                                 

const char charTelaConfiguraLimiteZero[]=      {"LIMITE ZERO     ""                "};
const char charTelaModoPesagemIndicador[]=     {"ZERO POWER ON   ""                "};
//const char charTelaTempoCongelaPeso[]=         {"T/CONGELA PESO  ""                "};
//const char charTelaQtDivisoesCargaViva[]=      {"QT/DIVISOES CARG""A VIVA          "};
const char charTelaModoFuncBackLight[]=        {"MODO BACK LIGHT ""                "};
const char charTelaTempoBackLight[]=           {"TEMPO BACK LIGHT""                "};


const char charTelaAtivado[]=    {"ATIVADO"};
const char charTelaDesativado[]= {"DESATIVADO"};

const char charTelaLigado[]=           {"LIGADO"};
const char charTelaLigadoPorTempo[]=   {"LIGADO/TEMPO"};
const char charTelaDesligado[]=        {"DESLIGADO"};



static unsigned char tempConfigIndicador;


//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
//																							//
//FUNÇOES DISPLAY																			/
//																							//
//////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////
const char charTelaConfiguraLimiteZeroNextion[]=      {"LIMITE ZERO     "};
const char charTelaConfiguraLimiteZeroNextion2[]=      {"        "};

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
//flags utilizados na programa��o

