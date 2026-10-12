#include <iostream>

class Sumadora {
public:
    // Método que recibe 2 números como parámetros y regresa la suma
    double sumar(double a, double b) {
        return a + b;
    }
};

int main() {
    Sumadora miCalculadora;
    
    double num1, num2;
    std::cout << "Ingresa el primer numero: ";
    std::cin >> num1;
    
    std::cout << "Ingresa el segundo numero: ";
    std::cin >> num2;
    
    double resultado = miCalculadora.sumar(num1, num2);
    std::cout << "La suma es: " << resultado << std::endl;
    
    return 0;
}