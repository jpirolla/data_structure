#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada_cruzada.h"

// Função para criar um novo nó com os dados fornecidos e posicionamento na matriz
Node* criarNode(int data, int row, int column) {
    Node* novoNode = (Node*)malloc(sizeof(Node));
    if (novoNode == NULL) { // Verifica a alocação de memória
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    // Inicializa os dados e os ponteiros para o próximo elemento na linha e coluna
    novoNode->data = data;
    novoNode->row = row;
    novoNode->column = column;
    novoNode->next_row = NULL;
    novoNode->next_column = NULL;
    return novoNode;
}

// Função para criar um cabeçalho de linha ou coluna
NodeHead* criarNodeHead(int index) {
    NodeHead* novoHead = (NodeHead*)malloc(sizeof(NodeHead));
    if (novoHead == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    // Inicializa o índice e os ponteiros do cabeçalho
    novoHead->index = index;
    novoHead->first = NULL;
    novoHead->next = NULL;
    return novoHead;
}

// Função para criar uma matriz esparsa, definindo o número de linhas e colunas
SparseMatrix* criarMatriz(int num_rows, int num_columns) {
    SparseMatrix* matriz = (SparseMatrix*)malloc(sizeof(SparseMatrix));
    matriz->head_row = NULL;
    matriz->head_column = NULL;
    matriz->num_rows = num_rows;
    matriz->num_columns = num_columns;
    matriz->size = 0; // Inicializa o tamanho da matriz com zero
    return matriz;
}

// Função para encontrar ou criar um cabeçalho de linha ou coluna
NodeHead* encontrarOuCriarHead(SparseMatrix* matriz, int index, int isRow) {
    NodeHead** head = isRow ? &matriz->head_row : &matriz->head_column;
    NodeHead* atual = *head;
    NodeHead* anterior = NULL;

    // Procura o cabeçalho com o índice fornecido, ordenado
    while (atual && atual->index < index) {
        anterior = atual;
        atual = atual->next;
    }

    // Retorna o cabeçalho se já existir
    if (atual && atual->index == index) {
        return atual;
    }

    // Cria e insere um novo cabeçalho, mantendo a ordenação
    NodeHead* novoHead = criarNodeHead(index);
    if (anterior == NULL) {
        novoHead->next = *head;
        *head = novoHead;
    } else {
        anterior->next = novoHead;
        novoHead->next = atual;
    }
    return novoHead;
}

// Função para remover um nó na posição especificada
void remover(SparseMatrix* matriz, int row, int column) {
    NodeHead* rowHead = encontrarOuCriarHead(matriz, row, 1);
    NodeHead* colHead = encontrarOuCriarHead(matriz, column, 0);

    Node* linhaAtual = rowHead->first;
    Node* colunaAtual = colHead->first;
    Node* anteriorLinha = NULL;
    Node* anteriorColuna = NULL;

    // Navega até a coluna correta
    while (linhaAtual && linhaAtual->column < column) {
        anteriorLinha = linhaAtual;
        linhaAtual = linhaAtual->next_column;
    }

    // Verifica se o nó está na posição correta
    if (!linhaAtual || linhaAtual->column != column) return;

    // Navega até a linha correta
    while (colunaAtual && colunaAtual->row < row) {
        anteriorColuna = colunaAtual;
        colunaAtual = colunaAtual->next_row;
    }

    // Remove as referências do nó na linha e coluna
    if (anteriorLinha) anteriorLinha->next_column = linhaAtual->next_column;
    else rowHead->first = linhaAtual->next_column;

    if (anteriorColuna) anteriorColuna->next_row = linhaAtual->next_row;
    else colHead->first = linhaAtual->next_row;

    // Libera a memória do nó
    free(linhaAtual);
    matriz->size--;
}

// Função para inserir um valor na matriz esparsa
void inserir(SparseMatrix* matriz, int data, int row, int column) {
    // Verifica se a posição está dentro dos limites da matriz
    if (row < 0 || column < 0 || row >= matriz->num_rows || column >= matriz->num_columns) return;

    NodeHead* rowHead = encontrarOuCriarHead(matriz, row, 1);
    NodeHead* colHead = encontrarOuCriarHead(matriz, column, 0);

    Node* linhaAtual = rowHead->first;
    Node* colunaAtual = colHead->first;
    Node* anteriorLinha = NULL;
    Node* anteriorColuna = NULL;

    // Navega até o ponto de inserção na linha e coluna
    while (linhaAtual && linhaAtual->column < column) {
        anteriorLinha = linhaAtual;
        linhaAtual = linhaAtual->next_column;
    }
    while (colunaAtual && colunaAtual->row < row) {
        anteriorColuna = colunaAtual;
        colunaAtual = colunaAtual->next_row;
    }

    // Atualiza ou remove o nó caso ele já exista
    if (linhaAtual && linhaAtual->row == row && linhaAtual->column == column) {
        if (data == 0) {
            remover(matriz, row, column);
        } else {
            linhaAtual->data = data;
        }
        return;
    }

    // Insere um novo nó caso o valor seja diferente de zero
    if (data != 0) {
        Node* novoNode = criarNode(data, row, column);

        // Insere o nó na linha
        if (anteriorLinha) {
            anteriorLinha->next_column = novoNode;
            novoNode->next_column = linhaAtual;
        } else {
            novoNode->next_column = rowHead->first;
            rowHead->first = novoNode;
        }

        // Insere o nó na coluna
        if (anteriorColuna) {
            anteriorColuna->next_row = novoNode;
            novoNode->next_row = colunaAtual;
        } else {
            novoNode->next_row = colHead->first;
            colHead->first = novoNode;
        }
        matriz->size++;
    }
}

// Função para buscar um valor na matriz esparsa
int buscar(SparseMatrix* matriz, int row, int column) {
    NodeHead* rowHead = encontrarOuCriarHead(matriz, row, 1);
    Node* linhaAtual = rowHead->first;

    while (linhaAtual && linhaAtual->column < column) {
        linhaAtual = linhaAtual->next_column;
    }
    return (linhaAtual && linhaAtual->column == column) ? linhaAtual->data : 0;
}

// Função para somar todos os elementos não-nulos da matriz
int somaInterna(SparseMatrix* matriz) {
    int soma = 0;
    NodeHead* linha = matriz->head_row;

    while (linha) {
        Node* elemento = linha->first;
        while (elemento) {
            soma += elemento->data;
            elemento = elemento->next_column;
        }
        linha = linha->next;
    }
    return soma;
}

// Função para somar duas matrizes esparsas e retornar uma nova matriz resultante
SparseMatrix* somar(SparseMatrix* matriz1, SparseMatrix* matriz2) {
    if (matriz1->num_rows != matriz2->num_rows || matriz1->num_columns != matriz2->num_columns) return NULL;

    SparseMatrix* resultado = criarMatriz(matriz1->num_rows, matriz1->num_columns);
    for (int i = 0; i < matriz1->num_rows; i++) {
        Node* node1 = encontrarOuCriarHead(matriz1, i, 1)->first;
        Node* node2 = encontrarOuCriarHead(matriz2, i, 1)->first;

        while (node1 || node2) {
            int valor = 0;
            int column;

            if (node1 && (!node2 || node1->column < node2->column)) {
                column = node1->column;
                valor = node1->data;
                node1 = node1->next_column;
            } else if (node2 && (!node1 || node2->column < node1->column)) {
                column = node2->column;
                valor = node2->data;
                node2 = node2->next_column;
            } else {
                column = node1->column;
                valor = node1->data + node2->data;
                node1 = node1->next_column;
                node2 = node2->next_column;
            }

            if (valor != 0) inserir(resultado, valor, i, column);
        }
    }
    return resultado;
}

// Função para imprimir todos os elementos não-nulos da matriz
void imprimir(SparseMatrix* matriz) {
    for (int i = 0; i < matriz->num_rows; i++) {
        NodeHead* rowHead = encontrarOuCriarHead(matriz, i, 1);
        Node* atual = rowHead->first;

        while (atual) {
            printf("Elemento em [%d][%d] = %d\n", atual->row, atual->column, atual->data);
            atual = atual->next_column;
        }
    }
}

float calculaEsparsidade(SparseMatrix *matriz) {
    if (matriz->size == 0) {
        return 1.0f; // Se não há elementos não-nulos, a matriz é totalmente esparsa
    }

    // Calcula o total de posições da matriz com base no número de linhas e colunas
    int totalLinhas = matriz->num_rows;
    int totalColunas = matriz->num_columns;
    int totalPosicoes = totalLinhas * totalColunas;

    // Obtém o número de elementos não-nulos
    int elementosNaoNulos = matriz->size;

    // Calcula a esparsidade
    float esparsidade = (float)(totalPosicoes - elementosNaoNulos) / totalPosicoes;

    return esparsidade;
}

void freeMatrix(SparseMatrix *matriz) {
    if (matriz == NULL) return;

    // Libera os nós de cada linha, navegando pela lista de cabeçalhos de linha
    NodeHead *current_row_head = matriz->head_row;
    while (current_row_head != NULL) {
        Node *current_node = current_row_head->first;
        while (current_node != NULL) {
            Node *temp = current_node;
            current_node = current_node->next_column; // Avança na linha
            free(temp); // Libera o nó atual
        }
        
        NodeHead *temp_row_head = current_row_head;
        current_row_head = current_row_head->next;
        free(temp_row_head); // Libera o cabeçalho da linha
    }

    // Libera os cabeçalhos de coluna
    NodeHead *current_col_head = matriz->head_column;
    while (current_col_head != NULL) {
        NodeHead *temp_col_head = current_col_head;
        current_col_head = current_col_head->next;
        free(temp_col_head); // Libera o cabeçalho da coluna
    }

    // Finalmente, libera a estrutura da matriz esparsa
    free(matriz);
}