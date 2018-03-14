/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** tetriminos_error_handling
*/

#include "tetris.h"

int remp_tetri_info_form(struct tetriminos *tetri, char *file)
{
	static char	*tetr_dos = "tetriminos/";
	int		i = 0;
	int		fd  = 0;

	if ((fd = open(my_strcat(tetr_dos, file), O_RDONLY)) == -1)
		return (-1);
	tetri->info = get_next_line(fd);
	my_printf("%s\n", tetri->info);
	while ((tetri->form[i] = get_next_line(fd)) != NULL) {
		my_printf("%s\n", tetri->form[i]);
		++i;
	}
	close(fd);
	return (0);
}

struct tetriminos *tetriminos_error_handling(struct tetriminos *tetri)
{
	DIR			*dir;
	struct dirent		*read_direc;
	struct tetriminos	*tmp = tetri;

	dir = opendir("tetriminos/");
	while ((read_direc = readdir(dir)) != NULL) {
		if (read_direc->d_name[0] != '.') {
			my_printf("\n%s\n", read_direc->d_name);
			if ((tetri->form = malloc(sizeof(char *) * 10)) == NULL)
				return (NULL);
			if (remp_tetri_info_form(tetri,
					read_direc->d_name) != 0)
				return (NULL);
		}
		tetri->next = malloc(sizeof(struct tetriminos));
		tetri = tetri->next;
	}
	tetri->next = NULL;
	return (tmp);
}
