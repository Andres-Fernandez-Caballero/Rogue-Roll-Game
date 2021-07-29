#pragma once
#ifndef MI_JUEGO_H
#define MI_JUEGO_H


#include "UI_Juego/Recursos.h"
#include "Modelos/Modelos.h"

const int FILAS = 27;
const int COLUMNAS = 104;

namespace funcionesJuego {

	char colision(Personaje& elemento, char escenario[FILAS][COLUMNAS]) {
		return escenario[jugador.Y][jugador.X];
	}
	
	bool ControlarPosicion(Personaje& jugador, char escenario[FILAS][COLUMNAS]) {
		bool validar = true;
		
		if (escenario[jugador.Y][jugador.X] == 'X' || escenario[jugador.Y][jugador.X] == 'P') {
			validar = false;
		}
		return validar;
	}

	void MoverJugador(Personaje& jugador, int velX, int velY, char escenario[FILAS][COLUMNAS]) {
		//guardo la posicion temporal
		int auxX = jugador.X;
		int auxY = jugador.Y;

		//borrar el anteropr				
		pantalla::PosicionarXY(jugador.X, jugador.Y);
		pantalla::CambiarColor(color::BLANCO);
		printf("%c", apariencia::IMAGEN_ESPACIO_BLANCO);
		jugador.X += velX;
		jugador.Y += velY;

		//Barra de posicion
		pantalla::PosicionarXY(2, 20);
		pantalla::CambiarColor(color::BLANCO);
		printf("(%d,%d)", jugador.Y, jugador.X);

		if (!ControlarPosicion(jugador, escenario)) {
			jugador.X = auxX;
			jugador.Y = auxY;
		}
	}

	void Nivel1(string v[28]) { //TODO: pasar el mapa a una libreria aparte
		//61 ancho
		//                111111111122222222223333333333444444444455555555556666666666777777777788888888889999999999
		//      01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
		v[0] =  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//0
		v[1] =  "X                                          XXX          XXXXXXXX                            X           ";//1
		v[2] =  "X                        O          O             XXXX      P                               X           ";//2
		v[3] =  "X    X    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXDDXXX  XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//3
		v[4] =  "X    X    XX                                 X  XXX  XXX    X  X O                          X           ";//4
		v[5] =  "X    X  XXXX                                 X2 X           X  X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//5
		v[6] =  "X    X  XX1                                  XXXX           X  X                            X           ";//6
		v[7] =  "X    XXXXXXXXXXXXXXXXXXXXXXXXXX                             X  XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//7
		v[8] =  "X                                      O                    X  X O                          X           ";//8
		v[9] =  "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     X  X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//9
		v[10] = "X?   XXXXX        XXXX                     O          X     X  X                            X           ";//10
		v[11] = "X                          O      XXXX                X     X  XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//11
		v[12] = "X                 XXXX                     O                X  X O                          X           ";//12
		v[13] = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX  X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//13
		v[14] = "                                                               X                            X           ";//14
		v[15] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//15
		v[16] = "                                                               X O                          X           ";//16
		v[17] = "                                                               X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//17
		v[18] = "                                                               X                            X           ";//18
		v[19] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//19
		v[20] = "                                                               X O                          X           ";//20
		v[21] = "                                                               X XXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//21
		v[22] = "                                                               X                            X           ";//22
		v[23] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXX X           ";//23
		v[24] = "                                                               XF      O                    X           ";//24
		v[25] = "                                                               XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX           ";//25
		v[26] = "                                                                                                        ";//26
		v[27] = "                                                                                                        ";//27
		//v[28] = "                                                                                                        ";
	}

	void ConvertiraMatriz(string v[28], char escenario[FILAS][COLUMNAS], Personaje& jugador, Personaje& enemigo) 
	{
		for (int i = 0; i < FILAS; i++) {
			for (int j = 0; j < COLUMNAS; j++) {
	
				escenario[i][j] = v[i][j]; // V no es una matriz
				
				if (escenario[i][j] == objetos::JUGADOR) {
					jugador.X = j;
					jugador.Y = i;
				}
				if (escenario[i][j] == 'f') {
					enemigo.X = j;
					enemigo.Y = i;
				}
			}
		}
	}

	void DibujarEscenario(char escenario[FILAS][COLUMNAS]) 
	{
		pantalla::CambiarColor(color::BLANCO);

		for (int y = 0; y < FILAS; y++) {
			for (int x = 0; x < COLUMNAS; x++) {
				
				char caracterDelMapa = escenario[y][x];

				switch (caracterDelMapa) {
					case objetos::MURO:
						pantalla::PosicionarXY(x, y); 
						printf("%c", apariencia::IMAGEN_MURO);
					break;

					case objetos::JUGADOR: 
					break;

					case objetos::LLAVE:
						pantalla::PosicionarXY(x, y); 
						pantalla::CambiarColor(color::CELESTE);
						printf("%c", apariencia::IMAGEN_LLAVE);
						pantalla::CambiarColor(color::BLANCO);
					break;

					case objetos::PUERTA:
						pantalla::PosicionarXY(x, y);
						pantalla::CambiarColor(color::AMARILLO);
						printf("%c", apariencia::IMAGEN_PUERTA);
						pantalla::CambiarColor(color::BLANCO);
					break;

					case objetos::ENEMIGO:
						pantalla::PosicionarXY(x, y);
						pantalla::CambiarColor(color::ROJO);
						printf("%c", apariencia::IMAGEN_ENEMIGO);
						pantalla::CambiarColor(color::BLANCO);
					break;

					default:
						pantalla::PosicionarXY(x, y);
						printf("%c", apariencia::IMAGEN_ESPACIO_BLANCO);
					break;
				}
				
			}
		}
	}

	void MoverEnemigo(Personaje& enemigo, int desplazamientoenY, int direccion) {

		pantalla::PosicionarXY(enemigo.X, enemigo.Y); // j son columnas(X) e i son filas osea (Y)
		pantalla::CambiarColor(6);
		printf("%c", 169);
		pantalla::CambiarColor(7);

		int posYinicial = enemigo.Y;
		if (enemigo.Y == posYinicial)
		{
			//+
			direccion = 1;
		}
	}

	bool Administrador(char escenario[FILAS][COLUMNAS], Personaje jugador, Personaje& enemigo) {
		
		//detectar colisiones y mover objetos en pantalla
		int valido = false;
		char objeto = colision(jugador, escenario);
		bool barraenergia = true;
		
		// TODO: Cambiar todos los if anidados por un switch
		if (objeto == '1') {
			barraenergia = false;
		}
		if (objeto == '2') {
			pantalla::PosicionarXY(jugador.X, jugador.Y);
			escenario[jugador.Y][jugador.X] = ' ';
			escenario[2][61] = ' ';
			pantalla::PosicionarXY(61, 2); // j son columnas(X) e i son filas osea (Y)
			pantalla::CambiarColor(6);
			printf("%c", 178);
			pantalla::CambiarColor(7);
		}
		if (objeto == 'O') {
			pantalla::PosicionarXY(jugador.X, jugador.Y);
			pantalla::CambiarColor(6);
			//printf("PUM");
			pantalla::CambiarColor(7);
		}
		if (objeto == 'M') {
			pantalla::PosicionarXY(jugador.X, jugador.Y);
			pantalla::CambiarColor(6);
			printf("Ganaste");
			pantalla::CambiarColor(7);
			valido = true;
		}
		if (cont % 1200 == 0 && barraenergia) {
			MoverEnemigo(enemigo, 5, 0);
			escenario[enemigo.Y][enemigo.X] = 'F';
		}
		return valido;
	}
}
#endif // !MI_JUEGO_H

