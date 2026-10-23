#include <iostream>

using namespace std;

class ColaDinamica {
private:
    struct Nodo {
        int dato;
        Nodo* siguiente;
    };
    Nodo* frente;
    Nodo* fin;

public:
    ColaDinamica() {
        frente = NULL;
        fin = NULL;
    }

    bool estaVacia() {
        return frente == NULL;
    }

    void insertar(int n) {
        Nodo* nuevo = new Nodo();
        nuevo->dato = n;
        nuevo->siguiente = NULL;
        if (estaVacia()) {
            frente = nuevo;
        } else {
            fin->siguiente = nuevo;
        }
        fin = nuevo;
    }

    void quitar(int &n) {
        if (estaVacia()) return;
        n = frente->dato;
        Nodo* aux = frente;
        frente = frente->siguiente;
        if (frente == NULL) {
            fin = NULL;
        }
        delete aux;
    }

    void mostrar() {
        Nodo* actual = frente;
        while (actual != NULL) {
            cout << actual->dato << " ";
            actual = actual->siguiente;
        }
        cout << endl;
    }
};

int main() {
    ColaDinamica cola;
    int op, dato;
    do {
        cin >> op;
        switch(op) {
            case 1:
                cin >> dato;
                cola.insertar(dato);
                break;
            case 2:
                cola.quitar(dato);
                break;
            case 3:
                cola.mostrar();
                break;
        }
    } while(op != 4);
    return 0;
}