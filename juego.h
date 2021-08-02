#pragma once
#ifndef JUEGO_H
#define JUEGO_H

#include "UI_Juego/Recursos.h"
#include "ControladorJuego.h"
#include "Modelos/Modelos.h"

using namespace accionesJuego;

namespace juego {

	Personaje enemigos[12];

	bool RefrescarPantalla(char escenario[FILAS][COLUMNAS]) {
	
		bool juegoTernimando = false;
		
		int tecla = teclado::leerTecla();
		
		switch (tecla) {
		case teclado::TECLA_A: 
			MoverJugador(-1, 0, escenario);
			break;
		case teclado::TECLA_D:
			MoverJugador(1, 0, escenario);
			break;
		case teclado::TECLA_W:
			MoverJugador(0, -1, escenario);
			break;
		case teclado::TECLA_S:
			MoverJugador(0, 1, escenario);
			break;
		case teclado::TECLA_LEFT:
			MoverJugador(-1, 0, escenario);
			break;
		case teclado::TECLA_RIGTH:
			MoverJugador(1, 0, escenario);
			break;
		case teclado::TECLA_UP:
			MoverJugador(0, -1, escenario);
			break;
		case teclado::TECLA_DOWN:
			MoverJugador(0, 1, escenario);
			break;
		default:
			juegoTernimando = true;
			break;
		}
		juegoTernimando = controladorEventos(escenario, enemigos);

		return juegoTernimando;
	}

	void IniciarJugador(std::string nombre, int imagen, int color) {
		int vidaMax = 100;

		jugador.nombre = nombre;
		jugador.apariencia.imagen = imagen;
		jugador.apariencia.color = color;
		jugador.llaves = 0;
		jugador.vida = vidaMax;
	}

	void CargarRecursos(string vecMapa[LONG_VEC_MAP], char escenario[FILAS][COLUMNAS]) {
		accionesJuego::Nivel1(vecMapa);
		
		pantalla::ocultarCursor(true);

		IniciarJugador("Martin", apariencia::IMAGEN_JUGADOR, color::VERDE);

		accionesJuego::cargarEscenario(vecMapa, escenario, enemigos);
	}
	
	void PosicionarJugador() {
		mostrarObjetoPantalla(jugador.X, jugador.Y, jugador.apariencia.imagen, jugador.apariencia.color);
	}

	void Jugar() {
		string vecMapa[LONG_VEC_MAP];
		char escenario[FILAS][COLUMNAS];

		CargarRecursos(vecMapa, escenario);

		bool juegoTerminado = false;
		accionesJuego::DibujarEscenario(escenario);

		do {
			PosicionarJugador();
			juegoTerminado = RefrescarPantalla(escenario);
			moverEnemigos(enemigos, escenario);
			pantalla::espera(35);
		} while (!juegoTerminado);
	}
}
#endif // !JUEGO_H
