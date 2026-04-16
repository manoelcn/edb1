# IMD0029 - Estruturas de Dados 1 - 2025.1 - Unidade 1
# Prof. Eiji Adachi

## Questão 1 - Valor: 2.0
Crie uma função recursiva que identifica o menor dígito de um número natural `N`. Por exemplo, se `N` for `987234`, a função retorna `2`.

A função deve seguir a assinatura abaixo e ser implementada no arquivo `q1/main_q1.cpp`.
```c++
int menorDigito(int N)
```

**Obs.: Não utilize laços de repetição; apenas recursão.**

## Questão 2 - Valor: 2.0
Implemente o algoritmo de ordenação Merge Sort de modo que os elementos do array estejam ordenados em ordem **DECRESCENTE**. Sua implementação deverá seguir a assinatura abaixo e deve ser implementada no arquivo ``q2/main_q2.cpp``.

``` c++
void mergeSort(int array[], int esquerda, int direita)
```

 Obs.: A função auxiliar ``estaDecrescente`` não pode ser alterada.

## Questão 3 - Valor: 2.0

Dado um array ordenado de inteiros em ordem crescente e um elemento alvo, implemente uma função recursiva que determina a posição em que o elemento deveria ser inserido para manter o array ordenado. A posição retornada deve ser o índice onde o elemento alvo seria inserido, considerando que os elementos maiores que ele seriam deslocados para a direita. Assuma que o elemento alvo nunca existirá no array e que o array não possui elementos repetidos.

Por exemplo:

- Para o array `{10, 30, 50, 70}` e o elemento alvo `1`, a função deve retornar `0`, indicando que o elemento alvo deve ser inserido na posição de índice `0`.
- Para o array `{10, 30, 50, 70}` e o elemento alvo `40`, a função deve retornar `2`, indicando que o elemento alvo deve ser inserido na posição de índice `2`.
- Para o array `{10, 30, 50, 70}` e o elemento alvo `100`, a função deve retornar `4`, indicando que o elemento alvo deve ser inserido na posição de índice `4`. Neste caso, mesmo que o valor `4` não seja um índice válido no array de entrada, ele indica que o elemento alvo deveria ser inserido no fim do array após o elemento `70`.

Sua função deverá obrigatoriamente ser recursiva, ter complexidade Θ(lg(n)), seguir a assinatura abaixo e ser implementada no arquivo `q3/main_q3.cpp`:

```c++
int posicaoInsercao(int array[], int esquerda, int direita, int alvo)
```

**Obs.: Não utilize laços de repetição; apenas recursão.**
