#ifndef MAIN_H
#define MAIN_H

/* ========== Libraries ========== */
/* Standards */
#include <gb/gb.h>
#include <stdio.h>

/* Custom */

/* ========== Globals ========== */
/* Map size */
#define MAP_HEIGHT 32
#define MAP_WIDTH 32
extern uint8_t map[MAP_HEIGHT][MAP_WIDTH];

/* ========== Prototypes ========== */
/* Player */
void player_init(void);
void player_display(void);
void player_animation(UINT8 frame_counter);

/* World */
void world_update(void);

/* Battle */
int  battle_trigger(void);
void battle_start(void);

#endif
