/*
** EPITECH PROJECT, 2018
** tetri.c
** File description:
** Vincent
*/

#include "tetris.h"

int print_tetri(char *size)
{
	struct tetriminos	*tetri = malloc(sizeof(struct tetriminos));
	struct size		max;

	max = recup_size(size);
	if (tetri == NULL)
		return (84);
	tetri = recup_tetriminos(tetri);
	tetri = tetri_order(tetri);
	while (tetri->next != NULL) {
<<<<<<< HEAD
		tetrimino_error_handling(tetri, max);
=======
//		tetrimino_error_handling(tetri);
>>>>>>> bb65c3591f4fe11036cc1db693a2a268a54f499b
		tetri = tetri->next;
	}
	my_printf("Press any key to start Tetris\n");
	return (0);
}