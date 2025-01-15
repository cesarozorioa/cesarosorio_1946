#include <iostream>
#include <conio.h>

using namespace std;
main()
{
    bool entrar = true;
    char limpiar;
    int op,cantNumeros,contador,numero,nverificador,contverficador,suma;
    while (entrar){
        cout<<"Menu de Opciones "<<endl;
        cout<<"1. Numeros Abundantes"<<endl;
        cout<<"2. Numeros Deficientes"<<endl;
        cout<<"3. Numeros Amigos"<<endl;
        cout<<"4. Salir"<<endl;
        cout<<"Ingresa una opcion: ";
        cin>>op;
        if(op>0 && op <4){
            cout<<"Ingrese la cantidad de numeros ";
            cin>>cantNumeros;
            contador = 0;  
            nverificador = 2;          
       }
        switch(op){
            case 1 : 
                while (contador < cantNumeros){
                    
                    contverficador = 1;
                    suma=0;
                    while(contverficador < nverificador){
                        if(nverificador % contverficador==0){
                            suma = suma+contverficador;
                        }
                        contverficador++;
                    }
                    if(suma > nverificador){
                        cout<<"Abundante: "<<nverificador<<endl;
                        contador ++;
                    }
                    nverificador++;
                }
                break;
            case 2: 
                cout<<"Deficientes"<<endl;
                break;
            case 3: 
                cout<<"Amigo"<<endl;
                break;
            case 4:
                entrar = false;
                break;
            default :
                cout<<"Opción no valida"<<endl;
        }
       
        system("pause");        
        system("cls");

    }
}