#include <iostream>
#include <stdio.h>
using namespace std;
main()
{
    int num, r,div;
    cout << "Ingrese un numero:";
    cin >> num;
    cout << "ingresa numero divisor:";
    cin >> div;
    r = num % div;
    if (r == 0){
        cout << "El numero "<< num << " es divisible por " << div << endl;  
        printf("El numero %d es divisible por %d\n", num, div);
    }
    num = 0;
}
