/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** cat_two_str
*/

#include <stdlib.h>

int my_strlen(char *str);

char *my_strcpy(char *dest, char const *src);

char *my_strcat(char *str1, char *str2)
{
	char	*tmp = malloc(sizeof(char) * my_strlen(str1));
	int	i = 0;
	int	j = 0;

	my_strcpy(tmp, str1);
	str1 = malloc(sizeof(char) * (my_strlen(tmp) + my_strlen(str2) + 1));
	while (tmp[i] != '\0') {
		str1[i] = tmp[i];
		++i;
	}
	while (str2[j] != '\0')
		str1[i++] = str2[j++];
	str1[i] = '\0';
	return (str1);
}