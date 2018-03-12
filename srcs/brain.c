/*
** EPITECH PROJECT, 2017
** brain.c
** File description:
** blabla
*/

#include "tetris.h"

int main(int ac, char **av)
{
	tetrimino	*list = malloc(sizeof(struct tetrimino));

	list = open_read_tetriminos(list, ac, av);
	return(0);
}
