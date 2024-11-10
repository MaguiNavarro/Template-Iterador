#ifndef FILA_H
#define FILA_H


#include <iostream>
#include "Nodo.h"
#include "IteradorFila.h"
using namespace std;



template <typename T>
class Fila {
private:
    Nodo<T>* frente;
    Nodo<T>* final;

public:
    Fila() : frente(nullptr), final(nullptr) {}

    ~Fila() {
        while (frente != nullptr) {
            Nodo<T>* temp = frente;
            frente = frente->siguiente;
            delete temp;
        }
    }

    void Enfila(const T& elemento) {
        Nodo<T>* nuevoNodo = new Nodo<T>(elemento);
        if (final == nullptr) {
            frente = final = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
        }
    }

    bool estaVacia() const {
        return frente == nullptr;
    }

    T Defila() {
        if (estaVacia()) {
            throw std::runtime_error("Fila vacía");
        }
        Nodo<T>* temp = frente;
        T dato = frente->dato;
        frente = frente->siguiente;
        if (frente == nullptr) {
            final = nullptr;
        }
        delete temp;
        return dato;
    }

    Nodo<T>* getFrente() const {
        return frente;
    }

    // Función para depuración
    void Mostrar() const {
        Nodo<T>* actual = frente;
        while (actual != nullptr) {
            std::cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        std::cout << std::endl;
    }

    // Necesario para el iterador
    friend class IteradorFila<T>;
};

#endif // FILA_H