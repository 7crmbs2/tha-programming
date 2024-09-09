#include <stdio.h>
#include "Console.h"
#include "Cursor.h"


//Leere Bildschirm, verstecke Cursor, Position 0,0
void console_init()
{
	console_leeren();
	console_verstecken();
}
//Leere Terminal
void console_leeren()
{
	printf("\33[2J");
}
//Verstecke Cursor
void console_verstecken()
{
	printf("\33[?25l");
}
//Zeigt den Cursor
void console_zeigen()
{
	printf("\33[?25h");
}

//Gebe Zeichen c an Position x, y aus.
void console_zeichne_punkt(int x, int y, char c)
{
	//printf("\33[%d;%dH%c", y, x, c);
	cursor_bewegen(x, y);
	printf("%c", c);
}
//Zeichnet ein Rechteck mit dem angegebenen Symbol
void console_zeichne_rechteck(int xpos, int ypos, int x_size, int y_size, char symbol)
{
	for (int x = xpos; x < xpos + x_size; x++)
		for (int y = ypos; y < ypos + y_size; y++)
		{
			if ((x == xpos) || (x == xpos + x_size-1) || (y == ypos) || (y == ypos + y_size-1))
			{
				console_zeichne_punkt(x, y, symbol);
			}
		}
}

