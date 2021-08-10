/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Ponteiros e estruturas

Funcao deste programa: Ilustrar o uso de ponteiros em dados estruturados. Basicamente, realize leitura/escrita e impressao
                       de valores de uma estrutura de maneira indireta, isto é, utilizando ponteiros.

Como compilar:
                gcc struct_ponteiro.c -o stpont
Para executar:
                ./stpont

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UFT-8.
*/

// Biblioteca de entrada e saida padrao
#include <stdio.h>

// Declaracao da estrutura item
struct item
{
    char tipo;
    int ano;
    float peso;
};

// Definicao de um tipo de dados Item
typedef struct item Item;

// Funcao principal
int main()
{
    // Variavel do tipo Item
    Item produto;
    
    // Variavel ponteiro para Item
    Item *ponteiro;
    
    // Ponteiro aponta para produto
    // Eh importante lembrar que, structs não são ponteiros constantes, como ocorrem em vetores e matrizes
    ponteiro = &produto;

    // Realiza operações de leitura e escrita de maneira indireta utilizando o ponteiro para Item
    printf("Digite o tipo (N-Neutro;P-Perfumado): ");
    
    /* Notacao para a leitura de um dado e escrita em um dos campos da estrutura:
                    (*ponteiro).tipo serve para acessar o conteúdo que está em tipo, como se
                    estivéssemos trabalhando com uma variavel char normalmente.
                    Agora para realizar a escrita no campo da struct, utiliza-se o operador &
                    da mesma maneira que quando se quer ler um valor char.
    */
    scanf("%c",&(*ponteiro).tipo);
    
    scanf("%*c");             // operacao para ler e descartar o <enter>
    
    printf("Digite o ano: ");
    scanf("%d",&(*ponteiro).ano);
    
    printf("Digite o peso: ");
    scanf("%f",&(*ponteiro).peso);

    // Informacoes do item inserido    
    printf("\nItem inserido\nTipo: %c\nAno: %d\nPeso: %.2f\n",(*ponteiro).tipo,(*ponteiro).ano,(*ponteiro).peso);

    // Indica ao Sistema Operacional que a execucao do programa foi encerrada
    return 0;
}