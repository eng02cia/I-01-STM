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
// telas de programacao
                                                 
// TELA PROG PORTUGUES
const char charTelaAcessaMenuModoTecnicoIndicadorPT[]=  {"MODO TECNICO    ""INDICADOR       "};
const char charTelaAcessaMenuConfiguraSerial_1PT[]=     {"CONFIGURA SERIAL""                "};
const char charTelaAcessaMenuFazCalibracaoPT[]=         {"CALIBRACAO      ""INDICADOR       "};
const char charTelaAcessaMenuProgRelogioPT[]=           {"DATA/HORA       ""                "};


// TELA PROG ESPANHOL
const char charTelaAcessaMenuModoTecnicoIndicadorESP[]= {"MODO TECNICO    ""INDICADOR       "};
const char charTelaAcessaMenuConfiguraSerial_1ESP[]=    {"CONFIGURAR SERIE""                "};
const char charTelaAcessaMenuFazCalibracaoESP[]=        {"CALIBRACION     ""INDICADOR       "};
const char charTelaAcessaMenuProgRelogioESP[]=          {"FECHA/HORA      ""                "};

// TELA PROG INGLES
const char charTelaAcessaMenuModoTecnicoIndicadorING[]= {"TECHNICAL MODE  ""INDICATOR       "};
const char charTelaAcessaMenuConfiguraSerial_1ING[]=    {"CONFIGURE SERIAL""                "};
const char charTelaAcessaMenuFazCalibracaoING[]=        {"CALIBRATION     ""INDICATOR       "};
const char charTelaAcessaMenuProgRelogioING[]= 	        {"DATE/TIME       ""                "};


//indica qual o menu atual que esta sendo programado
enum menuAcessaMenusProgramacao
{
    menuAcessaMenusProgramacaoEmEspera,
    acessaMenuModoTecnicoIndicador,     
    acessaMenuProgramaSerial_1,
    acessaMenuCalibracao,
    acessaMenuProgRelogio,
}menuAcessaMenusProgramacao = menuAcessaMenusProgramacaoEmEspera;

//flags utilizados na programacao

