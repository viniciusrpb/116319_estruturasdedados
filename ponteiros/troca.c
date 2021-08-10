/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Ponteiros

Funcao deste programa: Troca o valor de duas variaveis inteiras utilizando ponteiros

Como compilar:
                gcc troca.c -o troca
Para executar:
                ./troca

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UFT-8.
*/

// Biblioteca de entrada e saida padrao
#include <stdio.h>

// Funcao que realiza a troca
void troca(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}

// Funcao principal
int main()
{

    // Declaracao de variaveis
    int a,b;

    a = 2;
    b = 8;

    printf("Antes: A: %d B: %d\n",a,b);
    
    // Chama a funcao que troca os dois elementos
    troca(&a,&b);

    printf("Depois: A: %d B: %d\n",a,b);
    
    // Indica ao Sistema Operacional que a execucao do programa foi bem sucedida
    return 0;
}