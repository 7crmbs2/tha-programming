/*
 * Input.h
 *
 *  Created on: 12.12.2022
 *      Author: student
 */

#ifndef INPUT_H_
#define INPUT_H_

#ifdef _WIN32
#include <Windows.h> //Sleep
#include <conio.h>	 //Non-blocking Input
#else //LINUX
#include <termios.h> //Non-blocking Input
#include <unistd.h>  //Provides sleep and usleep
#include <fcntl.h>
#endif
#include <stdlib.h>
#include <stdio.h>

struct Input
{
	char last_input_player;
};
typedef struct Input Input;

Input* input_create();

void input_init(struct Input* input_ptr);

void input_read(struct Input* input_ptr);

#endif /* INPUT_H_ */
