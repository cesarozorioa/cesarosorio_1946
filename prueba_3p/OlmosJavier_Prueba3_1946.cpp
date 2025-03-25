#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
using namespace std;
  
void nombresConductores(vector<string>& nombres, int conductores){
    for(int i = 0; i < conductores; ++i){
        cout << "Ingresa el nombre del conductor " << i + 1 << ": "; cin >> nombres[i];
    }
}
void kilometros(vector<vector<int>>& kms, int conductores, int dias) {
    srand(time(0));
    for (int i = 0; i < conductores; ++i) {
        cout << "Kilometros recorridos por " << nombresConductores[i] << " en cada dia de la semana:\n";
        for (int j = 0; j < dias; ++j) {
            kms[i][j] = rand() %  41;
            cout << "Dia " << j + 1 << ": " << kms[i][j] << " km\n";
        }
    }
}
void totalKilometros(const vector<vector<int>>& kms, vector<int>& total_kms, int conductores, int dias) {
    for (int i = 0; i < conductores; ++i){
        int suma = 0;
        for (int j = 0; j < dias; ++j){
            suma += kms[i][j];
        }
        total_kms[i] = suma;
    }
}
void mostrarListaConductores(const vector<string>& nombres, const vector<int>& total_kms, int conductores) {
    cout << "\nLista de conductores y kilometros recorridos:\n";
    for (int i = 0; i < conductores; ++i) {
        cout << nombres[i] << ": " << total_kms[i] << " km\n";
    }
}
 int conductorMasKilometros(const vector<int>& total_kms, int conductores) {
    int max_kms = total_kms[0];
    int indice_max_kms = 0;
    for (int i = 1; i < conductores; ++i){
        if (total_kms[i] > max_kms) {
            max_kms = total_kms[i];
            indice_max_kms = i;
        }
    }
    return indice_max_kms;
}
void graficamente(const vector<string>& nombres, const vector<int>& total_kms, int conductores){
    cout << "\nGrafica de kilometros recorridos:\n";
    for (int i = 0; i < conductores; ++i) {
        cout << nombres[i] << ": ";
        int num_caracteres = total_kms[i] / 10;
        for (int j = 0; j < num_caracteres; ++j) {
            cout << "*";
        }
        cout << "\n";
    }
}
int main(){
    int conductores, dias = 7;
    cout << "Ingresa el numero de conductores: ";cin >> conductores;
    vector<string> nombres(conductores);
    vector<vector<int>> kms(conductores, vector<int>(dias)); 
    vector<int> total_kms(conductores, 0);
    nombresConductores(nombres, conductores);
    kilometros(kms, conductores, dias);
    totalKilometros(kms, total_kms, conductores, dias);
    mostrarListaConductores(nombres, total_kms, conductores);
    int indice_max_kms = conductorMasKilometros(total_kms, conductores);
    cout << "\nEl conductor con el mayor numero de kilometros es: " << nombres[indice_max_kms] << " con " << total_kms[indice_max_kms] << " km\n";
    graficamente(nombres, total_kms, conductores);	
     
	return 0;
}