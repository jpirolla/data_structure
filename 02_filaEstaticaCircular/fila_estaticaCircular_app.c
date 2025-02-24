#include <stdio.h>
#include <stdlib.h>

#include "fila_estaticaCircular.h"

#define CAPACITY 5

int main() {

    // Inicializa a fila
    Fila* fila = criarFila(CAPACITY);

    printf("\nenqueue(5)");
    enqueue(fila, 5);
    imprimir(fila);

    printf("\nenqueue(3)");
    enqueue(fila, 3);
    imprimir(fila);

    printf("\nenqueue(9)");
    enqueue(fila, 9);
    imprimir(fila);

    printf("Size: %d\n", getSize(fila));

    printf("\ndequeue()");
    int valor = dequeue(fila);
    imprimir(fila);

    printf("\ndequeue()");
    valor = dequeue(fila);
    imprimir(fila);

    printf("Vazia?: %d\n", isEmpty(fila));

    printf("\ndequeue()");
    valor = dequeue(fila);
    imprimir(fila);

    printf("Vazia?: %d\n", isEmpty(fila));

    printf("\ndequeue()");
    valor = dequeue(fila);
    imprimir(fila);

    printf("\nenqueue(2)");
    enqueue(fila, 2);
    imprimir(fila);

    printf("\nenqueue(14)");
    enqueue(fila, 14);
    imprimir(fila);

    printf("Vazia?: %d\n", isEmpty(fila));

    clear(fila);
    printf("Vazia?: %d\n", isEmpty(fila));

    // limpa a fila
    free(fila);

    return 0;
}
