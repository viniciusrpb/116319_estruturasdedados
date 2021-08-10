/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Listas de alocação dinamica e acesso encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma lista não-ordenada de alocação dinamica e acesso encadeado

Arquivo do TAD Lista Dinamica Encadeada Nao-Ordenada: lista_din.c

Como compilar:
                gcc lista_din.c main.c -o listadin
Para executar:
                ./listadin

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include <stdio.h>
#include <stdlib.h>
#include "lista_din.h"

// Declaracao da estrutura de um nó dinamico
// Razao: os campos dos nós serão utilizados apenas no arquivo lista_din.c
struct no
{
    Data data;              // Campo de informação (dados) do nó
    struct no *prox;        // Endereço do nó sucessor para possibilitar o acesso encadeado
};

// Funcao que cria e inicializa uma lista
ListaDin ** cria_inicializa_Lista()
{
    // Declara a lista dinamica encadeada como um ponteiro para ponteiro
    // Um ponteiro referente ao inicio da lista
    // o outro ponteiro se refere aos elementos (nos dinamicos da lista)
    ListaDin **l;
    
    // Aloca um espaco em memoria para uma variavel ponteiro para ponteiro do tipo ListaDin
    // Esta variavel eh o endereco da lista e armazena o endereco do primeiro nó (cabeça) da lista
    l = (ListaDin **) malloc(sizeof(ListaDin *));
    
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
int ehVazia_Lista(ListaDin **l)
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
int insere_inicio_Lista(ListaDin **l, Data elem)
{
    // Variavel que se refere ao novo nó a ser inserido no inicio da lista
    ListaDin *novo;
    
    // Verifica se a lista existe
    if(l == NULL)
    {
        printf("ERRO: Inserção falhou devido a um problema na lista\n");
        return -1;
    }
    
    // Aloca dinamicamente um novo nó 
    novo = (ListaDin *) malloc (sizeof(ListaDin));
    
    // Se a alocacao de memoria para o novo nó falhou
    if(novo == NULL)
    {
        printf("ERRO: Problemas ao alocar novo nó\n");
        return 0;
    }
    
    // Atribui o elem a ser inserido para o campo de dados do nó
    novo->data = elem;
    
    // Atribui ao campo prox do novo nó o primeiro nó da lista
    novo->prox = *l;
    
    // Atualiza o primeiro nó da lista para o novo nó
    *l = novo;
    
    // Inserção realizada com sucesso
    return 1;
}


int insere_ultimo_Lista(ListaDin **l, Data elem)
{
    
    // Variavel que se refere ao novo nó a ser inserido no inicio da lista
    ListaDin *novo;
    
    // Declara um no auxiliar
    ListaDin *aux;
    
    // Verifica se a lista existe
    if(l == NULL)
    {
        printf("ERRO: Inserção falhou devido a um problema na lista\n");
        return 0;
    }
    
    // Aloca dinamicamente um novo nó 
    novo = (ListaDin *) malloc (sizeof(ListaDin));
    
    // Atribui o elem a ser inserido para o campo de dados do nó
    novo->data = elem;
    
    // Se a alocacao de memoria para o novo nó falhou
    if(novo == NULL)
    {
        printf("ERRO: Problemas ao alocar novo nó\n");
        return 0;
    }
    
    // A inserção de uma lista no final envolve analisar duas situações
    // Se a lista eh vazia
    if(*l == NULL)
    {
	// O primeiro no da lista eh o proprio novo nó
        *l = novo;
	
	// Insercao realizada com sucesso
        return 1;
    }
    else
    {
	// Utiliza o no auxiliar para percorrer a lista
	// Lembrete: o uso do de *l para percorrer a lista resulta na perda do primeiro nó
	//           original da lista
	
	// Aux aponta para o primeiro no da lista
        aux = *l;
	
	// Enquanto nao alcançar o ultimo nó da lista, caminhar pela lista
        while(aux->prox != NULL)
        {
            aux = aux->prox;
        }
        
        // Chegamos ao final da lista.
        // O campo prox do novo nó é NULL (neste caso, aux->prox)
        novo->prox = aux->prox;
	
	// O campo prox do ultimo nó da lista agora aponta para o novo nó
        aux->prox = novo;
	
	// Inserção realizada com sucesso
        return 1;
    }
}

// Funcao que remove a primeira ocorrencia de um elemento (elem) na lista
int remove_Lista(ListaDin **l, Data elem)
{

    // Declara um no auxiliar que eh responsavel por caminhar pela lista e armazenar
    // o elemento a ser removido
    ListaDin *aux;
    
    // Declara um segundo no auxiliar que possui o endereço de nó anterior ao nó aux
    ListaDin *ant;
    
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
    ant = aux;
    
    // O nó auxiliar, que no momento aponta para o primeiro nó da lista,
    // passa a apontar para o seu sucessor
    aux = aux->prox;
    
    // Percorre a lista até encontrar o elemento a ser removido ou
    // até alcançar o ultimo nó da lista
    while(aux->prox != NULL && aux->data.chave != elem.chave)
    {
        // Atualiza os nós analisados: o antecessor e o auxiliar
        aux = aux->prox;
        ant = ant->prox;
    }

    // Ao sair do laço, verifica se o nó auxiliar tem chave igual à
    // chave do elemento a ser removido. Caso não tenha, retorna 
    if(aux->data.chave != elem.chave)
    {
        printf("ERRO: Elemento não encontrado.\n");
        return 0;
    }
    else
    {
        // Elemento encontrado: o campo prox do nó antecessor recebe o endereço 
        // do nó sucessor de aux
        ant->prox = aux->prox;
	
	// Libera o espaço em memoria ocupado pelo nó a ser removido
        free(aux);
    }
    
    // Sucesso na remocao
    return 1;
}

// Funcao que imprime uma lista dinamica encadeada
void imprime(ListaDin **l)
{
    // Declara um no auxiliar
    ListaDin *aux;
    
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
void libera(ListaDin **l)
{
    ListaDin *aux;
 
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


