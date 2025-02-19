#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;


void llenar(int v[],int n,int rangoini=0,int rangofin=100){
    int i;
    srand(time(NULL));
    for(i=0;i<n;i++){
        v[i]=rand()%(rangofin-rangoini+1)+rangoini;
        std::cout<< v[i]<<" ";
    }
}

void muestravector(int v[],int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout << endl;
}

int ordenaburbujav3(int v[],int n){
    int mejora=1;
    bool cambio=true;
    int aux,cont=0;
    for(int i=0;i<n && cambio;i++){
        cambio=false;
        for(int j=0;j<n-mejora;j++){
            cont++;
            if(v[j]>v[j+1])
            {
                aux=v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio=true;
            }
        }
        mejora++;
    }
    return cont;
}

void juego(int rangoini=0,int rangofin=100,int numintentos=4){
    int vector[1];
    int intentos;

    
    llenar(vector, 1, rangoini, rangofin); 

    cout<<"Que numero estoy pensando entre " << rangoini << " y " << rangofin <<endl ;
    for(int i=0; i<numintentos;i++){
        cout<<"Este es tu intento numero: " << i << "/" << numintentos << ": ";
        cin>>intentos;
        if (intentos < vector[0]) {
            cout << "El numero que estoy pensando es un numero mayor.\n";
        } else if (intentos > vector[0]) {
            cout << "El numero que estoy pensando es un numero menor.\n";
        } else {
            cout << "Felicidades, Has adivinado el numero en " << i << " intentos.\n";
            return;  
        }
    }

  
    cout << "Lo siento, has agotado tus " << numintentos << " intentos. El numero era " << vector[0] << ".\n";
}


    



