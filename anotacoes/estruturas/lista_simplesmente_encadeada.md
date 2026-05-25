# Lista Simplesmente Encadeada

Uma coleção de nós onde cada nó armazena um valor e um ponteiro para o próximo nó. O último nó aponta para nullptr.

A lista simplesmente encadeada com ponteiros para o primeiro e o último elemento é uma estrutura versátil e eficiente, **especialmente para inserções no início ou no final**. No entanto, **a remoção no final e acessos em posições arbitrárias continuam a exigir percorrer toda a lista.** Atenção especial deve ser dada aos casos de listas vazias e de listas com apenas um elemento.

## Operações e Complexidades

| Operação | Complexidade |
| :------- | :-----------: |
| Inserir no início    | O(1) |
| Inserir no fim       | O(1) |
| Inserir na posição i | O(n) |
| Acessar o primeiro   | O(1) |
| Acessar o último     | O(1) |
| Acessar na posição i | O(1) |
| Remover no início    | O(1) |
| Remover no fim       | O(n) |
| Remover na posição i | O(1) |

### Vantagens

- Inserir e remover no início são muito eficientes.
- Tamanho dinâmico.
- Alocação flexível na memória.

### Desvantagens

- Acesso e busca lentos.
- Inserir e remover no fim são ineficientes.
