#include "Cola.hpp"
#include <iostream>

Cola::Cola() {
    primero = nullptr;
    ultimo = nullptr;
    longitud = 0;
}

Cola::~Cola() {
    while (primero) {
        eliminar();
    }
}

void Cola::insertar(Aficionado afic) {
    pnodoCola nuevo = new NodoCola(afic);
    if (ultimo)
        ultimo->siguiente = nuevo;
    ultimo = nuevo;
    if (!primero)
        primero = nuevo;
    longitud++;
}

Aficionado Cola::eliminar() {
    if (!primero) throw std::runtime_error("Cola vacía");

    pnodoCola nodo = primero;
    Aficionado afic = nodo->valor;
    primero = nodo->siguiente;
    if (!primero)
        ultimo = nullptr;

    delete nodo;
    longitud--;
    return afic;
}

void Cola::mostrar() const {
    pnodoCola aux = primero;
    std::cout << "Contenido de la cola:\n";
    while (aux) {
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
}

Aficionado Cola::verPrimero() const {
    if (!primero) throw std::runtime_error("Cola vacía");
    return primero->valor;
}

int Cola::getLongitud() const {
    return longitud;
}