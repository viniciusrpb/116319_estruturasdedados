/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Listas de alocação dinamica e acesso duplamente encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma lista ordenada de alocação dinamica e acesso duplamente encadeado

Arquivo: main.c  == serve apenas de interacao com o usuario a partir da apresentacao de um menu

Como compilar:
                gcc lista_dupla_ord.c main.c -o listadupord
Para executar:
                ./listadupord

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include "lista_dupla.h"
#include <stdio.h>

int menu()
{
    int op=0, ok =0;


    while(!ok)
    {
        printf("\n\n\n\n\nLista Dinamica Duplamente Encadeada (Ordenada) - Opcoes\n\n");
        printf("(1) Criar e Inicializar lista\n");
        printf("(2) Inserir elemento ordenado\n");
        printf("(3) Remover um elemento\n");
        printf("(0) SAIR\n");
        printf("Digite a sua opcao: ");
        scanf("%d",&op);

        if(op < 0 || op >3)
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
    ListaDinDupla **lista;   // Declaracao da variavel que representara a lista estatica
    Data elem;          // Uso para leitura de elementos a serem inseridos/removidos     

    lista = NULL;
    
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
            printf("Digite o elemento a ser inserido ordenado: ");
            scanf("%d",&elem.chave);
            insere_ordenado_Lista(lista, elem);
        }
        if(op == 3)
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