#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvores.h"


void printTitle(const char *title) {
    int totalLength = 50; // comprimento padrão para os títulos dos testes
    int titleLength = strlen(title); // calcula o comprimento do título fornecido

    // calcula a qtd de espaço em branco à esquerda e à direita do título
    int padding = (totalLength - titleLength) / 2; 

    // Imprime os caracteres '=' à esquerda do título para centralizá-lo
    for (int i = 0; i < padding; i++) 
        printf("="); 

    printf(" %s ", title);  

    // Imprime os caracteres '=' à direita do título para completar o alinhamento
    for (int i = 0; i < padding; i++) 
        printf("="); 

    // Se a diferença entre o comprimento do título e o comprimento total for ímpar,
    // ajusta o número de '=' 
    if (totalLength % 2 != titleLength % 2) 
        printf("="); 

    printf("\n"); // nova linha após o título
}
int main(){

    Tree *tree = createTree();
    printTitle("Início dos testes da árvore binária");
    
    printTitle("Teste de Inserção de Valores Válidos");
    printf("\n");

    printf("Inserindo os elementos da árvore de exemplo\n 61, 34, 67, 19, 50, 66, 94, 20, 55, 64, 70, 95\n");
    tree->root = insert(tree->root, 61);
    tree->root = insert(tree->root, 34);
    tree->root = insert(tree->root, 67);
    tree->root = insert(tree->root, 19);
    tree->root = insert(tree->root, 50);
    tree->root = insert(tree->root, 66);
    tree->root = insert(tree->root, 94);
    tree->root = insert(tree->root, 20);
    tree->root = insert(tree->root, 55);
    tree->root = insert(tree->root, 64);
    tree->root = insert(tree->root, 70);
    tree->root = insert(tree->root, 95);


    // Exerplo árvore dos slides
    // tree->root = insert(tree->root, 17);
    // tree->root = insert(tree->root, 6);
    // tree->root = insert(tree->root, 4);
    // tree->root = insert(tree->root, 14);
    // tree->root = insert(tree->root, 35);
    // tree->root = insert(tree->root, 23);
    // tree->root = insert(tree->root, 48);
    // printf("\n");
    // printf("Estado da árvore (inordem):\n");
    // strInOrder(tree->root);
    // printf("\n");


    printf("\n");
    // Teste de busca de valores existentes e inexistentes
    printTitle("Teste de Busca de Valores");
    printf("Busca pelo valor 67 (esperado: encontrado '1'): %d\n", search(tree->root, 67));
    printf("Busca pelo valor 589 (esperado: não encontrado '0'): %d\n", search(tree->root, 589));
    printf("\n\n");

    // Teste da função de soma dos caminhos
    printTitle("Teste de Soma dos Caminhos");
    caminhos(tree->root, 0);
    printf("\n\n");


    // Teste de obter o nó mínimo e máximo
    printTitle("Teste de Nó Mínimo e Máximo");
    Node *minNode = getMinNode(tree->root);
    Node *maxNode = getMaxNode(tree->root);
    if (minNode != NULL) printf("Menor valor na árvore: %d\n", minNode->data);
    if (maxNode != NULL) printf("Maior valor na árvore: %d\n", maxNode->data);
    printf("\n\n");


    // Teste de impressão dos percursos em diferentes ordens
    printTitle("Teste de Impressão dos Percursos");
    printf("Pré-ordem: ");
    strPreOrder(tree->root);
    printf("\n");

    printf("Em-ordem: ");
    strInOrder(tree->root);
    printf("\n");

    printf("Pós-ordem: ");
    strPostOrder(tree->root);
    printf("\n\n");

    // Teste de remoção de nós com diferentes configurações de filhos
    printTitle("Teste de Remoção de Nós");
    printf("Removendo nó com dois filhos (94)\n");
    tree->root = deleteNode(tree->root, 94, 'D');
    printf("Em ordem: ");
    strInOrder(tree->root);
    printf("\nPós ordem: ");
    strPostOrder(tree->root);
    
    printf("\n\n");
    

    printf("Removendo nó com um filho (50)\n");
    deleteNode(tree->root, 50, 'D');
    printf("Em ordem: ");
    strInOrder(tree->root);
    printf("\nPós ordem: ");
    strPostOrder(tree->root);
    
    printf("\n\n");

    printf("Removendo nó folha (20)\n");
    deleteNode(tree->root, 20, 'D');
    strInOrder(tree->root);
    printf("\n\n");

    // Teste de impressão dos percursos em diferentes ordens
    printTitle("Teste Percursos na nova árvore");
    printf("Pré-ordem: ");
    strPreOrder(tree->root);
    printf("\n");

    printf("Em-ordem: ");
    strInOrder(tree->root);
    printf("\n");

    printf("Pós-ordem: ");
    strPostOrder(tree->root);
    printf("\n\n");

    printTitle("Teste completo");
    printf("\n");
    // Liberação de memória
    free(tree);

    return 0;
    

}
