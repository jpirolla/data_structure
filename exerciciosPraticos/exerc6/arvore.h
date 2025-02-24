#ifndef TREE_H_INCLUDED
#define TREE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura Node
typedef struct Node{
    int data; // Dado armazenado no nó
    struct Node* left; // Ponteiro para o filho esquerdo
    struct Node* right; // Ponteiro para o filho direito
} Node;

// Definição da estrutura Tree
typedef struct{
    Node* root; // Ponteiro para a raiz da árvore
} Tree;

// Declaração das funções que manipulam a árvore

// Função para criar um novo nó
Node* createNode(int data); 

// Função para criar uma nova árvore
Tree* createTree(); 

// Função para inserir um novo nó na árvore
Node* insert( Node* node, int data ); 

// Função para buscar um nó na árvore
Node* search( Node* node, int data ); 

// Função para encontrar o nó com o maior valor
Node* getMaxNode( Node* node ); 

// Função para encontrar o nó com o menor valor
Node* getMinNode( Node* node ); 

// Função para deletar um nó da árvore
Node* deleteNode( Node* node, int data, char filhoSubstituto); 

// Função para percorrer a árvore em pré-ordem
void strPreorder(Node *node); 

// Função para percorrer a árvore em ordem
void strInorder(Node *node); 

// Função para percorrer a árvore em pós-ordem
void strPostorder(Node *node); 

// Função para contar o número de subnós de um nó específico
int qntSubnos(Node* node, int data); 

#endif // TREE_H_INCLUDED
