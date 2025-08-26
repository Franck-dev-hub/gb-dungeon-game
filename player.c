#include "main.h"
#include "assets/player/sprite_player_idle_1.c"
#include "assets/player/sprite_player_idle_2.c"

#define SCREEN_X 160
#define SCREEN_Y 144

UINT8 sprite_player_idle = 0;
UINT8 current_frame = 0;
PlayerDir player_dir;

void player_init(void)
{
	player_dir = DIR_RIGHT;
	set_sprite_data(0, 1, sprite_player_idle_1);
	set_sprite_data(1, 1, sprite_player_idle_2);
}

void player_display(void)
{
	UINT8 player_x = (SCREEN_X / 2) + 8;
	UINT8 player_y = (SCREEN_Y / 2) + 16;

	set_sprite_tile(sprite_player_idle, 0);
	move_sprite(sprite_player_idle, player_x, player_y);
	SHOW_SPRITES;
}

void player_animation(UINT8 frame_counter)
{
	if (frame_counter % 30 == 0)
	{
		current_frame = (current_frame + 1) % 2;
		set_sprite_tile(sprite_player_idle, current_frame);
	}
}
