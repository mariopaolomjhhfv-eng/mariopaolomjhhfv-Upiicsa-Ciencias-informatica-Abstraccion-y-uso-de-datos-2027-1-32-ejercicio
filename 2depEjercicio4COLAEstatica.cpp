#include <iostream>

using namespace std;

#define MAX 5

class ColaEstatica {
private:
    int datos[MAX];
    int frente;
    int final;

public:
    ColaEstatica() {
        frente = 0;
        final = -1;
    }

    void encolar(int val) {
        if (final >= MAX - 1) {
            cout << "Cola llena (Overflow).\n";
            return;
        }
        datos[++final] = val;
        cout << "Elemento encolado correctamente.\n";
    }

    void desencolar() {
        if (frente > final) {
            cout << "Cola vacia (Underflow).\n";
            return;
        }
        cout << "Elemento atendido: " << datos[frente++] << endl;
        // Reiniciar indices si la cola se vacio
        if (frente > final) {
            frente = 0;
            final = -1;
        }
    }

    void mostrar() {
        if (frente > final || final == -1) {
            cout << "Cola vacia.\n";
            return;
        }
        cout << "Cola [frente -> final]: ";
        for (int i = frente; i <= final; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    ColaEstatica cola;
    int opcion, val;

    for (;;) {
        cout << "\n--- MENU COLA ESTATICA ---\n";
        cout << "1. Encolar (Insertar)\n";
        cout << "2. Desencolar (Eliminar)\n";
        cout << "3. Mostrar cola\n";
        cout << "4. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 4) break;

        switch (opcion) {
            case 1:
                cout << "Valor a encolar: ";
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