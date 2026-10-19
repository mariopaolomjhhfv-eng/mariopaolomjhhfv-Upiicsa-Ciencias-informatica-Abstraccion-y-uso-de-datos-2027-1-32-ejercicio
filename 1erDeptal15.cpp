#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

class Fractal {
private:
    void generarCantor(string &s, int inicio, int fin)
    {
        int longitud = fin - inicio + 1;
        if (longitud < 3) return; 

        int tercio = longitud / 3;
        int inicio_medio = inicio + tercio;
        int fin_medio = inicio + 2 * tercio - 1;

        for (int i = inicio_medio; i <= fin_medio; i++) {
            s[i] = ' ';
        }

        generarCantor(s, inicio, inicio_medio - 1);
        generarCantor(s, fin_medio + 1, fin);
    }

    void sierpinski(vector<string>& matriz, int n, int x, int y) {
        if (n == 1) {
            matriz[x][y] = '*'; 
            return;
        }

        int tam = pow(2, n - 1);

        sierpinski(matriz, n - 1, x, y);                    
        sierpinski(matriz, n - 1, x + tam, y - tam);        
        sierpinski(matriz, n - 1, x + tam, y + tam);        
    }

public:
    void ejecutarCantor() {
        int n;
        cout << "\npolvo" << endl;
        cout << "Ingresa el nivel de profundidad: ";
        cin >> n;

        int tam = pow(3, n);
        string linea(tam, '-'); 

        generarCantor(linea, 0, tam - 1);

        cout << "\nResultado:\n";
        for (int i = 0; i < n + 1; i++) {
            cout << linea << endl;
        }
    }

    void ejecutarSierpinski() {
        int n;
        cout << "\ntriangulo" << endl;
        cout << "Ingrese el nivel de profundidad ";
        cin >> n;

        int altura = pow(2, n);
        int ancho = 2 * altura;

        vector<string> matriz(altura, string(ancho, ' '));

        sierpinski(matriz, n, 0, altura);

        cout << "\nResultado:\n";
        for (int i = 0; i < altura; i++) {
            cout << matriz[i] << endl;
        }
    }
};

int main() {
    Fractal objFractal;
    int opcion;

    do {

        cout << " fractales" << endl;
        cout << "1 Polvo de Cantor" << endl;
        cout << "2 Triangulo de Sierpinski" << endl;
        cout << "3 Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                objFractal.ejecutarCantor();
                break;
            case 2:
                objFractal.ejecutarSierpinski();
                break;
            case 3:
                cout << "\nSaliendo del programa" << endl;
                break;
            default:
                cout << "\nOpcion no valida. Intente de nuevo." << endl;
        }

        if(opcion != 3) {
            cout << "\nPresiona espacio para continuar";
            cin.ignore();
            cin.get();
        }

    } while(opcion != 3);

    return 0;
}
