#include <iostream>

using namespace std;

class QuickSortIndirecto {
private:
    int particion(int arr[], int indices[], int bajo, int alto) {
        int pivote = arr[indices[alto]];
        int i = bajo - 1;

        for (int j = bajo; j < alto; j++) {
            if (arr[indices[j]] <= pivote) {
                i++;
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }
        int temp = indices[i + 1];
        indices[i + 1] = indices[alto];
        indices[alto] = temp;
        return i + 1;
    }

public:
    void quicksort(int arr[], int indices[], int bajo, int alto) {
        if (bajo < alto) {
            int pi = particion(arr, indices, bajo, alto);
            quicksort(arr, indices, bajo, pi - 1);
            quicksort(arr, indices, pi + 1, alto);
        }
    }

    void mostrarOrdenado(int arr[], int indices[], int n) {
        for (int i = 0; i < n; i++) {
            cout << arr[indices[i]] << " ";
        }
        cout << endl;
    }
};

int main() {
    QuickSortIndirecto qs;
    int n, arr[50], indices[50];

    cout << "Cuantos elementos ingresaras? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Valor [" << i << "]: ";
        cin >> arr[i];
        indices[i] = i;
    }

    qs.quicksort(arr, indices, 0, n - 1);

    cout << "\nElementos ordenados por QuickSort indirecto: ";
    qs.mostrarOrdenado(arr, indices, n);

    return 0;
}