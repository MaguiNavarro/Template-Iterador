#include <iostream>
#include "Fila.h"
#include "IteradorFila.h"
#include "ContarX.h"
#include "Pelicula.hpp"
#include "Persona.h"
#include "Fecha.h"


// class Fecha {
// private:
//     int dia, mes, anio;
// public:
//     Fecha(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}

//     bool operator==(const Fecha& otra) const {
//         return dia == otra.dia && mes == otra.mes && anio == otra.anio;
//     }

//     friend std::ostream& operator<<(std::ostream& os, const Fecha& f) {
//         os << f.dia << "/" << f.mes << "/" << f.anio;
//         return os;
//     }
// };

int main() {
    // Fila de enteros
    Fila<int> filaInt;
    filaInt.Enfila(1);
    filaInt.Enfila(2);
    filaInt.Enfila(1);
    std::cout << "Conteo de 1 en filaInt: " << ContarX(filaInt, 1) << std::endl;

    // Fila de fechas
    Fila<Fecha> filaFecha;
    filaFecha.Enfila(Fecha(1, 1, 2023));
    filaFecha.Enfila(Fecha(2, 2, 2023));
    filaFecha.Enfila(Fecha(1, 1, 2023));
    std::cout << "Conteo de 1/1/2023 en filaFecha: " << ContarX(filaFecha, Fecha(1, 1, 2023)) << std::endl;
      
     Fila<Pelicula> filaPeli;
     Fecha estreno1(16, 7, 2024);
     Persona director("Christopher Nolan", "Es un director britanico famoso por peliculas como Inception y The Dark Knight.", 53);
     filaPeli.Enfila(Pelicula("Inception",director,estreno1,100.0, 'I' ));
     filaPeli.Mostrar();


    return 0;
}