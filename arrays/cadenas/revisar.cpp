#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

bool esAlfanumerico(char c) {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

std::string limpiarPalabra(const std::string& palabra) {
    std::string limpia;
    for (size_t i = 0; i < palabra.length(); ++i) { 
        char c = palabra[i];
        if (esAlfanumerico(c)) { 
            limpia += c;
        }
    }
    return limpia;
}

std::string convertirAMinusculas(const std::string& str) {
    std::string minusculas = str;
    std::transform(minusculas.begin(), minusculas.end(), minusculas.begin(), ::tolower);
    return minusculas;
}

int main() {
    std::string cadena;
    std::string objetivo;
    std::string reemplazo;

    std::cout << "Ingrese una cadena: ";
    std::getline(std::cin, cadena);

    std::cout << "Que palabra se va a reemplazar?: ";
    std::cin >> objetivo;

    std::cout << "Cual sera el reemplazo de la palabra?: ";
    std::cin >> reemplazo;

    std::string objetivoMinusculas = convertirAMinusculas(objetivo);
    
    std::istringstream stream(cadena);
    std::string palabra;
    std::string resultado;

    bool primeraPalabra = true; 

    while (stream >> palabra) {
        std::string palabraLimpia = limpiarPalabra(palabra);
        std::string palabraLimpiaMinusculas = convertirAMinusculas(palabraLimpia);

        if (palabraLimpiaMinusculas == objetivoMinusculas) {
            if (!primeraPalabra) {
                resultado += " "; 
            }
            resultado += reemplazo; 
        } else {
            if (!primeraPalabra) {
                resultado += " ";
            }
            resultado += palabra; 
        }
        primeraPalabra = false; 
    }

    std::cout << "Resultado: " << resultado << std::endl;

    return 0;
}