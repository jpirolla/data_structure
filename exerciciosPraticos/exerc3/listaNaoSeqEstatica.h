#ifndef LISTANAOSEQESTATICA_H
#define LISTANAOSEQESTATICA_H

#include <stdio.h>
#include <stdlib.h>

#include "fila_estaticaCircular.h"
// Definição da LNSE
typedef struct {
    int *elementos;
    int *sucessor;
    Fila* posicoes_vazias;
    int first;
    int last;
    int capacity;
    int qtdElementos;
    int indiceUltimoElemento;
} Lista;


void criarLista(Lista* lista, int tamanho);
void inserir(Lista* lista, int x, int i);
int remover(Lista* lista, int x);
int buscar(Lista* lista, int x);
int size(Lista* lista);
void clearLista(Lista* lista);
void imprimirLista(Lista* lista);


#endif // LISTANAOSEQESTATICA_H
