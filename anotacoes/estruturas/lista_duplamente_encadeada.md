# Lista Duplamente Encadeada

Uma coleção de nós onde cada nó armazena um valor, um ponteiro para o próximo nó e um ponteiro para o nó anterior. O uso de nós sentinelas (cabeça e cauda) nas extremidades elimina ponteiros nulos e simplifica a estrutura.

## Operações e Complexidades

| Operação                   | Complexidade |
|:---------------------------|:------------:|
| Inserção no início         | O(1)         |
| Inserção no fim            | O(1)         |
| Inserção em posição i      | O(n)         |
| Remoção no início          | O(1)         |
| Remoção no fim             | O(1)         |
| Remoção em posição i       | O(n)         |
| Acesso ao primeiro         | O(1)         |
| Acesso ao último           | O(1)         |
| Acesso em posição i        | O(n)         |
| Busca de elemento          | O(n)         |

### Vantagens

- Inserir e remover eficientes tanto no início quanto no fim.
