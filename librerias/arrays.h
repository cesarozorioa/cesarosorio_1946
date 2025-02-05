#include <stdlib.h>
#include <time.h>
#include <iostream>
namespace vectorn
{
    void llenarVector(int v[], int n, int ri = 0, int rs = 10)
    {
        int i;
        for (i = 0; i < n; i++)
        {
            v[i] = rand() % (rs - ri + 1) + ri;
            // v[i]= ri + rand() % (rs+1 - ri);
            // variable = limite_inferior + rand() % (limite_superior +1 - limite_inferior);
        }
    }
    void ordenaBurbujav3(int v[], int n)
    {
        int mejora = 1;
        bool cambio = true;
        int aux;
        for (int i = 0; i < n && cambio; i++)
        {
            cambio = false;
            for (int j = 0; j < n - mejora; j++)
            {

                if (v[j] > v[j + 1])
                {
                    aux = v[j];
                    v[j] = v[j + 1];
                    v[j + 1] = aux;
                    cambio = true;
                }
            }
            mejora++;
        }
    }
    void verVector(int v[], int n)
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << v[i] << " ";
        }
    }
    bool isBusquedaBinaria(int v[], int n, int elemento)
    {
        int arriba, abajo, centro;
        abajo = 0;
        arriba = n - 1;
        while (abajo <= arriba)
        {
            centro = (abajo + arriba) / 2;
            if (v[centro] == elemento)
            {
                return true;
            }
            else if (v[centro] < elemento)
            {
                abajo = centro + 1;
            }
            else
            {
                arriba = centro - 1;
            }
        }
        return false;
    }
}