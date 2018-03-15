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
	char	*tmp = malloc(sizeof(char) * (size + 1));

	max.width = my_getnbr(size);
	while (size[i] != '*' || size[i] != '\0')
		++i;
	if (size[i] != '\0')
		++i;
	while (size[i] != '\0')
		tmp[j++] = size[i++];
	max.height = my_getnbr(tmp);
	return (max);
}