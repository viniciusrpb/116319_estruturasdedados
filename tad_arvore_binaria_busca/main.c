/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Arvores Binarias de Busca

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma arvore binaria de busca (ABB) em sua versao de alocacao dinamica e acesso encadeado

Arquivo: main.c

Como compilar:
                gcc trees.c main.c -o arvbin
Para executar:
                ./arvbin

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

// Arquivo main.c
#include <stdio.h>
#include "tree.h"

int main()
{
    Tree **root;
    Data info;
    
    root = cria_inicializa_Tree();
    // Inserindo o elemento de chave 8
    info.chave = 8;
    insere_Tree(root,info);
    // Inserindo o elemento de chave 3
    info.chave = 3;
    insere_Tree(root,info);
    // Inserindo o elemento de chave 0
    info.chave = 0;
    insere_Tree(root,info);
    // Inserindo o elemento de chave 15
    info.chave = 15;
    insere_Tree(root,info);
    // Inserindo o elemento de chave -4
    info.chave = -4;
    insere_Tree(root,info);
    // Inserindo o elemento de chave 6
    info.chave = 6;
    insere_Tree(root,info);
    // Inserindo o elemento de chave 1
    info.chave = 1;
    insere_Tree(root,info);
    // Inserindo o elemento de chave 10
    info.chave = 10;
    insere_Tree(root,info);
    // Inserindo o elemento de chave 4
    info.chave = 4;
    insere_Tree(root,info);
    
    printf("\nImpressao 1\n");
    caminha_InOrder_Tree(root);
    
    // Remove o elemento -4
    info.chave = -4;
    if(remove_Arvore(root,info) == 1)
    {
        printf("No %d removido\n",info.chave);
    }
    
     // Remove o elemento 3
    info.chave = 3;
    if(remove_Arvore(root,info) == 1)
    {
        printf("No %d removido\n",info.chave);
    }
    else
    {
        printf("Elemento %d nao encontrado\n",info.chave);
    }
    
     // Remove o elemento 15
    info.chave = 15;
    if(remove_Arvore(root,info) == 1)
    {
        printf("No %d removido\n",info.chave);
    }
    
     // Remove o elemento 8
    info.chave = 8;
    if(remove_Arvore(root,info) == 1)
    {
        printf("No %d removido\n",info.chave);
    }
    
    printf("\nImpressao 2\n");
    
    caminha_InOrder_Tree(root);
    printf("\n");

    return 0;
}