#include <iostream>

#include "Fila.h"
#include "Iterador.h"


using namespace std;
int ContarX(const Fila& fila, item X);


int main() {


	// Creamos una fila y agregamos algunos elementos
    Fila fila;// Creo un objeto fila con el constructor por defecto
    fila.Enfila(1);
    fila.Enfila(2);
    fila.Enfila(3);
    fila.Enfila(1);
    fila.Enfila(5);

  
   std::cout << "Elementos en la fila: ";
    fila.Mostrar();

   
    std::cout << "Iterando sobre la fila: ";
    Iterador iterador(fila);
    while (iterador.hayMasElementos()) {
        std::cout << iterador.elementoActual() << " ";
        iterador.avanzar();
    }
    std::cout << std::endl;
     

     // Prueba de la función ContarX
    item X = 5;
    int cantidad = ContarX(fila, X);
    std::cout << "Cantidad de elementos iguales a " << X << ": " << cantidad << std::endl;

    return 0;
	
}
int  ContarX( const Fila& fila, item X) {
    Iterador iterador(fila);
    int contador = 0;

    while (iterador.hayMasElementos()) {
        if (iterador.elementoActual() == X) {
            contador++;
        }
        iterador.avanzar();
    }

    return contador;
}
