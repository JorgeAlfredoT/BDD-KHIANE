#include <iostream>
#include <cstring>
#include <cstdlib> // para atoi atof
#include "principal.h"
using namespace std;

template<typename type>
Principal<type>::Principal(){
	dni = 0;
	strcpy(nombre,"\0");
	strcpy(posicion,"\0");
}

template<typename type>
type Principal<type>::getDni()const{
	return dni;
}

template<typename type>
void Principal<type>::datos_constantes(){
	cout << "\n";
	cout << "\t\tDNI del jugador: " << dni << endl;
	cout << "\t\tnombre del jugador: " << nombre << endl;
	cout << "\t\tPosicion del jugador: " << posicion << "\n\n" <<endl;
}

template<typename type>
void Principal<type>::pedirdatos(){
	//system("clear");
	cout << "\t\t\tIngrese datos del fichaje del jugador:\n " << endl;
	//datos_constantes();

	cout << "\t\tDNI: "; cin >> dni ;
	cout << "\t\tNombre: "; cin >> nombre;
 	cout << "\t\tPosicion: "; cin >> posicion;
}

template<typename type>
void Principal<type>::modificar(){
	//system("clear");
	char nombrem[15];
	char posicionm[12];
	char dnim[3];

	cout << "\n\t\t\tMODIFICACION DEL FICHAJE \n";
	datos_constantes();

	cout << "\n\t\tNuevo nombre: "; cin >> nombrem;
	cout << "\t\tNueva Posicion "; cin >> posicionm;
	cout << "\t\tConfirme el DNI para modificar: "; cin>> dnim;

	if(dnim[0] != '\0')
		dni = atoi(dnim);

	if(nombrem[0] != '\0'){
		//strcpy(nombre,"?");
		strcpy(nombre,nombrem);
	}
	if(posicionm[0] != '\0')
		strcpy(posicion,posicionm);
}

template<typename type>
void Principal<type>::consultas(){
	cout << "\n\t\t\tCONSULTAS DE UN JUGADOR DE EL CLUB \n";
	datos_constantes();
}
