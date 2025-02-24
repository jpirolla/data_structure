#include <stdio.h>
#include <stdlib.h>

#include "fila_heap.h"

int main() {

    // Inicializa a fila
    Fila* fila = criarFila(11);

    enqueue(fila, 17, 5);
    enqueue(fila, 13, 3);
    enqueue(fila, 19, 4);
    enqueue(fila, 15, 1);
    enqueue(fila, 11, 2);
    enqueue(fila, 12, 1);
    imprimir(fila);

    printf("\nenqueue([21-6])");
    enqueue(fila, 21, 6);
    imprimir(fila);

    printf("\nenqueue([25-3])");
    enqueue(fila, 25, 3);
    imprimir(fila);

    printf("Size: %d\n", getSize(fila));

    printf("\ndequeue()");
    Data valor = dequeue(fila);
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
    enqueue(fila, 2, 1);
    imprimir(fila);

    printf("\nenqueue(14)");
    enqueue(fila, 14, 5);
    imprimir(fila);

    printf("Vazia?: %d\n", isEmpty(fila));

    clear(fila);
    printf("Vazia?: %d\n", isEmpty(fila));

    // limpa a fila
    free(fila);

    return 0;
}
