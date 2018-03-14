/*
** EPITECH PROJECT, 2018
** tetris.h
** File description:
** tetris_h
*/

#ifndef TETRIS_H_
#define TETRIS_H_

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
#include <getopt.h>

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

void draw_help(char **av);
void print_debug(char_arg *printable);
int launch_debug(int ac, char **av);
int modif_debug(int ac, char **av, char_arg *printable);

#endif
