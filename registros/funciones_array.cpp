#include <iostream>
using namespace std;
struct persona
{
    int id = 0;
    string nombre;
    int edad;
    bool casado = false;
};
void ingresarDatosRegistro(persona per[], int n)
{
    int i;
    char resp;
    for (i = 0; i < n; i++)
    {
        per[i].id = i + 1;
        cout << "Ingrese el nombre de la persona: ";
        cin.ignore();
        getline(cin,per[i].nombre);
        cout << "Ingrese la edad de la persona: ";
        cin >> per[i].edad;
        cout << "Es casado? <<S/N>>: ";
        cin.ignore();
        cin.get(resp);
        if (resp == 's' || resp == 'S')
            per[i].casado = true;
    }
}
void mostrarDatosRegistro(persona per[], int n)
{
    int i;
    cout << "ID\tNOMBRE\tEDAD\tCASADO" << endl;
    for (i = 0; i < n; i++)
    {
        cout << per[i].id << "\t";
        cout << per[i].nombre << "\t";
        cout << per[i].edad << "\t";
        (per[i].casado) ? cout << "SI" << endl : cout << "NO" << endl;
        // cout<<per[i].casado<<endl;
    }
}
persona buscarPersonaId(persona per[], int n, int id)
{
    int i;
    persona encontrada;
    for (i = 0; i < n; i++)
    {
        if (per[i].id == id)
        {
            encontrada = per[i];
            return encontrada;
        }
    }
    return encontrada;
}
persona buscarPersonaNombres(persona per[], int n, string nombres)
{
    int i,j=0,id;
    persona encontrados[10];
    persona encontrada;   
    for (i=0;i<n;i++){
            if(per[i].nombre.find(nombres)!=string::npos){
                encontrados[j]=per[i];
                j++;      
           }               
    }
    cout<<"Listado de personas encontradas: "<<j<<endl;
    for(i=0;i<j;i++){
        cout<<encontrados[i].id<<"\t";
        cout<<encontrados[i].nombre<<"\t";
        cout<<encontrados[i].edad<<"\t";
        (encontrados[i].casado) ? cout << "SI" << endl : cout << "NO" << endl;
    }
    cout<<"Ingrese el id de la persona que desea extraer: ";
    cin>>id;
    encontrada = buscarPersonaId(encontrados,(j+1),id);
    return encontrada;    
}
main()
{
    int np, id;
    string nombre;
    cout << "Ingrese la cantidad de personas: ";
    cin >> np;
    persona personas[np], encontrada;
    ingresarDatosRegistro(personas, np);
    mostrarDatosRegistro(personas, np);
    cout << "Ingrese nombre de la persona a buscar: ";
    cin.ignore();
    getline(cin,nombre);
   // encontrada = buscarPersonaId(personas, np, id);
    encontrada = buscarPersonaNombres(personas, np, nombre);

    if (encontrada.id == 0)
    {
        cout << "Persona no encontrada" << endl;
    }
    else
    {
        cout<<"Persona encontrada:\n";
        cout << "ID\tNOMBRE\tEDAD\tCASADO" << endl;
        cout << encontrada.id << "\t";
        cout << encontrada.nombre << "\t";
        cout << encontrada.edad << "\t";
        (encontrada.casado) ? cout << "SI" << endl : cout << "NO" << endl;
    }
}