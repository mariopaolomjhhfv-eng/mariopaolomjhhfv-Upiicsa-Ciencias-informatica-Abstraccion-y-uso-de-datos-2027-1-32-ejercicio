#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Pila {
private:
    static const int MAX = 10;
    int datos[MAX];
    int tope;

public:
    Pila() {
        tope = -1;
    }

    bool estaVacia() const {
        return tope == -1;
    }

    bool estaLlena() const {
        return tope == MAX - 1;
    }

    int tamanio() const {
        return tope + 1;
    }

    bool push(int valor) {
        if (estaLlena()) return false;
        datos[++tope] = valor;
        return true;
    }

    bool pop(int& valor) {
        if (estaVacia()) return false;
        valor = datos[tope--];
        return true;
    }

    bool cima(int& valor) const {
        if (estaVacia()) return false;
        valor = datos[tope];
        return true;
    }

    void vaciar() {
        tope = -1;
    }

    void mostrar() const {
        if (estaVacia()) {
            cout << "La pila esta vacia." << endl;
            return;
        }
        cout << "Cima " << endl;
        for (int i = tope; i >= 0; i--) {
            cout << "  [" << i << "] " << datos[i] << endl;
        }
        cout << "Base" << endl;
    }

    int capacidad() const {
        return MAX;
    }
};

int leerEntero(const string& mensaje) {
    int valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) return valor;
        cout << "Entrada no valida, intente de nuevo." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int main() {
    Pila pila;
    int opcion;

    do {
        cout << "\nPila Estatica" << endl;
        cout << "1. Insertar (push)" << endl;
        cout << "2. Eliminar (pop)" << endl;
        cout << "3. Ver cima" << endl;
        cout << "4. Mostrar pila" << endl;
        cout << "5. Tamanio actual" << endl;
        cout << "6. Vaciar pila" << endl;
        cout << "0. Salir" << endl;
        opcion = leerEntero("Opcion: ");

        switch (opcion) {
            case 1: {
                if (pila.estaLlena()) {
                    cout << "Desbordamiento: la pila esta llena ("
                         << pila.capacidad() << " elementos)." << endl;
                } else {
                    int valor = leerEntero("Ingrese el valor: ");
                    pila.push(valor);
                    cout << "Valor " << valor << " insertado." << endl;
                }
                break;
            }
            case 2: {
                int valor;
                if (pila.pop(valor))
                    cout << "Elemento eliminado: " << valor << endl;
                else
                    cout << "Subdesbordamiento: la pila esta vacia." << endl;
                break;
            }
            case 3: {
                int valor;
                if (pila.cima(valor))
                    cout << "Elemento en la cima: " << valor << endl;
                else
                    cout << "La pila esta vacia." << endl;
                break;
            }
            case 4:
                pila.mostrar();
                break;
            case 5:
                cout << "Elementos: " << pila.tamanio()
                     << " de " << pila.capacidad() << endl;
                break;
            case 6:
                pila.vaciar();
                cout << "Pila vaciada." << endl;
                break;
            case 0:
                cout << "Hasta luego." << endl;
                break;
            default:
                cout << "Opcion no valida." << endl;
        }
    } while (opcion != 0);

    return 0;
}