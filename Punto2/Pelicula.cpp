#include <iostream>
#include <iomanip>


#include "Pelicula.hpp"
using namespace std;

int Pelicula::autonumerico = 0; // Inicialización del autonumérico

// Constructor por defecto
Pelicula::Pelicula() : titulo(""), director(Persona("Nolan", "nada", 2019)), estreno(Fecha(2,7,2019)), precioBase(0.0f), tipoPelicula('N')
{
    // No se incrementa el autonumérico porque el código es 0 en este caso
}
// Constructor con parámetros

Pelicula::Pelicula(string titul, Persona direc, Fecha estre, float precio, char tipoPeli)
{
     autonumerico++;
    codigo = 0;
    titulo = titul;
    director = direc;
    estreno = estre;
    precioBase = precio;
    tipoPelicula = tipoPeli;
}
// Constructor Copia
Pelicula::Pelicula(const Pelicula &original)
{
    autonumerico++;
    // No incrementar autonumerico, copiamos tal cual los atributos del objeto original, ya que el objetivo del constructor copia es duplicar el objeto tal como es, sin modificar el código.
    codigo = original.codigo; // Mantener el mismo código
    titulo = original.titulo;
    director = original.director;
    estreno = original.estreno;
    precioBase = original.precioBase;
    tipoPelicula = original.tipoPelicula;
}
// Método para listar la información
void Pelicula::mostrarInformacion()
{
    cout << "Codigo: " << codigo << endl;
    cout << "Titulo: " << titulo << endl;
    cout << "Director: " << director.getNombre() << endl;
    // No dentro de cout
    cout << "Fecha de Estreno: ";
    estreno.mostrarFecha(); // mostrarFecha() imprime la fecha directamente
    cout << endl;
    cout << "Precio Base: $" << precioBase << endl;
    cout << "Tipo de Pelicula: " << (tipoPelicula == 'N' ? "Nacional" : "Internacional") << endl;
}
// Método para calcular el costo
float Pelicula::calcularCosto() const
{
    float costo = precioBase;
    int AnioEstreno = estreno.getAnio();
    if (tipoPelicula == 'I')
    {
        costo *= 1.30; // Si es internacional, se aumenta el costo en un 30%
    }
    else if (estreno.esEstreno())
    {
        costo *= 0.8; // Si no es estreno, se disminuye el costo en un 20%
    }

    return costo;
}



std::ostream& operator<<(std::ostream& os, const Pelicula& pelicula) {
    os << "ID: " << pelicula.autonumerico << "\n"
       << "Codigo: " << pelicula.getCodigo() << "\n"
       << "Titulo: " << pelicula.getTitulo() << "\n"
       << "Director: " << pelicula.getDirector() << "\n"
       << "Fecha Estreno: " << pelicula.getEstreno() << "\n"
       << "Precio Base: $" << pelicula.getPrecioBase() << "\n"
       << "Tipo Pelicula: " << (pelicula.getTipoPelicula() == 'N' ? "Nacional" : "Internacional") << "\n"
       << "Costo Final: $" << pelicula.calcularCosto()<< "\n";

    return os;
}

// int main()
// {
//     // // Crear una película usando el constructor por defecto
//     // Pelicula p1;
//     // p1.mostrarInformacion();
//     // cout << "Costo: $" << p1.calcularCosto() << endl
//     //      << endl;

//     // // Crear una película usando el constructor con parámetros
//     // Pelicula p2("Inception", "Christopher Nolan", true, 100.0, 'I');
//     // p2.mostrarInformacion();
//     // cout << "Costo: $" << p2.calcularCosto() << endl
//     //      << endl;

//     // // Crear una copia de la película p2 usando el constructor copia
//     // Pelicula p3(p2);
//     // p3.mostrarInformacion();
//     // cout << "Costo: $" << p3.calcularCosto() << endl
//     //      << endl;

//  // Crear una instancia de Persona (el director)
//     Persona director1("Christopher Nolan", "Es un director britanico famoso por peliculas como Inception y The Dark Knight.", 53);

//     // Crear una instancia de Fecha (el estreno de la película)
//     Fecha estreno1(16, 7, 2024); // 16 de julio de 2010

//     // Crear una película usando el constructor con parámetros
//     Pelicula pelicula1("Inception", director1, estreno1, 100.0, 'I');

//     // Mostrar información de la película, incluyendo la fecha de estreno
//     pelicula1.mostrarInformacion();
//      // Obtener y mostrar la biografía del director de la película
//     std::cout << director1.getBiografia() << std::endl;

//     // Verificar si es un estreno reciente (año actual o año pasado)
//     if (estreno1.esEstreno()) {
//         std::cout << "La pelicula es un estreno reciente." << std::endl;
//     } else {
//         std::cout << "La pelicula no es un estreno reciente." << std::endl;
//     }

//     return 0;
// }