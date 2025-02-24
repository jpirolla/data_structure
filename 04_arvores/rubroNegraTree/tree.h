#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define RED 1
#define BLACK 0

typedef struct Node{

    int data;
    int color; // RED ou BLACK
    struct Node* left;
    struct Node* right;
    struct Node* parent;

} Node;

typedef struct{
    Node* root;
}Tree;

Node* createNode(int data);

Tree* createTree();

void insert( Tree* tree, int data );

void trataInsert(Tree* tree, Node* currentNode);

int search( Node* node, int data );

Node* getMaxNode( Node* node );

Node* getMinNode( Node* node );

void strPreorder(Node *node);

int max(int a, int b);

Node* leftRotation(Tree* tree, Node* node);
Node* rightRotation(Tree* tree, Node* node);
Node* leftRightRotation(Tree* tree, Node* node);
Node* rightLeftRotation(Tree* tree, Node* node);


#endif // TREE_H_INCLUDED
