//////////////////////////////////////////////////////////////////////////////////		
//metodo que inicia a utilizacao da entrada externa do botao liga Desliga       //
//////////////////////////////////////////////////////////////////////////////////
extern UART_HandleTypeDef huart3;
void iniciaTeclaExterna (void)
{

}
//////////////////////////////////////////////////////////////////////////////////
//Funcoes de tratamento das teclas utilizadas                                   //
//////////////////////////////////////////////////////////////////////////////////			
void trataControleDasTeclas (void)
{
    if (((trataTeclaValidaIndicador == 1) || (teclaValidaPs2 == 1)) && teclaPressionada == 0 && exibeVersionControl == 0)
	{
        teclaPressionada = 1;
        trataTeclaValidaIndicador = 0;
//controle back light por tempo        
        if (statusLigaDesliga == _LIGADO && modoFuncionamentoBackLightMem == _BACKLIGHT_TEMPORIZADO)
        {
        	HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_SET);
            tempoSegundoBacklightLigado = 0;
            tempoBacklightLigado = 0;
			flagTempoExibeBackLight = 1;
        }
//teclas do menu principal disponiveis somente fora da programacao
        if (menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
           && menuCalibraIndicador == menuCalibraIndicadorEmEspera
           && menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
           && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera
           && menuProgramaDefinicaoFucionamento == menuDefinicaoFuncionamentoEmEspera
           && menuProgramacaoRelogioAtual == menuProgramaRelogioEmEspera)
        {
//verifica se liga ou desliga o indicador de peso      
            if (teclaPressionadaAtual == teclaLigaDesliga)
            {
                if (statusLigaDesliga == _DESLIGADO){metodoLigaSistema();}
                else{metodoDesligaSistema();}               
            }            
//acesso liberado somente com o indicador ligado
            if (statusLigaDesliga == _LIGADO)
            {

                if (teclasEditaProgramaAtualPs2 == teclaFuncao1)
                {
                    teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
                    // transmiteCargaCompleta = 0;
                    // transmiteSemFonte = 0;
                    // transmiteCarregando = 0;
                    // transmiteSemBateria = 0;
                    acessaMenuModoFuncionamentoLiguagem();
                }  
//////////////////////////////////////////////////////////////////////////////////		
//Verifica o acesso aos menus de programacao                          		 	//
//////////////////////////////////////////////////////////////////////////////////		
                if (menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera)
                {
                    if (teclaPressionadaAtual == teclaSalva){flagTempoAcessoMenuProgramacao = 1;} 
                }                            
// tecla zera peso indicador
                if (teclaPressionadaAtual == teclaZeroRetorna && controleTara == 0){fazZeroIndicadorPeso = 1;}  
// tecla tara peso indicador
                if (teclaPressionadaAtual == teclaTaraSetaEsquerda)
                {
//nao aceita tara quando indicador em zero
                    if (controleTara == _TARADESATIVADA)
                    {
                        if (indicadorEmZero != 1) 
                        {
                            controleTara = _TARAATIVADA;
                            fazTaraIndicadorPeso = 1;
                        }                       
                    }   
                    else
                    {
                        controleTara = _TARADESATIVADA;
                        valorTaraIndicador = valorZeroIndicador;
                    }
                }
            }                                     
        }
        else
        {
//Acesso ao Menu de calibracao do indicador
            if (menuCalibraIndicador != menuCalibraIndicadorEmEspera){controleCalibraIndicador();}
//acessa os menus de selecao dos menus de programacao
            if (menuAcessaMenusProgramacao != menuAcessaMenusProgramacaoEmEspera){funcaoAcessaMenusProgramacao();}
//acessa os menus de programacao da serial 1
            if (menuConfiguraSerial_1 != menuConfiguraSerial_1EmEspera){funcaoMenusConfiguraSerial_1();} 
//acessa os menus de programacao tecnica do indicador de peso
            if ( menuModoTecnicoIndicador != menuModoTecnicoIndicadorEmEspera){funcaoMenuModoTecnicoIndicador();}            
//acessa o menu de programacao das definicoes de funcionamento do indicador   
            if (menuProgramaDefinicaoFucionamento != menuDefinicaoFuncionamentoEmEspera){funcaoProgramaDefinicaoFuncionamento();}
//acessa o menu de programacao da hora e data
            if (menuProgramacaoRelogioAtual != menuProgramaRelogioEmEspera){funcaoProgramaHoraData();}
        }
    }
}	
//////////////////////////////////////////////////////////////////////////////////		
//metodo liga sistema                                                         	//
//////////////////////////////////////////////////////////////////////////////////		
void metodoLigaSistema(void)
{
    if (modoFuncionamentoBackLightMem != _BACKLIGHT_DESLIGADO) {
    	HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_SET);
    	backLightDwinMaximo();
    }
    if (modoFuncionamentoBackLightMem == _BACKLIGHT_DESLIGADO)
    {
    	HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_RESET);
    	backLightDwinMinimo();
    }
    statusLigaDesliga = _LIGADO;
    exibeVersionControl = 1;
    statusPowerOnMem = _LIGADO;
    carregaTela11();
    transfereCaracterDwinTelaInicial();  
    trocarPaginaDwin = 0;
//    preparaSalvaStatusPowerOn();
#ifdef displaySeteSegmentosLcd
    telaVersaoSeteSegmentos();
#endif
    fazTelaInicialPesoDwin = 0;
    fazTelaInicialSeteSegmento = 0;
    escreveDadoLcd(&telaInicialIndicador[0],&caracterLcd[0]);
    escreveDadoLcd(&telaInicialVersao[0],&caracterLcd[16]);
    controleTara = _TARADESATIVADA;
// o indicador sera zerado na inicializacao caso o peso esteja dentro do limite de zero
    if (statusZeroAoLigarMem == 1){fazZeroIndicadorPeso = 1;}
}
//////////////////////////////////////////////////////////////////////////////////		
//metodo desliga sistema                                                      	//
//////////////////////////////////////////////////////////////////////////////////		
void metodoDesligaSistema(void)
{
    carregaArrayComEspacoAscii(32,&caracterLcd[0]);
    HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_RESET);
    backLightDwinMinimo();
    statusLigaDesliga = _DESLIGADO;
    statusPowerOnMem = _DESLIGADO;
    carregaTela0();
//    preparaSalvaStatusPowerOn();
#ifdef displaySeteSegmentosLcd
    apagaLcdSeteSegmentos();
#endif
    controleTara = _TARADESATIVADA;
    tempoSegundoBacklightLigado = 0;
    tempoBacklightLigado = 0;
    flagTempoExibeBackLight = 0;
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que controla o tempo para liberar o acesso ao menu de programacao  	//
//////////////////////////////////////////////////////////////////////////////////		
void funcaoTempoAcessoMenuProgramacao(void)
{
    if (flagTempoAcessoMenuProgramacao == 1)
    {
		if (++tempoAcessoMenuProgramacao == 29)
		{
            tempoAcessoMenuProgramacao = 0;
            flagTempoAcessoMenuProgramacao = 0;
            teclaPressionada = 1;
            flagTempoValidaTeclaSolta = 0;
            tempoValidaTeclaSolta = 0;
//Acesso aos menus de programacao tecnica
            if (teclaPressionadaAtual == teclaSalva)
            {
                teclaPressionadaAtual = teclaSolta;
                telaAcessaMenuModoTecnicoIndicador();                   
            }
        }
	}
}
//////////////////////////////////////////////////////////////////////////////////		
//Funcao que controla o tempo de tecla solta                                  	//
// quando a tecla momoria 1 ou memoria 2 e solta antes do tempo para            //
// para acesso a programacao o acesso a programacao e cancelado e a momoria     //
//correspondente a tecla e ativada                                              //
//////////////////////////////////////////////////////////////////////////////////	
void tempoValidaTeclaQuandoSolta (void)
{
    if (flagTempoValidaTeclaSolta == 1)
    {
        if (++tempoValidaTeclaSolta == 130)
        {
            tempoValidaTeclaSolta = 0;
            flagTempoValidaTeclaSolta = 0;
            tempoAcessoMenuProgramacao = 0;
            flagTempoAcessoMenuProgramacao = 0;            
            if (menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
            && menuCalibraIndicador == menuCalibraIndicadorEmEspera
            && menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
            && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera)
            {
                if (flagSaidaMenuProgramacao == 1)
                {
                    flagSaidaMenuProgramacao = 0;
                }
                else
                {
//verifica se muda a tela de status principal

                }
            }
            else
            {
                flagSaidaMenuProgramacao = 1;                   
            }
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Metodo a tela de erro quando erro no limite de zero                         	//
//////////////////////////////////////////////////////////////////////////////////
void telaErroLimiteZero(void)
{    
    mostraTelaTemporariaLcd = 1;
    transfereArrayToArray(32,&caracterLcd[0],&backupTelaLcd[0]);
    
    if (linguagemSelecionadaMem == _PORTUGUES) {transfereConstToArray(&telaErroLimiteZeroLcdPT[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _INGLES) {transfereConstToArray(&telaErroLimiteZeroLcdING[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _ESPANHOL) {transfereConstToArray(&telaErroLimiteZeroLcdESP[0],&caracterLcd[0]);}
    
    transfereCaracterLcdLinha1Dwin();

#ifdef displaySeteSegmentosLcd
	transfereArrayToArray(6,&dadoLcdSetSegmentos[1],&backupDigitosLcdSeteSegmentos[0]);
	dadoLcdSetSegmentos[1] = 'E';
	dadoLcdSetSegmentos[2] = 'R';
	dadoLcdSetSegmentos[3] = 'R';
	dadoLcdSetSegmentos[4] = 'O';
	dadoLcdSetSegmentos[5] = 'R';
	dadoLcdSetSegmentos[6] = '1';
#endif
}
//////////////////////////////////////////////////////////////////////////////////		
//funcao de controle do tempo para apagar o backlight quando backlight amarelo	//
//////////////////////////////////////////////////////////////////////////////////		
void funcaoTempoBackLight(void)
{
    if (menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
    && menuCalibraIndicador == menuCalibraIndicadorEmEspera
    && menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
    && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera)  
    {
        if (flagTempoExibeBackLight == 1)
        {
            if (++tempoSegundoBacklightLigado == 60)
            {
                tempoSegundoBacklightLigado = 0;
                if (++tempoBacklightLigado == tempoDesligaBackLightMem)
                {
                    tempoBacklightLigado = 0;
                    flagTempoExibeBackLight = 0;
                    HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_RESET);
                }
            }
        }
	}
}
