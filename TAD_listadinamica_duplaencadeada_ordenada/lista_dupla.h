/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Listas de alocação dinamica e acesso encadeado

Funcao deste programa: Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma lista ordenada de alocação dinamica e acesso duplamente encadeado

Arquivo do TAD Lista Dinamica Duplamente Encadeada Ordenada: lista_dupla_ord.h (header file)

Como compilar:
                gcc lista_dupla_ord.c main.c -o listadupord
Para executar:
                ./listadupord

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

// Declaracao da estrutura de dados aqui, pois seus campos são utilizados 
// pelas funcoes do arquivo lista_dupla_ord.c e lista_dupla_ord.h. Portanto, o compilador
// deve "enxergar" as variaveis e tipos da estrutura para calcular o tamanho
// das variaveis
struct dados
{
    int chave;
};

// Define um tipo para struct dados
typedef struct dados Data;

// Define o tipo de dados ListaDin
typedef struct no ListaDinDupla;

// Prototipos das funcoes implementadas em lista_dupla_ord.c
// Aqui fica somente a abstracao

void imprime(ListaDinDupla **l);

ListaDinDupla ** cria_inicializa_Lista();

int insere_ordenado_Lista(ListaDinDupla **l, Data elem);

int remove_Lista(ListaDinDupla **l, Data elem);

void libera(ListaDinDupla **l);

int ehVazia_Lista(ListaDinDupla **l);
