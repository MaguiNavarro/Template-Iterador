#ifndef CONTARX_H
#define CONTARX_H

#include "IteradorFila.h"

template <typename X>
int ContarX(const Fila<X>& fila, const X& elemento) {
    int contador = 0;
    IteradorFila<X> iterador(fila);
    while (iterador.hayMasElementos()) {
        if (iterador.elementoActual() == elemento) {
            contador++;
        }
        iterador.avanzar();
    }
    return contador;
}

#endif // CONTARX_H