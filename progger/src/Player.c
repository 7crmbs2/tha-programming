#include "Player.h"
#include "Configuration.h"
#include <stdlib.h>
#include "Cursor.h"
#include "Console.h"
#include <string.h>
// this import would be needed to do printf so that migth not be the correct approach
#include <stdio.h>

Player* player_create()
{
	Player* address;
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
	p_ptr->x = PLAYER_XPOS - STREET_OFFSET;
	p_ptr->y = PLAYER_YPOS;
	p_ptr->symbol = PLAYER_SYMBOL;
	strcpy(p_ptr->color, PLAYER_COLOR);
}

void player_print(Player* p_ptr)
{
	cursor_bewegen(p_ptr->x, p_ptr->y); // move the cursor to the correct coordinates
	cursor_setze_farbe(HINTERGRUND_SCHWARZ); // set background to black
	cursor_setze_farbe(p_ptr->color); // set cursor to player color
	printf("%c", p_ptr->symbol); // print player symbol
	cursor_setze_farbe(CURSOR_SCHWARZ); // set cursor to black
}

void player_move(Player* p_ptr, char direction)
{
	int speed = 1;

	cursor_setze_farbe(HINTERGRUND_SCHWARZ); // set background to black
	cursor_bewegen(p_ptr->x, p_ptr->y); // move the cursor to the correct coordinates
	printf(" ");

	if (direction == MOVE_UP) {
		p_ptr->y -= speed; // x -= 1 same as x = x - 1
	} else if (direction == MOVE_DOWN) {
		p_ptr->y += speed;
	} else if (direction == MOVE_RIGHT) {
		p_ptr->x += speed;
	} else if (direction == MOVE_LEFT) {
		p_ptr->x -= speed;
	}

	player_print(p_ptr);

}
char player_compare(Player* player1_ptr, Player* player2_ptr)
{
	if (player1_ptr->x == player2_ptr->x && player1_ptr->y == player2_ptr->y){
		return 1;
	}
	return 0;
}
