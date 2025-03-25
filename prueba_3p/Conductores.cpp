#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;


struct Conductor
{
    string nombre;
    vector<int> totalKms; 
    int totalSemana;      
};


vector<int> generarRecorridos()
{
    vector<int> recorridos(7); 
    for (int i = 0; i < 7; ++i)
    {
        recorridos[i] = rand() % 201; 
    }
    return recorridos;
}


int calcularTotal(const vector<int> &totalKms)
{
    int total = 0;
    for (int km : totalKms)
    {
        total += km;
    }
    return total;
}


void imprimirTabla(const vector<Conductor> &conductores)
{
    string diasSemana[] = {"Lunes", "Martes", "Miercoles", "Jueves", "Viernes", "Sabado", "Domingo"};

    // Imprimir encabezado de la tabla
    cout << "\nTabla de Recorridos:\n";
    cout << setw(10) << "Conductor";
    for (const string &dia : diasSemana)
    {
        cout << setw(10) << dia;
    }
    cout << setw(10) << "Total" << endl;

    
    for (const Conductor &conductor : conductores)
    {
        cout << setw(10) << conductor.nombre;
        for (int km : conductor.totalKms)
        {
            cout << setw(10) << km;
        }
        cout << setw(10) << conductor.totalSemana << endl;
    }
}

void ordenarRanking(vector<Conductor> &conductores)
{
    int n = conductores.size();
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = 0; j < n - i - 1; ++j)
        {
            if (conductores[j].totalSemana < conductores[j + 1].totalSemana)
            {

                Conductor temp = conductores[j];
                conductores[j] = conductores[j + 1];
                conductores[j + 1] = temp;
            }
        }
    }
}


void imprimirRanking(const vector<Conductor> &conductores)
{
    cout << "\nRanking de Conductores:\n";
    for (const Conductor &conductor : conductores)
    {
        cout << conductor.nombre << ": ";
        for (int i = 0; i < conductor.totalSemana / 10; ++i)
        {
            cout << "#";
        }
        cout << endl;
    }
}

void rankingConductores(const vector<Conductor> &conductores){
    cout<<"Rendimiento conductores: "<<endl;
    for (const Conductor &conductor : conductores)
    {
        cout << conductor.nombre << ": ";
        for (int i = 0; i < conductor.totalSemana / 10; ++i)
        {
            cout << conductor.nombre<<": "<<conductor.totalSemana;
        }
        
    }

}

int main()
{
    srand(time(0));

    int numConductores;
    cout << "Ingrese la cantidad de conductores: ";
    cin >> numConductores;

    vector<Conductor> conductores(numConductores);

    
    for (int i = 0; i < numConductores; ++i)
    {
        cout << "Ingrese el nombre del conductor " << i + 1 << ": ";
        cin >> conductores[i].nombre;
        conductores[i].totalKms = generarRecorridos();
        conductores[i].totalSemana = calcularTotal(conductores[i].totalKms);
    }

    imprimirTabla(conductores);
    ordenarRanking(conductores);

    imprimirRanking(conductores);

    return 0;
}