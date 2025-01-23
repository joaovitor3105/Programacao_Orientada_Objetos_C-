#pragma once
#include <iostream>
#include "Modulo.hpp"

class ModuloComFogo : Modulo
{

public:
    ModuloComFogo(char tipo);
    bool podeAcessar() override;
};