/*
** EPITECH PROJECT, 2018
** check_kcu.c
** File description:
** Arthur
*/

#include "tetris.h"
#include <curses.h>
#include <term.h>

char *convert_kcu(char *tmp, const char *unc_ret, int *i)
{
	int	j = 0;

	while (unc_ret[j] != '\0') {
		tmp[*i] = unc_ret[j];
		++j;
		++*i;
	}
	return (tmp);
}

char *check_kcu(char *arg)
{
	char	*tmp;

	setupterm(NULL, 0, NULL);
	tmp = tigetstr(arg);
	if (tmp == (char*) -1)
		exit(84);
	if (tmp[0] == 27)
		my_putstr("^E");
	my_printf("%s", tmp + 1);
	return (tmp);
}
