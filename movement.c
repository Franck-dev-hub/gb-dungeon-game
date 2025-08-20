#include "main.h"

/**
 * player_movement - Handle player movement
 * @x: X player position
 * @y: Y pleyer position
 */
void player_movement(UINT8 *x, UINT8 *y)
{
	if (joypad() & J_LEFT && *x > 8)
		(*x)--;
	if (joypad() & J_RIGHT && *x < 160)
		(*x)++;
	if (joypad() & J_UP && *y > 16)
		(*y)--;
	if (joypad() & J_DOWN && *y < 152)
		(*y)++;

	move_sprite(0, *x, *y);
}
