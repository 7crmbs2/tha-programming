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
	for (int i = 0; i < length; i++){ // or just < but then we cant do -1
		for (int j = 0; j <  length; j++){
			if (type == VALUE) {
				printf("%02i ", (int)matrix[i][j]); // convert char from matrix into int and print it
			} else if (type == CHAR) {
				printf("%c ", (char)matrix[i][j]); // print matrix field (as char)
			} else {
				printf("This is not the correct input for printMatrix.\n");
			}
		}
		printf("\n\n");
	}
	printf("\n");
}

/* Aufgabe – Zufallszahlen */
void setArray(unsigned char* array, int length, unsigned char value) {
	for (int i = 0; i < length; i++) {
		array[i] = value;
	}
}

void setMatrix(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int length, unsigned char value) {
	for (int i = 0; i < length; i++) {
		for (int j = 0; j < length; j++) {
			matrix[i][j] = value;
		}
	}
}

unsigned char myRand(int max) {
	return (unsigned char)((rand() % max) + 1);
}

void randArray(unsigned char* array, int length, int max) {
	for (int i = 0; i < length; i++) {
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
	int minesSet;
	for (int i = 0; i < numberOfMines; i++){
		minesSet = i;
		while (minesSet == i) {
			// Switch between these to have the mines more centered or not
			// int xcoord = myRand(length-1);
			// int ycoord = myRand(length-1);
			int xcoord = myRand((length-1)/2) + myRand((length-1)/2);
			int ycoord = myRand((length-1)/2) + myRand((length-1)/2);
			if (matrix[xcoord][ycoord] != TYP_MINE){
				matrix[xcoord][ycoord] = TYP_MINE;
				minesSet++;
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

void checkNeighbors(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int y, int x) {
	if (matrix[y][x] == TYP_GRASS) {
		int mineCounter = 0; // reset mineCounter for new count
		for (int i = -1; i < 2; i++){
			for (int j = -1; j < 2; j++){
				if (matrix[y + i][x + j] == TYP_MINE){
					mineCounter++;
				}
			}
		}
		matrix[y][x] = mineCounter;
	}
}


void calcDangerzone(unsigned char matrix[MATRIXSIZE][MATRIXSIZE], int length, int numberOfMines) {
	for (int i = 1; i <= length - 1; i++){
		for (int j = 1; j <=  length - 1; j++){
			if (matrix[i][j] != TYP_MINE){
				checkNeighbors(matrix, i, j);
			}
		}
	}
}

// Aufgabe - Sudoku Test
// char lineTest(const char matrix[MATRIXSIZE][MATRIXSIZE], int line, int length) { /* IHR CODE */ }
//char columnTest(const char matrix[MATRIXSIZE][MATRIXSIZE], int column, int length) { /* IHR CODE */ }
//char sudokuTest(const char matrix[MATRIXSIZE][MATRIXSIZE], int length) { /* IHR CODE */ }
