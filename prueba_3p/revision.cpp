#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

struct conductor
{
    string nombre;
    double kilometrosl, kilometrosm, kilometrosmie, kilometrosj, kilometrosv, kilometross, kilometrosd;
    double kilometrostotal = 0;
};

void registroNombreConductores(vector<conductor> &conductores, int num)
{
    string nombre;
    for (int i = 0; i < num; i++)
    {
        cout << "---------------------------------" << endl;
        cout << "Ingrese el nombre del conductor: ";
        getline(cin, nombre);
        while (nombre == "\0" || nombre == " ")
        {
            cout << "Ingrese un nombre valido: ";
            getline(cin, nombre);
        }
        conductor conductor = {nombre, 0};
        conductores.push_back(conductor);
        cout << "Conductor: " << conductores[i].nombre << " registrado." << endl;
    }
    cout << "=====================================" << endl;
    cout << "Conudctores registrados exitosamente." << endl;
    cout << "=====================================" << endl;
}

void registrarKmConductor(vector<conductor> &conductores, int num)
{
    double km;
    for (int i = 0; i < num; i++)
    {
        cout << "---------------------------------" << endl;
        cout << "Ingrese los kilometros recorridos por " << conductores[i].nombre << " en la semana." << endl;
        cout << "Lunes: ";
        cin >> km;
        conductores[i].kilometrosl = km;
        cout << "Martes: ";
        cin >> km;
        conductores[i].kilometrosm = km;
        cout << "Miercoles: ";
        cin >> km;
        conductores[i].kilometrosmie = km;
        cout << "Jueves: ";
        cin >> km;
        conductores[i].kilometrosj = km;
        cout << "Viernes: ";
        cin >> km;
        conductores[i].kilometrosv = km;
        cout << "Sabado: ";
        cin >> km;
        conductores[i].kilometross = km;
        cout << "Domingo: ";
        cin >> km;
        conductores[i].kilometrosd = km;
        while (km < 0)
        {
            cout << "Ingrese un numero valido: ";
            cin >> km;
        }
        conductores[i].kilometrostotal = conductores[i].kilometrosl + conductores[i].kilometrosm + conductores[i].kilometrosmie + conductores[i].kilometrosj + conductores[i].kilometrosv + conductores[i].kilometross + conductores[i].kilometrosd;
        cout << "Kilometros totales recorridos por " << conductores[i].nombre << ": " << conductores[i].kilometrostotal << endl;
    }
}

void generarTabla(vector<conductor> &conductores, int num)
{
    cout << setw(20) << left << "Nombre del conductor" << setw(12) << "Km Lunes" << setw(12) << "Km Martes" << setw(14) << "Km Miercoles" << setw(12) << "Km Jueves" << setw(12) << "Km Viernes" << setw(12) << "Km Sabado" << setw(14) << "Km Domingo" << setw(10) << "Total" << endl;
    cout << "====================================================================================================================\n";
    double maxKm = 0;
    int maxIndex = 0;
    for (int i = 0; i < num; i++)
    {
        cout << setw(20) << left << conductores[i].nombre << setw(12) << conductores[i].kilometrosl << setw(12) << conductores[i].kilometrosm << setw(14) << conductores[i].kilometrosmie << setw(12) << conductores[i].kilometrosj << setw(12) << conductores[i].kilometrosv << setw(12) << conductores[i].kilometross << setw(14) << conductores[i].kilometrosd << setw(10) << conductores[i].kilometrosl + conductores[i].kilometrosm + conductores[i].kilometrosmie + conductores[i].kilometrosj + conductores[i].kilometrosv + conductores[i].kilometross + conductores[i].kilometrosd << endl;
        if (conductores[i].kilometrostotal > maxKm)
        {
            maxKm = conductores[i].kilometrostotal;
            maxIndex = i;
        }
    }
    cout << "====================================================================================================================\n";
    cout << "Conductor con mas kilometros recorridos: " << conductores[maxIndex].nombre << " con " << maxKm << " kilometros." << endl;
}
main()
{
    vector<conductor> conductores;
    string nombre;
    int nCon;
    double km;
    char respuesta;

    cout << "Ingrese el numero de conductores: ";
    cin >> nCon;
    while (nCon <= 0)
    {
        cout << "Ingrese un numero valido: ";
        cin >> nCon;
    }
    cin.ignore();
    registroNombreConductores(conductores, nCon);
    registrarKmConductor(conductores, nCon);
    generarTabla(conductores, nCon);
}