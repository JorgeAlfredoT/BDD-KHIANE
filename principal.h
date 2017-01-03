#ifndef PRINCIPAL_H
#define PRINCIPAL_H

template<typename type>
class Principal{
protected:
	type dni;
	char nombre[15];
	char posicion[12]; // posicion en la que juega el jugador
public:
	Principal();
	~Principal(){}

	type getDni()const;
	void datos_constantes();
	void pedirdatos();
	void modificar();
	void consultas();

};


#endif
