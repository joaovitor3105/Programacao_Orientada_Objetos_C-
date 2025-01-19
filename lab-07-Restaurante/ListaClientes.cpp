#include <iostream>
#include "NoCliente.hpp"
#include "ListaClientes.hpp"

ListaClientes::ListaClientes()
{
    // se não passar elemento, então cabeca e cauda são NULL
    cabeca = NULL;
    cauda = NULL;
}

ListaClientes::ListaClientes(Pessoa pessoa)
{
    // se passar elemento, então cria novo No
    cabeca = new NoCliente(pessoa);
    cauda = cabeca;
}

ListaClientes::~ListaClientes() // destrutor corrigido
{
    NoCliente *atual = cabeca;
    while (atual != NULL)
    {
        NoCliente *proximo = atual->obterProx();
        delete atual;
        atual = proximo;
    }
    cabeca = NULL;
    cauda = NULL;
}

// mostra todos os elementos da lista
void ListaClientes::mostrarTodos()
{
    if (vazia())
    {
        cout << "Nenhum cliente cadastrado! " << endl;
        return;
    }
    else
    {
        cout << "\nImprimindo todos os elementos...\n";
        NoCliente *c = cabeca;

        if (vazia())
            cout << "A lista NÃO possui elementos!!\n";
        else
        {
            while (c) // percorre a lista
            {
                cout << c->obterValor().getDetalhes() << endl;
                c = c->obterProx();
            }
            cout << endl;
        }
    }
}

bool ListaClientes::vazia() // verifica se a lista está vazia
{
    return (cabeca == NULL);
}

// insere no início (semelhante a push_front da list)
void ListaClientes::inserir_inicio(Pessoa pessoa)
{
    NoCliente *novo_no = new NoCliente(pessoa);

    if (vazia())
    {
        cabeca = novo_no;
        cauda = novo_no;
    }
    else
    {
        novo_no->setProx(cabeca);
        cabeca = novo_no;
    }
}

// insere no final (semelhante a push_back)
void ListaClientes::inserir_final(Pessoa pessoa)
{
    NoCliente *novo_no = new NoCliente(pessoa);

    if (vazia())
    {
        cabeca = novo_no;
        cauda = novo_no;
    }
    else
    {
        cauda->setProx(novo_no);
        cauda = novo_no;
    }
}

// retorna o tamanho da lista
int ListaClientes::size()
{
    if (vazia()) // se for vazia, então retorna 0
        return 0;

    NoCliente *c = cabeca;
    int tam = 0;

    // percorre a lista
    do
    {
        c = c->obterProx();
        tam++;
    } while (c);

    return tam;
}

// verifica se um elemento existe na lista
bool ListaClientes::existe(Pessoa pessoa)
{
    NoCliente *c = cabeca;

    while (c)
    {
        if (c->obterValor().getCPF() == pessoa.getCPF())
            return true;
        c = c->obterProx();
    }
    return false;
}

// remove da lista, remoção do final
void ListaClientes::remover()
{
    if (!vazia())
    {
        // se houver só 1 elemento
        if (cabeca->obterProx() == NULL)
            cabeca = NULL;
        else if (cabeca->obterProx()->obterProx() == NULL) // 2 elementos
            cabeca->setProx(NULL);
        else // > 2 elementos
        {
            NoCliente *ant_ant = cabeca;
            NoCliente *ant = cabeca->obterProx();
            NoCliente *corrente = cabeca->obterProx()->obterProx();

            while (corrente)
            {
                NoCliente *aux = ant;
                ant = corrente;
                ant_ant = aux;
                corrente = corrente->obterProx();
            }
            delete ant_ant->obterProx(); // libera memória
            ant_ant->setProx(NULL);      // seta o prox como NULL
            cauda = ant_ant;             // atualiza a cauda
        }
    }
}

bool ListaClientes::verificarCPF(string CPF)
{
    NoCliente *c = cabeca;
    while (c)
    {
        if (c->obterValor().getCPF() == CPF)
            return true;
        c = c->obterProx();
    }
    return false;
}

Pessoa ListaClientes::buscarCliente(string CPF)
{
    NoCliente *c = cabeca;
    while (c)
    {
        if (c->obterValor().getCPF() == CPF)
            return c->obterValor();
        c = c->obterProx();
    }
    return Pessoa();
}
