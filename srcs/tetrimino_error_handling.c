/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetrimino_error_handling
*/

#include "tetris.h"

char *recup_tetri_name(char *name)
{
	int	i = 0;

	while (name[i] != '.' && name[i] != '\0')
		++i;
	name[i] = '\0';
	return (name);
}

int nb_stars(char *str)
{
	int	stars = 0;
	int	i = 0;

	while (str[i] != '\0') {
		if (str[i] == '*')
			++stars;
		if (str[i + 1] == ' ' && str[i + 2] != '\0')
			++stars;
		++i;
	}
	return (stars);
}

int is_good_height(struct tetriminos *tetri, int max_height)
{
	int	height = 0;
	int	i = 0;

	while (tetri->form[i] != NULL) {
		if (nb_stars(tetri->form[i]) > 0)
			++height;
		++i;
	}
	if (height != my_getnbr(recup_height(tetri->info)) || height == 0
			|| height > max_height)
		return (-1);
	return (0);
}

int is_good_width(struct tetriminos *tetri, int max_width)
{
	int	width = 0;
	int	count = 0;
	int	i = 0;

	while (tetri->form[i] != NULL) {
		count = nb_stars(tetri->form[i]);
		if (count > width)
			width = count;
		++i;
	}
	if (width != my_getnbr(tetri->info) || width == 0
			|| width > max_width)
		return (-1);
	return (0);
}

void tetrimino_error_handling(struct tetriminos *tetri, struct size max)
{
	my_printf("Tetriminos : ");
	my_printf("Name %s : ", recup_tetri_name(tetri->name));
	if (tetri->good != 1) {
		my_printf("Error\n");
		return;
	}
	if (is_good_width(tetri, max.width) != 0) {
		my_printf("Error\n");
		return;
	} else if (is_good_height(tetri, max.height) != 0) {
		my_printf("Error\n");
		return;
	}
	if (my_getnbr(recup_color(tetri->info)) < 0 ||
			my_getnbr(recup_color(tetri->info)) > 8) {
		my_printf("Error\n");
		return;	
	}
	display_infos(tetri);
}