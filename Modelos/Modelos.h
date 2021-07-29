#pragma once
#ifndef MODELS_H
#define MODELS_H

#include <iostream>

struct Posicion {
	int x;
	int y;
};

struct Apariencia {
	int imagen = 0;
	int color = 0;
};

struct Personaje {
	std::string nombre = "";
	int X = 0;
	int Y = 0;
	Apariencia apariencia;
} jugador, enemigo;  //TODO: eliminar las variables globales


Personaje CrearJugador(
	std::string nombre,
	int posX,
	int posY,
	int imagen,
	int color
) {
	Personaje personaje;

	personaje.nombre = nombre;
	personaje.X = posX;
	personaje.Y = posY;
	personaje.apariencia.imagen = imagen;
	personaje.apariencia.color = color;

	return personaje;
}
	
extern int cont = 0; // esto tiene alguna relacion con la barra de vida ... corregir!!!

#endif // !MODELS_H

