/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Filas de alocação dinâmica e acesso encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma fila de alocação dinâmica e acesso encadeado

Arquivo do TAD Fila de alocação dinâmica e acesso encadeado: fila.c

Como compilar:
                gcc fila.c main.c -o queue
Para executar:
                ./queue

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

// Declaracao da estrutura de um nó dinamico
// Razao: os campos dos nós serão utilizados apenas no arquivo fila.c

// Funcao que cria e inicializa uma fila
Fila ** cria_inicializa_Fila()
{
    // Declara a fila dinamica encadeada como um ponteiro para ponteiro
    // Um ponteiro referente ao inicio da fila
    // o outro ponteiro se refere aos elementos (nos dinamicos da fila)
    Fila **nova_fila;
    
    // Aloca um espaco em memoria para uma variavel ponteiro para ponteiro do tipo Fila
    // Esta variavel eh o endereco da fila e armazena o endereco do primeiro nó da fila
    nova_fila = (Fila **) malloc(sizeof(Fila *));
    
    // Se a alocacao foi bem sucedida
    if(nova_fila != NULL)
    {
        // Inicializa a fila como NULL
        // isto eh, o primeiro no da fila eh NULL - nao existe (ainda)
        *nova_fila = NULL;
    }
    
    // Retorna o endereco da fila
    return nova_fila;
}

// Funcao que verifica se uma fila eh vazia
int ehVazia_Fila(Fila **queue)
{
    if(queue == NULL)
    {
        return -1;
    }
    
    // Se o primeiro no da fila aponta para NULL, entao a fila eh vazia
    if(*queue == NULL)
    {
        return 1;    // Se a fila eh vazia, retorna 1
    }
    else
    {
        return 0;    // Se a fila nao eh vazia, retorna 0
    }
    
}

// Funcao que insere um novo elemento no topo da fila
// Para o novo elemento, deve-se alocar um nó em tempo de execucao
// e coloca-lo no topo da fila (como o primeiro nó de uma lista dinamica encadeada)
int enfileira(Fila **queue, Data elem)
{
    // Variavel que se refere ao novo nó a ser inserido no topo da fila
    Fila *novo;
    
    Fila *aux;
    
    // Verifica se a fila existe
    if(queue == NULL)
    {
        printf("ERRO: A fila nao existe\n");
        return -1;
    }
    
    // Aloca dinamicamente um novo nó 
    novo = (Fila *) malloc (sizeof(Fila));
    
    // Se a alocacao de memoria para o novo nó falhou
    if(novo == NULL)
    {
        printf("ERRO: Problemas ao alocar novo nó\n");
        return 0;
    }
    
    // Atribui o elem a ser inserido para o campo de dados do nó
    novo->data = elem;
    
    // Como a insercao na fila eh no final, coloca campo prox do
    // novo no como sendo NULL
    novo->prox = NULL;
    
    // Verifica se a fila eh vazia
    if(*queue == NULL)
    {
        // Atualiza o primeiro no da fila para o novo nó
        *queue = novo;
    }
    else
    {
        aux = *queue;
        // Percorre a fila ate encontrar o ultimo no. Insercao sempre
        // ocorre no final
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        
        // Faz o novo no ser o ultimo no da lista
        aux->prox = novo;
    }
    
    // Retorna Inserção realizada com sucesso
    return 1;
}

// Funcao que desenfileira um elemento da fila, isto eh, remove o primeiro elemento da fila
int desenfileira(Fila **queue, Data *elem)
{
    // Declara um no auxiliar que eh responsavel por receber o primeiro elemento da fila
    Fila *aux;
    
    // Verifica se a fila existe
    if(queue == NULL)
    {
        printf("ERRO: A fila nao foi criada\n");
        return -1;
    }
    
    // Verifica se a fila eh vazia
    if(*queue == NULL)
    {
        printf("ERRO: a fila está vazia\n");
        return 0;
    }
    
    // aux aponta para o primeiro no da fila
    aux = *queue;

    // salva o primeiro elemento da fila
    *elem = aux->data;
    
    // O segundo no da fila passa ser o primeiro no da fila
    *queue = (*queue)->prox;
	
    // Libera o nó desenfileirado
    free(aux);
	
    // Retorna sucesso na remoção
    return 1;
}

// Funcao que imprime uma fila dinamica encadeada
// utilizando apenas operacoes de emfilar e desemfilar
void imprime(Fila **queue)
{
    // Declara uma fila auxiliar
    Fila **aux;
    
    // Ajuda ao receber os elementos desemfilados e serve tambem para emfilar elementos
    Data elem;
    
    if(queue != NULL)
    {
        // Cria e inicializa a fila auxiliar
        aux = cria_inicializa_Fila();
        
        // Desenfileira elemento por elemento da fila e enfileira cada um na fila auxiliar
        printf("\n\n\nINICIO =>");
        while(*queue != NULL)
        {
            desenfileira(queue,&elem);
            printf("=> %d  ",elem.chave);
            enfileira(aux,elem);
        }
        printf("\n");
        // Reconstroi a fila original queue
        while(*aux != NULL)
        {
            // tira da fila o primeiro elemento
            desenfileira(aux,&elem);
            
            // enfileira o elemento na fila original
            enfileira(queue,elem);
        }
        
        // Libera a fila auxiliar da memoria
        libera(aux);
    }
}

// Funcao que libera uma fila
void libera(Fila **queue)
{
    Fila *aux;
    Data elem;
    
    // Desenfileira todos os elementos da fila
    if(queue != NULL)
    {
        while(*queue != NULL)
        {
            if(!desenfileira(queue,&elem))
            {
                printf("ERRO: erro ao desenfileirar elemento\n");
                return ;
            }
        }
        
        // Apaga o endereco de inicio da fila
        free(queue);
    }
}


