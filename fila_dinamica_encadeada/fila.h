/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

 Aula: Filas de alocação dinâmica e acesso encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma fila de alocação dinâmica e acesso encadeado

Arquivo do TAD Fila de alocação dinâmica e acesso encadeado: fila.h

Como compilar:
                gcc fila.c main.c -o queue
Para executar:
                ./queue

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

// Declaracao da estrutura de dados aqui, pois seus campos são utilizados 
// pelas funcoes do arquivo fila.c e fila.h. Portanto, o compilador
// deve "enxergar" as variaveis e tipos da estrutura para calcular o tamanho
// das variaveis

struct dados
{
    int chave;
};

// Define um tipo para struct dados
typedef struct dados Data;

struct no
{
    Data data;              // Campo de informação (dados) do nó
    struct no *prox;        // Endereço do nó sucessor para possibilitar o acesso encadeado
};
// Define o tipo de dados Fila
typedef struct no Fila;

// Prototipos das funcoes implementadas em fila.c
// Aqui fica somente a abstracao

void imprime(Fila **queue);

Fila ** cria_inicializa_Fila();

int enfileira(Fila **queue, Data elem);

int desenfileira(Fila **queue, Data *elem);

void libera(Fila **queue);

int ehVazia_Fila(Fila **queue);

