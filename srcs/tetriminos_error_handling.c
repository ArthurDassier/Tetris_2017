/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetriminos_error_handling
*/

#include "tetris.h"

struct tetriminos *tetriminos_error_handling(struct tetriminos *all_tetri, int ac, char **av)
{
	DIR			*tetrim;
	struct dirent		*read_direc;
	struct tetriminos	*tmp = all_tetri;
	FILE			*file;

	tetrim = opendir("tetriminos");
	while ((read_direc = readdir(tetrim)) != NULL) {
		file = fopen(read_direc->d_name, "r");
		fclose(file);
	}
	return (tmp);
}