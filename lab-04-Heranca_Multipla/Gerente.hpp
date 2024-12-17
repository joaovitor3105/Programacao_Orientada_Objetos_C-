#ifndef GERENTE_HPP
#define GERENTE_HPP
#include <string>
#include <iostream>
#include "Funcionario.hpp"
using namespace std;
class Gerente : public virtual Funcionario
{
private:
    int num_equipes;

public:
    int bonus();
    Gerente(int num_equipes, string nome, int salario_base);
    void setNumEquipes(int num_equipes);
    int getNumEquipes();
};

#endif