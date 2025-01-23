#include "EstacaoEspacial.hpp"
#include "Modulo.hpp"

EstacaoEspacial::EstacaoEspacial()
{
}

EstacaoEspacial::EstacaoEspacial(int linhas, int colunas)
{
    this->linhas = linhas;
    this->colunas = colunas;
    this->matriz = new Modulo *[linhas];
    for (int i = 0; i < linhas; ++i)
    {
        this->matriz[i] = new Modulo[colunas];
    }
}

void EstacaoEspacial::adicionarModulo(int x, int y, char tipo)
{
    this->matriz[x][y] = Modulo(tipo);
}

void EstacaoEspacial::adicionarAstronauta(Astronauta astronauta)
{
    this->astronautas.push_back(astronauta);
}

Modulo **EstacaoEspacial::getMatriz()
{
    return this->matriz;
}

vector<Astronauta> EstacaoEspacial::getAstronautas()
{
    return this->astronautas;
}

int EstacaoEspacial::getColunas()
{
    return this->colunas;
}

int EstacaoEspacial::getLinhas()
{
    return this->linhas;
}

EstacaoEspacial::~EstacaoEspacial()
{
    for (int i = 0; i < linhas; ++i)
    {
        delete[] this->matriz[i];
    }
    delete[] this->matriz;
}