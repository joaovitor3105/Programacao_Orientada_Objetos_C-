#include <iostream>
#include "Biblioteca.hpp"
#include <vector>
#include <string>
using namespace std;

Biblioteca::Biblioteca()
{
}

void Biblioteca::adicionarLivro(Livro novolivro)
{
    this->livros.push_back(novolivro);
}

void Biblioteca::buscarLivro(string titulobuscar)
{

    for (int i = 0; i < livros.size(); i++)
    {

        if (livros[i].getTitulo() == titulobuscar)
        {

            cout << "Titulo:" << livros[i].getTitulo() << endl;
            cout << "ISBN:" << livros[i].getIsbn() << endl;
            cout << "Autor:" << livros[i].getAutor().getNome() << endl;
            cout << "Data de Nascimento:" << livros[i].getAutor().getNome() << "\n\n"
                 << endl;
            break;
        }
        else
            cout << "Livro nao Encontrado na Biblioteca" << endl;
    }
}

void Biblioteca::mostrarLivros()
{

    for (int i = 0; i < livros.size(); i++)
    {

        cout << "Titulo:" << livros[i].getTitulo() << endl;
        cout << "ISBN:" << livros[i].getIsbn() << endl;
        cout << "Autor:" << livros[i].getAutor().getNome() << endl;
        cout << "Data de Nascimento:" << livros[i].getAutor().getNome() << "\n\n"
             << endl;
    }
}