#include "Vestuario.hpp"

Vestuario ::Vestuario(string nome, double preco, string tamanho) : Produto(nome, preco)
{
    this->tamanho = tamanho;
}

string Vestuario::getDetalhes()
{
    return Produto::getDetalhes() + "\nTamanho: " + tamanho;
}
