#include "main.h"
#include "assets/world/sprite_black.c"
#include "assets/world/sprite_white.c"
#include "assets/world/world_map.c"

#define SCREEN_X 160
#define SCREEN_Y 144
#define TILE 8

#define PLAYER_X 8
#define PLAYER_Y 8


INT8 cam_x = 0;
INT8 cam_y = 0;

void world_init(void)
{
	int i, j;

	set_bkg_data(0, 1, sprite_white);
	set_bkg_data(1, 1, sprite_black);

	for (i = 0; i < MAP_HEIGHT; i++)
	{
		for (j = 0; j < MAP_WIDTH; j++)
		{
			if (map[i][j])
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}

	set_bkg_tiles(0, 0, MAP_WIDTH, MAP_HEIGHT, (unsigned char*)map);
	SHOW_BKG;
}

void world_scroll(void)
{
	INT8  cam_speed_x = 0;
	INT8  cam_speed_y = 0;
	UINT8 speed	  = 1;

	/* Actual position */
	UINT8 player_tile_x_left = (cam_x + SCREEN_X / 2) / TILE;
	UINT8 player_tile_x_right = (cam_x + SCREEN_X / 2 + PLAYER_X - 1) / TILE;
	UINT8 player_tile_y_up = (cam_y + SCREEN_Y / 2) / TILE;
	UINT8 player_tile_y_down = (cam_y + SCREEN_Y / 2 + PLAYER_Y - 1) / TILE;

	/* Next position */
	UINT8 next_left;
	UINT8 next_right;
	UINT8 next_up;
	UINT8 next_down;

	if (joypad() & J_LEFT)
	{
		player_dir = DIR_LEFT;
		next_left = (cam_x + SCREEN_X / 2 - speed) / TILE;
		if (map[player_tile_y_up][next_left] == 0 &&
		   map[player_tile_y_down][next_left] == 0)
			cam_speed_x = -speed;
	}
	if (joypad() & J_RIGHT)
	{
		player_dir = DIR_RIGHT;
		next_right = (cam_x + SCREEN_X / 2 + PLAYER_X - 1 + speed) / TILE;
		if (map[player_tile_y_up][next_right] == 0 &&
		   map[player_tile_y_down][next_right] == 0)
			cam_speed_x = speed;
	}
	if (joypad() & J_UP)
	{
		player_dir = DIR_UP;
		next_up = (cam_y + SCREEN_Y / 2 - speed) / TILE;
		if (map[next_up][player_tile_x_left] == 0 &&
		   map[next_up][player_tile_x_right] == 0)
			cam_speed_y = -speed;
	}
	if (joypad() & J_DOWN)
	{
		player_dir = DIR_DOWN;
		next_down = (cam_y + SCREEN_Y / 2 + PLAYER_Y - 1 + speed) / TILE;
		if (map[next_down][player_tile_x_left] == 0 &&
		   map[next_down][player_tile_x_right] == 0)
			cam_speed_y = speed;
	}

	cam_x += cam_speed_x;
	cam_y += cam_speed_y;

	scroll_bkg(cam_speed_x, cam_speed_y);
	if(player_dir == DIR_LEFT)
		set_sprite_prop(sprite_player_idle, S_FLIPX);
	else if(player_dir == DIR_RIGHT)
		set_sprite_prop(sprite_player_idle, 0x00);

}
