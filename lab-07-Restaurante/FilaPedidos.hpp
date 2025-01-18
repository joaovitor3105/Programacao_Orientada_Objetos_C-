#ifndef FILA_PEDIDOS_HPP
#define FILA_PEDIDOS_HPP

#include "Pedido.hpp"
#include "NoPedido.hpp"
#include "ListaClientes.hpp"

class FilaPedidos
{
private:
    NoPedido *frente; // ponteiro para o primeiro elemento
    NoPedido *tras;   // ponteiro para o último elemento

public:
    FilaPedidos();              // construtor padrão
    FilaPedidos(Pedido pedido); // construtor com pedido inicial
    ~FilaPedidos();             // destrutor

    void enfileirar(Pedido pedido);      // adiciona pedido no final da fila
    Pedido desenfileirar();              // remove e retorna o primeiro pedido
    Pedido primeiro();                   // retorna o primeiro pedido sem remover
    void mostrarTodos(ListaClientes lc); // mostra todos os pedidos da fila
    bool vazia();                        // verifica se a fila está vazia
    int tamanho();                       // retorna o tamanho da fila
    bool existe(Pedido pedido);          // verifica se um pedido existe na fila
};

#endif