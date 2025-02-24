#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaDupla.h"

/**
 * O objetivo da main é executar testes na estrutura de pilha dupla implementada.
 *
 * As operações testadas incluem:
 * - pushA e pushB para inserções até o limite de cada pilha
 * - getTop para verificar o elemento no topo de cada pilha
 * - clearA e clearB para esvaziar individualmente as pilhas
 * - popA e popB para remover elementos do topo de cada pilha
 *
 * Etapas do teste:
 * 1. Inicialização da pilha dupla com um tamanho máximo.
 * 2. Inserções na pilha A até o limite e verificação da pilha cheia.
 * 3. Obtenção do topo de A.
 * 4. Limpeza da pilha A para permitir testes na pilha B.
 * 5. Inserções na pilha B até o limite e verificação da pilha cheia.
 * 6. Obtenção do topo de B.
 * 7. Inserções parciais em ambas as pilhas e verificação dos estados.
 * 8. Inserções até o limite em ambas as pilhas em conjunto.
 * 9. Remoção de elementos de ambas as pilhas até que fiquem vazias.
 * 10. Limpeza completa das pilhas e finalização dos testes.
 *
 */


/**
 * @brief Imprime um título centralizado, decorado com símbolos de igual ('=') em ambos os lados.
 * 
 * Essa função adicional é apenas para fins de estética dos testes. Ela permite imprimir um título 
 * em uma linha, centralizado dentro de um comprimento fixo de 50 caracteres.
 * 
 */

void printTitle(const char *title) {
    int totalLength = 50; // comprimento padrão para os títulos dos testes
    int titleLength = strlen(title); // calcula o comprimento do título fornecido

    // calcula a qtd de espaço em branco à esquerda e à direita do título
    int padding = (totalLength - titleLength) / 2; 

    // Imprime os caracteres '=' à esquerda do título para centralizá-lo
    for (int i = 0; i < padding; i++) 
        printf("="); 

    printf(" %s ", title); 

    // Imprime os caracteres '=' à direita do título para completar o alinhamento
    for (int i = 0; i < padding; i++) 
        printf("="); 

    // Se a diferença entre o comprimento do título e o comprimento total for ímpar,
    // ajusta o número de '=' 
    if (totalLength % 2 != titleLength % 2) 
        printf("="); 

    printf("\n"); // nova linha após o título
}


int main() {
    int maxSize = 10;
    DoubleStack *stack = createDStack(maxSize);

    printTitle("Testando pushA e pushB até o limite");
    printf("\n");
    printTitle("Teste pilha A sozinha");
    
    int i = 1;
    // Inserir em A até o limite
    while (!isFull(stack)) {
        printf("Inserindo %d em A\n", i);
        pushA(stack, i);
        imprimirA(stack);
        printf("\n");
        i++;
    }

    // Verificar pilha cheia após pushA
    printf("Tentando inserir em A com a pilha cheia:\n");
    pushA(stack, 99);


    printf("\n");
    printTitle("Testando getTop para A");
    printf("Topo de A: %d\n", getTop(stack, 'A'));


    printf("Aplicando clear em A para fazer o mesmo teste em B\n");
    i = 1;
    clearA(stack);  // Limpar  A para testar o próximo caso
    imprimirA(stack);
    imprimirB(stack);


    printf("\n");
    printTitle("Teste pilha B sozinha");

    // Inserir em B até o limite
    while (!isFull(stack)) {
        printf("Inserindo %d em B\n", i * 10);
        pushB(stack, i * 10);
        imprimirB(stack);
        printf("\n");
        i++;
    }

    // Verificar pilha cheia após pushB
    printf("Tentando inserir em B com a pilha cheia:\n");
    pushB(stack, 99);


    printf("\n");
    printTitle("Testando getTop para B");
    printf("Topo de B: %d\n", getTop(stack, 'B'));

    printf("\n");
    printTitle("Teste getTop inválido");
    printf("Indicando pilha F: %d\n", getTop(stack, 'F'));

    printf("\n");
    printTitle("Teste inserção geral");

    printf("Esvaziar pilhas\n");
    clearA(stack);
    clearB(stack);
    imprimirA(stack);
    imprimirB(stack);

    printf("\nInserindo elementos em ambas as pilhas parcialmente:\n");
    for (i = 1; i <= maxSize / 4; i++) {
        printf("Inserindo %d em A\n", i);
        pushA(stack, i);
        imprimirA(stack);

        printf("Inserindo %d em B\n", i * 10);
        pushB(stack, i * 10);
        imprimirB(stack);
        printf("\n");
    }

    printf("\nEstado atual das pilhas:\n");
    imprimirA(stack);
    imprimirB(stack);


    printf("\n");
    printTitle("Topo atual");
    printf("Topo de A: %d\n", getTop(stack, 'A'));
    printf("Topo de B: %d\n", getTop(stack, 'B'));

    printf("\nInserindo mais elementos em ambas as pilhas até atingir o limite:\n");
    while (!isFull(stack)) {
        printf("Inserindo %d em A\n", i);
        pushA(stack, i);
        imprimirA(stack);

        printf("Inserindo %d em B\n", i * 10);
        pushB(stack, i * 10);
        imprimirB(stack);
        printf("\n");
        i++;
    }

    printf("Tentando inserir em ambas as pilhas com a pilha cheia:\n");
    pushA(stack, 99);
    pushB(stack, 99);

    printTitle("Topo atual");
    printf("Topo de A: %d\n", getTop(stack, 'A'));
    printf("Topo de B: %d\n", getTop(stack, 'B'));


    printf("\n");
    printTitle("Testando popA e popB");

    printf("Removendo elementos de A:\n");
    while (getTop(stack, 'A') != -1) {
        printf("Removendo topo de A: %d\n", popA(stack));
        imprimirA(stack);
    }
    printf("Tentativa de remover de A (esperado '-1'): %d\n", popA(stack));

    printf("\nRemovendo elementos de B:\n");
    while (getTop(stack, 'B') != -1) {
        printf("Removendo topo de B: %d\n", popB(stack));
        imprimirB(stack);
    }
    printf("Tentativa de remover de B (esperado '-1'): %d\n", popB(stack));


    printf("\n");
    printTitle("Testando clearA e clearB");

    for (int j = 1; j <= 3; j++) {
        pushA(stack, j);
        pushB(stack, j * 10);
    }

    printf("Pilha A antes de clearA: ");
    imprimirA(stack);
    clearA(stack);
    printf("Pilha A após clearA: ");
    imprimirA(stack);

    printf("\nPilha B antes de clearB: ");
    imprimirB(stack);
    clearB(stack);
    printf("Pilha B após clearB: ");
    imprimirB(stack);

    printf("\n");
    printTitle("Teste completo");
    free(stack->vet);
    free(stack);
    return 0;
}
