/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Listas de alocação estática e acesso sequencial

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma lista não-ordenada de alocação estática e acesso sequencial

Tipo Abstrato de Dados (TAD): TAD Lista Estática não-ordenada
     - Arquivo lista_est.h

Como compilar:
                gcc lista_est.c main.c -o listaest
Para executar:
                ./listaest

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

// Declaracao da estrutura dados.
// Esta declarada aqui porque vamos utiliza-la diretamente na funcao main e
// nas funções do arquivo lista_est.h
struct dados
{
    int chave;
};

// Define o tipo de dados Data
typedef struct dados Data;

// Define o tipo ListaEst
typedef struct listaest ListaEst;

// Protótipo das funcoes implementadas em lista_est.c

ListaEst * cria_inic_Lista();

int esta_cheia_ListaEst(ListaEst *l);

int esta_vazia_ListaEst(ListaEst *l);

void libera(ListaEst *l);

int remove_Lista(ListaEst *l, Data elem);

int insere_inicio_Lista(ListaEst *l, Data elem);

int insere_ultimo_Lista(ListaEst *l, Data elem);

void imprime(ListaEst *l);





