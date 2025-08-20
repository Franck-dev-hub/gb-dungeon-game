#ifndef MAIN_H
#define MAIN_H

#include <gb/gb.h>

/* ========== Prototypes ========== */
/* Player */
void player_update(void);
void player_display(void);

/* World */
void world_update(void);

/* Battle */
int  battle_trigger(void);
void battle_start(void);

#endif
