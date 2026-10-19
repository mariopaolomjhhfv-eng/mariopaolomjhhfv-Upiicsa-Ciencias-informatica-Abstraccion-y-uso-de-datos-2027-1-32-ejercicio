#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
    float precio;
    int anio;

public:
    void capturarDatos() {
        cout << "Ingrese el precio del auto: ";
        cin >> precio;

        cout << "Ingrese el anio del auto: ";
        cin >> anio;
    }

    void mostrarDatos() {
        cout << "\nDATOS DEL AUTO" << endl;
        cout << "Precio: $" << precio << endl;
        cout << "Anio: " << anio << endl;
    }
};

int main() {
    Auto auto1;

    auto1.capturarDatos();
    auto1.mostrarDatos();

    return 0;
}
