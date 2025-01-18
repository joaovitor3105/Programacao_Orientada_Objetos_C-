#include <iostream>
#include "NoCliente.hpp"

NoCliente::NoCliente(Pessoa pessoa) // construtor
{
    this->pessoa = pessoa;
    this->prox = NULL;
}

Pessoa NoCliente::obterValor() // obtém o valor
{
    return this->pessoa;
}

NoCliente *NoCliente::obterProx() // obtém o próximo NoCliente
{
    return prox;
}

void NoCliente::setProx(NoCliente *p) // seta o próximo NoCliente
{
    prox = p;
}
