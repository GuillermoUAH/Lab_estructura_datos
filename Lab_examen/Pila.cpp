#include "Pila.hpp"

Pila::Pila() {
    ultimo = nullptr;
    longitud = 0;
}

Pila::~Pila() {
    while (ultimo) {
        pnodoPila aux = ultimo;
        ultimo = ultimo->siguiente;
        delete aux;
    }
}

void Pila::insertar(Aficionado afic) {
    pnodoPila nuevo = new NodoPila(afic, ultimo);
    ultimo = nuevo;
    longitud++;
}

Aficionado Pila::extraer() {
    if (!ultimo) throw std::runtime_error("Pila vacía");

    pnodoPila nodo = ultimo;
    Aficionado afic = nodo->valor;
    ultimo = nodo->siguiente;
    delete nodo;
    longitud--;
    return afic;
}

Aficionado Pila::cima() const {
    if (!ultimo) throw std::runtime_error("Pila vacía");
    return ultimo->valor;
}

void Pila::mostrar() const {
    pnodoPila aux = ultimo;
    std::cout << "Contenido de la pila:\n";
    while (aux) {
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
}

int Pila::getLongitud() const {
    return longitud;
}