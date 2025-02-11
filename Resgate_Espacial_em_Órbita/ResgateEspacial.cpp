#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Modulo.hpp"
#include "Astronauta.hpp"
#include "EstacaoEspacial.hpp"
#include "RoboDeResgate.hpp"
#include "ModuloNormal.hpp"
#include "ModuloObstaculo.hpp"
#include "ModuloVazio.hpp"
#include "ModuloSeguranca.hpp"
#include "ModuloComFogo.hpp"
#include "ModuloComAstronauta.hpp"
using namespace std;

EstacaoEspacial lerArquivo(string nomeArquivo)
{
    ifstream arquivo;
    arquivo.open(nomeArquivo);

    if (!arquivo.is_open())
    {
        cout << "Erro ao abrir o arquivo:" << nomeArquivo << endl;
        return EstacaoEspacial(0, 0, vector<vector<char>>());
    }
    // lendo dimensoes da matriz
    int linha, coluna;
    arquivo >> linha;
    arquivo >> coluna;
    vector<vector<char>> matriztemp = vector<vector<char>>(linha, vector<char>(coluna));

    char tipo;

    // lendo matriz e definindo os modulos

    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            arquivo >> tipo;
            matriztemp[i][j] = tipo;
        }
    }

    EstacaoEspacial estacao(linha, coluna, matriztemp);
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
    return estacao;
}

int main()
{
    string nomeAquivo;

    EstacaoEspacial estacao;
    for (int i = 0; i <= 10; i++)
    {
        nomeAquivo = "entrada" + to_string(i) + ".txt";
        estacao = lerArquivo(nomeAquivo);
        if (estacao.getLinhas() != 0 && estacao.getColunas() != 0)
        {
            estacao.imprimirEstacao();
            RoboDeResgate robo = RoboDeResgate(0, 0, estacao);
            robo.iniciarResgate(0, 0);
        }
        cout << "-----------------------------------" << endl;
    }

    return 0;
};