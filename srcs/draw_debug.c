/*
** EPITECH PROJECT, 2018
** draw_debug.c
** File description:
** Arthur
*/

#include "tetris.h"

void print_debug(char **av)
{
	(void) av;
	my_printf("*** DEBUG MODE ***\n");
	my_printf("Key Left :  ^EOD\n");
	my_printf("Key Right :  ^EOC\n");
	my_printf("Key Turn :  (space)\n");
	my_printf("Key Drop :  x\n");
	my_printf("Key Quit :  q\n");
	my_printf("Key Pause :  p\n");
	my_printf("Next :  Yes\n");
	my_printf("Level :  1\n");
	my_printf("Size :\t20*10\n");
}
