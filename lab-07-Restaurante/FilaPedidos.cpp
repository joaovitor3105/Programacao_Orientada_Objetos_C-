#include <iostream>
#include "NoPedido.hpp"
#include "FilaPedidos.hpp"

FilaPedidos::FilaPedidos()
{
    // inicializa com frente e tras como NULL quando não há elementos
    frente = NULL;
    tras = NULL;
}

FilaPedidos::FilaPedidos(Pedido pedido)
{
    // se passar elemento, cria novo No como primeiro elemento
    frente = new NoPedido(pedido);
    tras = frente;
}

FilaPedidos::~FilaPedidos() // destrutor
{
    delete frente;
}

// mostra todos os elementos da fila
void FilaPedidos::mostrarTodos(ListaClientes lc)
{
    if (vazia())
    {
        cout << "Não há pedidos em espera!" << endl;
        return;
    }
    else
    {
        cout << "\nImprimindo todos os pedidos da fila...\n";
        NoPedido *p = frente;

        if (vazia())
            cout << "A fila NÃO possui pedidos!!\n";
        else
        {
            while (p) // percorre a fila
            {
                cout << p->obterValor().getDetalhes() << endl;
                cout << lc.buscarCliente(p->obterValor().getCPF()).getDetalhes() << endl;
                p = p->obterProx();
            }
            cout << endl;
        }
    }
}

bool FilaPedidos::vazia() // verifica se a fila está vazia
{
    return (frente == NULL);
}

// enfileira um novo pedido (adiciona no final da fila)
void FilaPedidos::enfileirar(Pedido pedido)
{
    NoPedido *novo_no = new NoPedido(pedido);

    if (vazia())
    {
        frente = novo_no;
        tras = novo_no;
    }
    else
    {
        tras->setProx(novo_no);
        tras = novo_no;
    }
}

// desenfileira (remove o primeiro elemento da fila)
Pedido FilaPedidos::desenfileirar()
{
    if (vazia())
    {
        throw "Fila vazia!";
    }

    NoPedido *p = frente;
    Pedido pedido = p->obterValor();

    frente = frente->obterProx();

    if (frente == NULL)
        tras = NULL;

    p->setProx(NULL);
    delete p;

    return pedido;
}

// retorna o primeiro elemento da fila sem removê-lo
Pedido FilaPedidos::primeiro()
{
    if (vazia())
    {
        throw "Fila vazia!";
    }
    return frente->obterValor();
}

// retorna o tamanho da fila
int FilaPedidos::tamanho()
{
    if (vazia()) // se for vazia, então retorna 0
        return 0;

    NoPedido *p = frente;
    int tam = 0;

    do
    {
        p = p->obterProx();
        tam++;
    } while (p);

    return tam;
}

// verifica se um pedido existe na fila
bool FilaPedidos::existe(Pedido pedido)
{
    NoPedido *p = frente;
    while (p)
    {
        if (p->obterValor().getCodigoPedido() == pedido.getCodigoPedido())
            return true;
        p = p->obterProx();
    }
    return false;
}