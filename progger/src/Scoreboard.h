#ifndef SCOREBOARD
#define SCOREBOARD

#include "Configuration.h"
#include "Console.h"
#include <stdio.h>
#include <stdlib.h>
struct Scoreboard
{
	int score;
	int lives;
	int x;
	int y;
};

typedef struct Scoreboard Scoreboard;
Scoreboard* scoreboard_create();

void scoreboard_init(Scoreboard* scoreboard_ptr);

void scoreboard_print(Scoreboard* scoreboard_ptr);

#endif