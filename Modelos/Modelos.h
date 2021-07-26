#pragma once
#ifndef MODELS_H
#define MODELS_H


	struct Personaje {
		int X;
		int Y;
		int icono;
	};

	Personaje jugador;
	Personaje enemigo;
	int cont = 0; // esto tiene alguna relacion con la barra de vida ... corregir!!!

#endif // !MODELS_H

