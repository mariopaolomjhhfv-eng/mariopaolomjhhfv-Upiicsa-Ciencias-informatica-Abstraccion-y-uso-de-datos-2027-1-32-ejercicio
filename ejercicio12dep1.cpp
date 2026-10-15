#include <iostream>
#include <string>
using namespace std;

struct Auto {
    float precio;
    int anio;
};

struct Persona {
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
};

int main() {

    const int TOTAL = 2;

    Auto autos[TOTAL];
    Persona personas[TOTAL];
    cout << "registro autos" << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "\nAuto " << (i + 1) << ":" << endl;
        cout << "Ingrese el precio del auto: ";
        cin >> autos[i].precio;
        cout << "Ingrese el anio del auto: ";
        cin >> autos[i].anio;
    }

    cout << "\n\nregistro persona" << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "\nPersona " << (i + 1) << ":" << endl;
        cout << "Ingresa el nombre: ";
        cin >> personas[i].nombre;
        cout << "Ingresa el apellido paterno: ";
        cin >> personas[i].ap;
        cout << "Ingresa el apellido materno: ";
        cin >> personas[i].am;
        cout << "Ingresa el genero: ";
        cin >> personas[i].genero;
        cout << "Ingresa la edad: ";
        cin >> personas[i].edad;
    }

    cout << " lista " << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "Auto " << (i + 1) << " Precio: $" << autos[i].precio
             << " | Anio: " << autos[i].anio << endl;
    }



    cout << " lista de personas " << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "Persona " << (i + 1) << " -> " << personas[i].nombre << " "
             << personas[i].ap << " " << personas[i].am
             << " | Genero: " << personas[i].genero
             << " | Edad: " << personas[i].edad << " anios" << endl;
    }

    return 0;
}
