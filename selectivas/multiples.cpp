#include <iostream>
using namespace std;
main()
{
    int dia;
    cout<<"Ingrese dia de la semana: ";
    cin>>dia;
    switch (dia)
    {
        case 1:
                cout<<"Es lunes"<<endl;
                break;
        case 2: 
                cout <<"Es Martes"<<endl;
                break;
        case 3:
                cout <<"Es Miercoles"<<endl;
                break;
        case 4:
                cout <<"Es Jueves"<<endl;
                break;
        case 5: 
                cout <<"Es Viernes"<<endl;
                break;
        case 6:
                cout<<"Es sabado"<<endl;
        case 7:
                cout <<"Es fin de semana"<<endl;
                break;
        default:
                cout<<"Dia no valido"<<endl;    

    }
    
}