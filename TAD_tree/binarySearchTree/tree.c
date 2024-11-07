
#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

/*
Antes de implementar as funções, lembrar que tenho duas estrut principais
    1. Node: que armazena dados e ponteiros para os filhos (left e right)
        - cada nó é um elemento da arvore e pode ter filho a esq ou dir
    2. Tree: contem apenas um ponteiro para o nó raiz
*/

Node *createNode(int data){
    /*
    Alocar a memoria para node do tipo NODE
    atibuo o valor do nó a data
    inicializo os filhos como nullos

    Retorno o próprio nó
    */
    Node *node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Tree *createTree(){
    /*
    - Aloco memoria para a árvore
    - Inicializo o root
    - Retorno a própria árvore
    */

   Tree *tree = (Tree *)malloc(sizeof(Tree));
   tree->root = NULL;
   return tree;

}

Node *insert(Node *node, int value){
    /*
    Para inserir um dado, preciso encontrar a posição correta
    para inserir esse dado. Se o valor for maior que a raiz
    ir para direita etc
    Forma recursiva
    */

   //caso base se o ponteiro de node aponta p nulo, tenho que criar um novo nó
   // Os outros casos avalio se é menor que o nó ou maior

   if (node == NULL){
        Node *newNode = createNode(value);
        printf("\n%d", newNode->data);
        return newNode;
   }

   // se o valor for menor que a raiz
   if(value < node->data){
    node->left = insert(node->left, value);
   }

   else{
    node->right = insert(node->right, value);
   }

    return node;

}

int search(Node *node, int data){
    /*
    A busca também é recursiva, comparando o valor atual com o dado do nó e decidindo se vai para a esquerda ou direita
    Considerar o caso do valor nao ser encontrado

    Retorna 1 para valor encontrado e 0 para valor n encontrado
    */

   // caso base node nulo e encontrar no primeiro nó
   if(node == NULL){
    return 0;
   }

   if(data == node->data){
    return 1;
   }

    //casos especiais recursivos
    int valBusca;

    if (data < node->data){
        valBusca = search(node->left, data);
    }
    else{
        valBusca = search(node->right, data);
    }
    return valBusca;

}

Node *getMinNode(Node *node){
    /*
    Tb é recursiva
    Preciso percorrer a árvore para achar o menor.
    Mas sei que o menor estará mais à esquerda
    */

   if(node == NULL){
    return NULL;
   }

    // Quando eu chegar no nó esquerdo que não tiver filho (ou seja node->left for nulo), retorno o nó
    if(node->left == NULL){
    return node;
   }

    return getMinNode(node->left);

}


Node *getMaxNode(Node *node){

    if (node == NULL){
        return NULL;
    }

    if (node->right == NULL){
        return node;
    }

    return getMaxNode(node->right);
}

Node *deleteNode(Node *node, int data) {
    if (node == NULL) {
        return NULL; // Árvore vazia, nada a fazer
    }

    // Se o valor a ser removido é menor que o valor do nó, vá para a esquerda
    if (data < node->data) {
        node->left = deleteNode(node->left, data);
    }
    // Se o valor a ser removido é maior que o valor do nó, vá para a direita
    else if (data > node->data) {
        node->right = deleteNode(node->right, data);
    }
    // Caso o valor seja igual ao valor do nó, este é o nó a ser removido
    else {
        // Caso 1: Nó sem filhos (nó folha)
        if (node->left == NULL && node->right == NULL) {
            free(node);
            return NULL;
        }
        // Caso 2: Nó com um filho
        else if (node->left == NULL) {
            Node *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL) {
            Node *temp = node->left;
            free(node);
            return temp;
        }
        // Caso 3: Nó com dois filhos
        else {
            // Encontrar o nó mínimo da subárvore direita
            Node *temp = getMinNode(node->right);
            node->data = temp->data;  // Substitui o valor do nó pelo valor do sucessor
            node->right = deleteNode(node->right, temp->data); // Remove o sucessor
        }
    }

    return node;
}


void strPreOrder(Node *node){
    if( node != NULL ){

        printf("%d ", node->data );
        strPreOrder(node->left);
        strPreOrder(node->right);
    }
}


// Função para percorrer a árvore em ordem
void strInOrder(Node *node) {
    if (node != NULL) {

        strInOrder(node->left);
        printf("%d ", node->data);
        strInOrder(node->right);
    }
}

// Função para percorrer a árvore em pós-ordem
void strPostOrder(Node *node) {
    if (node != NULL) {

        strPostOrder(node->left);
        strPostOrder(node->right);
        printf("%d ", node->data);
    }
}


