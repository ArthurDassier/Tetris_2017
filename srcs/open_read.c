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
	char		*line = malloc(sizeof(char) * 11);
	int		fd = 0;

	while (ac != 1) {
		fd = open(av[ac-1], O_RDONLY);
		read(fd, line, 10);
		line[10] = '\0';
		list->width = my_getnbr(line);
		list->height = my_getnbr(line);
		list->color = my_getnbr(line);
		list->next = malloc(sizeof(struct tetrimino));
		list = list->next;
		close(fd);
		--ac;
	}
	list->next = NULL;
	return (tmp);
}
