#include <iostream>
using namespace std;
int potenciar(int base, int exponente)
{
    if (exponente == 0)
        return 1;
    else
        return base * potenciar(base, exponente - 1);
}
int multiplicacionr(int a, int b)
{
    if (b == 0)
        return 0;
    else
        return a + multiplicacionr(a, b - 1);
}
main()
{
    int n1,n2;
    cout << "Introduce un numero entero: ";
    cin >> n1;
    cout << "Introduce otro numero entero: ";
    cin >> n2;
    cout << "La potencia de " << n1 << " elevado a " << n2 << " es: " << potenciar(n1, n2) << endl;
    cout << "La multiplicacion de " << n1 << " por " << n2 << " es: " << multiplicacionr(n1, n2) << endl;
}