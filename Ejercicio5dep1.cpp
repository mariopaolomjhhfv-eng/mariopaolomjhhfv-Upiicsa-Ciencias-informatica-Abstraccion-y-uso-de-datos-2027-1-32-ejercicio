#include <iostream>

using namespace std;

class OperacionesBasicas {
public:
    int sumar(int x, int y) {
        return x + y;
    }

    int restar(int x, int y) {
        return x - y;
    }
};

class OperacionesAvanzadas : public OperacionesBasicas {
public:
    int multiplicar(int x, int y) {
        return x * y;
    }

    int dividir(int x, int y) {
        if (y != 0) {
            return x / y;
        }
        cout << "Error: Division por cero" << endl;
        return 0;
    }
};

int main() {
    OperacionesAvanzadas miCalculadora;

    int valor1 = 15;
    int valor2 = 3;

    cout << "Resultado suma (heredada): " << miCalculadora.sumar(valor1, valor2) << endl;
    cout << "Resultado resta (heredada): " << miCalculadora.restar(valor1, valor2) << endl;

    cout << "Resultado multiplicacion (nueva): " << miCalculadora.multiplicar(valor1, valor2) << endl;
    cout << "Resultado division (nueva): " << miCalculadora.dividir(valor1, valor2) << endl;

    return 0;
}