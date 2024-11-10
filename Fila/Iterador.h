#ifndef ITERADOR_H_
#define ITERADOR_H_
using namespace std;
#include "Nodo.h" 
#include "Fila.h"
class Fila;
class Iterador
{
    const Fila& fila;  // Referencia constante a la fila que queremos iterar
    Nodo* actual;      // Puntero al nodo actual

public:
   Iterador(const Fila& f);
     bool hayMasElementos() const;
     int  elementoActual() const ;
     void  avanzar() ;

};


#endif // ITERADOR_H_


