#pragma once
#ifndef MODELS_H
#define MODELS_H

#include <iostream>


struct Apariencia {
	int imagen;
	int color;
	char objeto;
};

struct Personaje {
	std::string nombre;
	int vida;
	int X;
	int Y;
	Apariencia apariencia;
	int llaves;
} jugador; //variable global

void recogerLlave(Personaje& personaje) {
	personaje.llaves++;
}

#endif // !MODELS_H

