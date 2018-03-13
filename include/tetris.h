/*
** EPITECH PROJECT, 2017
** tetris.h
** File description:
** tetris_h
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include "my.h"
#include "printf.h"
#include "sys/stat.h"
#include "fcntl.h"
#include "sys/types.h"

typedef struct tetrimino
{
	int			**info;
	struct tetrimino	*next;
} tetrimino;

struct tetrimino *open_read_tetriminos(struct tetrimino *list, int ac,
char **av);

#endif
