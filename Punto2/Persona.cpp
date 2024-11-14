#include <iostream>
#include "Persona.h"

using namespace std;

 Persona :: Persona(): Nombre(""), Descripcion(""), Edad(0) {} // Constructor por defecto
Persona:: Persona(string nombre, string biografia, int edad){
      Nombre= nombre;
      Descripcion=biografia;
      Edad= edad;
}


string Persona:: getNombre() const{
    return Nombre;
}
string Persona:: getBiografia()const {
    return Descripcion;
}
int Persona:: getEdad()const {
     return Edad;
}
   // Método para mostrar la información de la persona
    void Persona:: mostrarInformacion() const {
        std::cout << "Nombre: " << Nombre << "\nBiografía: " << Descripcion<< "\nEdad: " << Edad<< " años\n";
    }

// Supongamos que Persona tiene los métodos getNombre() y getApellido()
std::ostream& operator<<(std::ostream& os, const Persona& persona) {
    os << persona.getNombre() << " " << persona.getEdad();
    return os;
}