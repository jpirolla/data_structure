#ifndef ARVORES_H_INCLUDED
#define ARVORES_H_INCLUDED

// Estrutura que representa um nó da árvore binária.
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

// Estrutura que representa a árvore binária.
typedef struct Tree{
    Node *root;
} Tree;

// Cria um novo nó na árvore binária.
Node *createNode(int data);

//Cria uma nova árvore binária.
Tree *createTree();

//Deleta um nó da árvore binária.
Node *deleteNode( Node* node, int data, char filhoSubstituto);

// insere valor na árvore
Node *insert(Node *node, int data);

// busca um valor a partir do no atual passado
int search(Node *atualNode, int valor);

// obter maior e menor nó da árvore
Node *getMinNode(Node *rootNode);
Node *getMaxNode(Node *rootNode);

// funções para percorrer a arvore
void strPreOrder(Node *node);
void strInOrder(Node *node);
void strPostOrder(Node *node);

// calcula a soma dos caminhos 
void caminhos(Node *node, int somaAtual);

#endif

