#pragma once
#ifndef JUEGO
#define JUEGO


#include "UI_Juego/Recursos.h"
#include "MiJuego.h"
#include "Modelos/Modelos.h"


using namespace funcionesJuego;


namespace juego {

	void CargarRecursos(Personaje enemigo, Personaje &jugador, string v[28],char escenario[FILAS][COLUMNAS]) {
		funcionesJuego::Nivel1(v);
		funcionesJuego::ConvertiraMatriz(v, escenario, jugador, enemigo);
		int a = 0;
	}

	bool Actualizar(char escenario[FILAS][COLUMNAS]) {
	
		bool salir = false;
		int tecla = 0;
		
		tecla = teclado::leerTecla();
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
		salir=MI_JUEGO_H::Administrador(escenario, jugador, enemigo);

		return salir;
	}

	void Dibujar(char escenario[FILAS][COLUMNAS],Personaje jugador) {
	
		pantalla::CambiarCursor(false);
			
		pantalla::PosicionarXY(jugador.X, jugador.Y);
		pantalla::CambiarColor(2);
		printf("%c", jugador.icono);
	}
	
	void Jugar() {	
		string v[28]; //esto es el la prepreentancion del mapa arreglarlo
		char escenario[FILAS][COLUMNAS];
		
		jugador.X = 10;
		jugador.Y = 10;
		jugador.icono = 64;

		enemigo.X = 45;
		enemigo.Y = 11;
		enemigo.icono = 169;
		
		CargarRecursos(enemigo, jugador, v, escenario);
				
		bool salir = false;
		funcionesJuego::DibujarEscenario(escenario);

		do {
			Dibujar(escenario, jugador);
			salir=Actualizar(escenario);
			cont += 1;
		} while (!salir);
	}
}
#endif // !"GAME"
