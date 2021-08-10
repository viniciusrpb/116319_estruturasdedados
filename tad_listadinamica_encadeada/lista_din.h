/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Listas de alocação dinamica e acesso encadeado

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma lista não-ordenada de alocação dinamica e acesso encadeado

Arquivo do TAD Lista Dinamica Encadeada Nao-Ordenada: lista_din.h (header file)

Como compilar:
                gcc lista_din.c main.c -o listadin
Para executar:
                ./listadin

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

// Declaracao da estrutura de dados aqui, pois seus campos são utilizados 
// pelas funcoes do arquivo lista_din.c e lista_din.h. Portanto, o compilador
// deve "enxergar" as variaveis e tipos da estrutura para calcular o tamanho
// das variaveis
struct dados
{
    int chave;
};

// Define um tipo para struct dados
typedef struct dados Data;

// Define o tipo de dados ListaDin
typedef struct no ListaDin;

// Prototipos das funcoes implementadas em lista_din.c
// Aqui fica somente a abstracao

void imprime(ListaDin **l);

ListaDin ** cria_inicializa_Lista();

int insere_inicio_Lista(ListaDin **l, Data elem);

int insere_ultimo_Lista(ListaDin **l, Data elem);

int remove_Lista(ListaDin **l, Data elem);

void libera(ListaDin **l);

int ehVazia_Lista(ListaDin **l);
