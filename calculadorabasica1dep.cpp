#include <iostream>

using namespace std;

float a = 0;
float b = 0;


void Suma();
void Resta();
void Multiplicacion();
void Division();

int main()
{
    int opcion;

    for (;;) {
        cout << "\n--- CALCULADORA BASICA ---" << endl;
        cout << "1. Suma\n";
        cout << "2. Resta\n";
        cout << "3. Multiplicacion\n";
        cout << "4. Division\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                Suma();
                break;
            case 2:
                Resta();
                break;
            case 3:
                Multiplicacion();
                break;
            case 4:
                Division();
                break;
            case 5:
                cout << "Saliendo de la calculadora..." << endl;
                return 0;
            default:
                cout << "Opcion no valida. Intenta de nuevo.\n" << endl;
                break;
        }
    }

    return 0;
}


void Suma()
{
    float suma = 0;
    cout << "\n Suma basica " << endl;
    cout << "ingresa el primer numero: ";
    cin >> a;
    cout << "ingresa el segundo numero: ";
    cin >> b;
    suma = a + b;
    cout << "El resultado es: " << suma << endl;
}

void Resta()
{
    float resta = 0;
    cout << "\n Resta basica " << endl;
    cout << "ingresa el minuendo: ";
    cin >> a;
    cout << "ingresa el sutraendo: ";
    cin >> b;
    resta = a - b;
    cout << "El resultado es: " << resta << endl;
}

void Multiplicacion()
{
    float multiplicacion = 0;
    cout << "\n Multiplicacion basica " << endl;
    cout << "ingresa el valor a multiplicar: ";
    cin >> a;
    cout << "ingresa el valor a multiplicar: ";
    cin >> b;
    multiplicacion = a * b;
    cout << "El resultado es: " << multiplicacion << endl;
}

void Division()
{
    float division = 0;
    cout << "\n Division basica " << endl;
    cout << "ingresa el dividendo: ";
    cin >> a;
    cout << "ingresa el divisor: ";
    cin >> b;

    if (b != 0) {
        division = a / b;
        cout << "El resultado es: " << division << endl;
    } else {
        cout << "Error: No se puede dividir entre cero." << endl;
    }
}
