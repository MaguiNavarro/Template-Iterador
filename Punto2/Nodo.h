#ifndef NODO_H
#define NODO_H

template <typename T>
class Nodo {
public:
    T dato;
    Nodo* siguiente;

    Nodo(const T& d) : dato(d), siguiente(nullptr) {}
};

#endif // NODO_H