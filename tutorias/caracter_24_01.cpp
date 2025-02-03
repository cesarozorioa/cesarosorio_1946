#include <iostream>
#include <cstring>
using namespace std;
void ingresaCadena(char *cadena, int longitud){

    cout << "Ingrese una cadena de caracteres: ";
    cin.getline(cadena, longitud);
    cin.clear();

}
int longitudCadena(char cadena[]){
    int longitud = 0;
    while(cadena[longitud] != '\0'){
        longitud++;
    }
    return longitud;
}
void muestraCadena(char cadena[]){
    cout << "La cadena ingresada es: " << cadena << endl;
}
void formatoTitulo(char cadena[]){
    char caracter=178;
    for (int i=0;cadena[i]!=0;i++){
        if( cadena[i] == ' ' ){
            cadena[i+1] = cadena[i+1] - 32;          
        }else if( i==0 ){
            cadena[i] = cadena[i] - 32;
        }
    } 
    for(int i=1; i<=50;i++){

        cout<<caracter;
    }   
}
main()
{
    char cadena[100];
    ingresaCadena(cadena, 100);
    muestraCadena(cadena);
    cout << "La longitud de la cadena es: " << longitudCadena(cadena) << endl;
    cout << "La longitud de la cadena es : " << strlen(cadena) << endl;
    formatoTitulo(cadena);
    cout << "\nLa cadena con formato de titulo es: " << cadena << endl;
}