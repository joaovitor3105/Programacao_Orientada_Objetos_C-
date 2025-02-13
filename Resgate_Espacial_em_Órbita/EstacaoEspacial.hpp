#pragma once
#include "Modulo.hpp"
#include "Astronauta.hpp"
#include "Astronauta.hpp"
#include "EstacaoEspacial.hpp"
#include "ModuloNormal.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloVazio.hpp"
#include "ModuloSeguranca.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloComAstronauta.hpp"
#include <vector>

class EstacaoEspacial
{
private:
    std::vector<std::vector<Modulo>> matriz;
    std::vector<Astronauta> astronautas;
    int linhas;
    int colunas;

public:
    ~EstacaoEspacial();
    EstacaoEspacial() = default;
    EstacaoEspacial(int linhas, int colunas, std::vector<std::vector<char>> matriz);
    void adicionarModulo(int x, int y, char tipo);
    void adicionarAstronauta(Astronauta astronauta);
    std::vector<std::vector<Modulo>> &getMatriz();
    std::vector<Astronauta> &getAstronautas();
    int getColunas();
    int getLinhas();
    void imprimirEstacao();
    Modulo getModulo(int x, int y);
};
;
;