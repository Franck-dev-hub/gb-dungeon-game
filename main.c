#include "main.h"

/*
 * Largeur = 160px -> 20 tiles
 * Longeur = 144px -> 18 tiles
 *
 * Haut Gauche	-> 8, 16
 * Haut Droit	-> 160, 16
 * Bas Droit	-> 160, 152
 * Bas Gauche	-> 8, 152
 */

/*
 * 0b00000000, 0b00000000 -> bit bas, bit haut -> ligne blanche
 * 00 -> bit haut = 0, bit bas = 0 -> blanc
 * 01 -> bit haut = 0, bit bas = 1 -> gris clair
 * 10 -> bit haut = 1, bit bas = 0 -> gris foncé
 * 11 -> bit haut = 1, bit bas = 1 -> noir
 */

void main(void)
{
	unsigned char perso[] = {
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
		0b11111111, 0b11111111,
	};

	unsigned char pixel_sprite[] = {
		0b10000000, 0b10000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
		0b00000000, 0b00000000,
	};

	UINT8 x = 8; /* Position X initiale */
	UINT8 y = 16; /* Position Y initiale */

	/* Chargement du sprite */
	set_sprite_data(0, 1, perso);	/* Charge tile 0 */
	set_sprite_tile(0, 0);	/* Sprite 0 utilise tile 0 */
	move_sprite(0, x, y);	/* Position initiale */

	set_sprite_data(1, 1, pixel_sprite);
	set_sprite_tile(1, 1); /* sprite 1 utilise tile 1 */
	move_sprite(1, 80, 72); /* milieu de l'écran */

	SHOW_SPRITES;

	/* Boucle principale */
	while (1)
	{
		player_movement(&x, &y);

		wait_vbl_done(); /* Attend la synchro (60FPS) */
	}
}
