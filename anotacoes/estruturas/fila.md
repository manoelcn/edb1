# TAD Fila

Primeiro a entrar, primeiro a sair.

Fila com array (frente = (frente + 1) % capacidade) e lista encadeadas 

F I F O

- Enfileirar / Enqueue
- desenfileirar / Dequeue
- Frente / Front
- Tamanho / Size

---

## Fila com array

```cpp
Enfileirar(e)
{
    if (cheia)
        throw;
    elementos[posicao] = e;
    posicao = (posicao - 1) % capacidade;
}

Desenfileirar{
    frente = (frente + 1) % capacidade;
}
```
---

## Fila com lista encadeada

- Enfileirar / Enqueue: inserir_fim ou inserir_inicio
- desenfileirar / Dequeue: remover_inicio ou remover_fim
- Frente / Front: primeiro ou ultimo
