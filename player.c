#include "main.h"

UINT8 player_x = 80;
UINT8 player_y = 72;

/**
 * player_display - Display player on screen
 */
void player_display(void)
{
	unsigned char player[] = {
		0b11111111, 0b11111111, 0b11111111, 0b11111111,
		0b11111111, 0b11111111, 0b11111111, 0b11111111,
		0b11111111, 0b11111111, 0b11111111, 0b11111111,
		0b11111111, 0b11111111, 0b11111111, 0b11111111,
	};

	set_sprite_data(0, 1, player);
	set_sprite_tile(0, 0);
	move_sprite(0, player_x, player_y);
	SHOW_SPRITES;
}
/**
 * player_movement - Handle player movement
 */
void static player_movement(void)
{
	if (joypad() & J_LEFT && player_x > 8)
		player_x--;
	if (joypad() & J_RIGHT && player_x < 160)
		player_x++;
	if (joypad() & J_UP && player_y > 16)
		player_y--;
	if (joypad() & J_DOWN && player_y < 152)
		player_y++;

	move_sprite(0, player_x, player_y);
}

/**
 * player_update - Player main function
 */
void player_update(void)
{
	player_movement();
}
