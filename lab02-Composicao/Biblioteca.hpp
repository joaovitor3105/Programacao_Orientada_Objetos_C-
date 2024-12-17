#ifndef BIBLIOTECA_HPP
#define BIBLIOTECA_HPP
#include "Livro.hpp"

#include <vector>

using namespace std;
class Biblioteca
{
private:
    vector<Livro> livros;

public:
    Biblioteca();
    void adicionarLivro(Livro novoLivro);
    void buscarLivro(string titulo);
    void mostrarLivros();
};

#endif