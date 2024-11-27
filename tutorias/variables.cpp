#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
    int valor, numero;
    int valpi;
    float pi = 3.1416;
    int valpi = (int)pi;
    cout << "El valor de valpi es: " << valpi << endl;
    cout << "Ingrese un valor: ";
    
    cin >> valor;
    if (valor < 0)
    {
        valor = valor * -1;
    }
    valor++;
    ++valor;
    cout << "El valor absoluto es: " << valor << endl;
    return 0;
}
