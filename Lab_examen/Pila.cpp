#include "Pila.hpp"
#include <iostream>

Pila::Pila() {
    ultimo = nullptr;
    longitud = 0;
}

Pila::~Pila() {
    pnodoPila aux;
    while (ultimo) {
        aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}

void Pila::insertar(int v) {
    pnodoPila nuevo = new NodoPila(v, ultimo);
    ultimo = nuevo;
    longitud++;
}

int Pila::extraer() {
    if (!ultimo)
        return 0;

    pnodoPila nodo = ultimo;
    int v = nodo->valor;
    ultimo = nodo->siguiente;
    delete nodo;
    longitud--;
    return v;
}

int Pila::cima() const {
    if (!ultimo)
        return 0;
    return ultimo->valor;
}

void Pila::mostrar() const {
    pnodoPila aux = ultimo;
    std::cout << "El contenido de la pila es : ";
    while (aux) {
        std::cout <<"-> "<< aux->valor;
        aux = aux->siguiente;
    }
    std::cout << std::endl;
}

int Pila::getLongitud() const {
    return longitud;
}
