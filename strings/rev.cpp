#include <iostream>
using namespace std;

string remplazarCadena(string primeraCadena, string segundaCadena, string nuevaCadena) {
    string resultado = " " + primeraCadena + " ";  // Agregamos espacios para evitar problemas con palabras al inicio o final
    string objetivo = " " + segundaCadena + " ";
    string reemplazo = " " + nuevaCadena + " ";

    size_t pos = resultado.find(objetivo);
    while (pos != string::npos) {
        resultado.replace(pos, objetivo.size(), reemplazo);
        pos = resultado.find(objetivo, pos + reemplazo.size());
    }

    return resultado.substr(1, resultado.size() - 2);  // Quitamos los espacios extra añadidos
}

int main() {
    string cadena, cadena2, cadena3;
    cout << "Ingrese una cadena: " << endl;
    getline(cin, cadena);
    cout << "Ingrese cadena objetivo: " << endl;
    getline(cin, cadena2);
    cout << "Ingrese cadena para reemplazar: " << endl;
    getline(cin, cadena3);

    string cadenaFinal = remplazarCadena(cadena, cadena2, cadena3);
    cout << "La cadena final es: " << cadenaFinal << endl;

    return 0;
}