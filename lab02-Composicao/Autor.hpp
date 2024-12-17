#ifndef AUTOR_HPP
#define AUTOR_HPP
#include <string>

using namespace std;
class Autor
{

private:
    string nome, datadenascimento;

public:
    Autor(string nome, string datadenascimento);
    void setNome(string nome);
    string getNome();
    void setData(string nome);
    string getData();
};
#endif