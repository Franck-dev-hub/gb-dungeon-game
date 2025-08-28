#include "main.h"
#include "assets/player/player_idle.c"

#define SCREEN_X 160
#define SCREEN_Y 144

UINT8 current_sprite = 0;
UINT8 current_frame = 0;
PlayerDirection player_direction;

void player_init(void)
{
	player_direction = DIR_RIGHT;
	set_sprite_data(0, 2, player_idle);
}

void player_display(void)
{
	UINT8 player_x = (SCREEN_X / 2) + 8;
	UINT8 player_y = (SCREEN_Y / 2) + 16;

	set_sprite_tile(0, 0);
	move_sprite(0, player_x, player_y);
	SHOW_SPRITES;
}

void player_animation(UINT8 frame_counter)
{
	if (frame_counter % 30 == 0)
	{
		current_frame = (current_frame + 1) % 2;
		set_sprite_tile(0, current_frame);
	}
}
