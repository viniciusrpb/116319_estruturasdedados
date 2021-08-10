/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Alocação dinamica de memoria

Funcao deste programa: Ilustrar o uso de aritmética de ponteiros em vetores alocados dinamicamente em operações de
                       leitura e escrita de dados em vetores

Como compilar:
                gcc aritmetica_pont_vetor_dinamico.c -o pontarit
Para executar:
                ./pontarit

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UFT-8.
*/

// Biblioteca de entrada e saida padrao
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Ponteiro para inteiro que sera utilizado para apontar para um bloco de memoria
    // que armazenara um vetor por alocacao dinamica
    int *vetor,*inicioVetor;
    
    int i,tam;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam);
    
    // Aloca dinamicamente um vetor de inteiros
    // malloc retorna o endereço de memoria do bloco alocado
    vetor = (int *) malloc( sizeof(int)* tam);
    
    // inicioVetor aponta para a primeira posicao do vetor "dinamico"
    inicioVetor = vetor;
    
    // Realiza a leitura dos dados utilizando apenas aritmetica de ponteiros
    for(i = 0; i < tam;i++)
    {
        printf("Digite o elemento #%d do vetor (vetor[%d]): ",i,i);
        scanf("%d\n",vetor);
        
        // Passa para a proxima posicao do vetor, isto eh, para os proximos 4 bytes
        vetor++;               
    }
    
    // Repare que o procedimento realizado para leitura dos dados do vetor fez "perder" o inicio do vetor
    
    // Basta recuperar tal endereço que estava armazenado no ponteiro inteiro inicio
    vetor = inicio;
    
    // Imprime o vetor de inteiros utilizando apenas aritmética de ponteiros
    // mas agora, sem alterar o endereço de inicio do vetor
    for(i = 0; i < tam;i++)
    {
        printf("%d ",*(vetor+i));
    }
    printf("\n");
    
    // Para todo malloc, deve-se ter um free
    // Libera o espaço em memoria apontado pela variavel vetor
    free(vetor);
    
    // Indica ao Sistema Operacional que a execucao do programa foi encerrada
    return 0;
}
