#include <iostream>
#include <sstream>

using namespace std;

int contarPalabras(const string &cadena) {
    stringstream ss(cadena);
    string palabra;
    int contador = 0;

    while (ss >> palabra) { // Extrae palabra por palabra ignorando espacios múltiples
        contador++;
    }
    return contador;
}

int main() {
    string texto;
    cout << "Ingrese una cadena: ";
    getline(cin, texto);

    int numeroPalabras = contarPalabras(texto);
    cout << "La cadena tiene " << numeroPalabras << " palabras." << endl;

    return 0;
}