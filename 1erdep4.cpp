#include <iostream>

using namespace std;

class Calculadora {
private:
    float a = 0;
    float b = 0;
    float c = 0;
    int n;

public:
    void Suma()
    {
        cout << "\n cuantos numeros desea sumar solo se aceptan 0,2,3 " << endl;
        cin >> n;
        if (n==0){
            printf("la suma es cero");
        }
        if (n==2){
        float suma = 0;
        cout << "\n Suma basica " << endl;
        cout << "ingresa el primer numero: ";
        cin >> a;
        cout << "ingresa el segundo numero: ";
        cin >> b;
        suma = a + b;
        cout << "El resultado es: " << suma << endl;
        }
        if (n==3){
        cout << "\n Suma basica " << endl;
        cout << "ingresa el primer numero: ";
        cin >> a;
        cout << "ingresa el segundo numero: ";
        cin >> b;
        cout << "ingresa el tercer numero: ";
        cin >> c;
        float suma = a + b + c;
        cout << "El resultado es: " << suma << endl;
        }
    }

    void Resta()
    {
     cout << "\n cuantos numeros desea restar solo se aceptan 0,2,3 " << endl;
        cin >> n;
        if (n==0){
            printf("la resta es cero");
        }
        if (n==2){
        float resta = 0;
        cout << "\n resta basica " << endl;
        cout << "ingresa el minuendo: ";
        cin >> a;
        cout << "ingresa el sustraendo: ";
        cin >> b;
        resta = a - b;
        cout << "El resultado es: " << resta << endl;
        }
        if (n==3){
        cout << "\n resta basica " << endl;
        cout << "use el signo de resta para afectuar la operacion ";
        cout << "ingresa el primer numero: ";
        cin >> a;
        cout << "ingresa el segundo numero: ";
        cin >> b;
        cout << "ingresa el tercer numero: ";
        cin >> c;
        float resta = a + b + c;
        cout << "El resultado es: " << resta << endl;
        }
    }

    void Multiplicacion()
    {
        cout << "\n cuantos numeros desea multiplicar solo se aceptan 0,2,3 " << endl;
        cin >> n;
        if (n==0){
            printf("la multiplicacion es cero");
        }
        if (n==2){
        float multiplicacion = 0;
        cout << "\n Suma basica " << endl;
        cout << "ingresa el primer numero: ";
        cin >> a;
        cout << "ingresa el segundo numero: ";
        cin >> b;
        multiplicacion = a * b;
        cout << "El resultado es: " << multiplicacion << endl;
        }
        if (n==3){
        cout << "\n multiplicacion basica " << endl;
        cout << "ingresa el primer numero: ";
        cin >> a;
        cout << "ingresa el segundo numero: ";
        cin >> b;
        cout << "ingresa el tercer numero: ";
        cin >> c;
        float multiplicacion = a * b * c;
        cout << "El resultado es: " << multiplicacion << endl;
        }
    }

    void Division()
    {
        cout << "\n cuantos numeros desea dividir solo se aceptan 0,2,3 " << endl;
        cin >> n;
        if (n==0){
            printf("la division es cero");
        }
        if (n==2){
        float division = 0;
        cout << "\n Division basica " << endl;
        cout << "ingresa el dividendo: ";
        cin >> a;
        cout << "ingresa el divisor: ";
        cin >> b;
        division = a / b;
        cout << "El resultado es: " << division << endl;
        }
        if (n==3){
        cout << "\n division basica " << endl;
        cout << "ingresa el dividendo: ";
        cin >> a;
        cout << "ingresa el divisor: ";
        cin >> b;
        cout << "ingresa el segundo divisor: ";
        cin >> c;
        float division = (a / b)/ c;
        cout << "El resultado es: " << division << endl;
        }
    }

    void Menu()
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
                    return;
                default:
                    cout << "Intenta de nuevo.\n" << endl;
                    break;
            }
        }
    }
};

int main()
{
    Calculadora calc;
    calc.Menu();

    return 0;
}
