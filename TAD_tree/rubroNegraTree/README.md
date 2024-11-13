# README: Árvore Rubro-Negra

## O que é uma Árvore Rubro-Negra?

A árvore rubro-negra é uma árvore de busca binária balanceada, inspirada na árvore 2-3-4 desenvolvida por Rudolf Bayer em 1972 e formalizada por Guibas e Sedgewick em 1978. Ela possui regras específicas para balanceamento, usando a coloração dos nós para garantir uma estrutura aproximadamente balanceada, o que facilita operações eficientes de inserção, remoção e busca.

Essas árvores são amplamente usadas em sistemas que demandam eficiência em consultas, como bancos de dados, sistemas de arquivos (ex: ext3 e ext4) e em algoritmos de análise léxica e roteamento de pacotes.

## Estrutura da Árvore Rubro-Negra

Cada nó em uma árvore rubro-negra tem:
- **Cor**: vermelho ou preto.
- **Valor**: o dado armazenado.
- **Filhos**: ponteiros para os filhos esquerdo e direito.
- **Pai**: ponteiro para o nó pai.

### Regras de Estruturação

1. A raiz da árvore é sempre preta.
2. As folhas são sempre pretas e representam nós nulos.
3. Se um nó é vermelho, seus filhos devem ser pretos (não pode haver dois nós vermelhos consecutivos).
4. Todos os caminhos de qualquer nó até uma folha descendente têm o mesmo número de nós pretos (balanceamento de caminho negro).

A combinação dessas regras garante que a altura máxima da árvore seja \(2 \log(n+1)\), onde \(n\) é o número de nós. Dessa forma, todas as operações principais (inserção, remoção e busca) têm complexidade média de \(O(\log n)\).

## Operações Principais

### Inserção

1. **Inserção do Nó**: Procure a posição onde o novo nó será inserido, substitua a folha por um novo nó vermelho e adicione folhas nulas pretas nos filhos.
2. **Recolorir e Balancear**:
   - Se o nó inserido for a raiz, altere a cor para preto.
   - Se o pai do nó inserido é preto, não há violação das regras.
   - Caso o pai seja vermelho, aplique operações de recoloração e, se necessário, rotações (simples ou duplas), até restaurar o balanceamento da árvore.

### Remoção

1. **Remoção do Nó**: Localize e remova o nó como em uma árvore de busca binária. Em caso de substituição pelo sucessor, o nó removido efetivo será uma folha ou nó com um único filho.
2. **Correção de Violação**:
   - Se o nó removido é vermelho, não há impacto no balanceamento.
   - Se for preto, pode ser necessário aplicar um "preto duplo" para ajustar o caminho negro e restaurar o balanceamento por meio de recolorações e rotações apropriadas.

## Rotações

### Rotações Simples e Duplas

Durante as operações de inserção e remoção, podem surgir situações onde o balanceamento precisa ser restaurado por meio de rotações:
- **Rotação Simples (Esquerda ou Direita)**: Corrige quando há desequilíbrio devido à coloração vermelha consecutiva entre um nó e seu filho.
- **Rotação Dupla**: Executa uma rotação simples em uma direção seguida por uma rotação na direção oposta, aplicada em casos específicos onde há "desalinhamento".

## Comparação com a Árvore AVL

Apesar de ambas serem árvores balanceadas, a árvore rubro-negra é menos rígida em suas condições de balanceamento. Isso torna as operações de busca ligeiramente mais lentas (apesar da mesma complexidade assintótica), mas simplifica as inserções e remoções, exigindo menos rotações comparadas às árvores AVL.

## Aplicações

- **Bancos de Dados**: Utilizadas para manter índices balanceados, proporcionando eficiência em consultas, inserções e remoções.
- **Sistemas de Arquivos**: Adotadas em sistemas como ext3 e ext4 para gerenciar operações com um grande volume de arquivos.
- **Análise Léxica e Sintática**: Organização e gerenciamento de tokens e símbolos durante a compilação.
- **Roteamento de Pacotes**: Implementação de tabelas de endereçamento IP e roteamento de pacotes de dados de forma eficiente.

### Resumo

A árvore rubro-negra combina simplicidade na implementação com eficiência operacional, sendo uma escolha robusta para cenários que exigem balanceamento dinâmico. Seguindo as regras de balanceamento e aplicando as rotações e recolorações conforme necessário, uma árvore rubro-negra mantém-se equilibrada, garantindo desempenho adequado para diversas aplicações computacionais.

## Referências 
- [Slides sobre árvores rubro-negras - IME/USP](https://www.ime.usp.br/~song/mac5710/slides/08rb.pdf)
- [Slides sobre árvores rubro-negras - UFU](https://www.facom.ufu.br/~backes/gsi011/Aula12-ArvoreRB.pdf)
- Aulas de Estrutura de Dados - ICMC/USP, Professor Renato Moraes Silva
