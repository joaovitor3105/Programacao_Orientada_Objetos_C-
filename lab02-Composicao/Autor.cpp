#include <iostream>
#include "Autor.hpp"

using namespace std;

Autor::Autor(string nome, string datadenascimento) : nome(nome), datadenascimento(datadenascimento) {}

void Autor ::setNome(string novonome)
{
    this->nome = novonome;
}

void Autor ::setData(string novadata)
{
    this->datadenascimento = novadata;
}

string Autor ::getData()
{

    return datadenascimento;
}

string Autor ::getNome()
{

    return nome;
}