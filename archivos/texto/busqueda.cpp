#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
using namespace std;
void buscarPalabra(ifstream &archivoEntrada, ofstream &archivoSalida, string palabraBuscar, string palabraReemplazar)
{
    archivoEntrada.open("ejemplo.txt");
    archivoSalida.open("ejemplo_modificado.txt");
    string linea;

    if (!archivoEntrada.is_open() || !archivoSalida.is_open())
    {
        cout << "Error al abrir los archivos." << endl;
        return;
    }

    while (getline(archivoEntrada, linea))
    {
        string lineaModificada = linea;
        size_t posicion = lineaModificada.find(palabraBuscar);
        if (posicion != string::npos)
        {
            while (posicion != string::npos)
            {
                lineaModificada.replace(posicion, palabraBuscar.length(), palabraReemplazar);
                posicion = lineaModificada.find(palabraBuscar, posicion + palabraReemplazar.length());
            }
        }
        archivoSalida << lineaModificada << endl;
    }

    archivoEntrada.close();
    archivoSalida.close();
}
void manejoArchivos()
{
    if (remove("ejemplo.txt") == -1)
        perror("Could not delete 'CRT_REMOVE.TXT'");
    else
        printf("Deleted 'CRT_REMOVE.TXT'\n");
    //renombrar archivos
    if (rename("ejemplo_modificado.txt", "ejemplo.txt") == -1)
        perror("Could not rename 'ejemplo_modificado.txt' to 'ejemplo.txt'");
    else
        printf("Renamed 'ejemplo_modificado.txt' to 'ejemplo.txt'\n");

}

int main()
{
    ifstream archivoEntrada;
    ofstream archivoSalida;
    string palabraBuscar, palabraReemplazar, linea;
    cout << "Ingresa la palabra a buscar: ";
    getline(cin, palabraBuscar);
    cout << "Ingresa la palabra de reemplazo: ";
    getline(cin, palabraReemplazar);
    buscarPalabra(archivoEntrada, archivoSalida, palabraBuscar, palabraReemplazar);
    cout << "Proceso completado." << endl;
    manejoArchivos();
    return 0;
}