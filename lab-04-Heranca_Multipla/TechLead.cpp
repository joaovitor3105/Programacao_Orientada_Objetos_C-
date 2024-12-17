#include <string>
#include <iostream>
#include "TechLead.hpp"

TechLead ::TechLead(int projetos_em_andamento, int num_equipes, string linguagem_principal, string nome, int salario_base)
    : Funcionario(nome, salario_base), Desenvolvedor(linguagem_principal, nome, salario_base), Gerente(num_equipes, nome, salario_base)
{
    this->projetos_em_andamento = projetos_em_andamento;
}

void TechLead ::setprojetos_em_andamento(int projetos_em_andamento)
{

    this->projetos_em_andamento = projetos_em_andamento;
}

int TechLead ::getprojetos_em_andamento()
{

    return projetos_em_andamento;
}

string TechLead ::descricao()
{

    return "Funcionario:" + getNome() + "\nSalario Base:" + to_string(getSalario_base()) + "\nLinguagem Principal:" + getLinguagemPrincipal() + "\n Numero de Equipes:" + to_string(getNumEquipes()) + "\nProjetos em Andamento:" + to_string(getprojetos_em_andamento()) + projetos_realizados() + "\nBonus:" + to_string(bonus());
}