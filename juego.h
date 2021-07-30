#pragma once
#ifndef JUEGO
#define JUEGO


#include "UI_Juego/Recursos.h"
#include "MiJuego.h"
#include "Modelos/Modelos.h"


using namespace accionesJugego;

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
		salir=MI_JUEGO_H::Administrador(escenario);

		return salir;
	}

	void IniciarJugador(std::string nombre, int posX, int posY, int imagen, int color) {
		jugador.nombre = nombre;
		jugador.X = posX;
		jugador.Y = posY;
		jugador.apariencia.imagen = imagen;
		jugador.apariencia.color = color;
		//jugador.llaves = 0;
	}

	void CargarRecursos(Personaje& jugador, string vecMapa[LONG_VEC_MAP], char escenario[FILAS][COLUMNAS]) {
		accionesJugego::Nivel1(vecMapa);
		
		pantalla::ocultarCursor(true);

		IniciarJugador("Martin", 1, 10, apariencia::IMAGEN_JUGADOR, color::VERDE);

		accionesJugego::ConvertiraMatriz(vecMapa, escenario);
	}
	
	void PosicionarJugador(char escenario[FILAS][COLUMNAS], Personaje jugador) {
		pantalla::PosicionarXY(jugador.X, jugador.Y);
		pantalla::CambiarColor(jugador.apariencia.color);
		printf("%c", jugador.apariencia.imagen);
	}

	void Jugar() {
		string vecMapa[LONG_VEC_MAP];
		char escenario[FILAS][COLUMNAS];

		CargarRecursos(jugador, vecMapa, escenario);

		bool salir = false;
		accionesJugego::DibujarEscenario(escenario);

		do {
			PosicionarJugador(escenario, jugador);
			salir = RefrescarPantalla(escenario);
			cont += 1;
		} while (!salir);
	}
}
#endif // !"GAME"
