#include <iostream>
using namespace std;
main()
{
    int op;
    cout<<"Ingrese un numero: "; cin>>op;
    switch(op)
    {
        case 1: cout<<"uno"; break;
        case 2: cout<<"dos"; break;
        case 3: cout<<"tres"; break;
        case 4: cout<<"cuatro"; break;
        case 5: cout<<"cinco"; break;
        default: cout<<"no es un numero valido"; break;
    }
}