#include <iostream>
#include <string>

using namespace std;

struct Conductor {
    string nombre;
    int kilometros[7];
    int total_kms = 0;
};

int encontrarMaximo(Conductor conductores[], int num_conductores) {
    int indice_max = 0;
    for (int i = 1; i < num_conductores; i++) {
        if (conductores[i].total_kms > conductores[indice_max].total_kms) {
            indice_max = i;
        }
    }
    return indice_max;
}


void representarGraficamente(Conductor conductores[], int num_conductores, int indice_max) {
    cout << "\nRepresentación gráfica del recorrido:\n";
    for (int i = 0; i < num_conductores; i++) {
        cout << conductores[i].nombre << " | ";
        for (int j = 0; j < conductores[i].total_kms / 10; j++) {
            cout << "#";
        }
        cout << " (" << conductores[i].total_kms << " km)";
        
       
        if (i == indice_max) {
            cout << " -> ASCII: ";
            for (char c : conductores[i].nombre) {
                cout << int(c) << " ";
            }
        }

        cout << endl;
    }
}

int main() {
    int num_conductores;
    cout << "Ingrese la cantidad de conductores: ";
    cin >> num_conductores;
    cin.ignore();

    Conductor conductores[num_conductores];

   
    for (int i = 0; i < num_conductores; i++) {
        cout << "\nIngrese el nombre del conductor " << i + 1 << ": ";
        getline(cin, conductores[i].nombre);

        cout << "Ingrese los kilómetros recorridos en los 7 días de la semana:\n";
        for (int j = 0; j < 7; j++) {
            cout << "Día " << j + 1 << ": ";
            cin >> conductores[i].kilometros[j];
            conductores[i].total_kms += conductores[i].kilometros[j];
        }
        cin.ignore();
    }

   
    cout << "\nDatos de los conductores:\n";
    for (int i = 0; i < num_conductores; i++) {
        cout << "Nombre: " << conductores[i].nombre << endl;
        cout << "Kilómetros recorridos por día: ";
        for (int j = 0; j < 7; j++) {
            cout << conductores[i].kilometros[j] << " ";
        }
        cout << "\nTotal kilómetros recorridos: " << conductores[i].total_kms << " km\n";
        cout << "-----------------------------------\n";
    }


    int indice_max = encontrarMaximo(conductores, num_conductores);

  
    representarGraficamente(conductores, num_conductores, indice_max);

    return 0;
}
