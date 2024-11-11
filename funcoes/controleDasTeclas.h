//////////////////////////////////////////////////////////////////////////////////		
//metodo que inicia a utilização da entrada externa do botão liga Desliga       //
//////////////////////////////////////////////////////////////////////////////////
extern UART_HandleTypeDef huart3;
void iniciaTeclaExterna (void)
{

}
//////////////////////////////////////////////////////////////////////////////////
//Funções de tratamento das teclas utilizadas                                   //
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
//teclas do menu principal disponiveis somente fora da programação
        if (menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
           && menuCalibraIndicador == menuCalibraIndicadorEmEspera
           && menuConfiguraSerial_1 == menuConfiguraSerial_1EmEspera
           && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera
           && menuProgramaDefinicaoFucionamento == menuDefinicaoFuncionamentoEmEspera)
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

                if(teclasEditaProgramaAtualPs2 == teclaFuncao1)
                {
                    teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
                    // transmiteCargaCompleta = 0;
                    // transmiteSemFonte = 0;
                    // transmiteCarregando = 0;
                    // transmiteSemBateria = 0;
                    acessaMenuProgramaNomeTelaInicial();
                }  
//////////////////////////////////////////////////////////////////////////////////		
//Verifica o acesso aos menus de programação                          		 	//
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
//não aceita tara quando indicador em zero
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
//Acesso ao Menu de calibração do indicador
            if (menuCalibraIndicador != menuCalibraIndicadorEmEspera){controleCalibraIndicador();}
//acessa os menus de seleção dos menus de programação
            if (menuAcessaMenusProgramacao != menuAcessaMenusProgramacaoEmEspera){funcaoAcessaMenusProgramacao();}
//acessa os menus de programação da serial 1
            if (menuConfiguraSerial_1 != menuConfiguraSerial_1EmEspera){funcaoMenusConfiguraSerial_1();} 
//acessa os menus de programação tecnica do indicador de peso
            if ( menuModoTecnicoIndicador != menuModoTecnicoIndicadorEmEspera){funcaoMenuModoTecnicoIndicador();}            
//acessa o menu de programacao das definicoes de funcionamento do indicador   
            if(menuProgramaDefinicaoFucionamento != menuDefinicaoFuncionamentoEmEspera){funcaoProgramaDefinicaoFuncionamento();}
        }
    }
}	
//////////////////////////////////////////////////////////////////////////////////		
//metodo liga sistema                                                         	//
//////////////////////////////////////////////////////////////////////////////////		
void metodoLigaSistema(void)
{
    if (modoFuncionamentoBackLightMem == _BACKLIGHT_DESLIGADO){HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_SET);}
    statusLigaDesliga = _LIGADO;
    exibeVersionControl = 1;
    statusPowerOnMem = _LIGADO;
    trocarPaginaPeso = 1;
    carregaTela11();
    transfereCaracterDwinTelaInicial();  
    fazTelaInicialPesoDwin = 0;
    trocarPaginaDwin = 0;
//    preparaSalvaStatusPowerOn();
    escreveDadoLcd(&telaInicialIndicador[0],&caracterLcd[0]);
    controleTara = _TARADESATIVADA;
// o indicador sera zerado na inicialização caso o peso esteja dentro do limite de zero
    if (statusZeroAoLigarMem == 1){fazZeroIndicadorPeso = 1;}
}
//////////////////////////////////////////////////////////////////////////////////		
//metodo desliga sistema                                                      	//
//////////////////////////////////////////////////////////////////////////////////		
void metodoDesligaSistema(void)
{
    carregaArrayComEspacoAscii(32,&caracterLcd[0]);
    HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_RESET);
    statusLigaDesliga = _DESLIGADO;
    statusPowerOnMem = _DESLIGADO;

    carregaTela0();

	HAL_UART_Transmit(&huart3, "sleep=1", 7, 25);
	HAL_UART_Transmit(&huart3, cmd_end, 3, 25);

	HAL_UART_Transmit(&huart3, "page START", 10, 25);
	HAL_UART_Transmit(&huart3, cmd_end, 3, 25);


//    preparaSalvaStatusPowerOn();
    controleTara = _TARADESATIVADA;
    tempoSegundoBacklightLigado = 0;
    tempoBacklightLigado = 0;
    flagTempoExibeBackLight = 0;
}
//////////////////////////////////////////////////////////////////////////////////		
//Função que controla o tempo para liberar o acesso ao menu de programação  	//
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
//Acesso aos menus de programação tecnica
            if (teclaPressionadaAtual == teclaSalva)
            {
                teclaPressionadaAtual = teclaSolta;
                telaAcessaMenuModoTecnicoIndicador();                   
            }
        }
	}
}
//////////////////////////////////////////////////////////////////////////////////		
//Função que controla o tempo de tecla solta                                  	//
// quando a tecla momoria 1 ou memoria 2 é solta antes do tempo para            //
// para acesso a programação o acesso a programação é cancelado e a momoria     //
//correspondente a tecla é ativada                                              //
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
    transfereConstToArray(&telaErroLimiteZeroLcd[0],&caracterLcd[0]);
    transfereCaracterLcdLinha1Dwin();
}
//////////////////////////////////////////////////////////////////////////////////		
//função de controle do tempo para apagar o backlight quando backlight amarelo	//
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
