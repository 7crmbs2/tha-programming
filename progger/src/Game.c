#include "Game.h"
#ifdef _WIN32
#include <Windows.h> //Sleep
#include <conio.h>	 //Nicht-blockierendes Einlesen
#else
#include <unistd.h>  //Sleep usleep();
//#include <ncurses.h>
#endif
#include "Player.h"
#include "Input.h"
#include "Scoreboard.h"
#include "Cursor.h"
Game* game_create()
{
	/* IHR CODE */
	return NULL;
}
void game_init(Game* game_ptr)
{
	/* IHR CODE */
}
void game_add_traffic(Game* game_ptr)
{
	/* IHR CODE */
}
void game_proceed(Game* game_ptr)
{
	/* IHR CODE */
}
void game_print(Game* game_ptr)
{
	/* IHR CODE */
}

void game_run(Game* game_ptr)
{
	game_print(game_ptr);
	while (game_ptr->scoreboard_ptr->lives > 0)
	{
		//Read input W,A,S,D
		input_read(game_ptr->input_ptr);
		//Update Traffic and Player
		game_proceed(game_ptr);
		//Add Traffic
		game_add_traffic(game_ptr);
		//Print Game
		game_print(game_ptr);
		//Check Player Position and Collision
		game_check(game_ptr);
		//Paus Main-Thread to slow down the game
		Sleep(GAME_TICK_DURATION_MS);
	}
	//Game Over
	console_leeren();				//Leere Terminal
	cursor_bewegen(2, 2);
	cursor_setze_farbe(HINTERGRUND_SCHWARZ);
	cursor_setze_farbe(CURSOR_GRUEN);
	printf("GAME OVER!");
	scoreboard_print(game_ptr->scoreboard_ptr);
}

void game_draw_border(Game* game_ptr)
{
	/* IHR CODE */
}

void game_check(Game* game_ptr)
{
	/* IHR CODE */
}
