
#include <iostream>
#include <string>
using namespace std;


struct Auto {
    float precio;
    int anio;
};

int main() {
    Auto auto1;

    cout << "Ingrese el precio del auto: ";
    cin >> auto1.precio;

    cout << "Ingrese el anio del auto: ";
    cin >> auto1.anio;

    cout << "\nDATOS DEL AUTO" << endl;
    cout << "Precio: $" << auto1.precio << endl;
    cout << "Anio: " << auto1.anio << endl;

    return 0;
}

