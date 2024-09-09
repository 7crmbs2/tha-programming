#include "Deck.h"
#include "Karte.h"
//#include "Karte.c"

//Aufgabe 3a+b
int main()
{
	Karte* karte = Karte_erzeugen();
	Karte_setzen(karte, '2', 'O');
	Karte_ausgeben(karte, 1, 1);
	printf("\n\n\n\n");

//	Deck* deck = malloc(sizeof(Deck));
//	printf("%c", deck->stapel[1]->farbe);
	// Deck_init(deck);
	// Deck_ausgeben(deck);

	getchar();
	return 0;
}
