#include <iostream>
using namespace std;
void deportes(string deportes[]){
    string deportesx[5] = {"futbol","tenis","baloncesto","voley","natacion"}; 
    for(int i=0;i<5;i++){
        deportes[i] = deportesx[i];
    }     
}
void animales(string animales[]){
    string animalesx[5] = {"perro","gato","conejo","tigre","leon"};
    for (int i = 0; i < 5; i++)
       animales[i] = animalesx[i];    
}
void frutas(string frutas[]){
    string frutasx[5] = {"manzana","naranja","pera","platano","uva"};
    for(int i=0;i<5;i++)
        frutas[i] = frutasx[i];
}
void paises(string paises[]){
    string paisesx[5]={"peru","ecuador","colombia","argentina","chile"};
    for(int i=0;i<5;i++){
        paises[i]=paisesx[i];
    }
}
