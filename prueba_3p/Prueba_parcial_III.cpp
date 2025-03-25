#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

main() {
    srand(time(0)); 

    int n;
    cout << "Ingrese el numero de conductores: ";
    cin >> n;

    vector<string> nombres(n);
    vector<vector<int>> kms(n, vector<int>(5));
    vector<string> dias = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};

    for (int i = 0; i < n; ++i) {
        cout << "Nombre del conductor " << i + 1 << ": ";
        cin >> nombres[i];
        cout << "Kilometros del lunes: ";
        cin >> kms[i][0];
        for (int j = 1; j < 5; ++j) {
            kms[i][j] = rand() % 100 + 1; 
    }

    vector<int> total_kms(n, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            total_kms[i] += kms[i][j];
        }
    }

    cout << "\n Lista de Conductores \n";
    cout << left << setw(15) << "Conductor";
    for (const auto& dia : dias) {
        cout << left << setw(10) << dia;
    }
    cout << left << setw(10) << "Total" << endl;

    for (int i = 0; i < n; ++i) {
        cout << left << setw(15) << nombres[i];
        for (int j = 0; j < 5; ++j) {
            cout << left << setw(10) << kms[i][j];
        }
        cout << left << setw(10) << total_kms[i] << endl;
    }

    int max_idx = 0;
    for (int i = 1; i < n; ++i) {
        if (total_kms[i] > total_kms[max_idx]) {
            max_idx = i;
        }
    }
    cout << "\nConductor con mas kilometros: " << nombres[max_idx] << " (" << total_kms[max_idx] << " km)\n";

    vector<int> indices(n);
    for (int i = 0; i < n; ++i) indices[i] = i;
    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return (total_kms[a] == total_kms[b]) ? a < b : total_kms[a] > total_kms[b];
    });

    cout << "\n Ranking (Orden Descendente) \n";
    int max_kms = total_kms[indices[0]];
    for (int idx : indices) {
        cout << nombres[idx] << " (" << total_kms[idx] << " km): ";
        int stars = (total_kms[idx] * 10) / max_kms;  
        cout << string(stars, '*') << "\n";
    }

    return 0;
}