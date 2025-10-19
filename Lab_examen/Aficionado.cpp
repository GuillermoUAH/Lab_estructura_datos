#include "Aficionado.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Aficionado::Aficionado(int id) {
    static bool semillaInicializada = false;
    if (!semillaInicializada) {
        srand(time(nullptr));
        semillaInicializada = true;
    }

    this->id = id;                  // ID asignado directamente
    minuto = generarHora();        // aleatorio
    socio = asignarSocio(id);      // par = socio
}

Aficionado::~Aficionado() {}

int Aficionado::generarHora() {
    return rand() % 60; // minutos entre 0 y 59
}

bool Aficionado::asignarSocio(int id) {
    return id % 2 == 0;
}

int Aficionado::getID() const {
    return id;
}

int Aficionado::getMinuto() const {
    return minuto;
}

bool Aficionado::esSocio() const {
    return socio;
}

void Aficionado::mostrar() const {
    std::cout << "ID: " << id
              << " | Hora llegada: 18:" << (minuto < 10 ? "0" : "") << minuto
              << " | Tipo: " << (socio ? "Socio" : "Simpatizante") << std::endl;
}