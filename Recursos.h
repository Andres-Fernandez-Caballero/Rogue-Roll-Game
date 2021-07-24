#pragma once
#ifndef RECURSOS
#define RECURSOS


#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <stdio.h>


using namespace std;

namespace Recursos {

	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

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

	//TODO: este metodo modifica la vista del cursor en la consola nombre alternativo "ocultarCursor" aparte solo se usa una vez en false
	void CambiarCursor(bool estado) {
		HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_CURSOR_INFO info;
		info.dwSize = 100;
		info.bVisible = estado;
		SetConsoleCursorInfo(consoleHandle, &info);
	}

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

	void PosicionarXY(int col, int fila) {
		COORD coord;
		coord.X = col;
		coord.Y = fila;
		SetConsoleCursorPosition(
			GetStdHandle(STD_OUTPUT_HANDLE),
			coord
		);
	}

	int leerTecla() {
		if (_kbhit()) {
			char l= _getch();
			int ascii = (int)l;
			return ascii;
			/*
			* 27 ESC
			*/
		}
	}
}
#endif // !RECURSOS

