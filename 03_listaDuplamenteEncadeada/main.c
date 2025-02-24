#include <stdio.h>
#include <stdlib.h>

#include "listaDuplamenteEncadeada.h"

int main()
{

    Lista* lista = criarLista();

    printf("\nEstá vazia? %d", isEmpty(lista));

    printf("\nTamanho: %d", getSize(lista));

    printf("\n\nbusca(5)");
    int pos = busca(lista, 5);
    printf("Posicao: %d", pos);

    insertHead(lista, 10);
    printLista(lista);

    insertHead(lista, 5);
    printLista(lista);

    insertTail(lista, 3);
    printLista(lista);

    insert(lista, 8, 2);
    printLista(lista);

    insertTail(lista, 9);
    printLista(lista);

    insertHead(lista, 8);
    printLista(lista);

    insert(lista, 7, 4);
    printLista(lista);

    printf("\n\nbusca(9)");
    pos = busca(lista, 9);
    printf("Posicao: %d", pos);

    printf("\n\nremoveHead(lista)");
    removeHead(lista);
    printLista(lista);

    printf("\n\nremoveTail(lista)");
    removeTail(lista);
    printLista(lista);

    printf("\n\nremoveNode(lista, 2)");
    removeNode(lista, 2);
    printLista(lista);


    printf("\n\nclear(lista)");
    clear(lista);
    printLista(lista);

    return 0;
}
