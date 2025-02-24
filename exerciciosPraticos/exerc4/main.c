#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_dupla_encadeada.h"


// Supondo que as funções criarLista, insertTail, busca, ordenar, buscaBinaria, printLista, e clear já estejam implementadas

void printTitle(const char *title) {
    int totalLength = 50;
    int titleLength = strlen(title);
    int padding = (totalLength - titleLength) / 2;

    for (int i = 0; i < padding; i++) 
        printf("=");
    printf(" %s ", title);
    for (int i = 0; i < padding; i++) 
        printf("=");
    if (totalLength % 2 != titleLength % 2) 
        printf("=");
    printf("\n");
}

int main() {
    printTitle("Teste: Criacao e Insercao de Elementos");

    // Cria a lista
    Lista* lista = criarLista();

    // Insere elementos na lista
    insertTail(lista, 20);
    insertTail(lista, 5);
    insertTail(lista, 15);
    insertTail(lista, 10);
    insertTail(lista, 8);
    insertTail(lista, 18);
    printLista(lista);
    printf("\n\n");

    printTitle("Teste: Busca Linear - Valor Presente");

    // Testa a função busca antes da ordenação
    int valor_busca = 15;
    int posicao = busca(lista, valor_busca);
    if (posicao != -1) {
        printf("Valor %d encontrado na posicao %d (busca linear)\n", valor_busca, posicao);
    } else {
        printf("Valor %d nao encontrado (busca linear).\n\n", valor_busca);
    }

    printf("\n\n");
    printTitle("Teste: Busca Linear - Valor Ausente");

    valor_busca = 56;
    posicao = busca(lista, valor_busca);
    if (posicao != -1) {
        printf("Valor %d encontrado na posicao %d (busca linear).\n", valor_busca, posicao);
    } else {
        printf("Valor %d nao encontrado (busca linear).\n", valor_busca);
    }
    printf("\n\n");
    printTitle("Teste: Ordenacao da Lista");

    printf("Chamando a funcao de ordenacao...\n");
    ordenar(lista);
    printLista(lista);


    printf("\n\n");
    printTitle("Busca Binaria - Valor Presente");

    valor_busca = 15;
    posicao = busca(lista, valor_busca);
    if (posicao != -1) {
        printf("Valor %d encontrado na posicao %d (busca binaria).\n", valor_busca, posicao);
    } else {
        printf("Valor %d nao encontrado (busca binaria).\n", valor_busca);
    }

    printf("\n\n");
    printTitle("Teste: Busca Binaria - Valor Ausente");

    valor_busca = 42;
    posicao = busca(lista, valor_busca);
    if (posicao != -1) {
        printf("Valor %d encontrado na posicao %d (busca binaria).\n", valor_busca, posicao);
    } else {
        printf("Valor %d nao encontrado (busca binaria).\n", valor_busca);
    }

    printf("\n\n");
    printTitle("Teste: Busca Binaria Direta");

    int valor_busca_bin = 10;
    posicao = buscaBinaria(lista, valor_busca_bin);
    if (posicao != -1) {
        printf("Valor %d encontrado na posicao %d (busca binaria direta).\n", valor_busca_bin, posicao);
    } else {
        printf("Valor %d nao encontrado (busca binaria direta).\n", valor_busca_bin);
    }

    printf("\n\n");
        
    printf("Buscando numa lista vazia\n");
    Lista* lista_vazia = criarLista();
    posicao = busca(lista_vazia, 5);
    if (posicao != -1) {
        printf("Valor 5 encontrado na posicao %d (busca em lista vazia).\n", posicao);
    } else {
        printf("Valor 5 nao encontrado (busca em lista vazia).\n");
    }
    clear(lista_vazia);
    free(lista_vazia);

    printf("\n\n");
    printTitle("Teste: Busca do Primeiro e Ultimo Elemento");

    posicao = busca(lista, 5); // Primeiro elemento
    printf("Primeiro elemento (5) %s encontrado na posicao %d.\n", (posicao != -1) ? "" : "nao", posicao);
    posicao = busca(lista, 20); // Último elemento
    printf("Ultimo elemento (20) %s encontrado na posicao %d.\n", (posicao != -1) ? "" : "nao", posicao);

    printf("\n\n");
    printTitle("Teste: Ordenacao de Lista Ja Ordenada");

    ordenar(lista);
    printLista(lista);
    printf("\n\n");
    // Libera a memória da lista
    printTitle("Fim dos Testes");
    clear(lista);
    free(lista);

    return 0;
}
