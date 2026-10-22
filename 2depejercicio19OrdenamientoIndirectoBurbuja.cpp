#include <iostream>

using namespace std;

class BurbujaIndirecta {
public:
    void ordenarIndirecto(int arr[], int indices[], int n) {
        // Inicializar arreglo de indices
        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        // Metodo de burbuja intercambiando unicamente las posiciones
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[indices[j]] > arr[indices[j + 1]]) {
                    int aux = indices[j];
                    indices[j] = indices[j + 1];
                    indices[j + 1] = aux;
                }
            }
        }
    }

    void mostrarArreglo(int arr[], int n) {
        for (int i = 0; i < n; i++) cout << arr[i] << " ";
        cout << endl;
    }

    void mostrarOrdenado(int arr[], int indices[], int n) {
        for (int i = 0; i < n; i++) cout << arr[indices[i]] << " ";
        cout << endl;
    }
};

int main() {
    BurbujaIndirecta burbuja;
    int n, datos[50], indices[50];

    cout << "Numero de elementos: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Dato [" << i << "]: ";
        cin >> datos[i];
    }

    burbuja.ordenarIndirecto(datos, indices, n);

    cout << "\nArreglo original en memoria (intacto): ";
    burbuja.mostrarArreglo(datos, n);

    cout << "Arreglo ordenado mediante indices indirectos: ";
    burbuja.mostrarOrdenado(datos, indices, n);

    return 0;
}