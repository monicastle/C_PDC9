#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Contacto.cpp"
#include "Asignacion3.hpp"
using namespace std;
void Asignacion3::escribir_o_leer(fstream &fcont, bool Escribir) {
    for (int i = 0; i < 6; ++i)
        if (Escribir) {
            Contacto cont("FALTA TELEFONO", "Nombre " + to_string(i), i);
            fcont.write(reinterpret_cast<const char *>(&cont), sizeof(Contacto));
        } else {
            Contacto cont;
            fcont.seekp(i*sizeof(Contacto));
            fcont.read(reinterpret_cast< char *>(&cont), sizeof(Contacto));
            cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
        }    
}
void Asignacion3::leer_el_3(fstream &fcont, Contacto &cont) {
    fcont.seekp(3*sizeof(Contacto));
    fcont.read(reinterpret_cast< char *>(&cont), sizeof(Contacto));
    cout << cont.obtenerId() << ":" << cont.obtenerNombre() << endl;
}
void Asignacion3::escribir_el_3(fstream &fcont, Contacto &cont) {
    fcont.seekp(3*sizeof(Contacto));   
    cont.establecerId(5000);
    cont.establecerNombre("NOMBRE 5 -> 5000");
    fcont.write(reinterpret_cast<const char *>(&cont), sizeof(Contacto));
}
void Asignacion3::cambios(fstream &fcont) {
    Contacto cont;
    leer_el_3(fcont, cont);
    escribir_el_3(fcont, cont);
    leer_el_3(fcont, cont);
}