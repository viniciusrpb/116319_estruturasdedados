/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Listas de alocação dinamica e acesso encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma lista não-ordenada de alocação dinamica e acesso encadeado

Arquivo: main.c  == serve apenas de interacao com o usuario a partir da apresentacao de um menu

Como compilar:
                gcc lista_din.c main.c -o listadin
Para executar:
                ./listadin

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include "lista_din.h"
#include <stdio.h>

int menu()
{
    int op=0, ok =0;


    while(!ok)
    {
        printf("\n\n\n\n\nLista Dinamica Encadeada - Opcoes\n\n");
        printf("(1) Criar e Inicializar lista\n");
        printf("(2) Inserir elemento no inicio\n");
        printf("(3) Inserir elemento ao final\n");
        printf("(4) Remover um elemento\n");
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
    ListaDin **lista;   // Declaracao da variavel que representara a lista estatica
    Data elem;          // Uso para leitura de elementos a serem inseridos/removidos     

    do
    {
	// Chama o menu
        op = menu();
	
        if(op == 1)
        {
            printf("Cria e inicializa a lista...\n");
            lista = cria_inicializa_Lista();
        }
        if(op == 2)
        {
            printf("Digite o elemento a ser inserido no inicio: ");
            scanf("%d",&elem.chave);
            insere_inicio_Lista(lista,elem);
        }
        if(op == 3)
        {
            printf("Digite o elemento a ser inserido no final: ");
            scanf("%d",&elem.chave);
            insere_ultimo_Lista(lista,elem);
        }
        if(op == 4)
        {
            printf("Digite o elemento a ser removido: ");
            scanf("%d",&elem.chave);
            remove_Lista(lista,elem);
        }
        
        imprime(lista);
	
    }while(op);
    
    printf("Liberando lista da memória...\n");
    
    libera(lista);
    
    printf("Execução encerrada.\n");    
    
    return 0;
}