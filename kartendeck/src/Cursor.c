#include "Cursor.h"
#include <stdio.h>

//Positioniere Cursor an Position x,y
void cursor_bewegen(int x, int y)
{
	printf("\33[%d;%dH", y, x);	//Kommandos	\033[<L>; <C>H oder \033[<L>; <C>f
}

//Bewege den cursor um n Zeilen nach oben
void cursor_hoch(int n)
{
	printf("\033[%dA", n);
}
//Bewege den cursor um n Zeilen nach unten
void cursor_runter(int n)
{
	printf("\033[%dB", n);
}
//Bewege Cursor um n Stellen/Spalten nach rechts:  \033[<N>C
void cursor_rechts(int n)
{
	printf("\033[%dC", n);
}
//Bewege Cursor um n Stellen/Spalten nach links:  \033[<N>D
void cursor_links(int n)
{
	printf("\033[%dD", n);
}
//Setze Schriftfarbe oder Hintergrundfarbe
void cursor_setze_farbe(const char* farbe)
{
	printf("%s", farbe);
}

//Speichert die aktuelle Cursor Position
void cursor_speichere_position()
{
	printf("\033[s");
}
//Stellt die gespeicherte Cursor Position wieder her
void cursor_gehezu_letzte_gespeicherte_position()
{
	printf("\033[u");
};