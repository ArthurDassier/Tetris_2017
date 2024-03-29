/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** recup_tetriminos.c
*/

#include "tetris.h"

int remp_tetri_info_form(struct tetriminos *tetri, char *file)
{
	static char	*tetr_dos = "tetriminos/";
	int		i = 0;
	int		fd = 0;

	my_strcpy(tetri->name, file);
	if ((fd = open(my_strcat(tetr_dos, file), O_RDONLY)) == -1)
		return (-1);
	if ((tetri->info = get_next_line(fd)) == NULL) {
		tetri->good = 0;
		close(fd);
		return (0);
	}
	while ((tetri->form[i] = get_next_line(fd)) != NULL)
		++i;
	tetri->form[i] = NULL;
	tetri->good = 1;
	close(fd);
	return (0);
}

struct tetriminos *recup_tetriminos(struct tetriminos *tetri)
{
	DIR			*dir;
	struct dirent		*read_direc;
	struct tetriminos	*tmp = tetri;

	if ((dir = opendir("tetriminos/")) == NULL)
		exit(84);
	while ((read_direc = readdir(dir)) != NULL) {
		if (read_direc->d_name[0] != '.') {
			tetri->form = malloc(sizeof(char *) * 10);
			tetri->name = malloc(sizeof(char) *
				(my_strlen(read_direc->d_name) + 1));
			remp_tetri_info_form(tetri, read_direc->d_name);
			tetri->next = malloc(sizeof(struct tetriminos));
			tetri = tetri->next;
		}
	}
	tetri->next = NULL;
	return (tmp);
}
