#include "Astronauta.hpp"
#include <iostream>
#include <string>
using namespace std;

Astronauta::Astronauta(string nome, int nivelSaude, bool atendimentoUrgente, int x, int y)
{
    this->nome = nome;
    this->nivelSaude = nivelSaude;
    this->atendimentoUrgente = atendimentoUrgente;
    this->x = x;
    this->y = y;
}

string Astronauta::getNome()
{
    return nome;
}
int Astronauta::getNivelSaude()
{
    return nivelSaude;
}

bool Astronauta::getAtendimentoUrgente()
{
    return atendimentoUrgente;
}

int Astronauta::getX()
{
    return x;
}

int Astronauta::getY()
{
    return y;
}

void Astronauta::setNome(string nome)
{
    this->nome = nome;
}

void Astronauta::setNivelSaude(int nivelSaude)
{
    this->nivelSaude = nivelSaude;
}

void Astronauta::setAtendimentoUrgente(bool atendimentoUrgente)
{
    this->atendimentoUrgente = atendimentoUrgente;
}

void Astronauta::setX(int x)
{
    this->x = x;
}

void Astronauta::setY(int y)
{
    this->y = y;
}
