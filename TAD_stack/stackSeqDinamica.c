#include <stdio.h>
#include <stdlib.h> 
#include "stackSeqDinamica.h"


Stack *createStack(int size){
	Stack *stack = (Stack *)malloc(sizeof(Stack));
    if (stack != NULL) {
        stack->array = (int *)malloc(size * sizeof(int));
        stack->top = -1;  // Pilha começa vazia
        stack->capacity = size;
    }
    return stack;
}


int isEmpty(Stack *stack){
	return (stack->top == -1);
}

int isFull(Stack *stack){
	return (stack->top == stack->capacity - 1);
}	

int size(Stack *stack){
	return (stack->top);
}

void push(Stack *stack, int value){
	if(isFull(stack)){
		printf("Overflow!\n");
		return;
	}
    stack->top++;
	stack->array[stack->top] = value;
}

int pop(Stack *stack){
	if(isEmpty(stack)){
		printf("Underflow!\n");
		return -1;
	}
	return stack->array[stack->top--];
}

int getTop(Stack *stack){ 
	if(isEmpty(stack)){
		printf("Underflow\n");
		return -1;
	}
	return stack->array[stack->top];
}
void printStack(Stack *stack){
    Stack *aux = createStack(stack->capacity);
    printf("\n[");

    // remove elementos da pilha original e os empilha na pilha auxiliar
    while (!isEmpty(stack)) {
        int data = pop(stack);
        printf(" %d", data);
        push(aux, data);
    }

    // restaura a stack original
    while (!isEmpty(aux)) {
        push(stack, pop(aux));
    }

    printf(" ]\n");

}

void freeStack(Stack *stack) {
    free(stack->array); 
    free(stack); 
}

