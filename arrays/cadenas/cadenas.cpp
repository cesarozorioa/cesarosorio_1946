#include <iostream>
using namespace std;
void llenarCadena(char cad[], int n = 50)
{
    cout << "Ingresa una cadena de caracteres: ";
    cin.getline(cad, n);
    cin.clear();
}
int longitudCadena(char cad[])
{
    int contador = 0;
    for (int i = 0; cad[i] != '\0'; i++)
        contador++;
    return contador;
}
int contarPalabras(char cad[])
{
    char aux[20];    
    int palabras = 0,j=0;    
    for (int i = 0; cad[i] != '\0'; i++)
    {
       while (cad[i] != ' ' && cad[i] != '\0'){
            aux[j] = cad[i];            
            if(cad[i]!='\0'){
                i++;
            }            
            j++;          
        }        
        aux[j] = '\0';        
        j = 0;
        cout<<"aux: "<<aux<<endl;
        if (aux[0] != '\0' && aux[1] != '\0')
            palabras++;
        if (cad[i] == '\0')
            break;
    }
    return palabras;
}

main()
{
    char palabras[50];
    llenarCadena(palabras);
    cout << "La cadena ingresada es: " << palabras << endl;
    cout << "La longitud de la cadena es: " << longitudCadena(palabras) << endl;
    cout << "La cantidad de palabras es: " << contarPalabras(palabras) << endl;
}