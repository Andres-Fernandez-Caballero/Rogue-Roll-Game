#pragma once
#ifndef GAME
#define GAME

/*
	inlcude
*/
#include "Recursos.h"
#include "TaTeTi.h"
// loop

void Jugar() {
	
	/*
	* programar nuestro loop
	*/

	Inicializar();
	CargarRecursos();
	bool salir = false;
	do{
		Actualizar();
		Dibujar();
	} while (!salir);
	
	DescargarRecursos();
	Terminar();
}

void Inicializar() {}
void CargarRecursos() {}
void Actualizar() {}
void Dibujar() {}
void DescargarRecursos() {}
void Terminar() {}


#endif // !"GAME"
