/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include <unistd.h>
#include <getopt.h>
#include "tetris.h"

int manage_argv(int ac, char **av, int oc)
{
	switch (oc) {
		case 'h':
			if (ac > 2)
				return (84);
			draw_help(av);
			return (0);
		case 'D':
			print_debug(av);
			return (0);
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

int main(int ac, char **av)
{
	int		oc;
	struct option	longopts[] = {
		{"help", no_argument, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};
	while ((oc = getopt_long(ac, av, "D", longopts, NULL)) != -1)
		if (manage_argv(ac, av, oc) == 84)
			return (84);
	return (0);
}
