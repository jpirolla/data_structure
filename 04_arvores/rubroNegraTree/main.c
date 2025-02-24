#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

int main()
{
    Tree* tree = createTree();

    printf("\n\nPercurso pré-ordem\n");
    strPreorder(tree->root);

    printf("\n\nInsert 0");
    insert(tree, 0);

    printf("\n\nInsert 1");
    insert(tree, 1);

    printf("\n\nInsert 2");
    insert(tree, 2);

    printf("\n\nPercurso pré-ordem\n");
    strPreorder(tree->root);

    printf("\n\nInsert 3");
    insert(tree, 3);

    printf("\n\nInsert 4");
    insert(tree, 4);

    printf("\n\nPercurso pré-ordem\n");
    strPreorder(tree->root);

    printf("\n\nInsert 5");
    insert(tree, 5);

    printf("\n\nInsert 6");
    insert(tree, 6);

    printf("\n\nInsert 7");
    insert(tree, 7);

    printf("\n\nPercurso pré-ordem\n");
    strPreorder(tree->root);

}

