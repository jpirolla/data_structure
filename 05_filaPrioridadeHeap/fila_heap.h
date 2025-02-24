#ifndef FILA_HEAP_H
#define FILA_HEAP_H

typedef struct {
    int value;
    int priority;
} Data;

typedef struct {
    int capacity;
    Data *data;
    int rear;
    int size;
} Fila;

// Função para inicializar a fila
Fila* criarFila(int capacity);

// Função para adicionar um elemento na fila
void enqueue(Fila *fila, int data, int priority);

// Função para remover um elemento da fila
Data dequeue(Fila *fila);

// Função para obter o tamanho da fila
int getSize(Fila *fila);

// Função para verificar se a fila está vazia
int isEmpty(Fila *fila);

// Função para verificar se a fila está cheia
int isFull(Fila *fila);

// Função para obter o primeiro elemento da fila
Data getFront(Fila *fila);

// Função para limpar a fila
void clear(Fila *fila);

// Função para imprimir a fila
void imprimir(Fila *fila);

#endif // FILA_ESTATICACIRCULAR_H
