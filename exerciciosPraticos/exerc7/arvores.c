#include<stdio.h>
#include<stdlib.h>
#include "arvores.h"

/*
    Estruturas principais:
    1. Node: Representa um nó da árvore binária, que armazena dados e ponteiros para os filhos (esquerdo e direito).
    2. Tree: Contém o ponteiro para o nó raiz da árvore.
*/

/**
 * @brief Cria um novo nó na árvore binária.
 *
 * Função responsável por alocar memória para um novo nó e inicializar seus valores.
 * O nó criado terá o valor de dados atribuído e os ponteiros para os filhos serão definidos como NULL.
 *
 * @param data O valor a ser armazenado no nó.
 * @return Node* Ponteiro para o novo nó criado.
 */
Node *createNode(int data){
   
    Node *node = (Node*)malloc(sizeof(Node));

    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

/**
 * @brief Cria uma nova árvore binária.
 *
 * Função responsável por alocar memória para uma nova árvore binária e 
 * inicializar o ponteiro para a raiz como NULL.
 *
 * @return Tree* Ponteiro para a árvore criada.
 */
Tree *createTree(){

   Tree *tree = (Tree *)malloc(sizeof(Tree));
   tree->root = NULL;
   return tree; 

}

/**
 * @brief Insere um valor na árvore binária de forma recursiva.
 *
 * Função que insere um valor na árvore binária, comparando-o com os valores dos nós e decidindo se o valor
 * deve ser inserido à esquerda ou à direita do nó atual.
 *
 * @param node Ponteiro para o nó atual da árvore.
 * @param value O valor a ser inserido.
 * @return Node* Ponteiro para o nó atualizado após a inserção.
 */
Node *insert(Node *node, int value){

   //caso base se o ponteiro de node aponta p nulo, tenho que criar um novo nó
   // Os outros casos avalio se é menor que o nó ou maior 

   if (node == NULL){ 
        Node *newNode = createNode(value);
        //printf("valor do novo nó que foi adicionado: %d", newNode->data);
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
/**
 * @brief Realiza uma busca na árvore binária.
 *
 * Função que realiza uma busca na árvore binária, comparando o valor procurado com o valor do nó atual
 * e decidindo se a busca deve continuar à esquerda ou à direita.
 *
 * @param node Ponteiro para o nó atual da árvore.
 * @param data O valor a ser buscado.
 * @return int Retorna 1 se o valor for encontrado, 0 caso contrário.
 */
int search(Node *node, int data){

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

/**
 * @brief Encontra o nó com o menor valor da árvore binária.
 *
 * Função recursiva que percorre a árvore para encontrar o nó mais à esquerda,
 * que é o nó com o menor valor.
 *
 * @param node Ponteiro para o nó atual da árvore.
 * @return Node* Ponteiro para o nó com o menor valor encontrado.
 */
Node *getMinNode(Node *node){

   if(node == NULL){
    return NULL;
   }

    // Quando eu chegar no nó esquerdo que não tiver filho (ou seja node->left for nulo), retorno o nó
    if(node->left == NULL){
    return node;    
   }

    return getMinNode(node->left);
    
}

/**
 * @brief Encontra o nó com o maior valor da árvore binária.
 *
 * Função recursiva que percorre a árvore para encontrar o nó mais à direita,
 * que é o nó com o maior valor.
 *
 * @param node Ponteiro para o nó atual da árvore.
 * @return Node* Ponteiro para o nó com o maior valor encontrado.
 */
Node *getMaxNode(Node *node){
    if (node == NULL){
        return NULL;
    }

    if (node->right == NULL){
        return node;
    }

    return getMaxNode(node->right);
}

/**
 * @brief Deleta um nó da árvore binária.
 *
 * Função recursiva que deleta um nó da árvore binária. Se o nó a ser deletado tiver filhos, o nó
 * será substituído por um nó à direita ou o maior à esquerda, dependendo da escolha.
 *
 * @param node Ponteiro para o nó atual da árvore.
 * @param data O valor do nó a ser deletado.
 * @param filhoSubstituto Se for 'D', substitui pelo nó à direita; se for 'E', substitui
 * pelo nó à esquerda.
 * @return Node* Ponteiro para a árvore atualizada após a exclusão.
 */
Node *deleteNode(Node *node, int data, char filhoSubstituto){

    // caso base
    if(node == NULL){
        return node;
    }

    // percorrer recursivamente para achar
    if(data < node->data){
        node->left = deleteNode(node->left, data, filhoSubstituto);
    }
    
    if (data > node->data){
        node->right = deleteNode(node->right, data, filhoSubstituto);
    }

    // encontrou o nó a ser excluido
    else{
        // se for um nó que nao tem filhos à esquerda
        if (node->left == NULL){
            //guardamos o ponteiro para o filho direito (se houver) em tempNode.
            Node *tempNode = node->right;
            free(node);

            // Retornamos o ponteiro para o filho direito do nó excluído (ou NULL, se ele não tiver filho direito). 
            // Isso faz com que, na árvore, o pai do nó deletado passe a apontar para o filho direito (ou NULL, se não houver nenhum).

            return tempNode;
        }

        else if( node->right == NULL ){
            Node* tempNode = node->left;
            free(node);
            return tempNode;
        }

        // se o no tem 2 filhos
        Node *tempNode;
        if (filhoSubstituto = 'D'){
                //Encontrar um nó substituto que mantenha a ordem 
                // o menor de todos do lado direito
                tempNode = getMinNode(node->right);
                node->data = tempNode->data;
                node->right = deleteNode(node->right,
                                        tempNode->data,
                                        filhoSubstituto);
            }
            else{
                // o maior de todos do lado esquerdo
                tempNode = getMaxNode(node->left);
                node->data = tempNode->data;
                node->left = deleteNode(node->left,
                                        tempNode->data,
                                        filhoSubstituto);
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


void strInOrder(Node *node) {
    if (node != NULL) {

        strInOrder(node->left);
        printf("%d ", node->data);
        strInOrder(node->right);
    }
}


void strPostOrder(Node *node) {
    if (node != NULL) {

        strPostOrder(node->left);
        strPostOrder(node->right);
        printf("%d ", node->data);
    }
}


void caminhos(Node *node, int somaAtual){
    /*
    Função baseada no search
    A cada nó percorrido, incremento com o valor do nó
    */

    if (node == NULL) {
        return;
    }

    // Atualiza a soma acumulada com o valor do nó atual
    somaAtual += node->data;

    // Se o nó é folha (não tem filhos à esquerda nem à direita)
    if (node->left == NULL && node->right == NULL) {
        printf("%d ", somaAtual);
        return;
    }

    // Chama a função recursivamente para os filhos esquerda e direita
    caminhos(node->left, somaAtual);
    caminhos(node->right, somaAtual);
}