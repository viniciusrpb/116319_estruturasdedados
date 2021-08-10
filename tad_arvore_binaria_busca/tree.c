/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Arvores Binarias de Busca

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma arvore binaria de busca (ABB) em sua versao de alocacao dinamica e acesso encadeado

Arquivo do TAD ABB: tree.c

Como compilar:
                gcc trees.c main.c -o arvbin
Para executar:
                ./arvbin

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

// Arquivo tree.c
#include <stdlib.h>
#include <stdio.h>
#include "tree.h"

struct no
{
    Data data;
    struct no *esq;
    struct no *dir;
};

Tree ** cria_inicializa_Tree()
{
    Tree **novo;
    // Cria um novo endereco para a raiz da arvore
    novo = (Tree **) malloc (sizeof(Tree *));
    // Se alocacao deu certo
    if(novo != NULL)
    {
        // Inicializa a arvore (uma arvore vazia)
        *novo = NULL;
    }
}

int ehVazia_Tree(Tree **root)
{
    if(root != NULL)
    {
        if(*root == NULL)
        {
            return 1; // eh vazia
        }
        else
        {
            return 0; // nao eh vazia
        }
    }
    return -1; // nao existe
}

int insere_Tree(Tree **root, Data elem)
{
    Tree *novo_no;
    
    if(root == NULL)
    {
        return -1; // A arvore nao existe
    }
    
    novo_no = (Tree *) malloc (sizeof(Tree));
    if(novo_no == NULL)
    {
        return -1; // Alocacao falhou
    }
    // Preenchendo o novo no
    novo_no->data = elem;
    novo_no->esq = NULL;
    novo_no->dir = NULL;
    
    if(ehVazia_Tree(root) == 1)
    {
        *root = novo_no;
        return 1;
    }
    
    return insere_no_Tree(*root,novo_no);
}

int insere_no_Tree(Tree *root, Tree *novo)
{
    // evita repeticoes
    if(root->data.chave == novo->data.chave)
    {
        return 0;
    }
    // Chave do elemento < chave da raiz?
    if(novo->data.chave < root->data.chave)
    {
        //Sim? Vou para a sub-arvore esquerda
        if(root->esq == NULL)
        {
            root->esq = novo;
            return 1;
        }
        else
        {
            // Nao! Existe uma sub-arvore esquerda
            // Caminha para a sub-arvore esquerda
            return insere_no_Tree(root->esq,novo);
        }
    }
    else
    {
        // Verifica se a sub-arvore direita existe
        if(root->dir == NULL)
        {
            // Se nao existe sub-arvore direita
            root->dir = novo;
            return 1;
        }
        else
        {
            // Sim! Existe uma sub-arvore direita
            // Caminha para a sub-arvore direita
            return insere_no_Tree(root->dir,novo);
        }
    }
}

// Funcao que visita um no
void visit(Tree *no)
{
    printf(" %d ",no->data.chave);
}

void caminha_InOrder_Tree(Tree **root)
{
    if(root != NULL)
    {
        caminha_InOrder_Tree_rec(*root);
    }
    printf("\n");
}

void caminha_InOrder_Tree_rec(Tree *root)
{
    // Criterio de parada da recursao
    if(root == NULL)
    {
        return ;
    }
    caminha_InOrder_Tree_rec(root->esq);
    visit(root);
    caminha_InOrder_Tree_rec(root->dir);
}


int remove_Arvore(Tree **root, Data elem)
{
    Tree *aux;
    
    // Se arvore existe
    if(root == NULL)
    {
	return -1;
    }
    
    // Se arvore eh vazia
    if(*root == NULL)
    {
	return -1;
    }
    
    // Verifica se o no da raiz eh o no a ser removido
    if((*root)->data.chave == elem.chave)
    {
        // Salva o no raiz
	aux = *root;
        // Encontra um no da ABB para substituir o no raiz e que preserva
        // as propriedades ABB
	*root = substituto_Arvore(*root);
        
        // Ajusta as subarvores esquerda e direita do novo no raiz
	(*root)->esq = aux->esq;
	(*root)->dir = aux->dir;
        
        // Libera o antigo no raiz da memoria
	free(aux);
        
        // Sucesso na remocao
	return 1;
    }
    else
    {
        // Verifica se o no a ser removido estah em alguma subarvore
        // Leva o endereco do no pai (no comeco eh o proprio no raiz)
	if(elem.chave < (*root)->data.chave)
	{
	    return remove_no_Arvore_rec((*root)->esq,*root,elem);
	}
	else
	{
	    return remove_no_Arvore_rec((*root)->dir,*root,elem);
	}
    }   
}

// Funcao que remove um no da arvore que nao esteja na raiz
int remove_no_Arvore_rec(Tree *root, Tree *dad, Data elem)
{

    Tree *substituto;
    Tree *aux_free;
    
    // Se root eh null, chave de busca nao existe na arvore
    if(root == NULL)
    {
        return 0;
    }

    // Se o no atual da arvore eh o no a ser removido
    if(root->data.chave == elem.chave)
    {
        // Procura um no substituto
	substituto = substituto_Arvore(root);

        // Se o substituto existir, isto eh, se o no a ser removido nao eh folha
        if(substituto != NULL)
        {
            // Verifique se o caso 3 eh aplicado, isto eh, se eh o no removido
            // possui subarvores esquerda e direita. Se sim, tais subarvores
            // sao filhas do novo no substituto
            if(root->esq != NULL && root->dir != NULL)
            {
                substituto->dir = root->dir;
                substituto->esq = root->esq;
            }
        }

        // Verifica se o no a ser removido eh o no filho esquerdo ou direito do no pai
	if(dad->dir == root)
	{
            // Se o filho direito do pai serah removido, entao atualiza o novo no filho direito
	    dad->dir = substituto;
	}
	else
	{
            // Se o filho esquerdo do pai serah removido, entao atualiza o novo no filho esquerdo
	    dad->esq = substituto;
	}
	
	// Libera o no root da memoria
	aux_free = root;
	free(aux_free);
        
        // Retorna sucesso
	return 1;
    }
    
    // Continua a caminhar pelos nos mais profundos da arvore
    if(elem.chave > root->data.chave)
    {
	return remove_no_Arvore_rec(root->dir,root,elem);
    }
    else
    {
	return remove_no_Arvore_rec(root->esq,root,elem);
    }
}

// Funcao que obtem um no substituto para um no que serah removido
Tree * substituto_Arvore(Tree *no)
{
    // Endereco do no pai em relacao a um no
    Tree *dad;
    
    // Endereco do novo no a ser posicionado no local onde ocorrera a remocao de algum no
    Tree *novo;

    // CASO 1: O no a ser removido eh folha?
    if(no->esq == NULL && no->dir == NULL)
    {
        // Se sim, basta remover o no, nao havera substituto
	return NULL;
    }
    
    // CASO 2.1: O no a ser removido tem apenas a subarvore direita?
    if(no->esq == NULL)
    {
        // Retorna o endereco da subarvore direita
	return no->dir;
    }
    // CASO 2.2: O no a ser removido tem apenas a subarvore esquerda?
    if(no->dir == NULL)
    {
        // Retorna o endereco da subarvore esquerda
	return no->esq;
    }
    
    /* CASO 3: O no a ser removido possui sub-arvores esquerda e direita
          Deve-se procurar o no substituto, que pode ser:
          1) O no mais profundo a direita da sub-arvore esquerda do no a ser removido
          2) O no mais profundo a esquerda da sub-arvore direita do no a ser removido
          
          A opcao 1 eh implementada aqui!!!
    */
    
    // Procura pelo pai do no mais profundo a direita da sub-arvore esquerda do no a ser removido
    dad = pai_no_mais_direita(no->esq,no);
    //printf("DAD: %d\n",dad->data.chave);
    
    // Precisamos do no pai para ficar mais facil de atualizar a sua nova sub-arvore direita
    novo = dad->dir;
    
    // A sub-arvore direita do no pai eh o no filho esquerdo do no substituto
    dad->dir = novo->esq;
    
    // Retorna o endereco do novo no
    return novo;    
}

// Funcao que retorna o no pai do no mais profundo a direita da subarvore esquerda
Tree * pai_no_mais_direita(Tree *no, Tree *dad)
{  
    // Encontrou o no mais profundo a direita da subarvore esquerda, mas esse no
    // possui um filho esquerdo
    if(no->dir == NULL)
    {
        // Retorna o endereco do pai
	return dad;
    }
   
    // Senao caminha um nivel mais profundo na ABB
    return pai_no_mais_direita(no->dir,no);
}

