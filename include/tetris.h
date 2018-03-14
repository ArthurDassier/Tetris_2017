/*
** EPITECH PROJECT, 2018
** tetris.h
** File description:
** tetris_h
*/

#ifndef TETRIS_H_
#define TETRIS_H_

#include "get_next_line.h"
#include "my.h"
#include "printf.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <grp.h>
#include <sys/sysmacros.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <pwd.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct char_arg
{
	char *key_left;
	char *key_right;
	char *key_turn;
	char *key_drop;
	char *key_quit;
	char *key_pause;
	char *key_next;
	char *key_level;
	char *key_size;
} char_arg;

struct tetriminos
{
	char			*info;
	char			**form;
	struct tetriminos	*next;
};

char *get_next_line(int fd);
void draw_help(char **av);
void print_debug(char_arg *printable);
void launch_debug(char **av);
struct tetriminos *tetriminos_error_handling(struct tetriminos *tetri);
int remp_tetri_info_form(struct tetriminos *tetri, char *file);

#endif
