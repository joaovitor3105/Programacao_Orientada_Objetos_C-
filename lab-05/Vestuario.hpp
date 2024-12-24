#pragma once
#include <string>
#include <vector>
#include "Produto.hpp"

class Vestuario : public Produto
{
private:
    string tamanho;

public:
    Vestuario(string nome, double preco, string tamanho);
    string getDetalhes() override;
};
