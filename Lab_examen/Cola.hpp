#ifndef COLA_HPP
#define COLA_HPP

#include "NodoCola.hpp"
#include "Aficionado.hpp"

class Cola {
public:
    Cola();
    ~Cola();

    void insertar(Aficionado afic);
    Aficionado eliminar();
    void mostrar() const;
    Aficionado verPrimero() const;
    int getLongitud() const;

private:
    pnodoCola primero, ultimo;
    int longitud;
};

#endif // COLA_HPP