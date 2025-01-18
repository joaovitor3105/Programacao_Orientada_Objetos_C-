#ifndef NOCLIENTE_HPP
#define NOCLIENTE_HPP
#include <iostream>
#include "NoCliente.hpp"
#include "Pessoa.hpp"

using namespace std;

class NoCliente
{
private:
    Pessoa pessoa;
    NoCliente *prox;

public:
    NoCliente(Pessoa pessoa);
    Pessoa obterValor();

    NoCliente *obterProx();

    void setProx(NoCliente *p);
};

#endif
