#include <iostream>
#include <list>

using namespace std;

class GestorLista {
private:
    list<int> listaNumeros;

public:
    void insertarFinal(int val) {
        listaNumeros.push_back(val);
        cout << "Elemento agregado al final.\n";
    }

    void insertarInicio(int val) {
        listaNumeros.push_front(val);
        cout << "Elemento agregado al inicio.\n";
    }

    void eliminar(int val) {
        if (listaNumeros.empty()) {
            cout << "La lista esta vacia.\n";
            return;
        }
        listaNumeros.remove(val);
        cout << "Si existia el valor " << val << ", ha sido eliminado.\n";
    }

    void mostrar() {
        if (listaNumeros.empty()) {
            cout << "Lista vacia.\n";
            return;
        }
        cout << "Contenido de la lista: ";
        for (int elemento : listaNumeros) {
            cout << elemento << " -> ";
        }
        cout << "NULL" << endl;
    }
};

int main() {
    GestorLista miLista;
    int opcion, val;

    for (;;) {
        cout << "\n--- LISTA DINAMICA (STL) ---\n";
        cout << "1. Insertar al inicio\n";
        cout << "2. Insertar al final\n";
        cout << "3. Eliminar un valor\n";
        cout << "4. Mostrar lista\n";
        cout << "5. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 5) break;

        switch (opcion) {
            case 1:
                cout << "Numero a insertar al inicio: ";
                cin >> val;
                miLista.insertarInicio(val);
                break;
            case 2:
                cout << "Numero a insertar al final: ";
                cin >> val;
                miLista.insertarFinal(val);
                break;
            case 3:
                cout << "Numero a eliminar: ";
                cin >> val;
                miLista.eliminar(val);
                break;
            case 4:
                miLista.mostrar();
                break;
            default:
                cout << "Opcion incorrecta.\n";
                break;
        }
    }
    return 0;
}