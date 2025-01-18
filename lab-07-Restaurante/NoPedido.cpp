#include <iostream>
#include "NoPedido.hpp"

NoPedido::NoPedido(Pedido pedido) // construtor
{
    this->pedido = pedido;
    this->prox = NULL;
}

Pedido NoPedido::obterValor() // obtém o valor
{
    return this->pedido;
}

NoPedido *NoPedido::obterProx() // obtém o próximo NoPedido
{
    return prox;
}

void NoPedido::setProx(NoPedido *p) // seta o próximo NoPedido
{
    prox = p;
}
