/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Pilhas de alocação dinâmica e acesso encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma pilha de alocação dinâmica e acesso encadeado

Arquivo do TAD Pilha de alocação dinâmica e acesso encadeado: pilha.c

Como compilar:
                gcc pilha.c main.c -o stack
Para executar:
                ./stack

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

// Declaracao da estrutura de um nó dinamico
// Razao: os campos dos nós serão utilizados apenas no arquivo pilha.c



// Funcao que cria e inicializa uma pilha
Pilha ** cria_inicializa_Pilha()
{
    // Declara a pilha dinamica encadeada como um ponteiro para ponteiro
    // Um ponteiro referente ao topo da pilha
    // o outro ponteiro se refere aos elementos (nos dinamicos da pilha)
    Pilha **nova_pilha;
    
    // Aloca um espaco em memoria para uma variavel ponteiro para ponteiro do tipo Pilha
    // Esta variavel eh o endereco da pilha e armazena o endereco do primeiro nó (topo) da pilha
    nova_pilha = (Pilha **) malloc(sizeof(Pilha *));
    
    // Se a alocacao foi bem sucedida
    if(nova_pilha != NULL)
    {
        // Inicializa a pilha como NULL
        // isto eh, o topo da pilha aponta para NULL
        *nova_pilha = NULL;
    }
    
    // Retorna o endereco da pilha
    return nova_pilha;
}

// Funcao que verifica se uma pilha eh vazia
int ehVazia_Pilha(Pilha **stack)
{
    if(stack == NULL)
    {
        return -1;
    }
    
    // Se o topo  da pilha aponta para uma posicao NULL, entao a pilha eh vazia
    if(*stack == NULL)
    {
        return 1;    // Se a pilha eh vazia, retorna 1
    }
    else
    {
        return 0;    // Se a pilha nao eh vazia, retorna 0
    }
    
}


// Funcao que verifica se uma pilha eh vazia
int verificaTopo_Pilha(Pilha **stack, Data *elem)
{
    // Verifica se a pilha existe e nao eh vazia
    if(stack == NULL)
    {
        return -1;    // Se a pilha nao existe, retorna -1
    }
    
    
    if(ehVazia_Pilha(stack) == 1)
    {
        return 0;    // Se a pilha eh vazia, retorna 0
    }
    else
    {
        // Se a pilha nao eh vazia
        
        // Faz elem apontar para o topo da pilha
        *elem = (*stack)->data;
        
        // Retorna sucesso
        return 1;
    }
    
}

// Funcao que insere um novo elemento no topo da pilha
// Para o novo elemento, deve-se alocar um nó em tempo de execucao
// e coloca-lo no topo da pilha (como o primeiro nó de uma lista dinamica encadeada)
int empilha(Pilha **stack, Data elem)
{
    // Variavel que se refere ao novo nó a ser inserido no topo da pilha
    Pilha *novo;
    
    // Verifica se a pilha existe
    if(stack == NULL)
    {
        printf("ERRO: A pilha nao existe\n");
        return -1;
    }
    
    // Aloca dinamicamente um novo nó 
    novo = (Pilha *) malloc (sizeof(Pilha));
    
    // Se a alocacao de memoria para o novo nó falhou
    if(novo == NULL)
    {
        printf("ERRO: Problemas ao alocar novo nó\n");
        return 0;
    }
    
    // Atribui o elem a ser inserido para o campo de dados do nó
    novo->data = elem;
    
    // Atribui ao campo prox do novo nó o atual topo da pilha
    novo->prox = *stack;
    
    // Atualiza o topo da pilha para o novo nó
    *stack = novo;
    
    // Retorna Inserção realizada com sucesso
    return 1;
}

// Funcao que desempilha um elemento da pilha, isto eh, remove o elemento do topo da pilha
int desempilha(Pilha **stack, Data *elem)
{

    // Declara um no auxiliar que eh responsavel por receber o elemento do topo da pilha
    Pilha *aux;
    
    // Verifica se a pilha existe
    if(stack == NULL)
    {
        printf("ERRO: A pilha nao foi criada\n");
        return -1;
    }
    
    // A inserção de uma pilha no final envolve analisar duas situações
    // Verifica se a pilha eh vazia
    if(*stack == NULL)
    {
        printf("ERRO: a pilha está vazia\n");
        return 0;
    }
    
    aux = *stack;

    // Aux aponta para o topo da pilha
    *elem = aux->data;
    
    // Caso positivo, atualiza o topo da pilha para o seu sucessor do nó do topo
    *stack = (*stack)->prox;
	
    // Libera o nó desempilhado
    free(aux);
	
    // Retorna sucesso na remoção
    return 1;
}

// Funcao que imprime uma pilha dinamica encadeada
// utilizando apenas operacoes de empilhar e desempilhar
void imprime(Pilha **stack)
{
    // Declara um no auxiliar
    Pilha **aux;
    
    // Ajuda ao receber os elementos desempilhados e serve tambem para empilhar elementos
    Data elem;
    
    // Variavel para ajudar a imprimir a pilha de maneira simpatica
    int i = 0;
    
    if(stack != NULL)
    {
        // Cria e inicializa a pilha auxiliar
        aux = cria_inicializa_Pilha();
        
        // Desempilha elemento por elemento da pilha e empilha cada um na pilha auxiliar
        printf("\n\n\nTOPO =>");
        while(*stack != NULL)
        {
            if(i)
            {
                printf("\n");
            }
            desempilha(stack,&elem);
            printf("\t %d  ",elem.chave);
            empilha(aux,elem);
            i++;
        }
        printf("\t<= BASE\n");

        // Reconstroi a pilha original stack
        while(*aux != NULL)
        {
            // desempilha o topo da Pilha auxiliar
            desempilha(aux,&elem);
            
            // Empilha em stack o elemento desempilhado em aux 
            empilha(stack,elem);
        }
        
        // Libera a pilha auxiliar da memoria
        libera(aux);
    }
}

// Funcao que libera uma pilha
void libera(Pilha **stack)
{
    Pilha *aux;
    Data elem;
    
    // Desempilha todos os elementos da pilha
    // Vale lembrar que ao desempilhar o elemento do topo
    // o espaco em memoria jah eh liberado
    if(stack != NULL)
    {

        while(*stack != NULL)
        {
            if(!desempilha(stack,&elem))
            {
                printf("ERRO: erro ao desempilhar elemento\n");
                return ;
            }
        }
        
        // Apaga o endereco de inicio da pilha
        free(stack);
    }
}


