#pragma once
#ifndef RECURSOS_H
#define RECURSOS_H

#include <iostream>
#include <ctime>
#include <cstdio>
#include <unistd.h>    // Para usar usleep
#include <termios.h>   // Para leer las teclas sin esperar a Enter
#include <sys/ioctl.h> // Para ocultar el cursor y limpiar pantalla
#include <cstdlib>     // Para usar rand y srand

using namespace std;

namespace apariencia
{

    const int IMAGEN_JUGADOR = 64;
    const int IMAGEN_ENEMIGO = 156;
    const int IMAGEN_ESPACIO_BLANCO = 32;
    const int IMAGEN_LLAVE = 170;
    const int IMAGEN_MURO = 178;
    const int IMAGEN_PUERTA = 178;
}

namespace objetos
{

    const char LLAVE_1 = 'K';
    const char LLAVE_2 = 'L';
    const char PUERTA_1 = 'P';
    const char PUERTA_2 = 'Q';
    const char MURO = 'X';
    const char JUGADOR = 'J';
    const char ENEMIGO = 'E';
    const char FINAL_NIVEL = 'F';
    const char ESPACIO_BLANCO = ' ';
}

namespace color
{

    // Colores ANSI
    const string NEGRO = "\033[0;30m";
    const string AZUL_OSCURO = "\033[0;34m";
    const string VERDE = "\033[0;32m";
    const string CELESTE = "\033[0;36m";
    const string ROJO = "\033[0;31m";
    const string VIOLETA = "\033[0;35m";
    const string AMARILLO = "\033[0;33m";
    const string BLANCO = "\033[0;37m";
    const string GRIS = "\033[1;30m";
    const string AZUL_CLARO = "\033[1;34m";
    const string SALMON = "\033[1;31m";
    const string CREMA = "\033[1;33m";
    const string RESET = "\033[0m"; // Resetear color
}

namespace pantalla
{

    void PosicionarXY(int posX, int posY)
    {
        cout << "\033[" << posY + 1 << ";" << posX + 1 << "H";
    }

    void espera(int miliseg)
    {
        usleep(miliseg * 1000); // usleep espera en microsegundos
    }

    void CambiarColor(const string &codigo_color)
    {
        cout << codigo_color;
    }

    void ocultarCursor(bool estado)
    {
        if (estado)
        {
            cout << "\033[?25l"; // Ocultar cursor
        }
        else
        {
            cout << "\033[?25h"; // Mostrar cursor
        }
    }

    void limpiarPantalla()
    {
        cout << "\033[2J\033[1;1H"; // Limpiar pantalla y posicionar cursor en (1,1)
    }
}

namespace teclado
{
    const int TECLA_A = 'a';
    const int TECLA_D = 'd';
    const int TECLA_W = 'w';
    const int TECLA_S = 's';
    const int TECLA_LEFT = 68;  // ASCII para la flecha izquierda en secuencias ANSI
    const int TECLA_RIGTH = 67; // ASCII para la flecha derecha en secuencias ANSI
    const int TECLA_UP = 65;    // ASCII para la flecha arriba en secuencias ANSI
    const int TECLA_DOWN = 66;  // ASCII para la flecha abajo en secuencias ANSI
    const int TECLA_ESC = 27;   // ASCII para la tecla ESC

    int leerTecla()
    {
        struct termios oldt, newt;
        int ch;
        tcgetattr(STDIN_FILENO, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &newt);
        ch = getchar();
        tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
        return ch;
    }

}

namespace logica
{

    int generarNumeroAleatorio(int min, int max)
    {
        srand(static_cast<unsigned int>(time(nullptr)));
        int random = min + rand() % ((max + 1) - min);
        return random;
    }
}

#endif // !RECURSOS_H
