//////////////////////////////////////////////////////////////////////////////////		
//Funções de programação do peso do corte                                       //
//////////////////////////////////////////////////////////////////////////////////
//prototipos de funções
void controleCalibraIndicador(void);

//telas                                   {"VALOR DIVISAO   ""                "};

//variaveis utilizadas

//indica qual o menu atual que esta sendo Acessado
enum 
{  
    menuAjustaValorDivisao,
    menuAjustaValorDivisaoEmEspera, 
}menuAjustaValorDivisao = menuAjustaValorDivisaoEmEspera;
//gerencia a manipulação dos digitos de um algarimos durante a programação
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

//flags utilizados na programação

