/* Universidade de Brasilia (UnB)
   Departamento de Ciencia da Computacao (CIC)
   116319 - Estruturas de Dados
   Prof. Dr. Vinicius R. P. Borges
   Data: 30/05/2019 
   
   
   Template de TAD LADAE ordenada para resolver problemas em Juizes On-line 
   
   Para compilar:
       gcc template_ladaeordenada.c -o binario
       
   Para executar:
       ./binario
       
   Obs.: para verificar possiveis vazamentos de memoria, digite na linha de comando:
   
        valgrind --leak-check=full ./binario
*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int elem;
    struct node *prox;
};

typedef struct node LADAE;

LADAE** cria_LADAE()
{
    LADAE **nova;
    
    nova = (LADAE **) malloc (sizeof(LADAE *));

    *nova = NULL;

    return nova;
}

int ehVazia_LADAE(LADAE **inicio)
{
    if(*inicio == NULL)
        return 1;
    return 0;
}

int existe_LADAE(LADAE **inicio)
{
    if(inicio == NULL)
        return 0;
    return 1;
}

int remove_LADAE(LADAE **lista, int x)
{
    LADAE *aux,*ant;
    
    if(existe_LADAE(lista) == 0 || ehVazia_LADAE(lista) == 1)
    {
        return 0;
    }
    else
    {
        aux = *lista;
        if(aux->elem == x)
        {
            *lista = (*lista)->prox;
            free(aux);
        }
        else
        {
            ant = aux;
            aux = aux->prox;
            while(aux->prox != NULL && x > aux->elem)
            {
                ant=ant->prox;
                aux=aux->prox;
            }
            if(aux->elem != x)
            {
                return 0;
            }
            else
            {
                if(aux->prox == NULL)
                {
                    ant->prox = NULL;
                }
                else
                {
                    ant->prox = aux->prox;
                }
                
                free(aux);
            }
        }

    }
    return 1;
}

int insere_LADAE(LADAE **lista, int valor)
{
    LADAE *nodo,*aux,*ant;

    nodo = (LADAE *) malloc(sizeof(LADAE));
    nodo->elem = valor;
    nodo->prox = NULL;
    
    if(ehVazia_LADAE(lista) == 1)
    {
        *lista = nodo;
    }
    else
    {
        aux = *lista;
        if(valor < aux->elem)
        {
            nodo->prox = aux;
            *lista = nodo;
        }
        else
        {
            if(aux->prox == NULL)
            {
                aux->prox = nodo;
            }
            else
            {
                ant = aux;
                aux=aux->prox;
                while(aux->prox != NULL && valor >= aux->elem)
                {
                    aux=aux->prox;
                    ant=ant->prox;
                }
                
                if(aux->prox != NULL || aux->elem >= valor)
                {
                    ant->prox = nodo;
                    nodo->prox = aux;
                }
                else
                {
                    aux->prox = nodo;
                }
            }
        }        
    }
    return 1;
}

void libera_LADAE(LADAE **lista)
{   
    LADAE *aux;
    
    while(ehVazia_LADAE(lista) == 0)
    {
        aux = *lista;
        *lista = (*lista)->prox;
        free(aux);
    }
    free(lista);
    lista = NULL;
}

void imprime_LADAE(LADAE **lista)
{   
    LADAE *aux = *lista;
    
    while(aux != NULL)
    {
        printf("%d ",aux->elem);
        aux = aux->prox;
    }
    printf("\n");
}


int main()
{
    LADAE **lista;
    
    lista = cria_LADAE();
    
    insere_LADAE(lista,4);
    
    remove_LADAE(lista,4);
    
    libera_LADAE(lista);

    return 0;
}