#include "Fila.h"

// Constructor por defecto que crea una fila vacía
Fila::Fila() : frente(nullptr), final(nullptr), longitud(0) {}

// Destructor que elimina la memoria asignada dinámicamente en la fila
Fila::~Fila() {
    while (!EsFilaVacia()) {
        Defila();
    }
}

Fila::Fila(const Fila& otra) : frente(nullptr), final(nullptr), longitud(0) {
    Nodo* actual = otra.frente; // va a crear nuevos nodos y copiar los datos uno por uno, para que la nueva fila sea independiente de la fila original.
    while (actual != nullptr) {
        Enfila(actual->getDato());     // Copia los datos de cada nodo de otra y los agrega al final de la nueva fila, utilizando la función Enfila().
        actual = actual->getSiguiente();
    }
}

// Verifica si la fila está vacía
bool Fila::EsFilaVacia() const {
    return frente == nullptr;
}
// Retorna el elemento al frente de la fila
int Fila::Frente() const {
    if (!EsFilaVacia()) {
        return frente->getDato();
    } 
     return -1;
}

// Elimina el elemento al frente de la fila
void Fila::Defila() {
    if (!EsFilaVacia()) {
        Nodo* temp = frente;
        frente = frente->getSiguiente();
        delete temp;
        longitud--;
        if (frente == nullptr) {
            final = nullptr;
        }
    }
 }

 void Fila::Enfila(int valor) {
    Nodo* nuevo = new Nodo{valor, nullptr};
    if (EsFilaVacia()) {
        frente = nuevo;
        final = nuevo;
    } else {
        final->setSiguiente(nuevo);
        final = nuevo;
    }
    longitud++;
}

int Fila::Longitud() const {
    return longitud;
}


bool Fila::Pertenece(int valor) const {
    Nodo* actual = frente;
    while (actual != nullptr) {
        if (actual->getDato() == valor) {
            return true;
        }
        actual = actual->getSiguiente();
    }
    return false;
}


void Fila::Mostrar() const {
    Nodo* actual = frente;
    while (actual != nullptr) {
        cout << actual->getDato() << " ";
        actual = actual->getSiguiente();
    }
    cout << endl;
}

// Función que cuenta los elementos iguales a X en la fila
// int Fila:: ContarX(Fila fila, item X) {
//     int contador = 0;
//     while (!fila.EsFilaVacia()) {
//         if (fila.Frente() == X) {
//             contador++;
//         }
//         fila.Defila();
//     }
//     return contador;
// }



