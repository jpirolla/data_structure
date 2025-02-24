#include<stdio.h>
#include<stdlib.h>
#include "pilhaDupla.h"

/**
 * Cria uma nova pilha dupla com tamanho máximo especificado.
 * 
 * @param max inteiro que dita o tamanho máximo das pilhas  
 * @return Ponteiro para a pilha dupla recém-criada.
 */
DoubleStack *createDStack(int max) {

    // Aloca memória para a pilha dupla
    DoubleStack *stack = (DoubleStack*)malloc(sizeof(DoubleStack));
    // Aloca memória para o vetor que armazenará os dados
    stack->vet = (int*)malloc(max * sizeof(int));
    // Inicializa os topos das pilhas A e B em posições fora do vetor
    stack->topA = -1;  
    stack->topB = max; 

    stack->max = max;  // tamanho máximo da pilha
    return stack;
}

/**
 * Verifica se a pilha dupla está cheia, ou seja, quando o topo da 
 * pilha A e o topo da pilha B se encontram.
 * 
 * @param stack Ponteiro para a pilha a ser verificada.
 * @return 1 se a pilha estiver cheia, 0 caso contrário.
 */
int isFull(DoubleStack *stack) {
    return stack->topA + 1 == stack->topB;
}

/**
 * Insere um elemento na pilha A.
 * 
 * @param stack onteiro para a pilha dupla onde irei inserir.
 * @param data dado a ser inserido na pilha 
 */
void pushA(DoubleStack *stack, int data) {
    // Verifica se a pilha A está cheia
    if (isFull(stack)) {
        printf("Pilha A cheia!\n");
        return;
    }
    // Insere o dado no topo da pilha A
    stack->topA++; //incremento top para proxima posicao
    stack->vet[stack->topA] = data;
}

/**
 * Insere um elemento na pilha B.
 * 
 * @param stack onteiro para a pilha dupla onde irei inserir.
 * @param data dado a ser inserido na pilha 
 */
void pushB(DoubleStack *stack, int data) {
    // Verifica se a pilha B está cheia
    if (isFull(stack)) {
        printf("Pilha B cheia!\n");
        return;
    }
    // Insere o dado no topo da pilha B
    stack->topB--;
    stack->vet[stack->topB] = data;
}

/**
 * Remove e retorna o elemento do topo da pilha A.
 * 
 * @param stack Ponteiro para a pilha dupla.
 * @return O valor removido do topo da pilha A, ou -1 se a 
 * pilha A estiver vazia.
 */
int popA(DoubleStack *stack) {
    // Verifica se a pilha A está vazia
    if (stack->topA == -1) {
        printf("Pilha A vazia!\n");
        return -1;
    }
    // Retorna o valor do topo da pilha A e o remove
    //acesso o índice do topo e depois decremento
    return stack->vet[stack->topA--];
}

/**
 * Remove e retorna o elemento do topo da pilha B.
 * 
 * @param stack Ponteiro para a pilha dupla.
 * @return O valor removido do topo da pilha B, ou -1 se a 
 * pilha B estiver vazia.
 */
int popB(DoubleStack *stack) {
    // Verifica se a pilha B está vazia
    if (stack->topB == stack->max) {
        printf("Pilha B vazia!\n");
        return -1;
    }
    // Retorna o valor do topo da pilha B e o remove
    //acesso o índice do topo e depois incremento
    return stack->vet[stack->topB++];
}

/**
 * Limpa a pilha A, removendo todos os elementos.
 * 
 * @param stack Ponteiro para a pilha dupla a ser limpa.
 */
void clearA(DoubleStack *stack) {
    stack->topA = -1; // Reseta o topo da pilha A
}

/**
 * Limpa a pilha B, removendo todos os elementos.
 * 
 * @param stack Ponteiro para a pilha dupla a ser limpa.
 */
void clearB(DoubleStack *stack) {
    stack->topB = stack->max; // Reseta o topo da pilha B
}

/**
 * Retorna o valor do topo de uma pilha especificada
 * 
 * @param stack Ponteiro para a pilha 
 * @param pilha caracter que indica qual pilha  deve ser acessada.
 * @return O valor do topo da pilha, ou -1 se a pilha estiver vazia.
 */
int getTop(DoubleStack *stack, char pilha) {
    if (pilha == 'A') {
        // Verifica se a pilha A não está vazia
        if (stack->topA != -1) {
            // Se a pilha A não estiver vazia, retorna seu topo
            return stack->vet[stack->topA];
        } else {
            // Se estiver vazia, retorna -1
            return -1;
        }
    } else if (pilha == 'B') {
        // Verifica se a pilha B não está vazia
        if (stack->topB != stack->max) {
            // Se não estiver vazia, retorna o topo de B
            return stack->vet[stack->topB];
        } else {
            // Se estiver vazia, retorna -1
            return -1;
        }
    }
    
    // Caso em que o caractere não seja 'A' nem 'B'
    printf("Caracter inválido!\nUtilize 'A' ou 'B'\n");
    return -1; // Caso inválido
}


/**
 * Imprime todos os elementos da pilha A, do topo à base
 * @param pilha Ponteiro para a pilha dupla.
 */
void imprimirA(DoubleStack *pilha) {
    // Cria uma pilha auxiliar para preservar o estado original da pilha A
    DoubleStack *auxPilha = createDStack(pilha->max);

    printf("Pilha A: [");

    // Transfere os elementos da pilha A para a pilha auxiliar e imprime
    while (pilha->topA != -1) {
        int data = popA(pilha);
        printf(" %d", data);
        pushA(auxPilha, data); 
    }
    
    // Restaura os elementos de volta para a pilha A
    while (auxPilha->topA != -1) {
        pushA(pilha, popA(auxPilha));
    }

    printf(" ]\n");
    free(auxPilha->vet);
    free(auxPilha);
}

/**
 * Imprime todos os elementos da pilha B, do topo à Base
 * 
 * @param pilha Ponteiro para a pilha dupla.
 */
void imprimirB(DoubleStack *pilha) {
    // Cria uma pilha auxiliar para preservar o estado original da pilha B
    DoubleStack *auxPilha = createDStack(pilha->max);

    printf("Pilha B: [");

    // Transfere os elementos da pilha B para a pilha auxiliar e imprime
    while (pilha->topB != pilha->max) {
        int data = popB(pilha);
        printf(" %d", data);
        pushB(auxPilha, data); 
    }
    
    // Restaura os elementos de volta para a pilha B
    while (auxPilha->topB != auxPilha->max) {
        pushB(pilha, popB(auxPilha));
    }

    printf(" ]\n");

    // libero os ponteiros auxiliares
    free(auxPilha->vet);
    auxPilha->vet = NULL; // previne o uso do ponteiro após free
    free(auxPilha);
}
