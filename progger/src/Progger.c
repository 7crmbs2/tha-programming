#include "Input.h"
#include "Configuration.h"
#include "Street.h"
#include "Cursor.h"
#include "Game.h"

// temporary import for testing
#include "Player.c"
#include "Player.h"

void start()
{
	console_init();
	Game* game_ptr = game_create();
	game_init(game_ptr);
	game_print(game_ptr);
	game_run(game_ptr);
	cursor_bewegen(0, 20);
}
int main()
{
	//Auskommentieren für finalen Spieltest
	//start();
	Street* myStreet = street_create();
	street_init(myStreet, 2, 5, STREET_OFFSET, hpallette[6], 1);
	street_add_car(myStreet, 20);
	street_print(myStreet);
	printf("\n");
	// weirdly the y coordinate doesnt do anything
	Street* myStreet2 = street_create();
	street_init(myStreet2, 1, 4, STREET_OFFSET, hpallette[5], 1);
	street_add_car(myStreet2, 20);
	street_print(myStreet2);

	Player* myPlayer;
	player_init(myPlayer);
	player_print(myPlayer);

	return 0;
}
