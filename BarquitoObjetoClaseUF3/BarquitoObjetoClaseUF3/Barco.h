#pragma once
#include <iostream>
class Barco
{
private:

	int Velocidad;
	int Distancia;
	int Nitro;
	int Dado;
	int Ataque;
	int Atacado;
	std::string Nombre;

public:

	//getters
	int getVelocidad();
	int getDistancia();
	int getNitro();
	int getDado();
	int getAtaque();
	int getAtacado();
	std::string getNombre();
	
	void getAttributes();

	//setters
	void setVelocidad(int pVelocidad);
	void setDistancia(int pDistancia);
	void setNitro(int pNitro);
	void setNombre(std::string pNombre);
	void setDado(int pDado);
	void setAtaque(int pAtaque);
	void setAtacado(int pAtacado);

	//creadores
	Barco();
	Barco(int pVelocidad, int pDistancia, int pNitro, std::string pNombre);
};

