//////////////////////////////////////////////////////////////////////////////////		
//////////////////////////////////////////////////////////////////////////////////
//Fun��o que inicializa a utilia��o dos canais digitais                         //
//////////////////////////////////////////////////////////////////////////////////
void inicializaMultiplexLed(void)
{

}
//////////////////////////////////////////////////////////////////////////////////
//Metodo que decodifica o teclado 												//
//////////////////////////////////////////////////////////////////////////////////
void metodoMultiplexLedIndicador(void)
{
// multiplexa leds indicadotivos de zero e tara  
	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin, GPIO_PIN_RESET);
    if(menuCalibraIndicador == menuCalibraIndicadorEmEspera
    && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera
    && menuProgramaPesoFulao == menuProgramaPesoEmEspera
    && menuProgramacaoRelogioAtual == menuProgramaRelogioEmEspera
    && menuModoTecnicoFulao == menuModoTecnicoFulaoEmEspera
    && menuControleCadastro == menuControleCadastroEmEspera
    && menuControleRelatorio == menuControleRelatoriosEmEspera
//    && menuConfiguraSerial_1 == menuConfiguraSerialEmEspera
    && menuSenhaAcesso == menuSenhaAcessoEmEspera)               
    {
// controle do zero do indicador 
        if(controleTara == _TARADESATIVADA && statusLigaDesliga == _LIGADO)
        {
            if(indicadorEmZero == 1)
            {
            	HAL_GPIO_WritePin(pinoColuna2_GPIO_Port, pinoColuna2_Pin, GPIO_PIN_SET);
            	HAL_GPIO_WritePin(LED5_GPIO_Port, pinoLedZero, GPIO_PIN_RESET);
            }
        }
//controle da tara
        if(controleTara == _TARAATIVADA && statusLigaDesliga == _LIGADO)
        {
        	HAL_GPIO_WritePin(pinoColuna1_GPIO_Port, pinoColuna1_Pin, GPIO_PIN_SET);
        	HAL_GPIO_WritePin(LED6_GPIO_Port, pinoLedTara, GPIO_PIN_RESET);
        }
    }  
}
