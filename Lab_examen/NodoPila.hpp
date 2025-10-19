#ifndef NODOPILA_HPP
#define NODOPILA_HPP

#include "Aficionado.hpp"

class NodoPila {
public:
    NodoPila(Aficionado afic, NodoPila* sig = nullptr);
    ~NodoPila();

private:
    Aficionado valor;
    NodoPila* siguiente;

    friend class Pila;
};

typedef NodoPila* pnodoPila;

#endif // NODOPILA_HPP