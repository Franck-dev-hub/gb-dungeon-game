#ifndef MAIN_H
#define MAIN_H

/* ========== Libraries ========== */
/* Standards */
#include <gb/gb.h>
#include <stdio.h>

/* Custom */

/* ========== Globals ========== */
/* Map vars */
#define MAP_HEIGHT 32
#define MAP_WIDTH 32
extern uint8_t map[MAP_HEIGHT][MAP_WIDTH];

/* Player vars*/
typedef enum {DIR_LEFT, DIR_RIGHT, DIR_UP, DIR_DOWN} PlayerDir;
extern PlayerDir player_dir;
extern UINT8 sprite_player_idle;

/* ========== Prototypes ========== */
/* Player */
void player_init(void);
void player_display(void);
void player_animation(UINT8 frame_counter);

/* World */
void world_init(void);
void world_scroll(void);
void world_update(void);

/* Battle */
int  battle_trigger(void);
void battle_start(void);

#endif
