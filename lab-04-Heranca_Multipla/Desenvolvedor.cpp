#include "Desenvolvedor.hpp"
#include <string>
using namespace std;

Desenvolvedor ::Desenvolvedor(string linguagem_principal, string nome, int salario_base) : Funcionario(nome, salario_base)
{
    this->linguagem_principal = linguagem_principal;
}

void Desenvolvedor ::setLinguagemPrincipal(string linguagemPrincipal)
{
    this->linguagem_principal = linguagemPrincipal;
}

string Desenvolvedor::getLinguagemPrincipal()
{

    return linguagem_principal;
}

string Desenvolvedor ::projetos_realizados()
{

    return "\nProjetos entregues na linguagem:" + linguagem_principal;
}