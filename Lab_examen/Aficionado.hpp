#ifndef AFICIONADO_HPP
#define AFICIONADO_HPP

#include <string>

class Aficionado {
public:
    Aficionado(int id); // ID asignado desde fuera
    ~Aficionado();

    int getID() const;
    int getMinuto() const;
    bool esSocio() const;
    void mostrar() const;

private:
    int id;
    int minuto;
    bool socio;

    int generarHora();         // aleatorio entre 0 y 59
    bool asignarSocio(int id); // par = socio
};

#endif // AFICIONADO_HPP