#include "main.h"

void main(void)
{
	player_init();
	player_display();
	world_init();

	UINT8 frame_counter = 0;

	while (1)
	{
		world_scroll();
		if (battle_trigger())
		{
			battle_start();
		}

		wait_vbl_done(); /* 60FPS */
		frame_counter++;
		player_animation(frame_counter);
	}
}
