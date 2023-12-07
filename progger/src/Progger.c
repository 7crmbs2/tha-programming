#include "Input.h"
#include "Configuration.h"
#include "Street.h"
#include "Cursor.h"
#include "Game.h"

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
	return 0;
}