#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
void llenaVector(int v[],int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){
       //v[i]=rand()%20+1;
        cin>>v[i];
    }
}
int ordenaBurbujav1(int v[],int n){
    
    int aux,contador=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            contador++;
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }           
        }
         
    }
    return contador;
}
int ordenaBurbujav2(int v[],int n){
    int mejora=1;
    int aux,contador=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n-mejora;j++){
            contador++;
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
            }           
        }
         mejora++;
    }
    return contador;
}
int ordenaBurbujav3(int v[],int n){
    int mejora=1;
    bool cambio=true;
    int aux,contador=0;
    for(int i=0;i<n && cambio;i++){
        cambio=false;
        for(int j=0;j<n-mejora;j++){
            contador++;
            if(v[j]>v[j+1]){
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }           
        }
         mejora++;
    }
    return contador;
}
void muestraVector(int v[],int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
main(){
    int ne;
    cout<<"Numero de elementos: ";
    cin>>ne;
    int vec[ne];
    llenaVector(vec,ne);
    cout<<"Vector original: ";
    muestraVector(vec,ne);
    cout<<endl;
    cout<<"El nro de comparaciones burbuja v1 = "<<ordenaBurbujav1(vec,ne);
    cout<<"El nro de comparaciones burbuja v2 = "<<ordenaBurbujav2(vec,ne);
    cout<<"El nro de comparaciones burbuja v3 = "<<ordenaBurbujav3(vec,ne);
    cout<<"\nVector ordenado: "<<endl;
    muestraVector(vec,ne);
}
