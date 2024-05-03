#include "Barco.h"
#include <iostream>

Barco::Barco() {
	Velocidad = 0;
	Distancia = 0;
	Nitro = 1;
}


Barco::Barco(int pVelocidad, int pDistancia, int pNitro, std::string pNombre) {
	Velocidad = pVelocidad;
	Distancia = pDistancia;
	Nitro = pNitro;
	Nombre = pNombre;
}

//getters
int Barco::getVelocidad() {
	return Velocidad;
}

int Barco::getDistancia() {
	return Distancia;
}

int Barco::getNitro() {
	return Nitro;
}

int Barco::getDado() {
	return Dado;
}


std::string Barco::getNombre() {
	return Nombre;
}

int Barco::getAtaque() {
	return Ataque;
}

int Barco::getAtacado() {
	return Atacado;
}


void Barco::getAttributes() {
	std::cout << "Nombre: " << Nombre << "\nVelocidad: " << Velocidad << "\nDistancia hasta la meta: " << 100 - Distancia << "\nNitro: " << Nitro << "\n\n";
}

//setters
void Barco::setVelocidad(int pVelocidad) {
	Velocidad = pVelocidad;
}

void Barco::setDistancia(int pDistancia) {
	Distancia = pDistancia;
}

void Barco::setNitro(int pNitro) {
	Nitro = pNitro;
}

void Barco::setNombre(std::string pNombre) {
	Nombre = pNombre;
}

void Barco::setDado(int pDado) {
	Dado = pDado;
}

void Barco::setAtaque(int pAtaque) {
	Ataque = pAtaque;
}

void Barco::setAtacado(int pAtacado) {
	Atacado = pAtacado;
}
