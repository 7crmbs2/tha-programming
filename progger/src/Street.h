#ifndef STREET_H
#define STREET_H 

#include "Configuration.h"
#include "Console.h"
#include "Cursor.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
struct Street
{
	int x;
	int y;
	int offset;
	char fields[STREET_LENGTH];
	char color[9];
	char direction;
};

typedef struct Street Street;

Street* street_create();

void street_init(Street* s_ptr, int x, int y, int offset, char* color, char direction);
void street_proceed(Street* s_ptr);
char street_check_free(Street* s_ptr, int number);

void street_add_car(Street* s_ptr, int length);

char street_check_field(Street* s_ptr, int xpos, int ypos);
void street_print(Street* s_ptr);
#endif