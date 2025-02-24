#ifndef LISTA_LIGADA_CRUZADA_H_INCLUDED
#define LISTA_LIGADA_CRUZADA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

// Estrutura para representar um nó da matriz esparsa
typedef struct Node {
    int data;
    int row;
    int column;
    struct Node* next_row;
    struct Node* next_column;
} Node;

// Estrutura para representar os cabeçalhos de linha e coluna
typedef struct NodeHead {
    int index;
    Node* first;
    struct NodeHead* next;
} NodeHead;

// Estrutura para representar a matriz esparsa
typedef struct SparseMatrix {
    NodeHead* head_row;
    NodeHead* head_column;
    int num_rows;
    int num_columns;
    int size;
} SparseMatrix;

// Função para criar um novo nó de dados na matriz esparsa, armazenando o valor e as coordenadas
// O nó inclui os ponteiros para os próximos elementos nas direções de linha e coluna
Node* criarNode(int data, int row, int column);

// Função para criar um cabeçalho de linha ou coluna
// O cabeçalho armazena o índice da linha ou coluna e um ponteiro para o primeiro nó da respectiva linha ou coluna
NodeHead* criarNodeHead(int index);

// Função para inicializar uma nova matriz esparsa com o número de linhas e colunas especificado
// Define os cabeçalhos de linha e coluna como NULL e o tamanho inicial da matriz como zero
SparseMatrix* criarMatriz(int num_rows, int num_columns);

// Função para encontrar ou criar um cabeçalho de linha ou coluna em uma matriz esparsa
// Se o cabeçalho correspondente ao índice solicitado não existir, ele é criado e inserido na lista de cabeçalhos
NodeHead* encontrarOuCriarHead(SparseMatrix* matriz, int index, int isRow);

// Função para remover um nó de dados em uma posição especificada na matriz esparsa
// Encontra o nó e remove suas referências da lista de linha e coluna, liberando a memória ocupada
void remover(SparseMatrix* matriz, int row, int column);

// Função para inserir ou atualizar um valor na matriz esparsa em uma posição especificada
// Se o valor for zero e o nó existir, ele será removido; se o valor for diferente de zero, ele será inserido ou atualizado
void inserir(SparseMatrix* matriz, int data, int row, int column);

// Função para buscar o valor de um elemento na matriz esparsa em uma posição especificada
// Retorna o valor se o nó existir ou zero caso contrário
int buscar(SparseMatrix* matriz, int row, int column);

// Função para somar internamente todos os valores não-nulos da matriz esparsa
// Percorre todos os nós e acumula seus valores, retornando o resultado da soma
int somaInterna(SparseMatrix* matriz);

// Função para somar duas matrizes esparsas e retornar uma nova matriz esparsa contendo o resultado
// Cria uma nova matriz, percorre ambas as matrizes e insere a soma dos valores em posições correspondentes
SparseMatrix* somar(SparseMatrix* matriz1, SparseMatrix* matriz2);


// Função para imprimir todos os elementos não-nulos da matriz esparsa
// Percorre todos os nós e exibe as coordenadas e valores dos elementos armazenados
void imprimir(SparseMatrix* matriz);

float calculaEsparsidade(SparseMatrix *matriz);
void freeMatrix(SparseMatrix *matriz);

#endif
