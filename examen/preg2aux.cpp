#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
using namespace std;

struct Producto {
    string nombre;
    int cantidad;
    double precio;
    string sucursal;
};

void leerDatos(const string& archivo, vector<Producto>& productos) {
    ifstream archivoEntrada(archivo);
    string linea;
    while (getline(archivoEntrada, linea)) {
        stringstream ss(linea);
        Producto p;
        string id;
        ss >> id >> p.nombre >> p.cantidad >> p.precio >> p.sucursal;
        productos.push_back(p);
    }
}

void calcularEstadisticas(const vector<Producto>& productos, int cantidadTotal[], int& sur, int& tecladoNorte, double recaudaciones[]) {
    for (const auto& p : productos) {
        if (p.nombre == "Laptop") cantidadTotal[0] += p.cantidad;
        if (p.nombre == "Mouse") cantidadTotal[1] += p.cantidad;
        if (p.nombre == "Teclado") cantidadTotal[2] += p.cantidad;
        if (p.nombre == "Monitor") cantidadTotal[3] += p.cantidad;
        if (p.nombre == "Impresora") cantidadTotal[4] += p.cantidad;
        if (p.nombre == "Webcam") cantidadTotal[5] += p.cantidad;

        if (p.sucursal == "Sur") sur += p.cantidad;
        if (p.sucursal == "Norte" && p.nombre == "Teclado") tecladoNorte += p.cantidad;

        if (p.sucursal == "Norte") recaudaciones[0] += p.cantidad * p.precio;
        if (p.sucursal == "Centro") recaudaciones[1] += p.cantidad * p.precio;
        if (p.sucursal == "Sur") recaudaciones[2] += p.cantidad * p.precio;
        if (p.sucursal == "Este") recaudaciones[3] += p.cantidad * p.precio;
    }
}

string sucursalMayorRecaudacion(const double recaudaciones[]) {
    double maxRecaudacion = recaudaciones[0];
    int sucursal = 0;  // 0: Norte, 1: Centro, 2: Sur, 3: Este
    for (int i = 1; i < 4; i++) {
        if (recaudaciones[i] > maxRecaudacion) {
            maxRecaudacion = recaudaciones[i];
            sucursal = i;
        }
    }
    return (sucursal == 0 ? "Norte" : sucursal == 1 ? "Centro" : sucursal == 2 ? "Sur" : "Este");
}

void escribirResultados(const string& archivo, int cantidadTotal[], int sur, int tecladoNorte, double recaudaciones[], double recaudacionTotal, const string& sucursalMayor) {
    ofstream archivoSalida(archivo);
    archivoSalida << "Cantidad total de cada articulo:\n";
    archivoSalida << "Laptop: " << cantidadTotal[0] << "\nMouse: " << cantidadTotal[1] << "\nTeclado: " << cantidadTotal[2]
                  << "\nMonitor: " << cantidadTotal[3] << "\nImpresora: " << cantidadTotal[4] << "\nWebcam: " << cantidadTotal[5] << endl;

    archivoSalida << "\nCantidad total de artículos en la sucursal Sur: " << sur << endl;
    archivoSalida << "Cantidad de Teclados en la sucursal Norte: " << tecladoNorte << endl;

    archivoSalida << "\nRecaudación total por sucursal:\n";
    archivoSalida << "Norte: $" << recaudaciones[0] << "\nCentro: $" << recaudaciones[1] << "\nSur: $" << recaudaciones[2]
                  << "\nEste: $" << recaudaciones[3] << endl;

    archivoSalida << "\nRecaudación total de la empresa: $" << recaudacionTotal << endl;
    archivoSalida << "Sucursal con mayor recaudación: " << sucursalMayor << endl;
}

int main() {
    vector<Producto> productos;
    leerDatos("empresa.txt", productos);

    int cantidadTotal[6] = {0};
    int sur = 0, tecladoNorte = 0;
    double recaudaciones[4] = {0};

    calcularEstadisticas(productos, cantidadTotal, sur, tecladoNorte, recaudaciones);

    double recaudacionTotal = recaudaciones[0] + recaudaciones[1] + recaudaciones[2] + recaudaciones[3];
    string sucursalMayor = sucursalMayorRecaudacion(recaudaciones);

    escribirResultados("consolidado.txt", cantidadTotal, sur, tecladoNorte, recaudaciones, recaudacionTotal, sucursalMayor);
    cout << "Resultados guardados en consolidado.txt" << endl;

    return 0;
}
