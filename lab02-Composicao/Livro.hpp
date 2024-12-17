#ifndef LIVRO_HPP
#define LIVRO_HPP
#include <string>
#include "Autor.hpp"
class Livro
{
private:
    string titulo, ISBN;
    Autor autor;

public:
    Livro(string titulo, string ISBN, Autor autor);
    void setAutor(Autor novoautor);
    void setTitulo(string titulo);
    void setIsbn(string ISBN);
    string getTitulo();

    string getIsbn();

    Autor getAutor();
};
#endif