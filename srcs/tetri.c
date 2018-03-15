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

	if (tetri == NULL)
		return (84);
	max = recup_size(size);
	tetri = recup_tetriminos(tetri);
	tetri = tetri_order(tetri);
	while (tetri->next != NULL) {
		tetrimino_error_handling(tetri, max);
		tetri = tetri->next;
	}
	my_printf("Press any key to start Tetris\n");
	return (0);
}
