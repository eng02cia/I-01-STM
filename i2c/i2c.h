//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
// Funcoes de comunicacao com teclado PS2                                   	//
//////////////////////////////////////////////////////////////////////////////////
//  DESCRICAO DO PROTOCOLO:													  	//
//  Pinos Utilizados
// Portb 00 clock
// Portb 01 data


//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////		
//funcao que inicializa o barramento de comunicacao com teclado ps2 			//
//////////////////////////////////////////////////////////////////////////////////		
void inicializaComunicacaoI2c(void)
{
	anoBase = valorAnoBase;
    tempoLeituraRelogio = 2;

    le_Relogio_i2c();
    if(statusLeituraRelogio == comRelogio)
    {
    	segundoRelogio = bcdToDec(set_time[0]);
    	minutoRelogio = bcdToDec(set_time[1]);
    	horaRelogio = bcdToDec(set_time[2]);
    	diaSemanaRelogio = bcdToDec(set_time[3]);
    	diaMesRelogio = bcdToDec(set_time[4]);
    	mesRelogio = bcdToDec(set_time[5]);
    	anoRelogio = bcdToDec(set_time[6]);
    	inteiroTo2BytesAscii(horaRelogio,&arrayHora[0]);
    	inteiroTo2BytesAscii(minutoRelogio,&arrayMinuto[0]);
    	inteiroTo2BytesAscii(diaMesRelogio,&arrayDia[0]);
    	inteiroTo2BytesAscii(mesRelogio,&arrayMes[0]);
    	inteiroTo2BytesAscii(anoRelogio,&arrayAno[0]);
    	//em caso de data incorreta reinicia relogio
    	if(flagRelogioInicializado == 0)
    	{
    		flagRelogioInicializado = 1;
    		if(anoRelogio < 22)
    		{
    			minutoTemp = 1;// minuto
    			horaTemp = 1;// hora
    			diaTemp = 1;// dia
    			mesTemp = 1;//mes
    			anoTemp = 22;//ano
    			grava_Relogio_i2c(0,minutoTemp,horaTemp,0,diaTemp,mesTemp,anoTemp);
    		}
    	}
    }
}

//////////////////////////////////////////////////////////////////////////////////		
//metodo de controle do tempo de leitura do relogio                             //
//////////////////////////////////////////////////////////////////////////////////
void metodoTempoLeituraRelogio(void)
{
    if(++ tempoLeituraRelogio > 4)
    {
        tempoLeituraRelogio = 0;
        if(mostraTelaTemporariaLcd == 0
        && exibeVersionControl == 0
        && menuAcessaMenusProgramacao == menuAcessaMenusProgramacaoEmEspera
//        && menuProgramacao2 == menuProgramacao2EmEspera
    	&& menuCalibraIndicador == menuCalibraIndicadorEmEspera
//        && menuResetFabrica == menuResetFabricaEmEspera
        && menuModoTecnicoIndicador == menuModoTecnicoIndicadorEmEspera
//		&& menuModoTecnicoIndicadorI01 == menuModoTecnicoIndicadorI01EmEspera
//        && menuDadosPesagemCargaViva == menuDadosPesagemCargaVivaEmEspera
        && menuProgramacaoRelogioAtual == menuProgramaRelogioEmEspera
//        && menuConfiguraSemFio == menuConfiguraSemFioEmEspera
        && menuProgramaDefinicaoFucionamento == menuDefinicaoFuncionamentoEmEspera)
//        && menuStatusHomologacao == menuStatusHomologacaoEmEspera)
        {
        	le_Relogio_i2c();
        	segundoRelogio = bcdToDec(set_time[0]);
        	minutoRelogio = bcdToDec(set_time[1]);
        	horaRelogio = bcdToDec(set_time[2]);
        	diaSemanaRelogio = bcdToDec(set_time[3]);
        	diaMesRelogio = bcdToDec(set_time[4]);
        	mesRelogio = bcdToDec(set_time[5]);
        	anoRelogio = bcdToDec(set_time[6]);
        	inteiroTo2BytesAscii(horaRelogio,&arrayHora[0]);
        	inteiroTo2BytesAscii(minutoRelogio,&arrayMinuto[0]);
        	inteiroTo2BytesAscii(diaMesRelogio,&arrayDia[0]);
        	inteiroTo2BytesAscii(mesRelogio,&arrayMes[0]);
        	inteiroTo2BytesAscii(anoRelogio,&arrayAno[0]);
         }
    }    
}
//////////////////////////////////////////////////////////////////////////////////		
//metodo que escreve no relogio			                            			//
//////////////////////////////////////////////////////////////////////////////////
void grava_Relogio_i2c(uint8_t seg, uint8_t min, uint8_t horas, uint8_t diaDaSemana, uint8_t diaDoMes, uint8_t mes, uint8_t ano)
{
	set_time[0] = decToBcd(seg);
	set_time[1] = decToBcd(min);
	set_time[2] = decToBcd(horas);
	set_time[3] = decToBcd(diaDaSemana);
	set_time[4] = decToBcd(diaDoMes);
	set_time[5] = decToBcd(mes);
	set_time[6] = decToBcd(ano);
	HAL_I2C_Mem_Write(&hi2c1, DS1307_ADDRESS, 0X00,1, &set_time, 7, 1000);
}
//////////////////////////////////////////////////////////////////////////////////		
//metodo que le o relogio				                            			//
//////////////////////////////////////////////////////////////////////////////////
void le_Relogio_i2c(void)
{
	HAL_I2C_Mem_Read(&hi2c1, DS1307_ADDRESS,0x00,1,&set_time, 7, 1000);
	time.segundos = bcdToDec(set_time[0]);
	time.minutos = bcdToDec(set_time[1]);
	time.horas = bcdToDec(set_time[2]);
	time.diaDaSemana = bcdToDec(set_time[3]);
	time.diaDoMes = bcdToDec(set_time[4]);
	time.mes = bcdToDec(set_time[5]);
	time.ano = bcdToDec(set_time[6]);
	if(time.segundos == 0 && time.minutos == 0 && time.horas == 0 && time.diaDaSemana == 0 && time.diaDoMes == 0 && time.mes == 0 && time.ano == 0)
	{
		statusLeituraRelogio = semRelogio;
	}
	else
	{
		statusLeituraRelogio = comRelogio;
	}
}
//////////////////////////////////////////////////////////////////////////////////		
//metodo que transforma bcd para decimal                               			//
//////////////////////////////////////////////////////////////////////////////////
unsigned char transformaBcdParaDecimal(unsigned char valor)
{
    unsigned char valorTemp;
    valorTemp = valor;
    valorTemp = valorTemp >>4;
    valor = valor & 0b00001111;
    valorTemp = (valorTemp * 10) + valor;
    return valorTemp;
}
//////////////////////////////////////////////////////////////////////////////////		
//metodo que transforma decimal para bcd                               			//
//////////////////////////////////////////////////////////////////////////////////
unsigned char transformaDecimalParaBcd(unsigned char valor)
{
    unsigned char valorTemp;
    
    valorTemp = valor;
    valor = 0;
    while(valorTemp > 9)
    {
        valorTemp = valorTemp - 10;
        valor++;   
    }
    valorTemp = (valor * 16) + valorTemp;
    return valorTemp;
}       
        
