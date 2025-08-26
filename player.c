#include "main.h"

#define SCREEN_X 160
#define SCREEN_Y 144

void player_display(void)
{
	UINT8 player_x = (SCREEN_X / 2) + 8;
	UINT8 player_y = (SCREEN_Y / 2) + 16;

	unsigned char player[] = {
		// clang-format off
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		// clang-format on
	};

	set_sprite_data(0, 1, player);
	set_sprite_tile(0, 0);
	move_sprite(0, player_x, player_y);
	SHOW_SPRITES;
}
