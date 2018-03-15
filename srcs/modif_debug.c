/*
** EPITECH PROJECT, 2018
** modif_debug.c
** File description:
** Arthur
*/

#include "tetris.h"

char *change_str(char *arg, char *printer)
{
	int	i = 0;
	char	*tmp = malloc(sizeof(char) * 1024);

	if (tmp == NULL)
		return (NULL);
	while (printer[i] != ':') {
		tmp[i] = printer[i];
		++i;
	}
	for (int count = i; count != i + 3; ++count)
		tmp[count] = printer[count];
	i += 3;
	for (int j = 0; arg[j] != '\0'; ++j) {
		tmp[i] = arg[j];
		++i;
		tmp[i] = '\0';
		my_realloc(tmp);
	}
	tmp[i] = '\0';
	return (tmp);
}

char *change_size(char *arg, char *printer)
{
	int	i = 0;
	char	*tmp = malloc(sizeof(char) * 1024);

	if (tmp == NULL)
		return (NULL);
	while (printer[i] != '\t') {
		tmp[i] = printer[i];
		++i;
	}
	tmp[i] = printer[i];
	++i;
	for (int j = 0; arg[j] != '\0'; ++j) {
		tmp[i] = arg[j];
		if (!((tmp[i] >= '0' && tmp[i] <= '9') || tmp[i] == '*'))
			return (NULL);
		++i;
		tmp[i] = '\0';
		my_realloc(tmp);
	}
	return (tmp);
}

int modif_debug(int ac, char **av, char_arg *printable)
{
	int			oc;
	struct option		longopts[] = {
		{"level", required_argument, NULL, 'L'},
		{"key-left", required_argument, NULL, 'l'},
		{"key-right", required_argument, NULL, 'r'},
		{"key-turn", required_argument, NULL, 't'},
		{"key-drop", required_argument, NULL, 'd'},
		{"key-quit", required_argument, NULL, 'q'},
		{"key-pause", required_argument, NULL, 'p'},
		{"map-size", required_argument, NULL, 'm'},
		{"without-next", required_argument, NULL, 'w'},
		{"debug", no_argument, NULL, 'D'},
		{NULL, 0, NULL, 0}
	};
	optind = 1;
	while ((oc = getopt_long(ac, av, "DL:l:r:t:d:q:p:m:w:", longopts, NULL)) != -1)
		if (get_argv(oc, printable) == 84)
			return (84);
	return (0);
}
