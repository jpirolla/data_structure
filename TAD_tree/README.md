# Estrutura de Dados: Árvores

Este repositório apresenta um resumo dos principais conceitos e operações relacionados à estrutura de dados **Árvore**. O foco é explorar árvores gerais e árvores binárias, com códigos que demonstram a estrutura básica do TAD. Conceitos mais avançados, como árvores-B, podem ser adicionados futuramente.

## O que é uma Árvore?

Uma **árvore** é uma estrutura de dados hierárquica que consiste em nós conectados por arestas, sem formar ciclos. É usada para representar relações de hierarquia entre elementos. Algumas características básicas:

- Um nó especial de origem chamado **raiz**.
- **Subárvores** conectadas abaixo da raiz e de outros nós.
- Cada nó tem um **sucessor** e um único nó que o aponta, exceto a raiz.
- **Folhas** são nós sem filhos.

**Exemplo**: Em uma árvore de diretórios de um sistema operacional, a raiz pode ser a pasta principal, com subpastas como filhos.

## Estrutura e Propriedades

- **Caminho**: sequência de nós que conecta um nó a outro.
- **Profundidade**: distância entre a raiz e um nó específico.
- **Altura**: profundidade máxima da árvore.

Uma árvore pode ser considerada um tipo especial de grafo:
- Não-direcionado.
- Conexo.
- Acíclico.

## Tipos de Árvores

1. **Árvore Binária**: cada nó tem no máximo dois filhos (esquerda e direita).
2. **Árvore Binária de Busca**: estrutura binária ordenada onde:
   - Todos os nós à esquerda são menores que o nó raiz.
   - Todos os nós à direita são maiores que o nó raiz.
3. **B-árvore**: usada para armazenar dados em discos, onde um nó pode ter mais de dois filhos.

## Operações em Árvores

As operações comuns incluem:

1. **Inserção**: Adiciona um nó mantendo a estrutura da árvore.
2. **Busca**: Localiza um valor específico na árvore.
3. **Contagem de Nós**: Conta o número total de nós na árvore.
4. **Percurso**: Caminho pelos nós da árvore em uma ordem específica (detalhes abaixo).

### Tipos de Percurso

1. **In-Order (Intra-ordem)**: Visita a subárvore esquerda, o nó raiz, e a subárvore direita.
   - Útil para imprimir elementos em ordem crescente em árvores binárias de busca.

2. **Pre-Order (Pré-ordem)**: Visita a raiz primeiro, depois a subárvore esquerda e, por último, a subárvore direita.
   - Usado para copiar ou exportar a estrutura da árvore.

3. **Post-Order (Pós-ordem)**: Visita a subárvore esquerda e direita primeiro, e depois a raiz.
   - Ideal para operações de remoção ou liberação de memória.

## Implementação

Funções básicas para implementação de uma árvore binária incluem:

1. **Criação da Árvore**: Inicializa uma árvore vazia, geralmente apontando para `NULL`.
2. **Criação de Nó**: Define um novo nó com um valor específico.
3. **Inserção**: Insere um nó na posição correta, mantendo a ordenação.
4. **Busca**: Pesquisa um valor, começando pela raiz e seguindo pelas subárvores.
5. **Contagem de Elementos**: Conta o total de nós na árvore, partindo da raiz.

## Aplicações de Árvores

- **Pesquisa Rápida**: Em buscas binárias, a árvore permite a divisão do conjunto de dados pela metade, acelerando a busca.
- **Estruturas de Dados de Memória Secundária**: Árvores como B-árvores são otimizadas para minimizar acessos ao disco.
- **Compilação e Processamento de Cadeias de Caracteres**: Árvores de sufixo são usadas em compiladores.
- **Transmissão de Dados, Criptografia e Compressão**: Árvores como árvores de Huffman são empregadas para compressão de dados.
