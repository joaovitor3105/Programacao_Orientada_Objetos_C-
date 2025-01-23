#pragma once
#include "Modulo.hpp"

class ModuloNormal : Modulo
{

public:
    ModuloNormal(char tipo);
    bool podeAcessar() override;
};