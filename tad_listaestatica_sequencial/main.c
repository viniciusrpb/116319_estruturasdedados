/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Listas de alocação estática e acesso sequencial

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma lista não-ordenada de alocação estática e acesso sequencial

Como compilar:
                gcc lista_est.c main.c -o listaest
Para executar:
                ./listaest

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include "lista_est.h"

int menu()
{
    int op=0, ok =0;


    while(!ok)
    {
        printf("\n\nLista de Alocacao Estatica e Acesso Sequencial\n\n");
	printf("Menu interativo - Opcoes\n");
        printf("(1) Criar e inicializar lista\n");
        printf("(2) Inserir elemento no começo\n");
        printf("(3) Inserir elemento no final\n");
	printf("(4) Remover elemento\n");
        printf("(0). SAIR.\n");
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

int main()
{
    
    int op = 0;         // tipo de operacao para ser usado no menu
    ListaEst *list;     // Declaracao da variavel que representara a lista estatica
    Data elem;          // Uso para leitura de elementos a serem inseridos/removidos
    
    do
    {
        op = menu();
        if(op == 1)
        {
            printf("Inicializando lista...\n");
            list = cria_inic_Lista();
        }
        if(op == 2)
        {
            printf("Digite o elemento a ser inserido no inicio: ");
            scanf("%d",&elem.chave);
            insere_inicio_Lista(list,elem);
        }
        if(op == 3)
        {
            printf("Digite o elemento a ser inserido no final: ");
            scanf("%d",&elem.chave);
            insere_ultimo_Lista(list,elem);
        }
        if(op == 4)
        {
            printf("Digite o elemento a ser removido: ");
            scanf("%d",&elem.chave);
            remove_Lista(list,elem);
        }
        
        // Toda que vez que uma operacao eh requerida, os elementos da lista são impressos
        imprime(list);
	
    }while(op);

    printf("Liberando lista da memória...\n");
    
    // Libera a variavel list ao final da execucao do programa
    libera(list);
    
    printf("Execução encerrada\n");

    // Indica ao Sistema Operacional que a execucao deste programa foi encerrada
    return 0;
}