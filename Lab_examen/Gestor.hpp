#ifndef GESTOR_HPP
#define GESTOR_HPP

#include "Pila.hpp"
#include "Cola.hpp"
#include "Lista.hpp"
#include "Aficionado.hpp"

class Gestor {
public:
    Gestor();
    ~Gestor();

    // Opción A
    void generar10Aficionados();

    // Opción B
    void muestraAficionados();

    // Opción C
    void borraAficionadosPila();

    // Opción D
    void encolarAficionados();

    // Opción E
    void muestraSociosCola();

    // Opción F
    void muestraSimpatizantesCola();

    // Opción G
    void borraAficionadosColas();

    // Opción H
    void enlistarAficionados();

    // Opción I
    void buscarAficionados();

    // Opción J
    void reiniciar();
    
    int AficionadosEnPila() const;
    int SociosEnCola() const;
    int SimpatizantesEnCola() const;
    int AficionadosEnLista() const;

private:
    Pila pila;
    Cola colaSocios;
    Cola colaSimpatizantes;
    Lista listaFinal;
    int remesaActual;
};

#endif // GESTOR_HPP