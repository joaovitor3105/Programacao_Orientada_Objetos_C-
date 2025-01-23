#include "Modulo.hpp"
#pragma once

class ModuloVazio : Modulo
{
public:
    ModuloVazio(char tipo);
    bool podeAcessar() override;
};
