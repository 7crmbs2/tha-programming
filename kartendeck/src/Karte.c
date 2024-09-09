#include "Karte.h"
#include <string.h>

//Aufgabe 1a
Karte* Karte_erzeugen()
{
	Karte* address = malloc(sizeof(Karte));
	if (address == NULL) {
		printf("ACHTUNG – Kein Speicher!");
		return NULL;
	}
	return address;
}
//Aufgabe 1b
void Karte_setzen(Karte* k_ptr, char symbol, char farbe)
{
	k_ptr->symbol = symbol;
	k_ptr->farbe = farbe;
}
//Aufgabe 1c
void Karte_ausgeben(const Karte* k_ptr, int x, int y)
{
	//cursor_bewegen(x,y);
	console_zeichne_rechteck(x, y, 9, 7,'x');
	console_zeichne_punkt(x+1,y+1, k_ptr->symbol);
	console_zeichne_punkt(x+7,y+1, k_ptr->symbol);
	console_zeichne_punkt(x+1,y+5, k_ptr->symbol);
	console_zeichne_punkt(x+7,y+5, k_ptr->symbol);
	console_zeichne_punkt(x+4,y+3, k_ptr->farbe);
}
