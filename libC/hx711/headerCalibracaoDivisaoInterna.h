//////////////////////////////////////////////////////////////////////////////////		
//Fun��es de programa��o do peso do corte                                       //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de fun��es
void controleCalibraIndicador(void);

//telas                                   {"VALOR DIVISAO   ""                "};

//variaveis utilizadas

//indica qual o menu atual que esta sendo Acessado
enum 
{  
    menuAjustaValorDivisao,
    menuAjustaValorDivisaoEmEspera, 
}menuAjustaValorDivisao = menuAjustaValorDivisaoEmEspera;
//gerencia a manipula��o dos digitos de um algarimos durante a programa��o
enum
{
    digitoZero,
    digitoUm,
    digitoDois,
    digitoTres,   
    digitoQuatro,
    digitoCinco,
    digitoSeis,
    digitoSete,
    digitoOito,
    digitoNove,    
}digitoAtualDivisao = digitoZero;

//flags utilizados na programa��o

