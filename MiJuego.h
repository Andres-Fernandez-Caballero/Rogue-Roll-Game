#pragma once
#ifndef MIJUEGO
#define MIJUEGO

/*
* include
*/
#include "Recursos.h"
#include "VariablesEntorno.h"
const int FILAS = 27;
const int COLUMNAS = 104;
//const int IMAGEN_JUGADOR=


using namespace Recursos;
using namespace variablesEntorno;

//funciones del juegos
namespace funcionesJuego {
	char colision(Sprite& elemento, char escenario[FILAS][COLUMNAS]) {
		return escenario[jugador.Y][jugador.X];
	}
	
	bool ControlarPosicion(Sprite& jugador, char escenario[FILAS][COLUMNAS]) {
		bool validar = true;
		/*if (jugador.X < 1) {
			jugador.X = 1;
			validar = false;
		}
		if (jugador.X >= 119) {
			jugador.X = 118;
			validar = false;
		}
		if (jugador.Y <= 0) {
			jugador.Y = 1;
			validar = false;
		}
		if (jugador.Y >= 28) {
			jugador.Y = 27;
			validar = false;
		}*/
		if (escenario[jugador.Y][jugador.X] == 'X' || escenario[jugador.Y][jugador.X] == 'P') {
			validar = false;
		}


		return validar;
	}

	void MoverJugador(Sprite& jugador, int velX, int velY, char escenario[FILAS][COLUMNAS]) {
		//guardo la posicion temporal
		int auxX = jugador.X;
		int auxY = jugador.Y;

		//borrar el anteropr				
		PosicionarXY(jugador.X, jugador.Y);
		//printf("%c", 32);
		CambiarColor(7);
		printf("%c", 61);
		variablesEntorno::jugador.X += velX;
		variablesEntorno::jugador.Y += velY;


		// Barra de Posicion
		PosicionarXY(2, 20);
		CambiarColor(7);
		printf("Posicion\n*************\n*    X:%d\n*    Y:%d\n*************", jugador.X, jugador.Y);

		if (!ControlarPosicion(jugador, escenario)) {
			jugador.X = auxX;
			jugador.Y = auxY;
		}
	}

	void Nivel1(string v[28]) {
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

	void ConvertiraMatriz(string v[28], char escenario[FILAS][COLUMNAS], Sprite& jugador, Sprite& enemigo) {

		for (int i = 0; i < FILAS; i++) {
			for (int j = 0; j < COLUMNAS; j++) {
				escenario[i][j] = v[i][j]; // V no es una matriz
				if (escenario[i][j] == '?') {
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
		CambiarColor(7);
		for (int i = 0; i < FILAS; i++) {
			for (int j = 0; j < COLUMNAS; j++) {
				//comezamos a dibujar la pantalla
				if ((int)escenario[i][j] == 'X') {
					PosicionarXY(j, i); // j son columnas(X) e i son filas osea (Y)
					printf("%c", 178);
				}
				else {
					if ((int)escenario[i][j] == '?') {
						PosicionarXY(j, i); // j son columnas(X) e i son filas osea (Y)
						printf("%c", 176);
					}
					else {
						if ((int)escenario[i][j] == '1') {
							PosicionarXY(j, i); // j son columnas(X) e i son filas osea (Y)
							CambiarColor(3);
							printf("%c", 35);
							CambiarColor(7);
						}
						else {
							if ((int)escenario[i][j] == '2') {
								PosicionarXY(j, i); // j son columnas(X) e i son filas osea (Y)
								CambiarColor(3);
								printf("%c", 35);
								CambiarColor(7);
							}
							else {
								if ((int)escenario[i][j] == 'P') {
									PosicionarXY(j, i); // j son columnas(X) e i son filas osea (Y)
									CambiarColor(6);
									printf("%c", 178);
									CambiarColor(7);
								}
								else {
									if ((int)escenario[i][j] == 'O') {
										PosicionarXY(j, i); // j son columnas(X) e i son filas osea (Y)
										CambiarColor(6);
										printf("%c", 169);
										CambiarColor(7);
									}
									else {
										PosicionarXY(j, i); // j son columnas(X) e i son filas osea (Y)
										printf("%c", 32);
									}
								}
							}
						}
					}
				}
			}
		}
	}
	void MoverEnemigo(Sprite& enemigo, int desplazamientoenY, int direccion) {

		PosicionarXY(enemigo.X, enemigo.Y); // j son columnas(X) e i son filas osea (Y)
		CambiarColor(6);
		printf("%c", 169);
		CambiarColor(7);

		//static int direccion;

		int posYinicial = enemigo.Y;
		if (enemigo.Y == posYinicial)
		{
			//+
			direccion = 1;
		}
	}
	bool Administrador(char escenario[FILAS][COLUMNAS], Sprite jugador, Sprite& enemigo) {
		//detectar colisiones
			//mover objetos en pantalla
		int valido = false;
		char objeto = colision(jugador, escenario);
		bool barraenergia = true;
		if (objeto == '1') {
			barraenergia = false;
		}
		if (objeto == '2') {
			PosicionarXY(jugador.X, jugador.Y);
			escenario[jugador.Y][jugador.X] = ' ';
			escenario[2][61] = ' ';
			PosicionarXY(61, 2); // j son columnas(X) e i son filas osea (Y)
			CambiarColor(6);
			printf("%c", 178);
			CambiarColor(7);
		}
		if (objeto == 'O') {
			PosicionarXY(jugador.X, jugador.Y);
			CambiarColor(6);
			//printf("PUM");
			CambiarColor(7);
		}
		if (objeto == 'M') {
			PosicionarXY(jugador.X, jugador.Y);
			CambiarColor(6);
			printf("Ganaste");
			CambiarColor(7);
			valido = true;
		}
		if (variablesEntorno::cont % 1200 == 0 && barraenergia) {
			MoverEnemigo(enemigo, 5, 0);
			escenario[enemigo.Y][enemigo.X] = 'F';
		}
		return valido;
	}
}

#endif // !TATETI

