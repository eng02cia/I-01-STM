
//////////////////////////////////////////////////////////////////////////////////		
//Menu qyue da acesso ao menus secundarios de programa��o                       //
//////////////////////////////////////////////////////////////////////////////////
void funcaoMenusConfiguraSerial_1(void)
{
    if (teclaPressionadaAtual == teclaZeroRetorna)
    {
        menuConfiguraSerial_1 = menuConfiguraSerial_1EmEspera;
        teclaPressionadaAtual = teclaSolta;
        flagInibeTeclaSolta = 1;

        telaAcessaMenuConfiguraSerial_1();
    } 
    switch (menuConfiguraSerial_1)
    {            
//////////////////////////////////////////////////////////////////////////////////
//configura a velocidade serial 1                                               //
//////////////////////////////////////////////////////////////////////////////////
        case defineVelocidadeSerial_1:
            switch (teclaPressionadaAtual)
            {
                case teclaTaraSetaEsquerda:   
                    teclaPressionadaAtual = teclaSolta;                              
                    velocidadeTxSerial_1 = velocidade1200Kbps;    
                    telaMostraProgVelocidadeSerial_1();                    
                    break;
                case teclaImprimeSetaAcima:
                    teclaPressionadaAtual = teclaSolta;                    
                    switch (velocidadeTxSerial_1)
                    {
                        case velocidade1200Kbps:
                            velocidadeTxSerial_1 = velocidade2400Kbps;
                            break;
                        case velocidade2400Kbps:
                            velocidadeTxSerial_1 = velocidade4800Kbps;
                            break;                            
                        case velocidade4800Kbps:
                            velocidadeTxSerial_1 = velocidade9600Kbps;
                            break;
                        case velocidade9600Kbps:
                            velocidadeTxSerial_1 = velocidade19200Kbps;
                            break;
                        case velocidade19200Kbps:
                            velocidadeTxSerial_1 = velocidade38400Kbps;
                            break;
                        case velocidade38400Kbps:
                            velocidadeTxSerial_1 = velocidade57600Kbps;
                            break;
                        case velocidade57600Kbps:
                            velocidadeTxSerial_1 = velocidade115200Kbps;
                            break;
                        case velocidade115200Kbps:
                            velocidadeTxSerial_1 = velocidade1200Kbps;
                            break;
                    }
                    telaMostraProgVelocidadeSerial_1();
                    break;   
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;
                    velocidadeTxSerial_1Mem = velocidadeTxSerial_1;
                    iniciaVariaveisTxSerial_1();
                    salvaStatusSaidaDadosSerial_1Mem();
                    tempConfigSerial = statusPortaSerial_1Mem;
                    menuConfiguraSerial_1 = definePortaSerial_1;
                    telaMostraTipoPortaSerial_1();

                break;
            }            
            break; 
//////////////////////////////////////////////////////////////////////////////////
//ativa desativa a transmis�o pela serial 1                                     //
//////////////////////////////////////////////////////////////////////////////////
        case ativaDesativaSerial_1:
            switch (teclaPressionadaAtual)
            {
                case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigSerial = 0;                
                    telaMostraAtivaDesativaSerial_1();                                       
                    break;
                case teclaImprimeSetaAcima:  
                    teclaPressionadaAtual = teclaSolta;                    
                    if (tempConfigSerial == 1){tempConfigSerial = 0;}
                    else{tempConfigSerial = 1;}
                    telaMostraAtivaDesativaSerial_1();            
                    break;            
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;  
                    statusComunicacaoSerial_1Mem = tempConfigSerial;
                    salvaStatusSaidaDadosSerial_1Mem();
                    tempConfigSerial = statusPortaSerial_1Mem;
                    menuConfiguraSerial_1 = definePortaSerial_1;
                    telaMostraTipoPortaSerial_1();

                    break;

            }            
            break;            
//////////////////////////////////////////////////////////////////////////////////
//seleciona a porta serial que sera usada  rs232 ou rs 485                      //
//////////////////////////////////////////////////////////////////////////////////
        case definePortaSerial_1:
            switch (teclaPressionadaAtual)
            {
                case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigSerial = 0; 
                    telaMostraTipoPortaSerial_1();            
                    break;                         
                case teclaImprimeSetaAcima:  
                    teclaPressionadaAtual = teclaSolta;                    
                    if (tempConfigSerial == 1){tempConfigSerial = 0;}
                    else{tempConfigSerial = 1;}
                    telaMostraTipoPortaSerial_1();            
                    break;            
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;  
                    statusPortaSerial_1Mem = tempConfigSerial;
                    salvaStatusSaidaPortaSerial_1Mem();
                    iniciaVariaveisTxSerial_1();
                    menuConfiguraSerial_1 = defineSaidaDadosSerial_1;
                    tempConfigSerial = statusSaidaDadosSerial_1Mem;
                    telaMostraTipoSaidaDadosSerial_1();
                    break;

            }            
            break;  
//////////////////////////////////////////////////////////////////////////////////
//define a forma da saida de dados serial 1                                     //
//////////////////////////////////////////////////////////////////////////////////
        case defineSaidaDadosSerial_1:
            switch (teclaPressionadaAtual)
            {
                case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigSerial = 0;
                    telaMostraTipoSaidaDadosSerial_1();            
                    break;                           
                case teclaImprimeSetaAcima: 
                    teclaPressionadaAtual = teclaSolta;                    
                    tempConfigSerial++;
                    if (tempConfigSerial == 3){tempConfigSerial = 0;}
                    telaMostraTipoSaidaDadosSerial_1();            
                    break;            
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;  
                    statusSaidaDadosSerial_1Mem = tempConfigSerial;
                    salvaStatusSaidaDadosSerial_1Mem();
                    tempConfigSerial = enderecoIndicadorMem;
                    menuConfiguraSerial_1 = defineEnderecoIndicadorSerial_1;
                    telaMostraEnderecoIndicador(); 
                    

                    break;
            }            
            break;                                   
//////////////////////////////////////////////////////////////////////////////////
//quando modbus-rtu ou Sigmacia SA define o endere�o do indicador de peso       //
//////////////////////////////////////////////////////////////////////////////////
        case defineEnderecoIndicadorSerial_1:
            switch (teclaPressionadaAtual)
            {
                case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigSerial = 1;
                    telaMostraEnderecoIndicador();            
                    break;                        
                case teclaImprimeSetaAcima: 
                    teclaPressionadaAtual = teclaSolta;
                    tempConfigSerial++;
                    if (tempConfigSerial == 99){tempConfigSerial = 1;}
                    telaMostraEnderecoIndicador();            
                    break;    
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;  
                    enderecoIndicadorMem = tempConfigSerial;
                    salvaEnderecoIndicadorMem();
                    tempConfigSerial = qtFramePorSegundoMem;
                    menuConfiguraSerial_1 = defineQtFramePorSegundoSerial_1;
                    telaMostraQtFramePorSegundo();


                    break;
            }            
            break;
//////////////////////////////////////////////////////////////////////////////////
//quando na transmiss�o continua define a quantidade de frames por segundo      //
//////////////////////////////////////////////////////////////////////////////////
        case defineQtFramePorSegundoSerial_1:
            switch (teclaPressionadaAtual)
            {
                case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigSerial = 1;                
                    telaMostraQtFramePorSegundo();            
                    break;                
                case teclaImprimeSetaAcima: 
                    teclaPressionadaAtual = teclaSolta;                    
                    tempConfigSerial++;
                    if (tempConfigSerial == 9){tempConfigSerial = 1;}
                    telaMostraQtFramePorSegundo();            
                    break;    
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;  
                    qtFramePorSegundoMem = tempConfigSerial;
                    salvaQtFramePorSegundoMem();
                    menuConfiguraSerial_1 = defineSaidaDadosSerial_2;
                    tempConfigSerial = statusSaidaDadosSerial_2Mem;
                    telaMostraTipoSaidaDadosSerial_2();                                       
                    break;
            }            
            break;
/////////////////////////////////////////////////////////////////////////////////
//define a forma da saida de dados serial 2                                     //
//////////////////////////////////////////////////////////////////////////////////
        case defineSaidaDadosSerial_2:
            switch (teclaPressionadaAtual)
            {
                case teclaTaraSetaEsquerda:                   
                    teclaPressionadaAtual = teclaSolta; 
                    tempConfigSerial = 0;
                    telaMostraTipoSaidaDadosSerial_2();            
                    break;                           
                case teclaImprimeSetaAcima: 
                    teclaPressionadaAtual = teclaSolta;                    
                    tempConfigSerial++;
                    if (tempConfigSerial == 2){tempConfigSerial = 0;}
                    telaMostraTipoSaidaDadosSerial_2();            
                    break;            
//tecla Ok
                case teclaSalva:
                    teclaPressionadaAtual = teclaSolta;  
                    statusSaidaDadosSerial_2Mem = tempConfigSerial;
                    salvaStatusSaidaDadosSerial_2Mem();
                    velocidadeTxSerial_1 = velocidadeTxSerial_1Mem;
                    menuConfiguraSerial_1 = defineVelocidadeSerial_1;
                    telaMostraProgVelocidadeSerial_1();                    
                    break;
            }            
            break;                              
    }
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra ativa desativa serial                                         	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraAtivaDesativaSerial_1(void)
{
    escreveDadoLcd(&charTelaAtivaDesativaSerial_1[0],&caracterLcd[0]);
    if (tempConfigSerial == _SERIAL_1ATIVADA){escreveDadoLcd(&charAtivado[0],&caracterLcd[25]);}
    else{escreveDadoLcd(&charDesativado[0],&caracterLcd[25]);}
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;     
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra ativa desativa serial                                         	//
//////////////////////////////////////////////////////////////////////////////////    
void telaMostraProgVelocidadeSerial_1(void)  
{

    escreveDadoLcd(&charTelaConfiguraVelocidadeSerial[0],&caracterLcd[0]);
    switch (velocidadeTxSerial_1)
    {
        case velocidade1200Kbps:
            escreveDadoLcd(&charVelocidade1200Kbps[0],&caracterLcd[23]);
            break;
        case velocidade2400Kbps:
            escreveDadoLcd(&charVelocidade2400Kbps[0],&caracterLcd[23]);
            break;                            
        case velocidade4800Kbps:
            escreveDadoLcd(&charVelocidade4800Kbps[0],&caracterLcd[23]);
            break;
        case velocidade9600Kbps:
            escreveDadoLcd(&charVelocidade9600Kbps[0],&caracterLcd[23]);
            break;
        case velocidade19200Kbps:
            escreveDadoLcd(&charVelocidade19200Kbps[0],&caracterLcd[23]);
            break;  
        case velocidade38400Kbps:
            escreveDadoLcd(&charVelocidade38400Kbps[0],&caracterLcd[23]);
            break;             
        case velocidade57600Kbps:
            escreveDadoLcd(&charVelocidade57600Kbps[0],&caracterLcd[23]);
            break;
        case velocidade115200Kbps:
            escreveDadoLcd(&charVelocidade115200Kbps[0],&caracterLcd[23]);
            break;
    }
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva; 
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra ativa desativa serial                                         	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraTipoPortaSerial_1(void)
{

    escreveDadoLcd(&charTelaEscolhePortaSerial_1[0],&caracterLcd[0]);
    if (tempConfigSerial == _RS232){escreveDadoLcd(&charRs232[0],&caracterLcd[16]);}
    if (tempConfigSerial == _RS485){escreveDadoLcd(&charRs485[0],&caracterLcd[16]);}  
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;     
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra a forma de saida de dados serial 2                              	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraTipoSaidaDadosSerial_1(void)
{
    escreveDadoLcd(&charTelaConfiguraVelocidadeSerial[0],&caracterLcd[0]);
    if (tempConfigSerial == _TRANSMISSAOCONTINUA_1){escreveDadoLcd(&charTcContinua_1[0],&caracterLcd[16]);}
	if (tempConfigSerial == _TRANSMISSAOCONTINUA_2){escreveDadoLcd(&charTcContinua_2[0],&caracterLcd[16]);}
    if (tempConfigSerial == _MODBUS_RTU){escreveDadoLcd(&charModBusRtu[0],&caracterLcd[16]);}
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;
}

//////////////////////////////////////////////////////////////////////////////////		
//tela mostra a forma de saida de dados serial 2                              	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraTipoSaidaDadosSerial_2(void)
{
    escreveDadoLcd(&charTelaFormaSaidaDadosSerial_2[0],&caracterLcd[0]);
    if (tempConfigSerial == _TRANSMISSAOCONTINUA_1){escreveDadoLcd(&charTcContinua_1[0],&caracterLcd[16]);}
    if (tempConfigSerial == _TRANSMISSAOCONTINUA_2){escreveDadoLcd(&charTcContinua_2[0],&caracterLcd[16]);}
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;     
}
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra o endere�o definido para a modbus-rtu e Sigmacia SA              	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraEnderecoIndicador(void)
{
    escreveDadoLcd(&charTelaEnderecoIndicadorSerial_1[0],&caracterLcd[0]);
    inteiroTo2BytesAscii(tempConfigSerial,&caracterLcd[25]);
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;     
} 
//////////////////////////////////////////////////////////////////////////////////		
//tela mostra a programa��o da quantidade de frames por segundo                	//
//////////////////////////////////////////////////////////////////////////////////
void telaMostraQtFramePorSegundo(void)
{
    escreveDadoLcd(&charTelaQtFramePorSegundo[0],&caracterLcd[0]);
    inteiroTo2BytesAscii(tempConfigSerial,&caracterLcd[25]);
    caracterLcd[29] = caracterRetorna;
    caracterLcd[30] = caracterIncremento;
    caracterLcd[31] = caracterSalva;     
} 

