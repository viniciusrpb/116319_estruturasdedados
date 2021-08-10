/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Pilhas de alocação dinâmica e acesso encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma pilha de alocação dinâmica e acesso encadeado

Arquivo do TAD Pilha de alocação dinâmica e acesso encadeado: pilha.h (header file)

Como compilar:
                gcc pilha.c main.c -o stack
Para executar:
                ./stack

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

// Declaracao da estrutura de dados aqui, pois seus campos são utilizados 
// pelas funcoes do arquivo pilha.c e pilha.h. Portanto, o compilador
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
// Define o tipo de dados Pilha
typedef struct no Pilha;

// Prototipos das funcoes implementadas em pilha.c
// Aqui fica somente a abstracao

void imprime(Pilha **stack);

Pilha ** cria_inicializa_Pilha();

int empilha(Pilha **stack, Data elem);

int desempilha(Pilha **stack, Data *elem);

void libera(Pilha **stack);

int ehVazia_Pilha(Pilha **stack);

int verificaTopo_Pilha(Pilha **stack, Data *elem);
