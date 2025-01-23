#pragma once
#include "EstacaoEspacial.hpp"
#include "Modulo.hpp"
#include "Astronauta.hpp"

class RoboDeResgate
{
private:
    int posicaoInicialX;
    int posicaoInicialY;
    EstacaoEspacial estacao;
    vector<Astronauta> resgatados;
    vector<Astronauta> naoResgatados;
    int passos;
    bool **visitado;
    int **distancias;

public:
    RoboDeResgate(int posicaoInicialX, int posicaoInicialY, EstacaoEspacial estacao);
    void iniciarResgate();
    void calcularDistancias(int x, int y);
    bool proximoAoFogo(int x, int y);
    void resgatarAstronauta(int x, int y);
    void gerarRelatorio();
    void gerarRelatorio();
};