#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Modulo.hpp"
#include "Astronauta.hpp"
#include "EstacaoEspacial.hpp"
#include "RoboDeResgate.hpp"
using namespace std;

class ResgateEspacial
{

    RoboDeResgate roboderesgate;
    EstacaoEspacial estacao;
};

int main()
{

    ifstream arquivo;
    arquivo.open("entrada1.txt");
    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo" << endl;
        return 1;
    }
    // lendo dimensoes da matriz
    int linha, coluna;
    arquivo >> linha;
    arquivo >> coluna;
    EstacaoEspacial estacao = EstacaoEspacial(linha, coluna);
    char tipo;

    // lendo matriz e definindo os modulos

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            arquivo >> tipo;
            estacao.adicionarModulo(i, j, tipo);
        }
    }

    string linhaStr;
    arquivo.ignore();
    getline(arquivo, linhaStr);

    while (getline(arquivo, linhaStr))

    {
        if (linhaStr == "Posições dos astronautas na matriz:")
        {
            break;
        }

        stringstream ss(linhaStr);
        string nome;
        int nivelSaude, urgenciaMedico;
        getline(ss, nome, ',');
        ss >> nivelSaude;
        ss.ignore();
        ss >> urgenciaMedico;
        Astronauta astronauta = Astronauta(nome, nivelSaude, urgenciaMedico);
        estacao.adicionarAstronauta(astronauta);
    }

    // lendo as posições dos astronautas

    while (getline(arquivo, linhaStr))
    {

        stringstream ss(linhaStr);
        string nome;
        int x, y;
        char ignoreChar;
        getline(ss, nome, ':');
        ss >> ignoreChar >> x >> ignoreChar >> y >> ignoreChar;
        for (Astronauta &astronauta : estacao.getAstronautas())

        {
            if (astronauta.getNome() == nome)
            {
                astronauta.setX(x);
                astronauta.setY(y);
                break;
            }
        }
    }

    arquivo.close();

    cout << "Matriz:" << endl;
    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            cout << estacao.getModulo(i, j).getTipo();
        }
        cout << endl;
    }

    // Imprimir os astronautas e suas posições
    cout << "Astronautas:" << endl;
    for (const Astronauta &astronauta : estacao.getAstronautas())
    {
        cout << "Nome: " << astronauta.getNome()
             << ", Nivel de Saude: " << astronauta.getNivelSaude()
             << ", Urgencia Medica: " << astronauta.getAtendimentoUrgente()
             << ", Posicao: (" << astronauta.getX() << ", " << astronauta.getY() << ")"
             << endl;
    }
    return 0;
};