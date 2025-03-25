#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Conductor {
    string nombre;
    int kms[7];
    int totalKms;
};
bool comparar(Conductor a, Conductor b) {
    return a.totalKms > b.totalKms; 
}
int generarKmAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}
int main() {
    srand(time(0));
    int numConductores;
    cout << "Ingrese el numero de conductores: ";
    cin >> numConductores;
    vector<Conductor> conductores(numConductores);
    int kmMin = 50;
    int kmMax = 200;
    for (int i = 0; i < numConductores; i++) {
        cout << "Ingrese el nombre del conductor " << i + 1 << ": ";
        cin >> conductores[i].nombre;
        conductores[i].totalKms = 0; 
        for (int j = 0; j < 7; j++) {
            conductores[i].kms[j] = generarKmAleatorio(kmMin, kmMax);
            conductores[i].totalKms += conductores[i].kms[j]; 
        }
    }
    sort(conductores.begin(), conductores.end(), comparar);

    cout << "\nLista de conductores y sus kilometros recorridos:\n";
    for (int i = 0; i < numConductores; i++) {
        cout << conductores[i].nombre << ": ";
        for (int j = 0; j < 7; j++) {
            cout << conductores[i].kms[j] << " ";
        }
        cout << "Total: " << conductores[i].totalKms << " km\n";
    }
    cout << "\nEl conductor con mas kilmetros recorridos es: " << conductores[0].nombre
         << " con " << conductores[0].totalKms << " km.\n";
    cout << "\nGrafico de kilometros recorridos (escala 1 # por cada 20 km):\n";
    for (int i = 0; i < numConductores; i++) {
        int barras = conductores[i].totalKms / 20;  
        cout << conductores[i].nombre << ": ";
        for (int j = 0; j < barras; j++) {
            cout << "#";
        }
        cout << " (" << conductores[i].totalKms << " km)\n";
    }

    return 0;
}
