# TAD Pilha

Uma coleção linear de elementos que segue o princípio LIFO (Last In, First Out. Ou seja, o último a entrar é o primeiro a sair).

Pilha com array e lista encadeada

## Pilha array

```cpp
pilha
{
    *elementos;
    capacidade;
    quantidade;
    fim;
}

push(e)
{
    elementos[quantidade] = e;
    quantidade++;
}

// quantidade é tempo a quantidade de elementos quanto a posicao do primeiro elemento vazio/primeira posicao disponivel.

pop()
{
    quantidade--;
}

top()
{
    return quantidade - 1;
}
```

---

## Pilha lista encadeada

- push: inserir_inicio ou inserir_fim.

- pop: remover_inicio ou remover_fim. 

- top: primeiro ou ultimo