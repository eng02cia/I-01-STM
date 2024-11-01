#include "transfereConstToArray.h"
//////////////////////////////////////////////////////////////////////////////////		
//Menu qyue da acesso ao menus secundarios de programa��o                       //
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
//Verifica se da acesso a programa��o dos paramentos da serial 1                //
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
//Verifica se da acesso ao menu de calibra��o                                   //
//////////////////////////////////////////////////////////////////////////////////
        case acessaMenuCalibracao:
            switch (teclaPressionadaAtual)
            {
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta; 
                    telaAcessaMenuModoTecnicoIndicador();                               
                    break;                 
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
//                    controleTara = _TARADESATIVADA;
//                    tempProgIndicador = valorFiltroDigitalMem;
//                    telaValorFiltroDigitalIndicador();  
//                    menuAcessaMenusProgramacao = menuAcessaMenusProgramacaoEmEspera;
                    telaSenhaDeAcessoCalibracao();
                break;
            }            
        break;                                       
        }               
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//tela de acesso a configura��o geral                                          	//
//////////////////////////////////////////////////////////////////////////////////
void telaAcessaMenuModoTecnicoIndicador(void)
{
    menuAcessaMenusProgramacao = acessaMenuModoTecnicoIndicador;
    escreveDadoLcd(&charTelaAcessaMenuModoTecnicoIndicador[0],&caracterLcd[0]);  
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;       
}
//////////////////////////////////////////////////////////////////////////////////		
//tela de acesso a configura��o da serial                                     	//
//////////////////////////////////////////////////////////////////////////////////
void telaAcessaMenuConfiguraSerial_1(void)
{
    menuAcessaMenusProgramacao = acessaMenuProgramaSerial_1;
    escreveDadoLcd(&charTelaAcessaMenuConfiguraSerial_1[0],&caracterLcd[0]);
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;       
}
//////////////////////////////////////////////////////////////////////////////////		
//tela de acesso a calibra��o do indicador                                     	//
//////////////////////////////////////////////////////////////////////////////////
void telaAcessaMenuFazCalibracao(void)
{
    menuAcessaMenusProgramacao = acessaMenuCalibracao;
    escreveDadoLcd(&charTelaAcessaMenuFazCalibracao[0],&caracterLcd[0]);
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;       
}
