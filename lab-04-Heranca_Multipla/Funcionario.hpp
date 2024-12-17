#ifndef FUNCIONARIO_HPP
#define FUNCIONARIO_HPP
using namespace std;
#include <string>

#include <iostream>
class Funcionario
{
private:
    string nome;
    int salario_base;

public:
    Funcionario(string nome, int salario_base);
    virtual string descricao();

    string getNome();
    int getSalario_base();
    void setNome(string nome);
    void setSalario_base(int salario_base);
};

#endif