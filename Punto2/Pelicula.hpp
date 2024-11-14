#include <iostream>
#include <iomanip> 
#include "Persona.h"
#include "Fecha.h"

using namespace std;
class Pelicula
{
private:
   static int autonumerico;
   int codigo;
    string titulo;
    Persona director;
     Fecha estreno;
    float precioBase;
    char tipoPelicula;

    
 
public:
    Pelicula();
    Pelicula(  string titulo, Persona director, Fecha estreno, float precio, char tipoPelicula);

      // Constructor de copia
    Pelicula(const Pelicula& p);


    void mostrarInformacion();
    float calcularCosto()const;

        // Getters 
    int getCodigo() const { return codigo; }
    string getTitulo() const { return titulo; }
    Persona getDirector() const { return director; }
    Fecha getEstreno() const { return estreno; }
    float getPrecioBase() const { return precioBase; }
    char getTipoPelicula() const { return tipoPelicula; }
    friend ostream& operator<<(std:: ostream& os, const Pelicula& pelicula);

};

