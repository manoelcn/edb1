# IMD0029 - EDB1 - 2025.2 - Unidade 1
# Prof. Eiji Adachi

## Questão 1 - Valor: 2.0
Crie uma função que calcula a média aritmética dos elementos de um array de inteiros, utilizando recursão em alguma etapa da implementação. Isso pode ser feito diretamente na função `calcularMedia` ou em funções auxiliares que ela invoque. A média aritmética é calculada ao somar todos os valores de um conjunto de dados e dividir essa soma pelo número total de valores no conjunto. Por exemplo, se o array de entrada for `[1, 2, 3, 4, 5]`, a função retorna `3`.

A função deve seguir a assinatura abaixo e ser implementada no arquivo `q1/main.cpp`.
```c++
int calcularMedia(int v[], int tamanho)
```

**Obs.1: Não pode utilizar laços de repetição.**

## Questão 2 - Valor: 2.0
Implemente o algoritmo de ordenação Quick Sort de modo que os elementos do array estejam ordenados em ordem **DECRESCENTE** e usando a estratégia da mediana de 3 para seleção do pivô. Sua implementação deverá seguir a assinatura abaixo e deve ser implementada no arquivo ``q2/main.cpp``.

``` c++
void quickSort(int array[], int esquerda, int direita)
```

**Obs.1: A função auxiliar ``estaDecrescente`` não pode ser alterada.**

**Obs.2: Caso não consiga implementar a mediana de 3, utilize uma estratégia mais simples (ex: sempre escolher um elemento fixo como pivô). Nesse caso, a pontuação máxima da questão será reduzida para 1.4.**

## Questão 3 - Valor: 2.0

Dado um array ordenado de inteiros em ordem crescente e um elemento alvo, implemente uma função recursiva que determine a posição em que o elemento deveria ser inserido para manter o array ordenado. A posição retornada deve ser o índice onde o elemento alvo seria inserido, considerando que os elementos maiores que ele seriam deslocados para a direita. Assuma que o elemento alvo nunca existirá no array e que o array não possui elementos repetidos.

Por exemplo:

- Para o array `{10, 30, 50, 70}` e o elemento alvo `1`, a função deve retornar `0`, indicando que o elemento alvo deve ser inserido na posição de índice `0`.
- Para o array `{10, 30, 50, 70}` e o elemento alvo `40`, a função deve retornar `2`, indicando que o elemento alvo deve ser inserido na posição de índice `2`.
- Para o array `{10, 30, 50, 70}` e o elemento alvo `100`, a função deve retornar `4`, indicando que o elemento alvo deve ser inserido na posição de índice `4`. Neste caso, mesmo que o valor `4` não seja um índice válido no array de entrada, ele indica que o elemento alvo deveria ser inserido no fim do array após o elemento `70`.

Sua função deverá obrigatoriamente ser recursiva, ter complexidade Θ(lg(n)), seguir a assinatura abaixo e ser implementada no arquivo `q3/main.cpp`:

```c++
int posicaoInsercao(int array[], int esquerda, int direita, int alvo)
```

**Obs.1: Não utilize laços de repetição; apenas recursão.**

**Obs.2: Soluções de complexidade superior a Θ(lg(n)) (por ex., complexidade linear) não receberão pontuação.**
