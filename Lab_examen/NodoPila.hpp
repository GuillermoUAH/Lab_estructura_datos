#ifndef NODOPILA_HPP
#define NODOPILA_HPP

class NodoPila
{
public:
    NodoPila(int v, NodoPila* sig = nullptr);
    ~NodoPila();

private:
    int valor;
    NodoPila* siguiente;

    friend class Pila;
};

typedef NodoPila* pnodoPila;

#endif // NODOPILA_HPP
