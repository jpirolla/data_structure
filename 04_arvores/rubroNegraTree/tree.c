#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node* createNode(int data){
    Node* node = (Node*) malloc( sizeof(Node) );

    node->data = data;
    node->color = RED; // novo noh deve sempre ser vermelho
    node->left = NULL;
    node->right = NULL;
    node->parent = NULL;

    return node;
}

Tree* createTree(){
    Tree* tree = (Tree*) malloc( sizeof(Tree) );

    tree->root = NULL;
    return tree;
};

void insert( Tree* tree, int data ){

    Node* newNode = createNode(data);
    Node* father = NULL;
    Node* currentNode = tree->root;

    // insercao padrao de uma arvore binaria de busca
    while (currentNode != NULL) {
        father = currentNode;
        if (newNode->data < currentNode->data) {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }
    newNode->parent = father;

    if (father == NULL) {
        tree->root = newNode;  // A árvore estava vazia
    } else if (newNode->data < father->data) {
        father->left = newNode;
    } else {
        father->right = newNode;
    }

    // tratar a arvore, pois ela pode ter deixado de ficar equilibrada
    trataInsert(tree, newNode);
}

// Corrigir as propriedades da Árvore Rubro-Negra após a inserção
void trataInsert(Tree* tree, Node* currentNode){

    // iremos partir do noh atual em direcao a raiz corrigindo os problemas
    while (currentNode != tree->root && currentNode->parent->color == RED) {

        Node *father, *uncle, *grandfather;

        father = currentNode->parent;
        grandfather = father->parent;
        uncle = grandfather->left; // temporario (essa posicao pode estar errada, mas, nesse caso, o if abaixo ira corrigir)

        if (father == grandfather->left){
            uncle = grandfather->right;
        }

        // primeiro caso: tio e pai vermelhos (ja sabemos que o pai eh vermelho, pois entrou no while)
        if (uncle != NULL && uncle->color == RED) {

            father->color = BLACK;
            uncle->color = BLACK;
            grandfather->color = RED;
            currentNode = grandfather; // mudamos o noh atual para o avo, pois a alteracao possa ter estragado o avo
        }
        // o tio é preto
        else{


            // segundo caso: o tio eh preto e o noh atual e seu pai sao filhos esquerdos
            if (father == grandfather->left && currentNode == father->left){

                    father->color = BLACK;
                    grandfather->color = RED;

                    // rotacao direita
                    rightRotation(tree, grandfather);
            }

            // terceiro caso: o tio eh preto e o noh atual e seu pai sao filhos direitos
            else if (father == grandfather->right && currentNode == father->right){

                    father->color = BLACK;
                    grandfather->color = RED;

                    // rotacao esquerda
                    leftRotation(tree, grandfather);
            }

            // quarto caso: o tio eh preto, o pai eh filho esquerdo e o noh atual eh filho direito
            else if (father == grandfather->right && currentNode == father->right){

                currentNode->color = BLACK;
                grandfather = RED;

                leftRotation(tree, father);
                rightRotation(tree, grandfather);

            }

            // quinto caso: o tio eh preto, o pai eh filho direito e o noh atual eh filho esquerdo
            else if (father == grandfather->right && currentNode == father->right){

                currentNode->color = BLACK;
                grandfather = RED;

                currentNode = currentNode->parent;
                rightRotation(tree, currentNode);


                leftRotation(tree, currentNode->parent->parent);

            }
        }
    }
    tree->root->color = BLACK;  // A raiz deve ser sempre preta
}

// Função para realizar rotação à esquerda
Node* leftRotation(Tree* tree, Node* root) {
    Node* newRoot = root->right;
    root->right = newRoot->left;

    if (newRoot->left != NULL) {
        newRoot->left->parent = root;
    }

    newRoot->parent = root->parent;

    if (root->parent == NULL) {
        tree->root = newRoot;
    } else if (root == root->parent->left) {
        root->parent->left = newRoot;
    } else {
        root->parent->right = newRoot;
    }

    newRoot->left = root;
    root->parent = newRoot;

    return newRoot;
}

// Função para realizar rotação à direita
Node* rightRotation(Tree* tree, Node* root){

    // aplica a rotacao direita
    Node* newRoot = root->left;
    root->left = newRoot->right;
    newRoot->right = root;

    // --- daqui para baixo arruma os pais que foram trocados

    // se a raiz não possui pai, significa que ela eh a raiz da arvore
    // a nova raiz assumira o lugar da raiz antiga como raiz da arvore
    if(root->parent==NULL){
        tree->root = newRoot;
    }
    // verifica se esta no lado esquerdo
    else if(root == root->parent->left){
        root->parent->right = newRoot; // indica que o novo filho direito do pai da raiz atual sera a nova raiz
    }
    // verifica se esta no lado direito
    else{
        root->parent->left = newRoot; // indica que o novo filho esquerdo do pai da raiz atual sera a nova raiz
    }

    // o novo pai do filho direito da nova raiz sera a raiz antiga
    if (newRoot->right != NULL) {
        newRoot->right->parent = root;
    }

    // troca o pai da nova raiz. O novo pai sera o pai da raiz antiga
    newRoot->parent = root->parent;

    // troca o pai da raiz antiga. O novo pai sera a nova raiz
    root->parent = newRoot;

    return newRoot;
}

int max(int a, int b){
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int search( Node* node, int data ){

    if (node == NULL){
        return 0;
    }

    if (data == node->data){
        return 1;
    }

    int achou;
    // verifica se vai para o lado esquerdo
    if (data < node->data){
        achou = search(node->left, data);
    }
    // vai para o lado direito
    else{
        achou = search(node->right, data);
    }

    return achou;

}

Node* getMaxNode( Node* node ){

    if (node == NULL){
        return NULL;
    }

    if (node->right == NULL){
        return node;
    }

    return getMaxNode( node->right );

}

Node* getMinNode( Node* node ){

    if (node == NULL){
        return NULL;
    }

    if (node->left == NULL){
        return node;
    }

    return getMinNode( node->left );

}

void strPreorder(Node *node){
    if( node != NULL ){

        char cor;
        if(node->color == RED){
            cor = 'R';
        }
        else{
            cor = 'B';
        }

        printf("%d[%c] ", node->data, cor );
        strPreorder(node->left);
        strPreorder(node->right);
    }
}


