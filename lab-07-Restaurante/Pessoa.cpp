#include "Pessoa.hpp"
Pessoa ::Pessoa()
{
}

Pessoa::Pessoa(string nome, string CPF)
{
    this->nome = nome;
    this->CPF = CPF;
}

string Pessoa::getNome()
{
    return nome;
}

string Pessoa::getCPF()
{
    return CPF;
}

string Pessoa::getDetalhes()
{
    return "\nNome:" + nome + "\nCPF:" + CPF;
}
