#include <iostream>
#include <string>

using namespace std;

struct Individuo {
    string alias;
};

int main() {
    Individuo grupo[] = {{"Carlos"}, {"Sofia"}};
    const int total = sizeof(grupo) / sizeof(grupo[0]);

    Individuo *actual = grupo;
    Individuo *fin = grupo + total;

    cout << "Recorrido con puntero:" << endl;
    while (actual != fin) {
        cout << (*actual).alias << "\n";
        actual++;
    }

    return 0;
}