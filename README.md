# Implementacion de las colas:

#include <cola.hpp>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    Cola cola;
    
    cola.insertar(1);
    cola.insertar(2);
    cola.insertar(3);
    cola.insertar(4);
    cola.mostrar();
    
    int primero = cola.verPrimero();
    cola.eliminar();
    cout << "Despues de extraer el primero: (" << primero << ")..."<< endl;
    cola.mostrar();
    
    cola.eliminar();
    cola.mostrar();
    cola.insertar(5);
    cola.mostrar();
    cola.eliminar();
    cola.mostrar();
    cola.eliminar();
    cola.mostrar();
    cola.eliminar();
    cola.mostrar();
    cola.eliminar();
    cola.mostrar();
	return 0;
}

#Implementacion de las pilas:
#include <stdio.h>
#include <Pila.hpp>

using namespace std;

int main(int argc, char **argv)
{
    Pila pila;
    
    pila.insertar(1);
    pila.insertar(2);
    pila.insertar(3);
    pila.insertar(4);
    pila.mostrar();

    int cima = pila.cima();
    pila.extraer();
    cout << "Despues de extraer la cima (" << cima << ")..." << endl;
    pila.mostrar();
    
    pila.insertar(5);
    pila.mostrar();
    pila.extraer();
    pila.mostrar();
    pila.extraer();
    pila.mostrar();
    pila.extraer();
    pila.mostrar();
    pila.extraer();
    pila.mostrar();

    
    return 0;
}

