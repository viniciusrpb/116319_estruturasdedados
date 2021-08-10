/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Alocação dinâmica de matrizes

Funcao deste programa: Aloca dinamicamente uma matriz de inteiros em uma função e retorna o ponteiro para ponteiro desta matriz

Como compilar:
                gcc alocacao_din_matriz.c -o adm
Para executar:
                ./adm

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UFT-8.
*/

#include <stdio.h>      // Biblioteca de entrada e saida padrao
#include <stdlib.h>     // Biblioteca que implementa as funcoes malloc, sizeof e free

// Funcao que recebe as dimensoes (nro de linhas x nro de colunas) da matriz e retorna o seu endereco na memoria 
int **
alocaMatriz(int n, int m)
{
    int i,j;
    int **ma;           // variavel ponteiro para ponteiro que representa a matriz "dinamica"
    
    // Aloca o espaço em memoria para um vetor de ponteiros inteiros
    ma = (int **) malloc(sizeof(int *)*n);

    for(i = 0; i < n;i++)
    {
        // Para cada posicao do vetor de ponteiros, aloca um espaço em memória referente a um vetor.
        // Ao final, obtém-se uma matriz
        ma[i] = (int *) malloc(sizeof(int)*m);
        for(j = 0; j < m;j++)
        {
            // Preenche ma com valores aleatorios.. pode-se alterar para zero
            ma[i][j] = i*j + i + j;
        }
    }
    
    //Retorna o endereço da primeira posicao da matriz
    return ma;
}


// Funcao main
int main()
{
    
    int **matriz;      // Variavel da matriz "dinamica" na funcao main 
    int n,m,i,j;       // n e m sao as dimensoes da matriz

    // Pede ao usuario que digite a quantidade de linhas (n) e de colunas (m)
    printf("Nro de linhas: ");
    scanf("%d",&n);
    printf("Nro de colunas: ");
    scanf("%d",&m);

    // Chama a funcao que aloca o espaco em memoria para a matriz... retorna o endereco do primeiro elemento (matriz[0][0]) na memoria
    matriz = alocaMatriz(n,m);

    // Imprime a matriz
    for(i = 0; i < n;i++)
    {
        for(j = 0; j < m;j++)
        {
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
    
    // Mantra: para cada malloc, deve-se ter um free. Portanto libera-se o espaço em memoria de cada coluna
    for(i = 0; i < n;i++)
    {
        free(matriz[i]);
    }
    // Em seguida, libera o espaco em memoria da linha da matriz
    free(matriz);

    // Retorna ao Sistema Operacional que a execucao do programa foi bem sucedida
    return 0;
}
