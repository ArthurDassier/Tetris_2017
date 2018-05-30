/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetri_order
*/

#include "tetris.h"

void cpy_tetri(struct tetriminos *order, struct tetriminos *tetri)
{
	int	i = 0;

	order->name = malloc(sizeof(char) * (my_strlen(tetri->name) + 1));
	my_strcpy(order->name, tetri->name);
	order->good = tetri->good;
	if (tetri->good != 1)
		return;
	order->info = malloc(sizeof(char) * (my_strlen(tetri->info) + 1));
	my_strcpy(order->info, tetri->info);
	while (tetri->form[i] != NULL)
		++i;
	order->form = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (tetri->form[i] != NULL) {
		order->form[i] = malloc(sizeof(char) *
				(my_strlen(tetri->form[i]) + 1));
		my_strcpy(order->form[i], tetri->form[i]);
		++i;
	}
	order->form[i] = NULL;
}

int alph_order(struct tetriminos *order, struct tetriminos *tetri, char alph)
{
	struct tetriminos	*tmp = tetri;

	while (tetri->next != NULL) {
		if (tetri->name[0] == alph) {
			cpy_tetri(order, tetri);
			return (0);
		}
		tetri = tetri->next;
	}
	tetri = tmp;
	return (1);
}
struct tetriminos *tetri_order(struct tetriminos *tetri)
{
	struct tetriminos	*order = malloc(sizeof(struct tetriminos));
	struct tetriminos	*tmp = order;
	char		*alph = "123456789abcdefghijklmnopqrstuvwxyz";
	int			i = 0;

	my_printf("Tetriminos : %d\n", nb_tetriminos(tetri));
	while (alph[i] != '\0') {
		if (alph_order(order, tetri, alph[i++]) == 0) {
			order->next = malloc(sizeof(struct tetriminos));
			order = order->next;
		}
	}
	order->next = NULL;
	return (tmp);
}
