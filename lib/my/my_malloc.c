/*
** EPITECH PROJECT, 2018
** my_malloc.c
** File description:
** Arthur
*/

#include <stdlib.h>

char *my_malloc_char(char *str, int size)
{
	str = malloc(sizeof(char) * size);
	if (str == NULL)
		return (NULL);
	return (str);
}

int *my_malloc_int(int *str, int size)
{
	str = malloc(sizeof(int) * size);
	if (str == NULL)
		return (NULL);
	return (str);
}
