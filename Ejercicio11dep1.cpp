#include <iostream>

using namespace std;

class CalculadoraMatrices {
private:
    static const int FILAS = 2;
    static const int COLUMNAS = 2;

public:
    void escalar(int matriz[2][2], int factor) {
        cout << "--- Matriz A * Constante (" << factor << ") ---" << endl;
        for (int fila = 0; fila < FILAS; fila++) {
            for (int col = 0; col < COLUMNAS; col++) {
                cout << matriz[fila][col] * factor << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }

    void producto(int matA[2][2], int matB[2][2]) {
        int resultado[2][2] = {0};

        cout << "--- Producto Matricial A * B ---" << endl;
        for (int i = 0; i < FILAS; i++) {
            for (int j = 0; j < COLUMNAS; j++) {
                resultado[i][j] = 0;
                for (int k = 0; k < FILAS; k++) {
                    resultado[i][j] += matA[i][k] * matB[k][j];
                }
                cout << resultado[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    CalculadoraMatrices calcMat;

    int matrizA[2][2] = {
        {2, 3},
        {1, 4}
    };

    int matrizB[2][2] = {
        {3, 1},
        {2, 5}
    };

    int constante = 3;

    calcMat.escalar(matrizA, constante);
    calcMat.producto(matrizA, matrizB);

    return 0;
}