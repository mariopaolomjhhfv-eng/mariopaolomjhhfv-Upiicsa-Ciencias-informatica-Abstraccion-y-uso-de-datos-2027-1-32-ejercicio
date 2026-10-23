#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ColaDinamica {
private:
    Nodo* frente;
    Nodo* final;

public:
    ColaDinamica() {
        frente = nullptr;
        final = nullptr;
    }

    void encolar(int val) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = val;
        nuevo->siguiente = nullptr;

        if (frente == nullptr) {
            frente = nuevo;
            final = nuevo;
        } else {
            final->siguiente = nuevo;
            final = nuevo;
        }
        cout << "Elemento " << val << " encolado correctamente.\n";
    }

    void desencolar() {
        if (frente == nullptr) {
            cout << "Cola vacia (Underflow).\n";
            return;
        }

        Nodo* aux = frente;
        cout << "Elemento atendido: " << aux->dato << endl;
        frente = frente->siguiente;

        if (frente == nullptr) {
            final = nullptr;
        }

        delete aux;
    }

    void mostrar() {
        if (frente == nullptr) {
            cout << "Cola vacia.\n";
            return;
        }

        Nodo* actual = frente;
        cout << "Cola [frente -> final]: ";
        while (actual != nullptr) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }

    ~ColaDinamica() {
        while (frente != nullptr) {
            Nodo* aux = frente;
            frente = frente->siguiente;
            delete aux;
        }
    }
};

int main() {
    ColaDinamica cola;
    int opcion, val;

    for (;;) {
        cout << "\n--- MENU COLA DINAMICA ---\n";
        cout << "1. Encolar (Insertar)\n";
        cout << "2. Desencolar (Atender)\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 4) break;

        switch (opcion) {
            case 1:
                cout << "Ingresa valor: ";
                cin >> val;
                cola.encolar(val);
                break;
            case 2:
                cola.desencolar();
                break;
            case 3:
                cola.mostrar();
                break;
            default:
                cout << "Opcion no valida.\n";
                break;
        }
    }

    return 0;
}