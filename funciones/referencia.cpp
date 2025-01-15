#include <iostream>
using namespace std;
void operaciones(float num1, float num2, float &suma, float &resta, float &multiplicacion, float &division, int &resultado){
   suma = num1 + num2;
   resta = num1 - num2;
   multiplicacion = num1 * num2;
   division = num1 / num2;
   resultado = (int)num1 % (int)num2;
   }
main()
{
    float a, b, suma, resta, multiplicacion, division;
    int residuo;
    cout << "Ingrese el primer número: ";
    cin >> a;
    cout << "Ingrese el segundo número: ";
    cin >> b;
    operaciones(a, b, suma, resta, multiplicacion, division, residuo);
    cout << "La suma de los números es: " << suma << endl;
    cout << "La resta de los números es: " << resta << endl;
    cout << "La multiplicación de los números es: " << multiplicacion << endl;
    cout << "La división de los números es: " << division << endl;
    cout << "El residuo de la división de los números es: " << residuo << endl;
}