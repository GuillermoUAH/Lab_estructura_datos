#include "NodoLista.hpp"

NodoLista::NodoLista(Aficionado afic, NodoLista* sig) {
    valor = afic;
    siguiente = sig;
}

NodoLista::~NodoLista() {}