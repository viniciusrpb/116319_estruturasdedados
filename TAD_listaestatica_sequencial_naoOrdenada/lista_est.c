/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Listas de alocação estática e acesso sequencial

Funcao deste programa: Implementa diversas operações definidas pelo tipo abstrato de dados de uma lista não-ordenada de alocação estática e acesso sequencial

Tipo Abstrato de Dados (TAD): TAD Lista Estática não-ordenada
     - Arquivo lista_est.c

Como compilar:
                gcc lista_est.c main.c -o listaest
Para executar:
                ./listaest

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UTF-8.
*/

// Inclusao do header lista estatica
#include "lista_est.h"

// Declaracao da estrutura que define a Lista Estatica Sequencial
struct listaest
{
    int fim;          // marca a primeira posicao livre na lista
    Data lista[MAX];  // a lista eh declarada como um vetor estatico
};


// Funcao que cria uma lista
ListaEst * cria_inic_Lista()
{
    ListaEst *novo;    // Define um ponteiro para uma Lista Estatica
                       // Esta variavel tem que ser ponteiro, pois
                       // faremos alteracoes nas variaveis que 
                       // compoe a estrutura
    // Aloca espaco em memoria para a variavel novo, que eh um ponteiro para ListaEst
    novo = (ListaEst *) malloc(sizeof(ListaEst));
    
    // Se a alocacao deu certo, inicializa a ListaEst
    if(novo != NULL)
    {
      novo->fim = 0;
    }
    
    // Retorna o endereco do bloco de memoria apontado pela variavel novo
    return novo;
}

// Funcao que verifica se a lista está cheia
int esta_cheia_ListaEst(ListaEst *l)
{
  if(l->fim > MAX-1)  // Se a lista estah cheia, isto eh, o fim da lista eh maior que MAX-1
  {
      return 1;
  }
  return 0;
}

// Funcao que verifica se a lista está vazia
int esta_vazia_ListaEst(ListaEst *l)
{
  if(l->fim < 1)  // Se a lista estah vazia, isto eh, o fim da lista eh igual a zero
  {
      return 1;
  }
  return 0;
}

// Funcao que libera espaco em memoria utilizado por uma variavel ponteiro para ListaEst
void libera(ListaEst *l)
{
    free(l);
}

// Imprime os elementos da lista estatica
void imprime(ListaEst *l)
{
    int i;       // Contador
    Data d;      // Variavel auxiliar
    
    if(l != NULL)
    {
	printf("\n\n\nLISTA\n");
	for(i = 0; i < l->fim;i++)
	{
	    d = l->lista[i];
	    printf("%d ",d.chave);
	}
	printf("\n\n\n\n");
    }
}

// Funcao que implementa a operacao de inserir um elemento no inicio da lista
// Data elem eh lido na funcao main
int insere_inicio_Lista(ListaEst *l, Data elem)
{
    
    int j;
    
    // Verifica se a lista existe
    if(l == NULL)
    {
	printf("ERRO: A lista nao existe\n");
	return -1;
    }
    
    // Verifica se a lista estah cheia
    if(esta_cheia_ListaEst(l) == 1)
    {
        return 0;
    }
    else
    {
	// Se eh possivel inserir
	
	// Verifica se a lista esta vazia
        if(esta_vazia_ListaEst(l) == 1)
        {
	    // Coloca o elemento na primeira posicao e atualiza o fim da lista
            l->lista[l->fim] = elem;
            l->fim++;
        }
        else
        {
	    // Senao deve-se inserir o elemento no inicio
	    // e deslocar todos os elementos em direcao ao final da lista
	    
            for(j = l->fim; j > 0; j--)
            {
                l->lista[j] = l->lista[j-1];
            }
            
            // Coloca o novo elemento no inicio da lista
            l->lista[j] = elem;
	    
	    // Atualiza o final da lista
            l->fim++;
        }
    }
    // Retorna 1 para sucesso
    return 1;
}

// Funcao que insere um novo elemento no final da lista
int insere_ultimo_Lista(ListaEst *l, Data elem)
{
    
    int i,j;
    
    // Verifica se a lista existe
    if(l == NULL)
    {
	printf("ERRO: A lista nao existe\n");
	return -1;
    }
    
    // Verifica se a lista estah cheia
    if(esta_cheia_ListaEst(l) == 1)
    {
        return 0;
    }
    else
    {
	// Coloca o elemento no final da lista
        l->lista[l->fim] = elem;
	
	// Atualiza o final da lista
        l->fim++;
    }
    
    // Retorna sucesso na operacao de insercao
    return 1;
} 

// Funcao que remove a primeira ocorrencia de um elemento na lista
int remove_Lista(ListaEst *l, Data elem)
{
    int i,j;
    
    // Verifica se a lista existe
    if(l == NULL)
    {
	printf("ERRO: A lista nao existe\n");
	return -1;
    }
    
    // Verifica se a lista esta vazia
    if(esta_vazia_ListaEst(l) == 1)
    {
        return 0;
    }
    else
    {
	// Realiza a busca pelo elemento na lista
        i = 0;
	
	// Tenta encontrar o elemento ao percorrer a lista do inicio até o final
        while(i < l->fim && l->lista[i].chave != elem.chave)
        {
            i++;
        }
        
        // Se a procura ultrapassou o final da lista, entao elemento não foi encontrado
        if(i == l->fim)
        {
            printf("Elemento não encontrado\n");
	    
	    // Retorna FALHA
            return 0;
        }
        else
        {
	    // Caso contrario, elemento foi encontrado
	    // Desloca todos os elementos da lista que aparecem após o elemento
	    // a ser removido
            for(j = i; j < l->fim;j++)
            {
                l->lista[j] = l->lista[j+1];
                
            }
            
            // Atualiza o final da lista
            l->fim--;
        }
    }
    
    // Retorna sucesso na remoção
    return 1;
}
