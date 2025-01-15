#include <iostream>
using namespace std;

// Función recursiva para dividir dos números
void dividir(int dividendo, int divisor, int &cociente, int &residuo) {
    if (dividendo < divisor) {
        cociente = 0;
        residuo = dividendo;
    } else {
        dividir(dividendo - divisor, divisor, ++cociente, residuo);
    }
}

int main() {
    int dividendo, divisor, cociente = 0, residuo = 0;
    cout << "Introduce el dividendo: ";
    cin >> dividendo;
    cout << "Introduce el divisor: ";
    cin >> divisor;

    if (divisor == 0) {
        cout << "Error: División por cero no es permitida." << endl;
        return 1;
    }

    dividir(dividendo, divisor, cociente, residuo);

    cout << "El cociente de " << dividendo << " dividido por " << divisor << " es: " << cociente << endl;
    cout << "El residuo es: " << residuo << endl;

    return 0;
}