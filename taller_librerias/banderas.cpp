#include <iostream>
using namespace std;
main()
{
    bool bandera = true;
    bandera = !bandera;
    if(!bandera){
        cout<<"Esto es falso";
    }
    else{
        cout<<"Esto es verdadero";
    }
}