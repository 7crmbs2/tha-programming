#ifndef DECK_H
#define DECK_H
#include "Karte.h"

struct Deck
{
	Karte* stapel[32];
};
typedef struct Deck Deck;
void Deck_init(Deck* d_ptr);
void Deck_mischen(Deck* d_ptr);
void Deck_ausgeben(const Deck* d_ptr);


#endif 