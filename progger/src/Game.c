#include "Game.h"
#include <unistd.h>  //Sleep usleep();
#include <ncurses.h>
#include "Player.h"
#include "Input.h"
#include "Scoreboard.h"
#include "Cursor.h"

Game* game_create()
{
	Game* address;
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
	// create a street NUMBER_OF_STREETS times and put it into the game
	for (int i = 0; i < NUMBER_OF_STREETS; i++){
		int randColor = (rand() % 15) + 1; // we have 16 elements so 0-15 - not 0 because not black
		int randCar = (rand() % MAX_CAR_LENGTH) + 1; // set max car length
		char randDir = rand() % 2; // set random direction for each street

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

	// draw a rectangle as game field
	game_draw_border(game_ptr);

	game_ptr->run = 1;
}

void game_add_traffic(Game* game_ptr)
{
	for (int i = 0; i < NUMBER_OF_STREETS; i++){
		if ((rand()%100)+1 <= TRAFFIC_PROBABILITY){
			short randCar = (rand() % MAX_CAR_LENGTH) + 1; // set max car length
			street_add_car(game_ptr->road[i], randCar); // add the car to the road if possible
		}
	}
}

void game_proceed(Game* game_ptr)
{
	for (int i = 0; i < NUMBER_OF_STREETS; i++){
		street_proceed(game_ptr->road[i]);
	}
	player_move(game_ptr->player_ptr, game_ptr->input_ptr->last_input_player);
}

void game_print(Game* game_ptr)
{
	for (int i = 0; i < NUMBER_OF_STREETS; i++){
		cursor_bewegen(PLAYGROUND_OFFSET_X, PLAYGROUND_OFFSET_Y);
		street_print(game_ptr->road[i]);
	}
	player_print(game_ptr->player_ptr);
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
}

void game_draw_border(Game* game_ptr) // draw the game border
{
	// STREET_VISIBLE + 2 and then - 1 on the x to ensure no overlap
	console_zeichne_rechteck(STREET_OFFSET + PLAYGROUND_OFFSET_X - 1, PLAYGROUND_OFFSET_Y - 1, STREET_VISIBLE + 2, PLAYER_YPOS + 1, PLAYGROUND_BOARDER_COLOR);
}

void game_check(Game* game_ptr)
{
	if (player_compare(game_ptr->player_ptr, game_ptr->destination_ptr)){ // check if player is at destination
		game_ptr->scoreboard_ptr->score += 10;
		player_init(game_ptr->player_ptr);
		player_print(game_ptr->player_ptr);
		player_print(game_ptr->destination_ptr);
	} else { // check if player is coliding with car for every street
		for (int i = 0; i < NUMBER_OF_STREETS; i++){
			if (game_ptr->player_ptr->y == game_ptr->road[i]->y && game_ptr->player_ptr->x == game_ptr->road[i]->x){ // check if player is coliding with car
				game_ptr->scoreboard_ptr->lives -= 1; // remove one life
				player_init(game_ptr->player_ptr); // reset player
				player_print(game_ptr->player_ptr);
				if (game_ptr->scoreboard_ptr->lives <= 0){ // check if lives ran out
					game_ptr->run = 0; // end game
				}
			}
		}
	}
	if (((game_ptr->player_ptr->x <= STREET_OFFSET + PLAYGROUND_OFFSET_X) || (game_ptr->player_ptr->x >= PLAYGROUND_OFFSET_X + STREET_OFFSET + STREET_VISIBLE)) ||
	        (game_ptr->player_ptr->y <= PLAYGROUND_OFFSET_Y) || (game_ptr->player_ptr->y >= PLAYER_YPOS + 2))
	{
		game_ptr->scoreboard_ptr->lives -= 1;
		player_init(game_ptr->player_ptr);
		game_draw_border(game_ptr);
		if (game_ptr->scoreboard_ptr->lives <= 0){ // check if lives ran out
			game_ptr->run = 0; // end game
		}
	}
}
