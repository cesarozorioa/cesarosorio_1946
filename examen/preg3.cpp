#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;
struct Articulo {
    string producto;
    int cantidad;
    double precio;
    string sucursal;
};

void leerDatos(vector<Articulo>& articulos) {
    ifstream archivo("empresa.txt");
    string linea;

    if (archivo.is_open()) {
        getline(archivo, linea);

        while (getline(archivo, linea)) {
            Articulo articulo;
            istringstream ss(linea);
            string token;

            getline(ss, token, '\t');  
            getline(ss, articulo.producto, '\t');
            ss >> articulo.cantidad >> articulo.precio;
            getline(ss, token, '\t'); 
            getline(ss, articulo.sucursal, '\t');

            articulos.push_back(articulo);
        }
    }
}

void cantidadesTotales(const vector<Articulo>& articulos, vector<string>& productos, vector<int>& totales) {
    for (const auto& articulo : articulos) {
        auto it = find(productos.begin(), productos.end(), articulo.producto);
        if (it != productos.end()) {
            int index = distance(productos.begin(), it);
            totales[index] += articulo.cantidad;
        } else {
            productos.push_back(articulo.producto);
            totales.push_back(articulo.cantidad);
        }
    }
}

int cantidadSucursal(const vector<Articulo>& articulos, const string& sucursal) {
    int total = 0;
    for (const auto& articulo : articulos) {
        if (articulo.sucursal == sucursal) {
            total += articulo.cantidad;
        }
    }
    return total;
}

int cantidadArticuloSucursal(const vector<Articulo>& articulos, const string& producto, const string& sucursal) {
    int total = 0;
    for (const auto& articulo : articulos) {
        if (articulo.producto == producto && articulo.sucursal == sucursal) {
            total += articulo.cantidad;
        }
    }
    return total;
}

void recaudacionSucursal(const vector<Articulo>& articulos, vector<string>& sucursales, vector<double>& recaudaciones) {
    for (const auto& articulo : articulos) {
        auto it = find(sucursales.begin(), sucursales.end(), articulo.sucursal);
        if (it != sucursales.end()) {
            int index = distance(sucursales.begin(), it);
            recaudaciones[index] += articulo.cantidad * articulo.precio;
        } else {
            sucursales.push_back(articulo.sucursal);
            recaudaciones.push_back(articulo.cantidad * articulo.precio);
        }
    }
}

double recaudacionTotalEmpresa(const vector<double>& recaudaciones) {
    double total = 0.0;
    for (double recaudacion : recaudaciones) {
        total += recaudacion;
    }
    return total;
}

string mayorRecaudacion(const vector<string>& sucursales, const vector<double>& recaudaciones) {
    auto max_it = max_element(recaudaciones.begin(), recaudaciones.end());
    int index = distance(recaudaciones.begin(), max_it);
    return sucursales[index];
}

int main() {
    vector<Articulo> articulos;

    leerDatos(articulos);

    vector<string> productos;
    vector<int> totales;
    cantidadesTotales(articulos, productos, totales);

    int cantidadSur = cantidadSucursal(articulos, "Sur");

    int cantidadTecladoNorte = cantidadArticuloSucursal(articulos, "Teclado", "Norte");

    vector<string> sucursales;
    vector<double> recaudaciones;
    recaudacionSucursal(articulos, sucursales, recaudaciones);

    double recaudacionTotal = recaudacionTotalEmpresa(recaudaciones);

    string sucursalMayorRecaudacion = mayorRecaudacion(sucursales, recaudaciones);

    ofstream archivoSalida("consolidado.txt");

    if (archivoSalida.is_open()) {

        archivoSalida << "Cantidad total de cada artículo:\n";
        for (size_t i = 0; i < productos.size(); ++i) {
            archivoSalida << productos[i] << ": " << totales[i] << "\n";
        }

        archivoSalida << "\nCantidad de artículos en la sucursal Sur: " << cantidadSur << "\n";

        archivoSalida << "\nCantidad de Teclado en la sucursal Norte: " << cantidadTecladoNorte << "\n";

        archivoSalida << "\nRecaudación total por sucursal:\n";
        for (size_t i = 0; i < sucursales.size(); ++i) {
            archivoSalida << sucursales[i] << ": " << recaudaciones[i] << "\n";
        }

        archivoSalida << "\nRecaudación total de la empresa: " << recaudacionTotal << "\n";
        archivoSalida << "\nSucursal con mayor recaudación: " << sucursalMayorRecaudacion << "\n";
        archivoSalida.close();
        cout << "Los resultados han sido guardados en 'consolidado.txt'." << endl;
    } else {
        cout << "No se pudo abrir el archivo para escribir." << endl;
    }

    return 0;
}