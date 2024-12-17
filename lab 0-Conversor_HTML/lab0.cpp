#include <iostream>
#include <string>
#include <locale>
#include <fstream>

int main()
{
    setlocale(LC_ALL, "");

    bool verificador = true, verificador2 = true;

    using namespace std;

    string texto, texto2, linha;

    ifstream arq("entrada.txt");
    if (!arq.is_open())
    {
        cerr << "Erro ao abrir arquivo" << endl;
        return -1;
    }

    while (getline(arq, linha))
    {
        texto += linha + "\n";
    }

    for (int i = 0; i < texto.length(); i++)
    {

        if (texto[i] == '*')
        {
            if (verificador)
            {
                texto2 += "<b>";
            }
            else
            {
                texto2 += "</b>";
            }
            verificador = !verificador;
        }
        else if (texto[i] == '_')
        {
            if (verificador2)
            {
                texto2 += "<i>";
            }
            else
            {
                texto2 += "</i>";
            }
            verificador2 = !verificador2;
        }
        else
            texto2 += texto[i];
    }

    cout << "Seu texto convertido:\n\n"
         << texto2 << endl;
    return 0;
}