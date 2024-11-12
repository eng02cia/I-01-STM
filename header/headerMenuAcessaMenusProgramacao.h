//////////////////////////////////////////////////////////////////////////////////		
//hederes do menu de acesso a programacao do sistema                            //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de funcao
void funcaoAcessaMenusProgramacao(void);
void telaAcessaMenuModoTecnicoCorte(void);
void telaAcessaMenuModoTecnicoIndicador(void);
void telaAcessaMenuConfiguraSerial_1(void);
void telaAcessaMenuFazCalibracao(void);
void telaAcessaMenuTesteDasSaidas(void);
//contantes utilizadas na funcao                
// telas de programa�ao
                                                 
// TELA PROG PORTUGUES
const char charTelaAcessaMenuModoTecnicoIndicadorPT[]={"MODO TECNICO    ""INDICADOR       "};
const char charTelaAcessaMenuConfiguraSerial_1PT[]=   {"CONFIGURA SERIAL""                "};
const char charTelaAcessaMenuFazCalibracaoPT[]=       {"CALIBRACAO      ""INDICADOR       "};

// TELA PROG ESPANHOL
const char charTelaAcessaMenuModoTecnicoIndicadorESP[]={"MODO TECNICO    ""INDICADOR       "};
const char charTelaAcessaMenuConfiguraSerial_1ESP[]=   {"CONFIGURAR SERIE""                "};
const char charTelaAcessaMenuFazCalibracaoESP[]=       {"CALIBRACION     ""INDICADOR       "};

// TELA PROG INGLES
const char charTelaAcessaMenuModoTecnicoIndicadorING[]={"TECHNICAL MODE  ""INDICATOR       "};
const char charTelaAcessaMenuConfiguraSerial_1ING[]=   {"CONFIGURE SERIAL""                "};
const char charTelaAcessaMenuFazCalibracaoING[]=       {"CALIBRATION     ""INDICATOR       "};

// const char linha0NextionModoTecnico[]={"t11.txt=\"MODO TECNICO\""};
// const char linha1NextionModoTecnico[]={"t12.txt=\"INDICADOR\""};

// const char linha0NextionConfiguraSerial[]={"t6.txt=\"CONFIGURA SERIAL\""};
// const char linha1NextionConfiguraSerial[]={"t7.txt=\"\""};

// const char linha0NextionCalibracaoIndicador[]={"t8.txt=\"CALIBRACAO\""};
// const char linha1NextionCalibracaoIndicador[]={"t9.txt=\"INDICADOR\""};

// const char trocaPagina0[]={"page 0"};
// const char trocaPagina1[]={"page 1"};
// const char trocaPagina2[]={"page 2"};
// const char trocaPagina3[]={"page 3"};
// const char trocaPagina4[]={"page 4"};
// const char trocaPagina5[]={"page 5"};


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

//flags utilizados na programacao

