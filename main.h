#ifndef MAIN_H
#define MAIN_H

/* ========== Libraries ========== */
/* Standards */
#include <gb/gb.h>
#include <stdio.h>

/* Custom */

/* ========== Prototypes ========== */
/* Player */
void player_display(void);

/* World */
void world_update(void);

/* Battle */
int  battle_trigger(void);
void battle_start(void);

#endif
