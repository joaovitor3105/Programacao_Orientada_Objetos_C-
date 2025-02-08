#pragma once
#include "Modulo.hpp"
#include "Astronauta.hpp"
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