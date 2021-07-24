//TODO: cambiar el nombre de la libreria a Models.h
#pragma once
#ifndef VARIABLESENTORNO
#define VARIABLESENTORNO


namespace variablesEntorno {

	struct Sprite { //TODO: cambiar el nombre de la estructura a Personaje
		int X;
		int Y;
		int icono;
	};

	Sprite jugador;
	Sprite enemigo;
	int cont = 0;
}
#endif // !VARIABLESENTORNO

