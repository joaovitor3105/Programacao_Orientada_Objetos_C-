#include <iostream>
#include "NoPedido.hpp"
#include "HistoricoPedidos.hpp"

HistoricoPedidos::HistoricoPedidos()
{
    // se não passar elemento, então cabeca e cauda são NULL
    cabeca = NULL;
    cauda = NULL;
}

HistoricoPedidos::HistoricoPedidos(Pedido pedido)
{
    // se passar elemento, então cria novo No
    cabeca = new NoPedido(pedido);
    cauda = cabeca;
}

HistoricoPedidos::~HistoricoPedidos() // destrutor
{
    NoPedido *atual = cabeca;
    while (atual != NULL)
    {
        NoPedido *proximo = atual->obterProx();
        delete atual;
        atual = proximo;
    }
    cabeca = NULL;
    cauda = NULL;
}

// mostra todos os elementos da lista
void HistoricoPedidos::mostrarTodos(ListaClientes lc)
{
    if (vazia())
    {
        cout << "Não há pedidos concluídos!" << endl;
        return;
    }
    else
    {
        cout << "\nImprimindo histórico de pedidos...\n";
        NoPedido *p = cabeca;

        if (vazia())
            cout << "O histórico NÃO possui pedidos!!\n";
        else
        {
            while (p) // percorre a lista
            {
                cout << p->obterValor().getDetalhes() << endl;
                cout << lc.buscarCliente(p->obterValor().getCPF()).getDetalhes() << endl;
                p = p->obterProx();
            }
            cout << endl;
        }
    }
}

bool HistoricoPedidos::vazia() // verifica se a lista está vazia
{
    return (cabeca == NULL);
}

// insere no início (semelhante a push_front da list)
void HistoricoPedidos::inserir_inicio(Pedido pedido)
{
    NoPedido *novo_no = new NoPedido(pedido);

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
void HistoricoPedidos::inserir_final(Pedido pedido)
{
    NoPedido *novo_no = new NoPedido(pedido);

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
int HistoricoPedidos::size()
{
    if (vazia()) // se for vazia, então retorna 0
        return 0;

    NoPedido *p = cabeca;
    int tam = 0;

    do
    {
        p = p->obterProx();
        tam++;
    } while (p);

    return tam;
}

// verifica se um elemento existe na lista
bool HistoricoPedidos::existe(Pedido pedido)
{
    NoPedido *p = cabeca;
    while (p)
    {
        if (p->obterValor().getCodigoPedido() == pedido.getCodigoPedido())
            return true;
        p = p->obterProx();
    }
    return false;
}

// remove da lista, remoção do final
void HistoricoPedidos::remover()
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
            NoPedido *ant_ant = cabeca;
            NoPedido *ant = cabeca->obterProx();
            NoPedido *corrente = cabeca->obterProx()->obterProx();

            while (corrente)
            {
                NoPedido *aux = ant;
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