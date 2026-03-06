# Introdução ao C++

C++ foi criado por Bjarne Stroustrup nos anos 80 como um "C com classes". A grande adição foi o paradigma de Orientação a Objetos.

---

## Diferenças básicas de sintaxe

### Entrada e Saída

```c
// em C você usava:
printf("Olá, %s!\n", nome);
scanf("%d", &numero);
```

```cpp
// em C++ você usa:
cout << "Olá, " << nome << "!" << endl;
cin >> numero;
```

O `<<` é o operador de **inserção** e o `>>`é o de **extração**.

---

### Hello World em C++

```cpp
#include <iostream> // equivalente ao <stdio.h> do C
using namespace std; // permite usar cout/cin diretamente

int main() {
    cout << "Olá, mundo!" << endl;
    return 0;
}
```
---

### O tipo `string`

```cpp
#include <iostream>
#include <string> // biblioteca de strings
using namespace std;

int main() {
    string nome = "Manoel"; // sem char[], sem ponteiro
    cout << "Tamanho: " << nome.size() << endl;
    cout << "Olá, " << nome << endl;
    return 0;
}
```

Em C você usava `char[]` e funções como `strlen()`. Em C++, `string` é um tipo completo e muito mais confortável de usar.

---

### Compilar pela linha de comando

Abra o terminal e digite:

```bash
g++ <nome-do-arquivo>.cpp -o <nome-do-arquivo>.exe -Wall -pedantic
```

**O que significa?**

- `g++`: compilador C++
- `<nome-do-arquivo>.cpp`: arquivo-fonte
- `-o <nome-do-arquivo>.exe`: nome do executável gerado
- `-Wall`: habilita avisos importantes
- `-pedantic`: reforça conformidade com o padrão da linguagem

Se não aparecer erro, será criado o arquivo `<nome-do-arquivo>.exe`.