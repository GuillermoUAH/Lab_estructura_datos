#ifndef LISTA_HPP
#define LISTA_HPP

#include "NodoLista.hpp"
#include <iostream>

class Lista {
public:
    Lista();
    ~Lista();

    void insertarOrdenado(Aficionado afic);
    void mostrar() const;
    void insertarFinal(Aficionado afic);
    void vaciar();
    int getLongitud() const;

    Aficionado getPrimero() const;
    Aficionado getUltimo() const;
    Aficionado getPrimerSocio() const;
    Aficionado getUltimoSocio() const;
    Aficionado getPrimerSimpatizante() const;

private:
    pnodoLista primero;
    int longitud;
};

#endif // LISTA_HPP