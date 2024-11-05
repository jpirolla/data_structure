#ifndef STACKSEQDINAMICA_H
#define STACKSEQDINAMICA_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Stack {
    int *array;
    int capacity;
    int top;
}Stack;


Stack *createStack(int size);
void deleteStack(Stack **stack);
int isEmpty(Stack *stack);

int size(Stack *stack);
void push(Stack *stack, int val);
int pop(Stack *stack);
int getTop(Stack *stack);
void printStack(Stack *stack);
//void invertedPrint(Stack *stack)
void freeStack(Stack *stack);

#endif