/*
 ============================================================================
 Name        : progger.c
 Author      : Julian Di Luzio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	Street* memAddress = street_create();
	printf("%s", &memAddress);
	return EXIT_SUCCESS;
}
