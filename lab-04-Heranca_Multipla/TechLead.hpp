#ifndef TECH_LEAD_HPP
#define TECH_LEAD_HPP
using namespace std;
#include "Funcionario.hpp"
#include "Desenvolvedor.hpp"
#include "Gerente.hpp"
#include <string>
#include <iostream>

class TechLead : public Desenvolvedor, public Gerente
{
private:
    int projetos_em_andamento;

public:
    TechLead(int projetos_em_andamento, int num_equipes, string linguagem_principal, string nome, int salario_base);
    void setprojetos_em_andamento(int projetos_em_andamento);
    int getprojetos_em_andamento();
    string descricao() override;
};

#endif