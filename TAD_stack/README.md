# TAD Pilhas

## Regras

- *Last in First Out*
- **Acesso ao topo**: Apenas o elemento do topo (último inserido) pode ser acessado diretamente.

## Aplicações

- Conversão para binário
    - Para converter um número decimal em binário, usamos divisões inteiras por 2, guardando o resto. Para obter o resultado final em ordem correta, é necessário ler os restos na ordem inversa, simulando uma pilha.
- Botão “voltar” no navegador ou “desfazer” em editores de texto
- Controle de chamada de procedimentos
- Estrutura de dados auxiliar em alguns algoritmos como busca em profundidade

## Principais operações

- `push(Pilha, valor)` → insere um elemento x no topo da Pilha
    - insere o elemento no topo da pilha
    - aumenta o tamanho da pilha
    - atualiza qual elemento é o topo
- `pop(Pilha)` → remove o elemento do topo e retorna esse elemento
    - removo o elemento do topo
    - reduzo o tamanho da pilha
    - atualizo qual elemento é o topo
    

## Implementação de Pilhas

Há duas principais maneiras de implementar uma pilha

1. Utilizando vetores
    - Normalmente utiliza-se alocação estática, ou seja, alocamos memória em tempo de compilação
    - Quando tenho uma aplicação em que o tamanho do problema é fixo (ex: utilizo cartas do baralho ou quero verificar a ordem das operações matemáticas)
2. Lista ligada
    - Nesse caso, recorremos à alocação dinâmica, ou seja, alocamos memória em tempo de execução.
    - Útil para aplicações onde o tamanho é imprevisível ou pode crescer significativamente.

## Organização vs Alocação de memória

Temos 4 tipos de formas de **organizar** os elementos na memória e de alocar memória, respectivamente

1. Sequencial e Estática
    - Utiliza-se vetores
    - Tamanho fixo pré-definido
2. Sequencial e dinâmica
    - Utiliza-se vetores cujo tamanho pode crescer em tempo de execução e não precisa ser pré-definido
3. Encadeada e estática 
    - Nesse caso, utilizo um vetor para simular a memória principal, ou seja, não preciso estar sequencialmente na memória
    - Simula uma lista encadeada usando um vetor, onde os elementos não precisam ser alocados em sequência.
4. Encadeada e dinâmica
    - Usa listas encadeadas com ponteiros para o próximo elemento, permitindo memória flexível e não-sequencial.

## Visualização

Uma ferramenta que pode auxiliar a compreensão do funcionamento da pilha pode ser encontrada nesse link https://www.cs.usfca.edu/~galles/visualization/StackArray.html

## Operações - TAD Pilhas

Para criar uma estrutura abstrata de dados do tipo Pilha, recorremos à algumas funções auxiliares principais, dentre elas temos: 

- `createStack(Stack)` → cria uma pilha vazia
- `deleteStack(Stack)` →apaga a pilha da memória
- `top(Stack)` → retorna o elemento do topo sem remover
- `size(Stack)` → retorna o número de elementos na pilha
- `isEmpty(Stack)` → indica se a pilha está vazia
- `isFull(Stack)` →  indica se a pilha está cheia

# Código das implementações 

Inserir o link de cada pasta 