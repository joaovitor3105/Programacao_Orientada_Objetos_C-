#ifndef NOPEDIDO
#define NOPEDIDO
#include <iostream>
#include "Pedido.hpp"
using namespace std;

class NoPedido
{
private:
    Pedido pedido;
    NoPedido *prox;

public:
    NoPedido(Pedido Ppdido);
    Pedido obterValor();

    NoPedido *obterProx();

    void setProx(NoPedido *p);
};

#endif
