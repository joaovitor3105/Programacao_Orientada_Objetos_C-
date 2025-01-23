#pragma once
#include "Modulo.hpp"

class ModuloSeguranca : Modulo
{
public:
    ModuloSeguranca(char tipo);
    bool podeAcessar() override;
};