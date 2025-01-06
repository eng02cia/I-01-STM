//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//               Header de escrita de dados no display lcd de sete segmentos     //
//////////////////////////////////////////////////////////////////////////////////			
//////////////////////////////////////////////////////////////////////////////////		
//prototipos de funcao utilizados												//
//////////////////////////////////////////////////////////////////////////////////
void telaVersaoSeteSegmentos(void);
void telaSubCargaSeteSegmentos(void);
void telaSobreCargaSeteSegmentos(void);
void telaAguardeSeteSegmentos(void);
void telaMostraDadoLcdSeteSegmentos(void);
void telaSemCelulaCargaSeteSegmentos(void);
void telaPesoCalibracaoSeteSegmentos (void);
void telaCapacidadeMaximaSeteSegmentos (void);
void telaSemPesoSeteSegmentos (void);
void telaComPesoSeteSegmentos (void);
void telaConfigSerialSeteSegmentos (void);
void telaAcessaMenuModoTecnicoSeteSegmentos (void);
void telaAcessaMenuCalibracaoSeteSegmentos (void);
void telaConfLimiteZeroSeteSegmentos (void);
void telaValorFiltroDigitalSeteSegmentos (void);
void telaMostraStatusZeroLigarSeteSegmentos (void);
void telaMostraFuncionamentoBackLightSeteSegmentos (void);
void telaTempoBackLightSeteSegmentos (void);
void telaMostraSelecionaIdiomaSeteSegmentos (void);
void telaMostraNaoSeAplicaSeteSegmentos (void);
void telaSenhaSeteSegmentos (void);
void telaPosicaoPontoSeteSegmentos (void);
void telaDefineDegrauPesoSeteSegmentos (void);
void telaAguardeCalibracaoSeteSegmentos (void);
void telaMostraProgVelSerial_1SeteSegmentos (void);
void telaMostraAtivDesativSerial_1SeteSegmentos (void);
void telaMostraTipoPortaSerial_1SeteSegmentos (void);
void telaMostraTipoSaidaSerial_1SeteSegmentos (void);
void telaMostraTipoSaidaSerial_2SeteSegmentos (void);
void telaMostraenderecoIndicadorSeteSegmentos (void);
void telaMostraQtFramePorSegundoSeteSegmentos (void);
void telaAcessaConfiguraRelogioSeteSegmentos (void);
void telaMostraProgExibeRelogioSeteSegmentos (void);
void telaMostraProgHoraDataSeteSegmentos (void);
void telaMostraHoraSeteSegmentos (void);
void telaZeroOkCalibracaoSeteSegmentos (void);
void telaCertoCalibracaoSeteSegmentos (void);



unsigned char *digitosDspTemp;
unsigned char *displayPesoTemp;
static unsigned char loopConverteTelaLcd;
static unsigned char asciiTelaDisplaySeteSegmentos;
