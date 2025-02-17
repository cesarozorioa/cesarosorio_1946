#include <iostream>
using namespace std;

int main() {
	string cadena="informatica";
	//Borramos los caracteres de la cadena
	cadena.clear();
	cout << cadena; //No muestra nada
	//Volvemos a inicializar con un valor
	cadena="informatica";

	//Longitud de la cadena
	cout << "La cadena " << cadena << " tiene " << cadena.length() << " caracteres." <<     endl;

	//Primer y último carácter
	cout << "Primer caracter: " << cadena.front() << endl; //Igual que cadena[0]
	cout << "Último caracter: " << cadena.back() << endl; // Igual que cadena[[cadena.  length() - 1]]

	//Añadir cadenas
	cadena.append(" moderna"); //Es lo mismo que cadena += " moderna";
	cout << cadena << endl;

	//Añadimos un carácter
	char car='0';
	cadena.append(1,car);
	cout << cadena << endl;

	//Volvemos a inicializar con un valor
	cadena="informatica";

	//Buscar caracteres
	if(cadena.find("i")!=-1)
		cout << "posicion del primer carácter i: " << cadena.find("i") << endl;
	cout << "posicion del segundo  carácter i: " << cadena.find("i",1) << endl;

	//Extraer subcadenas
	string subcad;
	subcad=cadena.substr(2,3);
	cout << subcad << endl;
	subcad=cadena.substr(5);
	cout << subcad << endl;

	// Reemplazar parte de la cadena
	cout << cadena << endl;
	cadena.replace(6,3,"lat");	
	cout << cadena << endl;	
	return 0;
}