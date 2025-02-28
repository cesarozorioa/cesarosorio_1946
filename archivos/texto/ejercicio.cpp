#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    // Declarar variables
    string palabraBuscar, palabraReemplazar, linea;    
    // Pedir al usuario las palabras
    cout << "Ingresa la palabra que quieres buscar: ";
    getline(cin, palabraBuscar);
    cout << "Ingresa la palabra por la que la quieres reemplazar: ";
    getline(cin, palabraReemplazar);    
    // Abrir el archivo original para leer
    ifstream archivoEntrada("ejemplo.txt");
    // Abrir un archivo nuevo para escribir el resultado
    ofstream archivoSalida("ejemplo_modificado.txt");
    
    // Verificar si ambos archivos se abrieron correctamente
    if (!archivoEntrada.is_open()) {
        cout << "No se pudo abrir el archivo original." << endl;
        return 1;
    }
    if (!archivoSalida.is_open()) {
        cout << "No se pudo crear el archivo de salida." << endl;
        archivoEntrada.close();
        return 1;
    }
    
    bool encontrada = false; // Bandera para saber si encontramos la palabra
    // Leer el archivo línea por línea
    while (getline(archivoEntrada, linea)) {
        string lineaModificada = linea; // Copia de la línea original
        
        // Buscar la palabra en la línea
        size_t posicion = lineaModificada.find(palabraBuscar);
        if (posicion != string::npos) { // Si la palabra está en la línea
            encontrada = true;
            // Reemplazar todas las ocurrencias de la palabra
            while (posicion != string::npos) {
                lineaModificada.replace(posicion, palabraBuscar.length(), palabraReemplazar);
                posicion = lineaModificada.find(palabraBuscar, posicion + palabraReemplazar.length());
            }
        }
        
        // Escribir la línea (modificada o no) en el archivo de salida
        archivoSalida << lineaModificada << endl;
    }    
    // Cerrar ambos archivos
    archivoEntrada.close();
    archivoSalida.close();
    
    // Informar al usuario
    if (encontrada) {
        cout << "La palabra '" << palabraBuscar << "' fue reemplazada por '" 
             << palabraReemplazar << "' en el nuevo archivo 'ejemplo_modificado.txt'." << endl;
    } else {
        cout << "La palabra '" << palabraBuscar << "' no se encontró en el archivo." << endl;
    }
    
    return 0;
}