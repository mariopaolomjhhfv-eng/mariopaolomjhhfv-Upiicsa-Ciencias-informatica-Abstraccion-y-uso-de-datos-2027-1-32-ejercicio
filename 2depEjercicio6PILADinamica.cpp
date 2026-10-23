#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class PilaDinamica {
private:
    Nodo* tope;

public:
    PilaDinamica() {
        tope = nullptr;
    }

    void push(int val) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = val;
        nuevo->siguiente = tope;
        tope = nuevo;
        cout << "Dato apilado en memoria dinamica.\n";
    }

    void pop() {
        if (tope == nullptr) {
            cout << "Pila vacia.\n";
            return;
        }
        Nodo* aux = tope;
        cout << "Elemento retirado: " << aux->dato << endl;
        tope = tope->siguiente;
        delete aux;
    }

    void mostrar() {
        if (tope == nullptr) {
            cout << "Pila vacia.\n";
            return;
        }
        Nodo* actual = tope;
        cout << "Pila [tope -> fondo]: ";
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    ~PilaDinamica() {
        while (tope != nullptr) {
            Nodo* aux = tope;
            tope = tope->siguiente;
            delete aux;
        }
    }
};

int main() {
    PilaDinamica pila;
    int opcion, val;

    for (;;) {
        cout << "\n--- MENU PILA DINAMICA ---\n";
        cout << "1. Push (Apilar)\n";
        cout << "2. Pop (Desapilar)\n";
        cout << "3. Mostrar pila\n";
        cout << "4. Salir\n";
        cout << "Selecciona opcion: ";
        cin >> opcion;

        if (opcion == 4) break;

        switch (opcion) {
            case 1:
                cout << "Ingresa valor: ";
                cin >> val;
                pila.push(val);
                break;
            case 2:
                pila.pop();
                break;
            case 3:
                pila.mostrar();
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    }
    return 0;
}