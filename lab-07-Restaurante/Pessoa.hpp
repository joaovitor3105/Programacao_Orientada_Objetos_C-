#ifndef PESSOA_HPP
#define PESSOA_HPP
#include <iostream>
#include <string>

using namespace std;

class Pessoa
{
private:
    string nome;
    string CPF;

public:
    Pessoa();
    Pessoa(string nome, string CPF);
    string getNome();
    string getCPF();
    string getDetalhes();
};
#endif
