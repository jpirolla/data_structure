#ifndef PILHADUPLA_H
#define PILHADUPLA_H

/**
 * @file pilhaDupla.h
 * @brief Definição de uma pilha dupla, onde duas pilhas compartilham o mesmo vetor de forma estática.
 *
 * Este arquivo define a estrutura de uma pilha dupla, onde duas pilhas compartilham
 * o mesmo vetor de dados. O acesso a cada pilha é feito através de dois índices distintos,
 * sendo um para a pilha A e outro para a pilha B. A estrutura não usa nós e, por isso, 
 * é alocada de forma estática.
 *
 * A pilha A começa do índice 0 e cresce para a direita, enquanto a pilha B começa do final 
 * do vetor e cresce para a esquerda. Ambas as pilhas podem ser manipuladas independentemente.
 * 
 * @note Este código assume que a alocação do vetor será feita com um tamanho fixo e máximo,
 * definido na criação da pilha. Não há alocação dinâmica para as pilhas individualmente.
 */

typedef struct DoubleStack {
    int *vet; /** Ponteiro para o vetor que armazena os dados das pilhas. */
    int topA; /** Índice do topo da pilha A. */
    int topB; /** Índice do topo da pilha B. */
    int max;  /** Tamanho máximo do vetor (máximo de elementos para ambas as pilhas combinadas). */
} DoubleStack;

/**
 * @brief Cria e inicializa uma nova pilha dupla.
 *
 * Esta função aloca e inicializa uma pilha dupla com um vetor de tamanho especificado.
 * Os índices dos topos das pilhas A e B são definidos de forma a permitir o uso do 
 * mesmo vetor de forma independente para as duas pilhas.
 *
 * @param size Tamanho máximo da pilha (o tamanho do vetor compartilhado entre as pilhas).
 * @return DoubleStack* Ponteiro para a pilha dupla criada
 */
DoubleStack *createDStack(int size);

/**
 * @brief Verifica se a pilha dupla está cheia.
 * A pilha dupla está cheia quando os topos das pilhas A e B se encontram.
 *
 * @param stack Ponteiro para a pilha dupla.
 * @return int Retorna 1 se a pilha estiver cheia, caso contrário, retorna 0.
 */
int isFull(DoubleStack *stack);

/**
 * @brief Insere um valor no topo da pilha A.
 * Esta função empilha um valor na pilha A. Se a pilha A estiver cheia, a operação
 * não será realizada.
 *
 * @param stack Ponteiro para a pilha dupla.
 * @param data Valor a ser inserido na pilha A.
 */
void pushA(DoubleStack *stack, int data);

/**
 * @brief Insere um valor no topo da pilha B.
 * Esta função empilha um valor na pilha B. Se a pilha B estiver cheia, a operação
 * não será realizada.
 *
 * @param stack Ponteiro para a pilha dupla.
 * @param data Valor a ser inserido na pilha B.
 */
void pushB(DoubleStack *stack, int data);

/**
 * @brief Remove e retorna o valor do topo da pilha A.
 * Esta função desempilha um valor da pilha A. Se a pilha A estiver vazia, a função
 * retorna -1.
 *
 * @param stack Ponteiro para a pilha dupla.
 * @return valor removido do topo da pilha A.
 */
int popA(DoubleStack *stack);

/**
 * @brief Remove e retorna o valor do topo da pilha B.
 * Esta função desempilha um valor da pilha B. Se a pilha B estiver vazia, a função
 * retorna -1.
 *
 * @param stack Ponteiro para a pilha dupla.
 * @return valor removido do topo da pilha B.
 */
int popB(DoubleStack *stack);

/**
 * @brief Limpa (desempilha todos os elementos de) a pilha A.
 * Esta função limpa a pilha A, removendo todos os elementos.
 *
 * @param stack Ponteiro para a pilha dupla.
 */
void clearA(DoubleStack *stack);

/**
 * @brief Limpa (desempilha todos os elementos de) a pilha B.
 * Esta função limpa a pilha B, removendo todos os elementos.
 *
 * @param stack Ponteiro para a pilha dupla.
 */
void clearB(DoubleStack *stack);

/**
 * @brief Imprime todos os elementos da pilha A.
 * Esta função imprime os elementos da pilha A, desde o topo até a base, sem alterar
 * o estado da pilha e respeitando a restrição de acesso
 *
 * @param stack Ponteiro para a pilha dupla.
 */
void imprimirA(DoubleStack *stack);

/**
 * @brief Imprime todos os elementos da pilha B.
 * Esta função imprime os elementos da pilha B, desde o topo até a base, sem alterar
 * o estado da pilha e respeitando a restrição de acesso
 *
 * @param stack Ponteiro para a pilha dupla.
 */
void imprimirB(DoubleStack *stack);

/**
 * @brief Retorna o valor do topo de uma pilha (A ou B).
 * Esta função retorna o valor no topo de uma pilha específica (A ou B), ou -1
 * caso a pilha esteja vazia. Para caracteres invalidos, também apresenta uma mensagem.
 *
 * @param stack Ponteiro para a pilha dupla.
 * @param pilha Especifica qual pilha ('A' ou 'B') acessar.
 * @return int valor no topo da pilha especificada, ou -1 se a pilha estiver vazia.
 */
int getTop(DoubleStack *stack, char pilha);

#endif
