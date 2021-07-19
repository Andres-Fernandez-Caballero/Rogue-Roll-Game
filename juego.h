#pragma once
#ifndef JUEGO
#define JUEGO

/*
	inlcude
*/
#include "Recursos.h"
#include "MiJuego.h"
#include "VariablesEntorno.h"

using namespace Recursos;
using namespace variablesEntorno;
using namespace funcionesJuego;
// loop
namespace juego {
	
	
	void Inicializar() {
	
		
	}
	void CargarRecursos(Sprite enemigo, Sprite &jugador, string v[28],char escenario[FILAS][COLUMNAS]) {
		
		funcionesJuego::Nivel1(v);
		funcionesJuego::ConvertiraMatriz(v, escenario, jugador, enemigo);
		int a = 0;
	}
	bool Actualizar(char escenario[FILAS][COLUMNAS]) {
	
		bool salir = false;
		int tecla = 0;
		
		tecla = leerTecla();
		if (tecla != 0) {
			if (tecla == 27) {
				//controla la salida
				salir = true;
			}
			if (tecla == 97) MoverJugador(jugador, -1,0, escenario); //a							
			if (tecla == 100) MoverJugador(jugador, 1,0,escenario);	//d			
			if (tecla == 119) MoverJugador(jugador, 0,-1,escenario); //w
			if (tecla == 115) MoverJugador(jugador, 0, 1, escenario); //s
			if (tecla == 75) MoverJugador(jugador, -1, 0, escenario); //Izquierda							
			if (tecla == 77) MoverJugador(jugador, 1, 0, escenario);	//derecha			
			if (tecla == 72) MoverJugador(jugador, 0, -1, escenario); //arriba
			if (tecla == 80) MoverJugador(jugador, 0, 1, escenario); //abajo

		}
		//llamar Administrador
		salir=MIJUEGO::Administrador(escenario, jugador, enemigo);

		return salir;
		
	}
	void Dibujar(char escenario[FILAS][COLUMNAS],Sprite jugador) {
	
		CambiarCursor(false);
		
		
		PosicionarXY(jugador.X, jugador.Y);
		CambiarColor(2);
		printf("%c", jugador.icono);
		
	
	}
	void DescargarRecursos() {}
	void Terminar() {}
	void Jugar() {
		
		/*
		* programar nuestro loop
		*/
		
		string v[28];
		char escenario[FILAS][COLUMNAS];
		
		variablesEntorno::jugador.X = 10;
		variablesEntorno::jugador.Y = 10;
		variablesEntorno::jugador.icono = 64;

		variablesEntorno::enemigo.X = 45;
		variablesEntorno::enemigo.Y = 11;
		variablesEntorno::enemigo.icono = 169;
		


		Inicializar();
		CargarRecursos(enemigo, jugador, v, escenario);
		
				
		bool salir = false;
		funcionesJuego::DibujarEscenario(escenario);
		do {
			Dibujar(escenario, jugador);
			salir=Actualizar(escenario);
			variablesEntorno::cont += 1;
		} while (!salir);
		
		DescargarRecursos();
		Terminar();
	}
	
}
#endif // !"GAME"
