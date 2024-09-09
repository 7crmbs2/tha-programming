#ifndef GAME_H
#define GAME_H 

#include "Street.h"

struct Game
{
	Street* road[NUMBER_OF_STREETS];
	struct Player* player_ptr;
	struct Player* destination_ptr;
	struct Scoreboard* scoreboard_ptr;
	struct Input* input_ptr;
	char run;
};

typedef struct Game Game;

Game* game_create();
void game_init(Game* game_ptr);
void game_add_traffic(Game* game_ptr);
void game_proceed(Game* game_ptr);
void game_print(Game* game_ptr);
void game_run(Game* game_ptr);
void game_draw_border(Game* game_ptr);
void game_check(Game* game_ptr);


#endif
