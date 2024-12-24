#include "Produto.hpp"

Produto ::Produto(string nome, double preco)
{
    this->nome = nome;
    this->preco = preco;
}

string Produto::getDetalhes()
{
    return "\nNome: " + nome + "\nPreço: " + to_string(preco);
}

double Produto::getPreco()
{
    return preco;
}