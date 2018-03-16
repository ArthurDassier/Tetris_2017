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
	while (size[i] != '\0')
		++i;
	while (size[i] != ' ')
		--i;
	while (size[++i] != '*')
		tmp2[j++] = size[i];
	tmp2[j] = '\0';
	max.width = my_getnbr(tmp2);
	j = 0;
	while (size[++i] != '\0')
		tmp[j++] = size[i];
	tmp[j] = '\0';
	max.height = my_getnbr(tmp);
	my_printf("%d	%d\n", max.width, max.height);
	free(tmp);
	free(tmp2);
	return (max);
}
