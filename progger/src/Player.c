#include "Player.h"
#include "Configuration.h"
#include <stdlib.h>
#include"Cursor.h"
#include"Console.h"
#include <string.h>
// this import would be needed to do printf so that migth not be the correct approach
#include <stdio.h>

Player* player_create()
{
	Player *address;
	// dynamic memory allocation to runtime
	address = malloc(sizeof(Player));
	//malloc returns NULL pointer, if the allocation fails
	if (address == NULL)
	{
		printf("Fehler - Speicherallokierung nicht möglich\n");
		return NULL;
	}
	return address;
}

void player_init(Player* p_ptr)
{
	p_ptr->x = PLAYER_XPOS;
	p_ptr->y = PLAYER_YPOS;
	p_ptr->symbol = PLAYER_SYMBOL;
	strcpy(p_ptr->color, PLAYER_COLOR);
}

void player_print(Player* p_ptr) // TODO this doesnt seem done
{
	cursor_setze_farbe(HINTERGRUND_SCHWARZ); // set background to black
	cursor_setze_farbe(p_ptr->color); // set cursor to player color
	cursor_bewegen(p_ptr->x, p_ptr->y); // move the curser to the correct coordinates
	printf("%c", p_ptr->symbol); // print player symbol
	cursor_setze_farbe(CURSOR_SCHWARZ); // set curser to black
}

void player_move(Player* p_ptr, char direction)
{
	/* IHR CODE */
}
char player_compare(Player* player1_ptr, Player* player2_ptr)
{
	/* IHR CODE */
	return 0;
}
