#include <iostream>
#include <string>

using namespace std;

class EmpleadoPunteroObjeto {
public:
    string apellido;
};

int main() {
    EmpleadoPunteroObjeto equipo[3] = {{"Najera"}, {"Mendoza"}, {"Quiroz"}};
    EmpleadoPunteroObjeto *apuntador = equipo;

    cout << "Recorrido con punteros (POO):" << endl;
    for(int k = 0; k < 3; k++) {
        cout << (apuntador + k)->apellido << endl;
    }
    return 0;
}