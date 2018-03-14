/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** recup_tetri_info
*/

#include "tetris.h"

char *recup_color(char *str)
{
	char	*tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
	int	i = 0;
	int	j = 0;

	while (str[i] != '\0')
		++i;
	while (str[i] != ' ')
		--i;
	++i;
	while (str[i] != '\0')
		tmp[j++] = str[i++];
	return (tmp);
}
char *recup_height(char *str)
{
	char	*tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
	int	i = 0;

	while (str[i] != ' ' && str[i] != '\0') {
		tmp[i] = str[i];
		++i;
	}
	return (tmp);
}

char *recup_width(char *str)
{
	char	*tmp = malloc(sizeof(char) * (my_strlen(str) + 1));
	int	k = 0;
	int	j = 0;

	while (str[j] != ' ' && str[j] != '\0')
		++j;
	if (str[j] != '\0')
		++j;
	while (str[j] != ' ' && str[j] != '\0')
		tmp[k++] = str[j++];
	tmp[k] = '\0';
	return (tmp);
}