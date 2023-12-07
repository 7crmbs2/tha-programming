#ifndef PLAYER_H
#define PLAYER_H

struct Player
{
	int x;
	int y;
	char symbol;
	char color[9];
};
typedef struct Player Player;

Player* player_create();
void player_init(Player* p_ptr);
void player_print(Player* p_ptr);
void player_move(Player* p_ptr, char direction);
char player_compare(Player* player1_ptr, Player* player2_ptr);

#endif // !PLAYER_H
