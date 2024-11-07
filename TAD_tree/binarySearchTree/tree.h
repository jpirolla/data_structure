#ifndef TREE_H
#define TREE_H

// struct para definir os nós que vao compor a árvore
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}Node;

// struct para criar a árvore -> nela só tenho o meu nó raiz
typedef struct Tree{
    Node *root;
} Tree; 


Node *createNode(int data);
Tree *createTree();
Node* deleteNode( Node* node, int data);

// para inserir um valor na árvore, preciso saber o nó que vou inserir e o dado
Node* insert(Node *node, int data);

// para buscar, preciso saber onde vou começar a buscar e o valor buscado
int search(Node *atualNode, int valor);

// para contar quantos nós tem, tenho que passar o nó raiz que vai iniciar a contagem
Node* getMinNode(Node *rootNode);
Node* getMaxNode(Node *rootNode);

// funções para percorrer a arvore
void strPreOrder(Node *node);
void strInOrder(Node *node);
void strPostOrder(Node *node);



#endif