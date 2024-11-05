# Estruturas de Dados

## Índice
1. [Introdução](#introdução)
2. [Estruturas Lineares](#estruturas-lineares)
   - [Arrays](#arrays)
   - [Listas Ligadas](#listas-ligadas)
   - [Pilhas (Stacks)](#pilhas-stacks)
   - [Filas (Queues)](#filas-queues)
3. [Estruturas Não Lineares](#estruturas-não-lineares)
   - [Árvores](#árvores)
   - [Grafos](#grafos)
4. [Tabelas de Dispersão (Hash Tables)](#tabelas-de-dispersão-hash-tables)
5. [Algoritmos de Ordenação e Pesquisa](#algoritmos-de-ordenação-e-pesquisa)
6. [Complexidade de Tempo e Espaço](#complexidade-de-tempo-e-espaço)
7. [Referências](#referências)

## Introdução
Estruturas de dados são formas de organizar e armazenar dados para que possam ser acessados e manipulados de maneira eficiente. Cada estrutura é projetada para casos de uso específicos e possui vantagens e desvantagens dependendo do tipo de aplicação. Compreender estruturas de dados é essencial para desenvolver algoritmos eficientes e é uma habilidade fundamental em programação.

## Estruturas Lineares

### Arrays
Um array é uma coleção de elementos de mesmo tipo armazenados em posições contíguas de memória. Ele permite acesso rápido a qualquer elemento usando um índice, mas possui tamanho fixo e operações de inserção e remoção custosas.

### [Pilhas (Stacks)](https://github.com/jpirolla/data_structure/tree/main/TAD_stack)
Uma pilha é uma estrutura de dados que segue o princípio LIFO (Last In, First Out). A última coisa que é adicionada à pilha é a primeira a ser removida. As operações principais são `push` (inserir) e `pop` (remover).

**Uso:** Controle de chamadas de funções em uma linguagem de programação.

### Filas (Queues)
Uma fila é uma estrutura de dados que segue o princípio FIFO (First In, First Out). O primeiro elemento inserido é o primeiro a ser removido. As operações principais são `enqueue` (inserir) e `dequeue` (remover).

### Listas Ligadas
Listas ligadas são uma coleção de elementos chamados "nós", onde cada nó armazena um valor e uma referência para o próximo nó. Elas são dinâmicas e facilitam a inserção e remoção de elementos, mas possuem acesso sequencial, o que as torna mais lentas para acesso a elementos específicos.


## Estruturas Não Lineares

### Árvores
Árvores são estruturas hierárquicas que consistem em nós com uma relação de "pai e filho". A árvore binária, um tipo comum, possui no máximo dois filhos para cada nó. Árvores são usadas para representar dados hierárquicos e para operações de busca rápida em grandes conjuntos de dados.


### Grafos
Grafos consistem em um conjunto de nós conectados por arestas, podendo ser direcionados ou não. Grafos são úteis para representar relacionamentos complexos entre dados.


## Tabelas de Dispersão (Hash Tables)
Tabelas de dispersão utilizam uma função de hash para mapear chaves a valores, permitindo acesso rápido aos dados. Elas são eficientes para operações de inserção, remoção e busca, mas podem sofrer de colisões, quando duas chaves geram o mesmo índice.

## Algoritmos de Ordenação e Pesquisa

- **Algoritmos de Ordenação:** São métodos para organizar dados em uma ordem específica. Exemplos incluem:
  - **Bubble Sort** 
  - **Selection Sort** 
  - **Insertion Sort** 
  - **Merge Sort** 
  - **Quick Sort**

- **Algoritmos de Pesquisa:** São métodos para encontrar elementos dentro de uma estrutura de dados. 
  - **Busca Linear:** Percorre todos os elementos até encontrar o valor desejado.
  - **Busca Binária:** Utilizada em arrays ordenados, divide o conjunto ao meio a cada comparação.

## Complexidade de Tempo e Espaço
A eficiência de uma estrutura de dados ou algoritmo é medida pela sua complexidade de tempo (quanto tempo leva para executar) e complexidade de espaço (quanta memória utiliza). 

- **O(1):** Constante (acesso direto, como em arrays).
- **O(log n):** Logarítmica (exemplo: busca binária).
- **O(n):** Linear (exemplo: busca em lista).
- **O(n²):** Quadrática (exemplo: Bubble Sort em sua forma mais básica).


## Referências
- **Livros:** "Estruturas de Dados e Algoritmos em C" por Robert Lafore, "Algoritmos: Teoria e Prática" por Thomas H. Cormen, Charles E. Leiserson, Ronald L. Rivest, e Clifford Stein.
- **Aulas**: Disciplinas de Análise e Estrutura de Dados e Introdução à Ciência da Computação 2 cursadas no segundo semestre de 2024 na USP.
