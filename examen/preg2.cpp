#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

const int NUM_ARTICULOS = 6;
const int NUM_SUCURSALES = 4;

struct Sucursal {
    string nombre;
    int cantidades[NUM_ARTICULOS];
};

void leerDatos(float precios[], Sucursal sucursales[]) {
    ifstream archivoEntrada("empresa.txt");
    if (!archivoEntrada.is_open()) {
        cerr << "No se pudo abrir el archivo de datos." << endl;
        exit(1);
    }

    for (int i = 0; i < NUM_ARTICULOS; ++i) {
        archivoEntrada >> precios[i];
    }


    for (int i = 0; i < NUM_SUCURSALES; ++i) {
        for (int j = 0; j < NUM_ARTICULOS; ++j) {
            archivoEntrada >> sucursales[i].cantidades[j];
        }
    }

    archivoEntrada.close();
}

void generarReporte(const float precios[], const Sucursal sucursales[], const string productos[]) {
    ofstream archivoSalida("reporte.txt");
    if (!archivoSalida.is_open()) {
        cerr << "No se pudo abrir el archivo de salida." << endl;
        exit(1);
    }

  
    archivoSalida << "Precios de los artículos:" << endl;
    for (int i = 0; i < NUM_ARTICULOS; ++i) {
        archivoSalida << productos[i] << ": " << precios[i] << endl;
    }

    for (int i = 0; i < NUM_SUCURSALES; ++i) {
        archivoSalida << "\nCantidades vendidas en la sucursal " << sucursales[i].nombre << ":" << endl;
        for (int j = 0; j < NUM_ARTICULOS; ++j) {
            archivoSalida << productos[j] << ": " << sucursales[i].cantidades[j] << endl;
        }
    }

    archivoSalida.close();
}

void mostrarDatos(const float precios[], const Sucursal sucursales[], const string productos[]) {
    // Mostrar precios
    cout << "Precios de los artículos:" << endl;
    for (int i = 0; i < NUM_ARTICULOS; ++i) {
        cout << productos[i] << ": " << precios[i] << endl;
    }

    // Mostrar cantidades vendidas por sucursal
    for (int i = 0; i < NUM_SUCURSALES; ++i) {
        cout << "\nCantidades vendidas en la sucursal " << sucursales[i].nombre << ":" << endl;
        for (int j = 0; j < NUM_ARTICULOS; ++j) {
            cout << productos[j] << ": " << sucursales[i].cantidades[j] << endl;
        }
    }
}

int main() {
    float precios[NUM_ARTICULOS];
    Sucursal sucursales[NUM_SUCURSALES] = {
        {"Norte", {0}},
        {"Sur", {0}},
        {"Este", {0}},
        {"Oeste", {0}}
    };
    string productos[NUM_ARTICULOS] = { "laptop", "monitor", "teclado", "impresora", "camara", "mouse" };

    leerDatos(precios, sucursales);
    mostrarDatos(precios, sucursales, productos);
    generarReporte(precios, sucursales, productos);

    cout << "Reporte generado en reporte.txt" << endl;
    return 0;
}