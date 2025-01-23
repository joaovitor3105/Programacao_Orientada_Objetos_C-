#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Modulo.hpp"
#include "Astronauta.hpp"
#include "EstacaoEspacial.hpp"
#include "RoboDeResgate.hpp"
using namespace std;

class ResgateEspacial
{
private:
    EstacaoEspacial estacao;

public:
    void lerArquivo(string nomeArquivo)
    {
        ifstream arquivo;
        arquivo.open(nomeArquivo);
        if (!arquivo.is_open())
        {
            cout << "Erro ao abrir o arquivo" << endl;
            return;
        }
        // lendo dimensoes da matriz
        int linha, coluna;
        arquivo >> linha;
        arquivo >> coluna;
        estacao = EstacaoEspacial(linha, coluna);
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
    }
};

int main()
{
    ResgateEspacial resgate;
    resgate.lerArquivo("nome_do_arquivo.txt");
    return 0;
}