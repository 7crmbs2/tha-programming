/*
 * main.c
 *
 *  Created on: 14 Oct 2023
 *      Author: juliandiluzio
 */

#include <stdio.h>
#include <stdlib.h>

// Task 2
char viererPasch(int w1, int w2, int w3, int w4, int w5) {
if(w1 == w2 && w2 == w3 && w3 == w4){ //ohne w5
	return 1;
} else if (w1 == w2 && w2 == w3 && w3 == w5){ //ohne w4
	return 1;
} else if (w5 == w2 && w2 == w3 && w3 == w4){ //ohne w1
	return 1;
} else if (w1 == w5 && w5 == w3 && w3 == w4){ //ohne w2
	return 1;
} else if (w1 == w5 && w5 == w2 && w2 == w4){ //ohne w3
	return 1;
}
return 0;
}

char strasse(int w1, int w2, int w3, int w4, int w5) { // TODO die reihnfolge muss egal sein
	int values[] = { w1, w2, w3, w4, w5 };
	for(int i=0 ; i < 5; i++){ // iterate through every
		for(int j=i+1 ; j < 5 ; j++){
			if (values[j] < values[i]){
				int tmp = values[i]; // save first
				values[i] = values[j]; // write second into first
				values[j] = tmp; // write first into second
			}
		}
	}
	if(values[0] == values[1] - 1 && values[0] == values[2] - 2 && values[0] == values[3] - 3 && values[0] == values[4] - 4){ // check if the numbers are 1 to 5
		return 1;
	}
return 0;
}

// Task 3
void rechteck(unsigned int breite, unsigned int hoehe, char c) {
	hoehe = hoehe - 2; // This is because we have a top and bottom layer
	for(int i = 0; i < breite; i++){ //print the first line as width
		printf("%c", c);
	}
	printf("\n");
	for(int i = 0; i < hoehe; i++){ // for ever hoehe
		printf("%c", c); // write one edge char
		for(int i = 0; i < breite - 2; i++){ // skip to the other edge with whitespaces
				printf(" ");
			}
		printf("%c\n", c);// write another edge char
	}
	for(int i = 0; i < breite; i++){ //print the last line as width
		printf("%c", c);
	}
	printf("\n");
	printf("\n");
}

// Task 4
void sanduhr(unsigned int b, char c) {
	if (b % 2 == 1){
		for(int j = b; j > (b/2); j--){ // execute x(width) times -- fuer jedes j in der loop dann eine leerstelle machen - bzw in der mitte wieder weniger
			int ws = b-j; // calculate the white spaces we need
			for (int i = 0; i < ws; i++){ // print all the whitespaces necessary for this iteration
				printf(" ");
			}
			for (int i = 0; i < j-ws; i++){ // print all the characters necessary for this iteration - j as iteration minus the amount of whitespaces we need
				printf("%c", c);
			}
			printf("\n");
		}
		for(int j = 1; j <= (b/2); j++){ // j as counter for the second half of the hourwatch
			int ws = (b/2)-j;
			//int cs = b-j; // calculate the necessary char count
			for (int i = 0; i < ws; i++){
				printf(" ");
			}
				//printf("%i, %i, %i", ws, ws+ws, b);
			for (int i = 1; i <= b-(ws+ws); i++){ // +4 is needed to adjust the off
				printf("%c", c);
			}
			printf("\n");
		}
	} else {
		printf("gerade");
	}
}
			/*
			for(int i = 0; i < b; i++){ //print the first line as width
				for (int w = j ; w > 0 ; w--){ // width for the corresponding line (j) print x(w) amount of white spaces (w = whitespace)
					printf(" ");
				}
				printf("\n");
				// if j > b:2 dann wieder mehr leerzeichen
				// für jedes j ein leerzeichen quasi
				for (int w = j ; w > 0 ; w--){
					printf("%c", c);
				}
			}
			printf("\n ");

			for(int i = 0; i < (b - 2); i++){
				printf("%c", c);
			}
			printf("\n ");
			for(int i = 0; i < b - i; i++){ //print the first line as width
				printf("%c", c);
			}
			printf("\n  ");
			for(int i = 0; i < b - i; i++){ //print the first line as width
				printf("%c", c);
			}
			*/
			// große for schleife und nicht b - i sondern in der großen scheleife zB y nehmen und dann immer -y
			// 6 = 6x6 , 7 = 7x7
			// ACHTUNG noch ein Unterschied: gerade zahl ist unten leer, und hat immer in der mitte 2 anstatt bei einer ungeraden in der mitte 1

int main() {
	/*
	// Task 1
	for(int i = 0; i < 10000; i++){
		printf("%04i\n", i);
	}

	// Task 2
	if(viererPasch(1, 2, 1, 1, 1)){
		printf("WOOOWWW\n");
	} else {
		printf("NOOOOOO\n");
	}

	if(strasse(4, 3, 2, 1, 5)){
		printf("WOOOWWW\n");
	} else {
		printf("NOOOOOO\n");
	}
	*/

	// Task 3
	//rechteck(4, 6, 'x');

	// Task 4
	sanduhr(7, 'x');

	getchar();
	return 0;
}
