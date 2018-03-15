/*
** EPITECH PROJECT, 2018
** draw_debug.c
** File description:
** Arthur
*/

#include "tetris.h"

char_arg *init_debug(char_arg *printable)
{
	printable->key_left = "Key Left :  ^EOD";
	printable->key_right = "Key Right :  ^EOD";
	printable->key_turn = "Key Turn :  (space)";
	printable->key_drop = "Key Drop :  x";
	printable->key_quit = "Key Quit :  q";
	printable->key_pause = "Key Pause :  p";
	printable->key_next = "Next :  Yes";
	printable->key_level = "Level :  1";
	printable->key_size = "Size :\t20*10";
	return (printable);
}

void print_debug(char_arg *printable)
{
	my_printf("*** DEBUG MODE ***\n");
	my_printf("%s\n", printable->key_left);
	my_printf("%s\n", printable->key_right);
	my_printf("%s\n", printable->key_turn);
	my_printf("%s\n", printable->key_drop);
	my_printf("%s\n", printable->key_quit);
	my_printf("%s\n", printable->key_pause);
	my_printf("%s\n", printable->key_next);
	my_printf("%s\n", printable->key_level);
	my_printf("%s\n", printable->key_size);
}

int launch_debug(int ac, char **av)
{
	char_arg	*printable = malloc(sizeof(char_arg));

	if (printable == NULL)
		return (84);
	printable = init_debug(printable);
	if (modif_debug(ac, av, printable) == 84)
		return (84);
	print_debug(printable);
	if (print_tetri() == 84)
		return (84);
	return (0);
}
