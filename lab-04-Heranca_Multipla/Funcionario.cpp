
using namespace std;
#include <string>
#include "Funcionario.hpp"

Funcionario::Funcionario(string nome, int salario_base) : nome(nome), salario_base(salario_base) {}

string Funcionario::descricao()
{

    return "\nFuncionario:" + nome + "\nSalario Base:" + to_string(salario_base);
}

string Funcionario ::getNome()
{
    return nome;
}
int Funcionario ::getSalario_base()

{

    return salario_base;
}

void Funcionario::setNome(string nome)
{

    this->nome = nome;
}
void Funcionario::setSalario_base(int salario_base)
{

    this->salario_base = salario_base;
}
