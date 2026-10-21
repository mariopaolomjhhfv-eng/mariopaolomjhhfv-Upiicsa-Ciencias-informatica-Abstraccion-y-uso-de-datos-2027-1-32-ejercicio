#include <iostream>
#include <string>
using namespace std;

class Auto {
private:
    float precio;
    int anio;
    Auto* siguiente;

public:
    Auto() {
        precio = 0;
        anio = 0;
        siguiente = nullptr;
    }

    void capturar() {
        cout << "Ingrese el precio del auto: ";
        cin >> precio;
        cout << "Ingrese el anio del auto: ";
        cin >> anio;
    }

    void mostrar(int numero) const {
        cout << "Auto " << numero << " Precio: $" << precio
             << " | Anio: " << anio << endl;
    }

    void setSiguiente(Auto* s) {
        siguiente = s;
    }

    Auto* getSiguiente() const {
        return siguiente;
    }
};

class Persona {
private:
    string nombre;
    string ap;
    string am;
    string genero;
    int edad;
    Persona* siguiente;

public:
    Persona() {
        edad = 0;
        siguiente = nullptr;
    }

    void capturar() {
        cout << "Ingresa el nombre: ";
        cin >> nombre;
        cout << "Ingresa el apellido paterno: ";
        cin >> ap;
        cout << "Ingresa el apellido materno: ";
        cin >> am;
        cout << "Ingresa el genero: ";
        cin >> genero;
        cout << "Ingresa la edad: ";
        cin >> edad;
    }

    void mostrar(int numero) const {
        cout << "Persona " << numero << " -> " << nombre << " "
             << ap << " " << am
             << " | Genero: " << genero
             << " | Edad: " << edad << " anios" << endl;
    }

    void setSiguiente(Persona* s) {
        siguiente = s;
    }

    Persona* getSiguiente() const {
        return siguiente;
    }
};

int main() {

    const int TOTAL = 2;

    Auto autos[TOTAL];
    Persona personas[TOTAL];

    cout << "registro autos" << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "\nAuto " << (i + 1) << ":" << endl;
        autos[i].capturar();
        if (i > 0) {
            autos[i - 1].setSiguiente(&autos[i]);
        }
    }

    cout << "\n\nregistro persona" << endl;
    for (int i = 0; i < TOTAL; i++) {
        cout << "\nPersona " << (i + 1) << ":" << endl;
        personas[i].capturar();
        if (i > 0) {
            personas[i - 1].setSiguiente(&personas[i]);
        }
    }

    cout << "\n lista " << endl;
    Auto* actualAuto = &autos[0];
    int numAuto = 1;
    while (actualAuto != nullptr) {
        actualAuto->mostrar(numAuto);
        actualAuto = actualAuto->getSiguiente();
        numAuto++;
    }

    cout << "\n lista de personas " << endl;
    Persona* actualPersona = &personas[0];
    int numPersona = 1;
    while (actualPersona != nullptr) {
        actualPersona->mostrar(numPersona);
        actualPersona = actualPersona->getSiguiente();
        numPersona++;
    }

    return 0;
}