#include <iostream>
using namespace std;
float suma(float a, float b) {
    return a + b;
}   
float resta(float a, float b) {
    return a - b;
}
float multiplicacion(float a, float b) {
    return a * b;
}
float division(float a, float b) {
    return a / b;
}
int residuo(int a, int b) {
    return a % b;
}
main()
{
    float a, b;
    cout << "Ingrese el primer número: ";
    cin >> a;
    cout << "Ingrese el segundo número: ";
    cin >> b;
    cout << "La suma de los números es: " << suma(a, b) << endl;
    cout << "La resta de los números es: " << resta(a, b) << endl;
    cout << "La multiplicación de los números es: " << multiplicacion(a, b) << endl;
    cout << "La división de los números es: " << division(a, b) << endl;
    cout << "El residuo de la división de los números es: " << residuo(a, b) << endl;
    return 0;
}