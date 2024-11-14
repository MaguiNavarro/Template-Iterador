#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>
using namespace std;

class Persona
{
private:
   string Nombre;
   string Descripcion;
   int Edad;

public:
    Persona();
    Persona( string nombre, string descripcion, int edad);
    string  getNombre() const;
    string  getBiografia() const;
    int  getEdad() const;
    void  mostrarInformacion()const;
    friend std::ostream& operator<<(std::ostream& os, const Persona& persona);
};

#endif // PERSONA_H
