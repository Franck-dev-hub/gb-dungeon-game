#include "main.h"

void main(void)
{
	player_display();
	world_init();

	while (1)
	{
		world_scroll();
		if (battle_trigger())
		{
			battle_start();
		}
		wait_vbl_done(); /* Wait synchronisation (60FPS) */
	}
}
