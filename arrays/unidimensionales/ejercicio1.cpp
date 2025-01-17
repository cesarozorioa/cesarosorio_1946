#include <iostream>
using namespace std;
void llenaVector(int v[], int tamano){
    for( int i=0;i<tamano;i++){
        cout<<"Introduce el valor del elemento "<<i+1<<": ";
        cin>>v[i];
    }
}
void verVector(int v[], int tamano){
    for( int i=0;i<tamano;i++){
        cout<<"El elemento "<<i+1<<" del vector es: "<<v[i]<<endl;
    }
}

main()
{
    int ne;
    cout<<"Cuantos elementos tiene el vector?: ";
    cin>>ne;
    int vector[ne];
    llenaVector(vector,ne);
    verVector(vector,ne);
}