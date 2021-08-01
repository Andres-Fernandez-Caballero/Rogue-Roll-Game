#pragma once
#ifndef CONTROLADOR_JUEGO_H
#define CONTROLADOR_JUEGO_H

#include "UI_Juego/Recursos.h"
#include "Modelos/Modelos.h"

const int LONG_VEC_MAP = 28;
const int FILAS = 28;
const int COLUMNAS = 104;

const int ADELANTE = 1;
const int ATRAS = -1;

namespace accionesJuego {

	int llavesTotales = 0;

	int enemigosTotales = 0;

	int direccionEnemigo = ADELANTE;

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
		
		if ( objeto == objetos::MURO ) {
			avanzar = false;
		}
		
		if(objeto == objetos::PUERTA && personaje.llaves < llavesTotales) {
			avanzar = false;

		}
		
		if(objeto == objetos::PUERTA && personaje.llaves == llavesTotales) {
			avanzar = true;
			limpiarPosicion(escenario, personaje.X, personaje.Y);
		}
		return avanzar;
	}

	void mostrarBarraJugador() {
		pantalla::PosicionarXY(0, 20);
		pantalla::CambiarColor(color::BLANCO);
		printf("--------------------------\n");
		printf("status\n");
		cout << "Nombre del Jugador: " << jugador.nombre << "\n";
		printf("Coordenadas\n");
		printf("X: %d\n", jugador.X);
		printf("Y: %d\n", jugador.Y);
		printf("LLaves: %d\n", jugador.llaves);
		printf("--------------------------\n");
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
		mostrarBarraJugador();

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
			
			enemigos[numero].X += direccionEnemigo * 1;
			enemigos[numero].Y += direccionEnemigo * 0;

			// si el personaje no puede avanzar recupera su posicion inicial
			if (!puedeAvanzar(enemigos[numero], escenario)) {
				enemigos[numero].X = initX;
				enemigos[numero].Y = initY;

				if (direccionEnemigo == ADELANTE) {
					direccionEnemigo = ATRAS;
				}
				else {
					direccionEnemigo = ADELANTE;
				}
			}
			else {
				limpiarPosicion(escenario, initX, initY);
				escribirObjetoEnEscenario(escenario, enemigos[numero].X, enemigos[numero].Y, objetos::ENEMIGO);
				mostrarObjetoPantalla(enemigos[numero].X, enemigos[numero].Y, enemigos[numero].apariencia.imagen, enemigos[numero].apariencia.color);
			}
		}
	}

	void Nivel1(string v[LONG_VEC_MAP]) {

		//******0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000111****//x
		//******0000000000111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999000****//x
		//******01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123***//x
		v[0] =  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//0
		v[1] =  "X                                          XXX          XXXXXXXX                            X           ";//1
		v[2] =  "X                        E          E             XXXX      P                               X           ";//2
		v[3] =  "X    X    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXDDXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//3
		v[4] =  "X    X    XX                                 X  XXX  XXX    X  X E                          X           ";//4
		v[5] =  "X    X  XXXX                                 XK X           X  X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//5
		v[6] =  "X    X  XXK                                  XXXX           X  X                            X           ";//6
		v[7] =  "X    XXXXXXXXXXXXXXXXXXXXXXXXXX                             X  XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//7
		v[8] =  "X                                      E                    X  X E                          X           ";//8
		v[9] =  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     X  X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//9
		v[10] = "XJ   XXXXX        XXXX                     E          X     X  X                            X           ";//10
		v[11] = "X                          E      XXXX                X     X  XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//11
		v[12] = "X                 XXXX                     E                X  X E                          X           ";//12
		v[13] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//13
		v[14] = "                                                               X                            X           ";//14
		v[15] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//15
		v[16] = "                                                               X E                          X           ";//16
		v[17] = "                                                               X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//17
		v[18] = "                                                               X                            X           ";//18
		v[19] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//19
		v[20] = "                                                               X E                          X           ";//20
		v[21] = "                                                               X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//21
		v[22] = "                                                               X                            X           ";//22
		v[23] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//23
		v[24] = "                                                               XF      E                    X           ";//24
		v[25] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//25
		v[26] = "                                                                                                        ";//26
		v[27] = "                                                                                                        ";//27
	}

	void cargarEscenario(string vecMapa[LONG_VEC_MAP], char escenario[FILAS][COLUMNAS], Personaje enemigos[12]) {
		for (int y = 0; y < FILAS; y++) {
			for (int x = 0; x < COLUMNAS; x++) {
				escenario[y][x] = vecMapa[y][x]; 

				char objeto = obtenerObjetoEnEscenario(escenario, x, y);
				
			
				switch (objeto) {
					case objetos::LLAVE:
						llavesTotales++;
						break;
					case objetos::ENEMIGO:

						enemigos[enemigosTotales].nombre = "Enemigo";
						enemigos[enemigosTotales].X = x;
						enemigos[enemigosTotales].Y = y;
						enemigos[enemigosTotales].apariencia.imagen = apariencia::IMAGEN_ENEMIGO;
						enemigos[enemigosTotales].apariencia.color = color::ROJO;
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
					case objetos::JUGADOR: 
						break;
					case objetos::LLAVE:
						mostrarObjetoPantalla(x, y, apariencia::IMAGEN_LLAVE, color::CELESTE);	
						break;
					case objetos::PUERTA:
						if (jugador.llaves == llavesTotales) {
							mostrarObjetoPantalla(x, y, apariencia::IMAGEN_ESPACIO_BLANCO, color::NEGRO);
							escribirObjetoEnEscenario(escenario, x, y, objetos::ESPACIO_BLANCO);
						}
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

	bool controladorEventos(char escenario[FILAS][COLUMNAS]) {
		
		//detectar colisiones y mover objetos en pantalla
		int valido = false;
		char objeto = obtenerObjetoEnEscenario(escenario, jugador.X, jugador.Y);
		
		switch (objeto) {
		
		case objetos::LLAVE:
			limpiarPosicion(escenario, jugador.X, jugador.Y);
			jugador.llaves++;
			break;
		case objetos::ENEMIGO:
			/* barra de combate */
			/*------------------*/
			pantalla::PosicionarXY(9, 20); // cartel en pantalla
			pantalla::CambiarColor(color::VERDE);
			printf("combate!");
			/*------------------*/
			jugador.vida--;
			limpiarPosicion(escenario, jugador.X, jugador.Y);
			break;
		case objetos::FINAL_NIVEL:
			pantalla::PosicionarXY(jugador.X, jugador.Y);
			pantalla::CambiarColor(color::AMARILLO);
			printf("Ganaste");
			pantalla::CambiarColor(color::BLANCO);
			valido = true;
			break;
		}
		return valido;
	}
}
#endif // !CONTROLADOR_JUEGO_H

