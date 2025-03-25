#include <iostream>

using namespace std;
int ordenarKM(int v[], int n){
    int mejora=1;
    bool cambio = true;
    int aux, contador= 0;
    for(int i=0;i<n  && cambio;i++){
        cambio = false;
        for(int j=0;j<n-mejora;j++){
            contador++;
            if( v[j]<v[j+1]){
                aux = v[j];
                v[j]=v[j+1];
                v[j+1]=aux;
                cambio = true;
            }
        }
        mejora++;
    }
    return contador;
}
int main() {
    int n=3;

    // Nombres conductores
    string nombres[3] = {"Freddy", "Luis", "Jaren"};
    
    //Tabla de totales
    int kmRecorridos[3][5] = {
        {2, 8, 18, 6, 10}, // Freddy
        {5, 6, 5, 22, 8},  // Luis
        {7, 30, 8, 10, 7} // Jaren
    };
    
    // Almacena totales
    int totalKM[3] = {0, 0, 0};
    
    // Total km
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            totalKM[i] += kmRecorridos[i][j];
        }
    }
    ordenarKM(totalKM, n);
    // Mostrar resultados
   
    cout << "Nombres y kilometros totales recorridos:\n";
    for (int i = 0; i < 3; i++) {
        cout << nombres[i] << ": " << totalKM[i] << " km ";
        for (int j = 0; j < totalKM[i]; j++) {
            cout << "x";
        }
        cout << endl;
    }
    return 0;
}