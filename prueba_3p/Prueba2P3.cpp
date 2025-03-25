/*
Repositorio: 
https://github.com/BranScript/brandon_Collahuazo_1946.git
*/
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int DIAS = 5; //dias
const int MAX_CONDUCTORES = 10;

struct Conductor {
    string nombre;
    int kms[DIAS];
    int total_kms;
};

void generarKilometros(Conductor conductores[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        conductores[i].total_kms = 0;
        for (int j = 0; j < DIAS; j++) {
            conductores[i].kms[j] = rand() % 21; 
            conductores[i].total_kms += conductores[i].kms[j];
        }
    }
}

void imprimirTabla(Conductor conductores[], int n) {
    cout << "Nombre  Lunes  Martes  Miercoles  Jueves  Viernes  Total  Ranking" << endl;
    for (int i = 0; i < n; i++) {
        cout << conductores[i].nombre << "\t  ";
        for (int j = 0; j < DIAS; j++) {
            cout << conductores[i].kms[j] << "\t  ";
        }
        cout << conductores[i].total_kms << "\t  ";
        for (int k = 0; k < conductores[i].total_kms; k++) cout << "*";
        cout << endl;
    }
}

void ordenarPorKilometraje(Conductor conductores[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (conductores[i].total_kms < conductores[j].total_kms) {
                swap(conductores[i], conductores[j]);
            }
        }
    }
}

void mostrarMayorKilometraje(Conductor conductores[], int n) {
    ordenarPorKilometraje(conductores, n);
    cout << "\nConductor con más kilometraje:" << endl;
    cout << "NombreConductor  Total  Ranking" << endl;
    for (int i = 0; i < n; i++) {
        cout << conductores[i].nombre << "\t  " << conductores[i].total_kms << "\t  ";
        for (int j = 0; j < conductores[i].total_kms; j++) cout << "*";
        cout << endl;
    }
    cout << "\nEl conductor que más hizo es: " << conductores[0].nombre << endl;
}

int main() {
    int n;
    cout << "Ingrese la cantidad de conductores: ";
    cin >> n;
    if (n > MAX_CONDUCTORES) {
        cout << "El número máximo de conductores es " << MAX_CONDUCTORES << endl;
        return 1;
    }

    Conductor conductores[MAX_CONDUCTORES];
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el nombre del conductor " << i + 1 << ": ";
        cin >> conductores[i].nombre;
    }

    generarKilometros(conductores, n);
    
    int opcion;
    do {
        cout << "\nMenu:" << endl;
        cout << "1) Mostrar Tabla" << endl;
        cout << "2) Conductor con más kilometraje" << endl;
        cout << "3) Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                imprimirTabla(conductores, n);
                break;
            case 2:
                mostrarMayorKilometraje(conductores, n);
                break;
            case 3:
                cout << "Finalizo el programa :D" << endl;
                break;
            default:
                cout << "Opción no válida." << endl;
        }
    } while (opcion != 3);

    return 0;
}
