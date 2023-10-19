/*
 * main.c
 *
 *  Created on: 14 Oct 2023
 *      Author: juliandiluzio
 */

#include <stdio.h>

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

int main() {

	for(int i = 0; i < 10000; i++){
		printf("%04i\n", i);
	}

	if(viererPasch(1, 2, 1, 1, 1)){
		printf("WOOOWWW");
	} else {
		printf("NOOOOOO");
	}

    return 0;
}
