/*
** EPITECH PROJECT, 2018
** PSU_tetris_2017
** File description:
** recup_size
*/

#include "tetris.h"

struct size recup_size(char *size)
{
	struct	size max;
	int	i = 0;
	int	j = 0;
	char	*tmp = malloc(sizeof(char) * my_strlen(size) + 1);
	char	*tmp2 = malloc(sizeof(char) * my_strlen(size) + 1);

	if (tmp == NULL || tmp2 == NULL)
		exit (84);
	while (size[i] != '\t')
		++i;
	++i;
	while (size[i] != '*' && size[i] != '\0')
		tmp2[j++] = size[i++];
	++i;
	max.width = my_getnbr(tmp2);
	j = 0;
	while (size[i] != '\0')
		tmp[j++] = size[i++];
	max.height = my_getnbr(tmp);
	free(tmp);
	return (max);
}
