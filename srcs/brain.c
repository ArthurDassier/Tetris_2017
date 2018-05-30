/*
** EPITECH PROJECT, 2018
** brain.c
** File description:
** blabla
*/

#include "tetris.h"

int manage_argv(int ac, char **av, int oc)
{
	switch (oc) {
		case 'h':
			if (ac > 2)
				return (84);
			draw_help(av);
			exit(0);
		case 'D':
			if (launch_debug(ac, av) == 84)
				exit(84);
			exit(0);
		default:
			break;
		case ':':
			return (84);
		case '?':
			return (84);
	}
	return (0);
}

void analyse_before(int ac, char **av)
{
	int	i = 1;

	while (i != ac) {
		if (av[i][0] == '-')
			return;
		++i;
	}
	exit(84);
}

int manage_av(int ac, char **av, struct option *longopts)
{
	int	oc;

	analyse_before(ac, av);
	while ((oc = getopt_long(ac, av, "hDL:l:r:t:d:q:p:m:w:",
		longopts, NULL)) != -1) {
		if (manage_argv(ac, av, oc) == 84)
			return (84);
	}
	return (0);
}

int main(int ac, char **av)
{
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
		{"help", no_argument, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};

	if (ac > 1)
		if (manage_av(ac, av, longopts) == 84)
			return (84);
	return (0);
}
