/*
 * global.h
 *
 *  Created on: 8 Nov 2023
 *      Author: juliandiluzio
 */

#include <stdio.h>
#include <stdlib.h>

// Makros
#define MATRIXSIZE 30
#define ARRAYSIZE 100
#define TYP_GRASS 0
#define TYP_MINE '*'
#define TYP_BORDER '#'
#define SEED 5

#define VALUE 1
#define CHAR 0


/* Aufgabe – Printausgaben */
void printArray(unsigned char* array, int length) {
	for (int i = 0; i < length; i++){
		printf("%i", (int)array[i]);
		if (i != (length - 1)){ // ensure last output doesnt have a comma
			printf(", ");
		}
	}
	printf("\n\n");
}

void printMatrix(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int length, int type) {

	if (type == 1){ // check if its a value
		for (int i = 0; i <= length - 1; i++){ // or just < but then we cant do -1
			for (int j = 0; j <=  length - 1; j++){
				printf("%02i ", (int)matrix[i][j]); // convert char from matrix into int and print it
			}
			printf("\n\n");
		}

	} else if (type == 0){ // check if its a char
		for (int i = 0; i <= length - 1; i++){ // or just < but then we cant do -1
			for (int j = 0; j <=  length - 1; j++){
				printf("%c ", (char)matrix[i][j]); // convert char from matrix into int and print it
			}
			printf("\n\n");
		}

	} else { // tell the user the input is wrong
		printf("well this is awkward... You didn't enter a valid Value for the type.");
	}
	printf("\n");
}

/* Aufgabe – Zufallszahlen */
void setArray(unsigned char* array, int length, unsigned char value) {
	for (int i = 0; i < length - 1; i++) {
		array[i] = value;
	}
}

void setMatrix(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int length, unsigned char value) {
	for (int i = 0; i <= length - 1; i++) {
		for (int j = 0; j <= length - 1; j++) {
			matrix[i][j] = value;
		}
	}
}

unsigned char myRand(int max) {
	return (unsigned char)((rand() % max) + 1);
}

void randArray(unsigned char* array, int length, int max) {
	for (int i = 0; i < length - 1; i++) {
		array[i] = myRand(max);
	}
}

void randMatrix(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int length, int max) {
	for (int i = 0; i < length - 1; i++) {
		for (int j = 0; j < length - 1; j++){
			matrix[i][j] = myRand(max);
		}
	}
}


/* Aufgabe – Minefield */
void initMinefield(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int length) { // define the minefield with size, borders and grass
	for (int i = 0; i <= length; i++) {
		for (int j = 0; j <= length; j++) {
			if (i == 0 || j == 0 || i == length || j == length) { // if its the border do border if not do grass
				matrix[i][j] = TYP_BORDER;
			} else {
				matrix[i][j] = TYP_GRASS;
			}
		}
	}
}

void setMinefield(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int length, int numberOfMines) {
	int counter;
	for (int i = 0; i < numberOfMines; i++){
		counter = i;
		int xcoord = myRand(length-1);
		int ycoord = myRand(length-1);
		while (counter == i) {
			if (matrix[xcoord][ycoord] != TYP_MINE){
				matrix[xcoord][ycoord] = TYP_MINE;
				counter++;
			}
		}

	}

}

void printMinefield(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int length, int numberOfMines) {
	for (int i = 0; i <= length - 1; i++){
		for (int j = 0; j <=  length - 1; j++){
			if (matrix[i][j] == TYP_BORDER || matrix[i][j] == TYP_MINE){
				printf("%c", matrix[i][j]);
			} else if (matrix[i][j] == TYP_GRASS) { // since grass is defined as null we need to add a space for it
				printf(" ");
			} else {
				printf("%i", matrix[i][j]); // in case the normal types were not used print the field as integer
			}
		}
		printf("\n");
	}
	printf("\n");
}

int mineCounter = 0;

void checkNeighbors(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int y, int x) {
	if (matrix[y][x] == TYP_GRASS) {
		mineCounter = 0; // reset mineCounter for new count
		for (int i = -1; i < 2; i++){
			for (int j = -1; j < 2; j++){
				if (matrix[y + i][x + j] == TYP_MINE && matrix[y + i][x + j] != matrix[y][x]){
					mineCounter++;
				}
			}
		}
		matrix[y][x] = mineCounter;
		//printf("%i", mineCounter);
	}
}


void calcDangerzone(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int length, int numberOfMines) {
	for (int i = 1; i <= length - 1; i++){
		for (int j = 1; j <=  length - 1; j++){
			if (matrix[i][j] != TYP_MINE){
				checkNeighbors(matrix, i, j);
				matrix[i][j] = mineCounter;
				//printf("%i", mineCounter); // This would be the case if you want it to be displayed below (and uncomment the next few lines)
			}
			/*
			else {
				printf(" ");
			}
			 */
		}
		// printf("\n");
	}
}

// Aufgabe - Sudoku Test
char lineTest(const char matrix[MATRIXSIZE][MATRIXSIZE], int line, int length) {
/* IHR CODE */ }
char columnTest(const char matrix[MATRIXSIZE][MATRIXSIZE], int column, int length)
{ /* IHR CODE */ }
char sudokuTest(const char matrix[MATRIXSIZE][MATRIXSIZE], int length)
{ /* IHR CODE */ }
