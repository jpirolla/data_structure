#include <stdio.h>
#include <string.h>
#include "lista_ligada_cruzada.h"

// Função para imprimir títulos de testes
void printTitle(const char *title) {
    int totalLength = 50;
    int titleLength = strlen(title);
    int padding = (totalLength - titleLength) / 2;

    for (int i = 0; i < padding; i++) 
        printf("=");
    printf(" %s ", title);
    for (int i = 0; i < padding; i++) 
        printf("=");
    if (totalLength % 2 != titleLength % 2) 
        printf("=");
    printf("\n");
}


int main() {

    // Criando duas matrizes esparsas 5x5 para teste
    SparseMatrix* matriz1 = criarMatriz(5, 5);
    SparseMatrix* matriz2 = criarMatriz(5, 5);

    // Inserindo valores em matriz1
     printTitle("Teste: Insercao de Valores em Matriz1");
    inserir(matriz1, 5, 0, 0);     
    inserir(matriz1, 10, 0, 2);   
    inserir(matriz1, 15, 2, 0);    
    inserir(matriz1, 20, 2, 2);    
    inserir(matriz1, 25, 1, 1);

    printf("\n");
    printf("Imprimindo a matriz1:\n");    
    imprimir(matriz1);

    printf("\n");
    // Inserindo valores em matriz2
    printTitle("Teste: Insercao de Valores em Matriz2");
    inserir(matriz2, 10, 0, 1);  
    inserir(matriz2, 25, 2, 1);
    inserir(matriz2, 35, 1, 0);  
    inserir(matriz2, 40, 2, 2); 
    inserir(matriz2, 5, 1, 1);


    printf("\n");
    printf("Imprimindo a matriz2:\n");   
    imprimir(matriz2);
    printf("\n");

    // Testando a busca de elementos
    printTitle("Teste: Busca de Elementos");
    printf("Buscando elementos em matriz1:\n");
    printf("Elemento em (0,2): %d\n", buscar(matriz1, 0, 2)); // Deve retornar 10
    printf("Elemento em (2,0): %d\n", buscar(matriz1, 2, 0)); // Deve retornar 15
    printf("Elemento em (1,4): %d\n", buscar(matriz1, 1, 4)); // Deve retornar 0


    printf("\nBuscando elementos em matriz2:\n");
    printf("Elemento em (0,1): %d\n", buscar(matriz2, 0, 1)); // Deve retornar 10
    printf("Elemento em (2,1): %d\n", buscar(matriz2, 2, 1)); // Deve retornar 25
    printf("Elemento em (1,4): %d\n", buscar(matriz2, 1, 4)); // Deve retornar 0

     printf("\n");
    printTitle("Teste: Remocao de Elemento");

    // Removendo um elemento e imprimindo novamente
    printf("Removendo elemento em (2,2) de matriz1...\n");
    remover(matriz1, 2, 2);
    printf("Imprimindo a matriz1:\n");  
    imprimir(matriz1);
    printf("\n");

    printTitle("Teste: Soma Interna dos Elementos");
    // Testando soma interna dos elementos de matriz1
    printf("Soma interna de todos os elementos de matriz1: %d\n", somaInterna(matriz1));
    printf("\n");


    printTitle("Teste: Soma de Duas Matrizes");
    // Somando matriz1 e matriz2 em uma nova matriz
    printf("Somando matriz1 e matriz2...\n");
    SparseMatrix* matrizSoma = somar(matriz1, matriz2);
    printf("Resultado da soma de matriz1 e matriz2:\n");
    imprimir(matrizSoma);
    printf("\n");

    // Teste de atualização ao inserir zero (elemento deve ser removido)
    printTitle("Teste: Atualizacao com Valor Zero");
    printf("Inserindo valor 0 em (2,1) de matrizSoma (deve remover o elemento)...\n");
    inserir(matrizSoma, 0, 2, 1);
    printf("\nImprimindo a matrizSoma:\n");  
    imprimir(matrizSoma);
    printf("\n");


    printTitle("Teste: Calculo da Esparsidade");
    printf("\nEsparsidade: %.2f\n", calculaEsparsidade(matriz1));

    //Liberando a memória das matrizes
    freeMatrix(matriz1);
    freeMatrix(matriz2);
    freeMatrix(matrizSoma);

     printf("\n");
    printTitle("Teste completo");

    return 0;
}