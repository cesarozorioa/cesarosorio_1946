using namespace std;
#include <iostream>
main()
{
    int op;
    while (true)
    {
        do
        {
            cout << "Menu de Opciones" << endl;
            cout << "1. Abundantes" << endl;
            cout << "2. Deficientes" << endl;
            cout << "3. Amigos" << endl;
            cout << "4. Salir" << endl;
            cout << "Esoja una opción: ";
            cin >> op;
            if(op < 1 || op > 4){
                cout<<"Opcion no Valida\n";
                system("pause");
                system("cls");
            }            
            
        } while (op < 1 || op > 4);           
            
        switch (op)
        {
        case 1:
            cout << "Abundantes";
            break;
        case 2:
            cout << "Deficientes";
            break;
        case 3:
            cout << "Amigos";
            break;
        case 4:
            cout << "Saliendo del sistema";            
        }
        system("pause");
        system("cls");
        if(op==4)
            break;
    }
}