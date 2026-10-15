#include <iostream>
using namespace std;

class Calculadora {
public:
    long long factorial(int n) {
        if (n <= 1) return 1;
        return n * factorial(n - 1);
    }

    int fibonacci(int n) {
        if (n <= 0) return 0;
        if (n == 1) return 1;
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

    int multiplicacion(int a, int b) {
        if (b == 0) return 0;
        return a + multiplicacion(a, b - 1);
    }

    int division(int a, int b) {
        if (b == 0) {
            cout << "No se puede dividir entre cero" << endl;
            return 0;
        }
        if (a < b) return 0;
        return 1 + division(a - b, b);
    }
};

int main() {
    Calculadora calc;
    int opcion, a, b;

    for (;;) {
        cout << "\nCALCULADORA RECURSIVA" << endl;
        cout << "1. Multiplicacion recursiva\n";
        cout << "2. Division recursiva\n";
        cout << "3. Factorial\n";
        cout << "4. Fibonacci\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        if (opcion == 5) {
            cout << "Saliendo..." << endl;
            break;
        }

        switch (opcion) {
            case 1:
                cout << "Ingresa primer numero: ";
                cin >> a;
                cout << "Ingresa segundo numero: ";
                cin >> b;
                cout << "Resultado: " << calc.multiplicacion(a, b) << endl;
                break;
            case 2:
                cout << "Ingresa dividendo: ";
                cin >> a;
                cout << "Ingresa divisor: ";
                cin >> b;
                cout << "Resultado: " << calc.division(a, b) << endl;
                break;
            case 3:
                cout << "Ingresa numero: ";
                cin >> a;
                cout << "Resultado: " << calc.factorial(a) << endl;
                break;
            case 4:
                cout << "Ingresa posicion: ";
                cin >> a;
                cout << "Resultado: " << calc.fibonacci(a) << endl;
                break;
            default:
                cout << "Opcion no valida\n";
                break;
        }
    }

    return 0;
}