/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** open_read
*/

#include "tetris.h"

tetrimino *open_read_tetriminos(tetrimino *list, int ac, char **av)
{
	tetrimino	*tmp = list;
	File		fd = 0;

	while (ac != 1) {
		fd = open(av[ac-1], O_RDONLY);
		getline(list->info, fd);
		list->next = malloc(sizeof(struct tetrimino));
		list = list->next;
		close(fd);
		--ac;
	}
	list->next = NULL;
	return (tmp);
}
