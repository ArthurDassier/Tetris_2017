/*
** EPITECH PROJECT, 2017
** my_putstr.c
** File description:
** afficher_les_char
*/

#include <unistd.h>

void my_putchar(char c);

void my_putstr(char const *str)
{
	int	i = 0;

	while (str[i] != '\0') {
		my_putchar(str[i]);
		i = i + 1;
	}
}
