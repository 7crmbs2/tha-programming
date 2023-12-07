#ifndef CURSOR_H
#define CURSOR_H 

#define CURSOR_DUNKEL_GRAU	"\033[1;30m"
#define CURSOR_WEISS		"\033[1;37m"

#define CURSOR_SCHWARZ		"\033[0;30m"
#define CURSOR_ROT			"\033[0;31m"
#define CURSOR_GRUEN		"\033[0;32m"
#define CURSOR_BRAUN		"\033[0;33m"
#define CURSOR_BLAU			"\033[0;34m"
#define CURSOR_LILA			"\033[0;35m"
#define CURSOR_CYAN			"\033[0;36m"
#define CURSOR_HELL_GRAU	"\033[0;37m"

#define CURSOR_HELL_ROT		"\033[1;31m"
#define CURSOR_HELL_GRUEN	"\033[1;32m"
#define CURSOR_HELL_GELB	"\033[1;33m"
#define CURSOR_HELL_BLAU	"\033[1;34m"
#define CURSOR_HELL_LILA	"\033[1;35m"
#define CURSOR_HELL_CYAN	"\033[1;36m"
#define CURSOR_HELL_WEISS	"\033[1;37m"

#define HINTERGRUND_SCHWARZ	"\033[40m"
#define HINTERGRUND_ROT 	"\033[41m"
#define HINTERGRUND_GRUEN	"\033[42m"
#define HINTERGRUND_GELB    "\033[43m"
#define HINTERGRUND_BLAU    "\033[44m"
#define HINTERGRUND_LILA    "\033[45m"
#define HINTERGRUND_CYAN    "\033[46m"
#define HINTERGRUND_WEISS   "\033[47m"
#define HINTERGRUND_HELL_GRAU	"\033[100m"
#define HINTERGRUND_HELL_ROT	"\033[101m"
#define HINTERGRUND_HELL_GRUEN  "\033[102m"
#define HINTERGRUND_HELL_GELB	"\033[103m"
#define HINTERGRUND_HELL_BLAU	"\033[104m"
#define HINTERGRUND_HELL_LILA	"\033[105m"
#define HINTERGRUND_HELL_CYAN	"\033[106m"
#define HINTERGRUND_HELL_WEISS	"\033[107m"

static char* hpallette[16] = { HINTERGRUND_SCHWARZ, HINTERGRUND_ROT, HINTERGRUND_GRUEN,
						HINTERGRUND_GELB, HINTERGRUND_BLAU, HINTERGRUND_LILA,
						HINTERGRUND_CYAN, HINTERGRUND_WEISS, HINTERGRUND_HELL_GRAU,
						HINTERGRUND_HELL_ROT, HINTERGRUND_HELL_GRUEN, HINTERGRUND_HELL_GELB,
						HINTERGRUND_HELL_BLAU, HINTERGRUND_HELL_LILA, HINTERGRUND_HELL_CYAN,
						HINTERGRUND_HELL_WEISS};
static char* cpallette[16] = { CURSOR_SCHWARZ, CURSOR_ROT, CURSOR_GRUEN,
						CURSOR_BRAUN, CURSOR_BLAU, CURSOR_LILA,
						CURSOR_CYAN, CURSOR_WEISS, CURSOR_HELL_GRAU,
						CURSOR_HELL_ROT, CURSOR_HELL_GRUEN, CURSOR_HELL_GELB,
						CURSOR_HELL_BLAU, CURSOR_HELL_LILA, CURSOR_HELL_CYAN,
						CURSOR_HELL_WEISS };



void cursor_bewegen(int x, int y);	//Positioniere Cursor an Position x,y 

void cursor_hoch(int n);	//Bewege Cursor um n Stellen/Spalten nach oben	 \033[<N>A
void cursor_runter(int n);	//Bewege Cursor um n Stellen/Spalten nach unten  \033[<N>B
void cursor_rechts(int n);	//Bewege Cursor um n Stellen/Spalten nach rechts \033[<N>C
void cursor_links(int n);	//Bewege Cursor um n Stellen/Spalten nach links  \033[<N>D

//Setze Cursor-Farbe
void cursor_setze_farbe(const char* farbe);
//Speichert die aktuelle Cursor Position: //\033[s
void cursor_speichere_position();
//Stellt die gespeicherte Cursor Position wieder her: \033[u
void cursor_gehezu_letzte_gespeicherte_position();

#endif