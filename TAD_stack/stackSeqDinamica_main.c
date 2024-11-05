#include <stdio.h>
#include <stdlib.h> 
#include "stackSeqDinamica.h"

int main() {
    Stack *stack = createStack(3);

    
    push(stack, 10);
    push(stack, 20);
    push(stack, 30);  

   
    printf("Pilha atual:");
    printStack(stack);

    printf("Elemento do topo: %d\n", getTop(stack)); // Espera: 30
    printf("Removendo elemento do topo: %d\n", pop(stack)); // Espera: 30
    printStack(stack); // Espera: [ 10 20 ]
    printf("Tamanho: %d\n", size(stack));

    // Testando overflow
    push(stack, 40);
    printStack(stack);
    push(stack, 50);
    printStack(stack); // Espera: [ 10 20 40 50 ]

    // Testando underflow
    pop(stack);
    printStack(stack);
    pop(stack);
    printStack(stack);
    pop(stack);
    printStack(stack);
    pop(stack); // Espera: Underflow!

    // Remove um elemento
    printf("Removendo elemento do topo: %d\n", pop(stack));
    printf("Pilha após o pop:");
    printStack(stack);

    // Exibe a pilha em ordem inversa
    //printf("Pilha em ordem inversa:");
    //printStackInReverse(stack);

    freeStack(stack); 

    return 0;
}
