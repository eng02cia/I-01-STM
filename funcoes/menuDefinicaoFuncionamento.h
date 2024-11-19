#include "comparaValoresArray.h"
#include "transfereArrayToArray.h"
//////////////////////////////////////////////////////////////////////////////////		
//Menu qyue da acesso ao menus secundarios de programacao                       //
//////////////////////////////////////////////////////////////////////////////////
void funcaoProgramaDefinicaoFuncionamento(void)
{
    if (teclasEditaProgramaAtualPs2 == teclaEsc)
    {        
        menuProgramaDefinicaoFucionamento = menuDefinicaoFuncionamentoEmEspera;
        teclasEditaProgramaAtualPs2 = teclaSoltaPs2;  
        flagInibeTeclaSolta = 1;
    }
    else
    {
        switch (menuProgramaDefinicaoFucionamento)
        {            
//////////////////////////////////////////////////////////////////////////////////
//programa efetivamente o nome para tela inicial                                //
//////////////////////////////////////////////////////////////////////////////////
            case defineNomeTelaPrincipal:
                digita16CaracteresAscii();
                if (teclasEditaProgramaAtualPs2 == teclaEnter)
                {
                    posicaoDigitoControleCadastro = 0;
                    teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
                    transfereArrayToArray(16,&nomeProgTemp[0],&nomeTelaIndicadorMem[0]);
                    salvaNomeTelaIndicadorMem();
                    acessaMenuModoFuncionamentoLiguagem();
                    menuProgramaDefinicaoFucionamento = defineSelecionaLinguagem;
                    teclasEditaProgramaAtualPs2 = teclaSoltaPs2;  
                    flagInibeTeclaSolta = 1;
                }   
                break;         
            case defineSelecionaLinguagem:
           	//tecla incremento
            	switch(teclasEditaProgramaAtualPs2)
            	{
            		case teclaDel:
    					teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
    					tempConfigModoFuncionamento = 0;
	            		telaMostraSelecionaLinguagem();
	            		break;
    				case teclaSetaParaCima:
    					teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
    					tempConfigModoFuncionamento++;
    					if (tempConfigModoFuncionamento > 2){tempConfigModoFuncionamento = 0;}
    					telaMostraSelecionaLinguagem();
    					break;
    				case teclaSetaParaBaixo:
    					teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
    					tempConfigModoFuncionamento--;
    					if (tempConfigModoFuncionamento == 255){tempConfigModoFuncionamento = 2;}
    					telaMostraSelecionaLinguagem();
    					break;
    				case teclaEnter:
		           		teclasEditaProgramaAtualPs2 = teclaSoltaPs2;  
                        flagInibeTeclaSolta = 1;
			       		linguagemSelecionadaMem = tempConfigModoFuncionamento;
			       		salvaLinguagemSelecionadaMem();
                        menuProgramaDefinicaoFucionamento = defineNomeTelaPrincipal;
						acessaMenuProgramaNomeTelaInicial();
				      	break;
				   default:
				  		break;
            	}
                break;
            default:
             // do nothing
                break;  
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//menu faz a programacao de  um nome com 16 caracteres                         	//
//////////////////////////////////////////////////////////////////////////////////
void digita16CaracteresAscii(void)
{
    if (teclaPs2Press != 0)
    {                
        if (posicaoDigitoControleCadastro < 16)
       {          
            nomeProgTemp[posicaoDigitoControleCadastro++] = teclaPs2Press;
            telaMostraProgNomeAcii();
        }
        teclaPs2Press = 0;
    }
//verifica se apaga o nome 
    if (teclasEditaProgramaAtualPs2 == teclaDel)
    {
        teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
        posicaoDigitoControleCadastro = 0;
        carregaArrayComEspacoAscii(16,&nomeProgTemp[0]);
        telaMostraProgNomeAcii();
    }
//verifica se apaga um caracter
    if (teclasEditaProgramaAtualPs2 == teclaBackSpace)
    {
        teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
        if (posicaoDigitoControleCadastro != 0)
        {
             nomeProgTemp[--posicaoDigitoControleCadastro] = ' ';
            telaMostraProgNomeAcii();
       }
    } 
}
//////////////////////////////////////////////////////////////////////////////////		
//menu programa o nome da tela inicial                                        	//
//////////////////////////////////////////////////////////////////////////////////
void acessaMenuProgramaNomeTelaInicial(void)
{
    menuProgramaDefinicaoFucionamento = defineNomeTelaPrincipal;
    transfereArrayToArray(16,&nomeTelaIndicadorMem[0],&nomeProgTemp[0]);
    telaMostraProgNomeAcii();
}

//////////////////////////////////////////////////////////////////////////////////
//acessaa programacao da liguagem utiliziada pelo indicador de peso          	//
//////////////////////////////////////////////////////////////////////////////////
void acessaMenuModoFuncionamentoLiguagem(void)
{
	menuProgramaDefinicaoFucionamento = defineSelecionaLinguagem;
	tempConfigModoFuncionamento = linguagemSelecionadaMem;
	telaMostraSelecionaLinguagem();
}

//////////////////////////////////////////////////////////////////////////////////		
//tela mostra o acesso a programacao do nome da tela                          	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraProgNomeAcii(void)
{
    if (menuProgramaDefinicaoFucionamento == defineNomeTelaPrincipal)
    {
        if (linguagemSelecionadaMem == _PORTUGUES) {escreveDadoLcd(&charTelaDefineTelaInicialPT[0],&caracterLcd[0]);}
        if (linguagemSelecionadaMem == _INGLES) {escreveDadoLcd(&charTelaDefineTelaInicialING[0],&caracterLcd[0]);}
        if (linguagemSelecionadaMem == _ESPANHOL) {escreveDadoLcd(&charTelaDefineTelaInicialESP[0],&caracterLcd[0]);}
    }    
    transfereArrayToArray(16,&nomeProgTemp[0],&caracterLcd[16]);
    caracterLcd[13] = caracterRetorna;
    caracterLcd[14] = caracterIncremento;
    caracterLcd[15] = caracterSalva;
}

//////////////////////////////////////////////////////////////////////////////////
//tela mostra a configuracao da linguagem utilizada                         	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraSelecionaLinguagem(void)
{
	if (tempConfigModoFuncionamento == _PORTUGUES)
	{
	    escreveDadoLcd(&charTelaSelecionaLinguagemPT[0],&caracterLcd[0]);
		escreveDadoLcd(&charTelaPortugues[0],&caracterLcd[16]);
	}
	if (tempConfigModoFuncionamento == _INGLES)
	{
        escreveDadoLcd(&charTelaSelecionaLinguagemING[0],&caracterLcd[0]);
		escreveDadoLcd(&charTelaIngles[0],&caracterLcd[16]);
	}
	if (tempConfigModoFuncionamento == _ESPANHOL)
	{
        escreveDadoLcd(&charTelaSelecionaLinguagemESP[0],&caracterLcd[0]);
		escreveDadoLcd(&charTelaEspanhol[0],&caracterLcd[16]);
	}
}
