#ifndef ITERADORFILA_H
#define ITERADORFILA_H

#include "Fila.h"
#include "Nodo.h"

template <typename T>
class Fila;
template <typename T>
class IteradorFila {
private:
    const Fila<T>& fila;
    Nodo<T>* actual;

public:
    IteradorFila(const Fila<T>& f) : fila(f), actual(f.getFrente()) {}

    bool hayMasElementos() const {
        return actual != nullptr;
    }

    T elementoActual() const {
        if (actual != nullptr) {
            return actual->dato;
        }
        throw std::runtime_error("No hay elementos");
    }

    void avanzar() {
        if (actual != nullptr) {
            actual = actual->siguiente;
        }
    }
};

#endif // ITERADORFILA_H