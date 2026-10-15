#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    const int tamanio = 5;
    double numeros[tamanio];
    double suma = 0;
    double promedio, media, maximo, minimo;

    cout << "promedio  con arreglo de 5 NUMEROS" << endl;
    for (int i = 0; i < tamanio; i++) {
        cout << "Ingrese el numero " << (i + 1) << ": ";
        cin >> numeros[i];
        suma += numeros[i]; 
    }

    promedio = suma / tamanio;

    maximo = numeros[0];
    minimo = numeros[0];
    for (int i = 1; i < tamanio; i++) {
        if (numeros[i] > maximo) {
            maximo = numeros[i];
        }
        if (numeros[i] < minimo) {
            minimo = numeros[i];
        }
    }

    double copia[tamanio];
    for (int i = 0; i < tamanio; i++) {
        copia[i] = numeros[i];
    }
    sort(copia, copia + tamanio);

    media = copia[2];


    cout << "Suma total: " << suma << endl;
    cout << "Promedio (Media aritmetica): " << promedio << endl;
    cout << "Media (Mediana): " << media << endl;
    cout << "Numero Maximo: " << maximo << endl;
    cout << "Numero Minimo: " << minimo << endl;
    cout << "\nPresiona Enter para salir...";
    cin.ignore(); 
    cin.get();    

    return 0;
}
