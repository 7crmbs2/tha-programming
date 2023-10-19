/*
 * main.c
 *
 *  Created on: 14 Oct 2023
 *      Author: juliandiluzio
 */

#include <stdio.h>

int main() {

	int number = 5;

	for (int i = 0; i < number; i++ ) {
		if (number%i==0) {
			printf("The number %i is not prime number. It can be devided by %i.", number, i);
			return 0;
		}
	}

	printf("The number %i is a prime number!", number);

    return 0;
}
