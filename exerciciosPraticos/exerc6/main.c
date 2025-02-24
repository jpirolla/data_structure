#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

int main()
{
    // Testes das funções fornecidas pelo professor,
    // e criação de uma tree para testes na nova função
    Tree* tree = createTree();

    printf("\n\nInsert 17");
    tree->root = insert(tree->root, 17);

    printf("\n\nInsert 6");
    tree->root = insert(tree->root, 6);

    printf("\n\nInsert 35");
    tree->root = insert(tree->root, 35);

    printf("\n\nInsert 4");
    tree->root = insert(tree->root, 4);

    printf("\n\nInsert 14");
    tree->root = insert(tree->root, 14);

    printf("\n\nInsert 23");
    tree->root = insert(tree->root, 23);

    printf("\n\nInsert 48");
    tree->root = insert(tree->root, 48);

    Node* node = getMinNode(tree->root);
    printf("\n\nMenor: %d", node->data);

    node = getMaxNode(tree->root);
    printf("\n\nMaior: %d", node->data);

    printf("\n\nPercurso pre-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso pos-ordem\n");
    strPostorder(tree->root);

    printf("\n\ndeleteNode(4)\n");
    node = deleteNode(tree->root, 4, 'D');

    node = getMinNode(tree->root);
    printf("\n\nMenor: %d", node->data);

    printf("\n\nPercurso pre-ordem\n");
    strPreorder(tree->root);

    printf("\n\nPercurso em-ordem\n");
    strInorder(tree->root);

    printf("\n\nPercurso pos-ordem\n");
    strPostorder(tree->root);

    //Nova função qntSubnos testes:

    printf("\n\nTestes da nova funcao qntSubnos");

    printf("\n\nTeste na raiz da arvore");
    printf("\nQuantidade de subnos do valor 17: ");
    printf("%d", qntSubnos(tree->root, 17)); 

    printf("\n\nTeste em um no folha");
    printf("\nQuantidade de subnos do valor 23: ");
    printf("%d", qntSubnos(tree->root, 23)); //Retorna um, pois inclui ele mesmo

    printf("\n\nTeste em um no com 2 filhos");  
    printf("\nQuantidade de subnos do valor 35: ");
    printf("%d", qntSubnos(tree->root, 35));

    printf("\n\nTeste em um valor que nao esta na arvore");
    printf("\nQuantidade de subnos do valor 65: ");
    printf("%d, pois nao esta na arvore", qntSubnos(tree->root, 65)); //Usamos 0 para representar que o valor não está na árvore
}

