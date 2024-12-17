#ifndef DESENVOLVEDOR_HPP
#define DESENVOLVEDOR_HPP
using namespace std;
#include "Funcionario.hpp"
#include <string>
#include <iostream>

class Desenvolvedor : virtual public Funcionario
{
private:
    string linguagem_principal;

public:
    Desenvolvedor(string linguagem_principal, string nome, int salario_base);
    void setLinguagemPrincipal(string LinguagemPrincipal);
    string getLinguagemPrincipal();
    string projetos_realizados();
};

#endif
