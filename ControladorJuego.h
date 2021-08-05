#pragma once
#ifndef CONTROLADOR_JUEGO_H
#define CONTROLADOR_JUEGO_H

#include "UI_Juego/Recursos.h"
#include "Modelos/Modelos.h"
#include<string>

const int LONG_VEC_MAP = 28;
const int FILAS = 28;
const int COLUMNAS = 104;

namespace tableros {
	void mostrarBarraJugador() {
		pantalla::PosicionarXY(0, 20);
		pantalla::CambiarColor(color::BLANCO);
		printf("--------------------------\n");
		printf("Jugador\n");
		cout << "Nombre del Jugador: " << jugador.nombre << "\n";
		printf("Vida: %d\n", jugador.vida);
		printf("Coordenadas\n");
		printf("X: %d\n", jugador.X);
		printf("Y: %d\n", jugador.Y);
		printf("--------------------------\n");
	}

	void mostrarAlerta(std::string mensaje, int color) {
		pantalla::PosicionarXY(9, 20); // cartel en pantalla
		pantalla::CambiarColor(color);
		cout << mensaje;
		pantalla::espera(1000); // pauso el programa durante un segundo para que sea evidente la accion
	}

	void mostrarVictoria() {
		//pantalla::limpiarPantalla();
		system("cls");
		pantalla::PosicionarXY(35, 10);
		pantalla::CambiarColor(color::AMARILLO);
		printf("***********************\n");
		pantalla::PosicionarXY(35, 11);
		printf("******* Ganaste *******\n");
		pantalla::PosicionarXY(35, 12);
		printf("***********************\n");
		pantalla::espera(1500); //1,5 seg
	}

	void mostrarDerrota() {
		//pantalla::limpiarPantalla();
		system("cls");
		pantalla::PosicionarXY(35, 10);
		pantalla::CambiarColor(color::ROJO);
		printf("************************\n");
		pantalla::PosicionarXY(35, 11);
		printf("******* PERDISTE *******\n");
		pantalla::PosicionarXY(35, 12);
		printf("************************\n");
		pantalla::espera(1500); //1,5 seg
	}

	void mostrarSalidaDelJuego() {
		//pantalla::limpiarPantalla();
		system("cls");
		pantalla::PosicionarXY(35, 10);
		pantalla::CambiarColor(color::AZUL_CLARO);
		printf("*********************\n");
		pantalla::PosicionarXY(35, 11);
		printf("******* ADIOS *******\n");
		pantalla::PosicionarXY(35, 12);
		printf("*********************\n");
		pantalla::espera(1500); //1,5 seg
	}
}

namespace accionesJuego {

	int enemigosTotales = 0;

	void nivel_1(string v[LONG_VEC_MAP]) {

		//******0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111****//x
		//******0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999000****//x
		//******01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123***//x
		 v[0] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//0
		 v[1] = "X                                    E     XXX          XXXXXXXX                            X           ";//1
		 v[2] = "X                        E                        XXXX      Q                               X           ";//2
		 v[3] = "X    X    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXPPXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX   X           ";//3
		 v[4] = "X    X    XX                                 X  XXX  XXX    X  X E                          X           ";//4
		 v[5] = "X    X  XXXX                                 XL X           X  X   XXXXXXXXXXXXXXXXXXXXXXXXXX           ";//5
		 v[6] = "X    X  XXK                                  XXXX           X  X                            X           ";//6
		 v[7] = "X    XXXXXXXXXXXXXXXXXXXXXXXXXX                             X  XXXXXXXXXXXXXXXXXXXXXXXXXX   X           ";//7
		 v[8] = "X                                      E                    X  X E                          X           ";//8
		 v[9] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     X  X   XXXXXXXXXXXXXXXXXXXXXXXXXX           ";//9
		v[10] = "XJ   XXXXX        XXXX                     E          X     X  X                            X           ";//10
		v[11] = "X                          E      XXXX                X     X  XXXXXXXXXXXXXXXXXXXXXXXXXX   X           ";//11
		v[12] = "X                 XXXX                     E                X  X E                          X           ";//12
		v[13] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X   XXXXXXXXXXXXXXXXXXXXXXXXXX           ";//13
		v[14] = "                                                               X                            X           ";//14
		v[15] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXX   X           ";//15
		v[16] = "                                                               X E                          X           ";//16
		v[17] = "                                                               X   XXXXXXXXXXXXXXXXXXXXXXXXXX           ";//17
		v[18] = "                                                               X                            X           ";//18
		v[19] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXX   X           ";//19
		v[20] = "                                                               X E                          X           ";//20
		v[21] = "                                                               X   XXXXXXXXXXXXXXXXXXXXXXXXXX           ";//21
		v[22] = "                                                               X        E                   X           ";//22
		v[23] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXX   X           ";//23
		v[24] = "                                                               XF                           X           ";//24
		v[25] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//25
		v[26] = "                                                                                                        ";//26
		v[27] = "                                                                                                        ";//27
	}

	char obtenerObjetoEnEscenario(char escenario[FILAS][COLUMNAS],int posX, int posY) {
		return escenario[posY][posX];
	}

	void escribirObjetoEnEscenario(char escenario[FILAS][COLUMNAS], int posX, int posY, char objeto) {
		escenario[posY][posX] = objeto;
	}

	void mostrarObjetoPantalla(int posX, int posY, int imagen, int color) {
		pantalla::PosicionarXY(posX, posY);
		pantalla::CambiarColor(color);
		printf("%c", imagen);
	}

	void limpiarPosicion(char escenario[FILAS][COLUMNAS], int posX, int posY) {
		escribirObjetoEnEscenario(escenario, posX, posY, objetos::ESPACIO_BLANCO);
		mostrarObjetoPantalla(posX, posY, apariencia::IMAGEN_ESPACIO_BLANCO, color::NEGRO);
	}
	
	bool puedeAvanzar(Personaje& personaje, char escenario[FILAS][COLUMNAS]) {
		bool avanzar = true;
		char objeto = obtenerObjetoEnEscenario(escenario, personaje.X, personaje.Y);
		
		if ( objeto == objetos::MURO || objeto == objetos::PUERTA_1 || objeto == objetos::PUERTA_2) {
			avanzar = false;
		}
		
		return avanzar;
	}

	void MoverJugador(int posX, int posY, char escenario[FILAS][COLUMNAS]) {
		// posicion inicial
		int auxX = jugador.X;
		int auxY = jugador.Y;

		//borrar la posicion anterior
		mostrarObjetoPantalla(jugador.X, jugador.Y, apariencia::IMAGEN_ESPACIO_BLANCO, color::BLANCO);
		
		// nueva posicion
		jugador.X += posX;
		jugador.Y += posY;

		//Barra de posicion
		tableros::mostrarBarraJugador();

		// si el personaje no puede avanzar recupera su posicion inicial
		if (!puedeAvanzar(jugador, escenario)) {
			jugador.X = auxX;
			jugador.Y = auxY;
		}
	}

	void moverEnemigos(Personaje enemigos[12], char escenario[FILAS][COLUMNAS]) {
		for (int numero = 0; numero < enemigosTotales; numero++) {
			//posicion inicial
			int initX = enemigos[numero].X;
			int initY = enemigos[numero].Y;

			enemigos[numero].X += enemigos[numero].direccionX * 1;
			enemigos[numero].Y += enemigos[numero].direccionY * 0;

			// si el personaje no puede avanzar recupera su posicion inicial
			if (!puedeAvanzar(enemigos[numero], escenario)) {
				enemigos[numero].X = initX;
				enemigos[numero].Y = initY;

				if (enemigos[numero].direccionX == ADELANTE) {
					enemigos[numero].direccionX = ATRAS;
				}
				else {
					enemigos[numero].direccionX = ADELANTE;
				}
			}
			else {

				limpiarPosicion(escenario, initX, initY);
				escribirObjetoEnEscenario(escenario, enemigos[numero].X, enemigos[numero].Y, enemigos[numero].apariencia.objeto);
				mostrarObjetoPantalla(enemigos[numero].X, enemigos[numero].Y, enemigos[numero].apariencia.imagen, enemigos[numero].apariencia.color);
			}
		}
	}

	void eliminar_Enemigo(Personaje enemigos[12], int posX, int posY) {

		for (int numeroEnemigo = 0; numeroEnemigo < enemigosTotales; numeroEnemigo++) {
		
			if (enemigos[numeroEnemigo].X == posX && enemigos[numeroEnemigo].Y == posY) {
				enemigos[numeroEnemigo].apariencia.imagen = apariencia::IMAGEN_ESPACIO_BLANCO;
				enemigos[numeroEnemigo].apariencia.color = color::NEGRO;
				enemigos[numeroEnemigo].apariencia.objeto = objetos::ESPACIO_BLANCO;
			}
		}

	}

	// carga el escenario al inicio del programa con el mapa, tambien carga los enemigos y las llaves totales
	void cargarEscenario(string vecMapa[LONG_VEC_MAP], char escenario[FILAS][COLUMNAS], Personaje enemigos[12]) {
		for (int y = 0; y < FILAS; y++) {
			for (int x = 0; x < COLUMNAS; x++) {
				escenario[y][x] = vecMapa[y][x]; 

				char objeto = obtenerObjetoEnEscenario(escenario, x, y);
				
				switch (objeto) {
					case objetos::JUGADOR: 
						jugador.X = x;
						jugador.Y = y;
						break;
					case objetos::ENEMIGO:

						enemigos[enemigosTotales].nombre = "Enemigo";
						enemigos[enemigosTotales].X = x;
						enemigos[enemigosTotales].Y = y;
						enemigos[enemigosTotales].apariencia.imagen = apariencia::IMAGEN_ENEMIGO;
						enemigos[enemigosTotales].apariencia.color = color::ROJO;
						enemigos[enemigosTotales].apariencia.objeto = objetos::ENEMIGO;
						
						int direccion;
						do {
							direccion = logica::generarNumeroAleatorio(-1, 1);
							enemigos[enemigosTotales].direccionX = direccion;
							enemigos[enemigosTotales].direccionY = 0;
						} while (direccion == 0);
						
						enemigosTotales++;
						break;
				}
			}
		}
	}

	void DibujarEscenario(char escenario[FILAS][COLUMNAS]) {
		pantalla::CambiarColor(color::BLANCO);

		for (int y = 0; y < FILAS; y++) {
			for (int x = 0; x < COLUMNAS; x++) {
				
				char caracterDelMapa = obtenerObjetoEnEscenario(escenario, x, y);

				switch (caracterDelMapa) {
					case objetos::MURO:
						mostrarObjetoPantalla(x, y, apariencia::IMAGEN_MURO, color::GRIS);
						break;
					case objetos::LLAVE_1:
						mostrarObjetoPantalla(x, y, apariencia::IMAGEN_LLAVE, color::CELESTE);	
						break;
					case objetos::PUERTA_1:
						mostrarObjetoPantalla(x, y, apariencia::IMAGEN_PUERTA, color::AMARILLO);
						break;
					case objetos::LLAVE_2:
						mostrarObjetoPantalla(x, y, apariencia::IMAGEN_LLAVE, color::CELESTE);
						break;
					case objetos::PUERTA_2:
						mostrarObjetoPantalla(x, y, apariencia::IMAGEN_PUERTA, color::AMARILLO);
						break;
					case objetos::ENEMIGO:
						mostrarObjetoPantalla(x, y, apariencia::IMAGEN_ENEMIGO, color::ROJO);
						break;
					default:
						mostrarObjetoPantalla(x, y, apariencia::IMAGEN_ESPACIO_BLANCO, color::NEGRO);
						break;
				}
			}
		}
	}

	void abrirPuerta(char escenario[FILAS][COLUMNAS], char puerta) {
		for (int y = 0; y < FILAS; y++) {
			for (int x = 0; x < COLUMNAS; x++)
			{
				char objeto = obtenerObjetoEnEscenario(escenario, x, y);
				if (objeto == puerta) {
					limpiarPosicion(escenario, x, y);
				}
			}
		}
		
	}

	bool controladorEventos(char escenario[FILAS][COLUMNAS], Personaje enemigos[12]) {
		
		int juegoTerminado = false;
		char objeto = obtenerObjetoEnEscenario(escenario, jugador.X, jugador.Y);
		
		switch (objeto) {
		
		case objetos::LLAVE_1:
			limpiarPosicion(escenario, jugador.X, jugador.Y);
			tableros::mostrarAlerta("Puerta Abierta", color::VERDE);
			abrirPuerta(escenario, objetos::PUERTA_1);
			break;
		case objetos::LLAVE_2:
			limpiarPosicion(escenario, jugador.X, jugador.Y);
			tableros::mostrarAlerta("Puerta Abierta", color::VERDE);
			abrirPuerta(escenario, objetos::PUERTA_2);
			break;
		case objetos::ENEMIGO:
			tableros::mostrarAlerta("Combate", color::SALMON);
			jugador.vida--;
			if (jugador.vida <= 0) {
				juegoTerminado = true;
			}
			eliminar_Enemigo(enemigos, jugador.X, jugador.Y);
			limpiarPosicion(escenario, jugador.X, jugador.Y);

			break;
		case objetos::FINAL_NIVEL:
			juegoTerminado = true;
			break;
		}
		return juegoTerminado;
	}
}
#endif // !CONTROLADOR_JUEGO_H

