#include "Game.h"
#ifdef _WIN32
#include <Windows.h> //Sleep
#include <conio.h>	 //Nicht-blockierendes Einlesen
#else
#include <unistd.h>  //Sleep usleep();
#include <ncurses.h>
#endif
#include "Player.h"
#include "Input.h"
#include "Scoreboard.h"
#include "Cursor.h"

Game* game_create()
{
	Game *address;
	// dynamic memory allocation to runtime
	address = malloc(sizeof(Game));
	//malloc returns NULL pointer, if the allocation fails
	if (address == NULL)
	{
		printf("Fehler - Speicherallokierung nicht möglich\n");
		return NULL;
	}
	return address;
}




void game_init(Game* game_ptr)
{
	initscr();

	// create a street NUMBER_OF_STREETS times and put it into the game
	for (int i = 0; i < NUMBER_OF_STREETS; i++){
		short randColor = (rand() % 14) + 1; // we have 16 elements so 0-15 - not 0 because not black
		short randDir = rand() % 1; // set random direction for each street
		short randCar = (rand() % MAX_CAR_LENGTH) + 1; // set max car

		game_ptr->road[i] = street_create();
		street_init(game_ptr->road[i], PLAYGROUND_OFFSET_X, STREET_FIRST_Y+i, STREET_OFFSET, hpallette[randColor], randDir);
		street_add_car(game_ptr->road[i], randCar);
	}
	game_ptr->player_ptr = player_create();
	player_init(game_ptr->player_ptr);
	player_print(game_ptr->player_ptr);

	game_ptr->scoreboard_ptr = scoreboard_create();
	scoreboard_init(game_ptr->scoreboard_ptr);
	scoreboard_print(game_ptr->scoreboard_ptr);

	game_ptr->destination_ptr = player_create();
	player_init(game_ptr->destination_ptr);
	game_ptr->destination_ptr->symbol = '*';
	game_ptr->destination_ptr->y = STREET_FIRST_Y - 2;
	player_print(game_ptr->destination_ptr);

	game_ptr->input_ptr = input_create();

	console_zeichne_rechteck(0, 0, 50, 50, hpallette[12]);

	game_ptr->run = 1;

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
		//Pause Main-Thread to slow down the game
		sleep(GAME_TICK_DURATION_MS);
	}
	//Game Over
	console_leeren();				//Leere Terminal
	cursor_bewegen(2, 2);
	cursor_setze_farbe(HINTERGRUND_SCHWARZ);
	cursor_setze_farbe(CURSOR_GRUEN);
	printf("GAME OVER!");
	scoreboard_print(game_ptr->scoreboard_ptr);

	//TODO my code, maybe remove this later
	/*
	getchar();
	endwin();
	*/
}

void game_draw_border(Game* game_ptr)
{
	/* IHR CODE */
}

void game_check(Game* game_ptr)
{
	/* IHR CODE */
}
