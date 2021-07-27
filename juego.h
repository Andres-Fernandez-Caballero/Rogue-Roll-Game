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
		//int tecla = 0;
		
		int tecla = teclado::leerTecla();
		
		switch (tecla) {
		case teclado::TECLA_A: 
			MoverJugador(jugador, -1, 0, escenario);
			break;
		case teclado::TECLA_D:
			MoverJugador(jugador, 1, 0, escenario);
			break;
		case teclado::TECLA_W:
			MoverJugador(jugador, 0, -1, escenario);
			break;
		case teclado::TECLA_S:
			MoverJugador(jugador, 0, 1, escenario);
			break;
		case teclado::TECLA_LEFT:
			MoverJugador(jugador, -1, 0, escenario);
			break;
		case teclado::TECLA_RIGTH:
			MoverJugador(jugador, 1, 0, escenario);
			break;
		case teclado::TECLA_UP:
			MoverJugador(jugador, 0, -1, escenario);
			break;
		case teclado::TECLA_DOWN:
			MoverJugador(jugador, 0, 1, escenario);
			break;
		default:
			salir = true;
			break;
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
