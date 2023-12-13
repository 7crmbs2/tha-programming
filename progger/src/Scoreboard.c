#include "Scoreboard.h"
#include "Configuration.h"
#include "Console.h"
#include "Cursor.h"


 Scoreboard* scoreboard_create()
 {
	Scoreboard* address;
 	// dynamic memory allocation to runtime
 	address = malloc(sizeof(Scoreboard));
 	//malloc returns NULL pointer, if the allocation fails
 	if (address == NULL)
 	{
 		printf("Fehler - Speicherallokierung nicht möglich\n"); // TODO maybe das nochmal schöner machen
 		return NULL;
 	}
 	return address;
 }


void scoreboard_init(Scoreboard* scoreboard_ptr)
{
	scoreboard_ptr->x = SCOREBOARD_XPOS;
	scoreboard_ptr->y = SCOREBOARD_YPOS;
	scoreboard_ptr->score = 0;
	scoreboard_ptr->lives = LIVES;
}


void scoreboard_print(Scoreboard* scoreboard_ptr)
{
	// lol that next line is not needed, we already get the correct values from the struct I guess
	// lets make it STREET_VISIBLE / 2 and then add 5-10 so that they don't touch
	console_zeichne_rechteck(scoreboard_ptr->x, scoreboard_ptr->y, 15, 7, hpallette[4]);
	cursor_setze_farbe(cpallette[7]); // set cursor to white
	cursor_setze_farbe(hpallette[0]); // set background to black
	cursor_bewegen(scoreboard_ptr->x + 3, scoreboard_ptr->y + 2);
	printf("Score: %i", scoreboard_ptr->score);
	cursor_bewegen(scoreboard_ptr->x + 3, scoreboard_ptr->y + 4);
	printf("Lives: %i", scoreboard_ptr->lives);
}
