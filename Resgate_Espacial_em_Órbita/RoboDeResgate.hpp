#pragma once
#include "EstacaoEspacial.hpp"
#include "Modulo.hpp"
#include "Astronauta.hpp"

class RoboDeResgate
{
private:
    int posicaoInicialX;
    int posicaoInicialY;
    EstacaoEspacial &estacao;
    vector<Astronauta> resgatados;
    vector<Astronauta> naoResgatados;
    int passos;
    std::vector<std::vector<bool>> visitados;
    std::vector<std::vector<int>> distancia;

public:
    RoboDeResgate(EstacaoEspacial &estacao);
    ~RoboDeResgate();
    void iniciarResgate();
    bool proximoAoFogo(int x, int y);
    void resgatarAstronauta(int x, int y);
    string gerarRelatorio();
    bool posicaoValida(int x, int y);
    void imprimirEstacao(int x, int y);
};