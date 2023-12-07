

#include "Configuration.h"
#include "Console.h"
#include "Cursor.h"
#include "Street.h"

Street* street_create()
{
	Street *address;
	// dynamic memory allocation to runtime
	address = malloc(200 * sizeof(char));
	//malloc returns NULL pointer, if the allocation fails
	if (address == NULL)
	{
		printf("Fehler - Speicherallokierung nicht möglich\n");
		return NULL;
	}
	return address; // hier darf ich null ändern, die adresse soll returned werden
}

void street_init(Street* s_ptr, int x, int y, int offset, char* color, char direction)
{
	/* IHR CODE */
}
void street_proceed(Street* s_ptr)
{
	/* IHR CODE */
}
char street_check_free(Street* s_ptr, int number)
{
	/* IHR CODE */
	return 1;
}

void street_add_car(Street* s_ptr, int length)
{
	/* IHR CODE */
}

char street_check_field(Street* s_ptr, int xpos, int ypos)
{
	/* IHR CODE */
	return 0;
}
void street_print(Street* s_ptr)
{
	/* IHR CODE */
}
