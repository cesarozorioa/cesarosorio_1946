#include <iostream>
using namespace std;

int main()
{
    int inf, sup, val, suma = 0, contador = 0, informacion = 0;
    bool bandera = true;
    while (bandera)
    {
        cout << "Ingrese límite inferior" << endl;
        cin >> inf;
        cout << "Ingrese límite superior" << endl;
        cin >> sup;
        if (inf > sup)
        {
            cout << "si" << endl;
        }
        else
        {
            while (bandera)
            {
                cout << "Ingrese valores" << endl;
                cin >> val;
                if (val == 0)
                {
                    bandera = false;
                }
                else
                {
                    if (val == inf || val == sup)
                    {
                        informacion++;
                    }
                    if (val > inf && val < sup)
                    {
                        suma = suma + val;
                    }
                    else
                    {
                        contador++;
                    }
                }
            }
            bandera = false;
        }
    }
    cout << "La suma = " << suma << endl;
    cout << "Los cantidad de numero que están fuera del rango son " << contador << endl;
    if (informacion != 0)
    {
        cout << "Se ingresaron " << informacion << " iguales a los limites" << endl;
    }
    else
    {
        cout << "No se ingresaron número iguales a los intervalos" << endl;
    }
    return 0;
}