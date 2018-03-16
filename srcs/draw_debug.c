/*
** EPITECH PROJECT, 2018
** draw_debug.c
** File description:
** Arthur
*/

#include "tetris.h"
#include <term.h>

char **init_debug(char **printable)
{
	printable[0] = "Key Left : ";
	printable[1] = "Key Right : ";
	printable[2] = "Key Turn : ";
	printable[3] = "Key Drop : ";
	printable[4] = "Key Quit : q";
	printable[5] = "Key Pause : (pause)";
	printable[6] = "Next : Yes";
	printable[7] = "Level : 1";
	printable[8] = "Size : 20*10";
	return (printable);
}

void print_kcu(char *printable, char *arg, int i)
{
	if (my_strlen(printable) == i)
		check_kcu(arg);
	my_putchar('\n');
}

void print_debug(char **printable)
{
	my_printf("*** DEBUG MODE ***\n");
	my_printf("%s", printable[0]);
	print_kcu(printable[0], "kcub1", 11);
	my_printf("%s", printable[1]);
	print_kcu(printable[1], "kcuf1", 12);
	my_printf("%s", printable[2]);
	print_kcu(printable[2], "kcuu1", 11);
	my_printf("%s", printable[3]);
	print_kcu(printable[3], "kcud1", 11);
	my_printf("%s\n", printable[4]);
	my_printf("%s\n", printable[5]);
	my_printf("%s\n", printable[6]);
	my_printf("%s\n", printable[7]);
	my_printf("%s\n", printable[8]);
}

void do_canon(void)
{
	struct termios	origin;
	struct termios	actual;
	char		stock;

	tcgetattr(0, &origin);
	actual = origin;
	actual.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(0, TCSANOW, &actual);
	read(0, &stock, 1);
	tcsetattr(0, TCSANOW, &origin);
	my_putchar('\n');
}

int launch_debug(int ac, char **av)
{
	char	**printable = malloc(sizeof(char *) * 9);

	if (printable == NULL)
		return (84);
	printable = init_debug(printable);
	if (modif_debug(ac, av, printable) == 84)
		return (84);
	check_all(av);
	print_debug(printable);
	if (print_tetri(printable[8]) == 84)
		return (84);
	do_canon();
	return (0);
}
