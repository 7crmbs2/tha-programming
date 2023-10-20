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

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

char strasse(int w1, int w2, int w3, int w4, int w5) { // TODO die reihnfolge muss egal sein -> einfach schauen, dass nur eine von jeder zahl drinnen ist, entweder ab 1-5 oder ab 2-6
	int values[] = { w1, w2, w3, w4, w5 };
	qsort(values, 5, sizeof(int), cmpfunc);
	if(values[0] == values[1] - 1 && values[0] == values[2] - 2 && values[0] == values[3] - 3 && values[0] == values[4] - 4){
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
	for(int i = 0; i < hoehe; i++){
			/*printf("%c", c); // this would have been even better but c is not equal width as a whitespace
			for(int i = 0; i < breite; i++){
					printf(" ");
				}
			printf("%c\n", c);*/
			printf("%c  %c\n", c, c); // print n-2 lines for every hight
		}
	for(int i = 0; i < breite; i++){ //print the last line as width
			printf("%c", c);
		}
	printf("\n");
	printf("\n");
}

// Task 4
void sanduhr(unsigned int b, char c) {
	for(int i = 0; i < b; i++){ //print the first line as width
		printf("%c", c);
	}
	for(int i = 0; i < b; i++){
		printf("%c", c);
	}

	/*
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
	printf("\n");
}

int main() {

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

	if(strasse(1, 3, 2, 4, 5)){
			printf("WOOOWWW\n");
		} else {
			printf("NOOOOOO\n");
		}

	// Task 3
	rechteck(4, 6, 'x');

	// Task 4
	sanduhr(6, 'x');
	return 0;

	return 0;
}
