#include "comparaValoresArray.h"
#include "transfereArrayToArray.h"
//////////////////////////////////////////////////////////////////////////////////		
//Menu qyue da acesso ao menus secundarios de programa��o                       //
//////////////////////////////////////////////////////////////////////////////////
void funcaoProgramaDefinicaoFuncionamento(void)
{
    if(teclasEditaProgramaAtualPs2 == teclaEsc)
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
//programa o modo do funcionamento da pesagem					                //
// bovina 0 avicula 1															//
//////////////////////////////////////////////////////////////////////////////////
            // case defineModoFuncionamentoPesagem:
            //     switch (teclasEditaProgramaAtualPs2)
            //     {
            //         case teclaDel:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             tempConfigModoFuncionamento = 0;
            //             telaMostraProgModoFuncionamentoPesagem();
            //             break;
            //         case teclaSetaParaCima:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             tempConfigModoFuncionamento ++;
            //             if(tempConfigModoFuncionamento >= 2){tempConfigModoFuncionamento = 0;}
            //             telaMostraProgModoFuncionamentoPesagem();
            //             break;
            //         case teclaSetaParaBaixo:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             tempConfigModoFuncionamento ++;
            //             if(tempConfigModoFuncionamento >= 2){tempConfigModoFuncionamento = 0;}
            //             telaMostraProgModoFuncionamentoPesagem();
            //             break;                    
            //         //tecla Ok                   
            //         case teclaEnter:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             statusModoPesagemMem = tempConfigModoFuncionamento;
            //             salvaStatusModoFuncionamentoPesagemMem();
            //             acessaMenuEscolheVersaoIcv();
            //             break;
            //     }      
            //     break;     
//////////////////////////////////////////////////////////////////////////////////
//Verifica se ativa ou desativa o funcionamento da supervis�o de bateria        //                    
//////////////////////////////////////////////////////////////////////////////////
			// case defineModoFuncionamentoSupervisaoBateria:
			// 	switch (teclasEditaProgramaAtualPs2)
			// 	{
			// 		case teclaDel:
			// 			teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
			// 			tempConfigModoFuncionamento = 0;
			// 			telaMostraAtivaDesativaSupervisaoBateria();
			// 			break;
			// 		case teclaSetaParaCima:
			// 			teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
			// 			tempConfigModoFuncionamento++;
			// 			if(tempConfigModoFuncionamento > 2){tempConfigModoFuncionamento = 0;}
			// 			telaMostraAtivaDesativaSupervisaoBateria();
			// 			break;
			// 		case teclaSetaParaBaixo:
			// 			teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
			// 			if(tempConfigModoFuncionamento == 1){tempConfigModoFuncionamento = 0;}
			// 			else{tempConfigModoFuncionamento = 1;}
			// 			telaMostraAtivaDesativaSupervisaoBateria();
			// 			break;
			// 		//tecla Ok
			// 		case teclaEnter:
			// 			teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
			// 			difinicaoFuncionamentoSupervisaoBateriaMem = tempConfigModoFuncionamento;
			// 			salvaDifinicaoFuncionamentoSupervisaoBateriaMem();
			// 			acessaMenuEscolheVersaoIcv();
			// 			break;
			// 		default:

			// 			break;
			// 	}
			// 	break;
//////////////////////////////////////////////////////////////////////////////////
//Verifica se muda a versao de funcionamento do ICV                             //                    
//////////////////////////////////////////////////////////////////////////////////
            // case defineVersaoFuncionamentoICV:
            //     switch (teclasEditaProgramaAtualPs2)
            //     {
            //         case teclaDel:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             tempConfigModoFuncionamento = 0;
            //             telaMostraEscolheVersaoIcv();
            //             break;
            //         case teclaSetaParaCima:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             if(tempConfigModoFuncionamento == 1){tempConfigModoFuncionamento = 0;}
            //             else{tempConfigModoFuncionamento = 1;}
            //             telaMostraEscolheVersaoIcv();
            //             break;
            //         case teclaSetaParaBaixo:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             if(tempConfigModoFuncionamento == 1){tempConfigModoFuncionamento = 0;}
            //             else{tempConfigModoFuncionamento = 1;}
            //             telaMostraEscolheVersaoIcv();
            //             break;                    
            //         //tecla Ok                   
            //         case teclaEnter:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             defineFuncionamentoVersaoIcvMem = tempConfigModoFuncionamento;
            //             salvaDefineFuncionamentoVersaoIcvMem();
            //             acessaMenuModoFuncionamentoDpCalibracao();
            //             break;
            //     }      
            //     break;
//////////////////////////////////////////////////////////////////////////////////
//Verifica se muda a versao de funcionamento do ICV                             //
//////////////////////////////////////////////////////////////////////////////////
                // case defineMultiBalanca:
                // 	switch (teclasEditaProgramaAtualPs2)
                // 	{
                // 	case teclaDel:
                // 		teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
                // 		tempConfigModoFuncionamento = 0;
                // 		telaMostraEscolheVersaoIcv();
                // 		break;
                // 	case teclaSetaParaCima:
                // 		teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
                // 		if(tempConfigModoFuncionamento == 1){tempConfigModoFuncionamento = 0;}
                // 		else{tempConfigModoFuncionamento = 1;}
                // 		telaMostraEscolheDuplaCalibracao();
                // 		break;
                // 	case teclaSetaParaBaixo:
                // 		teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
                // 		if(tempConfigModoFuncionamento == 1){tempConfigModoFuncionamento = 0;}
                // 		else{tempConfigModoFuncionamento = 1;}
                // 		telaMostraEscolheDuplaCalibracao();
                // 		break;
                // 		//tecla Ok
                // 	case teclaEnter:
                // 		teclasEditaProgramaAtualPs2 = teclaSoltaPs2;

                // 		defineFuncionamentoCalibracao = tempConfigModoFuncionamento;
                // 		salvaDefineFuncionamentoDuplaCalibracao();

                // 		if(defineFuncionamentoCalibracao == 0)
                // 		{
                // 			carregaDadosBalanca1();
                // 			balancaEscolhidaMem = 0;
                // 			salvabalancaEscolhidaMem();

                // 		}
                // 		else
                // 		{
                // 			if(balancaEscolhidaMem == 0){carregaDadosBalanca1();}
                // 			else{carregaDadosBalanca2();}
                // 		}

                // 		acessaMenuModoFuncionamentoWifi();
                // 		break;
                // 	}
                // 	break;
//////////////////////////////////////////////////////////////////////////////////
//Verifica se ativa ou desativa o funcionamento do wifi                         //                    
//////////////////////////////////////////////////////////////////////////////////
            // case defineModoFuncionamentoWifi:
            //     switch (teclasEditaProgramaAtualPs2)
            //     {
            //         case teclaDel:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             tempConfigModoFuncionamento = 0;
            //             telaMostraAtivaDesativaWifi();
            //             break;
            //         case teclaSetaParaCima:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             if(tempConfigModoFuncionamento == 1){tempConfigModoFuncionamento = 0;}
            //             else{tempConfigModoFuncionamento = 1;}
            //             telaMostraAtivaDesativaWifi();
            //             break;
            //         case teclaSetaParaBaixo:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             if(tempConfigModoFuncionamento == 1){tempConfigModoFuncionamento = 0;}
            //             else{tempConfigModoFuncionamento = 1;}
            //             telaMostraAtivaDesativaWifi();
            //             break;                    
            //         //tecla Ok                   
            //         case teclaEnter:
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
            //             defineFuncionamentoWifiMem = tempConfigModoFuncionamento;
            //             salvaDefineFuncionamentoWifiMem();
            //             if(defineFuncionamentoWifiMem == _ativado)
            //             {
            //             	iniciaVariaveisTxEsp8266();
            //             	acessaMenuProgramaNomeRedeWifi();
            //             }
            //             else
            //             {
            //             	acessaMenuModoFuncionamentoBluetooth();
            //             }

            //             break;
            //         default:

            //         	break;
            //     }      
            //     break;       
//////////////////////////////////////////////////////////////////////////////////
//programa o nome da rede wifi                                                  //
//////////////////////////////////////////////////////////////////////////////////
            // case defineNomeRedeWifi:
            //     digita16CaracteresAscii();
            //     if(teclasEditaProgramaAtualPs2 == teclaEnter)
            //     {
            //         posicaoDigitoControleCadastro = 0;
            //         teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
                    
            //         tempConfigModoFuncionamento = comparaValoresArray(16,&nomeProgTemp[0],&arrayNomeRedeWifiMem[0]);
            //         if(tempConfigModoFuncionamento !=0)
            //         {
            //             transfereArrayToArray(16,&nomeProgTemp[0],&arrayNomeRedeWifiMem[0]);
            //             salvaArrayNomeRedeWifiMem();
            //             if(defineFuncionamentoWifiMem == _ativado){iniciaVariaveisTxEsp8266();}
            //         }
            //         acessaMenuProgramaSenhaWifi();
            //     }                   
            //     break;
//////////////////////////////////////////////////////////////////////////////////
//programa a senha da rede wifi                                                   //
//////////////////////////////////////////////////////////////////////////////////
            // case defineSenhaRedeWifi:
            //     if(mostraTelaTemporariaLcd == 0)
            //     {
            //         digita16CaracteresAscii();
            //         if(teclasEditaProgramaAtualPs2 == teclaEnter)
            //         {                    
            //             teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
                    
            //             tempConfigModoFuncionamento = comparaValoresArray(16,&nomeProgTemp[0],&arraySenhaWifiMem[0]);
            //             if(tempConfigModoFuncionamento !=0)
            //             {
            //                 if(posicaoDigitoControleCadastro < 8)
            //                 {                            
            //                     transfereArrayToArray(32,&caracterLcd[0],&backupTelaLcd[0]);      
            //                     transfereConstToArray(&charErroSenhaWifi[0],&caracterLcd[0]); 
            //                     mostraTelaTemporariaLcd = 1;
            //                     tempoMostraTelaTemporariaLcd = 1;                        
            //                 }
            //                 else
            //                 {                            
            //                     transfereArrayToArray(16,&nomeProgTemp[0],&arraySenhaWifiMem[0]);
            //                     arraySenhaWifiMem[16] = posicaoDigitoControleCadastro;
            //                     posicaoDigitoControleCadastro = 0;
            //                     salvaArraySenhaWifiMem();
            //                     if(defineFuncionamentoWifiMem == _ativado){iniciaVariaveisTxEsp8266();}
            //                 }                            
            //             } 
            //             if(mostraTelaTemporariaLcd == 0)
            //             {
            //             	acessaMenuModoFuncionamentoBluetooth();
            //             }
            //         } 
            //     }
            //     break;                
//////////////////////////////////////////////////////////////////////////////////
//faz a configuração do bluetooth							                    //
// 0 - desativado																//
// 1 - modo hc05																//
// 2 - modo bi conect bt836														//
// ////////////////////////////////////////////////////////////////////////////////
//             case defineModoFuncionamentoBluetooth:
//             	switch (teclasEditaProgramaAtualPs2)
//             	{
//             	case teclaDel:
//             		teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
//             		tempConfigModoFuncionamento = 0;
//             		telaMostraAtivaDesativaBluetooth();
//             		break;
//             	case teclaSetaParaCima:
//             		teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
//             		tempConfigModoFuncionamento++;
//             		if(tempConfigModoFuncionamento > 2){tempConfigModoFuncionamento = 0;}
//             		telaMostraAtivaDesativaBluetooth();
//             		break;
//             	case teclaSetaParaBaixo:
//             		teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
//             		tempConfigModoFuncionamento--;
//             		if(tempConfigModoFuncionamento == 255){tempConfigModoFuncionamento = 2;}
//             		telaMostraAtivaDesativaBluetooth();
//             		break;
//             		//tecla Ok
//             	case teclaEnter:
//             		teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
//             		defineFuncionamentoBluetoothMem = tempConfigModoFuncionamento;
//             		salvaDefineFuncionamentoBluetoothMem();
//             		acessaMenuProgramaNomeTelaInicial();
//             		break;
//             	default:

//             		break;
//             	}
//             	break;
//////////////////////////////////////////////////////////////////////////////////
//programa efetivamente o nome para tela inicial                                //
//////////////////////////////////////////////////////////////////////////////////
            case defineNomeTelaPrincipal:
                digita16CaracteresAscii();
                if(teclasEditaProgramaAtualPs2 == teclaEnter)
                {
                    posicaoDigitoControleCadastro = 0;
                    teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
                    transfereArrayToArray(16,&nomeProgTemp[0],&nomeTelaIndicadorMem[0]);
                    salvaNomeTelaIndicadorMem();
                    // acessaMenuProgramaModoFuncionamentoPesagem(); > ALTERAR CONFORME 
                    menuProgramaDefinicaoFucionamento = menuDefinicaoFuncionamentoEmEspera;
                    teclasEditaProgramaAtualPs2 = teclaSoltaPs2;  
                    flagInibeTeclaSolta = 1;
                }   
                break;           
        }
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//menu faz a programa��o de  um nome com 16 caracteres                         	//
//////////////////////////////////////////////////////////////////////////////////
void digita16CaracteresAscii(void)
{
    if(teclaPs2Press != 0)
    {                
        if(posicaoDigitoControleCadastro < 16)
       {          
            nomeProgTemp[posicaoDigitoControleCadastro++] = teclaPs2Press;
            telaMostraProgNomeAcii();
        }
        teclaPs2Press = 0;
    }
//verifica se apaga o nome 
    if(teclasEditaProgramaAtualPs2 == teclaDel)
    {
        teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
        posicaoDigitoControleCadastro = 0;
        carregaArrayComEspacoAscii(16,&nomeProgTemp[0]);
        telaMostraProgNomeAcii();
    }
//verifica se apaga um caracter
    if(teclasEditaProgramaAtualPs2 == teclaBackSpace)
    {
        teclasEditaProgramaAtualPs2 = teclaSoltaPs2;
        if(posicaoDigitoControleCadastro != 0)
        {
             nomeProgTemp[--posicaoDigitoControleCadastro] = ' ';
            telaMostraProgNomeAcii();
       }
    } 
}
//////////////////////////////////////////////////////////////////////////////////		
//menu programa modo funcionamento da pesagem		                         	//
//////////////////////////////////////////////////////////////////////////////////
// void acessaMenuProgramaModoFuncionamentoPesagem(void)
// {
//     menuProgramaDefinicaoFucionamento = defineModoFuncionamentoPesagem;
//     tempConfigModoFuncionamento = statusModoPesagemMem;
//     telaMostraProgModoFuncionamentoPesagem();
// }
//////////////////////////////////////////////////////////////////////////////////		
//menu programa modo funcionamento da supervis�o de bateria                    	//
//////////////////////////////////////////////////////////////////////////////////
// void acessaMenuModoFuncionamentoSupervisaoBateria(void)
// {
//     menuProgramaDefinicaoFucionamento = defineModoFuncionamentoSupervisaoBateria;
//     tempConfigModoFuncionamento = difinicaoFuncionamentoSupervisaoBateriaMem;
//     telaMostraAtivaDesativaSupervisaoBateria();
// }
// //////////////////////////////////////////////////////////////////////////////////		
// //menu programa a versao de funcionamento do Icv                            	//
// //////////////////////////////////////////////////////////////////////////////////
// void acessaMenuEscolheVersaoIcv(void)
// {
//     menuProgramaDefinicaoFucionamento = defineVersaoFuncionamentoICV;
//     tempConfigModoFuncionamento = defineFuncionamentoVersaoIcvMem;
//     telaMostraEscolheVersaoIcv();
// }
// //////////////////////////////////////////////////////////////////////////////////		
// //menu programa o modo do funcionamento do wifi                                	//
// //////////////////////////////////////////////////////////////////////////////////
// void acessaMenuModoFuncionamentoWifi(void)
// {
//     menuProgramaDefinicaoFucionamento = defineModoFuncionamentoWifi;
//     tempConfigModoFuncionamento = defineFuncionamentoWifiMem;
//     telaMostraAtivaDesativaWifi();
// }
//////////////////////////////////////////////////////////////////////////////////		
//menu programa o modo do funcionamento dupla calibracao	                      	//
//////////////////////////////////////////////////////////////////////////////////
// void acessaMenuModoFuncionamentoDpCalibracao(void)
// {
//     menuProgramaDefinicaoFucionamento = defineMultiBalanca;
//     tempConfigModoFuncionamento = defineFuncionamentoCalibracao;
//     telaMostraEscolheDuplaCalibracao();
// }
// //////////////////////////////////////////////////////////////////////////////////
// //menu programa o modo do funcionamento do bluetooth                           	//
// //////////////////////////////////////////////////////////////////////////////////
// void acessaMenuModoFuncionamentoBluetooth(void)
// {
//     menuProgramaDefinicaoFucionamento = defineModoFuncionamentoBluetooth;
//     tempConfigModoFuncionamento = defineFuncionamentoBluetoothMem;
//     telaMostraAtivaDesativaBluetooth();
// }
// //////////////////////////////////////////////////////////////////////////////////
// //menu programa o nome da rede wifi                                           	//
// //////////////////////////////////////////////////////////////////////////////////
// void acessaMenuProgramaNomeRedeWifi(void)
// {
//     menuProgramaDefinicaoFucionamento = defineNomeRedeWifi;
//     transfereArrayToArray(16,&arrayNomeRedeWifiMem[0],&nomeProgTemp[0]);
//     telaMostraProgNomeAcii();
// }
// //////////////////////////////////////////////////////////////////////////////////		
// //menu programa a senha da rede wifi                                           	//
// //////////////////////////////////////////////////////////////////////////////////
// void acessaMenuProgramaSenhaWifi(void)
// {
//     menuProgramaDefinicaoFucionamento = defineSenhaRedeWifi;
//     transfereArrayToArray(16,&arraySenhaWifiMem[0],&nomeProgTemp[0]);
//     telaMostraProgNomeAcii();
// }
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
//tela mostra ativa desativa saidas serial                                    	//
//////////////////////////////////////////////////////////////////////////////////
// void telaMostraProgModoFuncionamentoPesagem(void)
// {
//     escreveDadoLcd(&charTelaDefineFuncionamentoPesagem[0],&caracterLcd[0]);
//     if(tempConfigModoFuncionamento == _bovina)
// 	{
// 		escreveDadoLcd(&charBovina[0],&caracterLcd[16]);
// 	}
//     if(tempConfigModoFuncionamento == _avicula)
// 	{
// 		escreveDadoLcd(&charAvicula[0],&caracterLcd[16]);
// 	}
//     caracterLcd[29] = caracterRetorna;
//     caracterLcd[30] = caracterIncremento;
//     caracterLcd[31] = caracterSalva;
// }
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra ativa desativa saidas seriail                                    	//
//////////////////////////////////////////////////////////////////////////////////
// void telaMostraAtivaDesativaSupervisaoBateria(void)
// {
//     escreveDadoLcd(&charTelaDefineFuncionamentoSupervisaoBateria[0],&caracterLcd[0]);
//      if(tempConfigModoFuncionamento == _desativado)
//     {
//     	escreveDadoLcd(&charDesativado[0],&caracterLcd[21]);
//     }
//     if(tempConfigModoFuncionamento == _modo_1)
//     {
//     	escreveDadoLcd(&charModo_1[0],&caracterLcd[21]);
//     }
//     if(tempConfigModoFuncionamento == _modo_2)
//     {
//     	escreveDadoLcd(&charModo_2[0],&caracterLcd[16]);
//     }

//     caracterLcd[29] = caracterRetorna;
//     caracterLcd[30] = caracterIncremento;
//     caracterLcd[31] = caracterSalva;
// }
// //////////////////////////////////////////////////////////////////////////////////		
// //tela mostra ativa desativa wifi                                            	//
// //////////////////////////////////////////////////////////////////////////////////
// void telaMostraAtivaDesativaWifi(void)
// {
//     escreveDadoLcd(&charTelaDefineFuncionamentoWifi[0],&caracterLcd[0]);
//     if (tempConfigModoFuncionamento == _ativado)
// 	{
// 		escreveDadoLcd(&charAtivado[0],&caracterLcd[21]);
// 	}
//     else 
// 	{
// 		escreveDadoLcd(&charDesativado[0],&caracterLcd[21]);
// 	}
//     caracterLcd[29] = caracterRetorna;
//     caracterLcd[30] = caracterIncremento;
//     caracterLcd[31] = caracterSalva;
// }
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra ativa desativa bluetooth                                       	//
//////////////////////////////////////////////////////////////////////////////////
// void telaMostraAtivaDesativaBluetooth(void)
// {
//     escreveDadoLcd(&charTelaDefineFuncionamentoBluetooth[0],&caracterLcd[0]);
//     if (tempConfigModoFuncionamento == bluetoothDesativado)
// 	{
// 		escreveDadoLcd(&charDesativado[0],&caracterLcd[16]);
// 	}
//     if (tempConfigModoFuncionamento == modeloModuloHc05)
//  	{
//  		escreveDadoLcd(&charMonoConect[0],&caracterLcd[16]);
//  	}
//     if (tempConfigModoFuncionamento == modeloModulobt836)
//   	{
//   		escreveDadoLcd(&charMultConect[0],&caracterLcd[16]);
//   	}
//     caracterLcd[29] = caracterRetorna;
//     caracterLcd[30] = caracterIncremento;
//     caracterLcd[31] = caracterSalva;
// }


//////////////////////////////////////////////////////////////////////////////////
//tela mostra escolhe versao ICV                                            	//
//////////////////////////////////////////////////////////////////////////////////
// void telaMostraEscolheVersaoIcv(void)
// {
//     escreveDadoLcd(&charTelaDefineFuncionamentoVersaoIcv[0],&caracterLcd[0]);
//     if (tempConfigModoFuncionamento == _INDICADOR_VERSAO_01)
// 	{
// 		escreveDadoLcd(&charVersaoIcv01[0],&caracterLcd[16]);
// 	}
//     else 
// 	{
// 		escreveDadoLcd(&charVersaoIcv02[0],&caracterLcd[16]);
// 	}
//     caracterLcd[29] = caracterRetorna;
//     caracterLcd[30] = caracterIncremento;
//     caracterLcd[31] = caracterSalva;
// }
//////////////////////////////////////////////////////////////////////////////////
//tela mostra Escolhe multi balanca                                           	//
//////////////////////////////////////////////////////////////////////////////////
// void telaMostraEscolheDuplaCalibracao(void)
// {
//     escreveDadoLcd(&charTelaDefineFuncionamentoDpCalibracao[0],&caracterLcd[0]);
//     if (tempConfigModoFuncionamento == _INDICADOR_VERSAO_01)
// 	{
// 		escreveDadoLcd(&charUmaCalibracao[0],&caracterLcd[16]);
// 	}
//     else
// 	{
// 		escreveDadoLcd(&charDuasCalibracao[0],&caracterLcd[16]);
// 	}
//     caracterLcd[29] = caracterRetorna;
//     caracterLcd[30] = caracterIncremento;
//     caracterLcd[31] = caracterSalva;
// }
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra o acesso a programa��o do nome da tela                          	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraProgNomeAcii(void)
{
    //  if(menuProgramaDefinicaoFucionamento == defineNomeRedeWifi)
    // {
    //     escreveDadoLcd(&charTelaDefineNomeRedeWifi[0],&caracterLcd[0]); 
    // } 
    // if(menuProgramaDefinicaoFucionamento == defineSenhaRedeWifi)
    // {
    //     escreveDadoLcd(&charTelaDefineSenhaWifi[0],&caracterLcd[0]);
    // }
    if(menuProgramaDefinicaoFucionamento == defineNomeTelaPrincipal)
    {
        escreveDadoLcd(&charTelaDefineTelaInicial[0],&caracterLcd[0]);
    }    
    transfereArrayToArray(16,&nomeProgTemp[0],&caracterLcd[16]);
    caracterLcd[13] = caracterRetorna;
    caracterLcd[14] = caracterIncremento;
    caracterLcd[15] = caracterSalva;
}
