#include <iostream>
#include <vector>
#include <string>
#include <limits>

using namespace std;

struct Estudiante {
    string nombre;
    int    edad;
    double promedio;
};

template <typename T>
bool menorQue(const T& a, const T& b) {
    return a < b;
}

bool porNombre(const Estudiante& a, const Estudiante& b) {
    return a.nombre < b.nombre;
}

bool porEdad(const Estudiante& a, const Estudiante& b) {
    return a.edad < b.edad;
}

bool porPromedio(const Estudiante& a, const Estudiante& b) {
    return a.promedio > b.promedio;
}

template <typename T>
void mezclar(vector<T>& datos, int izq, int medio, int der,
             bool (*comparar)(const T&, const T&)) {
    vector<T> izquierda(datos.begin() + izq, datos.begin() + medio + 1);
    vector<T> derecha(datos.begin() + medio + 1, datos.begin() + der + 1);

    size_t i = 0, j = 0;
    int k = izq;

    while (i < izquierda.size() && j < derecha.size()) {
        if (!comparar(derecha[j], izquierda[i]))
            datos[k++] = izquierda[i++];
        else
            datos[k++] = derecha[j++];
    }
    while (i < izquierda.size()) datos[k++] = izquierda[i++];
    while (j < derecha.size())   datos[k++] = derecha[j++];
}

template <typename T>
void mergeSort(vector<T>& datos, int izq, int der,
               bool (*comparar)(const T&, const T&)) {
    if (izq >= der) return;
    int medio = izq + (der - izq) / 2;
    mergeSort(datos, izq, medio, comparar);
    mergeSort(datos, medio + 1, der, comparar);
    mezclar(datos, izq, medio, der, comparar);
}

template <typename T>
T leerValor(const string& mensaje) {
    T valor;
    while (true) {
        cout << mensaje;
        if (cin >> valor) return valor;
        cout << "Entrada no válida, intente de nuevo.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

int leerCantidad() {
    int n;
    do {
        n = leerValor<int>("Cantidad de elementos: ");
        if (n <= 0) cout << "Debe ser mayor que cero.\n";
    } while (n <= 0);
    return n;
}

string leerTexto(const string& mensaje) {
    string s;
    while (true) {
        cout << mensaje;
        cin >> ws;
        getline(cin, s);
        if (!s.empty()) return s;
    }
}

Estudiante leerEstudiante(int numero) {
    Estudiante e;
    cout << "\nEstudiante " << numero << "\n";
    e.nombre   = leerTexto("Nombre: ");
    e.edad     = leerValor<int>("Edad: ");
    e.promedio = leerValor<double>("Promedio: ");
    return e;
}

void mostrarEstudiante(const Estudiante& e) {
    cout << "  [" << e.nombre << ", " << e.edad << " años, prom: "
         << e.promedio << "]\n";
}

template <typename T>
void mostrarLista(const string& titulo, const vector<T>& datos) {
    cout << "\n" << titulo << ": ";
    for (const T& x : datos) cout << x << "  ";
    cout << "\n";
}

void ordenarEnteros() {
    int n = leerCantidad();
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(leerValor<int>("Entero " + to_string(i + 1) + ": "));

    mergeSort<int>(v, 0, n - 1, menorQue<int>);
    mostrarLista("Enteros ordenados", v);
}

void ordenarCaracteres() {
    int n = leerCantidad();
    vector<char> v;
    for (int i = 0; i < n; i++)
        v.push_back(leerValor<char>("Carácter " + to_string(i + 1) + ": "));

    mergeSort<char>(v, 0, n - 1, menorQue<char>);
    mostrarLista("Caracteres ordenados", v);
}

void ordenarEstudiantes() {
    int n = leerCantidad();
    vector<Estudiante> v;
    for (int i = 0; i < n; i++)
        v.push_back(leerEstudiante(i + 1));

    int opcion;
    do {
        opcion = leerValor<int>(
            "\nOrdenar por:\n1. Nombre\n2. Edad\n3. Promedio (mayor a menor)\nOpción: ");
    } while (opcion < 1 || opcion > 3);

    if (opcion == 1)
        mergeSort<Estudiante>(v, 0, n - 1, porNombre);
    else if (opcion == 2)
        mergeSort<Estudiante>(v, 0, n - 1, porEdad);
    else
        mergeSort<Estudiante>(v, 0, n - 1, porPromedio);

    cout << "\nEstudiantes ordenados:\n";
    for (const Estudiante& e : v) mostrarEstudiante(e);
}

int main() {
    int opcion;
    do {
        cout << "\nMerge Sort\n"
             << "1. Ordenar enteros\n"
             << "2. Ordenar caracteres\n"
             << "3. Ordenar estudiantes\n"
             << "0. Salir\n";
        opcion = leerValor<int>("Opción: ");

        switch (opcion) {
            case 1: ordenarEnteros();     break;
            case 2: ordenarCaracteres();  break;
            case 3: ordenarEstudiantes(); break;
            case 0: cout << "Hasta luego.\n"; break;
            default: cout << "Opción no válida.\n";
        }
    } while (opcion != 0);

    return 0;
}