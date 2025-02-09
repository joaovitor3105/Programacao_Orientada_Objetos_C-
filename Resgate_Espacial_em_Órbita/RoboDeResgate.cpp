#include "RoboDeResgate.hpp"
#include "ModuloNormal.hpp"
#include <queue>
#include <iostream>
#include <stack>
#include <climits>

RoboDeResgate ::RoboDeResgate(int posicaoInicialX, int posicaoInicialY, EstacaoEspacial &estacao) : posicaoInicialX(posicaoInicialX), posicaoInicialY(posicaoInicialY), estacao(estacao)
{
    this->passos = 0;
    resgatados = std::vector<Astronauta>();
    naoResgatados = estacao.getAstronautas();
    visitados = std::vector<std::vector<bool>>(estacao.getLinhas(), std::vector<bool>(estacao.getColunas(), false));
    distancia = std::vector<std::vector<int>>(estacao.getLinhas(), std::vector<int>(estacao.getColunas(), -1));
}

void RoboDeResgate ::iniciarResgate(int x, int y)
{
    queue<pair<int, int>> fila;
    fila.push({x, y});
    visitados[x][y] = true;

    // Inicializa distância corretamente
    for (int i = 0; i < estacao.getLinhas(); i++)
        for (int j = 0; j < estacao.getColunas(); j++)
            distancia[i][j] = INT_MAX;

    distancia[x][y] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!fila.empty())
    {
        int atualX = fila.front().first;
        int atualY = fila.front().second;
        fila.pop();
        passos++;

        // Se encontrou um astronauta, resgata ele
        if (estacao.getMatriz()[atualX][atualY].getTipo() == 'A')
        {
            cout << "Astronauta encontrado na posição (" << atualX << ", " << atualY << ")" << endl;
            resgatarAstronauta(atualX, atualY);
        }

        // Explora as 4 direções possíveis
        for (int i = 0; i < 4; i++)
        {
            int novoX = atualX + dx[i];
            int novoY = atualY + dy[i];

            if (posicaoValida(novoX, novoY) && !visitados[novoX][novoY])
            {
                fila.push({novoX, novoY});
                visitados[novoX][novoY] = true;
                distancia[novoX][novoY] = distancia[atualX][atualY] + 1;
            }
        }
    }

    if (distancia[posicaoInicialX][posicaoInicialY] != INT_MAX)
        passos += distancia[posicaoInicialX][posicaoInicialY];

    cout << "Retornando ao módulo inicial. Passos totais: " << passos << endl;
    for (int i = 0; i < estacao.getLinhas(); i++)
    {
        for (int j = 0; j < estacao.getColunas(); j++)
        {
            if (distancia[i][j] == INT_MAX)
            {
                cout << "I ";
            }
            else
                cout << distancia[i][j] << " ";
        }
        cout << endl;
    }
    gerarRelatorio();
}

/*void RoboDeResgate::dfs(int x, int y)
{
    stack<pair<int, int>> pilha;
    pilha.push({x, y});
    visitados[x][y] = true;

    // Direções ajustadas: direita, baixo, esquerda, cima (priorizando um padrão)
    int dx[] = {0, 1, 0, -1};
    int dy[] = {1, 0, -1, 0};

    while (!pilha.empty())
    {
        int atualX = pilha.top().first;
        int atualY = pilha.top().second;
        pilha.pop();
        passos++;

        // Verificar se encontrou um astronauta
        if (estacao.getMatriz()[atualX][atualY].getTipo() == 'A')
        {
            cout << "Astronauta encontrado na posição (" << atualX << ", " << atualY << ")" << endl;
            resgatarAstronauta(atualX, atualY);
        }

        // Explorar vizinhos
        for (int i = 0; i < 4; i++)
        {
            int novoX = atualX + dx[i];
            int novoY = atualY + dy[i];

            if (posicaoValida(novoX, novoY) && !visitados[novoX][novoY])
            {
                imprimirEstacao(novoX, novoY);
                cout << endl;
                visitados[novoX][novoY] = true;
                pilha.push({novoX, novoY});
            }
        }
    }

    // Voltar para o módulo inicial
    calcularDistancias(x, y);
    if (distancia[posicaoInicialX][posicaoInicialY] != -1)
    {
        passos += distancia[posicaoInicialX][posicaoInicialY];
        cout << "Retornando ao módulo inicial. Passos totais: " << passos << endl;
    }

    // Gerar relatório
    gerarRelatorio();
}

void RoboDeResgate::bfs(int x, int y)
{
    queue<pair<int, int>> fila;
    fila.push({x, y});
    visitados[x][y] = true;
    distancia[x][y] = 0;

    // Inicializa distância corretamente
    for (int i = 0; i < estacao.getLinhas(); i++)
        for (int j = 0; j < estacao.getColunas(); j++)
            distancia[i][j] = -1;

    distancia[x][y] = 0;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!fila.empty())
    {
        int atualX = fila.front().first;
        int atualY = fila.front().second;
        fila.pop();
        passos++;

        // Se encontrou um astronauta, resgata ele
        if (estacao.getMatriz()[atualX][atualY].getTipo() == 'A')
        {
            cout << "Astronauta encontrado na posição (" << atualX << ", " << atualY << ")" << endl;
            resgatarAstronauta(atualX, atualY);
        }

        // Explora as 4 direções possíveis
        for (int i = 0; i < 4; i++)
        {
            int novoX = atualX + dx[i];
            int novoY = atualY + dy[i];

            if (posicaoValida(novoX, novoY) && !visitados[novoX][novoY])
            {
                fila.push({novoX, novoY});
                visitados[novoX][novoY] = true;
                distancia[novoX][novoY] = distancia[atualX][atualY] + 1;
            }
        }
    }

    // Calcula a volta ao ponto inicial
    calcularDistancias(x, y);

    if (distancia[posicaoInicialX][posicaoInicialY] != -1)
        passos += distancia[posicaoInicialX][posicaoInicialY];
    else
        cout << "Erro: Caminho de volta não encontrado!" << endl;

    cout << "Retornando ao módulo inicial. Passos totais: " << passos << endl;
    gerarRelatorio();
}*/

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

void RoboDeResgate ::gerarRelatorio()
{

    for (const auto &astronauta : resgatados)
    {
        cout << "Resgatado: " << astronauta.getNome() << " na posição (" << astronauta.getX() << ", " << astronauta.getY() << ")" << endl;
    }

    cout << "Astronautas nao resgatados: " << naoResgatados.size() << endl;
    for (const auto &astronauta : naoResgatados)
    {
        cout << "Nao resgatado: " << astronauta.getNome() << " na posição (" << astronauta.getX() << ", " << astronauta.getY() << ")" << endl;
    }
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
    resgatados.clear();
    naoResgatados.clear();
    visitados.clear();
    distancia.clear();
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
