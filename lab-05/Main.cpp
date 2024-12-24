#include "Cliente.hpp"
#include "Eletronico.hpp"
#include "Vestuario.hpp"
#include <iostream>
using namespace std;

int main()

{
    vector<Cliente> clientes;
    int num;
    int tam;
    while (true)
    {
        cout << "MENU" << endl;
        cout << "1-Cadastrar Cliente" << endl;
        cout << "2-Cadastrar Produto a um Cliente" << endl;
        cout << "3-Exibir detalhes de um Cliente" << endl;
        cout << "4-Sair" << endl;
        cin >> num;
        cin.ignore();
        string nome, cpf;

        switch (num)
        {

        case 1:
            cout << "Digite o nome do cliente: ";
            getline(cin, nome);
            cout << "Digite o cpf do cliente: ";
            getline(cin, cpf);
            clientes.push_back(Cliente(nome, cpf));
            break;
        case 2:
            tam = clientes.size();
            cout << "Digite o cpf do cliente: ";
            cin >> cpf;
            for (int i = 0; i < clientes.size(); i++)
            {
                if (clientes[i].getCpf() == cpf)
                {
                    cout << "Qual produto deseja adicionar?" << endl;
                    cout << "1 - Eletronico" << endl;
                    cout << "2 - Vestuario" << endl;
                    int x;
                    cin >> x;
                    cin.ignore();
                    if (x == 1)
                    {
                        cout << "Digite o nome do produto: ";
                        getline(cin, nome);
                        cout << "Digite o preco do produto: ";
                        double preco;
                        cin >> preco;
                        cout << "Digite a garantia do produto: ";
                        int garantia;
                        cin >> garantia;
                        auto eletronico = make_shared<Eletronico>(nome, preco, garantia);
                        clientes[i].adicionarCompra(eletronico);
                        cout << "Produto adicionado com sucesso!" << endl;
                        break;
                    }

                    if (x == 2)
                    {

                        cout << "Digite o nome do produto: ";
                        cin >> nome;
                        cout << "Digite o preco do produto: ";
                        double preco;
                        cin >> preco;
                        cin.ignore();
                        cout << "Digite o tamanho do produto: ";
                        string tamanho;
                        getline(cin, tamanho);
                        auto vestuario = make_shared<Vestuario>(nome, preco, tamanho);
                        clientes[i].adicionarCompra(vestuario);
                        cout << "Produto adicionado com sucesso!" << endl;
                        break;
                    }

                    else
                    {
                        cout << "Opção não encontrada!" << endl;
                    }
                }
                else if (i == tam - 1)
                {
                    cout << "Cliente não encontrado!" << endl;
                }
            }
            break;
        case 3:
            tam = clientes.size();
            cout << "Digite o cpf do cliente: ";
            getline(cin, cpf);
            for (int i = 0; i < clientes.size(); i++)
            {
                if (clientes[i].getCpf() == cpf)
                {
                    cout << clientes[i].getDetalhes() << endl;
                    break;
                }
                else if (i = i == tam - 1)
                {
                    cout << "Cliente não encontrado!" << endl;
                }
            }
            break;
        case 4:
            return 0;
        default:
            break;
        }
    }
}
