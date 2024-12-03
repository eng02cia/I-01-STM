#include "transfereConstToArray.h"
//////////////////////////////////////////////////////////////////////////////////		
//Menu qyue da acesso ao menus secundarios de programacao                       //
//////////////////////////////////////////////////////////////////////////////////
void funcaoAcessaMenusProgramacao(void)
{
    if (teclaPressionadaAtual == teclaZeroRetorna)
    {        
        menuAcessaMenusProgramacao = menuAcessaMenusProgramacaoEmEspera;
        teclaPressionadaAtual = teclaSolta;    
        flagInibeTeclaSolta = 1;
    }
    else
    {
        switch (menuAcessaMenusProgramacao)
        {                 
//////////////////////////////////////////////////////////////////////////////////
//Verifica se da acesso ao menu do modo tecnico indicador                       //
//////////////////////////////////////////////////////////////////////////////////
        case acessaMenuModoTecnicoIndicador:
            switch (teclaPressionadaAtual)
            {
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta; 
                    telaAcessaMenuConfiguraSerial_1();                               
                    break; 
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    menuModoTecnicoIndicador = defineLimiteDeZero;
                    tempConfigIndicador = valorLimiteDeZeroMem;
                    telaMostraProgramacaoLimiteZero();
                    menuAcessaMenusProgramacao = menuAcessaMenusProgramacaoEmEspera;
                    break;
            }            
            break;                 
//////////////////////////////////////////////////////////////////////////////////
//Verifica se da acesso a programacao dos paramentos da serial 1                //
//////////////////////////////////////////////////////////////////////////////////
        case acessaMenuProgramaSerial_1:
            switch (teclaPressionadaAtual)
            {
                case teclaImprimeSetaAcima:     
                    teclaPressionadaAtual = teclaSolta; 
                    telaAcessaMenuFazCalibracao();        
                    break;            
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    velocidadeTxSerial_1 = velocidadeTxSerial_1Mem;
                    menuConfiguraSerial_1 = defineVelocidadeSerial_1;
                    telaMostraProgVelocidadeSerial_1();
                    menuAcessaMenusProgramacao = menuAcessaMenusProgramacaoEmEspera;
                    break;
            }            
            break;          
//////////////////////////////////////////////////////////////////////////////////
//Verifica se da acesso ao menu de calibracao                                   //
//////////////////////////////////////////////////////////////////////////////////
        case acessaMenuCalibracao:
            switch (teclaPressionadaAtual)
            {
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta; 
                    telaAcessaMenuConfiguraRelogio();                               
                    break;                 
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    telaSenhaDeAcessoCalibracao();
                    break;
            }            
            break;          
        case acessaMenuProgRelogio:
 			switch(teclaPressionadaAtual)
 			{
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta;
                    telaAcessaMenuModoTecnicoIndicador();
                    break;
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    menuAcessaMenusProgramacao = menuAcessaMenusProgramacaoEmEspera;
                    tempProgDataHora = exibeRelogioMem;
                    menuProgramacaoRelogioAtual = menuProgramaExibeRelogio;
                    break;
                default:
                    /* do nothing*/
                    break;
 			}
            break;    
        }               
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//tela de acesso a configuracao geral                                          	//
//////////////////////////////////////////////////////////////////////////////////
void telaAcessaMenuModoTecnicoIndicador(void)
{
    menuAcessaMenusProgramacao = acessaMenuModoTecnicoIndicador;
    if (linguagemSelecionadaMem == _PORTUGUES) {escreveDadoLcd(&charTelaAcessaMenuModoTecnicoIndicadorPT[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _INGLES) {escreveDadoLcd(&charTelaAcessaMenuModoTecnicoIndicadorING[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _ESPANHOL) {escreveDadoLcd(&charTelaAcessaMenuModoTecnicoIndicadorESP[0],&caracterLcd[0]);}    

    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;       

    telaAcessaMenuModoTecnicoSeteSegmentos();
}
//////////////////////////////////////////////////////////////////////////////////		
//tela de acesso a configuracao da serial                                     	//
//////////////////////////////////////////////////////////////////////////////////
void telaAcessaMenuConfiguraSerial_1(void)
{
    menuAcessaMenusProgramacao = acessaMenuProgramaSerial_1;
    if (linguagemSelecionadaMem == _PORTUGUES) {escreveDadoLcd(&charTelaAcessaMenuConfiguraSerial_1PT[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _INGLES) {escreveDadoLcd(&charTelaAcessaMenuConfiguraSerial_1ING[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _ESPANHOL) {escreveDadoLcd(&charTelaAcessaMenuConfiguraSerial_1ESP[0],&caracterLcd[0]);}

    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;       

    telaConfigSerialSeteSegmentos();
}
//////////////////////////////////////////////////////////////////////////////////		
//tela de acesso a calibracao do indicador                                     	//
//////////////////////////////////////////////////////////////////////////////////
void telaAcessaMenuFazCalibracao(void)
{
    menuAcessaMenusProgramacao = acessaMenuCalibracao;
    if (linguagemSelecionadaMem == _PORTUGUES) {escreveDadoLcd(&charTelaAcessaMenuFazCalibracaoPT[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _INGLES) {escreveDadoLcd(&charTelaAcessaMenuFazCalibracaoING[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _ESPANHOL) {escreveDadoLcd(&charTelaAcessaMenuFazCalibracaoESP[0],&caracterLcd[0]);}

    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;       

    telaAcessaMenuCalibracaoSeteSegmentos();
}
//////////////////////////////////////////////////////////////////////////////////
//tela de acesso a configuracao do relogio                                   	//
//////////////////////////////////////////////////////////////////////////////////
void telaAcessaMenuConfiguraRelogio(void)
{
	menuAcessaMenusProgramacao = acessaMenuProgRelogio;
    if (linguagemSelecionadaMem == _PORTUGUES){escreveDadoLcd(&charTelaAcessaMenuProgRelogioPT[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _INGLES){escreveDadoLcd(&charTelaAcessaMenuProgRelogioING[0],&caracterLcd[0]);}
    if (linguagemSelecionadaMem == _ESPANHOL){escreveDadoLcd(&charTelaAcessaMenuProgRelogioESP[0],&caracterLcd[0]);}

    telaMostraNaoSeAplicaSeteSegmentos();
}
