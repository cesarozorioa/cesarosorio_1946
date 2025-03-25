#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib> 
using namespace std;

struct Conductor {
    string nombre;
    int totalKm;
};
void limpiarBuffer() {
    cin.ignore(1000, '\n');  
}
int obtenerEnteroPositivo(const string& mensaje) {
    int numero;
    while (true) {
        cout << mensaje;
        cin >> numero;
        if (cin.fail() || numero <= 0) {
            cin.clear();
            limpiarBuffer();
            cout << "Entrada invalida. Intente de nuevo." << endl;
        } else {
            limpiarBuffer();
            return numero;
        }
    }
}
void ingresarDatos(int numConductores, vector<string>& nombres, 
                   vector<vector<int>>& kms, vector<int>& totalKms) {
    const int diasSemana = 5;  
    for (int i = 0; i < numConductores; i++) {
        cout << "\nIngrese el nombre del conductor " << i + 1 << ": ";
        getline(cin, nombres[i]);
        for (int dia = 0; dia < diasSemana; dia++) {
            
            int km = rand() % 61;
            kms[i][dia] = km;
            totalKms[i] += km;
        }
    }
}
void imprimirResumen(const vector<string>& nombres, const vector<int>& totalKms) {
    cout << "\n--- Lista de conductores y sus kilometros totales ---\n";
    for (size_t i = 0; i < nombres.size(); i++) {
        cout << nombres[i] << ": " << totalKms[i] << " km" << endl;
    }
}
int obtenerIndiceMaximo(const vector<int>& totalKms) {
    int indiceMax = 0;
    for (size_t i = 1; i < totalKms.size(); i++) {
        if (totalKms[i] > totalKms[indiceMax])
            indiceMax = i;
    }
    return indiceMax;
}
void imprimirRepresentacionGrafica(const vector<string>& nombres, const vector<int>& totalKms) {
    
    vector<Conductor> conductores;
    int numConductores = nombres.size();
    for (int i = 0; i < numConductores; i++) {
        conductores.push_back({ nombres[i], totalKms[i] });
    }
    sort(conductores.begin(), conductores.end(), [](const Conductor &a, const Conductor &b) {
        return a.totalKm > b.totalKm;
    });
    cout << "\n-------------------------------------------" << endl;
    cout << "Representacion grafica en orden descendente" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Conductor       Km        Grafica" << endl;
    cout << "-------------------------------------------" << endl;

    for (const auto &c : conductores) {
        
        string nombreFormateado = c.nombre;
        if (nombreFormateado.size() < 15)
            nombreFormateado.append(15 - nombreFormateado.size(), ' ');
        
        string kmStr = to_string(c.totalKm);
        if (kmStr.size() < 10)
            kmStr.append(10 - kmStr.size(), ' ');
        
        cout << nombreFormateado << kmStr;
        
        int numAsteriscos = c.totalKm / 10;
        if (numAsteriscos == 0)
            numAsteriscos = 1;
        for (int i = 0; i < numAsteriscos; i++) {
            cout << "*";
        }
        cout << endl;
    }
}

main() {
    int numConductores = obtenerEnteroPositivo("Ingrese el numero de conductores: ");
    
    vector<string> nombres(numConductores);
    vector<vector<int>> kms(numConductores, vector<int>(5, 0)); 
    vector<int> totalKms(numConductores, 0);
    
    ingresarDatos(numConductores, nombres, kms, totalKms);
    
    imprimirResumen(nombres, totalKms);
    
    int indiceMax = obtenerIndiceMaximo(totalKms);
    cout << "\nEl conductor con mayor numero de kilometros es: " 
         << nombres[indiceMax] << " con " << totalKms[indiceMax] << " km" << endl;
    
    imprimirRepresentacionGrafica(nombres, totalKms);
    
    return 0;
}
