#include "Gerente.hpp"
#include <string>
#include <iostream>
using namespace std;

Gerente ::Gerente(int num_equipes, string nome, int salario_base) : Funcionario(nome, salario_base)
{
    this->num_equipes = num_equipes;
}

void Gerente ::setNumEquipes(int num_equipes)
{
    this->num_equipes = num_equipes;
}
int Gerente ::getNumEquipes()
{

    return num_equipes;
}

int Gerente ::bonus()
{
    return num_equipes * 500;
}