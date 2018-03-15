/*
** EPITECH PROJECT, 2018
** modif_debug.c
** File description:
** Arthur
*/

#include "tetris.h"

char *check_space(char *str, int *i)
{
	if (str[*i] == ' ') {
		str[*i] = '(';
		str[*i + 1] = 's';
		str[*i + 2] = 'p';
		str[*i + 3] = 'a';
		str[*i + 4] = 'c';
		str[*i + 5] = 'e';
		str[*i + 6] = ')';
		str[*i + 7] = '\0';
		*i += 6;
	}
	return (str);
}

int check_arg(char *arg)
{
	int	i = 0;
	int	j = 0;

	while (arg[i] != '\0') {
		if (!((arg[i] >= '0' && arg[i] <= '9') || arg[i] == '*'))
			return (84);
		if (arg[i] == '*')
			++j;
		++i;
	}
	if (j != 1)
		return (84);
	if (arg[i - 1] == '*')
		return (84);
	return (0);
}

char *change_str(char *arg, char *printer)
{
	int	i = 0;
	char	*tmp = malloc(sizeof(char) * 1024);

	if (tmp == NULL)
		return (NULL);
	arg = check_kcu(arg);
	while (printer[i] != ':') {
		tmp[i] = printer[i];
		++i;
	}
	for (int count = i; count != i + 3; ++count)
		tmp[count] = printer[count];
	i += 3;
	for (int j = 0; arg[j] != '\0'; ++j) {
		tmp[i] = arg[j];
		tmp = check_space(tmp, &i);
		++i;
		tmp[i] = '\0';
		my_realloc(tmp);
	}
	return (tmp);
}

char *change_size(char *arg, char *printer)
{
	int	i = 0;
	char	*tmp = malloc(sizeof(char) * 1024);

	if (tmp == NULL || check_arg(arg) == 84)
		return (NULL);
	while (printer[i] != '\t') {
		tmp[i] = printer[i];
		++i;
	}
	tmp[i] = printer[i];
	++i;
	for (int j = 0; arg[j] != '\0'; ++j) {
		tmp[i] = arg[j];
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
	while ((oc = getopt_long(ac, av, "DL:l:r:t:d:q:p:m:w:",
	longopts, NULL)) != -1)
		if (get_argv(oc, printable) == 84)
			return (84);
	return (0);
}
