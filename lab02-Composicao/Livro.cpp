#include "Livro.hpp"
#include <iostream>
using namespace std;
Livro ::Livro(string titulo, string ISBN, Autor autor) : titulo(titulo), ISBN(ISBN), autor(autor) {}

string Livro ::getTitulo()
{
    return titulo;
}

string Livro ::getIsbn()
{
    return ISBN;
}

void Livro::setTitulo(string novotitulo)
{

    this->titulo = novotitulo;
}

void Livro::setIsbn(string novoISBN)
{

    this->ISBN = novoISBN;
}

void Livro::setAutor(Autor novoautor)
{

    this->autor = novoautor;
}

Autor Livro::getAutor()
{
    return autor;
}