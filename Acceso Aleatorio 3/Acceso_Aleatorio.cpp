#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Contacto.hpp"
#include "Asignacion3.hpp"
using namespace std;
int main() {
    Asignacion3 a;
    fstream fcont0("contactos.dat", ios::out);
    fcont0.close();
    fstream fcont("contactos.dat", ios::in | ios::out | ios::binary);
    a.escribir_o_leer(fcont, true);
    cout << "ANTES:" << endl;
    a.escribir_o_leer(fcont, false);
    cout << endl << "CAMBIOS:" << endl;
    a.cambios(fcont);
    cout << endl << "DESPUES:" << endl;
    a.escribir_o_leer(fcont, false);
}