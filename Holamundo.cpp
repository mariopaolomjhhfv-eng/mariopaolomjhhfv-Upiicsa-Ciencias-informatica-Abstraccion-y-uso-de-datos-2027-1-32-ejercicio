#include <iostream>
#include <string>

class Saludo {
private:
    std::string msj;

public:

    Saludo(const std::string& texto) : msj(texto) {}

    void mostrar() const {
        std::cout << msj << std::endl;
    }
};

int main() {
    Saludo saludo("Hola Mundo");
    saludo.mostrar();
    return 0;
}