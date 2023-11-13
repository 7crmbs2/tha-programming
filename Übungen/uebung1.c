/*
 * main.c
 *
 *  Created on: 13 Oct 2023
 *      Author: juliandiluzio
 */

#include <stdio.h>

float GM(float m, int l, int t){
	float g = 66.47 + (13.7 * m) + (5 * l) - (6.8 * t);
	return g;
}

float GW(float m, int l, int t){
	float g = 655.1 + (9.6 * m) + (1.8 * l) - (4.7 * t);
	return g;
}

int main() {
  printf(" (\"`-''-/\").___..--''\"`-._ \n");
  printf("  `6_ 6  )   `-.  (     ).`-.__.`) \n");
  printf("  (_Y_.)'  ._   )  `._ `. ``-..-' \n");
  printf("    _..`--'_..-_/  /--'_.' \n");
  printf("   ((((.-''  ((((.'  (((.-' \n\n");

  float GM1 = GM(58, 180, 25);
  float GW1 = GW(58, 180, 25);
  float GM2 = GM(90, 160, 45);
  float GW2 = GM(90, 160, 45);

  printf("\nExample 1:\n");
  printf("GM1: %f\n", GM1);
  printf("GW1: %f\n", GW1);
  printf("\nExample 2:\n");
  printf("GM2: %f\n", GM2);
  printf("GW2: %f\n", GW2);

  //int stunden = 12;
  //int minuten = 20;
  //int sekunden = 43;

  int stunden = 12;
  int minuten = 2;
  int sekunden = 3;

  printf("\nAktuelle Uhrzeit: %02i:%02i:%02i Uhr.\n", stunden, minuten, sekunden);

  int x = 24060; //Entspricht den seit 0:00Uhr vergangenen Sekunden

  stunden = x/60/60;
  minuten = (x/60)%60;
  sekunden = x%60;

  printf("\nProf. von Bodisco steht um %02i:%02i:%02i Uhr auf.\n", stunden, minuten, sekunden);
  printf("Prof. von Bodisco steht um %02i:%02i:%02i Uhr auf.\n", x/60/60, (x/60)%60, (x%60)%60);

  int stundenA = 12, minutenA = 20, sekundenA = 53; //Kurzschreibweise
  int stundenB = 18, minutenB = 48, sekundenB = 5; //Kurzschreibweise

  int stundenG = stundenB - stundenA;
  int minutenG = minutenB - minutenA;
  int sekundenG = sekundenB - sekundenA;
  if(minutenG < 0){
  	  stundenG = stundenG - 1;
  	  minutenG = minutenG + 60;
    };
  if(sekundenG < 0){
	  minutenG = minutenG - 1;
	  sekundenG = sekundenG + 60;
  };

  printf("\nZwischen %02i:%02i:%02i Uhr und %02i:%02i:%02i Uhr sind %02i Stunden %02i Minuten und %02i Sekunden vergangen."
		  "\nOder in anderer Schreibweise: %i Sekunden.",
		  stundenA, minutenA, sekundenA,
		  stundenB, minutenB, sekundenB,
		  stundenG, minutenG, sekundenG,
		  stundenG*60*60+minutenG*60+sekundenG);

  return 0;
}

