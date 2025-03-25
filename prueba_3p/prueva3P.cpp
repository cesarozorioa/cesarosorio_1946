#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int generarKilometrosAleatorios(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(0));

    int numConductores = 5;
    vector<string> nombre(numConductores);
    vector<vector<int>> kms(numConductores, vector<int>(7));
    vector<int> totalKms(numConductores, 0);

    ofstream archivo("resultados.txt");

    if (!archivo) {
        cout << "Error al abrir el archivo para escribir.\n";
        return 1;
    }

    archivo << "\tDia 1\tDia 2\tDia 3\tDia 4\tDia 5\tDia 6\tDia 7\tTotal\n";

    for (int i = 0; i < numConductores; ++i) {
        cout << "Ingrese el nombre del conductor " << i + 1 << ": ";
        cin >> nombre[i];

        archivo << nombre[i] << "\t";

        int sumaSemana = 0;
        
        for (int j = 0; j < 7; ++j) {
            kms[i][j] = generarKilometrosAleatorios(10, 40);
            archivo << kms[i][j] << "\t";
            sumaSemana += kms[i][j];
        }

        totalKms[i] = sumaSemana;
        archivo << totalKms[i] << "\n";
    }

    int maxKms = totalKms[0];
    int maxIndex = 0;

    for (int i = 1; i < numConductores; ++i) {
        if (totalKms[i] > maxKms) {
            maxKms = totalKms[i];
            maxIndex = i;
        }
    }

    archivo << "\nConductor con mas kilometros recorridos: " << nombre[maxIndex] << " con " << maxKms << " km\n";

    archivo << "\nRepresentacion grafica de los kilometros recorridos (por cada 'X' = 20 km):\n";
    for (int i = 0; i < numConductores; ++i) {
        archivo << nombre[i] << ": ";
        int barras = totalKms[i] / 20;
        for (int j = 0; j < barras; ++j) {
            archivo << "X";
        }
        archivo << " (" << totalKms[i] << " km)\n";
    }

    archivo.close();

    cout << "\nLos resultados se han guardado en el archivo 'resultados.txt'.\n";

    return 0;
}
