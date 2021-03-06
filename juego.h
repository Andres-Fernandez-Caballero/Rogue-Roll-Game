#pragma once
#ifndef JUEGO_H
#define JUEGO_H

#include "UI_Juego/Recursos.h"
#include "ControladorJuego.h"
#include "Modelos/Modelos.h"

using namespace accionesJuego;


namespace juego {

	unsigned long int clock = 0;

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
		case teclado::TECLA_ESC:
			juegoTernimando = true;
			break;
		}

		return juegoTernimando;
	}

	void IniciarJugador(std::string nombre, int imagen, int color) {
		int vidaMax = 3;

		jugador.nombre = nombre;
		jugador.apariencia.imagen = imagen;
		jugador.apariencia.color = color;
		jugador.vida = vidaMax;
	}

	void CargarRecursos(string vecMapa[LONG_VEC_MAP], char escenario[FILAS][COLUMNAS]) {
		accionesJuego::nivel_1(vecMapa);
		
		pantalla::ocultarCursor(true);

		IniciarJugador("Martin", apariencia::IMAGEN_JUGADOR, color::VERDE);

		accionesJuego::cargarEscenario(vecMapa, escenario, enemigos);
	}
	
	void PosicionarJugador() {
		mostrarObjetoPantalla(jugador.X, jugador.Y, jugador.apariencia.imagen, jugador.apariencia.color);
	}

	void MoverEnemigos(Personaje enemigos[12], char escenario[FILAS][COLUMNAS], int velocidadEnemigos) {
		if (clock % velocidadEnemigos == 0) {
			accionesJuego::moverEnemigos(enemigos, escenario);
		}
	}

	void Jugar() {
		string vecMapa[LONG_VEC_MAP];
		char escenario[FILAS][COLUMNAS];

		int velocidadEnemigos = 2000; //miliseg

		CargarRecursos(vecMapa, escenario);

		bool teclaEscOprimida = false;
		bool juegoTerminado = false;
		accionesJuego::DibujarEscenario(escenario);

		do {
			PosicionarJugador();
			MoverEnemigos(enemigos, escenario, velocidadEnemigos);
			teclaEscOprimida = RefrescarPantalla(escenario);
			juegoTerminado = controladorEventos(escenario, enemigos);
			clock++;
		} while (!teclaEscOprimida && !juegoTerminado);

		if (juegoTerminado && jugador.vida <= 0) {
			tableros::mostrarDerrota();
		}
		else if (teclaEscOprimida) {
			tableros::mostrarSalidaDelJuego();
		}
		else {
			tableros::mostrarVictoria();
		}
	}
}
#endif // !JUEGO_H
