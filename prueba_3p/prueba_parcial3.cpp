#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct kmDiarios {
    int lunes, martes, miercoles, jueves, viernes, sabado, domingo;
};

void calcularTotalKilometros(const vector<kmDiarios>& kilometrosDiarios, vector<int>& totalKilometros) {
    for (int i = 0; i < kilometrosDiarios.size(); i++) {
        int suma = kilometrosDiarios[i].lunes + kilometrosDiarios[i].martes + kilometrosDiarios[i].miercoles + 
                   kilometrosDiarios[i].jueves + kilometrosDiarios[i].viernes + kilometrosDiarios[i].sabado + 
                   kilometrosDiarios[i].domingo;
        totalKilometros.push_back(suma);
    }
}

void mostrarResultados(const vector<string>& nombres, const vector<int>& totalKilometros) {
    cout << "\nResultados:\n";
    cout << endl;
    for (size_t i = 0; i < nombres.size(); i++) {
        cout << "Conductor: " << nombres[i] << " - Total Kilometros: " << totalKilometros[i] << " km\n";
    }
    cout << endl;
}

void graficarKilometros(const vector<string>& nombres, const vector<int>& totalKilometros) {
    cout << "\nGrafico de Kilometros Recorridos:\n";
    cout << endl;
    for (size_t i = 0; i < nombres.size(); i++) {
        cout << nombres[i] << " | ";
        for (int j = 0; j < totalKilometros[i]; j++) {
            cout << "#";
        }
        cout << " (" << totalKilometros[i] << " km)\n";
    }
    cout << endl;
}

void graficarTablaKilometros(const vector<string>& nombres, const vector<kmDiarios>& kilometrosDiarios) {
    cout << "\nTabla de Kilometros Recorridos:\n";
    cout << endl;
    cout << setw(15) << left << "Conductor" << setw(10) << "Lunes" << setw(10) << "Martes" 
         << setw(10) << "Miercoles" << setw(10) << "Jueves" << setw(10) << "Viernes" 
         << setw(10) << "Sabado" << setw(10) << "Domingo" << endl;
    cout << endl;

    for (size_t i = 0; i < nombres.size(); i++) {
        cout << setw(15) << left << nombres[i]
             << setw(10) << kilometrosDiarios[i].lunes
             << setw(10) << kilometrosDiarios[i].martes
             << setw(10) << kilometrosDiarios[i].miercoles
             << setw(10) << kilometrosDiarios[i].jueves
             << setw(10) << kilometrosDiarios[i].viernes
             << setw(10) << kilometrosDiarios[i].sabado
             << setw(10) << kilometrosDiarios[i].domingo
             << endl;
    }
    cout << endl;
}

int main() {
    vector<string> nombres;
    vector<int> totalKilometros;
    vector<kmDiarios> kilometrosDiarios;

    int nroConductores;
    cout << "Ingrese el numero de conductores: ";
    cin >> nroConductores;

    cin.ignore();

    for (int i = 0; i < nroConductores; i++) {
        kmDiarios aux;
        string nombre;

        cout << "\nIngrese el nombre del conductor: ";
        getline(cin, nombre);
        nombres.push_back(nombre);

        cout << "Ingrese los kilometros recorridos por " << nombre << " en cada dia:\n";
        cout << "Lunes: "; cin >> aux.lunes;
        cout << "Martes: "; cin >> aux.martes;
        cout << "Miercoles: "; cin >> aux.miercoles;
        cout << "Jueves: "; cin >> aux.jueves;
        cout << "Viernes: "; cin >> aux.viernes;
        cout << "Sabado: "; cin >> aux.sabado;
        cout << "Domingo: "; cin >> aux.domingo;

        kilometrosDiarios.push_back(aux);

        cin.ignore();
    }

    graficarTablaKilometros(nombres, kilometrosDiarios);
    calcularTotalKilometros(kilometrosDiarios, totalKilometros);
    mostrarResultados(nombres, totalKilometros);
    graficarKilometros(nombres, totalKilometros);
     

    return 0;
}
