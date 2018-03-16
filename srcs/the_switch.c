/*
** EPITECH PROJECT, 2018
** the_switch.c
** File description:
** Arthur
*/

#include "tetris.h"

int get_argv_part4(int oc, char **ptb)
{
	switch (oc) {
		case 'w':
			check_yes_no(optarg);
			if ((ptb[6] = change_str(optarg,
					ptb[6])) == NULL)
				return (84);
			break;
		case ':':
			return (84);
		case '?':
			return (84);
	}
	return (0);
}

int get_argv_part3(int oc, char **ptb)
{
	switch (oc) {
		case 'r':
			if ((ptb[1] = change_str(optarg,
					ptb[1])) == NULL)
				return (84);
			break;
		case 'p':
			if ((ptb[5] = change_str(optarg,
					ptb[5])) == NULL)
				return (84);
			break;
		case 'm':
			if ((ptb[8] = change_size(optarg,
					ptb[8])) == NULL)
				return (84);
			break;
	}
	if (get_argv_part4(oc, ptb) == 84)
		return (84);
	return (0);
}

int get_argv_part2(int oc, char **ptb)
{
	switch (oc) {
		case 't':
			if ((ptb[2] = change_str(optarg,
					ptb[2])) == NULL)
				return (84);
			break;
		case 'd':
			if ((ptb[3] = change_str(optarg,
					ptb[3])) == NULL)
				return (84);
			break;
		case 'q':
			if ((ptb[4] = change_str(optarg,
					ptb[4])) == NULL)
				return (84);
			break;
	}
	if (get_argv_part3(oc, ptb) == 84)
		return (84);
	return (0);
}

int get_argv(int oc, char **ptb)
{
	switch (oc) {
		case 'D':
			break;
		case 'L':
			if ((ptb[7] = change_str(optarg,
					ptb[7])) == NULL)
				return (84);
			break;
		case 'l':
			if ((ptb[0] = change_str(optarg,
					ptb[0])) == NULL)
				return (84);
			break;
	}
	if (get_argv_part2(oc, ptb) == 84)
		return (84);
	return (0);
}
