//////////////////////////////////////////////////////////////////////////////////		
//hederes do menu de acesso a programa��o do sistema                            //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de fun��o
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
//contantes utilizadas na fun��o                
// telas de programa�ao


// PRIMEIRAMENTE TESTANDO APENAS COM MUDANCA DE TELA INICIAL
// 		Tambem devera contemplar escolha de idioma e ajuste de relogio
const char charTelaDefineTelaInicial[]=                     {"TELA INICIAL                    "};



const char charVersaoIcv01[]=    {"VERSAO ICV-01"};
const char charVersaoIcv02[]=    {"VERSAO ICV-03"};
const char charErroSenhaWifi[]= {"NO MINIMO 8 CARACTERES"};
const char charModo_1[]= {"FONTE 9V"};
const char charModo_2[]= {"FONTE 9 A 15V"};
const char charDesativ[]={"DESATIVA"};
const char charAtiv[]={"ATIVA"};
const char charBovina[]={"BOVINA"};
const char charAvicula[]={"AVICULA"};
const char charMonoConect[]={"MONO CONECT"};
const char charMultConect[]={"MULT CONECT"};

const char charUmaCalibracao[]={"UMA CALIBRACAO"};
const char charDuasCalibracao[]={"DUAS CALIBRACAO"};

//variaveis utilizadas
static unsigned char nomeProgTemp[16];
static unsigned char tempConfigModoFuncionamento;
static unsigned char posicaoDigitoControleCadastro;
//indica qual o menu atual que esta sendo programado
enum menuProgramaDefinicaoFucionamento
{
	defineModoFuncionamentoPesagem,
	defineModoFuncionamentoSupervisaoBateria,
	defineVersaoFuncionamentoICV,
	defineMultiBalanca,
	defineModoFuncionamentoWifi,
	defineNomeRedeWifi,
	defineSenhaRedeWifi,
	defineModoFuncionamentoBluetooth,
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

