#include "Lista.hpp"

Lista::Lista() {
    primero = nullptr;
    longitud = 0;
}

Lista::~Lista() {
    while (primero) {
        pnodoLista aux = primero;
        primero = primero->siguiente;
        delete aux;
    }
}

void Lista::insertarOrdenado(Aficionado afic) {
    pnodoLista nuevo = new NodoLista(afic);
    if (!primero || afic.getMinuto() < primero->valor.getMinuto()) {
        nuevo->siguiente = primero;
        primero = nuevo;
    } else {
        pnodoLista actual = primero;
        while (actual->siguiente && afic.getMinuto() >= actual->siguiente->valor.getMinuto()) {
            actual = actual->siguiente;
        }
        nuevo->siguiente = actual->siguiente;
        actual->siguiente = nuevo;
    }
    longitud++;
}

void Lista::mostrar() const {
    pnodoLista aux = primero;
    std::cout << "Contenido de la lista (ordenado por hora de llegada):\n";
    while (aux) {
        aux->valor.mostrar();
        aux = aux->siguiente;
    }
}

int Lista::getLongitud() const {
    return longitud;
}

Aficionado Lista::getPrimero() const {
    if (!primero) throw std::runtime_error("Lista vacía");
    return primero->valor;
}

Aficionado Lista::getUltimo() const {
    if (!primero) throw std::runtime_error("Lista vacía");
    pnodoLista aux = primero;
    while (aux->siguiente) {
        aux = aux->siguiente;
    }
    return aux->valor;
}

Aficionado Lista::getPrimerSocio() const {
    pnodoLista aux = primero;
    while (aux) {
        if (aux->valor.esSocio()) return aux->valor;
        aux = aux->siguiente;
    }
    throw std::runtime_error("No hay socios en la lista");
}

Aficionado Lista::getUltimoSocio() const {
    pnodoLista aux = primero;
    Aficionado* ultimo = nullptr;
    while (aux) {
        if (aux->valor.esSocio()) {
            ultimo = &aux->valor;
        }
        aux = aux->siguiente;
    }
    if (!ultimo) throw std::runtime_error("No hay socios en la lista");
    return *ultimo;
}

Aficionado Lista::getPrimerSimpatizante() const {
    pnodoLista aux = primero;
    while (aux) {
        if (!aux->valor.esSocio()) return aux->valor;
        aux = aux->siguiente;
    }
    throw std::runtime_error("No hay simpatizantes en la lista");
}

void Lista::insertarFinal(Aficionado afic) {
    pnodoLista nuevo = new NodoLista(afic);
    if (!primero) {
        primero = nuevo;
    } else {
        pnodoLista actual = primero;
        while (actual->siguiente) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
    longitud++;
}

void Lista::vaciar() {
    while (primero) {
        pnodoLista temp = primero;
        primero = primero->siguiente;
        delete temp;
    }
    longitud = 0;
}
