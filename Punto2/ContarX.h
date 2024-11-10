#ifndef CONTARX_H
#define CONTARX_H

#include "IteradorFila.h"

template <typename T>
int ContarX(const Fila<T>& fila, const T& elemento) {
    int contador = 0;
    IteradorDeFila<T> iterador(fila);
    while (iterador.hayMasElementos()) {
        if (iterador.elementoActual() == elemento) {
            contador++;
        }
        iterador.avanzar();
    }
    return contador;
}

#endif // CONTARX_H