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
    EstacaoEspacial estacao(linha, coluna);
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
            if (astronauta.getNome() == nome) // verificacao se a ordem dos astronautas esta correto
            {

                astronauta.setX(x);
                astronauta.setY(y);

                break;
            }
        }
    }

    arquivo.close();
    estacao.imprimirEstacao();

    return 0;
};