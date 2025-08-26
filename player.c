#include "main.h"
#include "assets/player/sprite_player.c"

#define SCREEN_X 160
#define SCREEN_Y 144

void player_display(void)
{
	UINT8 player_x = (SCREEN_X / 2) + 8;
	UINT8 player_y = (SCREEN_Y / 2) + 16;

	set_sprite_data(0, 1, sprite_player);
	set_sprite_tile(0, 0);
	move_sprite(0, player_x, player_y);
	SHOW_SPRITES;
}
