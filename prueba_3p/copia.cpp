#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
#include <iomanip>  

using namespace std;


void ingresarConductores(vector<string> &conductores, int numConductores) {
 
    conductores.resize(numConductores);

    for (int i = 0; i < numConductores; i++) {
        cout << "Ingrese el nombre del conductor " << i + 1 << ": ";
        cin >> conductores[i]; 
    }
}


void generarKilometros(vector<vector<int>> &kilometros, int numConductores, int diasSemana) {
    srand(time(0)); 
    for (int i = 0; i < numConductores; i++) {
        vector<int> kmPorSemana;
        for (int j = 0; j < diasSemana; j++) {
            kmPorSemana.push_back(rand() % 101 + 50); 
        }
        kilometros.push_back(kmPorSemana); 
    }
}


vector<int> calcularTotalKm(const vector<vector<int>> &kilometros) {
    vector<int> totalKm;
    for (const auto &fila : kilometros) {
        int suma = 0;
        for (int km : fila) {
            suma += km;
        }
        totalKm.push_back(suma);
    }
    return totalKm;
}


int encontrarMayorKm(const vector<int> &totalKm) {
    int maxKm = totalKm[0];
    int indice = 0;
    for (size_t i = 1; i < totalKm.size(); i++) {
        if (totalKm[i] > maxKm) {
            maxKm = totalKm[i];
            indice = i;
        }
    }
    return indice;
}


void mostrarResultados(const vector<string> &conductores, const vector<vector<int>> &kilometros, const vector<int> &totalKm, int indiceMax) {
    cout << "\nListado de conductores y kilometros recorridos:\n";
    cout << setw(12) << "Conductor" << " | Lunes | Martes | Miérc | Jueves | Viernes | Sáb | Dom | Total\n";
    cout << string(80, '-') << endl;

    for (size_t i = 0; i < conductores.size(); i++) {
        cout << setw(10) << conductores[i] << " | ";
        for (int km : kilometros[i]) {
            cout << setw(4) << km << " | ";
        }
        cout << setw(5) << totalKm[i] << " km\n";
    }

    cout << "\n El conductor con mas kilómetros recorridos es: " << conductores[indiceMax] << " con " << totalKm[indiceMax] << " km.\n";
}


void mostrarGrafico(const vector<string> &conductores, const vector<int> &totalKm) {
    cout << "\nRepresentacion grafica del kilometraje total por conductor:\n";
    for (size_t i = 0; i < conductores.size(); i++) {
        cout << setw(10) << conductores[i] << " | ";
        int numAsteriscos = totalKm[i] / 10; 
        for (int j = 0; j < numAsteriscos; j++) {
            cout << "*";
        }
        cout << " (" << totalKm[i] << " km)\n";
    }
}

int main() {
    int numConductores;
    const int DIAS_SEMANA = 7;

    cout << "Ingrese el numero de conductores: ";
    cin >> numConductores;

    vector<string> conductores; 
    vector<vector<int>> kilometros; 

   
    ingresarConductores(conductores, numConductores);
    generarKilometros(kilometros, numConductores, DIAS_SEMANA);

    
    vector<int> totalKm = calcularTotalKm(kilometros);

   
    int indiceMax = encontrarMayorKm(totalKm);

    
    mostrarResultados(conductores, kilometros, totalKm, indiceMax);

    mostrarGrafico(conductores, totalKm);

    return 0;
}
