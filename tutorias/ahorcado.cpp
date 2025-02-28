#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "../librerias/ahoracado.h"
using namespace std;
string palabraAleatoria(string palabras[]){
    srand(time(NULL));
    int numero = rand() % 5;
    return palabras[numero];
}
void humano(int intento){    
    switch(intento){
        case 1: 
            cout<<"   O   "<<endl;
            break;
        case 2:
            cout<<"   O   "<<endl;
            cout<<"   |   "<<endl;
            break;
        case 3:
            cout<<"   O   "<<endl;
            cout<<"   |   "<<endl;
            cout<<"  /    "<<endl;
            break;
        case 4:
            cout<<"   O   "<<endl;
            cout<<"   |   "<<endl;
            cout<<"  / \\   "<<endl;
            break;
        case 5:
            cout<<"   O   "<<endl;
            cout<<"   |   "<<endl;
            cout<<"  /|\\  "<<endl;
            break;
        case 6:
            cout<<"   O   "<<endl;        
            cout<<"  /|\\  "<<endl;
            cout<<"  /|    "<<endl;
            break;
        case 7:
            cout<<"   O   "<<endl;       
            cout<<"  /|\\  "<<endl;
            cout<<"  /|\\    "<<endl;
            break;       

    }    
    system("pause");    
}
void jugar(string palabraSeleccionada){    
     int longitud = palabraSeleccionada.length();
     string palabraOculta(longitud, '-');
     int intentos = 0;
     char letra;
     bool bandera;
     while (intentos < 7 && palabraOculta != palabraSeleccionada) {
        bandera=false;
        cout << "Palabra: " << palabraOculta << endl;
        cout << "Intentos restantes: " << 7 - intentos << endl;
        cout << "Ingresa una letra: ";
        cin.ignore();
        cin.get(letra);
        for (int i = 0; i < longitud; i++) {   
            if (palabraSeleccionada[i] == letra) {
                palabraOculta[i] = letra;
                bandera=true;
            }            
        }
        if(!bandera){
            intentos++;
            humano(intentos);
        } 
        system("cls");       
    }
    if (palabraOculta == palabraSeleccionada) {
        cout << "Felicidades, has adivinado la palabra: " << palabraOculta << endl;
    } else {    
        cout << "Lo siento, has agotado tus intentos. La palabra era: " << palabraSeleccionada << endl;
    }
}
int opciones(){
    int op;
    cout << "1. Deportes" << endl;
    cout <<"2. Animales" << endl;
    cout << "3. Frutas" << endl;
    cout <<"4. Paises" <<endl;
    cout<<"Esoja una opcion: ";
    cin >> op;
    return op;
}
main()
{
    string palabras[5],palabraSeleccionada;
    
    int op;
    cout << "Juego del Ahorcado" << endl;
    cout << "-------------------" << endl;
    cout<<"Elige una categoria: "<<endl;
    op = opciones();
    (op==1)? deportes(palabras): (op==2)? animales(palabras): (op==3)?frutas(palabras):paises(palabras);
    system("cls");
    palabraSeleccionada = palabraAleatoria(palabras);
    jugar(palabraSeleccionada);
}