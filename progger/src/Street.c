

#include "Configuration.h"
#include "Console.h"
#include "Cursor.h"
#include "Street.h"

Street* street_create() // allocate space for a Street type and return the Address
{
	Street *address;
	// dynamic memory allocation to runtime
	// int + int + int + char*STREET_LENGTH + char*10 + char = 3x4 + 10+20+10 + 10 + 1 = 63 - so lets do 100
	address = malloc(100 * sizeof(char));
	//malloc returns NULL pointer, if the allocation fails
	if (address == NULL)
	{
		printf("Fehler - Speicherallokierung nicht möglich\n");
		return NULL;
	}
	return address;
}

void street_init(Street* s_ptr, int x, int y, int offset, char* color, char direction) // init street with these values
{
	// zahlenindex auswürfeln
	s_ptr->x = x;
	s_ptr->y = y;
	s_ptr->offset = offset;
	for (int i = 0; i < STREET_LENGTH; i++){
		s_ptr->fields[i] = ' ';
	}
	strcpy(s_ptr->color, color);
	s_ptr->direction = direction;
}

void street_proceed(Street* s_ptr) // move the street in the corresponding direction
{
	if (s_ptr->direction == TRAFFIC_LEFT){ // if the traffic comes from the left
		for (int i = STREET_LENGTH; i >= 0; i--){ // start moving the fields from the very far right
			s_ptr->fields[i] = s_ptr->fields[i-1];
		}
		s_ptr->fields[0] = ' '; // set the now "empty" / meaningless field 0 as space
	} else if (s_ptr->direction == TRAFFIC_RIGHT){ // if the traffic comes from the right
		for (int i = 0; i <= STREET_LENGTH; i++){ // start moving the fields from the very left
			s_ptr->fields[i] = s_ptr->fields[i+1];
		}
		s_ptr->fields[STREET_LENGTH] = ' '; // fill in the last field in the very last place
	}
}

char street_check_free(Street* s_ptr, int number) // return 1 = number*space is free, return = its not
{
	if (s_ptr->direction == TRAFFIC_LEFT){ // if the traffic comes from the left
		char spaceUsed = 0;
		for (int i = 0; i < number; i++){ // check for spaces in number of fields at the beginning
			if (s_ptr->fields[i] != ' '){
				spaceUsed = 1;
			}
		}
		if (spaceUsed == 1){ // if the space is used then return 0
			return 0;
		}
	} else if (s_ptr->direction == TRAFFIC_RIGHT){ // if the traffic comes from the right
		char spaceUsed = 0;
		for (int i = STREET_LENGTH; i <= (STREET_LENGTH-number); i--){
			if (s_ptr->fields[i] != ' '){   // check for spaces in number of fields at the end
				spaceUsed = 1;
			}
		}
		if (spaceUsed == 1){ // if the space is used then return 0
			return 0;
		}
	}
	return 1; // if the space is available return 1
}

void street_add_car(Street* s_ptr, int length) // add a car to a street
{
	if (street_check_free(s_ptr, length)){
		if (s_ptr->direction == TRAFFIC_LEFT){ // if the traffic comes from the left
			for (int i = 0; i < length; i++){
				s_ptr->fields[i] = 'X'; // set X for length at beginning
			}
		} else if (s_ptr->direction == TRAFFIC_RIGHT){ // if the traffic comes from the right
			for (int i = STREET_LENGTH; i > (STREET_LENGTH - length); i++){
				s_ptr->fields[i] = 'X'; // set X for length at end
			}
		}
	}
}

char street_check_field(Street* s_ptr, int xpos, int ypos)
{
	if (s_ptr->y == ypos && s_ptr->fields[s_ptr->offset + xpos] == 'X'){
		return 1;
	}
	return 0;
}
void street_print(Street* s_ptr) // print the street
{
	for (int i = s_ptr->offset; i < (STREET_LENGTH - s_ptr->offset); i++){
		if (s_ptr->fields[i] == 'X'){
			cursor_setze_farbe(s_ptr->color); // set background to street color
		} else {
			cursor_setze_farbe(HINTERGRUND_SCHWARZ); // set background to black
		}
		printf(" ");
		cursor_setze_farbe(HINTERGRUND_SCHWARZ); // set background to black
	}
}