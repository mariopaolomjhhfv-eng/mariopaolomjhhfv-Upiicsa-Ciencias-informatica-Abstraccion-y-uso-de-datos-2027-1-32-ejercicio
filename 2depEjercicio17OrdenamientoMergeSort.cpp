#include <iostream>

using namespace std;

class MergeSort {
private:
    void mezclar(int arr[], int inicio, int medio, int fin) {
        int n1 = medio - inicio + 1;
        int n2 = fin - medio;

        int izq[50], der[50];

        for (int i = 0; i < n1; i++) izq[i] = arr[inicio + i];
        for (int j = 0; j < n2; j++) der[j] = arr[medio + 1 + j];

        int i = 0, j = 0, k = inicio;
        while (i < n1 && j < n2) {
            if (izq[i] <= der[j]) {
                arr[k++] = izq[i++];
            } else {
                arr[k++] = der[j++];
            }
        }

        while (i < n1) arr[k++] = izq[i++];
        while (j < n2) arr[k++] = der[j++];
    }

public:
    void ordenar(int arr[], int inicio, int fin) {
        if (inicio < fin) {
            int medio = inicio + (fin - inicio) / 2;
            ordenar(arr, inicio, medio);
            ordenar(arr, medio + 1, fin);
            mezclar(arr, inicio, medio, fin);
        }
    }

    void mostrar(int arr[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    MergeSort ms;
    int n, arr[50];

    cout << "Cuantos elementos deseas ordenar? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Elemento [" << i << "]: ";
        cin >> arr[i];
    }

    cout << "\nArreglo original: ";
    ms.mostrar(arr, n);

    ms.ordenar(arr, 0, n - 1);

    cout << "Arreglo ordenado por Merge Sort: ";
    ms.mostrar(arr, n);

    return 0;
}