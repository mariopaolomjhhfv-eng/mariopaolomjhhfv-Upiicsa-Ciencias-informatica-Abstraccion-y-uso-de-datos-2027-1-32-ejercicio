#include <iostream>

using namespace std;

class MiObjeto {
    long codigo;
    double precio;
};

int main() {
    cout << "Tamano de long: " << sizeof(long) << " bytes" << endl;
    cout << "Tamano de MiObjeto: " << sizeof(MiObjeto) << " bytes" << endl;
    return 0;
}
