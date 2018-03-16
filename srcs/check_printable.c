/*
** EPITECH PROJECT, 2018
** check_printable.c
** File description:
** Arthur
*/

#include "tetris.h"

void comp_str(char *str1, char *str2)
{
	int	i = 0;
	int	j = 0;

	while (str1[i] != ':')
		++i;
	while (str2[j] != ':')
		++j;
	while (str1[i] != '\0' && str2[j] != '\0') {
		if (str1[i] != str2[j])
			return;
		++i;
		++j;
	}
	if (str1[i] != str2[j])
		return;
	exit(84);
}

void check_printable(char **printable)
{
	int	i = 0;
	int	j = 0;

	while (i != 8) {
		while (j != 8) {
			if (j != i)
				comp_str(printable[i], printable[j]);
			++j;
		}
		j = 0;
		++i;
	}
}
