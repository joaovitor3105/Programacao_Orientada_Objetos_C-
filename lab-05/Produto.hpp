#pragma once
#include <string>
using namespace std;

class Produto
{
private:
    string nome;
    double preco;

public:
    string virtual getDetalhes();
    double getPreco();
    Produto(string nome, double preco);
};
