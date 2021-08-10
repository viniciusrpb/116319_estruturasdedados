/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Filas de alocação dinâmica e acesso encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma fila de alocação dinâmica e acesso encadeado

Arquivo: main.c -- apenas um menu de interação

Como compilar:
                gcc fila.c main.c -o queue
Para executar:
                ./queue

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include "fila.h"
#include <stdio.h>

int menu()
{
    int op=0, ok =0;


    while(!ok)
    {
        printf("\n\n\n\n\nFila Dinamica Encadeada - Opcoes\n\n");
        printf("(1) Criar e Inicializar fila\n");
        printf("(2) Enfileirar elemento\n");
        printf("(3) Desenfileirar elemento\n");
        printf("(0) SAIR\n");
        printf("Digite a sua opcao: ");
        scanf("%d",&op);

        if(op < 0 || op > 3)
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
    Fila **queue;      // Declaracao da variavel que representa a fila
    Data elem;          // Uso para leitura de elementos a serem enfileirados/desenfileirados

    queue = NULL;
    
    do
    {
	// Chama o menu
        op = menu();
	
        if(op == 1)
        {
            printf("Cria e inicializa a fila...\n");
            queue = cria_inicializa_Fila();
        }
        if(op == 2)
        {
            printf("Digite o elemento a ser enfileirado: ");
            scanf("%d",&elem.chave);
            if(enfileira(queue,elem) == 1)
            {
                printf("Elemento %d enfileirado com sucesso\n",elem.chave);
            }
        }
        if(op == 3)
        {
            if(desenfileira(queue,&elem) == 1)
            {
                printf("O elemento desemfileirado foi %d\n",elem.chave);
            }
        }
        
        imprime(queue);

    }while(op);
    
    printf("Liberando fila da memória...\n");
    
    libera(queue);
    
    printf("Execução encerrada.\n");    
    
    return 0;
}