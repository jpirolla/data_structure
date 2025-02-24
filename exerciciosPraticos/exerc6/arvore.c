#include <stdio.h>
#include <stdlib.h>

#include "arvore.h"

// Função para criar um novo nó
Node* createNode(int data){
    Node* node = (Node*) malloc( sizeof(Node) ); // Aloca memória para o nó

    node->data = data; // Inicializa o dado do nó
    node->left = NULL; // Inicializa o ponteiro para o filho esquerdo como NULL
    node->right = NULL; // Inicializa o ponteiro para o filho direito como NULL

    return node; // Retorna o ponteiro para o novo nó
}

// Função para criar uma nova árvore
Tree* createTree(){
    Tree* tree = (Tree*) malloc( sizeof(Tree) ); // Aloca memória para a árvore

    tree->root = NULL; // Inicializa a raiz da árvore como NULL
    return tree; // Retorna o ponteiro para a nova árvore
}

// Função para inserir um novo nó na árvore
Node* insert( Node* node, int data ){

    if (node == NULL){
        Node* newNode = createNode(data); // Cria um novo nó se o nó atual for NULL
        printf("\n%d", newNode->data); // Imprime o dado do novo nó
        return newNode; // Retorna o novo nó
    }

    // Verifica se o dado deve ser inserido à esquerda
    if (data < node->data){
        node->left = insert(node->left, data); // Insere à esquerda
    }
    // Insere à direita
    else{
        node->right = insert(node->right, data); // Insere à direita
    }

    printf("\n%d", node->data); // Imprime o dado do nó atual
    return node; // Retorna o nó atual
}

// Função para buscar um nó na árvore
Node* search( Node* node, int data ){

    if (node == NULL){
        return NULL; // Retorna NULL se o nó atual for NULL
    }

    if (data == node->data){
        return node; // Retorna o nó se o dado for encontrado
    }

    Node* achou;
    // Verifica se deve buscar à esquerda
    if (data < node->data){
        achou = search(node->left, data); // Busca à esquerda
    }
    // Busca à direita
    else{
        achou = search(node->right, data); // Busca à direita
    }

    return achou; // Retorna o nó encontrado ou NULL

}

// Função para encontrar o nó com o maior valor
Node* getMaxNode( Node* node ){

    if (node == NULL){
        return NULL; // Retorna NULL se o nó atual for NULL
    }

    if (node->right == NULL){
        return node; // Retorna o nó se não houver filho à direita
    }

    return getMaxNode( node->right ); // Continua buscando à direita

}

// Função para encontrar o nó com o menor valor
Node* getMinNode( Node* node ){

    if (node == NULL){
        return NULL; // Retorna NULL se o nó atual for NULL
    }

    if (node->left == NULL){
        return node; // Retorna o nó se não houver filho à esquerda
    }

    return getMinNode( node->left ); // Continua buscando à esquerda

}

// Função para deletar um nó da árvore
Node* deleteNode( Node* node, int data, char filhoSubstituto){

    if (node == NULL){
        return node; // Retorna o nó atual se for NULL
    }

    if (data < node->data){
        node->left = deleteNode( node->left, data, filhoSubstituto); // Deleta à esquerda
    }
    else if( data > node->data ){
         node->right = deleteNode( node->right, data, filhoSubstituto); // Deleta à direita
    }
    else{
        // Encontrou o nó a ser excluído
        if(node->left == NULL){
            Node* tempNode = node->right; // Guarda o filho direito
            free(node); // Libera o nó atual
            return tempNode; // Retorna o filho direito
        }
        else if( node->right == NULL ){
            Node* tempNode = node->left; // Guarda o filho esquerdo
            free(node); // Libera o nó atual
            return tempNode; // Retorna o filho esquerdo
        }
        else{
            // O nó possui dois filhos
            Node* tempNode;
            if( filhoSubstituto == 'D' ){
                // Substitui pelo menor valor do lado direito
                tempNode = getMinNode(node->right);
                node->data = tempNode->data;
                node->right = deleteNode(node->right, tempNode->data, filhoSubstituto);
            }
            else{
                // Substitui pelo maior valor do lado esquerdo
                tempNode = getMaxNode(node->left);
                node->data = tempNode->data;
                node->left = deleteNode(node->left, tempNode->data, filhoSubstituto);
            }
        }
    }

    return node; // Retorna o nó atual
}

// Função para percorrer a árvore em pré-ordem
void strPreorder(Node *node){
    if( node != NULL ){
        printf("%d ", node->data ); // Imprime o dado do nó atual
        strPreorder(node->left); // Percorre a subárvore esquerda
        strPreorder(node->right); // Percorre a subárvore direita
    }
}

// Função para percorrer a árvore em ordem
void strInorder(Node *node) {
    if (node != NULL) {
        strInorder(node->left); // Percorre a subárvore esquerda
        printf("%d ", node->data); // Imprime o dado do nó atual
        strInorder(node->right); // Percorre a subárvore direita
    }
}

// Função para percorrer a árvore em pós-ordem
void strPostorder(Node *node) {
    if (node != NULL) {
        strPostorder(node->left); // Percorre a subárvore esquerda
        strPostorder(node->right); // Percorre a subárvore direita
        printf("%d ", node->data); // Imprime o dado do nó atual
    }
}

// Função recursiva para contar o número de subnós
int qntSubnosRec(Node *node){
    if (node == NULL) {
        return 0; // Retorna 0 se o nó atual for NULL
    }
    
    int contador = 1; // Contabiliza o nó atual
    contador += qntSubnosRec(node->left); // Soma os subnós à esquerda
    contador += qntSubnosRec(node->right); // Soma os subnós à direita
    
    return contador; // Retorna o total de nós
}

// Função para contar o número de subnós de um nó específico
int qntSubnos(Node *node, int data) {
    Node* nohData = search(node, data); // Encontra o nó com valor 'data'
    
    if (nohData == NULL) {
        return 0; // Se o nó não for encontrado, retorna 0
    }
    
    return qntSubnosRec(nohData); // Conta todos os subnós a partir de 'nohData'
}
