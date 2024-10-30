//////////////////////////////////////////////////////////////////////////////////		
//hederes do menu de acesso a programa��o do sistema                            //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de fun��o
void funcaoAcessaMenusProgramacao(void);
void telaAcessaMenuModoTecnicoCorte(void);
void telaAcessaMenuModoTecnicoIndicador(void);
void telaAcessaMenuConfiguraSerial_1(void);
void telaAcessaMenuFazCalibracao(void);
void telaAcessaMenuTesteDasSaidas(void);
//contantes utilizadas na fun��o                
// telas de programa�ao
                                                 
const char charTelaAcessaMenuModoTecnicoCorte[]=    {"MODO TECNICO    ""CORTE           "};
const char charTelaAcessaMenuModoTecnicoIndicador[]={"MODO TECNICO    ""INDICADOR       "};
const char charTelaAcessaMenuConfiguraSerial_1[]=   {"CONFIGURA SERIAL""                "};
const char charTelaAcessaMenuFazCalibracao[]=       {"CALIBRACAO      ""INDICADOR       "};
const char charTelaAcessaMenuTesteDasSaidas[]=      {"TESTA SAIDAS    ""                "};


const char linha0NextionModoTecnico[]={"t11.txt=\"MODO TECNICO\""};
const char linha1NextionModoTecnico[]={"t12.txt=\"INDICADOR\""};

const char linha0NextionConfiguraSerial[]={"t6.txt=\"CONFIGURA SERIAL\""};
const char linha1NextionConfiguraSerial[]={"t7.txt=\"\""};

const char linha0NextionCalibracaoIndicador[]={"t8.txt=\"CALIBRACAO\""};
const char linha1NextionCalibracaoIndicador[]={"t9.txt=\"INDICADOR\""};

const char trocaPagina0[]={"page 0"};
const char trocaPagina1[]={"page 1"};
const char trocaPagina2[]={"page 2"};
const char trocaPagina3[]={"page 3"};
const char trocaPagina4[]={"page 4"};
const char trocaPagina5[]={"page 5"};


const char linha0e1NextionModoTecnico[]={};
unsigned char tempQtBytes;
unsigned char tempTxQtBytes;




//indica qual o menu atual que esta sendo programado
enum menuAcessaMenusProgramacao
{
    menuAcessaMenusProgramacaoEmEspera,
    acessaMenuModoTecnicoIndicador,     
    acessaMenuProgramaSerial_1,
    acessaMenuCalibracao,
}menuAcessaMenusProgramacao = menuAcessaMenusProgramacaoEmEspera;

//flags utilizados na programa��o

