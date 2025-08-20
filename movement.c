#include "main.h"

/**
 * movement - Handle player movement
 * @x: X player position
 * @y: Y pleyer position
 */
void player_movement(UINT8 *x, UINT8 *y)
{
	if (joypad() & J_LEFT)
		(*x)--;
	if (joypad() & J_RIGHT)
		(*x)++;
	if (joypad() & J_UP)
		(*y)--;
	if (joypad() & J_DOWN)
		(*y)++;

	move_sprite(0, *x, *y);
}
