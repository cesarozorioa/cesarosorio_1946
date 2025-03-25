#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Conductor {
    string nombre;
    vector<int> kms;
    int totalKms;
};

void anadirConductor(vector<Conductor> &conduc) {
    Conductor est;
    est.totalKms = 0;
    cout << "Ingrese el nombre del conductor: ";
    cin >> est.nombre;
    

    for (int j = 0; j < 5; j++) {
        int km = rand() % 101; 
        est.kms.push_back(km);
        est.totalKms += km;
    }
    
    conduc.push_back(est);
    cout << "\nConductor agregado con exito.\n";
}

void mostrarLista(const vector<Conductor> &conduc) {
    if (conduc.empty()) {
        cout << "No hay conductores registrados.\n";
        return;
    }

    cout << "\nLista de conductores y kilometros recorridos:\n";
    cout << "------------------------------------------------------------\n";
    cout << "Nombre         Lunes  Martes  Miercoles  Jueves  Viernes\n";
    cout << "------------------------------------------------------------\n";
    
    for (const auto &est : conduc) {
        cout << est.nombre << "\t";
        for (int km : est.kms) {
            cout << km << "\t";
        }
        cout << "\n";
    }

    cout << "\nTabla de distancia total recorrida por conductor:\n";
    cout << "--------------------------------\n";
    cout << "Nombre         Total Kms\n";
    cout << "--------------------------------\n";
    
    for (const auto &est : conduc) {
        cout << est.nombre << "\t" << est.totalKms << " km\n";
    }

    cout << "\nLista de nombres de los conductores:\n";
    cout << "-------------------------\n";
    cout << "Nombre\n";
    cout << "-------------------------\n";
    
    for (const auto &est : conduc) {
        cout << est.nombre << "\n";
    }
}

int main() {
    srand(time(0)); 
    vector<Conductor> conduc;
    int opcion;
    
    do {
        cout << "\nMenu:\n";
        cout << "1. Agregar conductor\n";
        cout << "2. Mostrar tablas de kilometros\n";
        cout << "3. Salir\n";
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1:
                anadirConductor(conduc);
                break;
            case 2:
                mostrarLista(conduc);
                break;
            case 3:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion no valida, intente de nuevo.\n";
        }
    } while (opcion != 3);
    
    return 0;
}
