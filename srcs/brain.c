/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include <unistd.h>
#include <getopt.h>
#include "tetris.h"

int main(int ac, char **av)
{
	int		oc;
	struct option	longopts[] = {
		{"help", no_argument, NULL, 'h'},
		{NULL, 0, NULL, 0}
	};
	while ((oc = getopt_long(ac, av, "h", longopts, NULL)) != -1) {
		switch (oc) {
			case 'h':
				draw_help(av);
				break;
			case ':':
				/* missing option argument */
				break;
			case '?':
				default:
				/* invalid option */
				break;
			}
	}
	return (0);
}
