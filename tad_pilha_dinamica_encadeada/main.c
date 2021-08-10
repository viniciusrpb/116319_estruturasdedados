/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Pilhas de alocação dinâmica e acesso encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma pilha de alocação dinâmica e acesso encadeado

Arquivo: main.c  == serve apenas de interacao com o usuario a partir da apresentacao de um menu

Como compilar:
                gcc pilha.c main.c -o stack
Para executar:
                ./stack

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include "pilha.h"
#include <stdio.h>

int menu()
{
    int op=0, ok =0;


    while(!ok)
    {
        printf("\n\n\n\n\nPilha Dinamica Encadeada - Opcoes\n\n");
        printf("(1) Criar e Inicializar pilha\n");
        printf("(2) Empilha\n");
        printf("(3) Desempilha\n");
        printf("(4) Verifica o topo da pilha\n");
        printf("(0) SAIR\n");
        printf("Digite a sua opcao: ");
        scanf("%d",&op);

        if(op < 0 || op > 4)
        {
            printf("\nERRO: Opção inexistente\n");
            ok = 0;
        }
        else
        {
            ok = 1;
        }
    }
    return op;
}

// Funcao principal
int main()
{
    
    int op = 0;         // tipo de operacao para ser usado no menu
    Pilha **stack;      // Declaracao da variavel que representa a pilha
    Data elem;          // Uso para leitura de elementos a serem empihados/desempilhados

    stack = NULL;
    
    do
    {
	// Chama o menu
        op = menu();
	
        if(op == 1)
        {
            printf("Cria e inicializa a pilha...\n");
            stack = cria_inicializa_Pilha();
        }
        if(op == 2)
        {
            printf("Digite o elemento a ser empilhado: ");
            scanf("%d",&elem.chave);
            if(empilha(stack,elem) == 1)
            {
                printf("Elemento %d empilhado com sucesso\n",elem.chave);
            }
        }
        if(op == 3)
        {
            if(desempilha(stack,&elem) == 1)
            {
                printf("O elemento desempilhado foi %d\n",elem.chave);
            }
        }
        if(op == 4)
        {
            if(verificaTopo_Pilha(stack,&elem) == 1)
            {
                printf("O topo da pilha eh o elemento %d\n",elem.chave);
            }
        }

        imprime(stack);

    }while(op);
    
    printf("Liberando pilha da memória...\n");
    
    libera(stack);
    
    printf("Execução encerrada.\n");    
    
    return 0;
}