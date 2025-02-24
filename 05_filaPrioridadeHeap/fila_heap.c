#include <stdio.h>
#include <stdlib.h>

#include "fila_heap.h"


// Função para inicializar a fila
Fila* criarFila(int capacity) {

    Fila *fila = (Fila *)malloc(sizeof(Fila));

    fila->capacity = capacity;

    // cria o vetor que guardara os dados de maneira dinamica
    fila->data = (Data *)malloc(capacity * sizeof(Data));

    fila->rear = -1;
    fila->size = 0;
}

// Função para obter o tamanho da fila
int getSize(Fila *fila) {
    return fila->size;

    // Outras maneiras de fazer a mesma coisa
    // --------------------------------------
    // return fila->size == fila->capacity;

    // if (fila->size == fila->capacity){
    //    return 1;
    // }
    // else{
    //    return 0;
    // }
}

// Função para verificar se a fila está vazia
int isEmpty(Fila *fila) {
    return fila->size == 0;
}

// Função para verificar se a fila está cheia
int isFull(Fila *fila) {
    return fila->size == fila->capacity;
}

// Função para adicionar um elemento na fila
void enqueue(Fila *fila, int data, int priority) {
    if (fila->size >= fila->capacity) {
        printf("Erro. Overflow!");
        return;
    }

    fila->rear = fila->rear + 1;
    fila->data[fila->rear].value = data;
    fila->data[fila->rear].priority = priority;
    fila->size += 1;

    int pos = fila->rear;
    int pai = (pos - 1)/2;
    while(pos > 0 && fila->data[pos].priority > fila->data[pai].priority){

        Data temp = fila->data[pos];
        fila->data[pos] = fila->data[pai];
        fila->data[pai] = temp;

        // Atualizar `pos` e `pai`
        pos = pai;
        pai = (pos - 1) / 2;
    }
}

// Função para remover um elemento da fila
Data dequeue(Fila *fila) {
    if (fila->size == 0) {
        printf("Erro. Underflow!");
        return;
    }

    Data temp = fila->data[0];

    if (fila->size == 1) {
        fila->rear = -1;
    } else {


        // Substitui a raiz pelo último elemento
        fila->data[0] = fila->data[fila->rear];
        fila->rear -= 1;


        // Reorganiza o heap (heapify)
        int pos = 0;
        while (1) {
            int leftChild = (2 * pos) + 1;
            int rightChild = 2 * (pos + 1);
            int largest = pos;

            // Verifica o maior entre o nó atual e seus filhos
            if (leftChild <= fila->rear && fila->data[leftChild].priority > fila->data[largest].priority) {
                largest = leftChild;
            }
            if (rightChild <= fila->rear && fila->data[rightChild].priority > fila->data[largest].priority) {
                largest = rightChild;
            }

            // Se o maior for o próprio nó, o heap está ajustado
            if (largest == pos) {
                break;
            }

            // Caso contrário, troca e continua
            Data tempSwap = fila->data[pos];
            fila->data[pos] = fila->data[largest];
            fila->data[largest] = tempSwap;

            pos = largest; // Atualiza posição atual
        }
    }

    fila->size -= 1; // Atualiza o tamanho da fila
    return temp;
}

// Função para obter o primeiro elemento da fila
Data getFront(Fila *fila) {
    if (isEmpty(fila)) {
        printf("Fila vazia\n");
        return;
    }

    return fila->data[0];
}

// Função para limpar a fila
void clear(Fila *fila) {
    fila->rear = -1;
    fila->size = 0;
}

// Função para imprimir a fila
void imprimir(Fila *fila) {

    if (isEmpty(fila)) {
        printf("\n[ ]\n");
        return;
    }

    printf("\n[");
    // Seguindo as regras da fila, a unica forma de
    // acessar todos os seus valores, eh destruindo ela
    for(int i=0; i<=fila->rear; i++){
        printf(" [%d-%d]", fila->data[i].value, fila->data[i].priority);
    }

    printf(" ]\n");
}
