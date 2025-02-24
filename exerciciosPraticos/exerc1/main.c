#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilhaDinamica.h"
#include "fila_estaticaCircular.h"

/**
 * O objetivo da main é realizar uma série de testes para verificar o balanceamento
 * de diferentes sequências de parênteses, colchetes e chaves, usando uma função
 * que faz uso de pilha e fila para garantir a correta correspondência e ordem
 * dos símbolos.
 *
 * Os testes cobrem os seguintes cenários:
 * - Teste básico com uma sequência balanceada.
 * - Teste com excesso de símbolos de fechamento.
 * - Teste com sequência vazia.
 * - Teste com símbolos de abertura sem correspondentes de fechamento.
 * - Teste com símbolos de fechamento sem correspondentes de abertura.
 * - Teste com sequência alternada e balanceada.
 *
 * Cada teste é identificado com um título claro e acompanhado por uma função auxiliar
 * `testarBalanceamento` que imprime o resultado de cada caso.
 *
 */

/**
 * @brief Imprime um título centralizado e decorado para identificação de testes.
 *
 * A função `printTitle` imprime um título centralizado com símbolos '=' em ambos
 * os lados para separar visualmente os testes e melhorar a legibilidade.
 *
 * @param title O título a ser exibido.
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

    // Ajusta para comprimentos ímpares de título
    if (totalLength % 2 != titleLength % 2) 
        printf("="); 

    printf("\n"); // nova linha após o título
}

/**
 * @brief Verifica o balanceamento de uma sequência de parênteses, colchetes e chaves em uma fila.
 *
 * A função `verificaBalanceamento` analisa a sequência de símbolos contida em uma fila para
 * determinar se está balanceada em termos de parênteses `()`, colchetes `[]` e chaves `{}`.
 * Regras para uma sequência balanceada:
 * - Para cada símbolo de abertura há um símbolo de fechamento correspondente na ordem inversa.
 * - A sequência não deve conter mais símbolos de fechamento do que de abertura em nenhum ponto.
 *
 * @param fila A fila contendo a sequência de símbolos a ser verificada.
 * @param pilha A pilha usada para rastrear símbolos de abertura durante a verificação.
 * @return Retorna 1 se a sequência está balanceada, ou 0 caso esteja desbalanceada.
**/

int verificaBalanceamento(Fila *fila, Pilha* pilha) {
    Fila* filaAux = criarFila(getSize(fila));  // Fila auxiliar para restaurar o estado original
    int balanceado = 1;

    if (isEmpty(fila)) 
        return 1; // Considera balanceado se a fila está vazia

    while (!isEmpty(fila)) {
        char termoFila = dequeue(fila);
        enqueue(filaAux, termoFila);

        if (termoFila == ')' || termoFila == ']' || termoFila == '}') {
            if (isEmptyPilha(pilha)) {
                balanceado = 0; // Desbalanceado se há mais fechamentos que aberturas
                break;
            } else {
                char ultimoTermoPilha = pop(pilha);
                if ((ultimoTermoPilha == '(' && termoFila != ')') ||
                    (ultimoTermoPilha == '[' && termoFila != ']') ||
                    (ultimoTermoPilha == '{' && termoFila != '}')) {
                    balanceado = 0; // Desbalanceado se os pares não coincidem
                    break;
                }
            }
        } else {
            push(pilha, termoFila); // Guarda termos de abertura
        }
    }

    // Verifica se a pilha está vazia (se não estiver, há mais aberturas que fechamentos)
    if (!isEmptyPilha(pilha)) balanceado = 0;

    clearPilha(pilha); // Limpa a pilha para o estado inicial

    // Restaura a fila ao estado original
    while (!isEmpty(filaAux))
        enqueue(fila, dequeue(filaAux));

    clear(filaAux); // Libera memória de filaAux
    return balanceado;
}



/**
 * @brief Função auxiliar para verificar e exibir o resultado do balanceamento da fila.
 *
 * A função `testarBalanceamento` recebe uma fila e uma pilha, chama `verificaBalanceamento`
 * para determinar se a sequência na fila está balanceada, e imprime o resultado.
 *
 * @param fila A fila contendo a sequência de símbolos a ser verificada.
 * @param pilha A pilha usada na função de verificação de balanceamento.
 */
void testarBalanceamento(Fila* fila, Pilha* pilha) {
    printf("Fila: ");
    imprimir(fila);

    int resultado = verificaBalanceamento(fila, pilha);
    if (resultado == 1)
        printf("\n=> A fila está: Balanceada\n");
    else
        printf("\n=> A fila está: Desbalanceada\n");
}

int main() {
    int capacidadeFila = 20;
    Fila* fila = criarFila(capacidadeFila);
    Pilha* pilha = criarPilha();

    // 1. Teste com sequência balanceada básica
    printTitle("Teste 1: Sequência Balanceada Básica");
    enqueue(fila, '{');
    enqueue(fila, '(');
    enqueue(fila, ')');
    enqueue(fila, '}');
    testarBalanceamento(fila, pilha);

    // 2. Teste com desbalanceamento (excesso de fechamento)
    printTitle("Teste 2: Excesso de Fechamento");
    clear(fila);
    enqueue(fila, '{');
    enqueue(fila, '(');
    enqueue(fila, ')');
    enqueue(fila, '}');
    enqueue(fila, '}'); 
    
    testarBalanceamento(fila, pilha);

    // 3. Teste com sequência vazia
    printTitle("Teste 3: Sequência Vazia");
    clear(fila);
    testarBalanceamento(fila, pilha);

    // 4. Teste com apenas aberturas 
    printTitle("Teste 4: Apenas Aberturas");
    clear(fila);
    enqueue(fila, '{');
    enqueue(fila, '(');
    enqueue(fila, '[');
    testarBalanceamento(fila, pilha);

    // 5. Teste com apenas fechamentos 
    printTitle("Teste 5: Apenas Fechamentos");
    clear(fila);
    enqueue(fila, ')');
    enqueue(fila, ']');
    enqueue(fila, '}');
    testarBalanceamento(fila, pilha);

    // 6. Teste com sequência alternada e balanceada
    printTitle("Teste 6: Sequência Alternada e Balanceada");
    clear(fila);
    enqueue(fila, '{');
    enqueue(fila, '[');
    enqueue(fila, '(');
    enqueue(fila, ')');
    enqueue(fila, ']');
    enqueue(fila, '}');
    testarBalanceamento(fila, pilha);

    printf("\n");
    printTitle("Teste completo");

    clear(fila);
    clearPilha(pilha);

    return 0;
}
