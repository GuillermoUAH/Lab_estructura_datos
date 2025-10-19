#ifndef NODOLISTA_HPP
#define NODOLISTA_HPP

#include "Aficionado.hpp"

class NodoLista {
public:
    NodoLista(Aficionado afic, NodoLista* sig = nullptr);
    ~NodoLista();

private:
    Aficionado valor;
    NodoLista* siguiente;

    friend class Lista;
};

typedef NodoLista* pnodoLista;

#endif // NODOLISTA_HPP

