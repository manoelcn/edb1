#include "Lista.h"
#include <iostream>
#include <stdexcept>
#include <sstream>

Lista::Lista()
{
    this->quantidade = 0;
    this->primeiro = nullptr;
    this->ultimo = nullptr;
}

/**
 * @brief Destrutor da lista. Remove todos os nós alocados dinamicamente.
 */
Lista::~Lista()
{
    auto aux = this->primeiro;

    while (aux != nullptr)
    {
        auto tmp = aux;
        aux = aux->proximo;
        delete tmp;
    }

    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->quantidade = 0;
}

/**
 * @brief Insere um elemento no início da lista.
 *
 * @param elemento Elemento a ser inserido.
 * @return true se inserido com sucesso.
 */
bool Lista::inserirInicio(const std::string &elemento)
{
    Lista::No *novo = new Lista::No(elemento); // Cria um novo nó
    if (this->quantidade == 0)
    {
        this->ultimo = novo; // Se a lista estava vazia, ultimo também aponta para o novo nó
    }
    novo->proximo = this->primeiro; // o seu próximo aponta para o primeiro nó
    this->primeiro = novo;          // Atualiza o primeiro nó da lista para o novo nó
    this->quantidade++;             // Incrementa o contador de elementos
    return true;
}

/**
 * @brief Insere um elemento no fim da lista.
 *
 * @param elemento Elemento a ser inserido.
 * @return true se inserido com sucesso.
 */
bool Lista::inserirFim(const std::string &elemento)
{
    Lista::No *novo = new Lista::No(elemento); // Cria um novo nó
    if (this->quantidade == 0)
    {
        this->primeiro = novo; // Se a lista estava vazia, primeiro também aponta para o novo nó.
    }
    else
    {
        this->ultimo->proximo = novo; // o coloca após o último
    }
    novo->proximo = nullptr;
    this->ultimo = novo; // Atualiza ultimo para o novo nó
    this->quantidade++;  // Incrementa o contador de elementos
    return true;
}

/**
 * @brief Insere um elemento na posição i da lista.
 *
 * @param i Posição onde o elemento será inserido.
 * @param elemento Elemento a ser inserido.
 * @return true se a inserção for realizada com sucesso.
 * @throws std::out_of_range se o índice passado como parâmetro for menor do que 1 ou maior do que o tamanho+1.
 */
bool Lista::inserirNaPosicao(int i, const std::string &elemento)
{
    if (i < 1 || i > this->quantidade + 1)
    {
        throw std::out_of_range("");
    }

    if (i == 1) // Verifica se o índice é o primeiro.
    {
        return this->inserirInicio(elemento);
    }

    if (i == this->quantidade + 1) // Verifica se o índice é o último.
    {
        return this->inserirFim(elemento);
    }

    auto auxiliar = this->primeiro;
    Lista::No *novo = new Lista::No(elemento);

    for (int j = 1; j < i - 1; j++)
    // i começa em 1 (primeira posição)
    // Percorre até o nó i - 1 e insere após ele.
    {
        auxiliar = auxiliar->proximo;
    }

    novo->proximo = auxiliar->proximo;
    auxiliar->proximo = novo;
    this->quantidade++;
    return true;
}

/**
 * @brief Remove o elemento do início da lista.
 *
 * @return true se o elemento for removido com sucesso.
 * @throws std::underflow_error se a lista estiver vazia.
 */
bool Lista::removerInicio()
{
    if (this->quantidade == 0)
    {
        throw std::underflow_error("Lista Vazia."); // Retorna underflow_error se a lista estiver vazia.
    }
    auto auxiliar = this->primeiro;           // Faz um ponteiro auxiliar apontar para o primeiro nó
    this->primeiro = this->primeiro->proximo; // Atualiza primeiro para o próximo nó
    if (this->primeiro == nullptr)
    {
        this->ultimo = nullptr; // Se a lista ficar vazia, ultimo vira nullptr
    }
    delete auxiliar;    // Libera o nó auxiliar
    this->quantidade--; // decrementa o contador
    return true;
}

/**
 * @brief Remove o elemento do fim da lista.
 *
 * @return true se o elemento for removido com sucesso.
 * @throws std::out_of_range se a lista estiver vazia.
 */
bool Lista::removerFim()
{
    if (this->quantidade == 0)
    {
        throw std::underflow_error("Lista Vazia."); // Retorna underflow_error se a lista estiver vazia
    }
    if (this->quantidade == 1)
    {
        return Lista::removerInicio(); // Se há um único elemento, chama removerInicio
    }
    auto auxiliar = this->primeiro;
    while (auxiliar->proximo != this->ultimo)
    {
        auxiliar = auxiliar->proximo; // percorre até o penúltimo nó
    }
    delete this->ultimo;             // Remove o último nó
    this->ultimo = auxiliar;         // atualiza ultimo
    this->ultimo->proximo = nullptr; // ajusta os ponteiros
    this->quantidade--;              // decrementa o contador
    return true;
}

/**
 * @brief Remove o elemento da posição i da lista.
 *
 * @param i Posição do elemento a ser removido.
 * @return true se o elemento for removido com sucesso.
 * * @throws std::out_of_range se o índice passado como parâmetro for menor do que 1 ou maior do que o tamanho.
 */
bool Lista::removerNaPosicao(int i)
{
    if (this->quantidade == 0)
    {
        throw std::underflow_error("");
    }

    if (i < 1 || i > this->quantidade)
    {
        throw std::out_of_range("");
    }

    if (i == 1) // Verifica se o índice é o primeiro
    {
        return removerInicio();
    }

    if (i == this->quantidade) // Verifica se o índice é o último
    {
        return removerFim();
    }

    auto auxiliar = this->primeiro;
    for (int j = 1; j < i - 1; j++) // Percorre até i - 1
    {
        auxiliar = auxiliar->proximo;
    }
    auto noI = auxiliar->proximo;     // mantém um ponteiro auxiliar apontando para o nó i
    auxiliar->proximo = noI->proximo; // Ajusta o ponteiro próximo do nó i - 1 para apontar para o nó i + 1
    delete noI;                       // Libera o nó i
    this->quantidade--;               // decrementa o contador.
    return true;
}

/**
 * @brief Retorna o primeiro elemento da lista.
 *
 * @return Referência constante para a string armazenada no primeiro nó.
 * @throws std::out_of_range se a lista estiver vazia.
 */
const std::string &Lista::primeiroElemento() const
{
    if (quantidade > 0)
    {
        return primeiro->valor;
    }
    else
    {
        throw std::out_of_range("A lista está vazia. Não é possível acessar o primeiro elemento.");
    }
}

/**
 * @brief Retorna o último elemento da lista.
 *
 * @return Referência constante para a string armazenada no último nó.
 * @throws std::out_of_range se a lista estiver vazia.
 */
const std::string &Lista::ultimoElemento() const
{
    if (quantidade > 0)
    {
        return ultimo->valor;
    }
    else
    {
        throw std::out_of_range("A lista está vazia. Não é possível acessar o último elemento.");
    }
}

/**
 * @brief Retorna o elemento armazenado na posição i da lista.
 *
 * @param i Índice do elemento a ser acessado.
 * @return Referência constante para a string armazenada na posição i.
 * @throws std::out_of_range se o índice passado como parâmetro for menor do que 1 ou maior do que o tamanho.
 */
const std::string &Lista::elementoNaPosicao(int i) const
{
    if (i < 1 || i > this->quantidade)
    {
        throw std::out_of_range("");
    }

    auto elemento = this->primeiro;
    for (int j = 1; j < i; j++)
    {
        elemento = elemento->proximo;
    }
    return elemento->valor;
}

/**
 * @brief Retorna o número de elementos armazenados na lista.
 *
 * @return Quantidade de elementos.
 */
unsigned long Lista::tamanho() const
{
    return quantidade;
}

/**
 * @brief Imprime os elementos da lista no formato: { elem1, elem2, ... }
 */
std::string Lista::imprimir() const
{
    std::ostringstream oss;
    oss << "{";
    No *atual = primeiro;
    while (atual != nullptr)
    {
        oss << atual->valor;
        if (atual->proximo != nullptr)
            oss << ", ";
        atual = atual->proximo;
    }
    oss << "}";
    return oss.str();
}

/**
 * @brief Remove todos os nós cujo valor é igual ao parâmetro.
 *
 * @param valor Valor a ser removido da lista.
 * @return Quantidade de nós removidos.
 */
int Lista::removerTodos(const std::string &valor)
{
    throw std::runtime_error("Ainda não foi implementado.");
}

Lista::No::No(std::string valor)
{
    this->valor = valor;
    this->proximo = nullptr;
}

Lista::No::~No()
{
}