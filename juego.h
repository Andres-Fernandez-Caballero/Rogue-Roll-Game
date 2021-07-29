#pragma once
#ifndef JUEGO
#define JUEGO


#include "UI_Juego/Recursos.h"
#include "MiJuego.h"
#include "Modelos/Modelos.h"


using namespace funcionesJuego;

namespace juego {

	bool RefrescarPantalla(char escenario[FILAS][COLUMNAS]) {
	
		bool salir = false;
		
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
		salir=MI_JUEGO_H::Administrador(escenario, jugador, enemigo);

		return salir;
	}

	void IniciarJugador(int posX, int posY, int imagen, int color) {
		jugador.X = posX;
		jugador.Y = posY;
		jugador.apariencia.imagen = imagen;
		jugador.apariencia.color = color;
	}

	void CargarRecursos(Personaje enemigo, Personaje& jugador, string vecMapa[28], char escenario[FILAS][COLUMNAS]) {
		funcionesJuego::Nivel1(vecMapa);
		
		pantalla::ocultarCursor(true);

		IniciarJugador(10, 10, apariencia::IMAGEN_ARROBA, color::VERDE);

		enemigo.X = 45;
		enemigo.Y = 11;
		enemigo.apariencia.color = apariencia::IMAGEN_PIPA;

		funcionesJuego::ConvertiraMatriz(vecMapa, escenario, jugador, enemigo);
	}
	
	void PosicionarJugador(char escenario[FILAS][COLUMNAS], Personaje jugador) {
		pantalla::PosicionarXY(jugador.X, jugador.Y);
		pantalla::CambiarColor(jugador.apariencia.color);
		printf("%c", jugador.apariencia.imagen);
	}

	void Jugar() {
		string vecMapa[28];
		char escenario[FILAS][COLUMNAS];

		CargarRecursos(enemigo, jugador, vecMapa, escenario);

		bool salir = false;
		funcionesJuego::DibujarEscenario(escenario);

		do {

			PosicionarJugador(escenario, jugador);
			salir = RefrescarPantalla(escenario);
			cont += 1;
		} while (!salir);
	}
}
#endif // !"GAME"
