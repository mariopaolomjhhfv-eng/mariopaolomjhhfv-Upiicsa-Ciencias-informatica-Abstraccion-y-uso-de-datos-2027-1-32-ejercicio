#include <stdio.h>
#include <string.h>

typedef struct {
    char  nombre[30];
    int   matricula;
    float promedio;     
} Alumno;

void intercambiarInt(int *a, int *b) {
    int t = *a; *a = *b; *b = t;
}

int particionInt(int arr[], int bajo, int alto) {
    int pivote = arr[alto];
    int i = bajo - 1;
    for (int j = bajo; j < alto; j++) {
        if (arr[j] <= pivote) {
            i++;
            intercambiarInt(&arr[i], &arr[j]);
        }
    }
    intercambiarInt(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quickSortInt(int arr[], int bajo, int alto) {
    if (bajo < alto) {
        int p = particionInt(arr, bajo, alto);
        quickSortInt(arr, bajo, p - 1);
        quickSortInt(arr, p + 1, alto);
    }
}

void intercambiarChar(char *a, char *b) {
    char t = *a; *a = *b; *b = t;
}

int particionChar(char arr[], int bajo, int alto) {
    char pivote = arr[alto];
    int i = bajo - 1;
    for (int j = bajo; j < alto; j++) {
        if (arr[j] <= pivote) {
            i++;
            intercambiarChar(&arr[i], &arr[j]);
        }
    }
    intercambiarChar(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quickSortChar(char arr[], int bajo, int alto) {
    if (bajo < alto) {
        int p = particionChar(arr, bajo, alto);
        quickSortChar(arr, bajo, p - 1);
        quickSortChar(arr, p + 1, alto);
    }
}

void intercambiarAlumno(Alumno *a, Alumno *b) {
    Alumno t = *a; *a = *b; *b = t;
}

int particionAlumno(Alumno arr[], int bajo, int alto) {
    float pivote = arr[alto].promedio;
    int i = bajo - 1;
    for (int j = bajo; j < alto; j++) {
        if (arr[j].promedio <= pivote) {
            i++;
            intercambiarAlumno(&arr[i], &arr[j]);
        }
    }
    intercambiarAlumno(&arr[i + 1], &arr[alto]);
    return i + 1;
}

void quickSortAlumno(Alumno arr[], int bajo, int alto) {
    if (bajo < alto) {
        int p = particionAlumno(arr, bajo, alto);
        quickSortAlumno(arr, bajo, p - 1);
        quickSortAlumno(arr, p + 1, alto);
    }
}

void imprimirInts(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void imprimirChars(char arr[], int n) {
    for (int i = 0; i < n; i++) printf("%c ", arr[i]);
    printf("\n");
}

void imprimirAlumnos(Alumno arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("  %-10s | %d | %.1f\n", arr[i].nombre, arr[i].matricula, arr[i].promedio);
}

int main(void) {
    int   nums[]  = {34, 7, 23, 32, 5, 62, 32, 1};
    char  cars[]  = {'m', 'z', 'a', 'k', 'b', 'x'};
    Alumno alu[]  = {
        {"Lisette",   1001, 9.2f},
        {"Paolo",  1002, 7.5f},
        {"Julieta", 1003, 8.8f},
        {"Jorge", 1004, 6.9f}
    };
    int nN = sizeof(nums) / sizeof(nums[0]);
    int nC = sizeof(cars) / sizeof(cars[0]);
    int nA = sizeof(alu)  / sizeof(alu[0]);

    printf("Enteros antes:    "); imprimirInts(nums, nN);
    quickSortInt(nums, 0, nN - 1);
    printf("Enteros despues:  "); imprimirInts(nums, nN);

    printf("\nChars antes:      "); imprimirChars(cars, nC);
    quickSortChar(cars, 0, nC - 1);
    printf("Chars despues:    "); imprimirChars(cars, nC);

    printf("\nAlumnos antes:\n");   imprimirAlumnos(alu, nA);
    quickSortAlumno(alu, 0, nA - 1);
    printf("Alumnos despues (por promedio):\n"); imprimirAlumnos(alu, nA);

    return 0;
}