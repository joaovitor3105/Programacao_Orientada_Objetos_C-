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
    vector<vector<Modulo>> matriz;
    vector<Astronauta> astronautas;
    int linhas;
    int colunas;

public:
    ~EstacaoEspacial();
    EstacaoEspacial();
    EstacaoEspacial(int linhas, int colunas);
    void adicionarModulo(int x, int y, char tipo);
    void adicionarAstronauta(Astronauta astronauta);
    vector<vector<Modulo>> &getMatriz();
    vector<Astronauta> &getAstronautas();
    int getColunas();
    int getLinhas();
    void imprimirEstacao();
    Modulo getModulo(int x, int y);
};
;