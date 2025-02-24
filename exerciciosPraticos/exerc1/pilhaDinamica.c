#include <stdio.h>
#include <stdlib.h> // contem as funcoes malloc e free
#include "pilhaDinamica.h"

// Função para criar uma nova pilha
Pilha* criarPilha() {

    // Usaremos malloc para que a pilha possa ser usada em outras funcoes e para evitar ter que retornar uma copia dela
    Pilha* pilha = (Pilha*)malloc(sizeof(Pilha));

    pilha->top = NULL;
    pilha->tamanho = 0;
    return pilha;
}

// Função para criar um novo nó
Node* criarNode(char data) {

    // Usaremos malloc para que o noh possa ser usada em outras funcoes e para evitar ter que retornar uma copia dele
    Node* node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->next = NULL;

    return node;
}

// Função para verificar se a pilha está vazia
int isEmptyPilha(Pilha* pilha) {

    if (pilha->tamanho==0){
        return 1;
    }
    else{
        return 0;
    }

    // Outras maneiras válidas
    //------------------------
    // return pilha->tamanho==0;
    // return pilha->top == NULL;
    //------------------------
}

// Função para adicionar um elemento no topo da pilha
void push(Pilha* pilha, char data) {
    Node* node = criarNode(data);

    // O novo noh ira apontar para o noh que era o topo antes
    node->next = pilha->top;

    // Substitui o topo pelo novo noh
    pilha->top = node;
    pilha->tamanho++;
}

// Função para remover e retornar o elemento do topo da pilha
char pop(Pilha* pilha) {

    if ( isEmptyPilha(pilha) ) {
        printf("\nPilha vazia. Erro (underflow)");
        return -1;  // Erro: underflow
    }

    Node* temp = pilha->top;
    int data = temp->data;

    // O novo noh sera o que estava apontado pelo noh que sera excluido
    pilha->top = pilha->top->next;

    // Libera o espaço de memória que foi alocado para o noh
    free(temp);

    pilha->tamanho--;

    return data;
}

// Função para retornar a quantidade de elementos da pilha
int size(Pilha* pilha) {
    return pilha->tamanho;
}

// Função para retornar o topo da pilha sem remover
char getTop(Pilha* pilha) {

    if ( isEmptyPilha(pilha) ) {
        printf("\nPilha vazia. Erro (underflow)");
        return -1;  // Erro: underflow
    }

    return pilha->top->data;
}

// Função para limpar a pilha
void clearPilha(Pilha* pilha) {
    while (!isEmptyPilha(pilha)) {
        pop(pilha);
    }
}

// Função para imprimir a pilha
void imprimirPilha(Pilha* pilha) {
    Pilha* auxPilha = criarPilha();
    printf("\n | ");

    // Seguindo as regras da pilha, a unica forma de
    // acessar todos os seus valores, eh destruindo ela
    while ( isEmptyPilha(pilha)!=1 ) {
        int data = pop(pilha);

        // Salva o dado na outra pilha para recuperar depois
        push(auxPilha, data);
    }

    while ( isEmptyPilha(auxPilha)!=1 ) {
        int data = pop(auxPilha);

        // Recupera o valor na pilha original
        push(pilha, data);

        // Se voce quiser que o topo apareca no inicio do vetor, imprima no laco anterior
        // Se voce quiser que o topo apareca no final do vetor, imprima aqui
        printf(" %c", data);
    }

    printf("  |\n");

    free(auxPilha);
}
