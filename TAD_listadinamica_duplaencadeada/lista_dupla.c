/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Listas de alocação dinamica e acesso duplamente encadeado

Funcao deste programa: Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma lista ordenada de alocação dinamica e acesso duplamente encadeado

Arquivo do TAD Lista Dinamica Duplamente Encadeada Ordenada: lista_dupla_ord.c

Como compilar:
                gcc lista_dupla_ord.c main.c -o listadupord
Para executar:
                ./listadupord

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_dupla.h"

// Declaracao da estrutura de um nó dinamico
// Razao: os campos dos nós serão utilizados apenas no arquivo lista_duplamente_ord.c
struct no
{
    Data data;              // Campo de informação (dados) do nó
    struct no *prox;        // Endereço do nó sucessor
    struct no *ant;         // Endereço do nó antecessor
};

// Funcao que cria e inicializa uma lista
ListaDinDupla ** cria_inicializa_Lista()
{
    // Declara a lista dinamica encadeada como um ponteiro para ponteiro
    // Um ponteiro referente ao inicio da lista
    // o outro ponteiro se refere aos elementos (nos dinamicos da lista)
    ListaDinDupla **l;
    
    // Aloca um espaco em memoria para uma variavel ponteiro para ponteiro do tipo ListaDinDupla
    // Esta variavel eh o endereco da lista e armazena o endereco do primeiro nó (cabeça) da lista
    l = (ListaDinDupla **) malloc(sizeof(ListaDinDupla *));
    
    // Se a alocacao foi bem sucedida
    if(l != NULL)
    {
        // Inicializa a lista como NULL
        // isto eh, o inicio da lista aponta para NULL
        *l = NULL;
    }
    
    // Retorna o endereco da lista
    return l;
}

// Funcao que verifica se uma lista eh vazia
int ehVazia_Lista(ListaDinDupla **l)
{
    // Se o inicio da lista aponta para uma posicao NULL, entao a lista eh vazia
    if(*l == NULL)
    {
        return 1;    // Se a lista eh vazia, retorna 1
    }
    else
    {
        return 0;    // Se a lista nao eh vazia, retorna 0
    }
    
}

// Funcao que insere um novo elemento no inicio da lista
// Para o novo elemento, deve-se alocar um nó em tempo de execucao
// e coloca-lo como o primeiro nó da lista
int insere_ordenado_Lista(ListaDinDupla **l, Data elem)
{
    // Variavel que se refere ao novo nó a ser inserido no inicio da lista
    ListaDinDupla *novo;
    ListaDinDupla *aux;
    
    // Verifica se a lista existe
    if(l == NULL)
    {
        printf("ERRO: Lista nao existe\n");
        return -1;
    }
    
    // Aloca dinamicamente um novo nó 
    novo = (ListaDinDupla *) malloc (sizeof(ListaDinDupla));
    
    // Se a alocacao de memoria para o novo nó falhou
    if(novo == NULL)
    {
        printf("ERRO: Problemas ao alocar novo nó\n");
        return 0;
    }
    
    // Atribui o elem a ser inserido para o campo de dados do nó
    novo->data = elem;
    
    // Verifica se a lista eh vazia. Insercao em lista vazia
    if(*l == NULL)
    {
        // Se um, configura o unico no da lista
        novo->prox = NULL;
        novo->ant = NULL;
        
        // Primeiro no da lista passa a ser o novo no
        *l = novo;
	return 1;
    }
    
    //Se nao eh o primeiro elemento da lista
    aux = *l;
    
    // Verifica se insere no inicio da lista
    if(aux->data.chave >= elem.chave)
    {
        // O campo prox aponta para o primeiro no da lista
        novo->prox = aux;
        
        novo->ant = NULL;
        
        // O campo ant do primeiro no da lista aponta para o novo no
        aux->ant = novo;
        
        // Torna o novo no como o primeiro no da lista
        *l = novo;
        
        // Retorna sucesso
	return 1;
    }
    
    // Caminha pela lista ate encontrar o local de insercao do novo da lista
    // levando em conta que a lista estah ordenada
    while(aux->prox != NULL && aux->data.chave < elem.chave)
    {
	aux = aux->prox;
    }
    
    // Verifica em qual posicao da lista aux aponta
    if(aux->prox == NULL && aux->data.chave <= elem.chave)
    {
        // O novo noh deve ser o ultimo da lista...
	novo->prox = NULL;
        
        // O campo ant do novo noh aponta para o ultimo no da lista  
	novo->ant = aux;
        
        // Torna o novo no como sendo o ultimo da lista
	aux->prox = novo;
    }
    else
    {  
        // Neste else, a insercao deve ocorrer no meio da lista
        
        // O campo prox do novo no aponta para o no atual
	novo->prox = aux;
        // O campo ant do novo no aponta para o antecessor do no atual
	novo->ant = aux->ant;
        
        // O campo prox do antecessor do no atual aponta para o novo no
	(aux->ant)->prox = novo;
        
        // O antecessor do no atual eh o novo no
	aux->ant = novo;
        
        // Novo no faz parte da lista agora
    }
     
    // Inserção realizada com sucesso
    return 1;
}

// Funcao que remove a primeira ocorrencia de um elemento (elem) na lista
int remove_Lista(ListaDinDupla **l, Data elem)
{

    // Declara um no auxiliar que eh responsavel por caminhar pela lista e armazenar
    // o elemento a ser removido
    ListaDinDupla *aux;
    
    // Verifica se a lista existe
    if(l == NULL)
    {
        printf("ERRO: A lista nao foi criada\n");
        return -1;
    }
    
    // A inserção de uma lista no final envolve analisar duas situações
    // Verifica se a lista eh vazia
    if(*l == NULL)
    {
        printf("ERRO: a lista está vazia\n");
        return 0;
    }

    // Aux aponta para o primeiro nó da lista
    aux = *l;
    
    // Verifica se o primeiro elemento da lista eh o elemento a ser removido
    if(aux->data.chave == elem.chave)
    {
	// Caso positivo, atualiza *l (o primeiro nó da lista) como seu nó sucessor
        *l = (*l)->prox;
	
        // Se a lista contem mais de um elemento, o campo ant do no sucessor eh NULL
        if(aux->prox != NULL)
        {
            (aux->prox)->ant = NULL;
        }
        
	// Libera o nó contendo o elemento a ser removido
        free(aux);
	
	// Retorna sucesso na remoção
        return 1;
    }
    
    // Caso o elemento a ser removido nao esteja na cabeça, deve-se
    // percorrer a lista desde o segundo elemento até o final
    // isto eh, realizar um processo de busca
    
    // Para isso utiliza-se um No "anterior" que aponta sempre para o
    // nó antecessor do nó auxiliar
    //ant = aux;
    
    // O nó auxiliar, que no momento aponta para o primeiro nó da lista,
    // passa a apontar para o seu sucessor
    aux = aux->prox;
    
    // Percorre a lista até encontrar o elemento a ser removido ou
    // até alcançar o ultimo nó da lista
    while(aux->prox != NULL && aux->data.chave < elem.chave)
    {
        // Atualiza os nós analisados: o antecessor e o auxiliar
        aux = aux->prox;
    }

    // Ao sair do laço, verifica se o nó auxiliar tem chave igual à
    // chave do elemento a ser removido. Caso não tenha, retorna 
    if(aux->data.chave != elem.chave && aux->prox == NULL)
    {
        printf("ERRO: Elemento não encontrado.\n");
        return 0;
    }
    else
    {
        // Elemento encontrado: o campo prox do nó antecessor recebe o endereço 
        // do nó sucessor de aux
        if(aux->prox == NULL)
	{
            // Se eh o ultimo no, faz no prox de seu antecessor apontar para NULL
	    (aux->ant)->prox = NULL;
	}
	else
	{
            // Se nao eh o ultimo no
            // Faz o campo prox do antecessor apontar para o no sucessor do atual
	    (aux->ant)->prox = aux->prox;
            
            // Faz o campo ant do no sucessor apontar para o no anterior do atual 
	    (aux->prox)->ant = aux->ant;
	}
	
	// Libera o espaço em memoria ocupado pelo nó a ser removido
        free(aux);
    }
    
    // Sucesso na remocao
    return 1;
}

// Funcao que imprime uma lista dinamica encadeada
void imprime(ListaDinDupla **l)
{
    // Declara um no auxiliar
    ListaDinDupla *aux;
    
    // Verifica se a lista existe
    if(l != NULL)
    {
        // Se a lista existe
        
        // Verifica se a lista eh vazua
	if(ehVazia_Lista(l) == 0)
	{
	    // Se a lista nao eh vazia
	    printf("\n\n\nLISTA\n");
	    
	    // Aux aponta para a cabeça da lista
	    aux = *l;
	    
	    // Percorre a lista do inicio ateh o fim utilizando o No auxiliar
	    // para ler cada nó e evitar nao perder a cabeca da lista
	    while(aux->prox != NULL)
	    {
		printf("%d => ",aux->data.chave);
		aux= aux->prox;
	    }
	    printf("%d\n\n\n\n",aux->data.chave);
	}
	else
	{
	    printf("Lista esta vazia\n");
	}
    }
}

// Funcao que libera uma lista
void libera(ListaDinDupla **l)
{
    ListaDinDupla *aux;
 
    // Primeiramente verifica se a lista existe
    if(l != NULL)
    {
	// Enquanto não atingir o final da lista
        while(*l != NULL)
        {
	    // No auxiliar aponta para o primeiro nó da lista
	    aux = *l;
	    
	    // O primeiro nó da lista passa a ser o nó sucessor
            *l = (*l)->prox;
	    
	    // Libera o espaço de memória ocupado pelo nó
	    free(aux);
            
        }
        
        // Libera o espaço ocupado pelo ponteiro que remete ao inicio da lista
        free(l);
    }
    else
    {
        printf("Não liberou nada\n.");
    }
}


