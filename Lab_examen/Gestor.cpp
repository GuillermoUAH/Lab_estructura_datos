#include "Gestor.hpp"
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

Gestor::Gestor() {
    remesaActual = 0;
}

Gestor::~Gestor() {
    // Limpieza automática al destruir el gestor
    borraAficionadosPila();
    borraAficionadosColas();
    // listaFinal se limpia en su destructor
}

int Gestor::AficionadosEnPila() const {
    return pila.getLongitud();
}

int Gestor::SociosEnCola() const {
    return colaSocios.getLongitud();
}

int Gestor::SimpatizantesEnCola() const {
    return colaSimpatizantes.getLongitud();
}

int Gestor::AficionadosEnLista() const {
    return listaFinal.getLongitud();
}

// Opción A: Generar 10 aficionados y meterlos en la pila
void Gestor::generar10Aficionados() {
    int baseID = remesaActual * 10 + 1;
    for (int i = 0; i < 10; ++i) {
        Aficionado afic(baseID + i);
        pila.insertar(afic);
    }
    remesaActual++;
    cout << "Se han generado 10 aficionados y almacenado en la pila.\n";
}

// Opción B: Mostrar pila
void Gestor::muestraAficionados() {
    pila.mostrar();
}

// Opción C: Borrar pila
void Gestor::borraAficionadosPila() {
    while (pila.getLongitud() > 0) {
        pila.extraer();
    }
    cout << "Pila borrada.\n";
}

// Opción D: Clasificar aficionados en colas
void Gestor::encolarAficionados() {
    while (pila.getLongitud() > 0) {
        Aficionado afic = pila.extraer();
        if (afic.esSocio()) {
            colaSocios.insertar(afic);
        } else {
            colaSimpatizantes.insertar(afic);
        }
    }
    cout << "Aficionados clasificados en colas.\n";
}

// Opción E: Mostrar cola de socios
void Gestor::muestraSociosCola() {
    cout << "Cola de socios:\n";
    colaSocios.mostrar();
}

// Opción F: Mostrar cola de simpatizantes
void Gestor::muestraSimpatizantesCola() {
    cout << "Cola de simpatizantes:\n";
    colaSimpatizantes.mostrar();
}

// Opción G: Borrar colas
void Gestor::borraAficionadosColas() {
    while (colaSocios.getLongitud() > 0) {
        colaSocios.eliminar();
    }
    while (colaSimpatizantes.getLongitud() > 0) {
        colaSimpatizantes.eliminar();
    }
    cout << "Colas borradas.\n";
}

// Opción H: Formar lista final ordenada por hora de llegada
void Gestor::enlistarAficionados() {
    std::vector<Aficionado> socios;
    std::vector<Aficionado> simpatizantes;
    while (colaSocios.getLongitud() > 0) {
        socios.push_back(colaSocios.eliminar());
    }
    while (colaSimpatizantes.getLongitud() > 0) {
        simpatizantes.push_back(colaSimpatizantes.eliminar());
    }
    std::sort(socios.begin(), socios.end(), [](const Aficionado& a, const Aficionado& b) {
        return a.getMinuto() < b.getMinuto();
    });
    for (const auto& afic : socios) {
        listaFinal.insertarFinal(afic); 
    }

    std::sort(simpatizantes.begin(), simpatizantes.end(), [](const Aficionado& a, const Aficionado& b) {
        return a.getMinuto() < b.getMinuto();
    });

    for (const auto& afic : simpatizantes) {
        listaFinal.insertarFinal(afic);
    }
    std::cout << "Lista final formada.\n";
}



// Opción I: Mostrar aficionados clave
void Gestor::buscarAficionados() {
    try {
        cout << "\n1. Primer aficionado en acceder:\n";
        listaFinal.getPrimero().mostrar();

        cout << "\n2. Último socio en acceder:\n";
        listaFinal.getUltimoSocio().mostrar();

        cout << "\n3. Primer simpatizante en acceder:\n";
        listaFinal.getPrimerSimpatizante().mostrar();

        cout << "\n4. Último aficionado en acceder:\n";
        listaFinal.getUltimo().mostrar();
    } catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
}

// Opción J: Reiniciar todo
void Gestor::reiniciar() {
    borraAficionadosPila();
    borraAficionadosColas();
    listaFinal.vaciar(); 
    remesaActual = 0;
    cout << "Sistema reiniciado.\n";
}

