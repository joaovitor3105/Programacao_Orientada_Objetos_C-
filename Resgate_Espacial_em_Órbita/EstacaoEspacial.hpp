#pragma once
#include "Modulo.hpp"
#include "Astronauta.hpp"
#include <vector>

class EstacaoEspacial
{
private:
    Modulo **matriz;
    vector<Astronauta> astronautas;
    int linhas;
    int colunas;

public:
    EstacaoEspacial();
    EstacaoEspacial(int linhas, int colunas);
    void adicionarModulo(int x, int y, char tipo);
    void adicionarAstronauta(Astronauta astronauta);
    Modulo **getMatriz();
    vector<Astronauta> getAstronautas();
    int getColunas();
    int getLinhas();
};