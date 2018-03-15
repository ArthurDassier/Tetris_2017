/*
** EPITECH PROJECT, 2018
** tetri.c
** File description:
** Vincent
*/

#include "tetris.h"

int print_tetri(void)
{
	struct tetriminos	*tetri = malloc(sizeof(struct tetriminos));

	if (tetri == NULL)
		return (84);
	tetri = recup_tetriminos(tetri);
	tetri = tetri_order(tetri);
	while (tetri->next != NULL) {
		tetrimino_error_handling(tetri);
		tetri = tetri->next;
	}
	my_printf("Press any key to start Tetris\n");
	return (0);
}