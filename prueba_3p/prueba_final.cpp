#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>  
#include <ctime>    

using namespace std;

struct Conductor {
    string nombre;
    int total_kms;
};

// Metodo de burbuja mejorado para ordenar los conductores por kilometraje
void ordenarConductores(vector<Conductor> &conductores) {
    int n = conductores.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (conductores[j].total_kms < conductores[j + 1].total_kms) {
                // Intercambiar
                Conductor temp = conductores[j];
                conductores[j] = conductores[j + 1];
                conductores[j + 1] = temp;
            }
        }
    }
}

int main() {
    srand(time(0)); 

    int n;
    
    while (true) {
        cout << "Ingrese el numero de conductores: ";
        if (!(cin >> n) || n <= 0) {
            cout << "Caracter no valido. Intente de nuevo.\n";
            cin.clear(); 
            cin.ignore(10000, '\n'); 
        } else {
            break;
        }
    }
    
    cin.ignore(); 

    vector<string> nombres(n);
    vector<int> total_kms(n, 0);
    vector<string> dias = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes"};

    // Pedir los nombres de los conductores y generar los kilometros aleatoriamente
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre del conductor " << i + 1 << ": ";
        getline(cin, nombres[i]);

        cout << "Kilometros recorridos por " << nombres[i] << " en cada dia de la semana:\n";
        for (int j = 0; j < 5; j++) {
            int kms = rand() % 101; 
            cout << dias[j] << ": " << kms << " km\n";
            total_kms[i] += kms;
        }
        cout << "Total: " << total_kms[i] << " km\n\n";
    }

    // Crear un vector de estructuras para ordenar
    vector<Conductor> conductores(n);
    for (int i = 0; i < n; i++) {
        conductores[i] = {nombres[i], total_kms[i]};
    }

    ordenarConductores(conductores);

    bool empate = false;
    if (n > 1 && conductores[0].total_kms == conductores[1].total_kms) {
        empate = true;
    }

    // Mostrar lista ordenada
    cout << "\nLista de conductores con kilometros recorridos:\n";
    for (const auto &conductor : conductores) {
        cout << conductor.nombre << " - " << conductor.total_kms << " km\n";
    }

    if (empate) {
        cout << "\nEmpate entre: " << conductores[0].nombre << " y " << conductores[1].nombre 
            << " con " << conductores[0].total_kms << " km\n";
    } else {
        cout << "\nConductor con mayor kilometraje: " << conductores[0].nombre 
            << " con " << conductores[0].total_kms << " km\n";
    }

    cout << "\nTabla de posiciones de los conductores en forma descendente:\n";
    for (const auto &conductor : conductores) {
        cout << conductor.nombre << ": ";
        for (int j = 0; j < conductor.total_kms / 10; j++) {  
            cout << "*";
        }
        cout << " (" << conductor.total_kms << " km)\n";
    }

    return 0;
}
