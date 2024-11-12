//////////////////////////////////////////////////////////////////////////////////		
//hederes do menu de acesso a programacao do sistema                            //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de funcao
void funcaoProgramaDefinicaoFuncionamento(void);
void programaNomeTelaInicial(void);
int programaLetraDoNome(unsigned char letraTemp);
void controlaProgPiscaNomeTela(void);

void acessaMenuProgramaModoFuncionamentoSerial_1(void);
void acessaMenuModoFuncionamentoSupervisaoBateria(void);
void acessaMenuEscolheVersaoIcv(void);
void acessaMenuModoFuncionamentoWifi(void);
void acessaMenuModoFuncionamentoDpCalibracao(void);
void acessaMenuModoFuncionamentoBluetooth(void);
void acessaMenuProgramaNomeRedeWifi(void);
void acessaMenuProgramaSenhaWifi(void);
void acessaMenuProgramaNomeTelaInicial(void);
void digita16CaracteresAscii(void);
void telaMostraProgModoFuncionamentoPesagem(void);
void telaMostraAtivaDesativaSupervisaoBateria(void);
void telaMostraEscolheVersaoIcv(void);
void telaMostraEscolheDuplaCalibracao(void);
void telaMostraAtivaDesativaWifi(void);
void telaMostraAtivaDesativaBluetooth(void);
void telaMostraProgNomeAcii(void);
void telaMostraSelecionaLinguagem(void);
//contantes utilizadas na funcao                
// telas de programa�ao


// PRIMEIRAMENTE TESTANDO APENAS COM MUDANCA DE TELA INICIAL
// 	Tambem devera contemplar escolha de idioma e ajuste de relogio
// TELA PROG PORTUGUES
const char charTelaDefineTelaInicialPT[]=				{"TELA INICIAL                   "};
// TELA PROG ESPANHOL
const char charTelaDefineTelaInicialESP[]=				{"PANTALLA DE INICIO             "};
// TELA PROG INGLES
const char charTelaDefineTelaInicialING[]=				{"HOME SCREEN                    "};

const char charTelaSelecionaLinguagemPT[]=				{"ESCOLHER IDIOMA ""               "};
const char charTelaSelecionaLinguagemESP[]=				{"ELEGIR IDIOMA   ""               "};
const char charTelaSelecionaLinguagemING[]=				{"CHOOSE LANGUAGE ""               "};

const char charTelaPortugues[]=        				{"PORTUGUES      "};
const char charTelaEspanhol[]=        			    {"ESPANHOL       "};
const char charTelaIngles[]=        				{"ENGLISH        "};

// const char charUmaCalibracao[]={"UMA CALIBRACAO"};
// const char charDuasCalibracao[]={"DUAS CALIBRACAO"};

//variaveis utilizadas
static unsigned char nomeProgTemp[16];
static unsigned char tempConfigModoFuncionamento;
static unsigned char posicaoDigitoControleCadastro;
//indica qual o menu atual que esta sendo programado
enum menuProgramaDefinicaoFucionamento
{
	defineSelecionaLinguagem,
	defineNomeTelaPrincipal,
	menuDefinicaoFuncionamentoEmEspera,
}menuProgramaDefinicaoFucionamento = menuDefinicaoFuncionamentoEmEspera;


#define _INDICADOR_VERSAO_01 0
#define _INDICADOR_VERSAO_02 1

#define _desativado 0
#define _ativado 1
#define bluetoothDesativado 0
#define modeloModuloHc05    1
#define modeloModulobt836   2
#define _modo_1 1
#define _modo_2 2

#define _displayGrafico 2
#define _txContinua 1
#define _bovina 0
#define _avicula 1

