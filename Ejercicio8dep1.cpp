#include <iostream>

using namespace std;

class AnalizadorDatos {
private:
    int v1, v2, v3, v4, v5;

public:
    void asignarValores(int num1, int num2, int num3, int num4, int num5) {
        v1 = num1;
        v2 = num2;
        v3 = num3;
        v4 = num4;
        v5 = num5;
    }

    int obtenerSuma() {
        return v1 + v2 + v3 + v4 + v5;
    }

    double obtenerPromedio() {
        return obtenerSuma() / 5.0;
    }

    int obtenerMaximo() {
        int mayor = v1;
        if (v2 > mayor) mayor = v2;
        if (v3 > mayor) mayor = v3;
        if (v4 > mayor) mayor = v4;
        if (v5 > mayor) mayor = v5;
        return mayor;
    }

    int obtenerMinimo() {
        int menor = v1;
        if (v2 < menor) menor = v2;
        if (v3 < menor) menor = v3;
        if (v4 < menor) menor = v4;
        if (v5 < menor) menor = v5;
        return menor;
    }

    void mostrarResultados() {
        cout << "--- Resultados Estadisticos ---" << endl;
        cout << "Suma total: " << obtenerSuma() << endl;
        cout << "Promedio / Media: " << obtenerPromedio() << endl;
        cout << "Valor Maximo: " << obtenerMaximo() << endl;
        cout << "Valor Minimo: " << obtenerMinimo() << endl;
    }
};

int main() {
    AnalizadorDatos analisis;

    analisis.asignarValores(12, 45, 8, 29, 36);

    analisis.mostrarResultados();

    return 0;
}