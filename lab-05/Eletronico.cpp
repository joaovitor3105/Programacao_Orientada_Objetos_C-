#include "Eletronico.hpp"

Eletronico ::Eletronico(string nome, double preco, int garantia) : Produto(nome, preco)
{
    this->garantia = garantia;
}

string Eletronico::getDetalhes()
{
    return Produto::getDetalhes() + "\nGarantia: " + to_string(garantia);
}
