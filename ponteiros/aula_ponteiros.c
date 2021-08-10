/*
 * Universidade de Brasília
 * Departamento de Ciência da Computação
 * 116319 - Estruturas de Dados
 * Prof. Dr. Vinicius Ruela Pereira Borges

Aula: Ponteiros

Funcao deste programa: Ilustrar a utilizacao de ponteiros variaveis

Como compilar:
                gcc aula_ponteiros.c -o aula_ponteiros
Para executar:
                ./aula_ponteiros

Código-fonte testado no GCC 5.4.0, no Linux. Codificação-padrão deste arquivo é UFT-8.
*/

// Biblioteca de entrada e saida padrao
#include <stdio.h>

// Funcao principal
int main()
{

    // Declaracao das variaveis
    
    // Variavel do tipo inteiro
    int var1;
    
    // Variavel do tipo ponteiro inteiro
    int *pont;
    
    // Variavel do tipo ponteiro para ponteiro inteiro
    int **pont_pont;
    
    var1 = 12;
    
    // A variavel pont aponta para a variavel var1: pont possui o endereco de memoria de var1
    pont = &var1;
    
    // Apenas imprime o codigo-fonte
    printf("/* INICIO DO CODIGO-FONTE */\n\n#include <stdio.h>\n\nint main()\n{\n    int var1;\n    int *pont;\n    int **pont_pont;\n\n    var1 = 12;\n\n    /*Imprime variaveis 1*/\n\n    *pont=18;\n\n    /*Imprime variaveis 2*/\n\n    pont_pont = &pont;\n\n    /*Imprime variaveis 3*/\n\n    *pont = 4;\n\n    /*Imprime variaveis 4*/\n\n    **pont_pont = 0;\n\n    /*Imprime variaveis 5*/\n\n    return 0;\n}\n\n/* FIM DO CODIGO-FONTE */\n");
    printf("(Pressione <Enter> para continuar...)\n");
    scanf("%*c");
    
    // Imprime as variaveis apos realizar pont = &var1
    printf("\n\n\t\t Imprime variaveis 1 => após fazer pont = &var1\n\n");
    printf("Variavel var1\n var1 = %d ; &var1 = %p\n\n",var1,&var1);
    printf("Variavel *pont\n pont = %p ; *pont = %d; &pont = %p\n\n",pont,*pont,&pont);
    printf("(Pressione <Enter> para continuar...)\n");
    scanf("%*c");
    
    // Altera o conteudo do endereco existente em pont para 18, isto eh, altera-se indiretamente o valor de var1
    *pont = 18;
    
    // Imprime as variaveis apos realizar *pont = 18
    printf("\n\n\t\t Imprime variaveis 2 => após fazer *pont = 18\n\n");
    printf("Variavel var1\n var1 = %d ; &var1 = %p\n\n",var1,&var1);
    printf("Variavel *pont\n pont = %p ; *pont = %d; &pont = %p\n\n",pont,*pont,&pont);
    printf("(Pressione <Enter> para continuar...)\n");
    scanf("%*c");
    
    *pont_pont = pont;
    
    // Altera o conteudo do endereco existente em pont para 18, isto eh, altera-se indiretamente o valor de var1
    printf("\n\n\t\t Imprime variaveis 3 => após fazer pont_pont = &pont\n\n");
    printf("Variavel var1\n var1 = %d ; &var1 = %p\n\n",var1,&var1);
    printf("Variavel *pont\n pont = %p ; *pont = %d; &pont = %p\n\n",pont,*pont,&pont);
    printf("Variavel **pont_pont\n pont_pont = %p ; *pont_pont = %p; **pont_pont = %d; &pont_pont = %p\n\n",pont_pont,*pont_pont,**pont_pont,&pont_pont);
    printf("(Pressione <Enter> para continuar...)\n");
    scanf("%*c");
    
    // Atribui o valor 4 para a variavel var1 de maneira indireta utilizando ponteiro
    *pont = 4;
    
    printf("\n\n\t\t Imprime variaveis 4\n\n");
    printf("Variavel var1\n var1 = %d ; &var1 = %p\n\n",var1,&var1);
    printf("Variavel *pont\n pont = %p ; *pont = %d; &pont = %p\n\n",pont,*pont,&pont);
    printf("Variavel **pont_pont\n pont_pont = %p ; *pont_pont = %p; **pont_pont = %d; &pont_pont = %p\n\n",pont_pont,*pont_pont,**pont_pont,&pont_pont);
    printf("(Pressione <Enter> para continuar...)\n");
    scanf("%*c");
    
    // Atribui o valor zero para a variavel var1 de maneira indireta (multipla) pelo ponteiro de ponteiro
    **pont_pont = 0;
    
    printf("\n\n\t\t Imprime variaveis 5\n\n");
    printf("Variavel var1\n var1 = %d ; &var1 = %p\n\n",var1,&var1);
    printf("Variavel *pont\n pont = %p ; *pont = %d; &pont = %p\n\n",pont,*pont,&pont);
    printf("Variavel **pont_pont\n pont_pont = %p ; *pont_pont = %p; **pont_pont = %d; &pont_pont = %p\n\n",pont_pont,*pont_pont,**pont_pont,&pont_pont);
    printf("(Pressione <Enter> para finalizar...)\n");
    scanf("%*c");
    
    return 0;
}