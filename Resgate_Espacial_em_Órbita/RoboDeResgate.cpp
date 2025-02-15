#include "RoboDeResgate.hpp"
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
#include <queue>
#include <iostream>
#include <stack>
#include <climits>
#include <algorithm>

RoboDeResgate ::RoboDeResgate(EstacaoEspacial &estacao) : estacao(estacao)
{
    this->passos = 0;
    resgatados = std::vector<Astronauta>();
    naoResgatados = estacao.getAstronautas();
    visitados = std::vector<std::vector<bool>>(estacao.getLinhas(), std::vector<bool>(estacao.getColunas(), false));
    pai = std::vector<std::vector<std::pair<int, int>>>(estacao.getLinhas(), std::vector<std::pair<int, int>>(estacao.getColunas(), {-1, -1}));

        for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            if (estacao.getMatriz()[i][j].getTipo() == 'S')
            {
                this->posicaoInicialX = i;
                this->posicaoInicialY = j;
            }
        }
    }
}

void RoboDeResgate::iniciarResgate()
{
    this->passos = 0;
    pair<int, int> posicaoAtual = {posicaoInicialX, posicaoInicialY};

    while (!naoResgatados.empty())
    {
        queue<pair<int, int>> fila;
        visitados = std::vector<std::vector<bool>>(estacao.getLinhas(), std::vector<bool>(estacao.getColunas(), false));
        pai = vector<vector<pair<int, int>>>(estacao.getLinhas(), vector<pair<int, int>>(estacao.getColunas(), {-1, -1}));

        fila.push(posicaoAtual);
        visitados[posicaoAtual.first][posicaoAtual.second] = true;

        bool encontrouAstronauta = false;
        pair<int, int> astronautaPos;

        while (!fila.empty() && !encontrouAstronauta)
        {
            int x = fila.front().first;
            int y = fila.front().second;
            fila.pop();

            if (estacao.getMatriz()[x][y].getTipo() == 'A')
            {
                encontrouAstronauta = true;
                astronautaPos = {x, y};
                continue;
            }

            const int dx[] = {-1, 1, 0, 0};
            const int dy[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++)
            {
                int novoX = x + dx[i];
                int novoY = y + dy[i];

                if (novoX >= 0 && novoX < estacao.getLinhas() &&
                    novoY >= 0 && novoY < estacao.getColunas() &&
                    !visitados[novoX][novoY] &&
                    posicaoValida(novoX, novoY))
                {
                    visitados[novoX][novoY] = true;
                    pai[novoX][novoY] = {x, y};
                    fila.push({novoX, novoY});
                }
            }
        }

        // RESGATE DO ASTRONAUTA
        if (encontrouAstronauta)
        {
            cout << "Astronauta encontrado na posição (" << astronautaPos.first << ", " << astronautaPos.second << ")" << endl;

            vector<pair<int, int>> caminho;
            auto atual = astronautaPos;

            while (atual.first != -1 && atual != posicaoAtual)
            {
                caminho.push_back(atual);
                atual = pai[atual.first][atual.second];
            }
            caminho.push_back(posicaoAtual);
            reverse(caminho.begin(), caminho.end());

            // imprimindo o caminho
            cout << "Caminho até o astronauta:" << endl;
            for (size_t i = 0; i < caminho.size(); i++)
            {
                cout << "(" << caminho[i].first << ", " << caminho[i].second << ")";
                if (i < caminho.size() - 1)
                    cout << " -> ";
            }
            cout << "\n"
                 << endl;

            passos += caminho.size() - 1;
            resgatarAstronauta(astronautaPos.first, astronautaPos.second);
            posicaoAtual = astronautaPos;
        }

        else
        { // possivel erro
            cout << "Não foi possível encontrar mais astronautas acessíveis." << endl;
            break;
        }
    }

    // retornando ao módulo seguro
    if (posicaoAtual.first != posicaoInicialX || posicaoAtual.second != posicaoInicialY)
    {
        queue<pair<int, int>> fila;
        vector<vector<bool>> visitados(estacao.getLinhas(), vector<bool>(estacao.getColunas(), false));
        vector<vector<pair<int, int>>> pai(estacao.getLinhas(), vector<pair<int, int>>(estacao.getColunas(), {-1, -1}));

        fila.push(posicaoAtual);
        visitados[posicaoAtual.first][posicaoAtual.second] = true;
        bool encontrouModulo = false;

        while (!fila.empty() && !encontrouModulo)
        {
            int x = fila.front().first;
            int y = fila.front().second;
            fila.pop();

            if (x == posicaoInicialX && y == posicaoInicialY)
            {
                vector<pair<int, int>> caminho;
                auto atual = make_pair(x, y);

                while (atual.first != -1 && atual != posicaoAtual)
                {
                    caminho.push_back(atual);
                    atual = pai[atual.first][atual.second];
                }
                caminho.push_back(posicaoAtual);
                reverse(caminho.begin(), caminho.end());

                cout << "Caminho de volta ao módulo seguro:" << endl;
                for (size_t i = 0; i < caminho.size(); i++)
                {
                    cout << "(" << caminho[i].first << ", " << caminho[i].second << ")";
                    if (i < caminho.size() - 1)
                        cout << " -> ";
                }
                cout << "\n"
                     << endl;

                passos += caminho.size() - 1;
                encontrouModulo = true;
                break;
            }

            const int dx[] = {-1, 1, 0, 0};
            const int dy[] = {0, 0, -1, 1};

            for (int i = 0; i < 4; i++)
            {
                int novoX = x + dx[i];
                int novoY = y + dy[i];

                if (novoX >= 0 && novoX < estacao.getLinhas() &&
                    novoY >= 0 && novoY < estacao.getColunas() &&
                    !visitados[novoX][novoY] &&
                    posicaoValida(novoX, novoY))
                {
                    visitados[novoX][novoY] = true;
                    pai[novoX][novoY] = {x, y};
                    fila.push({novoX, novoY});
                }
            }
        }
    }

    gerarRelatorio();
}

bool RoboDeResgate ::proximoAoFogo(int x, int y)
{
    if (x + 1 < estacao.getLinhas() && y < estacao.getColunas() && estacao.getMatriz()[x + 1][y].getTipo() == 'F')
    {
        return true;
    }
    if (x - 1 >= 0 && y < estacao.getColunas() && estacao.getMatriz()[x - 1][y].getTipo() == 'F')
    {
        return true;
    }
    if (y + 1 < estacao.getColunas() && x < estacao.getLinhas() && estacao.getMatriz()[x][y + 1].getTipo() == 'F')
    {
        return true;
    }
    if (y - 1 >= 0 && x < estacao.getLinhas() && estacao.getMatriz()[x][y - 1].getTipo() == 'F')
    {
        return true;
    }

    return false;
}

void RoboDeResgate ::resgatarAstronauta(int x, int y)
{
    if (estacao.getMatriz()[x][y].getTipo() == 'A')

    {

        for (auto it = naoResgatados.begin(); it != naoResgatados.end(); it++)
        {
            if (it->getX() == x && it->getY() == y)

            {
                resgatados.push_back(*it);
                naoResgatados.erase(it);
                estacao.getMatriz()[x][y] = ModuloNormal('.');
                break;
            }
        }
    }
}

string RoboDeResgate ::gerarRelatorio()
{
    string relatorio = "Relatório de Resgate:\n\n";
    relatorio += "Astronautas resgatados: " + std::to_string(resgatados.size()) + "\n\n";
    for (const auto &astronauta : resgatados)
    {
        relatorio += "-" + astronauta.getNome() + " na posição (" + std::to_string(astronauta.getX()) + ", " + std::to_string(astronauta.getY()) + ")";
        relatorio += " Nivel de saude: " + std::to_string(astronauta.getNivelSaude());
        if (astronauta.getAtendimentoUrgente())
        {
            relatorio += " Atendimento urgente: sim\n";
        }
        else
        {
            relatorio += " Atendimento urgente: não\n";
        }
    }

    relatorio += "\nAstronautas não resgatados: " + std::to_string(naoResgatados.size()) + "\n\n";
    for (const auto &astronauta : naoResgatados)
    {
        relatorio += "-" + astronauta.getNome() + " na posição (" + std::to_string(astronauta.getX()) + ", " + std::to_string(astronauta.getY()) + ")";
        relatorio += " Nivel de saúde: " + std::to_string(astronauta.getNivelSaude());
        if (astronauta.getAtendimentoUrgente())
        {
            relatorio += " Atendimento urgente: sim\n";
        }
        else
        {
            relatorio += " Atendimento urgente: não\n";
        }
    }
    relatorio += "Tempo total de operação de resgate: " + std::to_string(passos) + "\n";
    return relatorio;
}

bool RoboDeResgate ::posicaoValida(int x, int y)
{
    if (x < 0 || x >= estacao.getLinhas() || y < 0 || y >= estacao.getColunas())
    {
        return false;
    }
    if (estacao.getMatriz()[x][y].podeAcessar() && !proximoAoFogo(x, y))
    {
        return true;
    }
    return false;
}

RoboDeResgate::~RoboDeResgate()
{
}

void RoboDeResgate ::imprimirEstacao(int atualX, int atualY)
{
    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            if (i == atualX && j == atualY)
            {
                cout << "R ";
            }
            else
            {
                cout << estacao.getMatriz()[i][j].getTipo() << " ";
            }
        }
        cout << endl;
    }
}
