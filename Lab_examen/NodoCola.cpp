#include "NodoCola.hpp"

NodoCola::NodoCola(Aficionado afic, NodoCola* sig) : valor(afic), siguiente(sig) {
}

NodoCola::~NodoCola() {}