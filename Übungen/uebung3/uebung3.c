/*
 ============================================================================
 Name        : uebung3.c
 Author      : Julian Di Luzio
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "global.h"

int main(void) {
	time_t seconds = time(NULL);
	srand(time(&seconds)); // randomize seed - time in seconds from the beginning of time (1.1.1970)

	/*
	 */
	char myArray[ARRAYSIZE] = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0 };
	printArray(myArray, 10);

	char myMatrix1[MATRIXSIZE][MATRIXSIZE] = { { 0,1,2 },{ 3,4,5 },{ 6,7,8 } };
	char myMatrix2[MATRIXSIZE][MATRIXSIZE] = {	{ "        "},
												{ "   *    "},
												{ "   ***  "},
												{ "********" },
												{ "*********" },
												{ "********" },
												{ "   ***  "},
												{ "   *    "},
												{ "        "} };
	printMatrix(myMatrix1, 3, VALUE);
	printMatrix(myMatrix2, 10, CHAR);

	/*
	char randomArray[10];
	setArray(randomArray, 10, 0);
	randArray(randomArray, 10, 30);
	printArray(randomArray, 10);

	unsigned char randomMatrix[MATRIXSIZE][MATRIXSIZE]; // when using a matrix of size 4x4 for some reason it doesnt work, it must be bigger or smaller
	setMatrix(randomMatrix, 4, 0);
	randMatrix(randomMatrix, 4, 30);
	printMatrix(randomMatrix, 4, VALUE);
	*/

	unsigned char minefield[MATRIXSIZE][MATRIXSIZE];
	initMinefield(minefield, 20);
	setMinefield(minefield, 20, 100);
	calcDangerzone(minefield, 20, 7);
	printMinefield(minefield, 21, 7);
}
