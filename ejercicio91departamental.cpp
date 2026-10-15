#include <iostream>
#include <algorithm> 

using namespace std;

int main() {
    const int tamanio = 5;//definimos el tamaño
    double numeros[tamanio];//le asiganmos una dimension que contiene los 5
    double suma = 0;
    double promedio, media, maximo, minimo;

    //  Ingresar los 5 números en el arreglo
    cout << "promedio  con arreglo de 5 NUMEROS" << endl;
    for (int i = 0; i < tamanio; i++) {//este bucle aumenta i hasta que sea tamanio
        cout << "Ingrese el numero " << (i + 1) << ": ";
        cin >> numeros[i];
        suma += numeros[i]; // de los valores que ingresa se hace la suma y lo guardamos en suma
    }

    // Calcula el promedio
    promedio = suma / tamanio;

    // Determinar el Máximo y el Mínimo
    maximo = numeros[0];
    minimo = numeros[0];
    for (int i = 1; i < tamanio; i++) {
        if (numeros[i] > maximo) {//se compara para ver si es maximo
            maximo = numeros[i];
        }
        if (numeros[i] < minimo) {//se compara para ver si es minimo
            minimo = numeros[i];
        }
    }

    // Calcular la Media
    double copia[tamanio];//este nos sirve para poder alterar y ordenar
    for (int i = 0; i < tamanio; i++) {// hasta que i alcance a tamanio
        copia[i] = numeros[i];// a copia se le asigna el valor de numeros
    }
    sort(copia, copia + tamanio);//la funcion sort ordena la lista

    media = copia[2];//se busca el valor medio osea el indice 0


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
