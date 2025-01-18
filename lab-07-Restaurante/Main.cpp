#include "HistoricoPedidos.hpp"
#include "FilaPedidos.hpp"
#include "ListaClientes.hpp"
#include <iostream>
#include <string>
using namespace std;

int main()
{
    FilaPedidos fp;
    HistoricoPedidos hp;
    ListaClientes lc;
    string nome;
    string CPF;
    Pessoa p;
    int tempoEstimado;
    string descricaoPedido;
    string codigoPedido;
    Pedido pedido;
    while (true)
    {

        cout << "    Menu de opções:" << endl;
        cout << "1 - Adicionar um cliente" << endl;
        cout << "2 - Adicionar um pedido" << endl;
        cout << "3 - Preparar o próximo pedido" << endl;
        cout << "4 - Exibir os pedidos em espera" << endl;
        cout << "5 - Exibir o histórico de pedidos concluídos" << endl;
        cout << "6 - Exibir a lista de pessoas cadastradas" << endl;
        cout << "7 - Sair" << endl;
        cout << "Digite a opção desejada: ";
        int opcao;
        cin >> opcao;
        cin.ignore();
        switch (opcao)
        {
        case 1:
            cout << "Digite o nome do cliente: ";
            getline(cin, nome);
            cout << "Digite o CPF do cliente: ";
            getline(cin, CPF);
            p = Pessoa(nome, CPF);
            lc.inserir_final(p);
            cout << "Cliente cadastrado com sucesso!" << endl;
            break;

        case 2:
            if (lc.vazia())
            {
                cout << "Nenhum cliente cadastrado! " << endl;
                break;
            }

            cout << "Digite o código do pedido: ";

            getline(cin, codigoPedido);
            cout << "Digite a descrição do pedido: ";

            getline(cin, descricaoPedido);
            cout << "Digite o tempo estimado para o pedido: ";
            try
            {
                cin >> tempoEstimado;
            }
            catch (const std::exception &e)
            {
                cout << "Tempo estimado inválido!" << endl;
            }
            cin.ignore();
            cout << "Clientes Cadastrados: " << endl;
            lc.mostrarTodos();
            cout << "Digite o CPF do cliente: ";
            getline(cin, CPF);
            if (!lc.verificarCPF(CPF))
            {
                cout << "CPF não encontrado!" << endl;
                break;
            }
            pedido = Pedido(codigoPedido, descricaoPedido, tempoEstimado, CPF);
            fp.enfileirar(pedido);
            cout << "Pedido adicionado com sucesso!" << endl;
            break;

        case 3:
            if (fp.vazia())
            {
                cout << "Não há pedidos para preparar!" << endl;
                break;
            }
            else
                pedido = fp.desenfileirar();
            hp.inserir_final(pedido);
            cout << "Pedido preparado: " << pedido.getDetalhes() << endl;
            break;
        case 4:

            fp.mostrarTodos(lc);
            break;
        case 5:

            hp.mostrarTodos(lc);
            break;
        case 6:

            lc.mostrarTodos();
            break;

        case 7:
            return 0;

        default:
            cout << "Digite um valor valido" << endl;
            break;
        }
    }

    return 0;
}
