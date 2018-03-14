/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetriminos_error_handling
*/

#include "tetris.h"

struct tetriminos *tetriminos_error_handling(struct tetriminos *tetri)
{
	DIR			*dir;
	struct dirent		*read_direc;
	struct tetriminos	*tmp = tetri;
	int			fd = 0;
	int			i = 0;
	char			*tet = "tetriminos/";

	dir = opendir("tetriminos");
	while ((read_direc = readdir(dir)) != NULL) {
		if (read_direc->d_name[0] != '.') {
			fd = open(my_strcat(tet, read_direc->d_name), O_RDONLY);
			my_printf("\n%s\n", read_direc->d_name);
			tetri->info = get_next_line(fd);
			my_printf("%s\n", tetri->info);
			tetri->form = malloc(sizeof(char *) * cti(tetri->info[2]));
			while ((tetri->form[i] = get_next_line(fd)) != NULL) {
				my_printf("%s\n", tetri->form[i]);
				++i;
			}
			tetri->form[i] = NULL;
		}
		i = 0;
		tetri->next = malloc(sizeof(struct tetriminos));
		close(fd);
	}
	return (tmp);
}