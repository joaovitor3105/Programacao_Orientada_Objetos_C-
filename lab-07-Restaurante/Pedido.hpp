#ifndef PEDIDO_HPP
#define PEDIDO_HPP
#include <iostream>
#include <string>
using namespace std;
class Pedido
{
private:
    string codigoPedido;
    string descricaoPedido;
    int tempoEstimado;
    string CPF;

public:
    Pedido();
    Pedido(string codigoPedido, string descricaoPedido, int tempoEstimado, string CPF);
    string getCodigoPedido();
    string getDescricaoPedido();
    int getTempoEstimado();
    string getDetalhes();
    string getCPF();
};

#endif