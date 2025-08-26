#include "main.h"

void player_display(void)
{
	UINT8 player_x = 84;
	UINT8 player_y = 80;

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
