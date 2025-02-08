#include "RoboDeResgate.hpp"
#include "ModuloNormal.hpp"
#include <queue>
#include <iostream>

RoboDeResgate ::RoboDeResgate(int posicaoInicialX, int posicaoInicialY, EstacaoEspacial &estacao) : posicaoInicialX(posicaoInicialX), posicaoInicialY(posicaoInicialY), estacao(estacao)
{
    this->passos = 0;
    resgatados = std::vector<Astronauta>();
    naoResgatados = estacao.getAstronautas();

    visitados = std::vector<std::vector<bool>>(estacao.getLinhas(), std::vector<bool>(estacao.getColunas(), false));
    distancia = std::vector<std::vector<int>>(estacao.getLinhas(), std::vector<int>(estacao.getColunas(), -1));
    cout << "Linhas: " << estacao.getLinhas() << ", Colunas: " << estacao.getColunas() << endl;
    cout << "Número de astronautas: " << estacao.getAstronautas().size() << endl;
    cout << "RoboDeResgate criado com sucesso!" << endl;
}

void RoboDeResgate ::iniciarResgate()
{
    int posX = posicaoInicialX;
    int posY = posicaoInicialY;

    while (!estacao.getAstronautas().empty())
    {
        calcularDistancias(posX, posY);

        // Encontra o astronauta mais próximo
        int menorDistancia = 10000;
        int astronautaX = -1;
        int astronautaY = -1;

        for (const Astronauta &astronauta : estacao.getAstronautas())
        {
            int ax = astronauta.getX();
            int ay = astronauta.getY();

            if (visitados[ax][ay] && distancia[ax][ay] < menorDistancia)
            {
                menorDistancia = distancia[ax][ay];
                astronautaX = ax;
                astronautaY = ay;
            }
        }

        // Se não encontrou caminho para nenhum astronauta
        if (astronautaX == -1)
        {
            break; // Os astronautas restantes não podem ser alcançados
        }

        // Move até o astronauta e o resgata
        passos += menorDistancia;
        resgatarAstronauta(astronautaX, astronautaY);

        // Atualiza posição atual
        posX = astronautaX;
        posY = astronautaY;
    }

    // Volta para o módulo de segurança
    calcularDistancias(posX, posY);

    // Procura o módulo de segurança
    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            if (estacao.getModulo(i, j).getTipo() == 'S')
            {
                if (visitados[i][j])
                {
                    passos += distancia[i][j];
                }
                break;
            }
        }
    }

    // Gera o relatório usando a função existente
    gerarRelatorio();
}

void RoboDeResgate ::calcularDistancias(int x, int y)
{
    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            visitados[i][j] = false;
            distancia[i][j] = 0;
        }
    }

    queue<pair<int, int>> fila;
    fila.push({x, y});
    visitados[x][y] = true;

    // Direções: cima, baixo, esquerda, direita
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!fila.empty())
    {
        int atualX = fila.front().first;
        int atualY = fila.front().second;
        fila.pop();

        // Verifica as 4 direções
        for (int i = 0; i < 4; i++)
        {
            int novoX = atualX + dx[i];
            int novoY = atualY + dy[i];

            // Usa a nova função de validação
            if (!visitados[novoX][novoY] && posicaoValida(novoX, novoY))
            {
                visitados[novoX][novoY] = true;
                distancia[novoX][novoY] = distancia[atualX][atualY] + 1;
                fila.push({novoX, novoY});
            }
        }
    }
}

bool RoboDeResgate ::proximoAoFogo(int x, int y)
{
    if (x + 1 < estacao.getLinhas() && estacao.getMatriz()[x + 1][y].getTipo() == 'F')
    {
        return true;
    }
    if (x - 1 >= 0 && estacao.getMatriz()[x - 1][y].getTipo() == 'F')
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
        size_t numAstronautas = estacao.getAstronautas().size();

        for (size_t i = 0; i < numAstronautas; i++)
        {
            if (estacao.getAstronautas()[i].getX() == x && estacao.getAstronautas()[i].getY() == y)
            {
                resgatados.push_back(estacao.getAstronautas()[i]);
                estacao.getAstronautas().erase(estacao.getAstronautas().begin() + i);
                estacao.getMatriz()[x][y] = ModuloNormal('.');
            }
        }
    }
}

void RoboDeResgate ::gerarRelatorio()
{
    cout << "Astronautas resgatados: " << resgatados.size() << endl;
    cout << "Astronautas nao resgatados: " << estacao.getAstronautas().size() << endl;
    cout << "Passos dados: " << passos << endl;
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

void RoboDeResgate ::imprimirEstacao()
{
    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            cout << estacao.getMatriz()[i][j].getTipo() << " ";
        }
        cout << endl;
    }
}