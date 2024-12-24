#include "Produto.hpp"
#include <string>
using namespace std;
#pragma once

class Eletronico : public Produto
{
private:
    int garantia;

public:
    Eletronico(string nome, double preco, int garantia);
    string getDetalhes() override;
};
