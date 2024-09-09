#ifndef KARTE_H
#define KARTE_H

#include <stdlib.h>
#include <stdio.h>
struct Karte
{
	char symbol;
	char farbe;
};
typedef struct Karte Karte;
Karte* Karte_erzeugen();
void Karte_setzen(Karte* k_ptr, char symbol, char farbe);
void Karte_ausgeben(const Karte* k_ptr, int x, int y);

#endif // !KARTE_H
