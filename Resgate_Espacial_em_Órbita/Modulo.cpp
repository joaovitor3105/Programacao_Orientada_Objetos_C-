#include "Modulo.hpp"
#include <iostream>
using namespace std;
Modulo::Modulo()
{
}
Modulo::Modulo(char tipo)
{
    this->tipo = tipo;
}

char Modulo::getTipo()
{
    return tipo;
}

bool Modulo::podeAcessar()
{
    return true;
}
