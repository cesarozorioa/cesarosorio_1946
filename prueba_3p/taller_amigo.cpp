#include <iostream>
#include <string>
using namespace std;

string ingresarCadena() {
    string nuevaCadena;
    cout << "Ingrese la cadena: ";
    getline(cin, nuevaCadena);
    return nuevaCadena;
}

void modificarCadena(string &cadena) {
    cout << "Opciones de modificacion:"<<endl;
    cout << "1. Agregar letra al final" << endl;
    cout << "2. Modificar primera letra" << endl;
    cout << "3. Modificar ultima letra"<<endl;
    
    int opcion;
    cout << "Elija opción: ";
    cin >> opcion;

    switch(opcion) {
        case 1: {
            char letra;
            cout << "Letra a agregar: ";
            cin >> letra;
            cadena.push_back(letra);
            break;
        }
        case 2: {
            char letra;
            cout << "Nueva primera letra: ";
            cin >> letra;
            cadena.front() = letra;
            break;
        }
        case 3: {
            char letra;
            cout << "Nueva ultima letra:";
            cin >> letra;
            cadena.back() = letra;
            break;
        }
    }
}

// Función para mostrar resultados
void mostrarResultados(const string &cadena) {
    cout << "Resultado final: " << cadena << endl;
}

int main() {

    string cadena1 = ingresarCadena();
    string cadena4;
    const char *auxiliar;

    // Método constructor
    string cadena2(cadena1);

    // Método de relleno
    string cadena3(10,'*');
    cout << cadena3 << endl;

    // Llamar a la función de modificación
    modificarCadena(cadena1);

    // Mostrar resultado después de la modificación
    mostrarResultados(cadena1);

    // Método para añadir usando push_back
    cadena1.push_back('x');
    cout << cadena1 << endl;

    // Método para modificar los caracteres
    cadena1.at(0) = 'i';
    cout << cadena1 << endl;

    // Usando front y back
    cadena1.front() = 'i';
    cadena1.back() = 'A';
    cout << cadena1 << endl;

    // Convertir a array de char
    auxiliar = cadena1.c_str();
    cout << "auxiliar array char: " << auxiliar << endl;

    // Verificar si está vacía
    (cadena4.empty()) ? cout << "Cadena Vacia\n" : cout << "Cadena no vacia\n";
    
    // Mostrar tamaño máximo
    cout << "Tamano maximo: " << cadena1.max_size() << endl;
    
    // Mostrar capacidad
    cout << "Capacidad " << cadena1.capacity() << endl;
    
    // Comparación de cadenas
    cout << "cad1" << cadena1 << "cad2" << cadena2 << endl;
    cadena1 = "Mola";
    cadena2 = "Holas";
    int comparacion = cadena1.compare(cadena2);
    cout << "compacion:" << comparacion << endl;
    
    // Búsqueda
    (cadena1.find("cos") == string::npos) ? 
        cout << "No encontrado" : 
        cout << "encontrado";

    return 0;
}