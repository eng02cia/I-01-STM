//////////////////////////////////////////////////////////////////////////////////		
//                                                                            	//
//               Fun��es de cofigura��o do modulo rf hm trp                		//
//////////////////////////////////////////////////////////////////////////////////		
//fun��o que inicializa a cumuni��o com hmtrp           						//
//////////////////////////////////////////////////////////////////////////////////		
void InicializaHmTrpSerial_2 (void)
{
    TRISCbits.TRISC0 = 0;
    TRISCbits.TRISC1 = 0;
    TRISCbits.TRISC2 = 0;
 
    TRISAbits.TRISA6 = 0;
    TRISAbits.TRISA7 = 0;
    
    TRISCbits.TRISC4 = 0;
    TRISCbits.TRISC5 = 0;   

    PenableHmTrpSerial_2 = 0;
    Velocidade9600KbpsSerial_2();
    IniciaConfiguracaoHmTrpSerial_2();
}

//////////////////////////////////////////////////////////////////////////////////		
//Metodo que Inicia a configura��o do canal rf do HmTrp   						//
//////////////////////////////////////////////////////////////////////////////////
void IniciaConfiguracaoHmTrpSerial_2 (void)
{
    FlagIniciaConfiguracaoHmTrpSerial_2 = 1;
    PconfigHmTrpSerial_2 = 0; 
}
//////////////////////////////////////////////////////////////////////////////////		
//fun��o que controla a transmis�o do frame de peso pela serial 2				//
//////////////////////////////////////////////////////////////////////////////////		
void ControlaTxFramePesoSerial_2 (void)
{
    if (FlagTransmitindoSerial_2 == 0 & FlagRecebendoDadoSerial_1 == 1)
    {
        if (++TempoTransmiteFramePesoHmTrp > 19)
        {
            TempoTransmiteFramePesoHmTrp = 0; 
            FrameTxSerial_2 [0] = ' ';
            FrameTxSerial_2 [1] = DisplayPeso[0];
            FrameTxSerial_2 [2] = DisplayPeso[1];
            FrameTxSerial_2 [3] = DisplayPeso[2];
            FrameTxSerial_2 [4] = DisplayPeso[3];
            FrameTxSerial_2 [5] = DisplayPeso[4];
            FrameTxSerial_2 [6] = DisplayPeso[5];
            FrameTxSerial_2 [7] = DisplayPeso[6];
            FrameTxSerial_2 [8] = '\r';
            FrameTxSerial_2 [9] = '\n';
            QuantidadeBytesTxSerial_2 = 10;
            IndexTxSerial_2 = 0;
            TXREG2= FrameTxSerial_2[IndexTxSerial_2];
            QuantidadeBytesTxSerial_2--;
            IndexTxSerial_2++;
            FlagTransmitindoSerial_2 = 1;
            FlagTxSerial_2 = 1;
            TXSTA2bits.TXEN = 1;          
        }
    }       
}               
//////////////////////////////////////////////////////////////////////////////////		
//fun��o que controla a transmis�o de dados pela serial 2						//
//////////////////////////////////////////////////////////////////////////////////		
void ControleTxSerial_2 (void)
	{
	if (FlagTxSerial_2 == 1  & TXSTA2bits.TRMT2 == 1)
		{
		if (QuantidadeBytesTxSerial_2 == 0)
			{
			FlagTxSerial_2 = 0;
			FlagTransmitindoSerial_2 = 0;
			IndexTxSerial_2 = 0;
			}
		else
			{
			TXREG2= FrameTxSerial_2[IndexTxSerial_2];
			QuantidadeBytesTxSerial_2--;
			IndexTxSerial_2++;
			FlagTxSerial_2 = 1;
			}
		}	
	}
//////////////////////////////////////////////////////////////////////////////////		
//fun��o que carrega as configura��es do mudulo rf hm trp						//
//////////////////////////////////////////////////////////////////////////////////		
void ConfiguraCanalRfHmTrpSerial_2 (void)
	{
	ConverteEnderecoRfHmTrpSerial_2();
	FrameTxSerial_2[0] = 0xAA;
	FrameTxSerial_2[1] = 0xFA;
	FrameTxSerial_2[2] = 0xD2;
	FrameTxSerial_2[3] = RendCanalRf[0];
	FrameTxSerial_2[4] = RendCanalRf[1];
	FrameTxSerial_2[5] = RendCanalRf[2];
	FrameTxSerial_2[6] = RendCanalRf[3];
    
	QuantidadeBytesTxSerial_2 = 7;
	IndexTxSerial_2 = 0;
	TXREG2= FrameTxSerial_2[IndexTxSerial_2];
	QuantidadeBytesTxSerial_2--;
	IndexTxSerial_2++;
	FlagTransmitindoSerial_2 = 1;
	FlagTxSerial_2 = 1;
	TXSTA2bits.TXEN = 1;
	}
//////////////////////////////////////////////////////////////////////////////////		
//fun��o que converte o endere�o armazenado para o padr�o hmtrp					//
//////////////////////////////////////////////////////////////////////////////////		
void ConverteEnderecoRfHmTrpSerial_2 (void)
{
        PCanalRf_01 = 1;
        PCanalRf_02 = 1;
        PCanalRf_03 = 1;
        PCanalRf_04 = 1;
        PCanalRf_05 = 1;
	switch (EnderecoModuloHmTrpEep)
		{
        case 1:
		RendCanalRf[0] = 0x36;
		RendCanalRf[1] = 0x3D;
		RendCanalRf[2] = 0x7F;
		RendCanalRf[3] = 0x80;
        PCanalRf_01 = 0;
		break;
        
        case 2:
		RendCanalRf[0] = 0x36;
		RendCanalRf[1] = 0x89;
		RendCanalRf[2] = 0xCA;
		RendCanalRf[3] = 0xC0;
        PCanalRf_02 = 0;
		break;
        
        case 3:
		RendCanalRf[0] = 0x36;
		RendCanalRf[1] = 0xD6;
		RendCanalRf[2] = 0x16;
		RendCanalRf[3] = 0x00;
        PCanalRf_03 = 0;
        break;
        
        case 4:
		RendCanalRf[0] = 0x37;
		RendCanalRf[1] = 0x22;
		RendCanalRf[2] = 0x61;
		RendCanalRf[3] = 0x40;
        PCanalRf_04 = 0;
		break;	

        case 5:
		RendCanalRf[0] = 0x37;
		RendCanalRf[1] = 0x6E;
		RendCanalRf[2] = 0xAC;
		RendCanalRf[3] = 0x80;
        PCanalRf_05 = 0;
        break;
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//Habilita a serial 2 para transmitir com velocidade de 9600 kbps				//
//////////////////////////////////////////////////////////////////////////////////	
void Velocidade9600KbpsSerial_2(void)
{
	TXSTA2bits.BRGH = 1;
	RCSTA2bits.SPEN = 1;
	BAUDCON2bits.BRG16 = 1;
    SPBRGH2 = 6;
	SPBRG2 = 130;
}
//////////////////////////////////////////////////////////////////////////////////		
//Tempo Inicia configura��o HmTrp                           					//
//O pino de configura��o do hmtrp � acionado quando a tecla � pressionada       //
// e so depois de 100 mils que � iniciada a configura��o                        //
//////////////////////////////////////////////////////////////////////////////////	
void MetodoTempoIniciaConfiguracaoHmTrpSerial_2 (void)
{
    if (FlagIniciaConfiguracaoHmTrpSerial_2 == 1)
    {
        if (++TempoInicioConfiguracaoHmTrpSerial_2 > 10)
        {
            FlagIniciaConfiguracaoHmTrpSerial_2 = 0;
            ConfiguraCanalRfHmTrpSerial_2();
            TempoInicioConfiguracaoHmTrpSerial_2 = 0;
            FlagFinalizaConfiguracaoHmTrpSerial_2 = 1;            
        }
    }    
}
//////////////////////////////////////////////////////////////////////////////////		
//Tempo Finaliza configura��o HmTrp                           					//
//Depois que a configura��o do HmTrp � finalizada Espera um tempo antes de      //
// desabilitar o pino de configura��o                                           //
//////////////////////////////////////////////////////////////////////////////////	
void MetodoTempoFinalizaConfiguracaoHmTrpSerial_2 (void)
{
    if (FlagFinalizaConfiguracaoHmTrpSerial_2 == 1)
    {
        if (++TempoFinalizaConfiguracaoHmTrpSerial_2 > 50)
        {
            FlagFinalizaConfiguracaoHmTrpSerial_2 = 0;
            TempoFinalizaConfiguracaoHmTrpSerial_2 = 0;
            PconfigHmTrpSerial_2 = 1;  
            FlagConfigurandoCanalRfSerial_2 = 0;
        }
    }    
}
