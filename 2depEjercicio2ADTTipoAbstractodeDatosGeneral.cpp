#include <iostream>

using namespace std;

// Interfaz pura
class IADTGeneral {
public:
    virtual void agregar(int dato) = 0;
    virtual void eliminarUltimo() = 0;
    virtual void mostrar() = 0;
    virtual ~IADTGeneral() {}
};

// Clase abstracta que implementa la interfaz
class ADTContenedor : public IADTGeneral {
protected:
    static const int MAX = 20;
    int datos[MAX];
    int cantidad;

public:
    ADTContenedor() {
        cantidad = 0;
    }

    void agregar(int dato) override {
        if (cantidad < MAX) {
            datos[cantidad++] = dato;
            cout << "Elemento guardado.\n";
        } else {
            cout << "Arreglo lleno.\n";
        }
    }

    void eliminarUltimo() override {
        if (cantidad > 0) {
            cantidad--;
            cout << "Ultimo dato eliminado.\n";
        } else {
            cout << "El contenedor esta vacio.\n";
        }
    }

    void mostrar() override {
        if (cantidad == 0) {
            cout << "Coleccion vacia.\n";
            return;
        }
        cout << "Datos actuales: ";
        for (int i = 0; i < cantidad; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ADTContenedor estructura;
    int opcion, valor;

    for (;;) {
        cout << "\n--- ADT GENERAL ---\n";
        cout << "1. Insertar dato\n";
        cout << "2. Eliminar ultimo\n";
        cout << "3. Mostrar coleccion\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 4) break;

        switch (opcion) {
            case 1:
                cout << "Ingresa dato: ";
                cin >> valor;
                estructura.agregar(valor);
                break;
            case 2:
                estructura.eliminarUltimo();
                break;
            case 3:
                estructura.mostrar();
                break;
            default:
                cout << "Opcion incorrecta.\n";
                break;
        }
    }
    return 0;
}