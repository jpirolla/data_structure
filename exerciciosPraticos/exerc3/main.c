#include <stdio.h>
#include <stdlib.h>
#include "listaNaoSeqEstatica.h"


/**
 * @brief Função principal para testar a estrutura de lista não sequencial estática.
 *
 */
int main()
{

//int buscar(Lista* lista, int x);

    Lista* lista = (Lista*)malloc(sizeof(Lista));
    criarLista(lista, 10);

    // teste inserção
    inserir(lista,1,0);
    inserir(lista,10,0);
    inserir(lista,16,1);


    //teste ao inserir em uma posição inválida
    inserir(lista,20,8);


    imprimirLista(lista);

    //teste remocao
    int retorno = remover(lista, 3);
    if(retorno!=-1)
        printf("\nSucesso em remover o elemento %d", retorno);
    retorno = remover(lista, 2);
    if(retorno!=-1)
        printf("\nSucesso em remover o elemento %d", retorno);
    printf("\nLista no momento está com tamanho: %d", size(lista));
    imprimirLista(lista);

    // Teste inserir dado repetido e inserção após remoção
    inserir(lista,10,0);
    inserir(lista,0,2);
    imprimirLista(lista);

    //testes do buscar
    int indice = buscar(lista,10);
    if(indice!=-1)
        printf("\nO elemento 10 está na posição %d na lista real", indice);
    else
        printf("\nElemento 10 não está presente na lista");

    indice = buscar(lista,11);
    if(indice!=-1)
        printf("\nO elemento 11 está na posição %d na lista real", indice);
    else
        printf("\nElemento 11 não está presente na lista\n");

    //Teste da função clear
    clearLista(lista);
    imprimirLista(lista);
    return 0;
}
