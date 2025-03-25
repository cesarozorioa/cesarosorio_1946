//Jhoel Pallaroso 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

void imprimirBarras(int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        cout << "*";
    }
    cout << endl;
}

void imprimirLinea(int longitud) {
    cout << "+" << string(longitud - 2, '-') << "+\n";
}

int main() {
    srand(time(0));  
    int numConductores, diasSemana = 7;
    vector<string> dias = {"Lun", "Mar", "Mie", "Jue", "Vie", "Sab", "Dom"};

    cout << "Ingrese el numero de conductores: ";
    cin >> numConductores;
    cin.ignore(); 

    vector<string> nombres(numConductores);
    vector<vector<int>> kms(numConductores, vector<int>(diasSemana));
    vector<int> total_kms(numConductores, 0);

    for (int i = 0; i < numConductores; i++) {
        cout << "Ingrese el nombre del conductor " << i + 1 << ": ";
        getline(cin, nombres[i]);

        for (int j = 0; j < diasSemana; j++) {
            kms[i][j] = rand() % 91 + 10;
            total_kms[i] += kms[i][j];
        }
    }

    cout << "\nKilometros recorridos por cada conductor:\n";
    imprimirLinea(81);
    cout << "| " << setw(10) << "Conductor" << " |";
    for (const auto& dia : dias) {
        cout << " " << setw(4) << dia << " |";
    }
    cout << " " << setw(6) << "Total" << " |\n";
    imprimirLinea(81);

    for (int i = 0; i < numConductores; i++) {
        cout << "| " << setw(10) << nombres[i] << " |";
        for (int j = 0; j < diasSemana; j++) {
            cout << " " << setw(4) << kms[i][j] << " |";
        }
        cout << " " << setw(6) << total_kms[i] << " |\n";
    }
    imprimirLinea(81);

    int maxIndex = max_element(total_kms.begin(), total_kms.end()) - total_kms.begin();
    cout << "\n Conductor con mas kilometros recorridos: " << nombres[maxIndex] << " con " << total_kms[maxIndex] << " km.\n";

    vector<pair<int, string>> ordenado;
    for (int i = 0; i < numConductores; i++) {
        ordenado.push_back({total_kms[i], nombres[i]});
    }
    sort(ordenado.rbegin(), ordenado.rend());

    cout << "\n Representacion grafica:\n";
    for (auto& par : ordenado) {
        cout << par.second << " (" << par.first << " km): ";
        imprimirBarras(par.first / 5); 
    }

    return 0;
}



