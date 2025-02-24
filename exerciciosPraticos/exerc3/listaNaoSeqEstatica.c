#include <stdio.h>
#include <stdlib.h>
#include "listaNaoSeqEstatica.h"
#include "fila_estaticaCircular.h"

// Função para criar uma nova lista
void criarLista(Lista* lista, int tamanho) {

    // Usaremos malloc para que a lista possa ser usada em outras funcoes e para evitar ter que retornar uma copia dela

    lista->elementos  = (int *)malloc(tamanho * sizeof(int));
    lista->sucessor  = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        lista->elementos[i] = -1;      // Inicializa valores como vazios
        lista->sucessor[i] = -1;      // Inicializa sucessores como vazios
    }

    lista->posicoes_vazias = criarFila(tamanho);
    for (int i = 0; i < tamanho; i++) {
        enqueue(lista->posicoes_vazias,i); // Preenche com os indices disponiveis
    }

    lista->first = -1;
    lista->last=-1;
    lista->capacity = tamanho;
    lista->qtdElementos = 0;
    lista->indiceUltimoElemento = -1;
}


void inserir(Lista* lista, int x, int posicao) {
    if (isEmpty(lista->posicoes_vazias) || posicao > lista->qtdElementos ) {
        // todas as posiçoes da lista estao ocupadas = fila de posicoes vazias esta vazia
        printf("Erro ao tentar inserir %d na posicao %d! Lista cheia ou posicao invalida, tente novamente.\n", x, posicao);
        return;
    }
    if(x==-1){
        printf("Erro ao tentar inserir o valor -1! Esse valor é usado para funcionamento interno, insira outro valor.");
        return;
    }
    // Verifica se o elemento já existe na lista
    for (int i = lista->first; i != -1; i = lista->sucessor[i]) {
        if (lista->elementos[i] == x) {
            printf("Erro ao tentar inserir %d! Elemento já existe na lista.\n", x);
            return;
        }
    }


    // Pega uma posicao vazia para inserir o novo valor
    int indice = dequeue(lista->posicoes_vazias); // Pega um indice que indica uma posicao vazia na lista
    lista->elementos[indice] = x;
    lista->sucessor[indice] = -1;

    if (lista->qtdElementos == 0) {
        // Inserindo o primeiro elemento
        lista->first = indice;
        lista->last = indice;
    } else {
        int atual = lista->first;
        int anterior = -1;

        // Navega até a posição desejada
        for (int i = 0; i < posicao; i++) {
            anterior = atual;
            atual = lista->sucessor[atual];
        }

        if (anterior == -1) { // Inserção na primeira posição
            lista->sucessor[indice] = lista->first;
            lista->first = indice;
        } else { // Inserção no meio ou no fim
            lista->sucessor[indice] = lista->sucessor[anterior];
            lista->sucessor[anterior] = indice;

            // Se estamos inserindo no final, atualizar o tail
            if (lista->sucessor[indice] == -1) {
                lista->last = indice;
            }
        }
    }
    lista->indiceUltimoElemento = indice;
    lista->qtdElementos++;
}


int remover(Lista* lista, int posicao){
     if (lista->qtdElementos == 0 || posicao >= lista->qtdElementos) {
        printf("\nErro na tentativa de remover elemento na posicao %d: Lista vazia ou posicao invalida.\n", posicao);
        return -1;
    }


    int atual = lista->first;
    int anterior = -1;
    for (int i = 0; i < posicao; i++) {
        anterior = atual;
        atual = lista->sucessor[atual];
    }

    if (anterior == -1) {
        lista->first = lista->sucessor[atual];
    } else {
        lista->sucessor[anterior] = lista->sucessor[atual];
        if (lista->sucessor[atual] == -1) {
            lista->last = anterior;
        }
    }

    if(atual == lista->indiceUltimoElemento){
        lista->indiceUltimoElemento--;
    }
    int valor = lista->elementos[atual];
    lista->elementos[atual] = -1; // Marca a posicao como vazia
    lista->sucessor[atual] = -1; // Remove o sucessor
    enqueue(lista->posicoes_vazias, atual); // Adiciona posicao livre na fila
    lista->qtdElementos--;

    return valor;
}

int buscar(Lista* lista, int x){
    int atual = lista->first;
    int posicao = 0;
    while (atual != -1) {
        if (lista->elementos[atual] == x) return posicao;
        atual = lista->sucessor[atual];
        posicao++;
    }
    return -1; // NÃ£o encontrado

}

int size(Lista* lista){
    return lista->qtdElementos;
}

void clearLista(Lista* lista)
{
    criarLista(lista, lista->capacity);
}

void imprimirLista(Lista* lista){
    printf("\nLista real: ");
    int atual = lista->first;
    while (atual != -1) {
        printf("%d ", lista->elementos[atual]);
        atual = lista->sucessor[atual];
    }
    printf("\n");

    printf("Elementos -> [");
    for (int i = 0; i < lista->capacity; i++) {
        if (lista->elementos[i] == -1){
            printf(" - ");
        } else {
            printf(" %d ", lista->elementos[i]);
        }
    }
    printf("]\n");

    printf("Sucessor ->  [");
    for (int i = 0; i < lista->capacity; i++) {
        if (lista->elementos[i] == -1) {
            printf(" - ");
        } else {
            printf(" %d ", lista->sucessor[i]);
        }
   }
    printf("]\n");

    printf("Capacity -> [ %d ]    First -> [ %d ]       Last -> [ %d ] \n\n",lista->capacity, lista->first, lista->last);
}
