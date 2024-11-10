
#include "Iterador.h"


Iterador::Iterador(const Fila& f) : fila(f)
{}
 // Verifica si hay más elementos en la fila
bool Iterador:: hayMasElementos() const {
    return actual != nullptr;
}
// Retorna el elemento actual
int  Iterador:: elementoActual() const {
     if (actual != nullptr) {
        return actual->getDato();
     }
       return -1;
 }

    // Avanza el iterador al siguiente nodo
void  Iterador:: avanzar() {
        if (actual != nullptr) {
            actual = actual->getSiguiente();
        }
    }
