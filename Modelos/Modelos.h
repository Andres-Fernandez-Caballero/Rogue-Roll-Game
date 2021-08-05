#pragma once
#ifndef MODELS_H
#define MODELS_H

#include <iostream>


struct Apariencia {
	int imagen;
	int color;
	char objeto;
};

const int ADELANTE = 1;
const int ATRAS = -1;

struct Personaje {
	std::string nombre;
	int vida;
	int X;
	int Y;
	Apariencia apariencia;
	int direccionX; //ADELANTE = 1 | ATRAS = -1
	int direccionY; //ADELANTE = 1 | ATRAS = -1
} jugador; //variable global


#endif // !MODELS_H

