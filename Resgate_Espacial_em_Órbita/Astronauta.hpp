#pragma once
#include <iostream>
#include <string>
using namespace std;
class Astronauta
{
private:
    string nome;
    int nivelSaude;
    bool atendimentoUrgente;
    int x;
    int y;

public:
    Astronauta(string nome, int nivelSaude, bool atendimentoUrgente, int x, int y);
    string getNome();
    int getNivelSaude();
    bool getAtendimentoUrgente();
    int getX();
    int getY();
    void setNome(string nome);
    void setNivelSaude(int nivelSaude);
    void setAtendimentoUrgente(bool atendimentoUrgente);
    void setX(int x);
    void setY(int y);
};