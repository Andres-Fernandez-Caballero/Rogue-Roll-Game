#pragma once
#ifndef MI_JUEGO_H
#define MI_JUEGO_H


#include "UI_Juego/Recursos.h"
#include "Modelos/Modelos.h"

const int LONG_VEC_MAP = 28;
const int FILAS = 28;
const int COLUMNAS = 104;

namespace accionesJuego {

	int llavesTotales = 0;

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
		escribirObjetoEnEscenario(escenario, jugador.X, jugador.Y, objetos::ESPACIO_BLANCO);
		mostrarObjetoPantalla(jugador.X, jugador.Y, apariencia::IMAGEN_ESPACIO_BLANCO, color::NEGRO);
	}
	
	
	bool colicion(Personaje& jugador, char escenario[FILAS][COLUMNAS]) {
		bool avanzar = true;
		char objeto = obtenerObjetoEnEscenario(escenario, jugador.X, jugador.Y);
		
		if ( objeto == objetos::MURO ) {
			avanzar = false;
		}
		
		if(objeto == objetos::PUERTA && jugador.llaves < llavesTotales){
			avanzar = false;
		}else if(objeto == objetos::PUERTA && jugador.llaves == llavesTotales){
			avanzar = true;
			limpiarPosicion(escenario, jugador.X, jugador.Y);

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

	void MoverJugador(int velX, int velY, char escenario[FILAS][COLUMNAS]) {
		//guardo la posicion temporal
		int auxX = jugador.X;
		int auxY = jugador.Y;

		//borrar el anteropr
		mostrarObjetoPantalla(jugador.X, jugador.Y, apariencia::IMAGEN_ESPACIO_BLANCO, color::BLANCO);

		jugador.X += velX;
		jugador.Y += velY;

		//Barra de posicion
		mostrarBarraJugador();

		if (!colicion(jugador, escenario)) {
			jugador.X = auxX;
			jugador.Y = auxY;
		}
	}

	void Nivel1(string v[LONG_VEC_MAP]) { //TODO: pasar el mapa a una libreria aparte
		//61 ancho
		//                111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999
		//      01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
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

	void ConvertiraMatriz(string vecMapa[LONG_VEC_MAP], char escenario[FILAS][COLUMNAS]) {
		for (int y = 0; y < FILAS; y++) {
			for (int x = 0; x < COLUMNAS; x++) {
				escenario[y][x] = vecMapa[y][x]; 

				if (obtenerObjetoEnEscenario(escenario, x, y) == objetos::LLAVE) {
					llavesTotales++;
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

	void MoverEnemigo(Personaje& enemigo, int desplazamientoenY, int direccion) {

		pantalla::PosicionarXY(enemigo.X, enemigo.Y); // j son columnas(X) e i son filas osea (Y)
		pantalla::CambiarColor(color::ROJO);
		printf("%c", apariencia::IMAGEN_ENEMIGO);
		pantalla::CambiarColor(color::BLANCO);

		int posYinicial = enemigo.Y;
		if (enemigo.Y == posYinicial)
		{
			//+
			direccion = 1;
		}
	}

	bool Administrador(char escenario[FILAS][COLUMNAS]) {
		
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
			limpiarPosicion(escenario, jugador.X, jugador.Y);
			break;
		case objetos::PUERTA:
			if (jugador.llaves == llavesTotales) {
				escribirObjetoEnEscenario(escenario, jugador.X, jugador.Y, objetos::ESPACIO_BLANCO);
				limpiarPosicion(escenario, jugador.X, jugador.Y);
			}
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
#endif // !MI_JUEGO_H

