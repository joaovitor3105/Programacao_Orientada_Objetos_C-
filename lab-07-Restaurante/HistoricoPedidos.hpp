#ifndef HISTORICO_PEDIDOS_HPP
#define HISTORICO_PEDIDOS_HPP

#include "Pedido.hpp"
#include "NoPedido.hpp"
#include "ListaClientes.hpp"
class HistoricoPedidos
{
private:
    NoPedido *cabeca; // ponteiro para o primeiro elemento
    NoPedido *cauda;  // ponteiro para o último elemento

public:
    HistoricoPedidos();              // construtor padrão
    HistoricoPedidos(Pedido pedido); // construtor com pedido inicial
    ~HistoricoPedidos();             // destrutor

    void inserir_inicio(Pedido pedido);  // insere no início da lista
    void inserir_final(Pedido pedido);   // insere no final da lista
    void remover();                      // remove o último elemento
    void mostrarTodos(ListaClientes lc); // mostra todos os pedidos
    bool vazia();                        // verifica se a lista está vazia
    int size();                          // retorna o tamanho da lista
    bool existe(Pedido pedido);          // verifica se um pedido existe
};

#endif