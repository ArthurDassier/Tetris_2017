/*
** EPITECH PROJECT, 2018
** modif_debug.c
** File description:
** Arthur
*/

#include "tetris.h"

int get_argv(int oc)
{
	switch (oc) {
		case 'D':
			break;
		case 'L':
			break;
		case 'l':
			break;
		case 'r':
			break;
		case 't':
			break;
		case 'd':
			break;
		case 'q':
			break;
		case 'p':
			break;
		case 'm':
			break;
		case 'w':
			break;
		case ':':
			my_puterror("read --help before testing random"
			" arguments retard\n");
			return (84);
		case '?':
			my_puterror("read --help before testing random"
			" arguments retard\n");
		return (84);
	}
	return (0);
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
		if (get_argv(oc) == 84)
			return (84);
	return (0);
}
