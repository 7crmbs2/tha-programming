#include "Deck.h"
//Aufgabe 2a
void Deck_init(Deck* d_ptr)
{
	// 7-9. Z (zehner) O, U, K, A
	getchar();
	char symbole[] = {'7','8','9','Z','U','O','K','A'};
	for (int i = 0; i <= 7; i++) {
		for (int j = 0; j < 4; j++) {
			switch (j) {
			case 0:
				d_ptr->stapel[i*j]->farbe = 'H';
				d_ptr->stapel[i*j]->symbol = symbole[i];
				break;
			case 1:
				d_ptr->stapel[i*j]->farbe = 'B';
				d_ptr->stapel[i*j]->symbol = symbole[i];
				break;
			case 2:
				d_ptr->stapel[i*j]->farbe = 'E';
				d_ptr->stapel[i*j]->symbol = symbole[i];
				break;
			case 3:
				d_ptr->stapel[i*j]->farbe = 'S';
				d_ptr->stapel[i*j]->symbol = symbole[i];
				break;
			}
		}
	}
}
//Aufgabe 2b
void Deck_mischen(Deck* d_ptr)
{
	int id1, id2;
	Karte* temp;
	for (int i = 0; i < 500; i++) {
		id1 = rand() % 32 + 1;
		id2 = rand() % 32 + 1;
		temp = d_ptr->stapel[id1];
		d_ptr->stapel[id1] = d_ptr->stapel[id2];
		d_ptr->stapel[id1] = temp;
	}
}
//Aufgabe 2c
void Deck_ausgeben(const Deck* d_ptr)
{
	for (int j = 0; j < 4; j++){
		for (int i = 0; i <= 8; i++) {
			Karte_ausgeben(d_ptr->stapel[i*j], 1 + i*5, 1+j*9);
		}
	}
}
