#include "main.h"

/**
 * main -
 *
 */
void main(void)
{
	player_display(); // Init player

	while (1)
	{
		player_update();
		world_update();
		if (battle_trigger())
		{
			battle_start();
		}
		wait_vbl_done(); /* Wait synchronisation (60FPS) */
	}
}
