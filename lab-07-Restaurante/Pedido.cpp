#include "Pedido.hpp"
#include <iostream>
using namespace std;
Pedido::Pedido()
{
}
Pedido::Pedido(string codigoPedido, string descricaoPedido, int tempoEstimado, string CPF)
{
    this->codigoPedido = codigoPedido;
    this->descricaoPedido = descricaoPedido;
    this->tempoEstimado = tempoEstimado;
    this->CPF = CPF;
}

string Pedido::getCodigoPedido()
{
    return codigoPedido;
}

string Pedido::getDescricaoPedido()
{
    return descricaoPedido;
}

int Pedido::getTempoEstimado()
{
    return tempoEstimado;
}

string Pedido::getCPF()
{
    return CPF;
}

string Pedido::getDetalhes()
{
    return "\nCódigo do Pedido: " + codigoPedido + "\nDescrição do Pedido: " + descricaoPedido + "\nTempo Estimado: " + to_string(tempoEstimado) + "\nCPF: " + CPF;
}