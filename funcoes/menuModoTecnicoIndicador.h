//////////////////////////////////////////////////////////////////////////////////		
//Menu qyue da acesso ao menus secundarios de programa��o                       //
//////////////////////////////////////////////////////////////////////////////////
void funcaoMenuModoTecnicoIndicador(void)
{
    if (teclaPressionadaAtual == teclaZeroRetorna)
    {
        menuModoTecnicoIndicador = menuModoTecnicoIndicadorEmEspera;
        teclaPressionadaAtual = teclaSolta;
        flagInibeTeclaSolta = 1;
        telaAcessaMenuModoTecnicoIndicador();
    } 
    switch (menuModoTecnicoIndicador)
    {            
//////////////////////////////////////////////////////////////////////////////////
//define o limite de zero                                                      //
//////////////////////////////////////////////////////////////////////////////////
        case defineLimiteDeZero:
            switch (teclaPressionadaAtual)
            {
                case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigIndicador = 1;     
                    telaMostraProgramacaoLimiteZero();
                    break;                             
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta;
                    if (++tempConfigIndicador == _LIMITE_ZERO_MAXIMO){tempConfigIndicador = 1;};                    
                    telaMostraProgramacaoLimiteZero();
                    break;   
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    valorLimiteDeZeroMem = tempConfigIndicador;
                    salvaValorLimiteDeZeroMem();
                    menuModoTecnicoIndicador = defineFiltroDigital;                   
                    tempConfigIndicador = valorFiltroDigitalMem;
                    telaValorFiltroDigitalModoTecnicoIndicador();
                    break;
            }            
            break; 
//////////////////////////////////////////////////////////////////////////////////
//define o valor do filtro digital                                              //
//////////////////////////////////////////////////////////////////////////////////
        case defineFiltroDigital:
 //tecla incremento
            switch (teclaPressionadaAtual )
            {               
                case teclaTaraSetaEsquerda:
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigIndicador = 0;  
                    telaValorFiltroDigitalModoTecnicoIndicador();
                    break; 
//tecla Seta acima                      
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta;
                    tempConfigIndicador++;
                    if (tempConfigIndicador >= _VMAX_FILTRO_DIGITAL){tempConfigIndicador = 0;}                   
                    telaValorFiltroDigitalModoTecnicoIndicador();
                    break;
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    valorFiltroDigitalMem = tempConfigIndicador;
                    salvaValorFiltroDigitalMem();
                    menuModoTecnicoIndicador = defineZeroAoLigar;
                    tempConfigIndicador = statusZeroAoLigarMem;
                    telaMostraProgramacaoStatusZeroLigarIndicador();
                    break;
            }					            
            break;
//////////////////////////////////////////////////////////////////////////////////
//define se executa ou nao zero ao ligar o indicador                            //
// 0 - desativado  1 - ativado                                                  //
//////////////////////////////////////////////////////////////////////////////////
        case defineZeroAoLigar: 
            switch (teclaPressionadaAtual )
            {   
                case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigIndicador = 0;
                    telaMostraProgramacaoStatusZeroLigarIndicador();
                    break;                            
//tecla Seta acima  
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta;
                    if (tempConfigIndicador == 1){tempConfigIndicador = 0;}
                    else{tempConfigIndicador = 1;}
                    telaMostraProgramacaoStatusZeroLigarIndicador();
                    break;
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    statusZeroAoLigarMem = tempConfigIndicador;
                    salvaStatusZeroPowerMem();
                    menuModoTecnicoIndicador = defineModoFuncionamentoBackLight;
                    tempConfigIndicador = modoFuncionamentoBackLightMem;
                    telaMostraProgramacaoModoFuncionamentoBackLight();
                    break;
            }					            
            break;                  
//////////////////////////////////////////////////////////////////////////////////
//define o modo de funcionamento do backlight                                   //
//0 - desligado 1 - ligado tempo todo  2 - ligado por tempo                     //
//////////////////////////////////////////////////////////////////////////////////
        case defineModoFuncionamentoBackLight:
            switch (teclaPressionadaAtual )
            {
                case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigIndicador = 0;
                    telaMostraProgramacaoModoFuncionamentoBackLight();
                    break;                    
//tecla Seta acima  
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta;
                    if (++tempConfigIndicador > 2){tempConfigIndicador = 0;}
                    telaMostraProgramacaoModoFuncionamentoBackLight();
                    break;
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    modoFuncionamentoBackLightMem = tempConfigIndicador;
                    salvaModoFuncionamentoBackLightMem();
                    if (modoFuncionamentoBackLightMem == _BACKLIGHT_LIGADO 
                        || modoFuncionamentoBackLightMem == _BACKLIGHT_DESLIGADO)
                    {
                        if (modoFuncionamentoBackLightMem == _BACKLIGHT_DESLIGADO)
                        {
                        	HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_SET);
                        	tempoBacklightLigado = 0;
                            tempoSegundoBacklightLigado = 0;
                            flagTempoExibeBackLight = 0;
                        	menuModoTecnicoIndicador = defineLimiteDeZero;
                        	tempConfigIndicador = valorLimiteDeZeroMem;
                        	telaMostraProgramacaoLimiteZero();
                        }
                        if (modoFuncionamentoBackLightMem == _BACKLIGHT_LIGADO)
                        {
                        	HAL_GPIO_WritePin(pinoBackLight_GPIO_Port, pinoBackLight_Pin,GPIO_PIN_RESET);
                        	menuModoTecnicoIndicador = defineLimiteDeZero;
                        	tempConfigIndicador = valorLimiteDeZeroMem;
                        	telaMostraProgramacaoLimiteZero();
                        }
                    }
                    else
                    {
                        menuModoTecnicoIndicador = defineTempoDesligaBackLight;
                        tempConfigIndicador = tempoDesligaBackLightMem;
                        telaTempoBackLightLigado();
                    }
                    break;
            }					            
            break;                  
//////////////////////////////////////////////////////////////////////////////////
//define o tempo que o back light fica ligado                                   //
//////////////////////////////////////////////////////////////////////////////////
        case defineTempoDesligaBackLight:
            switch (teclaPressionadaAtual )
            { 
               case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigIndicador = 1;
                    telaTempoBackLightLigado();
                    break;                    
//tecla Seta acima  
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta;
                    if (++tempConfigIndicador > 10){tempConfigIndicador = 1;};                    
                    telaTempoBackLightLigado();
                    break;
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    tempoDesligaBackLightMem = tempConfigIndicador;
                    salvaTempoDesligaBackLightMem();
                    menuModoTecnicoIndicador = defineLimiteDeZero;
                    tempConfigIndicador = valorLimiteDeZeroMem;
                    telaMostraProgramacaoLimiteZero();
                    break;
            }					            
            break;             
     }
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra limite de zero                                                	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraProgramacaoLimiteZero(void)
{

    escreveDadoLcd(&charTelaConfiguraLimiteZero[0],&caracterLcd[0]);
    caracterLcd[16] = tempConfigIndicador + '0';
    caracterLcd[18] = '%';
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;        
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra  filtro digital modo tecnico indicador                          	//
//////////////////////////////////////////////////////////////////////////////////
void telaValorFiltroDigitalModoTecnicoIndicador(void)
{


	transfereConstToArray(&charValorFiltroDigital[0],&caracterLcd[0]);
    if (tempConfigIndicador < 10){caracterLcd[16] = tempConfigIndicador + '0';}
    else if (tempConfigIndicador < 100){inteiroTo2BytesAscii(tempConfigIndicador,&caracterLcd[16]);}
    else{inteiroTo3BytesAscii(tempConfigIndicador,&caracterLcd[16]);}
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;    
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra a programa��o do modo de pesagem do indicador                   	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraProgramacaoStatusZeroLigarIndicador(void)
{

    escreveDadoLcd(&charTelaModoPesagemIndicador[0],&caracterLcd[0]);  
    if (tempConfigIndicador == 0){escreveDadoLcd(&charTelaDesativado[0],&caracterLcd[16]);}
    else{escreveDadoLcd(&charTelaAtivado[0],&caracterLcd[16]);}
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;    
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra a programa��o do modo de funcinamento do backlight             	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraProgramacaoModoFuncionamentoBackLight(void)
{

	escreveDadoLcd(&charTelaModoFuncBackLight[0],&caracterLcd[0]);
    if (tempConfigIndicador == 0){escreveDadoLcd(&charTelaDesligado[0],&caracterLcd[16]);}
    if (tempConfigIndicador == 1){escreveDadoLcd(&charTelaLigado[0],&caracterLcd[16]);}
    if (tempConfigIndicador == 2){escreveDadoLcd(&charTelaLigadoPorTempo[0],&caracterLcd[16]);}

    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;    
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra a programa��o do tempo que o back light fica ligado               //
//////////////////////////////////////////////////////////////////////////////////
void telaTempoBackLightLigado(void)
{
    escreveDadoLcd(&charTelaTempoBackLight[0],&caracterLcd[0]);
    inteiroTo2BytesAscii(tempConfigIndicador,&caracterLcd[16]);
    caracterLcd[19] = 'M';
	if (modoFuncionamentoBackLightMem == _BACKLIGHT_LIGADO){escreveDadoLcd(&charTelaDesligado[0],&caracterLcd[16]);}
	caracterLcd[29] = caracterRetorna;
	caracterLcd[30] = caracterIncremento;
	caracterLcd[31] = caracterSalva;
}


             
