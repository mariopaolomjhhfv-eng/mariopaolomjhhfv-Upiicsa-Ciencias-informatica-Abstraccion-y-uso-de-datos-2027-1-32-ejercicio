#include <iostream>

using namespace std;

class OperacionSuma {
public:
    int calcular(int num1, int num2) {
        return num1 + num2;
    }
};

int main() {
    OperacionSuma suma;

    int a = 18;
    int b = 27;

    int resultado = suma.calcular(a, b);

    cout << "El resultado de la suma es: " << resultado << endl;

    return 0;
}