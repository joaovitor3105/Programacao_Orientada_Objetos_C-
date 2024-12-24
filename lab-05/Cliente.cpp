#include "Cliente.hpp"

Cliente::Cliente(string nome, string cpf)
{
    this->nome = nome;
    this->cpf = cpf;
}

string Cliente::getNome()
{
    return nome;
}

string Cliente ::getCpf()
{
    return cpf;
}

void Cliente::adicionarCompra(std::shared_ptr<Produto> p)
{
    compras.push_back(p);
}

double Cliente::calculaTotal()
{
    double total = 0;
    for (int i = 0; i < compras.size(); i++)
    {
        total += compras[i]->getPreco();
    }
    return total;
}

string Cliente ::getDetalhes()
{
    return "\nNome: " + getNome() + "\nCPF: " + getCpf() + "\nPRODUTOS:" + listarProdutos() + "\nTotal: " + to_string(calculaTotal());
}

string Cliente::listarProdutos()
{
    string produtos;
    for (int i = 0; i < compras.size(); i++)
    {
        produtos += compras[i]->getDetalhes() + "\n";
    }
    return produtos;
}
