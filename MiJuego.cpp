#include "MiJuego.h"

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

	void MoverPersonaje(Sprite& personaje, int x, int y) {
		// mueve el personaje a una posicion (x,y) indicada
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


		// Barra de juego
		PosicionarXY(2, 20);
		CambiarColor(7);
		printf("Posicion\n*************\n*    X:%d\n*    Y:%d\n*************", jugador.X, jugador.Y);
		printf("\n*************\nLlaves: %d", jugador.llaves);

		if (!ControlarPosicion(jugador, escenario)) {
			jugador.X = auxX;
			jugador.Y = auxY;
		}
	}

	void ConvertiraMatriz(std::string v[28], char escenario[FILAS][COLUMNAS], Sprite& jugador, Sprite& enemigo) {

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
							if ((int)escenario[i][j] == '2') { // llave
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
	void MoverEnemigo(Sprite& enemigo) {

		PosicionarXY(enemigo.X, enemigo.Y); // j son columnas(X) e i son filas osea (Y)
		CambiarColor(6);
		printf("%c", 169);
		CambiarColor(7);

		//static int direccion;

		int posYinicial = enemigo.Y;
		if (enemigo.Y == posYinicial)
		{
			//+
			//direccion = 1;
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
			recogerLlave(jugador);
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
			MoverEnemigo(enemigo);
			escenario[enemigo.Y][enemigo.X] = 'F';
		}
		return valido;
	}

	// mis metodos para el juego
	int getLlaves(Sprite& personaje) {
		return personaje.llaves;
	}

	void recogerLlave(Sprite& personaje) {
		personaje.llaves++;
	}
}