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
	if (my_strlen(arg) < 5 || my_strlen(arg) > 5)
		return (arg);
	if (arg[0] == 'k' && arg[1] == 'c' && arg[2] == 'u') {
		tmp = tigetstr("kcub1");
		if (tmp == (char*) -1)
			return (arg);
		for (int i = 0; tmp[i] != '\0'; ++i)
			tmp = convert_kcu(tmp, unctrl(tmp[i]), &i);
		return (tmp);
	}
	return (arg);
}
