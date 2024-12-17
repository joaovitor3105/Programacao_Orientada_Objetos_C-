#include <iostream>
#include <string>
#include "Biblioteca.hpp"
#include "Autor.hpp"
#include "Livro.hpp"
using namespace std;
int main()
{
    Biblioteca biblioteca;
    int num;

    while (true)
    {

        cout << "\tMENU" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "1-Adicionar Livro" << endl;
        cout << "2-Buscar Livro " << endl;
        cout << "3-Mostrar Livros da Biblioteca" << endl;
        cout << "4-Sair" << endl;
        cout << "-------------------------------------------" << endl;
        fflush(stdin);
        cin >> num;

        switch (num)
        {
        case 1:
        {
            string titulo, ISBN, nome, data;
            cout << "Digite o Titulo do Livro:" << endl;
            cin >> titulo;
            fflush(stdin);

            cout << "Digite o ISBN do Livro:" << endl;
            cin >> ISBN;
            fflush(stdin);

            cout << "Digite o nome do Autor:" << endl;
            cin >> nome;
            fflush(stdin);
            cout << "Digite a data de nascimento do autor:" << endl;
            cin >> data;
            fflush(stdin);
            Autor novoautor(nome, data);
            Livro novolivro(titulo, ISBN, novoautor);

            biblioteca.adicionarLivro(novolivro);
            break;
        }
        case 2:
        {
            string info;
            cout << "Digite o Titulo do Livro:" << endl;
            cin >> info;
            biblioteca.buscarLivro(info);
            break;
        }
        case 3:
        {
            biblioteca.mostrarLivros();
            break;
        }
        case 4:
        {
            cout << "Saindo do programa..." << endl;
            return 0;
        }
        default:
        {
            cout << "Opcao errada" << endl;

            break;
        }
        }
    }
}
