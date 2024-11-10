#include <iostream>
#include "Fila.h"
#include "IteradorFila.h"
#include "ContarX.h"

class Fecha {
private:
    int dia, mes, anio;
public:
    Fecha(int d = 1, int m = 1, int a = 2000) : dia(d), mes(m), anio(a) {}

    bool operator==(const Fecha& otra) const {
        return dia == otra.dia && mes == otra.mes && anio == otra.anio;
    }

    friend std::ostream& operator<<(std::ostream& os, const Fecha& f) {
        os << f.dia << "/" << f.mes << "/" << f.anio;
        return os;
    }
};

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

    return 0;
}