#pragma once
#include <iostream>
#include <string>
using namespace std;

class Modulo
{
private:
    char tipo;

public:
    Modulo();
    Modulo(char tipo);
    char getTipo();
    virtual bool podeAcessar();
    virtual ~Modulo();
};