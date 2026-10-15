#include <iostream>
#include <string>
#include <vector>//esta libreria nos ayuda a poder operar vectores o arreglos o amatrices de manera dinamica y agrega funciones para poder modificar
#include <cmath>//esta nos agrega mas funciones matematicas

using namespace std;

// para hacer el polvo de cantor
void generarCantor(string &s, int inicio, int fin)//declaramos valorees de inicia y fin
{
    int longitud = fin - inicio + 1;//usamos esto para el tamaño o longitud
    if (longitud < 3) return; // Caso base

    int tercio = longitud / 3;//dividiendo el segmento
    int inicio_medio = inicio + tercio;
    int fin_medio = inicio + 2 * tercio - 1;

    // Rellenar el tercio central con espacios
    for (int i = inicio_medio; i <= fin_medio; i++) {
        s[i] = ' ';
    }

    // Llamadas recursivas para los tercios izquierdo y derecho
    generarCantor(s, inicio, inicio_medio - 1);//
    generarCantor(s, fin_medio + 1, fin);
}

void ejecutarCantor() {
    int n;
    cout << "\npolvo" << endl;
    cout << "Ingresa el nivel de profundidad: ";
    cin >> n;

    int tam = pow(3, n);//declarado como tam nos ayudara a simular la linea usamos guiones
    string linea(tam, '-'); // <-- Corrección: Se agregó el punto y coma faltante

    generarCantor(linea, 0, tam - 1);

    cout << "\nResultado:\n";
    for (int i = 0; i < n + 1; i++) {
        cout << linea << endl;
    }
}


void sierpinski(vector<string>& matriz, int n, int x, int y) {
    if (n == 1) {
        matriz[x][y] = '*'; // Caso base: dibuja un punto/asterisco
        return;
    }

    int tam = pow(2, n - 1);

    // Llamadas recursivas para los 3 subtriángulos
    sierpinski(matriz, n - 1, x, y);                   // Triángulo superior
    sierpinski(matriz, n - 1, x + tam, y - tam);       // Triángulo inferior izquierdo
    sierpinski(matriz, n - 1, x + tam, y + tam);       // Triángulo inferior derecho
}

void ejecutarSierpinski() {
    int n;
    cout << "\ntriangulo" << endl;
    cout << "Ingrese el nivel de profundidad ";
    cin >> n;

    int altura = pow(2, n);
    int ancho = 2 * altura;

    // Creamos una matriz de espacios en blanco
    vector<string> matriz(altura, string(ancho, ' '));

    sierpinski(matriz, n, 0, altura);

    cout << "\nResultado:\n";
    for (int i = 0; i < altura; i++) {
        cout << matriz[i] << endl;
    }
}


int main() {
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
                ejecutarCantor();
                break;
            case 2:
                ejecutarSierpinski();
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
