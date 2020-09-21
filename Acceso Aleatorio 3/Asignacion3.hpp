#pragma once
using namespace std;
class Asignacion3{
    public:
        void escribir_o_leer(fstream &fcont, bool Escribir);
        void leer_el_3(fstream &fcont, Contacto &cont);
        void escribir_el_3(fstream &fcont, Contacto &cont);
        void cambios(fstream &fcont);
};