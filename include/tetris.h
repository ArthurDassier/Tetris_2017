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
#include <getopt.h>

typedef struct char_arg
{
	char *key_left;
	char *key_right;
	char *key_turn;
	char *key_drop;
	char *key_quit;
	char *key_pause;//
	char *key_next;
	char *key_level;
	char *key_size;
} char_arg;

struct tetriminos
{
	int			good;
	char			*name;
	char			*info;
	char			**form;
	struct tetriminos	*next;
};

struct size
{
	int	width;
	int	height;
};

char *get_next_line(int fd);
void draw_help(char **av);
void print_debug(char **printable);
int launch_debug(int ac, char **av);
int modif_debug(int ac, char **av, char **printable);

struct tetriminos *recup_tetriminos(struct tetriminos *tetri);
int remp_tetri_info_form(struct tetriminos *tetri, char *file);
int get_argv(int oc, char **ptb);
char *change_str(char *arg, char *printer);
void cpy_tetri(struct tetriminos *order, struct tetriminos *tetri);
int alph_order(struct tetriminos *order, struct tetriminos *tetri, char alph);
struct tetriminos *tetri_order(struct tetriminos *tetri);

void tetrimino_error_handling(struct tetriminos *tetri, struct size max);
int is_good_height(struct tetriminos *tetri, int max_height);
int is_good_width(struct tetriminos *tetri, int max_width);
char *recup_tetri_name(char *name);
int nb_stars(char *str);
char *recup_height(char *str);
char *recup_width(char *str);
char *recup_color(char *str);
int nb_tetriminos(struct tetriminos *tetri);
int print_tetri(char *size);
char *change_size(char *arg, char *printer);
struct size recup_size(char *size);
char *check_kcu(char *arg);
int check_all(char **av);
void check_printable(char **printable);
void check_yes_no(char *arg);

void display_infos(struct tetriminos *tetri);

#endif
