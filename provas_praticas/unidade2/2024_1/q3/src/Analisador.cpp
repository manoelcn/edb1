//
//  ListaEncadeada.cpp
//
//  Created by Eiji Adachi Medeiros Barbosa
//

#include "../header/Analisador.h"
#include <string>
#include <stack>

using namespace std;

Analisador::Analisador()
{
}

bool Analisador::eBemFormada(std::string str)
{
    stack<char> pilha;

    for (char ch : str)
    {
        if (ch == '(' || ch == '[' || ch == '{')
        {
            pilha.push(ch);
        }
        if (ch == ')')
        {
            if (pilha.empty() == true)
            {
                return false;
            }
            if (pilha.top() != '(')
            {
                return false;
            }
            pilha.pop();
        }
        if (ch == ']')
        {
            if (pilha.empty() == true)
            {
                return false;
            }

            if (pilha.top() != '[')
            {
                return false;
            }
            pilha.pop();
        }
        if (ch == '}')
        {
            if (pilha.empty() == true)
            {
                return false;
            }

            if (pilha.top() != '{')
            {
                return false;
            }
            pilha.pop();
        }
    }
    if (pilha.empty() != true)
    {
        return false;
    }

    return true;
}
