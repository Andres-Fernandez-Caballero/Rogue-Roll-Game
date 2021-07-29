#pragma once
#ifndef RECURSOS
#define RECURSOS


#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>


using namespace std;

namespace apariencia {
	
	const int IMAGEN_ARROBA = 64;
	const int IMAGEN_PIPA = 169;
	const int IMAGEN_ESPACIO_BLANCO = 32;
	const int IMAGEN_LLAVE = 35; // #
}

namespace color {

	const int NEGRO = 0;
	const int AZUL_OSCURO = 1;
	const int VERDE = 2;
	const int CELESTE = 3;
	const int ROJO = 4;
	const int VIOLETA = 5;
	const int AMARILLO = 6;
	const int BLANCO = 7;
	const int GRIS = 8;
	const int AZUL_CLARO = 9;
}

namespace pantalla {

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	void PosicionarXY(int col, int fila) {
		COORD coord{};
		coord.X = col;
		coord.Y = fila;
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);
	}

	void CambiarColor(int codigo_color) {
		WORD wColor;

		HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO csbi;

		//We use csbi for the wAttributes word. 
		if (GetConsoleScreenBufferInfo(hStdOut, &csbi))
		{
			//Mask out all but the background attribute, and add in the forgournd  color 
			wColor = (csbi.wAttributes & 0xF0) + (codigo_color & 0x0F);
			SetConsoleTextAttribute(hStdOut, wColor);
		}
	}

	//TODO: este metodo modifica la vista del cursor en la consola nombre alternativo "ocultarCursor" aparte solo se usa una vez en false
	void ocultarCursor(bool estado) {
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info{};
		info.dwSize = 100;
		info.bVisible = !estado;
		SetConsoleCursorInfo(consoleHandle, &info);
	}

	//TODO: esta funcion no se usa
	void cls() {
		HANDLE                     hStdOut;
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		DWORD                      count;
		DWORD                      cellCount;
		COORD                      homeCoords = { 0, 0 };

		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		if (hStdOut == INVALID_HANDLE_VALUE) return;

		// Get the number of cells in the current buffer
		if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
		cellCount = csbi.dwSize.X * csbi.dwSize.Y;

		// Fill the entire buffer with spaces 
		if (!FillConsoleOutputCharacter(
			hStdOut,
			(TCHAR)' ',
			cellCount,
			homeCoords,
			&count
		)) return;

		// Fill the entire buffer with the current colors and attributes
		if (!FillConsoleOutputAttribute(
			hStdOut,
			csbi.wAttributes,
			cellCount,
			homeCoords,
			&count
		)) return;

		// Move the cursor home
		SetConsoleCursorPosition(hStdOut, homeCoords);
	}
}

namespace teclado {
	
	const int TECLA_A = 97;
	const int TECLA_D = 100;
	const int TECLA_W = 119;
	const int TECLA_S = 115;
	const int TECLA_LEFT = 75;
	const int TECLA_RIGTH = 77;
	const int TECLA_UP = 72;
	const int TECLA_DOWN = 80;
	const int TECLA_ESC = 27;


	int leerTecla() {
		if (_kbhit()) {
			char l = _getch();
			int ascii = (int)l;
			return ascii;
		}
	}
}

namespace logica {
	//TODO: este metodo no se usa todavia
	void CambiarSemilla() {
		unsigned int seed = time(0);
		srand(seed);
	}


	// TODO: este metodo no se usa, cambiar el nombre por uno mas coherente...
	int Random_Int(int min, int max) {
		int random = min + rand() % ((max + 1) - min);
		return random;
	}
}
#endif // !RECURSOS

