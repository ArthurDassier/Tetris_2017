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
			return (0);
		case 'D':
			launch_debug(ac, av);
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
	struct tetriminos	*tetri = malloc(sizeof(struct tetriminos));
	int			oc;
	struct option		longopts[] = {
		{"help", no_argument, NULL, 'h'},
		{"debug", no_argument, NULL, 'D'},
		{NULL, 0, NULL, 0}
	};
	while ((oc = getopt_long(ac, av, "D", longopts, NULL)) != -1)
		if (manage_argv(ac, av, oc) == 84)
			return (84);
	tetri = recup_tetriminos(tetri);
	tetri = tetri_order(tetri);
	while (tetri->next != NULL) {
		tetrimino_error_handling(tetri);
		tetri = tetri->next;
	}
	my_printf("Press any key to start Tetris\n");
	return (0);
}
