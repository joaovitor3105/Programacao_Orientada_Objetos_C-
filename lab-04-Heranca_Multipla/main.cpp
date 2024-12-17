using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include "Desenvolvedor.hpp"
#include "Gerente.hpp"
#include "TechLead.hpp"

int main()
{
    vector<Desenvolvedor> devs;
    vector<Gerente> gerentes;
    vector<TechLead> techleads;
    int num;

    while (true)
    {

        cout << "\n\tMENU" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "1-Cadastrar Gerente" << endl;
        cout << "2-Cadastrar Desenvolvedor " << endl;
        cout << "3-Cadastrar TechLead" << endl;
        cout << "4-Imprimir funcionarios" << endl;
        cout << "5-Sair" << endl;
        cout << "-------------------------------------------" << endl;

        cin >> num;
        cin.ignore();

        switch (num)
        {
        case 1:
        {
            string nome;
            int num_equipes, salario_base;
            cout << "\nDigite o nome do Gerente: " << endl;
            getline(cin, nome);
            cout << "\nDigite o Salario Base: " << endl;
            cin >> salario_base;
            cin.ignore();
            cout << "\n Digite o numero de equipes:" << endl;
            cin >> num_equipes;
            cin.ignore();
            Gerente gerente(num_equipes, nome, salario_base);
            gerentes.push_back(gerente);
            break;
        }

        case 2:
        {
            string nome, linguagem;
            int salario_base;
            cout << "\nDigite o nome do Desenvolvedor: " << endl;
            getline(cin, nome);
            cout << "\nDigite o Salario Base: " << endl;
            cin >> salario_base;
            cin.ignore();
            cout << "\n Digite a Linguagem de Programacao:" << endl;
            getline(cin, linguagem);
            Desenvolvedor dev(linguagem, nome, salario_base);
            devs.push_back(dev);
            break;
        }

        case 3:
        {
            string nome, linguagem;
            int projetos, num_equipes, salario_base;
            cout << "\nDigite o nome do TechLead: " << endl;
            getline(cin, nome);
            cout << "\nDigite o Salario Base: " << endl;
            cin >> salario_base;
            cin.ignore();
            cout << "\n Digite a Linguagem de Programacao:" << endl;
            getline(cin, linguagem);
            cout << "\n Digite o numero de equipes:" << endl;
            cin >> num_equipes;
            cin.ignore();
            cout << "\n Digite o numero de projetos:" << endl;
            cin >> projetos;
            cin.ignore();

            TechLead techlead(projetos, num_equipes, linguagem, nome, salario_base);
            techleads.push_back(techlead);
            break;
        }
        case 4:
        {
            if (devs.size() != 0)
            {
                cout << "\n\nDesenvolvedores:" << endl;
                for (int i = 0; i < devs.size(); i++)
                {
                    cout << devs[i].descricao() + devs[i].projetos_realizados() << endl;
                }
                cout << "\n\n";
            }

            if (gerentes.size() != 0)
            {
                cout << "\n\nGerentes:" << endl;
                for (int i = 0; i < gerentes.size(); i++)
                {
                    cout << gerentes[i].descricao() + "\nNumero de equipes:" + to_string(gerentes[i].getNumEquipes()) + "\nBonus:" + to_string(gerentes[i].bonus()) << endl;
                }
                cout << "\n\n";
            }
            if (techleads.size() != 0)
            {
                cout << "\n\nTechLeads:" << endl;
                for (int i = 0; i < techleads.size(); i++)
                {
                    cout << techleads[i].descricao() << endl;
                }
                cout << "\n\n";
            }
            break;
        }
        case 5:
        {
            cout << "Saindo do programa..." << endl;
            return 0;
            break;
        }
        }
    }
}
