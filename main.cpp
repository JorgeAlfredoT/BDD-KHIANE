#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <cstdlib> // para "clear"
#include "principal.h"
#include"principal.cpp"
#include"index.h"
#include"index.cpp"
using namespace std;

namespace functionsSupport{
	void Menu(){
		cout << "\n\n" ;
		cout << "\t\t\t\tMENU PRINCIPAL" << endl;;
		cout << "\t\t 1.- Ingresar Datos " << endl;
		cout << "\t\t 2.- Eliminacion de un jugador. " << endl;
		cout << "\t\t 3.- Consultas e Informacion del jugador. " << endl;
		cout << "\t\t 4.- Modificaciones de Datos de un jugador del club. " << endl;
		cout << "\t\t 5.- Salir" << endl;
		cout << "\t\t 6.- Mostrar Lista de Jugadores " << endl;
		cout << "\n\t\telige una opcion -->  ";
	}

	void clear(){
		system("clear");
	}
}

void verificar_tipaje(int iop){
	if(cin.fail()){
		cout << "new iop: ";cin >> iop;
		verificar_tipaje(iop);
	}
	else{
		return;
	}
}


int main(){

	// vavriables a utilizarse en el desarrollo.
	int iclave;
	int iop, ij,a, encontrado, temp;
	char ope = 'n', cont = 'N';
	bool repeat = false, entro = false;

	ifstream salida_pri;
	ofstream entrada_pri;
	ifstream salida_ind;
	ofstream entrada_ind;

	Principal<int> jugador1, aux_pri;
	Index<int> ind, aux_ind;

	do{
		functionsSupport::clear();
		functionsSupport::Menu();
		bool ver = true;
		int cont = 0;
		do{
			cin.clear();
			if(cont > 0) cin.ignore(1024, '\n');
			cout << "introduce un numero: ";
			cout << cont << endl;
			cin >> iop;
			cont++;
			if( !cin.fail() ){
				ver = false;
			}
		}while( ver );

		switch(iop){
			case 1:
				functionsSupport::clear();
				entrada_pri.open("principal.txt",ios::out | ios::app);
				do{
					jugador1.pedirdatos();
					/////////////////////////////////////////////////////// -verifica si es que ya existe el registro--

					salida_ind.open("index.txt", ios::in);
					while(salida_ind.read( (char*) &aux_ind, sizeof(aux_ind)) ){ // MODIFIED HERE 1
						if( jugador1.getDni() == aux_ind.getIndex() ){
							repeat = true;
							break;
						}
					}
					salida_ind.close();

					///////////////////////////////////////////////////////

					if (!repeat){ // si no se repite el registro
						entrada_pri.write( (char*) &jugador1, sizeof(jugador1)); // llena tabla principal
					}
					entrada_pri.seekp(0, ios::end); // pone el cursor al final del archivo.
					int l = entrada_pri.tellp() / sizeof(jugador1); // la posicion actual

					////////////////////////////////////////////////////////////////////

					entrada_ind.open("index.txt", ios::out | ios::app);
					ind.setIndex(jugador1.getDni());
					ind.setPosition(l); //
					if (!repeat){ // si no se repite el registro
						entrada_ind.write( (char*)&ind, sizeof(ind) );//llena tabla index
					}
					entrada_ind.close();
					/////////////////////////////////////////////////////////////////

					repeat = false;
					cout << "\n\n\t\tDesea otro registro ?: ";
					cin >> ope;
					functionsSupport::clear();
				} while(toupper(ope) == 'S');
				entrada_pri.close();
				break;

			case 2:
				functionsSupport::clear();
				salida_pri.open("principal.txt", ios::in);
				entrada_pri.open("temp_pri.txt", ios::out | ios::app);
				salida_ind.open("index.txt", ios::in);
				entrada_ind.open("temp_ind.txt", ios::out | ios::app);


				cout << "introduzca el DNI del jugador a eliminar del club: "; cin>> iclave;

				while(salida_ind.read( (char*) &ind, sizeof(ind))){ // elimina ese campo // MODIFIED HERE 2
					if(ind.getIndex() != iclave)
						entrada_ind.write( (char*) &ind, sizeof(ind) );
				}

				while( salida_pri.read( (char*) &jugador1, sizeof(jugador1) ) ){// elimina ese campo // MODIFIED HERE 3
					if(jugador1.getDni() != iclave)
						entrada_pri.write( (char*) &jugador1,sizeof(jugador1) );
				}
				salida_pri.close();
				entrada_pri.close();
				salida_ind.close();
				entrada_ind.close();

				remove("principal.txt");
				rename("temp_pri.txt","principal.txt");
				remove("index.txt");
				rename("temp_ind.txt", "index.txt");
				break;

			case 3:
				functionsSupport::clear();
				salida_pri.open("principal.txt",ios::in);
				salida_ind.open("index.txt",ios::in);
				cout << "\n\t\tIntrodusca el DNI del jugador a consultar -->  ", cin >> iclave;

				while(salida_ind.read( (char*) &ind, sizeof(ind))){ // buscara el dni en la tabla index // MODIFIED HERE 4
					if(ind.getIndex() == iclave){
						encontrado = ind.getPosition();
						entro = true;

					}
				}
				if(entro){ // entra si es que existe la consulta
					a = encontrado - 1;
					salida_pri.seekg(sizeof(jugador1) * a, ios::beg ); // te lleva a ese registro
					salida_pri.read( (char*) &aux_pri , sizeof(aux_pri));
					aux_pri.consultas();
					cout << "\n\n\t\t\t\tContinuar (Caracter) -->  "; cin >> cont;

					salida_pri.close();
					salida_ind.close();
				}
				entro  = false;
				break;

			case 4:
				functionsSupport::clear();
				salida_pri.open("principal.txt",ios::in);
				entrada_pri.open("temp.txt" ,ios::out | ios::app );

				cout << "\n\t\tDNI del jugador a modificar -->  "; cin >> iclave;

				while(salida_pri.read( (char*) &jugador1, sizeof(jugador1) )){ // modifica la tabla principal // MODIFIED HERE 5
					if(jugador1.getDni() == iclave){
						jugador1.modificar();
						entrada_pri.write( (char*)& jugador1, sizeof(jugador1) );
					}
					else
						entrada_pri.write( (char*)& jugador1, sizeof(jugador1) );
				}
				salida_pri.close();
				entrada_pri.close();
				remove("principal.txt");
				rename("temp.txt","principal.txt");
				break;

			case 6:
				functionsSupport::clear();
				salida_pri.open("principal.txt", ios::in);
				while( salida_pri.read( (char*)&jugador1, sizeof(jugador1) )){ // MODIFIED HERE 6
					jugador1.datos_constantes();
				}
				cout << "\n\n\t\t\t\tContinuar (Caracter) -->  "; cin >> cont;
				salida_pri.close();
				break;

		}
	} while(iop != 5);
	functionsSupport::clear();


	return 0;
}
