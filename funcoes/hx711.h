//////////////////////////////////////////////////////////////////////////////////
//funcoes de comunicao do o ad hx711                                           	//
//////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////
//inicializa os pinos para comunicacao com hx711                                //
//////////////////////////////////////////////////////////////////////////////////
void inicializaHx711(void)
{

}
//////////////////////////////////////////////////////////////////////////////////
//faz a leitura dos dados do sensor ad hx711                                    //
//////////////////////////////////////////////////////////////////////////////////
void readHx711(void)
{
    if (HAL_GPIO_ReadPin(GPIOB,pinoDataHx711_Pin) == 0)//indica que o hx 711 esta pronto
    {
        countReadHx711 = 24;
        while (countReadHx711 != 0)
        {
        	HAL_GPIO_WritePin(pinoClockHx711_GPIO_Port, pinoClockHx711_Pin,GPIO_PIN_SET);
            delayReadHx711();
            HAL_GPIO_WritePin(pinoClockHx711_GPIO_Port, pinoClockHx711_Pin,GPIO_PIN_RESET);
            if (HAL_GPIO_ReadPin(GPIOB,pinoDataHx711_Pin) == 0){rxDataBarramentoHx711.St.bit0 = 0;}
            if (HAL_GPIO_ReadPin(GPIOB,pinoDataHx711_Pin) == 1){rxDataBarramentoHx711.St.bit0 = 1;}
            hx711Temp = rxDataBarramentoHx711.Byte;
            rxDataBarramentoHx711.Byte = rxDataBarramentoHx711.Byte << 1;
            if (countReadHx711 == 17){arrayDataHx711[2] = hx711Temp;}
            if (countReadHx711 == 9){arrayDataHx711[1] = hx711Temp;}
            if (countReadHx711 == 1){arrayDataHx711[0] = hx711Temp;}            
            countReadHx711--;
        }
        HAL_GPIO_WritePin(pinoClockHx711_GPIO_Port, pinoClockHx711_Pin, GPIO_PIN_SET);
        delayReadHx711();
        HAL_GPIO_WritePin(pinoClockHx711_GPIO_Port, pinoClockHx711_Pin, GPIO_PIN_RESET);
//inverte resultado para complemento de 2
        arrayDataHx711[2] = ~ arrayDataHx711[2];
        arrayDataHx711[1] = ~ arrayDataHx711[1];
        arrayDataHx711[0] = ~ arrayDataHx711[0];
        hx711TipoPeso = _PESO_POSITIVO_CELULA_CARGA;
        hx711StatusSatura = _CELULA_CARGA_NAO_SATURADA;
//verifica se o a medicao esta saturada
//satura negativo
        if (arrayDataHx711[2] & 0x80)
        {
            arrayDataHx711[2] = 0xFF & arrayDataHx711[2];
            hx711StatusSatura = _CELULA_CARGA_SATURADA;
        } 
//satura positivo        
        if ((0x7F == arrayDataHx711[2]) && (0xFF == arrayDataHx711[1]) && (0xFF == arrayDataHx711[0]))
        {
            arrayDataHx711[2] =  0xFF & arrayDataHx711[2];
            hx711StatusSatura = _CELULA_CARGA_SATURADA;
        }
//verifica se medicao negativa da celula de carga
        if (arrayDataHx711[2] & 0x80)
        {
            arrayDataHx711[2] = ~ arrayDataHx711[2];
            arrayDataHx711[1] = ~ arrayDataHx711[1];
            arrayDataHx711[0] = ~ arrayDataHx711[0]; 
            hx711TipoPeso = _PESO_NEGATIVO_CELULA_CARGA;
        }
//CONVERTE PARA 32 BITS
        conversaoTipos.array4[0] = arrayDataHx711[0];
        conversaoTipos.array4[1] = arrayDataHx711[1];
        conversaoTipos.array4[2] = arrayDataHx711[2];
        conversaoTipos.array4[3] = 0;
        dataAdHx711 = conversaoTipos.int32;            
        if (hx711TipoPeso == _PESO_NEGATIVO_CELULA_CARGA){dataAdHx711 *= -1;} 
        hx711StatusCelulaCarga = _comCelulaDeCarga;
        if (dataAdHx711 >= -30000 && dataAdHx711 <= 30000) 
        {
            hx711StatusCelulaCarga = _semCelulaDeCarga;
        }
    }    
}
//////////////////////////////////////////////////////////////////////////////////
//faz a leitura dos dados do sensor ad hx711                                    //
//////////////////////////////////////////////////////////////////////////////////
void delayReadHx711(void)
{
    delayHx711 = 5;
    while (delayHx711!=0){delayHx711--;}
}

//////////////////////////////////////////////////////////////////////////////////
//armazena teste de leituras do ad                                              //
//////////////////////////////////////////////////////////////////////////////////
void testeLeituraAd(void)
{
    /*
    switch (loopTesteAd)
    {
        case 0:
            ad1 = dataAdHx711;
            loopTesteAd++;            
            break;
        case 1:
            ad2 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 2:
            ad3 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 3:
            ad4 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 4:
            ad5 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 5:
            ad6 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 6:
            ad7 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 7:
            ad8 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 8:
            ad9 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 9:
            ad10 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 10:
            ad11 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 11:
            ad12 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 12:
            ad13 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 13:
            ad14 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 14:
            ad15 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 15:
            ad16 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 16:
            ad17 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 17:
            ad18 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 18:
            ad19 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 19:
            ad20 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 20:
            ad21 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 21:
            ad22 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 22:
            ad23 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 23:
            ad24 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 24:
            ad25 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 25:
            ad26 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 26:
            ad27 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 27:
            ad28 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 28:
            ad29 = dataAdHx711;
            loopTesteAd++; 
            break;            
        case 29:
            ad30 = dataAdHx711;
            loopTesteAd++; 
            break;        
        case 30:
            ad31 = dataAdHx711;
            loopTesteAd++; 
            break;          
        case 31:
            ad32 = dataAdHx711;
            loopTesteAd++; 
            break; 
        case 32:
            ad33 = dataAdHx711;
            loopTesteAd++; 
            break;                
        case 33:
            ad34 = dataAdHx711;
            loopTesteAd++; 
            break;                
        case 34:
            ad35 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 35:
            ad36 = dataAdHx711;
            loopTesteAd++; 
            break;                
        case 36:
            ad37 = dataAdHx711;
            loopTesteAd++; 
            break;                
        case 37:
            ad38 = dataAdHx711;
            loopTesteAd++; 
            break;
        case 38:
            ad39 = dataAdHx711;
            loopTesteAd++; 
            break; 
        case 39:
            ad40 = dataAdHx711;
            loopTesteAd++; 
            break;   
       case 40:
            ad41 = dataAdHx711;
            loopTesteAd++; 
            break; 
       case 41:
            ad42 = dataAdHx711;
            loopTesteAd++; 
            break;                
       case 42:
            ad43 = dataAdHx711;
            loopTesteAd++; 
            break;                
       case 43:
            ad44 = dataAdHx711;
            loopTesteAd++; 
            break;                
       case 44:
            ad45 = dataAdHx711;
            loopTesteAd++; 
            break;   
        case 45:
            ad46 = dataAdHx711;
            loopTesteAd++; 
            break;               
       case 46:
            ad47 = dataAdHx711;
            loopTesteAd++; 
            break;                
       case 47:
            ad48 = dataAdHx711;
            loopTesteAd++; 
            break;
       case 48:
            ad49 = dataAdHx711;
            loopTesteAd++; 
            break; 
       case 49:
            ad50 = dataAdHx711;
            loopTesteAd = 0; 
            break;                
    }
*/   
}
