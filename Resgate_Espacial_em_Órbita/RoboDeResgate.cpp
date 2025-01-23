#include "RoboDeResgate.hpp"

RoboDeResgate ::RoboDeResgate(int posicaoInicialX, int posicaoInicialY, EstacaoEspacial estacao)
{

    this->posicaoInicialX = posicaoInicialX;
    this->posicaoInicialY = posicaoInicialY;
    this->estacao = estacao;
    this->passos = 0;
    this->visitado = new bool *[estacao.getLinhas()];
    this->distancias = new int *[estacao.getLinhas()];

    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        this->visitado[i] = new bool[estacao.getColunas()];
        this->distancias[i] = new int[estacao.getColunas()];
    }

    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            this->visitado[i][j] = false;
            this->distancias[i][j] = 0;
        }
    }
}

void RoboDeResgate ::iniciarResgate()
{
}

void RoboDeResgate ::calcularDistancias(int x, int y)
{
}

bool RoboDeResgate ::proximoAoFogo(int x, int y)
{
    if (x + 1 < estacao.getLinhas() && estacao.getMatriz()[x][y].getTipo() == 'F')
    {
        return true;
    }
    if (x - 1 >= 0 && estacao.getMatriz()[x + 1][y].getTipo() == 'F')
    {
        return true;
    }
    if (y + 1 < estacao.getColunas() && estacao.getMatriz()[x][y + 1].getTipo() == 'F')
    {
        return true;
    }
    if (y - 1 >= 0 && estacao.getMatriz()[x][y - 1].getTipo() == 'F')
    {
        return true;
    }
    return false;
}

void RoboDeResgate ::resgatarAstronauta(int x, int y)
{
    if (estacao.getMatriz()[x][y].getTipo() == 'A')

    {
    }
}
