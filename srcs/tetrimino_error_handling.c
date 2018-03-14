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

int is_good_width(struct tetriminos *tetri)
{
	int	width = 0;
	int	i = 0;

	while (tetri->form[i] != NULL) {
		if (nb_stars(tetri->form[i]) > 0)
			++width;
		++i;
	}
	if (width != my_getnbr(recup_width(tetri->info)) || width == 0)
		return (-1);
	return (0);
}

int is_good_height(struct tetriminos *tetri)
{
	int	height = 0;
	int	count = 0;
	int	i = 0;

	while (tetri->form[i] != NULL) {
		count = nb_stars(tetri->form[i]);
		if (count > height)
			height = count;
		++i;
	}
	if (height != my_getnbr(tetri->info) || height == 0)
		return (-1);
	return (0);
}

void tetrimino_error_handling(struct tetriminos *tetri)
{
	int	i = 0;

	my_printf("Tetriminos : ");
	my_printf("Name %s : ", recup_tetri_name(tetri->name));
	if (is_good_width(tetri) != 0) {
		my_printf("Error\n");
		return;
	} else if (is_good_height(tetri) != 0) {
		my_printf("Error\n");
		return;
	}
	if (my_getnbr(recup_color(tetri->info)) < 0 ||
			my_getnbr(recup_color(tetri->info)) > 8) {
		my_printf("Error\n");
		return;	
	}
	my_printf("Size : %s", recup_height(tetri->info));
	my_printf("%c", '*');
	my_printf("%s ", recup_width(tetri->info));
	my_printf(" Color : %c\n", tetri->info[4]);
	while (tetri->form[i] != NULL)
		my_printf("%s\n", tetri->form[i++]);
}