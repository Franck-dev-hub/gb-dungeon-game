#include "main.h"

/*
 *Largeur = 160px -> 20 tiles
 *Longeur = 144px -> 18 tiles
 *
 *Haut Gauche	-> 8, 16
 *Haut Droit	-> 160, 16
 *Bas Droit	-> 160, 152
 *Bas Gauche	-> 8, 152
 */

void main(void)
{
	unsigned char perso[] = {
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF,
		0xFF, 0xFF, 0xFF, 0xFF
	};

	UINT8 x = 8; /* Position X initiale */
	UINT8 y = 16; /* Position Y initiale */

	/* Chargement du sprite */
	set_sprite_data(0, 1, perso);	/* Charge tile 0 */
	set_sprite_tile(0, 0);	/* Sprite 0 utilise tile 0 */
	move_sprite(0, x, y);	/* Position initiale */
	SHOW_SPRITES;		/* Active les sprites */

	/* Boucle principale */
	while (1)
	{
		player_movement(&x, &y);

		wait_vbl_done(); /* Attend la synchro (60FPS) */
	}
}
