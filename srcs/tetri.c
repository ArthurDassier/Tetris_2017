/*
** EPITECH PROJECT, 2018
** tetri.c
** File description:
** Vincent
*/

#include "tetris.h"

void display_infos(struct tetriminos *tetri)
{
	int	i = 0;

	my_printf("Size : %s", recup_width(tetri->info));
	my_printf("*%s ", recup_height(tetri->info));
	my_printf(" Color %s :\n", recup_color(tetri->info));
	while (tetri->form[i] != NULL)
		my_printf("%s\n", tetri->form[i++]);
}

int print_tetri(char *size)
{
	struct tetriminos	*tetri = malloc(sizeof(struct tetriminos));
	struct size		max;

	if (tetri == NULL)
		return (84);
	max = recup_size(size);
	if ((tetri = recup_tetriminos(tetri)) == NULL)
		exit(84);
	tetri = tetri_order(tetri);
	while (tetri->next != NULL) {
		tetrimino_error_handling(tetri, max);
		tetri = tetri->next;
	}
	my_printf("Press any key to start Tetris\n");
	return (0);
}