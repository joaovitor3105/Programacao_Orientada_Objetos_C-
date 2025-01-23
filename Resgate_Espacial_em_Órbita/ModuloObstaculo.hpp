#pragma once
#include "Modulo.hpp"

class ModuloObstaculo : Modulo
{

public:
    ModuloObstaculo(char tipo);
    bool podeAcessar() override;
};