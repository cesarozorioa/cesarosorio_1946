#include <iostream>
using namespace std;
// Función recursiva para dividir dos números
int dividir(int a, int b, int &cociente) {
    if (b == 0)
        return -1;
    if (a < b)
        return a;
    else{
        cociente++;
        return dividir(a - b, b, cociente);
    }        
    
}
int main() {
    int dividendo, divisor, cociente=0,residuo = 0;
    cout << "Introduce el dividendo: ";
    cin >> dividendo;
    cout << "Introduce el divisor: ";
    cin >> divisor;
    residuo = dividir(dividendo, divisor, cociente);
    (residuo == -1) ? cout << "Error: División entre cero." << endl : cout << "El cociente es: " << cociente << " y el residuo es: " << residuo << endl;
        
       
}