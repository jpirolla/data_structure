#include "lista_dupla_encadeada.h" // Inclui o arquivo de cabeçalho com a definição de estruturas e funções para lista duplamente encadeada.

#include <stdio.h>  
#include <stdlib.h> 

// Função para criar um novo nó
Node* criarNode(int data) {
    Node* novoNode = (Node*)malloc(sizeof(Node)); // Aloca memória para um novo nó
    if (novoNode == NULL) { // Verifica se a alocação falhou
        printf("Erro ao alocar memoria!\n");
        exit(1); // Encerra o programa se houver falha
    }
    //Atribui os valores iniciais para  o nó
    novoNode->data = data; 
    novoNode->next = NULL;   
    novoNode->prev = NULL;   
    return novoNode;         // Retorna o ponteiro para o novo nó
}

// Função para inicializar uma lista duplamente ligada
Lista* criarLista() {
    Lista* lista = (Lista*)malloc(sizeof(Lista)); // Aloca memória para a lista
    if (lista == NULL) { // Verifica se a alocação falhou
        printf("Erro ao alocar memoria!\n");
        exit(1); // Encerra o programa se houver falha
    }
    //Atribui os valores iniciais para  a lista ligada
    lista->head = NULL;
    lista->tail = NULL; 
    lista->size = 0;    
    return lista;       // Retorna o ponteiro para a lista
}

// Função para obter o tamanho da lista
int getSize(Lista* lista){
    return lista->size; // Retorna o tamanho da lista
}

// Função para verificar se a lista está vazia
int isEmpty(Lista* lista){
    return getSize(lista) == 0; // Retorna 1 (verdadeiro) se a lista estiver vazia, 0 (falso) caso contrário
}

// Função para inserir um elemento no início da lista
void insertHead(Lista* lista, int data){
    Node* newNode = criarNode(data); // Cria um novo nó com o dado fornecido

    if (getSize(lista) == 0) { // Se a lista estiver vazia, o nó se torna o primeiro e o último
        lista->head = newNode;
        lista->tail = newNode;
    } else { // Caso contrário, insere o novo nó antes do nó existente na cabeça
        newNode->next = lista->head;
        lista->head->prev = newNode;
        lista->head = newNode;
    }

    lista->size++; // Incrementa o tamanho da lista
    lista->ordenado = 0; // Marca a lista como não ordenada
}

// Função para inserir um elemento no final da lista
void insertTail(Lista* lista, int data){
    if (isEmpty(lista)) { // Se a lista estiver vazia, insere na cabeça
        insertHead(lista, data);
    } else { // Caso contrário, insere no final
        Node* newNode = criarNode(data);
        newNode->prev = lista->tail; // Ajusta o ponteiro do nó anterior para a cauda atual
        lista->tail->next = newNode; // Ajusta o ponteiro do próximo nó da cauda
        lista->tail = newNode;       // Atualiza a cauda para o novo nó
        lista->size++;               // Incrementa o tamanho da lista
        lista->ordenado = 0;         // Marca a lista como não ordenada
    }
}

// Função para inserir um elemento em uma posição específica da lista
void insert(Lista* lista, int data, int position){
    if (position <= getSize(lista)) { // Verifica se a posição é válida

        if (position == 0) { // Se a posição for 0, insere no início
            insertHead(lista, data);
        } else if (position == getSize(lista)) { // Se a posição for igual ao tamanho da lista, insere no final
            insertTail(lista, data);
        } else { // Caso contrário, insere no meio da lista
            Node* newNode = criarNode(data); // Cria o novo nó
            Node* auxNode = lista->head; // Ponteiro auxiliar para encontrar a posição correta
            for (int i = 0; i < position - 1; i++) { // Avança até o nó anterior à posição desejada
                auxNode = auxNode->next;
            }
            // Ajusta os ponteiros para inserir o novo nó entre os nós existentes
            newNode->prev = auxNode;
            newNode->next = auxNode->next;
            auxNode->next->prev = newNode;
            auxNode->next = newNode;

            lista->size++; // Incrementa o tamanho da lista
            lista->ordenado = 0; // Marca a lista como não ordenada
        }
    }
}

// Função para remover o primeiro nó da lista
void removeHead(Lista* lista){
    if (isEmpty(lista)) { // Verifica se a lista está vazia
        printf("Erro. Underflow!");
        return;
    }

    Node* nodeRemover = lista->head; // Ponteiro para o nó a ser removido

    if (getSize(lista) == 1) { // Se houver apenas um nó, limpa a cabeça e a cauda
        lista->tail = NULL;
        lista->head = NULL;
    } else { // Caso contrário, ajusta a cabeça e remove o nó
        lista->head = nodeRemover->next;
        lista->head->prev = NULL;
    }

    lista->size--; // Decrementa o tamanho da lista
    free(nodeRemover); // Libera a memória do nó removido
}

// Função para remover o último nó da lista
void removeTail(Lista* lista){
    if (isEmpty(lista)) { // Verifica se a lista está vazia
        printf("Erro. Underflow!");
        return;
    }

    Node* nodeRemover = lista->tail; // Ponteiro para o nó a ser removido

    if (getSize(lista) == 1) { // Se houver apenas um nó, limpa a cabeça e a cauda
        lista->tail = NULL;
        lista->head = NULL;
    } else { // Caso contrário, ajusta a cauda e remove o nó
        lista->tail = nodeRemover->prev;
        lista->tail->next = NULL;
    }

    lista->size--; // Decrementa o tamanho da lista
    free(nodeRemover); // Libera a memória do nó removido
}

// Função para remover um nó em uma posição específica
void removeNode(Lista* lista, int position){
    if (isEmpty(lista)) { // Verifica se a lista está vazia
        printf("Erro. Underflow!");
        return;
    }

    if (position < 0 || position >= getSize(lista)) { // Verifica se a posição é válida
        printf("Posição inválida!");
        return;
    }

    if (position == 0) { // Se a posição for 0, remove o primeiro nó
        removeHead(lista);
        return;
    }

    if (position == getSize(lista) - 1) { // Se a posição for a última, remove o último nó
        removeTail(lista);
        return;
    }

    Node* tempNode = lista->head; // Ponteiro auxiliar para encontrar o nó
    for (int i = 0; i < position; i++) { // Percorre até a posição desejada
        tempNode = tempNode->next;
    }

    // Ajusta os ponteiros dos nós ao redor para remover o nó
    tempNode->prev->next = tempNode->next;
    
    tempNode->next->prev = tempNode->prev;

    lista->size--; // Decrementa o tamanho da lista
    free(tempNode); // Libera a memória do nó removido
}

// Função para buscar um valor na lista
int busca(Lista* lista, int data){
    if (lista->ordenado == 1) { // Se a lista estiver ordenada, realiza busca binária
        return buscaBinaria(lista, data);
    } else { // Caso contrário, realiza busca linear
        Node* tempNode = lista->head;
        for (int i = 0; i < getSize(lista); i++) {
            if (tempNode->data == data) { // Se encontrar o valor, retorna o índice
                return i;
            }
            tempNode = tempNode->next;
        }
        return -1; // Retorna -1 se o valor não for encontrado
    }
}

// Função para limpar a lista
void clear(Lista* lista){
    while (getSize(lista) > 0) { // Remove todos os nós, um por um
        removeHead(lista);
    }
}

// Função para imprimir os elementos da lista
void printLista(Lista* lista){
    Node* nohAtual = lista->head;

    if (getSize(lista) == 0) { // Verifica se a lista está vazia
        printf("\n[]");
        return;
    }

    printf("\n[");
    while (nohAtual->next != NULL) { // Imprime os nós até o penúltimo
        printf(" %d ", nohAtual->data);
        nohAtual = nohAtual->next;
    }

    printf(" %d ]", nohAtual->data); // Imprime o último nó
}

// Função para ordenar a lista (insertion sort)
void ordenar(Lista* lista) {
    if (lista->head == NULL || lista->head->next == NULL) {
        return; // Lista já está ordenada ou contém apenas um elemento
    }

    Node* current = lista->head->next; // Começa a partir do segundo elemento

    while (current != NULL) {
        Node* temp = current;
        int key = current->data;

        // Move o nó atual para a posição correta entre os nós anteriores
        while (temp->prev != NULL && temp->prev->data > key) {
            temp->data = temp->prev->data; // Desloca o valor maior para frente
            temp = temp->prev; // Move-se para trás na lista
        }
        temp->data = key; // Insere o valor na posição correta

        current = current->next; // Passa ao próximo nó
    }
    lista->ordenado = 1; // Marca a lista como ordenada
}


// Função auxiliar para encontrar o nó do meio da lista
Node* meioLista(Lista* lista, int meio) {
    Node* nohMeio = lista->head;
    for (int k = 0; k < meio; k++) { // Corrigido para começar em 0
        nohMeio = nohMeio->next;
    }
    return nohMeio;
}

// Função recursiva para busca binária
int buscaBinariaRec(Lista* lista, int comeco, int fim, int x) {
    if (comeco > fim) { // Caso base: valor não encontrado
        return -1;
    }

    int meio = (comeco + fim) / 2; // Calcula o meio
    Node* nohMeio = meioLista(lista, meio); // Obtém o nó do meio

    if (nohMeio == NULL) { // Verificação de segurança
        return -1;
    }

    if (x == nohMeio->data) { // Se o valor for encontrado, retorna o índice
        return meio;
    }

    if (x < nohMeio->data) { // Se o valor procurado é menor, busca na metade esquerda
        return buscaBinariaRec(lista, comeco, meio - 1, x);
    }

    return buscaBinariaRec(lista, meio + 1, fim, x); // Busca na metade direita
}

// Função para busca binária
int buscaBinaria(Lista* lista, int x) {
    if (lista->ordenado != 1) { // Verifica se a lista está ordenada
        printf("Erro: a lista precisa estar ordenada para busca binária.\n");
        return -1;
    }
    return buscaBinariaRec(lista, 0, getSize(lista) - 1, x); // Chama a função recursiva de busca binária
}
