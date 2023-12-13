/*
 * Input.c
 *
 *  Created on: 04.12.2023
 *      Author: student
 */

#include "Configuration.h"
#include "Input.h"

Input* input_create()
{
	Input* i_ptr = (Input*) malloc(sizeof(Input));
	input_init(i_ptr);
	return i_ptr;
}

void input_init(struct Input* input_ptr)
{
	input_ptr->last_input_player = MOVE_RIGHT;
}

void input_read(struct Input* input_ptr)
{
    //TERMIOS-----------------------------------------------------------------------------------------
    struct termios tio, oldtio;             // Hilfsvariablen zum Speichern der Terminaleinstellung
    tcgetattr(STDIN_FILENO, &oldtio);       // Sichern der aktuellen Terminaleinstellung
    oldtio.c_lflag &= ~(ECHO);              // Echo für Eingaben dauerhaft auf false setzen.
    tio = oldtio;
    tio.c_lflag &= ~(ICANON | ECHO);        // Verzögerungsfreies Einlesen ohne Ausgabe auf der Konsole
    tio.c_cc[VMIN] = 0;                     // Minimale Anzahl an Zeichen pro Lesevorgang
    tio.c_cc[VTIME] = 0;                    // Timeout bei Verwendung von Select in 1/10s
    tcsetattr(STDIN_FILENO, TCSANOW, &tio); // Setzen der neuen Terminaleinstellung
    //------------------------------------------------------------------------------------------------

    input_ptr->last_input_player = -1;
    char c = -1;
    for (int i = 0; i < 10; i++)
    {
        if (read(STDIN_FILENO, &c, 1) != 1)
        {
            continue;
        }
        usleep(50000); // Reduziert die CPU-Belastung durch Reduzierung der Abtastrate

        switch (c)
        {
        case PLAYER_UP:
            input_ptr->last_input_player = MOVE_UP;
            break;
        case PLAYER_DOWN:
            input_ptr->last_input_player = MOVE_DOWN;
            break;
        case PLAYER_LEFT:
            input_ptr->last_input_player = MOVE_LEFT;
            break;
        case PLAYER_RIGHT:
            input_ptr->last_input_player = MOVE_RIGHT;
            break;

        default:
            // UNGÜLTIG / UNBEKANNT
            break;
        };

    }
    tcsetattr(STDIN_FILENO, TCSANOW, &oldtio);      // Zurücksetzen der Terminaleinstellung
}
