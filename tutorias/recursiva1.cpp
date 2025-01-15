#include <iostream>
using namespace std;
int suma(int x, int y){
    if (y == 0)
        return x;
    else
        return suma(x+1, y - 1);
}
int main(){
    int x, y;
    cout << "Introduce dos números enteros: ";
    cin >> x >> y;
    cout << "La suma de " << x << " y " << y << " es: " << suma(x, y) << endl;
}