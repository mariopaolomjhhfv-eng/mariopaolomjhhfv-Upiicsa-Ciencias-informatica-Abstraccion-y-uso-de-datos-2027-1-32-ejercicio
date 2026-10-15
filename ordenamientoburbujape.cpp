#include <iostream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    float promedio;
};

//Burbuja para enteros
void burbujaEnteros(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool huboCambio = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                int aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                huboCambio = true;
            }
        }
        if (!huboCambio) break; //Se ordena
    }
}

//Burbuja para caracteres
void burbujaCaracteres(char v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool huboCambio = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j] > v[j + 1]) {
                char aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                huboCambio = true;
            }
        }
        if (!huboCambio) break;
    }
}

//Burbuja para Alumno (por promedio) 
void burbujaAlumnos(Alumno v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool huboCambio = false;
        for (int j = 0; j < n - 1 - i; j++) {
            if (v[j].promedio > v[j + 1].promedio) {
                Alumno aux = v[j];
                v[j] = v[j + 1];
                v[j + 1] = aux;
                huboCambio = true;
            }
        }
        if (!huboCambio) break;
    }
}

//Funciones de impresión
void imprimirEnteros(int v[], int n) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

void imprimirCaracteres(char v[], int n) {
    for (int i = 0; i < n; i++) cout << v[i] << " ";
    cout << endl;
}

void imprimirAlumnos(Alumno v[], int n) {
    for (int i = 0; i < n; i++)
        cout << "  " << v[i].nombre << " - " << v[i].promedio << endl;
}

//Programa principal
int main() {
    int enteros[] = {64, 25, 12, 22, 11, 90, 3};
    int nE = sizeof(enteros) / sizeof(enteros[0]);

    char letras[] = {'m', 'z', 'a', 'k', 'c', 'x'};
    int nC = sizeof(letras) / sizeof(letras[0]);

    Alumno alumnos[] = {
        {"Lisette", 9.2f}, {"Paolo", 7.5f}, {"Julieta", 8.8f}, {"Jorge", 6.9f}
    };
    int nA = sizeof(alumnos) / sizeof(alumnos[0]);

    cout << "Enteros" << endl;
    cout << "Antes:   "; imprimirEnteros(enteros, nE);
    burbujaEnteros(enteros, nE);
    cout << "Después: "; imprimirEnteros(enteros, nE);

    cout << "\nCaracteres" << endl;
    cout << "Antes:   "; imprimirCaracteres(letras, nC);
    burbujaCaracteres(letras, nC);
    cout << "Después: "; imprimirCaracteres(letras, nC);

    cout << "\nAlumnos (por promedio)" << endl;
    cout << "Antes:" << endl;   imprimirAlumnos(alumnos, nA);
    burbujaAlumnos(alumnos, nA);
    cout << "Después:" << endl; imprimirAlumnos(alumnos, nA);

    return 0;
}