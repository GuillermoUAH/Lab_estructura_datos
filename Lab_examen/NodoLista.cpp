#include "NodoLista.hpp"

NodoLista::NodoLista(Aficionado afic, NodoLista* sig) : valor(afic), siguiente(sig) {
    // El cuerpo ahora puede estar vacío
}

NodoLista::~NodoLista() {}