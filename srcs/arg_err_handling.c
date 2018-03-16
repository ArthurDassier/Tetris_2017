/*
** EPITECH PROJECT, 2018
** arg_err_handling.c
** File description:
** Arthur
*/

#include "tetris.h"

int my_str_cmp(char *str1, char *str2, int count1, int count2)
{
	int	i = 0;

	if (count1 == count2)
		return (0);
	if (my_strlen(str1) != my_strlen(str2))
		return (0);
	while (str1[i] != '\0' && str2[i] != '\0') {
		if (str1[i] != str2[i])
			return (0);
		++i;
	}
	if (str1[i] != str2[i])
		return (0);
	exit(84);
}

int check_all(char **av)
{
	int	i = 1;
	int	j = 1;

	while (av[i]) {
		while (av[j]) {
			my_str_cmp(av[i], av[j], i, j);
			++j;
		}
		j = 1;
		++i;
	}
	return (0);
}
