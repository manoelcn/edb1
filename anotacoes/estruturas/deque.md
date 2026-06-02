# TAD Deque

Deque = Double Ended Queue

Deque com array

Deque_array (Ocupação circular)

front = posição vazia na frente
back = elemento que está atrás

## Operações

- push_back
- pop_back
- push_front
- pop_front
- back
- front

push_front = (front == 0 ? capacidade - 1; front - 1)

```cpp
front(){
    if vazia -> exc...
    else{
        return v[(front + 1) % capacidade];
    }
}



back(){
    if vazia -> exc...
    else{
        return v[back];
    }
}

pop_front(){
front = (front + 1) % capacidade
quantidade--;
}

pop_back(){
    back = (back == 0 ? capacidade - 1; back - 1);
    quantidade--;
}


empurrarFrente(){
    if cheia(){
        throw alguma coisa;
    }
    this->elementos[this->frente] = elemento;
    this->frente = [this->frente == 0 ? this->capacidade - 1; this->frente - 1];
    this->quantidade++;
}

empurrarAtras(){
    this->atras = (this->atras + 1) % this->capacidade;
    this->elemento
}
```