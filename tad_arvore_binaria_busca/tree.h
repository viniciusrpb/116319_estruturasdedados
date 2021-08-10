/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Arvores Binarias de Busca

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma arvore binaria de busca (ABB) em sua versao de alocacao dinamica e acesso encadeado

Arquivo do TAD ABB: tree.h (header file)

Como compilar:
                gcc trees.c main.c -o arvbin
Para executar:
                ./arvbin

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

struct info
{
    int chave;
};

typedef struct info Data;

typedef struct no Tree;

// Prototipo das funcoes
Tree ** cria_inicializa_Tree();

int ehVazia_Tree(Tree **root);

int insere_Tree(Tree **root, Data elem);

int insere_no_Tree(Tree *root, Tree *novo);

int remove_Arvore(Tree **root, Data elem);

int remove_no_Arvore_rec(Tree *root, Tree *dad, Data elem);

Tree * substituto_Arvore(Tree *no);

Tree * pai_no_mais_direita(Tree *no, Tree *dad);

void visit(Tree *no);

void caminha_InOrder_Tree(Tree **root);

void caminha_InOrder_Tree_rec(Tree *root);













