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

void draw_help(char **av);
void print_debug(char **av);
struct tetriminos *tetriminos_error_handling(struct tetriminos *all_teri, int ac, char **av);

#endif