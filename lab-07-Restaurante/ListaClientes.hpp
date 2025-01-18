#ifndef LISTACLIENTES_HPP
#define LISTACLIENTES_HPP
#include "NoCliente.hpp"
using namespace std;
class ListaClientes
{
private:
    NoCliente *cabeca; // primeiro elemento
    NoCliente *cauda;  // último elemento
public:
    ListaClientes();
    ListaClientes(Pessoa pessoa);
    virtual ~ListaClientes();
    void mostrarTodos();
    bool vazia();
    void inserir_inicio(Pessoa Pessoa);
    void inserir_final(Pessoa Pessoa);
    int size();
    bool existe(Pessoa Pessoa);
    void remover();
    bool verificarCPF(string CPF);
    Pessoa buscarCliente(string CPF);
};
#endif