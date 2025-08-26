#include "main.h"

#define SCREEN_X 160
#define SCREEN_Y 144

void player_display(void)
{
	UINT8 player_x = (SCREEN_X / 2) + 8;
	UINT8 player_y = (SCREEN_Y / 2) + 16;

	unsigned char player[] = {
		// clang-format off
		0b11111000, 0b11010010,
		0b11111000, 0b10000101,
		0b11010000, 0b10000010,
		0b11111000, 0b10000010,
		0b10111100, 0b11000010,
		0b10110000, 0b01111010,
		0b10000000, 0b01111010,
		0b01010000, 0b00000010,
		// clang-format on
	};

	set_sprite_data(0, 1, player);
	set_sprite_tile(0, 0);
	move_sprite(0, player_x, player_y);
	SHOW_SPRITES;
}
