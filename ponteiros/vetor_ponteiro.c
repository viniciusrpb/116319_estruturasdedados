/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Alocação dinamica de memoria

Funcao deste programa: Ilustrar o uso de aritmética de ponteiros em vetores
                       nas operações de leitura e escrita de dados em vetores

Como compilar:
                gcc vetor_ponteiro.c -o vetpont
Para executar:
                ./vetpont

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UFT-8.
*/

// Biblioteca de entrada e saida padrao
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declara um vetor de inteiros
    int vetor[] = {7,6,5,4,3};
    int *pont_vetor;
    
    int i;
    
    // o ponteiro inteiro aponta para a variavel vetor, isto eh, para o endereço da primeira posicao do vetor[]
    pont_vetor = vetor;
    
    // Imprime o vetor de inteiros utilizando apenas aritmética de ponteiros
    printf("Impressão dos valores iniciais do vetor: \n");
    for(i = 0; i < 5;i++)
    {
        printf("%d ",*(pont_vetor++));
    }
    printf("\n\n\n");
    
     // Atualiza pont_vetor para a primeira posicao do vetor
    pont_vetor = vetor;
    
    printf("Leitura de novos dados para o vetor: \n");
    // Realiza a leitura dos dados utilizando apenas aritmetica de ponteiros
    for(i = 0; i < 5;i++)
    {
        printf("Digite o elemento vetor[%d]: ",i);
        scanf("%d",pont_vetor);
        
        // Passa para a proxima posicao do vetor, isto eh, para os proximos 4 bytes
        pont_vetor++;               
    }
    
    // Imprime o vetor de inteiros utilizando apenas aritmética de ponteiros
    // mas agora, sem alterar o endereço de inicio do vetor
    for(i = 0; i < 5;i++)
    {
        printf("%d ",*(vetor+i));
    }
    printf("\n");
    
    // Indica ao Sistema Operacional que a execucao do programa foi encerrada
    return 0;
}
