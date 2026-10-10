#include <iostream>
#include <iomanip>
using namespace std;

const int N = 5;

int main() {
    float numeros[N];        
    float *p = numeros;      
    float cp[N];
    float sum = 0, prom, med, max, min, aux;

   
    //Ingresar datos de forma indirecta (puntero)
    for (int i = 0; i < N; i++) {
        cout << "Ingrese un número: " << i + 1 << ": ";
        cin >> *(p + i);             
    }

    
    max = *p;
    min = *p;
    for (int i = 0; i < N; i++) {
        sum += *(p + i);
        if (*(p + i) > max) max = *(p + i);
        if (*(p + i) < min) min = *(p + i);
    }

    prom = sum / N;

    for (int i = 0; i < N; i++) cp[i] = *(p + i);
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - 1 - i; j++) {
            if (cp[j] > cp[j + 1]) {
                aux = cp[j];
                cp[j] = cp[j + 1];
                cp[j + 1] = aux;
            }
        }
    }
    med = cp[N / 2];

    cout << fixed << setprecision(2); //notación normal con 2 decimales
    cout << "Resultados:";
    cout << "\nSuma     : " << sum;
    cout << "\nPromedio : " << prom;
    cout << "\nMediana  : " << med;
    cout << "\nMaximo   : " << max;
    cout << "\nMinimo   : " << min << endl;

    return 0;
}