#include <iostream>
#include <string>
using namespace std;

class Alumno {
private:
    string nombre;
    float promedio;

public:
    Alumno() : nombre(""), promedio(0) {} //Crea objeto Alumno vacío
    Alumno(string nombre, float promedio) : nombre(nombre), promedio(promedio) {} //Constructor con parámetros

    string getNombre() const { return nombre; } //Leer atributos privados
    float getPromedio() const { return promedio; }

    //Sobrecarga (define cómo se comparan dos alumnos)
    bool operator>(const Alumno& otro) const {
        return promedio > otro.promedio;
    }

    //Sobrecarga (define cómo se imprime un alumno)
    friend ostream& operator<<(ostream& os, const Alumno& a) {
        os << a.nombre << " (" << a.promedio << ")";
        return os;
    }
};

//Clase de ordenamiento 
template <typename T>
class Burbuja {
private:
    T* datos;
    int n;

public:
    Burbuja(T arreglo[], int tam) : n(tam) {
        datos = new T[n];
        for (int i = 0; i < n; i++) datos[i] = arreglo[i];
    }

    ~Burbuja() { delete[] datos; }

    void ordenar() {
        for (int i = 0; i < n - 1; i++) {
            bool huboCambio = false;
            for (int j = 0; j < n - 1 - i; j++) {
                if (datos[j] > datos[j + 1]) {
                    intercambiar(datos[j], datos[j + 1]);
                    huboCambio = true;
                }
            }
            if (!huboCambio) break;
        }
    }

    void mostrar(const string& titulo) const {
        cout << titulo;
        for (int i = 0; i < n; i++) cout << datos[i] << "  ";
        cout << endl;
    }

private:
    void intercambiar(T& a, T& b) {
        T aux = a;
        a = b;
        b = aux;
    }
};

//Principal
int main() {
    int enteros[] = {64, 25, 12, 22, 11, 90, 3};
    char letras[] = {'m', 'z', 'a', 'k', 'c', 'x'};
    Alumno alumnos[] = {
        Alumno("Lisette", 9.2f), Alumno("Paolo", 7.5f),
        Alumno("Julieta", 8.8f), Alumno("Jorge", 6.9f)
    };

    Burbuja<int> ordenE(enteros, 7);
    cout << "Enteros" << endl;
    ordenE.mostrar("Antes:   ");
    ordenE.ordenar();
    ordenE.mostrar("Después: ");

    Burbuja<char> ordenC(letras, 6);
    cout << "\nCaracteres" << endl;
    ordenC.mostrar("Antes:   ");
    ordenC.ordenar();
    ordenC.mostrar("Después: ");

    Burbuja<Alumno> ordenA(alumnos, 4);
    cout << "\nAlumnos por promedio" << endl;
    ordenA.mostrar("Antes:   ");
    ordenA.ordenar();
    ordenA.mostrar("Después: ");

    return 0;
}