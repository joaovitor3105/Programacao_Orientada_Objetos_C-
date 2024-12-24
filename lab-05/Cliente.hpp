#include <string>
#include <iostream>
#include <vector>
#include <memory>

#include "Produto.hpp"
#pragma once
using namespace std;

class Cliente
{
private:
    string nome;
    string cpf;
    vector<shared_ptr<Produto>> compras;

public:
    Cliente(string nome, string cpf);
    string getNome();
    string getCpf();
    void adicionarCompra(shared_ptr<Produto> p);
    double calculaTotal();
    string getDetalhes();
    string listarProdutos();
};