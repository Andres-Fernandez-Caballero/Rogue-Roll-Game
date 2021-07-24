#pragma once

#ifndef PERSONAJE_H
#define PERSONAJE_H

#include<string>
#include "../Apariencia/Apariencia.h";
#include "../Posicion/Posicion.h";

using namespace std;

struct Personaje {
	string name; // nombre del personaje
	Posicion posicion;
	Apariencia apariencia;
	int llaves;
};
#endif // !PERSONAJE_H
